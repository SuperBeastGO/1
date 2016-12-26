#include<string>
#include<vector>

using namespace std;

class Component
{
protected:
	string name;
public:
	Component(string str);
	virtual void add(Component *pChild) = 0;
	virtual void display(int depth) = 0;
};

class Leaf: public Component
{
public:
	Leaf(string str): Component(str){}
	virtual void add(Component *pChild);
	virtual void display(int depth);
};

class Composite: public Component
{
private:
	vector<Component*> m_pChild;
public:
	Composite(string strName): Component(strName){}
	virtual void add(Component *pChild);
	virtual void display(int depth);
};
