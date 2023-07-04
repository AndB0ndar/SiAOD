#include <iostream>
#include "option4.h"

using namespace	std;

static int str_len(const char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return i;
}

static void str_cp(char **str_s, const char *str_d)
{
	(*str_s) = new char[str_len(str_d)+1];
	int i;
	for (i = 0; str_d[i]; i++)
		(*str_s)[i] = str_d[i];
	(*str_s)[i] = '\0';
}

static bool str_cmp(const char *str_s, const char *str_d)
{
	for (int i = 0; str_d[i]; i++)
		if (str_s[i] != str_d[i])
			return false;
	return true;
}

patient *search_root(patient *pos, int key)
{
	if (!pos)
		return NULL;
	if (key == pos->number)
		return pos;
	else
		return search_root(pos->next, key);
}

void show_menu()
{
	cout << "==================" << endl;
	cout << "show = 1" << endl;
	cout << "search = 2" << endl;
	cout << "add = 3" << endl;
	cout << "delete_patient = 4" << endl;
	cout << "extract = 5" << endl;
	cout << "quantity = 6" << endl; 
	cout << "menu = 7" << endl; 
	cout << "==================" << endl;
}

static void show_dlist_right(const patient *first)
{
	if (!first) {
		cout << endl;
		return;
	}
	cout << "num = " << first->number << endl;
	cout.width(len_field);
	cout << first->date << endl;
	cout.width(len_field);
	cout << first->diagnosis << endl;
	cout << "==" << endl;
	show_dlist_right(first->next);
}

static void show_dlist_left(const patient *last)
{
	if (!last) {
		cout << endl;
		return;
	}
	cout << "num = " << last->number << endl;
	cout.width(len_field);
	cout << last->date << endl;
	cout.width(len_field);
	cout << last->diagnosis << endl;
	cout << "==" << endl;
	show_dlist_left(last->prev);
}

void show_dlist(const patient *first, const patient *last)
{
	show_dlist_right(first);
	show_dlist_left(last);
}

void add_befor(patient **first, patient **last,
		int key, int number, char *str, int diag)
{
	patient *current = *first;
	patient *tmp = new patient;
	tmp->number = number;
	str_cp(&tmp->date, str);
	tmp->diagnosis = diag;

	while (current) {
		if (current->number == key) {
			tmp->next = current;
			tmp->prev = current->prev;
			current->prev = tmp;
			if (!tmp->prev) {
				(*first) = tmp;
				return;
			}
			tmp->prev->next = tmp;
			return;
		}
		current = current->next;
	}
		tmp->next = 0;
	if (!(*first)) {
		tmp->prev = 0;
		(*first) = tmp;
		(*last) = tmp;
	} else {
		tmp->prev = (*last);
		tmp->prev->next = tmp;
		(*last) = tmp;
	}
}

void delete_by_val(patient **first, patient **last, int diag)
{
	patient *del = *first;
	while (del) {
		patient *ather_del, *prev_del;
		if (del->diagnosis == diag) {
			ather_del = del->next;
			prev_del = del->prev;
			if (ather_del)
				ather_del->prev = prev_del;
			else
				*last = prev_del;
			if (prev_del)
				prev_del->next = ather_del;
			else
				*first = ather_del;
			delete del;
		}
		del = del->next;
	}
}

static void add_list(patient **first, patient **last, const patient *item)
{
	patient *tmp = new patient;
	tmp->number = item->number;
	str_cp(&tmp->date, item->date);
	tmp->diagnosis = item->diagnosis;
	tmp->next = 0;
	if (!(*last)) {
		tmp->prev = 0;
		*first = *last = tmp;
	} else {
		tmp->prev = (*last);
		(*last)->next = tmp;
		*last = tmp;
	}
}

void extract_in_list(patient **new_list_first, patient **new_list_last,
		const patient *pos, int key)
{
	while (pos) {
		if (pos->number == key)
			add_list(new_list_first, new_list_last, pos);
		pos = pos->next;
	}
}

int research(const patient *pos, const char *date, int diag)
{
	if (!pos)
		return 0;
	if (pos->diagnosis == diag && str_cmp(pos->date, date))
		return 1 + research(pos->next, date, diag);
	else
		return research(pos->next, date, diag);
}
