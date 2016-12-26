#include "Observer.h"

int main()
{
	Observer *p1 = new ConcreateObserver("Door");
	Observer *p2 = new ConcreateObserver("WindowA");
	Observer *p3 = new ConcreateObserver("WindowB");
	Subject* p = new ConcreateSubject;

	p->Attach(p1);
	p->Attach(p2);
	p->ShowObserverState(); //p1:Closed p2:Closed

	p->SetState("Fire");
	p->Notify();
	p->ShowObserverState(); //p1:Open p2:Open

	p->Detach(p1);
	p->Attach(p3);
	p->Notify();
	p->ShowObserverState(); //p2:Open p3:Open

	p3->m_state = "Closed";
	p->SetState("Safe");
	p->Notify();
	p->ShowObserverState(); //p2:Open p3:Closed

	system("pause");
}
