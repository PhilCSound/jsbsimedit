#include "Systems/FlightControlSubsystem.hpp"
#include "FlightControlSubsystem.hpp"

namespace DragDrop
{

    FlightControlSubsystem::FlightControlSubsystem(std::shared_ptr<Gtk::Application> &app)
        : m_systemName("flight_control"), Subsystem{"Flight Control", app}, m_canvas(app, "flight_control")
    {
    }

    std::vector<std::optional<std::string>> FlightControlSubsystem::InitializeGui()
    {
        std::vector<std::optional<std::string>> errors{};

        m_boxLayout.set_orientation(Gtk::Orientation::VERTICAL);
        try
        {
            m_refBuilder = Gtk::Builder::create_from_file("../../../flightControl.xml");
        }
        catch (const Glib::Error &ex)
        {
            errors.push_back({"Error loading flightControl.xml\n"});
            return errors;
        }

        std::vector<std::string> widgetContainers{"stackBox", "componentBox", "dividerBox", "canvasBox"};
        // Get all the box widgets, and add them to a container widget:
        for (auto &i : widgetContainers)
        {
            auto boxWidget = m_refBuilder->get_widget<Gtk::Box>(i);
            if (boxWidget)
            {
                // if canvasBox append the canvas to it, sorry about one line if
                if (i == "canvasBox")
                {
                    boxWidget->append(m_canvas);
                    boxWidget->show();
                }
                if (i == "stackBox")
                {
                    boxWidget->append(m_notebook);
                    boxWidget->show();
                }
                m_boxLayout.append(*boxWidget);
            }
            else
            {
                errors.push_back({"Error loading GUI widget in Flight Control.\n"});
                return errors;
            }
        }

        // Get all the image widgets, and add them to a container widget:
        for (int i = 0; i < COMPONENT_NAMES.size(); i++)
        {
            auto imgWidget = m_refBuilder->get_widget<Gtk::Image>(COMPONENT_NAMES[i]);
            if (imgWidget)
            {
                auto dragController = Gtk::DragSource::create();
                dragController->property_content().set_value(SetDragData(i));
                imgWidget->add_controller(dragController);
            }
            else
                errors.push_back({"Error finding: " + COMPONENT_NAMES[i] + " widget.\n"});
        }
        m_notebook.set_hexpand(true);
        m_notebook.set_show_border(false);
        // signal handler for changing channel tabs
        m_notebook.signal_switch_page().connect(sigc::mem_fun(*this, &FlightControlSubsystem::on_notebook_switch_page));
        return errors;
    }

    void FlightControlSubsystem::LoadDefault()
    {
    }

    std::vector<std::optional<std::string>> FlightControlSubsystem::LoadFromFile()
    {
        std::vector<std::optional<std::string>> errors;

        auto node = xmlptr()->GetNode("fdm_config").FindChild(m_systemName);
        if (!node)
            errors.push_back({"Error loading: " + m_systemName + " from file.\n"});
        else
        {
            for (auto &i : node.GetChildren())
            {
                if (i.GetName() == "channel")
                {
                    auto nameAtt = i.GetAttribute("name");
                    if (nameAtt.second.empty())
                    {
                        errors.push_back({"Error loading: " + m_systemName + " from file.\n"});
                        continue;
                    }
                    if (m_canvas.CreateNewChannel(nameAtt.second))
                    {
                        CreateNewTab(nameAtt.second);
                        m_canvas.LoadChannelFromXml(nameAtt.second, i);
                    }
                }
                else
                    std::cout << i.GetText() << "\n";
            }
        }
        return errors;
    }

    std::vector<std::optional<std::string>> FlightControlSubsystem::Validate()
    {
        return std::vector<std::optional<std::string>>();
    }

    void FlightControlSubsystem::CreateNewTab(const std::string &name)
    {
        Gtk::Box emptyBox{};
        m_notebook.append_page(emptyBox, name);
        m_notebook.show();
    }

    Glib::RefPtr<Gdk::ContentProvider> FlightControlSubsystem::SetDragData(int _data)
    {
        Glib::Value<int> data;
        data.init(data.value_type());
        data.set(_data);
        return Gdk::ContentProvider::create(data);
    }

    void FlightControlSubsystem::on_notebook_switch_page(Gtk::Widget *wid, guint page_num)
    {
        // not gonna lie i copied the function prototype above from the examplewindow.cpp
        auto nameClicked = m_notebook.get_tab_label_text(*wid);
        // std::cout << nameClicked << "\n";
        m_canvas.SetCurrentChannelName(nameClicked);
    }
};
