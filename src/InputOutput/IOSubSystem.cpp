#include "IOSubSystem.hpp"

IOSubSystem::IOSubSystem(std::shared_ptr<Gtk::Application> &app)
    : Subsystem{"InputOutput", app}
{
}

std::vector<std::optional<std::string>> IOSubSystem::InitializeGui()
{
  // std::cout << "\nin IOSubsystem::Create\n" << std::endl;

  m_grid.set_row_spacing(15);
  m_grid.set_column_spacing(20);

  // call MainWindow constructor
  MainWindow mainWindow(m_grid);
  return std::vector<std::optional<std::string>>();
}

void IOSubSystem::LoadDefault()
{
}

std::vector<std::optional<std::string>> IOSubSystem::LoadFromFile()
{
  return std::vector<std::optional<std::string>>();
}

std::vector<std::optional<std::string>> IOSubSystem::Validate()
{
  return std::vector<std::optional<std::string>>();
}
