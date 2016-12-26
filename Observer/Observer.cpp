#include "Observer.h"
#include <string>
#include <algorithm>

Subject::Subject()
{
	m_state = "Safe";
}

void Subject::Attach(Observer *pObserver)
{
	cout << "Attach " + pObserver->m_name << endl;
	m_ListObserver.push_back(pObserver);
}

void Subject::Detach(Observer *pObserver)
{
	list<Observer*>::iterator iter;
	iter = std::find(m_ListObserver.begin(), m_ListObserver.end(), pObserver);
	if (m_ListObserver.end() != iter)
		m_ListObserver.erase(iter);
	cout << "Detach " + pObserver->m_name << endl;
}

void Subject::Notify()
{
	list<Observer*>::iterator iter1, iter2;
	for (iter1 = m_ListObserver.begin(), iter2 = m_ListObserver.end(); iter1 != iter2; ++iter1)
		(*iter1)->Update(this);
}

void Subject::ShowObserverState()
{
	cout << "Show Observers' States:\n";
	list<Observer*>::iterator iter1, iter2;
	for (iter1 = m_ListObserver.begin(), iter2 = m_ListObserver.end(); iter1 != iter2; ++iter1)
		cout << (*iter1)->m_name + ": " + (*iter1)->m_state << endl;
	cout << endl;
}

Subject::~Subject()
{
	list<Observer*>::iterator iter1, iter2, temp;
	for (iter1 = m_ListObserver.begin(), iter2 = m_ListObserver.end(); iter1 != iter2;)
	{
		temp = iter1;
		++iter1;
		delete (*temp);
	}
	m_ListObserver.clear();
}

Observer::Observer(string name)
{
	m_state = "Closed";
	m_name = name;
}

void ConcreateSubject::SetState(string state)
{
	m_state = state;
}

string ConcreateSubject::GetState()
{
	return m_state;
}

void ConcreateObserver::Update(Subject* pSubject)
{
	if (NULL == pSubject)
		return;
	if ("Fire" == pSubject->GetState())
		m_state = "Open";
}
