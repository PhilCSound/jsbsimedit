#pragma once
#include <vector>
#include "inc/IObserver.hpp"

class ISubject
{
public:
    ISubject() = default;

    virtual void Notify() = 0;
    void AddObserver(IObserver *obs);
    void ClearAllObservers();

protected:
    std::vector<IObserver *> m_observerList{};
};