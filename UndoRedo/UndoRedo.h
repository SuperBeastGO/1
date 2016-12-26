#include <iostream>  
#include <stack>  
#include <string>  

using namespace std;

static double value = 0;

class Command  
{
public:  
    Command(){}  
    virtual ~Command(){}
    virtual void Execute() = 0;
	virtual void UnExecute() = 0; 
};

class CalculatorCommand: public Command
{
private:  
    char m_oprt;
	double m_num;
public:  
	CalculatorCommand(char oprt, int num);
    ~CalculatorCommand(){}  
    void Execute();
	void UnExecute();
};  

class Calculator
{
private:
    stack<Command*> m_Undo;
    stack<Command*> m_Redo;
public:  
    Calculator(Command *pCmd);
    ~Calculator();
    void ExecuteCommand(Command *pCmd);
    void Undo();
    void Redo();
};  
