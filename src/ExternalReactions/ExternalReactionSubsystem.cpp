#include "ExternalReactionsSubsystem.hpp"

ExternalReactionsSubsystem::ExternalReactionsSubsystem(std::shared_ptr<Gtk::Application> &app)
    : Subsystem{"External Reactions", app}
{
    m_forceCount = 2;
}

std::vector<std::optional<std::string>> ExternalReactionsSubsystem::InitializeGui()
{
    std::vector<std::optional<std::string>> errors{};

    m_grid.set_row_spacing(10);
    m_grid.set_column_spacing(10);
    int row = 0;

    m_notebook.set_margin(10);
    m_notebook.set_expand();

    // Prevents window stretching when adding alot of force tabs
    m_notebook.set_scrollable(true);
    m_notebook.set_tab_pos(Gtk::PositionType::TOP);
    m_grid.attach(m_notebook, 0, 1, 7, 1); // Attach notebook below the buttons

    m_nameTextbox = Gtk::make_managed<Gtk::Entry>();
    m_nameTextbox->set_placeholder_text("Enter Force name...");

    // Add New Force Button
    auto newForceButton = Gtk::make_managed<Gtk::Button>("Add Force");
    newForceButton->set_hexpand(false);
    newForceButton->set_vexpand(false);
    newForceButton->set_margin(5);

    newForceButton->set_halign(Gtk::Align::START);
    newForceButton->set_valign(Gtk::Align::START);

    newForceButton->signal_clicked().connect([this]()
                                             {
        std::string forceName = m_nameTextbox->get_text();


        if (forceName.empty()) 
        {
            forceName = "Force " + std::to_string(++m_forceCount);
        }

        m_pages.push_back(std::make_unique<Gtk::Grid>());
        m_notebook.append_page(*m_pages.back(), forceName);
        m_nameTextbox->set_text(""); });
    m_grid.attach(*newForceButton, 0, row);

    // Add Remove Force Button
    auto removeForceButton = Gtk::make_managed<Gtk::Button>("Remove Force");
    removeForceButton->set_hexpand(false);
    removeForceButton->set_vexpand(false);
    removeForceButton->set_margin(5);

    removeForceButton->set_halign(Gtk::Align::START);
    removeForceButton->set_valign(Gtk::Align::START);

    removeForceButton->signal_clicked().connect([this]()
                                                {
        if (!m_pages.empty()) // Ensure there are tabs to remove
        { 
            int current_page = m_notebook.get_current_page();
            if(current_page >= 0)
            {
                m_notebook.remove_page(current_page);
            }
            //m_notebook.remove_page(m_notebook.get_n_pages() - 1); // Remove the last page
            m_pages.pop_back(); // Remove from vector
            --m_forceCount;     // Adjust force count
        } });
    m_grid.attach(*removeForceButton, 1, row); // Place next to Add Force button

    // Attach input fields and labels below the buttons
    auto forceNameLabel = Gtk::make_managed<Gtk::Label>("Force Name:"); // Renamed to avoid conflict
    m_grid.attach(*forceNameLabel, 2, row);
    m_grid.attach(*m_nameTextbox, 3, row, 4, 1); // Extend across remaining columns

    // Force Type Dropdown
    auto typeLabel = Gtk::make_managed<Gtk::Label>("Force Type:");
    auto forceTypeDropDownList = Gtk::make_managed<Gtk::ComboBoxText>();
    forceTypeDropDownList->append("Push-back");
    forceTypeDropDownList->append("Hook");
    forceTypeDropDownList->append("Gravity");
    forceTypeDropDownList->set_active(0); // Default to "Push-back"
    m_grid.attach(*typeLabel, 0, 2);
    m_grid.attach(*forceTypeDropDownList, 1, 2);

    // Force Metrics Dropdown
    auto metricLabel = Gtk::make_managed<Gtk::Label>("Metric:");
    auto metricDropDownList = Gtk::make_managed<Gtk::ComboBoxText>();
    metricDropDownList->append("Inches");
    metricDropDownList->append("Meters");
    metricDropDownList->append("Feet");
    metricDropDownList->set_active(0); // Default to "Inches"
    m_grid.attach(*metricLabel, 2, 2);
    m_grid.attach(*metricDropDownList, 3, 2);

    // Location Input Fields
    auto locationLabel = Gtk::make_managed<Gtk::Label>("Location:");
    auto locationXTextbox = Gtk::make_managed<Gtk::Entry>();
    auto locationYTextbox = Gtk::make_managed<Gtk::Entry>();
    auto locationZTextbox = Gtk::make_managed<Gtk::Entry>();
    locationXTextbox->set_placeholder_text("X");
    locationYTextbox->set_placeholder_text("Y");
    locationZTextbox->set_placeholder_text("Z");
    m_grid.attach(*locationLabel, 0, 3);
    m_grid.attach(*locationXTextbox, 1, 3);
    m_grid.attach(*locationYTextbox, 2, 3);
    m_grid.attach(*locationZTextbox, 3, 3);

    // Direction Input Fields
    auto directionLabel = Gtk::make_managed<Gtk::Label>("Direction:");
    auto directionXTextbox = Gtk::make_managed<Gtk::Entry>();
    auto directionYTextbox = Gtk::make_managed<Gtk::Entry>();
    auto directionZTextbox = Gtk::make_managed<Gtk::Entry>();
    directionXTextbox->set_placeholder_text("X");
    directionYTextbox->set_placeholder_text("Y");
    directionZTextbox->set_placeholder_text("Z");
    m_grid.attach(*directionLabel, 0, 4);
    m_grid.attach(*directionXTextbox, 1, 4);
    m_grid.attach(*directionYTextbox, 2, 4);
    m_grid.attach(*directionZTextbox, 3, 4);

    // Frame Dropdown
    auto frameLabel = Gtk::make_managed<Gtk::Label>("Frame:");
    auto frameDropDownList = Gtk::make_managed<Gtk::ComboBoxText>();
    frameDropDownList->append("BODY");
    frameDropDownList->append("LOCAL");
    frameDropDownList->append("WIND");
    frameDropDownList->set_active(0); // Default to "BODY"
    m_grid.attach(*frameLabel, 0, 5);
    m_grid.attach(*frameDropDownList, 1, 5);

    // Connect Force Type Dropdown
    forceTypeDropDownList->signal_changed().connect(
        [forceTypeDropDownList, locationXTextbox, locationYTextbox, locationZTextbox, directionXTextbox, directionYTextbox, directionZTextbox]()
        {
            std::string selectedType = forceTypeDropDownList->get_active_text();
            if (selectedType == "Push-back")
            {
                locationXTextbox->set_text("1.0");
                locationYTextbox->set_text("0.0");
                locationZTextbox->set_text("0.0");
                directionXTextbox->set_text("-2.0");
                directionYTextbox->set_text("0.0");
                directionZTextbox->set_text("-1.0");
            }
            else if (selectedType == "Hook")
            {
                locationXTextbox->set_text("0.5");
                locationYTextbox->set_text("0.5");
                locationZTextbox->set_text("0.5");
                directionXTextbox->set_text("2.0");
                directionYTextbox->set_text("1.0");
                directionZTextbox->set_text("-1.0");
            }
            // Additional force types can be added here
        });

    // Initial Tabs
    m_pages.push_back(std::make_unique<Gtk::Grid>());
    m_notebook.append_page(*m_pages.back(), "Force 1");

    m_pages.push_back(std::make_unique<Gtk::Grid>());
    m_notebook.append_page(*m_pages.back(), "Force 2");

    return errors;
}

void ExternalReactionsSubsystem::LoadDefault()
{
}

std::vector<std::optional<std::string>> ExternalReactionsSubsystem::LoadFromFile()
{
    return std::vector<std::optional<std::string>>();
}

std::vector<std::optional<std::string>> ExternalReactionsSubsystem::Validate()
{
    return std::vector<std::optional<std::string>>();
}
