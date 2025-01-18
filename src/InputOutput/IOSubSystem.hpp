#pragma once
#include "inc/Subsystem.hpp"
#include <gtkmm.h>
#include <iostream>
#include "MainWindow.hpp"

class IOSubSystem : public Subsystem
{
public:
  IOSubSystem(std::shared_ptr<Gtk::Application> &app);
  void Create();
};
