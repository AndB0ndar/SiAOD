#include <iostream>

using namespace std;

enum { stack_down, stack_up, len=10 };
int *stack = new int[len];
int *st_down = stack;
int *st_up = stack+len-1;

void show(int *arr)
{
	for (int i = 0; i < len; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void push(int x, int *st)
{
	if (st == st_up && st == stack) {
		cout << "error: stack is full" << endl;
		return;
	} else if (st == st_down && st == stack+len-1) {
		cout << "error: stack is empty" << endl;
		return;
	}
	if (st == st_up) {
		(*st_up) = x; //TODO
		st_up = st_up-1;
	} else if (st == st_down) {
		(*st_down) = x;
		st_down = st_down+1;
	} else
		cout << "error" << endl;
}

int main()
{
	for (int i = 0; i < len; i++)
		stack[i] = 0;
	show(stack);
	while (true) {
		int num_s, val;
		cin >> num_s;
		cin >> val;
		switch (num_s) {
		case stack_down:
			push(val, st_down);
			break;
		case stack_up:
			push(val, st_up);
			break;
		default:
			break;
		}
		show(stack);
	}

	return 0;
}
