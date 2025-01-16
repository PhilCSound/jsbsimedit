#pragma once
#include <string>
#include <memory>
#include "gtkmm.h"

class Subsystem
{
public:
  /// @brief Constructor, used to create a subsystem.
  /// @param app - Used for subsystem to call.
  /// @param name - Name of the subsystem.
  Subsystem(const std::string &name, const std::shared_ptr<Gtk::Application> &app);

  /// @brief The default constructor is deleted.
  Subsystem() = delete;

  /// @brief Declaring the default destructor.
  ~Subsystem() = default;

  /// @brief Create makes all the widgets, and initializes and classes.
  /// Called before adding the subsystem to the Subsystem group.
  virtual void Create() = 0;

  /// @brief Returns a reference of the box containing widgets of the subsystem.
  [[nodiscard]]
  Gtk::Box &GetBox();

  /// @brief Returns the name of the subsystem.
  [[nodiscard]]
  std::string GetName() const;

protected:
  /////////////////////////////////////////////////////////////////////////////////
  ///       Member Variables
  /////////////////////////////////////////////////////////////////////////////////

  /// @brief Used by some subsystems to create modal popup windows.
  std::shared_ptr<Gtk::Application> m_app;

  /// @brief Some subsystems don't want the grid, and opt for box.
  /// However, m_grid is appended to this box. This should not be a issue if you don't use it.
  Gtk::Box m_boxLayout;

  /// @brief Subsystems can append their GUI widgets to the grid to display.
  Gtk::Grid m_grid;

  /// @brief This is the name of the subsystem.
  std::string m_name;
};
