#include <iostream>

using namespace std;

struct item {
	int data;
	item *next;
};

void add_list(item **first, int val)
{
#ifdef DEBUG
	cout << *first << endl;
#endif
	item *tmp = new item;
	tmp->data = val;
	tmp->next = (*first);
	(*first) = tmp;
#ifdef DEBUG
	cout << *first << endl;
#endif
}

void delete_item_to_list(item **first, int val)
{
	if (!(*first)) {
		return;
	} else if (((*first)->next)->data == val) {
		item *tmp = new item;
		tmp = (*first)->next;
		(*first)->next = ((*first)->next)->next;
		delete tmp;
	} else {
		delete_item_to_list(&(*first)->next, val);
	}
}

void show_list(item *first)
{
	if (!first) 
		return;
	cout << first->data << " ";
	show_list(first->next);
}

void merge_list(item **l, item *l1, item *l2)
{
	item *p = l1, *q;
	while (p) {
		bool f = false;
#ifdef DEBUG
		cout << p->data << ": ";
#endif
		q = l2;
		while (q) {
			if (p->data == q->data) {
				f = true;
				delete_item_to_list(&l2, q->data);
				break;
			}
#ifdef DEBUG
		cout << q->data << "-" << f << endl;
#endif
			q = q->next;
		}
		if (f) {
			add_list(l, p->data);
		}
		p = p->next;
	}
}

int main()
{
	int val;
	item *l1 = 0, *l2 = 0;
	item *l = 0;

	cin >> val;
	while (val != -1) {
		add_list(&l1, val);
		cin >> val;
	}
	show_list(l1);
	cout << endl;

	cin >> val;
	while (val != -1) {
		add_list(&l2, val);
		cin >> val;
	}
	show_list(l2);
	cout << endl;

	merge_list(&l, l1, l2);
	show_list(l);
	cout << endl;

	return 0;
}
