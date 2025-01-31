#pragma once
#include <string>
#include <functional>
#include "gtkmm.h"

namespace GUI
{

    class InputField
    {
    public:
        InputField(std::string key);

        virtual void AppendToGrid(const Gtk::Grid &grid, int x, int y, int w = 0, int h = 0) = 0;
        std::string GetKey() const;
        virtual std::string GetData() = 0;
        virtual void SetData(const std::string &val) = 0;
        void SetValidator(std::function<bool(const std::string &)> func);
        virtual bool Validate() = 0;

    protected:
        std::string m_key;
        std::function<bool(const std::string &)> m_validator;
    };

};