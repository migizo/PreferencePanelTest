/*
  ==============================================================================

    AnimationPreferencePanel.h
    Created: 26 Nov 2022 4:10:20pm
    Author:  migizo

  ==============================================================================
*/

#pragma once

#include <juce_gui_extra/juce_gui_extra.h>
#include "Images/Image1.h"
#include "Images/Image2.h"
#include "Images/Image3.h"

class AnimationPreferencePanel : public juce::PreferencesPanel, juce::Button::Listener
{
public:
    AnimationPreferencePanel()
    {
        // 独自に作成したaddCustomSettingsPage()を使用
        addCustomSettingsPage("Page 1", image1, image1Size);
        addCustomSettingsPage("Page 2", image2, image2Size);
        addCustomSettingsPage("Page 3", image3, image3Size);
        
        // 選択時の色を通常時の色と同じにする
        setColour(juce::DrawableButton::backgroundOnColourId,
                  findColour(juce::DrawableButton::backgroundColourId));
        
        // アニメーション用コンポーネント
        addAndMakeVisible(&animComp);
        animComp.setBounds(0, 0, getButtonSize(), getButtonSize());
        
        // ボタンリスナーを登録
        for (auto* child: getChildren())
        {
            if (auto* button = dynamic_cast<juce::Button*>(child))
                button->addListener(this);
        }
    }
    void colourChanged() override
    {
        auto target = juce::DrawableButton::backgroundOnColourId;
        auto colour = findColour(target);
        for (auto* child : getChildren())
        {
            child->setColour(target, colour);
        }
    }
    void buttonClicked (juce::Button* button) override
    {
        // 対象コンポーネントの境界をクリックされたボタンの境界にアニメーションさせて変化させる
        juce::Desktop::getInstance().getAnimator().animateComponent(&animComp,
                                                                    button->getBounds(),
                                                                    1.0,    // finalAlpha
                                                                    150,    // ms
                                                                    false,  // アニメーション時に代理コンポーネントを使用するかどうか
                                                                            // trueにすると元のコンポーネント自体をペイントする必要が無くなるが、管理がややこしそうな場合はfalseに
                                                                    1.0f,   // startSpeed,値を大きくするほど前半早くなる
                                                                    1.0f);  // endSpeed,値を大きくするほど後半早くなる
    }
    juce::Component* createComponentForPage (const juce::String& pageName) override
    {
        if (pageName == "Page 1")       return new juce::Label("Page 1", "Page 1");
        else if (pageName == "Page 2")  return new juce::Label("Page 2", "Page 2");
        else if (pageName == "Page 3")  return new juce::Label("Page 3", "Page 3");
        return nullptr;
    }
    
    // hover,選択に関わらず同じ表示にする
    void addCustomSettingsPage(const juce::String& title, const void* imageData, int imageDataSize)
    {
        juce::DrawableImage icon;
        icon.setImage (juce::ImageCache::getFromMemory (imageData, imageDataSize));
        addSettingsPage (title, &icon, &icon, &icon);
    }
    
private:
    // 半透明黒を描画するだけのコンポーネント
    class AnimComp : public juce::Component
    {
    public:
        void paint(juce::Graphics& g) override
        {
            g.fillAll(juce::Colours::black.withAlpha(0.5f));
        }
    };
    AnimComp animComp;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AnimationPreferencePanel)
};
