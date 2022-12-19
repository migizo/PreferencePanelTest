/*
  ==============================================================================

    SimplePreferencePanel.h
    Created: 26 Nov 2022 3:41:49pm
    Author:  migizo

  ==============================================================================
*/

#pragma once

#include <juce_gui_extra/juce_gui_extra.h>
#include "Images/Image1.h"
#include "Images/Image2.h"
#include "Images/Image3.h"

class SimplePreferencePanel : public juce::PreferencesPanel
{
public:
    // 各ページを追加
    SimplePreferencePanel()
    {
        addSettingsPage("Page 1", image1, image1Size);
        addSettingsPage("Page 2", image2, image2Size);
        addSettingsPage("Page 3", image3, image3Size);
    }
    
    // ページ名に対応するコンポーネントを返す
    juce::Component* createComponentForPage (const juce::String& pageName) override
    {
        if (pageName == "Page 1")       return new juce::Label("Page 1", "Page 1");
        else if (pageName == "Page 2")  return new juce::Label("Page 2", "Page 2");
        else if (pageName == "Page 3")  return new juce::Label("Page 3", "Page 3");
        return nullptr;
    }
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SimplePreferencePanel)
};
