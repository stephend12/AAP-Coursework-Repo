/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MidSideUtilityAudioProcessorEditor  : public AudioProcessorEditor,
                                            public Slider::Listener,
                                            public ComboBox::Listener,
                                            public Button::Listener
{
public:
    //==============================================================================
    MidSideUtilityAudioProcessorEditor (MidSideUtilityAudioProcessor& p);
    ~MidSideUtilityAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	MidSideUtilityAudioProcessor& processor;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<Slider> SliderInputGain;
    std::unique_ptr<Slider> SliderMidSideWidth;
    std::unique_ptr<TextEditor> GainTextBox;
    std::unique_ptr<TextEditor> StereoWidthTextBox;
    std::unique_ptr<ComboBox> MidSideInputComboBox;
    std::unique_ptr<ComboBox> MidSideOutputComboBox;
    std::unique_ptr<Slider> SliderMidPan;
    std::unique_ptr<Slider> SliderSidePan;
    std::unique_ptr<TextEditor> MidPanTextBox;
    std::unique_ptr<TextEditor> SidePanTextBox;
    std::unique_ptr<ToggleButton> LeftPhaseInvertToggleButton;
    std::unique_ptr<ToggleButton> RightPhaseInvertButton;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MidSideUtilityAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
