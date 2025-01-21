#pragma once
#include "inc/Subsystem.hpp"
#include "gtkmm.h"
#include "PropulsionManager.hpp"
#include "inc/XML_api.hpp"
#include "EngineThrusterDialog.hpp"
#include <iostream>
#include <vector>     // For buttonNames
#include <map>        // For buttonMap
#include <utility>    // For std::pair
#include <filesystem> // For `operations
#include <cstdlib>    // For GetCurrentPlatform
#include "EngineSelectorWindow.hpp"

// Inherit from both Subsystem and Gtk::Window
class PropulsionSubsystem : public Subsystem, public Gtk::Window
{
public:
    PropulsionSubsystem(std::shared_ptr<Gtk::Application> &app); // Constructor to initialize the window and UI components
    void Create();
    std::vector<std::optional<std::string>> InitializeGui() override;
    void LoadDefault() override;
    std::vector<std::optional<std::string>> LoadFromFile() override;
    std::vector<std::optional<std::string>> Validate() override; // Method to create and display the UI elements
    void on_button_clicked();                                    // Callback for button click events
    bool checkSelect(const std::string &inp);
    std::string GetCurrentPlatformDebug();
    std::string EngineOrThruster(const std::string &pulledInput);
    std::string getSelectedEngine() const;
    std::string getSelectedThruster() const;

    std::string selectedEngine;
    std::string selectedThruster;
    std::string selectedPair;
    std::string selectedTank;
};