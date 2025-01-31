#include "InputField.hpp"

namespace GUI
{
    InputField::InputField(std::string key)
        : m_key(key)
    {
    }

    std::string InputField::GetKey() const
    {
        return m_key;
    }

    void InputField::SetValidator(std::function<bool(const std::string &)> func)
    {
        m_validator = func;
    }
};