#pragma once
#include "inc/Subsystem.hpp"
#include "gtkmm.h"
#include <iostream>
#include "AerodynamicsWidget.hpp"

class AeroDynamicsSubsystem : public Subsystem
{
public:
  AeroDynamicsSubsystem(std::shared_ptr<Gtk::Application> &app);
  void Create();
};
