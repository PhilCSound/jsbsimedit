#pragma once
#include "inc/Subsystem.hpp"
#include "gtkmm.h"
#include <iostream>
#include "AerodynamicsWidget.hpp"

class AeroDynamicsSubsystem : public Subsystem
{
public:
  AeroDynamicsSubsystem(std::shared_ptr<Gtk::Application> &app);
  std::vector<std::optional<std::string>> InitializeGui() override;
  void LoadDefault() override;
  std::vector<std::optional<std::string>> LoadFromFile() override;
  std::vector<std::optional<std::string>> Validate() override;
};
