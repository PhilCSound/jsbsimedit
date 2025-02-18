#pragma once

#include "gtkmm/application.h"
#include "MainWindow/MainWindow.hpp"

namespace JSBEdit
{

    class Application
    {
    private:
        Glib::RefPtr<Gtk::Application> m_pApp;
        Glib::ustring m_appPath;

    public:
        Application();
        int Run(int argc, char *argv[]);
        int Stop();
        Glib::ustring GetApplicationPath();
    };

};
