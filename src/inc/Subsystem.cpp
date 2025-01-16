#include "Subsystem.hpp"

Subsystem::Subsystem(const std::string &name, const std::shared_ptr<Gtk::Application> &app)
    : m_name{name}
{
    m_boxLayout.append(m_grid);
}

Gtk::Box &Subsystem::GetBox()
{
    return m_boxLayout;
}

std::string Subsystem::GetName() const
{
    return m_name;
}