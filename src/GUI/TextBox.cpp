#include "TextBox.hpp"

namespace GUI
{

    TextBox::TextBox(const std::string &key, std::string label)
        : InputField(key), m_label(label)
    {
        m_label.set_text(label);
        // m_textEntry.signal_changed(std::bind(&));
    }

    void TextBox::AppendToGrid(Gtk::Grid &grid, int x, int y, int w, int h)
    {
        grid.attach(m_label, x, y, w, h);
        grid.attach(m_textEntry, x, y + 1, w, h);
    }

    std::string TextBox::GetData()
    {
        return std::string();
    }

    void TextBox::SetData(const std::string &val)
    {
        m_data = val;
        m_textEntry.set_text(val);
    }

    bool TextBox::Validate()
    {
        if (!m_validator)
            return false;
        return m_validator(m_data);
    }

    void TextBox::updateData()
    {
        m_data = m_textEntry.get_text();
    }
};