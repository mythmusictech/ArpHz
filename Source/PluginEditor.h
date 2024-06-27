/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class ArpHzAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    ArpHzAudioProcessorEditor (ArpHzAudioProcessor&);
    ~ArpHzAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    void toggleMode();

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    ArpHzAudioProcessor& audioProcessor;
    
    //GUI Components
    juce::Slider rateKnob;
    juce::TextButton buttonUp;
    juce::TextButton buttonDown;
    juce::TextButton buttonUpDown;
    juce::TextButton buttonDownUp;
    
    //juce::OwnedArray<juce::TextButton> modeButtons;
    
    //Labels
    juce::Label rateLabel;
    juce::Label modeLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ArpHzAudioProcessorEditor)
};
