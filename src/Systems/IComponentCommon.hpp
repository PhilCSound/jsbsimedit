#pragma once
#include <gtkmm.h>
#include <string>
#include <iostream>
#include "ComponentTypeEnum.hpp"
#include "inc/XML_api.hpp"
#include <vector>

namespace DragDrop{

class IComponentCommon
{
public:
    IComponentCommon(const std::string& compName, const ComponentType& type);
    bool CanHaveMultipleInputs();
    bool CanHaveMultipleOutputs();
    std::string GetName() const;
    ComponentType GetComponentType() const;
    float GetClipperMax() const;
    float GetClipperMin() const;
    bool IsClipperEnabled() const;
    void SetClipperState(bool enable);
    void SetClipperMax(float max);
    void SetClipperMin(float min);
    void SetName(const std::string& newName);
    virtual void LoadGUI(Glib::RefPtr<Gtk::Application>& app) = 0;
    virtual void LoadFromXml(JSBEdit::XMLNode& node) = 0;

protected:
    //Member Variables;
    std::string m_componentName {};
    ComponentType m_componentType;
    bool m_isClipperEnabled {};
    bool m_loadedFromXml = false;
    float m_clipperMax {};
    float m_clipperMin {};
    std::vector<std::string> m_inputs{};
    std::vector<std::string> m_outputs{};

private:

};

};