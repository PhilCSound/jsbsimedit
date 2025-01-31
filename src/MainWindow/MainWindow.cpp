#include "MainWindow/MainWindow.hpp"

namespace JSBEdit
{

    MainWindow::MainWindow(const Glib::RefPtr<Gtk::Application> &app)
        : m_Box(Gtk::Orientation::VERTICAL), m_appPointer{app},
          m_refRecentManager(Gtk::RecentManager::get_default())
    {
        set_title("JSBSim Commander");
        set_default_size(800, 600);
        // We can put a PopoverMenuBar at the top of the box and other stuff below it.
        set_child(m_Box);

        // Create actions for menus and toolbars:
        m_refActionGroup = Gio::SimpleActionGroup::create();

        // File menu:
        m_refActionGroup->add_action("new",
                                     sigc::mem_fun(*this, &MainWindow::on_menu_file_new));

        m_refActionGroup->add_action("save",
                                     sigc::mem_fun(*this, &MainWindow::on_menu_file_save)); // save

        // A menu item to open the file dialog:
        m_refActionGroup->add_action("files-dialog",
                                     sigc::mem_fun(*this, &MainWindow::on_menu_file_files_dialog));

        m_refActionGroup->add_action("quit",
                                     sigc::mem_fun(*this, &MainWindow::on_menu_file_quit));

        insert_action_group("example", m_refActionGroup);

        // When the menubar is a child of a Gtk::Window, keyboard accelerators are not
        // automatically fetched from the Gio::Menu.
        // See the examples/book/menus/main_menu example for an alternative way of
        // adding the menubar when using Gtk::ApplicationWindow.
        app->set_accel_for_action("example.new", "<Primary>n");
        app->set_accel_for_action("example.files-dialog", "<Primary>o");
        app->set_accel_for_action("example.quit", "<Primary>q");
        app->set_accel_for_action("example.save", "<Primary>s");

        try
        {
            m_refBuilder = Gtk::Builder::create_from_file("../../../mainWindow.xml");
        }
        catch (const Glib::Error &ex)
        {
            std::cerr << "Error loading mainWindow.xml" << ex.what();
        }

        auto pToolbar = m_refBuilder->get_widget<Gtk::Box>("toolbar");
        if (pToolbar)
            // Toolbar:
            m_Box.append(*pToolbar);
        else
            g_warning("toolbar not found");

        m_Notebook = new Gtk::Notebook();
        m_Notebook->set_margin(10);
        m_Notebook->set_expand();
        m_Box.append(*m_Notebook);
    }

    void MainWindow::on_menu_file_new()
    {
        if (!m_refFileDialog)
        {
            m_refFileDialog = Gtk::FileDialog::create();
            m_refFileDialog->set_modal(true);
        }
        m_refFileDialog->open(*this, sigc::mem_fun(*this, &MainWindow::on_dialog_finish));
    }

    void MainWindow::on_menu_file_save() // implement save function to over-write the xml
    {
        std::filesystem::path filePath = xmlptr()->GetFilePath();
        if (xmlptr()->SaveToFile(filePath))
        {
            std::cout << "Data saved successfully to: " << filePath << std::endl;
        }
        else
        {
            std::cout << "Failed to save to: " << filePath << std::endl;
        }
    }

    void MainWindow::on_menu_file_files_dialog()
    {
        if (!m_refFileDialog)
        {
            m_refFileDialog = Gtk::FileDialog::create();
            m_refFileDialog->set_modal(true);
            m_refFileDialog->set_title("Open XML File");
        }
        m_refFileDialog->open(*this, sigc::mem_fun(*this, &MainWindow::on_dialog_finish));
    }

    void MainWindow::on_menu_file_quit()
    {
        set_visible(false); // Closes the main window to stop the app->make_window_and_run().
    }

    void MainWindow::on_dialog_finish(Glib::RefPtr<Gio::AsyncResult> &result)
    {
        Glib::RefPtr<Gio::File> file;
        try
        {
            file = m_refFileDialog->open_finish(result);
        }
        catch (const Gtk::DialogError &err)
        {
            std::cout << "No file selected, " << err.what() << std::endl;
            return;
        }

        auto selected_uri = file->get_uri();
        std::cout << "URI selected = " << selected_uri << std::endl;
        std::string selected_path = selected_uri.substr(7);

        xmlptr()->LoadFileAndParse(selected_path);

        // delete the previous, if it exists
        if (m_Notebook)
        {
            m_Box.remove(*m_Notebook);
            delete m_Notebook;
        }

        m_Notebook = new Gtk::Notebook();
        m_Notebook->set_margin(10);
        m_Notebook->set_expand();
        m_Box.append(*m_Notebook);

        m_Subsystems.erase(m_Subsystems.begin(), m_Subsystems.end());
        // I suspect this leaks.  Strongly suspect

        // create the Subsystems objects
        m_Subsystems.push_back(new GeneralInformationSubsystem(m_appPointer));
        m_Subsystems.push_back(new AeroDynamicsSubsystem(m_appPointer));
        m_Subsystems.push_back(new BuoyantForcesSubsystem(m_appPointer));
        m_Subsystems.push_back(new MetricsSubsystem(m_appPointer));
        m_Subsystems.push_back(new PropulsionSubsystem(m_appPointer));
        m_Subsystems.push_back(new IOSubSystem(m_appPointer));
        m_Subsystems.push_back(new MassBalanceSubsystem(m_appPointer));
        m_Subsystems.push_back(new ExternalReactionsSubsystem(m_appPointer));
        m_Subsystems.push_back(new GroundReactionsSubsystem(m_appPointer));
        m_Subsystems.push_back(new DragDrop::FlightControlSubsystem(m_appPointer));

        // Call Create() for all subsystems
        for (const auto &i : m_Subsystems)
        {
            i->InitializeGui();
            i->LoadFromFile();
            m_Notebook->append_page(i->GetBox(), i->GetName());
        }

        std::cout << "Loaded XML data from: " << xmlptr()->GetFilePath() << std::endl;

        // metric_ptr->load_data(xmlptr());
    }
    void MainWindow::on_notebook_switch_page(Gtk::Widget * /* page */, guint page_num)
    {
        std::cout << "Switched to tab with index " << page_num << std::endl;

        // You can also use m_Notebook.get_current_page() to get this index.
    }

};
