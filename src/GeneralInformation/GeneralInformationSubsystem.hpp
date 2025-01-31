#pragma once
#include <string>
#include "inc/Subsystem.hpp"
#include "XML/XMLLoad.hpp"
#include "FileMetadata.hpp"
#include "XML/XMLWriter.hpp"
#include "Validation.hpp"
#include "inc/XML_api.hpp"

#include <filesystem> // For `operations

class GeneralInformationSubsystem : public Subsystem
{
public:
    GeneralInformationSubsystem(std::shared_ptr<Gtk::Application> &app);
    std::vector<std::optional<std::string>> InitializeGui() override;
    void LoadDefault() override;
    std::vector<std::optional<std::string>> LoadFromFile() override;
    std::vector<std::optional<std::string>> Validate() override;

private:
    // Define attributes to hold references to input widgets
    Gtk::Entry m_aircraftNameEntry{};
    Gtk::Entry m_fileNameEntry{};
    Gtk::Entry m_revisionNumberEntry{};
    Gtk::Entry m_configVersionEntry{};
    Gtk::Entry m_copyrightEntry{};
    Gtk::Entry m_flightModelVersionEntry{};
    Gtk::Entry m_authorEntry{};
    Gtk::Entry m_emailEntry{};
    Gtk::Entry m_organizationEntry{};
    Gtk::Entry m_licenseEntry{};
    Gtk::Entry m_licenseURLEntry{};
    Gtk::Entry m_limitationsEntry{};
    Gtk::Entry m_sensitivityEntry{};
    Gtk::Entry m_notes{};
    Gtk::Entry m_description{};
    Gtk::Entry m_filePathTextbox{};
    std::string m_filePath{};
    Gtk::Calendar m_fileCreationDate{};
    Gtk::ComboBoxText m_releaseLevelDropdown{};
};
