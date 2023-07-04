#include <iostream>

using namespace std;

#include "arr_stack.h"
#include "struct_stack.h"

enum { stack_down, stack_up, len=10 };

int main()
{
	cout << "Array stack:" << endl;
	int *astack = new int[1];
	astack[0] = 0;
	if (afull(astack))
		cout << "stack is full" << endl;
	if (aempty(astack))
		cout << "stack is empty" << endl;
	for (int i = 0; i < 5; i++)
		apush(rand()%10, &astack);
	ashow(astack);
	cout << endl;
	cout << apop(&astack) << endl;
	cout << apop(&astack) << endl;
	ashow(astack);
	cout << endl;
	cout << aget(astack) << endl;
	if (afull(astack))
		cout << "stack is full" << endl;
	if (aempty(astack))
		cout << "stack is empty" << endl;
	cout << endl;

	cout << "Struct stack:" << endl;
	sitem *sstack = new sitem;
	sstack = 0;
	if (sfull(sstack))
		cout << "stack is full" << endl;
	if (sempty(sstack))
		cout << "stack is empty" << endl;
	for (int i = 0; i < 5; i++)
		spush(rand()%10, &sstack);
	sshow(sstack);
	cout << endl;
	cout << spop(&sstack) << endl;
	cout << spop(&sstack) << endl;
	sshow(sstack);
	cout << endl;
	cout << sget(sstack) << endl;
	if (sfull(sstack))
		cout << "stack is full" << endl;
	if (sempty(sstack))
		cout << "stack is empty" << endl;
	return 0;
}
