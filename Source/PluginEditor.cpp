/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ArpHzAudioProcessorEditor::ArpHzAudioProcessorEditor (ArpHzAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    
    //Set rate knob
    rateKnob.setSliderStyle(juce::Slider::Rotary);
    rateKnob.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 20);
    
    //Set mode buttons
    /*          OH NOOO.... OUR TABLE.... ITS BROKEN.....
    for (int i = 0; i < 4; i++)
    {
        modeButtons.add(new juce::TextButton); //Modes: Up, Down, Up/Down, Down/Up
    }
    
    modeButtons[0]->setButtonText("Up");
    modeButtons[1]->setButtonText("Down");
    modeButtons[2]->setButtonText("Up/Down");
    modeButtons[4]->setButtonText("Down/Up");
    */
    buttonUp.setButtonText("Up");
    buttonDown.setButtonText("Down");
    buttonUpDown.setButtonText("Up/Down");
    buttonDownUp.setButtonText("Down/Up");
    
    //Set labels
    rateLabel.setText("Rate", juce::dontSendNotification);
    rateLabel.setEditable(false);
    
    modeLabel.setText("Mode", juce::dontSendNotification);
    modeLabel.setEditable(false);
    
    //Add all GUI components
    addAndMakeVisible(&rateKnob);
    addAndMakeVisible(&rateLabel);
    
    /*
    for (int modeID = 0; modeID < modeButtons.size(); modeID++)
    {
        addAndMakeVisible(modeButtons[modeID]);
    }
    addAndMakeVisible(&modeLabel);
    */
    addAndMakeVisible(&buttonUp);
    addAndMakeVisible(&buttonDown);
    addAndMakeVisible(&buttonUpDown);
    addAndMakeVisible(&buttonDownUp);
    addAndMakeVisible(&modeLabel);
    
    //Set plugin window size
    setSize (450, 250);
}

ArpHzAudioProcessorEditor::~ArpHzAudioProcessorEditor()
{
}

//==============================================================================
void ArpHzAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void ArpHzAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
    //Layout values
    auto marginX = getWidth() * 0.02;
    auto marginY = getHeight() * 0.02;
    auto knobSize = getWidth() * 0.3;
    auto buttonWidth = getWidth() * 0.15;
    auto buttonHeight = getHeight() * 0.1;
    auto textWidth = 100;
    auto textHeight = 50;
    
    /*
    for (int buttonID = 0; buttonID < modeButtons.size(); buttonID++)
    {
        modeButtons[buttonID]->setBounds(buttonID * (buttonWidth + marginX) + marginX, 2 * marginY + textHeight, buttonWidth, buttonHeight);
    }
    modeLabel.setBounds(marginX, marginY, textWidth, textHeight);
    */
    buttonUp.setBounds(marginX, 2 * marginY + textHeight, buttonWidth, buttonHeight);
    buttonDown.setBounds(buttonUp.getX() + buttonWidth + marginX, 2 * marginY + textHeight, buttonWidth, buttonHeight);
    buttonUpDown.setBounds(buttonDown.getX() + buttonWidth + marginX, 2 * marginY + textHeight, buttonWidth, buttonHeight);
    buttonDownUp.setBounds(buttonUpDown.getX() + buttonWidth + marginX, 2 * marginY + textHeight, buttonWidth, buttonHeight);
    modeLabel.setBounds(marginX, marginY, textWidth, textHeight);
    
    rateKnob.setBounds(getWidth() - knobSize - marginX, getHeight() - knobSize - marginY, knobSize, knobSize);
    rateLabel.setBounds(getWidth() - knobSize - (4 * marginX), getHeight() - (knobSize / 2) - marginY, textWidth, textHeight);
}

void toggleMode()
{
    //Only 1 mode should be selected at a time.
    //This function is used to toggle all other buttons off when one is selected.
}
