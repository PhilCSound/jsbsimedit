#include "IOSubSystem.hpp"

IOSubSystem::IOSubSystem(std::shared_ptr<Gtk::Application> &app)
    : Subsystem{"InputOutput", app}
{
}

void IOSubSystem::Create()
{
  // std::cout << "\nin IOSubsystem::Create\n" << std::endl;

  m_grid.set_row_spacing(15);
  m_grid.set_column_spacing(20);

  // call MainWindow constructor
  MainWindow mainWindow(m_grid);
}
