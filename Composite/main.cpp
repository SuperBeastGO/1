#include "Composite.h"

int main()
{
	Composite *p = new Composite("Composite");
	Composite *p1 = new Composite("Composite");
	Composite *p1_1 = new Composite("Debug");
	p1_1->add(new Leaf("cl.command.1.tlog"));
	p1_1->add(new Leaf("CL.read.1.tlog"));
	p1_1->add(new Leaf("otherfiles"));
	p1->add(p1_1);
	p1->add(new Leaf("Composite.cpp"));
	p1->add(new Leaf("Composite.h"));
	p1->add(new Leaf("Composite.vcxproj"));
	p1->add(new Leaf("Composite.vcxproj.filters"));
	p1->add(new Leaf("main.cpp"));
	p->add(p1);
	Composite *p2 = new Composite("Debug");
	p2->add(new Leaf("Composite.exe"));
	p2->add(new Leaf("Composite.ilk"));
	p2->add(new Leaf("Composite.pdb"));
	p->add(p2);
	p->add(new Leaf("Composite.opensdf"));
	p->add(new Leaf("Composite.sdf"));
	p->add(new Leaf("Composite.sln"));
	p->add(new Leaf("Composite.v11.suo"));
	p->display(0);
	system("pause");
};