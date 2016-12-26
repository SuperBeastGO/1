#include "UndoRedo.h"

CalculatorCommand::CalculatorCommand(char oprt, int num)  
{  
	m_oprt = oprt;
	m_num = num;
}  

void CalculatorCommand::Execute()  
{  
	cout << value;
    switch(m_oprt) 
    { 
      case '+': value += m_num; break; 
      case '-': value -= m_num; break; 
      case '*': value *= m_num; break; 
      case '/': value /= m_num; break; 
    } 
    cout << m_oprt << m_num << '=' << value << endl;
	cout << "Result: " << value << endl << endl;
}

void CalculatorCommand::UnExecute()  
{
	double origin = value;
    switch(m_oprt) 
    { 
      case '+': value -= m_num; break; 
      case '-': value += m_num; break; 
      case '*': value /= m_num; break; 
      case '/': value *= m_num; break; 
    } 
    cout << value << m_oprt << m_num << '=' << origin << endl;
	cout << "Result: " << value << endl << endl;
}  

Calculator::Calculator(Command *pCmd)  
{  
	m_Undo.push(pCmd);  
}

Calculator::~Calculator()  
{  
	while(false == m_Undo.empty())  
	{  
		delete m_Undo.top();  
		m_Undo.pop();  
	}  
	while(false == m_Redo.empty())  
	{  
		delete m_Redo.top();  
		m_Redo.pop();  
	}  
}  
      
void Calculator::ExecuteCommand(Command *pCmd)  
{
	cout << "Do: ";
	pCmd->Execute();  
	m_Undo.push(pCmd);
}  

void Calculator::Undo()  
{  
	if(m_Undo.empty())  
	{  
		cout << "No command to undo.\n";  
		return;  
	}  
	cout << "Undo: ";
	Command *pCmd = m_Undo.top();  
	m_Redo.push(pCmd);  
	m_Undo.pop();
	pCmd->UnExecute();
}  

void Calculator::Redo()  
{  
	if(m_Redo.empty())  
	{  
		cout << "No command to redo.\n";  
		return;  
	}  
	cout << "Redo: ";
	Command *pCmd = m_Redo.top();  
	m_Redo.pop();  
	m_Undo.push(pCmd);
	pCmd->Execute();
}