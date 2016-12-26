#include <list>
#include <iostream>

using namespace std;

class Observer;

class Subject
{
protected:
	string m_state;
	list<Observer*> m_ListObserver;
public:
	Subject();
	virtual ~Subject();
	void Attach(Observer *pObserver);
	void Detach(Observer *pObserver);
	void Notify();
	void ShowObserverState();
	virtual void SetState(string state) = 0;
	virtual string GetState() = 0;
};

class ConcreateSubject: public Subject
{
public:
	ConcreateSubject(): Subject(){}
	virtual ~ConcreateSubject(){}
	virtual void SetState(string state);
	virtual string GetState();
};

class Observer
{
public:
	string m_name;
	string m_state;
	Observer(string name);
	virtual ~Observer(){}
	virtual void Update(Subject* pSubject) = 0;
};

class ConcreateObserver: public Observer
{
public:
	ConcreateObserver(string name): Observer(name){}
	virtual ~ConcreateObserver(){}
	virtual void Update(Subject* pSubject);
};
