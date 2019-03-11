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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MidSideUtilityAudioProcessorEditor::MidSideUtilityAudioProcessorEditor (MidSideUtilityAudioProcessor& p)
    : AudioProcessorEditor(p), processor(p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    SliderInputGain.reset (new Slider ("Input Gain"));
    addAndMakeVisible (SliderInputGain.get());
    SliderInputGain->setRange (0, 2, 0);
    SliderInputGain->setSliderStyle (Slider::Rotary);
    SliderInputGain->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    SliderInputGain->addListener (this);

    SliderMidSideWidth.reset (new Slider ("Mid Side Width"));
    addAndMakeVisible (SliderMidSideWidth.get());
    SliderMidSideWidth->setRange (0, 2, 0);
    SliderMidSideWidth->setSliderStyle (Slider::Rotary);
    SliderMidSideWidth->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    SliderMidSideWidth->addListener (this);

    GainTextBox.reset (new TextEditor ("GainTextBox"));
    addAndMakeVisible (GainTextBox.get());
    GainTextBox->setMultiLine (false);
    GainTextBox->setReturnKeyStartsNewLine (false);
    GainTextBox->setReadOnly (true);
    GainTextBox->setScrollbarsShown (true);
    GainTextBox->setCaretVisible (false);
    GainTextBox->setPopupMenuEnabled (true);
    GainTextBox->setText (TRANS("Input Gain"));

    StereoWidthTextBox.reset (new TextEditor ("StereoWidthTextBox"));
    addAndMakeVisible (StereoWidthTextBox.get());
    StereoWidthTextBox->setMultiLine (false);
    StereoWidthTextBox->setReturnKeyStartsNewLine (false);
    StereoWidthTextBox->setReadOnly (true);
    StereoWidthTextBox->setScrollbarsShown (true);
    StereoWidthTextBox->setCaretVisible (false);
    StereoWidthTextBox->setPopupMenuEnabled (true);
    StereoWidthTextBox->setText (TRANS("Stereo Width"));

    MidSideInputComboBox.reset (new ComboBox ("MidSideInputComboBox"));
    addAndMakeVisible (MidSideInputComboBox.get());
    MidSideInputComboBox->setEditableText (false);
    MidSideInputComboBox->setJustificationType (Justification::centredLeft);
    MidSideInputComboBox->setTextWhenNothingSelected (String());
    MidSideInputComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    MidSideInputComboBox->addItem (TRANS("Stereo Input"), 1);
    MidSideInputComboBox->addItem (TRANS("Mid/Side Input"), 2);
    MidSideInputComboBox->addListener (this);

    MidSideOutputComboBox.reset (new ComboBox ("MidSideOutputComboBox"));
    addAndMakeVisible (MidSideOutputComboBox.get());
    MidSideOutputComboBox->setEditableText (false);
    MidSideOutputComboBox->setJustificationType (Justification::centredLeft);
    MidSideOutputComboBox->setTextWhenNothingSelected (String());
    MidSideOutputComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    MidSideOutputComboBox->addItem (TRANS("Stereo Output"), 1);
    MidSideOutputComboBox->addItem (TRANS("Mid/Side Output"), 2);
    MidSideOutputComboBox->addListener (this);

    SliderMidPan.reset (new Slider ("MidPanSlider"));
    addAndMakeVisible (SliderMidPan.get());
    SliderMidPan->setRange (0, 1, 0);
    SliderMidPan->setSliderStyle (Slider::Rotary);
    SliderMidPan->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    SliderMidPan->addListener (this);

    SliderSidePan.reset (new Slider ("SidePanSlider"));
    addAndMakeVisible (SliderSidePan.get());
    SliderSidePan->setRange (0, 1, 0);
    SliderSidePan->setSliderStyle (Slider::Rotary);
    SliderSidePan->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    SliderSidePan->addListener (this);

    MidPanTextBox.reset (new TextEditor ("MidPanTextBox"));
    addAndMakeVisible (MidPanTextBox.get());
    MidPanTextBox->setMultiLine (false);
    MidPanTextBox->setReturnKeyStartsNewLine (false);
    MidPanTextBox->setReadOnly (true);
    MidPanTextBox->setScrollbarsShown (true);
    MidPanTextBox->setCaretVisible (false);
    MidPanTextBox->setPopupMenuEnabled (true);
    MidPanTextBox->setText (TRANS("Left/Mid Pan"));

    SidePanTextBox.reset (new TextEditor ("SidePanTextBox"));
    addAndMakeVisible (SidePanTextBox.get());
    SidePanTextBox->setMultiLine (false);
    SidePanTextBox->setReturnKeyStartsNewLine (false);
    SidePanTextBox->setReadOnly (true);
    SidePanTextBox->setScrollbarsShown (true);
    SidePanTextBox->setCaretVisible (false);
    SidePanTextBox->setPopupMenuEnabled (true);
    SidePanTextBox->setText (TRANS("Right/Side Pan"));

    LeftPhaseInvertToggleButton.reset (new ToggleButton ("LeftPhaseInvertToggleButton"));
    addAndMakeVisible (LeftPhaseInvertToggleButton.get());
    LeftPhaseInvertToggleButton->setButtonText (TRANS("Left/Mid Phase Invert"));
    LeftPhaseInvertToggleButton->addListener (this);

    RightPhaseInvertButton.reset (new ToggleButton ("RightPhaseToggleButton"));
    addAndMakeVisible (RightPhaseInvertButton.get());
    RightPhaseInvertButton->setButtonText (TRANS("Right/Side Phase Invert"));
    RightPhaseInvertButton->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

MidSideUtilityAudioProcessorEditor::~MidSideUtilityAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    SliderInputGain = nullptr;
    SliderMidSideWidth = nullptr;
    GainTextBox = nullptr;
    StereoWidthTextBox = nullptr;
    MidSideInputComboBox = nullptr;
    MidSideOutputComboBox = nullptr;
    SliderMidPan = nullptr;
    SliderSidePan = nullptr;
    MidPanTextBox = nullptr;
    SidePanTextBox = nullptr;
    LeftPhaseInvertToggleButton = nullptr;
    RightPhaseInvertButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MidSideUtilityAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MidSideUtilityAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    SliderInputGain->setBounds (0, 0, proportionOfWidth (0.25f), proportionOfHeight (0.25f));
    SliderMidSideWidth->setBounds (448, 0, proportionOfWidth (0.25f), proportionOfHeight (0.25f));
    GainTextBox->setBounds (0, 120, proportionOfWidth (0.25f), proportionOfHeight (0.06f));
    StereoWidthTextBox->setBounds (448, 120, proportionOfWidth (0.25f), proportionOfHeight (0.06f));
    MidSideInputComboBox->setBounds (224, 32, proportionOfWidth (0.25f), proportionOfHeight (0.06f));
    MidSideOutputComboBox->setBounds (224, 104, proportionOfWidth (0.25f), proportionOfHeight (0.06f));
    SliderMidPan->setBounds (136, 168, proportionOfWidth (0.25f), proportionOfHeight (0.25f));
    SliderSidePan->setBounds (320, 168, proportionOfWidth (0.25f), proportionOfHeight (0.25f));
    MidPanTextBox->setBounds (136, 288, proportionOfWidth (0.25f), proportionOfHeight (0.06f));
    SidePanTextBox->setBounds (320, 288, proportionOfWidth (0.25f), proportionOfHeight (0.06f));
    LeftPhaseInvertToggleButton->setBounds (128, 344, proportionOfWidth (0.3f), proportionOfHeight (0.06f));
    RightPhaseInvertButton->setBounds (312, 344, proportionOfWidth (0.3f), proportionOfHeight (0.06f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MidSideUtilityAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]

    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == SliderInputGain.get())
    {
        //[UserSliderCode_SliderInputGain] -- add your slider handling code here..
		processor.InputGain = SliderInputGain->getValue();
        //[/UserSliderCode_SliderInputGain]
    }
    else if (sliderThatWasMoved == SliderMidSideWidth.get())
    {
        //[UserSliderCode_SliderMidSideWidth] -- add your slider handling code here..
		processor.StereoWidth = SliderMidSideWidth->getValue();
        //[/UserSliderCode_SliderMidSideWidth]
    }
    else if (sliderThatWasMoved == SliderMidPan.get())
    {
        //[UserSliderCode_SliderMidPan] -- add your slider handling code here..
		processor.LeftPan = SliderMidPan->getValue();
        //[/UserSliderCode_SliderMidPan]
    }
    else if (sliderThatWasMoved == SliderSidePan.get())
    {
        //[UserSliderCode_SliderSidePan] -- add your slider handling code here..
		processor.RightPan = SliderSidePan->getValue();
        //[/UserSliderCode_SliderSidePan]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void MidSideUtilityAudioProcessorEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == MidSideInputComboBox.get())
    {
        //[UserComboBoxCode_MidSideInputComboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_MidSideInputComboBox]
    }
    else if (comboBoxThatHasChanged == MidSideOutputComboBox.get())
    {
        //[UserComboBoxCode_MidSideOutputComboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_MidSideOutputComboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void MidSideUtilityAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == LeftPhaseInvertToggleButton.get())
    {
        //[UserButtonCode_LeftPhaseInvertToggleButton] -- add your button handler code here..
        //[/UserButtonCode_LeftPhaseInvertToggleButton]
    }
    else if (buttonThatWasClicked == RightPhaseInvertButton.get())
    {
        //[UserButtonCode_RightPhaseInvertButton] -- add your button handler code here..
        //[/UserButtonCode_RightPhaseInvertButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MidSideUtilityAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor"
                 constructorParams="MidSideUtilityAudioProcessor&amp; p" variableInitialisers="AudioProcessorEditor(p), processor(p)&#10;"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.33"
                 fixedSize="1" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <SLIDER name="Input Gain" id="e143cc5a1920da1c" memberName="SliderInputGain"
          virtualName="" explicitFocusOrder="0" pos="0 0 25% 25%" min="0.0"
          max="2.0" int="0.0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="Mid Side Width" id="75772a5d43ce0092" memberName="SliderMidSideWidth"
          virtualName="" explicitFocusOrder="0" pos="448 0 25% 25%" min="0.0"
          max="2.0" int="0.0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <TEXTEDITOR name="GainTextBox" id="f714a38b9c1281f3" memberName="GainTextBox"
              virtualName="" explicitFocusOrder="0" pos="0 120 25% 6%" initialText="Input Gain"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="1"
              caret="0" popupmenu="1"/>
  <TEXTEDITOR name="StereoWidthTextBox" id="f24538f25dfacd8f" memberName="StereoWidthTextBox"
              virtualName="" explicitFocusOrder="0" pos="448 120 25% 6%" initialText="Stereo Width"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="1"
              caret="0" popupmenu="1"/>
  <COMBOBOX name="MidSideInputComboBox" id="cb1d6ed077d76e35" memberName="MidSideInputComboBox"
            virtualName="" explicitFocusOrder="0" pos="224 32 25% 6%" editable="0"
            layout="33" items="Stereo Input&#10;Mid/Side Input" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <COMBOBOX name="MidSideOutputComboBox" id="ea3bd620b50244e0" memberName="MidSideOutputComboBox"
            virtualName="" explicitFocusOrder="0" pos="224 104 25% 6%" editable="0"
            layout="33" items="Stereo Output&#10;Mid/Side Output" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <SLIDER name="MidPanSlider" id="b56b33ede3b3abc5" memberName="SliderMidPan"
          virtualName="" explicitFocusOrder="0" pos="136 168 25% 25%" min="0.0"
          max="1.0" int="0.0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="SidePanSlider" id="79f796febe26eaa0" memberName="SliderSidePan"
          virtualName="" explicitFocusOrder="0" pos="320 168 25% 25%" min="0.0"
          max="1.0" int="0.0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <TEXTEDITOR name="MidPanTextBox" id="b5288c7a98ab9356" memberName="MidPanTextBox"
              virtualName="" explicitFocusOrder="0" pos="136 288 25% 6%" initialText="Left/Mid Pan"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="1"
              caret="0" popupmenu="1"/>
  <TEXTEDITOR name="SidePanTextBox" id="baf96a8cfcb5f46d" memberName="SidePanTextBox"
              virtualName="" explicitFocusOrder="0" pos="320 288 25% 6%" initialText="Right/Side Pan"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="1"
              caret="0" popupmenu="1"/>
  <TOGGLEBUTTON name="LeftPhaseInvertToggleButton" id="90fa0793a7339a0b" memberName="LeftPhaseInvertToggleButton"
                virtualName="" explicitFocusOrder="0" pos="128 344 30% 6%" buttonText="Left/Mid Phase Invert"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="RightPhaseToggleButton" id="c81799c67c011625" memberName="RightPhaseInvertButton"
                virtualName="" explicitFocusOrder="0" pos="312 344 30% 6%" buttonText="Right/Side Phase Invert"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
