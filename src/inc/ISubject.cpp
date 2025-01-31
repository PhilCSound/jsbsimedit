#include "ISubject.hpp"

void ISubject::AddObserver(IObserver *obs)
{
    m_observerList.push_back(obs);
}

void ISubject::ClearAllObservers()
{
    m_observerList.clear();
}
