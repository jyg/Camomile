/*
 // Copyright (c) 2015-2018 Pierre Guillot.
 // For information on usage and redistribution, and for a DISCLAIMER OF ALL
 // WARRANTIES, see the file, "LICENSE.txt," in this distribution.
 */

#pragma once

#include "PluginProcessor.h"
#include "PluginEditorInteraction.h"
#include "PluginEditorComponents.h"
#include "PluginEditorObject.hpp"

class CamomileEditor : public AudioProcessorEditor, protected Timer, public CamomileEditorInteractionManager
{
public:
    CamomileEditor(CamomileAudioProcessor&);
    ~CamomileEditor();
    void paint(Graphics&) final;
    void timerCallback() final;
    
    //////////////////////////////////////////////////////////////////////////////////////////
    bool keyPressed(const KeyPress& key) final;
    bool keyStateChanged(bool isKeyDown) final;
    void modifierKeysChanged(const ModifierKeys& modifiers) final;
    
    void guiResize() final;
    void guiRedraw() final;
    
private:
    void updateSize();
    void updateObjects();
    
    //! @brief Cleans the objects.
    void cleanObjects();
    
    //! @brief Add the objects.
    void addObjects();
    
    //! @brief Adds the label to the objects.
    void addObjectsLabels();
    
    using object_uptr = std::unique_ptr<PluginEditorObject>;
    using label_uptr = std::unique_ptr<Component>;
    
    CamomileAudioProcessor&         m_processor;
    std::vector<object_uptr>        m_objects;
    std::vector<label_uptr>         m_labels;
    CamomileEditorButton            m_button;
    DrawableImage                   m_image;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CamomileEditor)
};
