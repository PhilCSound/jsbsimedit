#pragma once
#include "Emptymass.hpp"
#include "Location.hpp"
#include "MomentOfInertia.hpp"
#include "Pointmass.hpp"
#include "gtkmm.h"
#include "inc/Subsystem.hpp"
#include "PointMassDialogue.hpp"
#include "inc/XML_api.hpp"
#include <assert.h>
#include <iostream>
#include <vector>

class MassBalanceSubsystem : public Subsystem
{
public:
  MassBalanceSubsystem(std::shared_ptr<Gtk::Application> &app);
  void Create();
  std::vector<std::optional<std::string>> InitializeGui() override;
  void LoadDefault() override;
  std::vector<std::optional<std::string>> LoadFromFile() override;
  std::vector<std::optional<std::string>> Validate() override;
  void on_button_pressed();

  // private:
  MassBalance::Location m_Location;
  MassBalance::EmptyMass m_Emptymass;
  MassBalance::MomentOfInertia m_airplane;
  MassBalance::PointMass m_Pointmass;
  // These structures do not match what is / can be in the xml file
  bool m_negated_crossproduct_inertia;
};
