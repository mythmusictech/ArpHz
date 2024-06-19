/*
  ==============================================================================

    MidiPropcessor.h
    Created: 19 Jun 2024 5:07:28pm
    Author:  Aiden Chimienti

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

class MidiProcessor
{
public:
    juce::MidiBuffer processedBuffer;
    
    void process(juce::MidiBuffer& midiMessages)
    {
        processedBuffer.clear();
        
        juce::MidiBuffer::Iterator iterator(midiMessages);
        juce::MidiMessage currentMessage;
        int samplePosition;
        
        while(iterator.getNextEvent(currentMessage, samplePosition))
        {
            if (currentMessage.isNoteOnOrOff())
            {
                auto harmonyMessage = currentMessage;
                auto oldNoteNumber = harmonyMessage.getNoteNumber();
                harmonyMessage.setNoteNumber(oldNoteNumber + 4);
                
                processedBuffer.addEvent(harmonyMessage, samplePosition);
            }
            
            processedBuffer.addEvent(currentMessage, samplePosition);
        }
        
        midiMessages.swapWith(processedBuffer);
    }
};
