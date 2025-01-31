#pragma once
#include "GUI/InputField.hpp"
#include "gtkmm.h"

namespace GUI
{

    class TextBox : public InputField
    {
    public:
        TextBox(const std::string &key, std::string label = "");
        void AppendToGrid(const Gtk::Grid &grid, int x, int y, int w = 0, int h = 0) override;
        std::string GetData() override;
        void SetData(const std::string &val) override;
        bool Validate() override;

    private:
        ///=========================================
        ///     Member Funcs
        ///=========================================

        void updateData();

        ///=========================================
        ///     Member Vars
        ///=========================================

        std::string m_labelName;
        std::string m_data;
        Gtk::Entry m_textEntry{};
        Gtk::Label m_label{};
    };

};