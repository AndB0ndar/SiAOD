#include <iostream>
//#include <string>
#include "option4.h"

using namespace std;

enum func_list { show=1, search, add, delete_patient, extract, quantity, menu };

void choose(const func_list flag, patient **first, patient **last)
{
	char date[max_len_date];
	int key, num, diagnosis;

	switch (flag) {
	case show:
		show_dlist((*first), (*last));
		break;
	case search:
		patient *tmp;
		cout << "Enter number medical policy ";
		cin >> num;
		tmp = search_root((*first), num);
		cout << tmp << endl;
		cout << "num= " << tmp->number << endl;
		break;
	case add:
		cout << "Enter" << endl << "number before which insert ";
		cin >> key;
		cout << "number medical policy ";
		cin >> num;
		cout << "date ";
		cin >> date;
		cout << "diagnosis number ";
		cin >> diagnosis;

		add_befor(&(*first), &(*last), key, num, date, diagnosis);
		break;
	case delete_patient:
		int diagnosis;
		cout << "Enter diagnosis number to delete ";
		cin >> diagnosis;

		delete_by_val(&(*first), &(*last), diagnosis);
		break;
	case extract:
		patient *nfirst, *nlast;
		nfirst = nlast = 0;
		cout << "Enter number medical policy ";
		cin >> key;
		extract_in_list(&nfirst, &nlast, (*first), key);
		show_dlist(nfirst, nlast);
		break;
	case quantity:
		cout << "Enter" << endl << "date ";
		cin >> date;
		cout << "diagnosis number ";
		cin >> diagnosis;
		cout << "number = " << research((*first), date, diagnosis) << endl;
		break;
	case menu:
		show_menu();
		break;
	default:
		break;
	}
}

int main()
{
	patient *first = 0, *last = 0;
	int f;

#if 0
	char date[max_len_date] = "1.1.2000";
	int tmp_key[] = { 5, 5, 5, 8, 11 };
	int tmp_num[] = { 5, 3, 12, 3, 11 };
	int tmp_d[] = { 5, 3, 3, 8, 3 };
	for (int i = 0; i < 5; i++) {
		add_befor(&first, &last, tmp_key[i], tmp_num[i], date, tmp_d[i]);
	}
	show_dlist(first, last);
#endif

	show_menu();
	while ((f = cin.get()) != EOF) {
		f -= '0';
		choose((func_list)f, &first, &last);
	}

	return 0;
}
