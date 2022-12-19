#pragma once

#include <JuceHeader.h>

#include "SimplePreferencePanel.h"
#include "CustomPreferencePanel.h"
#include "AnimationPreferencePanel.h"

//==============================================================================
class MainComponent  : public juce::Component
{
public:
    MainComponent();
    ~MainComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    SimplePreferencePanel simplePrefPanel;
    CustomPreferencePanel customPrefPanel;
    AnimationPreferencePanel animationPrefPanel;

    juce::TextButton openSimplePrefButton {"simple"};
    juce::TextButton openCustomPrefButton {"custom"};
    juce::TextButton openAnimationPrefButton {"animation"};

    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
