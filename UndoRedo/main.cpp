#include "UndoRedo.h"

int main()  
{  
    Calculator *p = new Calculator(new CalculatorCommand('+', 0));
    p->ExecuteCommand(new CalculatorCommand('+', 4)); //4
	p->ExecuteCommand(new CalculatorCommand('*', 5)); //20
	p->Undo(); //4
	p->ExecuteCommand(new CalculatorCommand('/', 2)); //2
	p->Undo(); //4
	p->Redo(); //2
	p->ExecuteCommand(new CalculatorCommand('-', 3)); //-1
	system("pause");
}