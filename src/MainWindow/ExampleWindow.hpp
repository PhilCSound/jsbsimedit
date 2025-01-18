#pragma once

#include "gtkmm.h"
#include "ExampleTab.hpp"
#include "Systems/FlightControlSubsystem.hpp"
#include <iostream>

#include "inc/XML_api.hpp"

#include "inc/Subsystem.hpp"
#include "Aerodynamics/AeroDynamicsSubsystem.hpp"
#include "BuoyantForces/BuoyantForcesSubsystem.hpp"
#include "Metrics/MetricsSubsystem.hpp"
#include "Propulsion/PropulsionSubsystem.hpp"
#include "InputOutput/IOSubSystem.hpp"
#include "MassBalance/MassBalanceSubsystem.hpp"
#include "ExternalReactions/ExternalReactionsSubsystem.hpp"
#include "GeneralInformation/GeneralInformationSubsystem.hpp"
#include "GroundReactions/GroundReactionsSubsystem.hpp"

namespace JSBEdit
{

	class ExampleWindow : public Gtk::Window
	{
	public:
		ExampleWindow(const Glib::RefPtr<Gtk::Application> &app);
		~ExampleWindow() = default;

	protected:
		// Signal handlers:
		bool load_stack(const Glib::RefPtr<Gtk::Application> &app);
		void on_menu_file_files_dialog();
		void on_menu_file_quit();
		void on_menu_file_new();
		void on_menu_file_save(); // save

		void on_dialog_finish(Glib::RefPtr<Gio::AsyncResult> &result);
		void on_notebook_switch_page(Gtk::Widget * /* page */, guint page_num);

		// Child widgets:
		Gtk::Box m_Box;
		Gtk::Stack m_stack{};
		Gtk::StackSwitcher m_stackSwitcher{};
		ExampleTab m_tab1;
		ExampleTab m_tab2;

		Glib::RefPtr<Gtk::Builder> m_refBuilder;
		Glib::RefPtr<Gio::SimpleActionGroup> m_refActionGroup;

		Glib::RefPtr<Gtk::RecentManager> m_refRecentManager;
		Glib::RefPtr<Gtk::FileDialog> m_refFileDialog;
		std::shared_ptr<Gtk::Application> m_appPointer;

		Gtk::Notebook *m_Notebook{nullptr};

		// Subsystems
		std::vector<Subsystem *> m_Subsystems;
	};

};