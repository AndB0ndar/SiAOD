#ifndef STRUCT_STACK_H
#define STRUCT_STACK_H

struct sitem
{
	int value;
	sitem *next;
};

void sshow(sitem *item)
{
	if (!item)
		return;
	cout << item->value << " ";
	sshow(item->next);
}

void spush(int x, sitem **first)
{
	sitem *tmp = new sitem;
	tmp->value = x;
	tmp->next = (*first);
	(*first) = tmp;
}

int spop(sitem **first)
{
	int val = (*first)->value;
	sitem *tmp = (*first);
	(*first) = (*first)->next;
	delete tmp;
	return val;
}

int sget(sitem *first)
{
	return first->value;
}

bool sfull(sitem *first)
{
	if (first)
		return true;
	else
		return false;
}

bool sempty(sitem *first)
{
	if (first)
		return false;
	else
		return true;
}

#endif
