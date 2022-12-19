#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
//    addAndMakeVisible(&prefPanel);
//    prefPanel.setBounds(0, 0, 600, 400);

    // simple
    addAndMakeVisible(&openSimplePrefButton);
    openSimplePrefButton.onClick = [this]
    {
        simplePrefPanel.showInDialogBox("Simple Preference", 300, 300, juce::Colours::lightblue);
    };
    openSimplePrefButton.setBounds(0, 10, 180, 32);
    
    // custom
    addAndMakeVisible(&openCustomPrefButton);
    openCustomPrefButton.onClick = [this]
    {
        customPrefPanel.showInNativeDialogBox("Custom Preference", 300, 300, juce::Colours::lightblue);
    };
    openCustomPrefButton.setBounds(200, 10, 180, 32);
    
    // animation
    addAndMakeVisible(&openAnimationPrefButton);
    openAnimationPrefButton.onClick = [this]
    {
        animationPrefPanel.showInDialogBox("Animation Preference", 300, 300, juce::Colours::lightblue);
    };
    openAnimationPrefButton.setBounds(400, 10, 180, 32);

    
    setSize (600, 400);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setFont (juce::Font (16.0f));
    g.setColour (juce::Colours::white);
    g.drawText ("Hello World!", getLocalBounds(), juce::Justification::centred, true);
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
