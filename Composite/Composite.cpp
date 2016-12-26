#include"Composite.h"
#include<iostream>

Component::Component(string str)
{
	this->name = str;
}

void Leaf::add(Component *pChild)
{
	cout << "Can't add child to leaf" << endl;
}

void Leaf::display(int depth)
{
	string strTemp;
	for (int i = 0; i < depth; i++)
	{
		strTemp += "--";
	}
	strTemp += this->name;
	cout << strTemp << endl;
}

void Composite::add(Component *pChild)
{
	m_pChild.push_back(pChild);
}

void Composite::display(int depth)
{
	string templine;
	for (int i = 0; i < depth; i++)
	{
		templine += "--";
	}
	templine += this->name;
	cout << templine << endl;
	vector<Component*>::iterator it = m_pChild.begin();
	while (it != m_pChild.end())
	{
		(*it)->display(depth + 1);
		++it;
	}
}