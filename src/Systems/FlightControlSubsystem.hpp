#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include "Systems/ChannelCanvas.hpp"
#include "inc/XML_api.hpp"
#include "inc/Subsystem.hpp"

namespace DragDrop
{

	class FlightControlSubsystem : public Subsystem
	{
	public:
		FlightControlSubsystem(std::shared_ptr<Gtk::Application> &app);
		~FlightControlSubsystem() = default;

		std::vector<std::optional<std::string>> InitializeGui() override;
		void LoadDefault() override;
		std::vector<std::optional<std::string>> LoadFromFile() override;
		std::vector<std::optional<std::string>> Validate() override;

		void CreateNewTab(const std::string &name);

	private:
		// Signal handlers
		Glib::RefPtr<Gdk::ContentProvider> SetDragData(int data);
		void on_notebook_switch_page(Gtk::Widget *wid, guint page_num);

		// Member vars
		ChannelCanvas m_canvas;
		Glib::RefPtr<Gtk::Builder> m_refBuilder;
		std::string m_systemName{};
		Gtk::Notebook m_notebook;
	};

};
