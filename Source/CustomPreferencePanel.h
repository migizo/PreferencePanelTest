/*
  ==============================================================================

    CustomPreferencePanel.h
    Created: 26 Nov 2022 3:42:30pm
    Author:  migizo

  ==============================================================================
*/

#pragma once

#include "SimplePreferencePanel.h"

class LookAndFeel : public juce::LookAndFeel_V2
{
public:
    void drawDrawableButton (juce::Graphics& g, juce::DrawableButton& button,
                                             bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown)
    {
        bool toggleState = button.getToggleState();

        
        g.fillAll (button.findColour (toggleState ? juce::DrawableButton::backgroundOnColourId :
                                                    juce::DrawableButton::backgroundColourId));
        
        // hover追加
        if(toggleState == false && shouldDrawButtonAsHighlighted)
            g.fillAll(juce::Colours::black.withAlpha(0.25f));

        
        const int textH = (button.getStyle() == juce::DrawableButton::ImageAboveTextLabel)
                            ? juce::jmin (16, button.proportionOfHeight (0.25f))
                            : 0;
        if (textH > 0)
        {
            g.setFont ((float) textH);

            g.setColour (button.findColour (toggleState ? juce::DrawableButton::textColourOnId
                                                        : juce::DrawableButton::textColourId)
                            .withMultipliedAlpha (button.isEnabled() ? 1.0f : 0.4f));

            g.drawFittedText (button.getButtonText(),
                              2, button.getHeight() - textH - 1,
                              button.getWidth() - 4, textH,
                              juce::Justification::centred, 1);
        }
    }
};

class CustomPreferencePanel : public SimplePreferencePanel
{
public:
    
    CustomPreferencePanel()
    {
//        setLookAndFeel(new LookAndFeel());
        setColour(juce::DrawableButton::backgroundOnColourId, juce::Colours::black.withAlpha(0.5f));
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
    
    // 一部変更箇所以外はjuce::PreferencePanel::showInDialogBox()と同じ
    void showInNativeDialogBox(const juce::String &dialogTitle, int dialogWidth, int dialogHeight, juce::Colour backgroundColour=juce::Colours::white)
    {
        setSize (dialogWidth, dialogHeight);

        juce::DialogWindow::LaunchOptions o;
        o.content.setNonOwned (this);
        o.dialogTitle                   = dialogTitle;
        o.dialogBackgroundColour        = backgroundColour;
        o.escapeKeyTriggersCloseButton  = false;
        o.useNativeTitleBar             = true; // ここをtrueに変更
        o.resizable                     = false;

        o.launchAsync();
    }
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CustomPreferencePanel)
};
