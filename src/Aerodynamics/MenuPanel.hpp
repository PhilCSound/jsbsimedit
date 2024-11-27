#pragma once

#include <gtkmm.h>
#include "AerodynamicsNode.hpp"
#include <iostream>

class MenuPanel : public Gtk::Box {
private:
    Gtk::Label* header;
public:
    MenuPanel() : Gtk::Box(Gtk::Orientation::VERTICAL)
    {
        // Creates a header for the menu
        header = Gtk::make_managed<Gtk::Label>();
        header->set_halign(Gtk::Align::CENTER);
        append(*header);
    }
    ~MenuPanel(){}

    void setHeader(std::string title){header->set_label(title);}

    using UpdateSignal = sigc::signal<void()>;
    UpdateSignal update_signal;
};

class FunctionMenu : public MenuPanel {
public:
    FunctionMenu(std::shared_ptr<AerodynamicsNode> node);
private:
    std::shared_ptr<Function> function;
};

class TableMenu : public MenuPanel {
public:
    TableMenu(std::shared_ptr<AerodynamicsNode> node);
private:
    std::shared_ptr<Table> table;
};

class ValueMenu : public MenuPanel {
public:
    ValueMenu(std::shared_ptr<AerodynamicsNode> node);
private:
    std::shared_ptr<Value> value;
};

class AxisMenu : public MenuPanel {
public:
    AxisMenu(std::shared_ptr<AerodynamicsNode> node);
private:
    void on_name_dropdown_selected();
    void on_unit_dropdown_selected();
    std::shared_ptr<Axis> axis;
    Gtk::Grid* grid;
    Gtk::Label* nameDropdownLabel;
    Gtk::DropDown* nameDropdown;
    Gtk::Label* unitDropdownLabel;
    Gtk::DropDown* unitDropdown;
    std::shared_ptr<Gtk::StringList> name_list;
    std::shared_ptr<Gtk::StringList> unit_list;
};

class PropertyMenu : public MenuPanel {
public:
    PropertyMenu(std::shared_ptr<AerodynamicsNode> node);
private:
    std::shared_ptr<AeroProperty> property;
};