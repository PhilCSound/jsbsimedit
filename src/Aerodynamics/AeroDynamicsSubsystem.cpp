#include "AeroDynamicsSubsystem.hpp"

AeroDynamicsSubsystem::AeroDynamicsSubsystem(std::shared_ptr<Gtk::Application> &app)
    : Subsystem{"Aerodynamics", app}
{
}

std::vector<std::optional<std::string>> AeroDynamicsSubsystem::InitializeGui()
{
  // std::cout << "in AeroDynamicsSubsystem::Create" << std::endl;

  // These widgets can come from a ui file or direct from code
  //
  /* set the spacing to 10 on x and 10 on y */
  std::vector<std::optional<std::string>> errors{};

  m_grid.set_row_spacing(10);
  m_grid.set_column_spacing(10);

  auto aerodynamicsWidget = Gtk::make_managed<AerodynamicsWidget>();
  aerodynamicsWidget->set_expand(true);
  m_grid.attach(*aerodynamicsWidget, 0, 0);

  return errors;
}

void AeroDynamicsSubsystem::LoadDefault()
{
}

std::vector<std::optional<std::string>> AeroDynamicsSubsystem::LoadFromFile()
{
  return std::vector<std::optional<std::string>>();
}

std::vector<std::optional<std::string>> AeroDynamicsSubsystem::Validate()
{
  return std::vector<std::optional<std::string>>();
}
