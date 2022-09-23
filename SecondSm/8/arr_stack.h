#ifndef	ARR_STACK_H
#define ARR_STACK_H

int alen(int *arr)
{
	int i = 0;
	while (arr[i])
		i++;
	return i+1;
}

void ashow(int *arr)
{
	for (int i = 0; i < alen(arr); i++)
		cout << arr[i] << " ";
}

void apush(int x, int **stk)
{
	int *tmp = (*stk);
	*stk = new int[alen(*stk)+1];
	int i = 0;
	(*stk)[i] = x;
	for (i = 1; tmp[i-1]; i++)
		(*stk)[i] = tmp[i-1];
	(*stk)[i] = 0;
	delete tmp;
}

int apop(int **stk)
{
	int *tmp = (*stk);
	*stk = new int[alen(*stk)];
	int val = tmp[0];
	int i = 0;
	for (i = 0; tmp[i+1]; i++)
		(*stk)[i] = tmp[i+1];
	(*stk)[i] = 0;
	delete tmp;
	return val;
}

int aget(int *stk)
{
	return stk[0];
}

bool afull(int *stk)
{
	if (stk && alen(stk)>1)
		return true;
	else
		return false;
}

bool aempty(int *stk)
{
	if (!stk[0] && alen(stk)==1)
		return true;
	else
		return false;
}

#endif
