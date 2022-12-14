./2_4.cpp                                                                                           0000664 0001751 0001751 00000001467 14247621536 011275  0                                                                                                    ustar   andre                           andre                                                                                                                                                                                                                  #include <iostream>
#include <ctime>

using namespace std;

void qsort(int *arr, int low, int hight, unsigned int &cf, unsigned int &mf)
{
	int check = arr[(low+hight)/2];
	int i = low, j = hight;
	do {
		while (cf++, arr[i] < check)
			i++;
		while (cf++, arr[j] > check)
			j--;
		if (cf++, i <= j) {
			mf++;
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	} while (cf++, ++i <= --j);
	if (cf++, i < hight)
		qsort(arr, i, hight, cf, mf);
	if (cf++, j > low)
		qsort(arr, low, j, cf, mf);
}

int main()
{
	int len;
	unsigned int t1, t2, cf = 0, mf = 0;

	cin >> len;
	int *arr = new int[len];
	for (int i = 0; i < len; i++)
		arr[i] = rand()%10;

	t1 = clock();
	qsort(arr, 0, len-1, cf, mf);
	t2 = clock();

	cout << len << endl;
	cout << t2 - t1 << endl;
	cout << "cf + mf = " << cf + mf;

	return 0;
}
                                                                                                                                                                                                         ./3_1.cpp                                                                                           0000664 0001751 0001751 00000003370 14247621536 011266  0                                                                                                    ustar   andre                           andre                                                                                                                                                                                                                  #include <iostream>
#include <ctime>

using namespace std;

void merge_sort(int *arr, int low, int interm, int hight, unsigned int &cf, unsigned int &mf)
{
	int u = 0, i = low, j = interm + 1;
	int len = hight - low + 1;
	int *tmp = new int [len];

#if DEBUG
	cout << i << "=" << j << ": ";
	for (int e = low; e <= hight; e++) {
		cout << arr[e] << " ";
	}
	cout << endl;
#endif

	while ((cf++, i <= interm) && (cf++, j <= hight)) {
		if (cf++, arr[i] <= arr[j]) {
			mf++;
			tmp[u++] = arr[i++];
		} else if (cf++, arr[i] > arr[j]) {
			mf++;
			tmp[u++] = arr[j++];
		}
	}
	if (cf++, i <= interm) {
		for (; cf++, i <= interm; i++, u++) {
			mf++;
			tmp[u] = arr[i];
		}
	}
	else if (cf++, j <= hight) {
		for (; cf++, j <= hight; j++, u++) {
			mf++;
			tmp[u] = arr[j];
		}
	}

#if DEBUG
	cout << low << " " << u << "| ";
	for (int e = low; e <= hight; e++) {
		cout << tmp[e-low] << " ";
	}
	cout << endl;
#endif

	for (int e = low; cf++, e <= hight; e++) {
		mf++;
		arr[e] = tmp[e-low];
	}

	delete [] tmp;
}

void merge(int *arr, int low, int hight, unsigned int &cf, unsigned int &mf)
{
	if (low >= hight)
		return;
	int interm = (low + hight) / 2;
	merge(arr, low, interm, cf, mf);
	merge(arr, interm + 1, hight, cf, mf);
	merge_sort(arr, low, interm, hight, cf, mf);
}

int main()
{
	int len;
	unsigned int t1, t2, cf = 0, mf = 0;

	cin >> len;
	int *arr = new int[len];
	for (int i = 0; i < len; i++)
		arr[i] = rand()%10;

#if DEBUG
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
#endif

	t1 = clock();
	merge(arr, 0, len-1, cf, mf);
	t2 = clock();

#if DEBUG
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
#endif

	cout << len << endl;
	cout << t2 - t1 << endl;
	cout << "cf + mf = " << cf + mf;

	return 0;
}
                                                                                                                                                                                                                                                                        ./4.cpp                                                                                             0000664 0001751 0001751 00000001317 14247621536 011046  0                                                                                                    ustar   andre                           andre                                                                                                                                                                                                                  #include <iostream>
#include <ctime>

using namespace std;

int search(int *arr, int len, int value, unsigned int &cf)
{
	int i;
	int tmp_n = arr[len-1];
	arr[len-1] = value;

	for (i = 0; cf++, arr[i] != value; i++)
		;

	if ((cf++, i != len-1) || (cf++, tmp_n == value))
		return i;
	else 
		return -1;
}

int main()
{
	int len, x;
	int pos, pos2, num = 12;
	unsigned int t1, t2, cf = 0;

	cin >> len;
	pos = rand()%len;
	int *arr = new int[len];
	for (int i = 0; i < len; i++)
		arr[i] = rand()%10;
	arr[pos] = num;

	cin >> x;

	t1 = clock();
	pos2 = search(arr, len, x, cf);
	t2 = clock();

	cout << len << endl;
	cout << pos << " " << pos2 << endl;
	cout << t2 - t1 << endl;
	cout << "cf = " << cf;

	return 0;
}
                                                                                                                                                                                                                                                                                                                 ./5_1.cpp                                                                                           0000664 0001751 0001751 00000001675 14247621536 011276  0                                                                                                    ustar   andre                           andre                                                                                                                                                                                                                  #include <iostream>
#include <ctime>
#include "sort.h"

using namespace std;

int bin_search(int *arr, int value, int low, int hight, unsigned int &cf)
{
	int interm = (low+hight)/2;
	if (cf++, value < arr[interm])
		return bin_search(arr, value, low, interm, cf);
	else if (cf++, value > arr[interm])
		return bin_search(arr, value, interm+1, hight, cf);
	else if (cf++, value == arr[interm])
		return interm;
	else
		return -1;
}

int main()
{
	int len, x;
	int pos, pos2;
	unsigned int t1, t2, cf = 0;

	cin >> len;
	int *arr = new int[len];
	for (int i = 0; i < len; i++)
		arr[i] = rand()%10;
	pos = rand()%len;
	arr[pos] = 13;

	merge(arr, 0, len-1);

#ifdef DEBUG
	for (int i = 0; i < len; i++)
		cout << arr[i] << " ";
	cout << endl;
#endif

	cin >> x;

	t1 = clock();
	pos2 = bin_search(arr, x, 0, len-1, cf);
	t2 = clock();

	cout << len << endl;
	cout << "index= " << pos2 << endl;
	cout << t2 - t1 << endl;
	cout << "cf = " << cf;

	return 0;
}
                                                                   ./6_3.cpp                                                                                           0000664 0001751 0001751 00000001776 14247621536 011303  0                                                                                                    ustar   andre                           andre                                                                                                                                                                                                                  #include <iostream>

using namespace std;

int cf = 0, mf = 0;
enum { len_buf = 256 };
const char str[] = "Usually, people in Russia give presents to their \
					family and friends. As for gifts for children, \
					these are brought by Grandfather Frost ??? \
					the Russian version of Santa Claus.";


int str_len(const char *str)
{
	int i;
	for (i = 0; str[i]; i++)
		;
	return i;
}

int bm_search(const char *str, const char *imag, const int *d, int len_i)
{
	int i = len_i-1, j = i;
	while (cf++, str[i]) {
		if (cf++, str[i] == imag[j]) {
			if (cf++, !j)
				return i;
			mf++;
			i--;
			j--;
		} else {
			mf++;
			i += d[(int)str[i]];
			j = len_i-1;
		}
	}
	return -1;
}

int main()
{
	char imag[] = "Russia";

	int len_i = str_len(imag);
	int d[len_buf];

	for (int i = 0; i < len_buf; i++)
		d[i] = len_i;
	for (int i = 0; imag[i]; i++)
		d[(int)imag[i]] = len_i-1-i;

	cout << bm_search(str, imag, d, len_i) << endl;
	cout << "cf = " << cf << " mf = " << mf << endl;
	cout << cf+mf << endl;

	return 0;
}
  ./7_1_2.cpp                                                                                         0000664 0001751 0001751 00000002646 14247621536 011520  0                                                                                                    ustar   andre                           andre                                                                                                                                                                                                                  #include <iostream>

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
                                                                                          ./7_2_4.cpp                                                                                         0000664 0001751 0001751 00000003624 14247621623 011515  0                                                                                                    ustar   andre                           andre                                                                                                                                                                                                                  #include <iostream>
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
                                                                                                            ./8_1.cpp                                                                                           0000664 0001751 0001751 00000002264 14247621645 011275  0                                                                                                    ustar   andre                           andre                                                                                                                                                                                                                  #include <iostream>

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
                                                                                                                                                                                                                                                                                                                                            ./8_2_3.cpp                                                                                         0000664 0001751 0001751 00000001677 14247621645 011527  0                                                                                                    ustar   andre                           andre                                                                                                                                                                                                                  #include <iostream>

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
                                                                 ./arr_stack.h                                                                                       0000664 0001751 0001751 00000001467 14247621651 012325  0                                                                                                    ustar   andre                           andre                                                                                                                                                                                                                  #ifndef	ARR_STACK_H
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
                                                                                                                                                                                                         ./option4.cpp                                                                                       0000664 0001751 0001751 00000007000 14247621623 012267  0                                                                                                    ustar   andre                           andre                                                                                                                                                                                                                  #include <iostream>
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
./option4.h                                                                                         0000664 0001751 0001751 00000001167 14247621626 011747  0                                                                                                    ustar   andre                           andre                                                                                                                                                                                                                  #ifndef OPTION4_H
#define OPTION4_H

enum { max_len_date = 11, len_field = 12 };

struct patient {
	int number;
	char *date;
	int diagnosis;
	patient *next;
	patient *prev;
};

void show_menu();
void show_dlist(const patient *first, const patient *last);
patient *search_root(patient *pos, int key);

void add_befor(patient **first, patient **last,
		int key, int number, char *str, int daig);
void delete_by_val(patient **first, patient **last, int diag);
void extract_in_list(patient **new_list_first, patient **new_list_last,
		const patient *pos, int key);
int research(const patient *pos, const char *date, int diag);

#endif
                                                                                                                                                                                                                                                                                                                                                                                                         ./sorting.cpp                                                                                       0000664 0001751 0001751 00000002121 14247621536 012362  0                                                                                                    ustar   andre                           andre                                                                                                                                                                                                                  #include <iostream>
#include "sort.h"

void qsort(int *arr, int low, int hight)
{
	int check = arr[(low+hight)/2];
	int i = low, j = hight;
	do {
		while (arr[i] < check)
			i++;
		while (arr[j] > check)
			j--;
		if (i <= j) {
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	} while (++i <= --j);
	if (i < hight)
		qsort(arr, i, hight);
	if (j > low)
		qsort(arr, low, j);
}

void merge_sort(int *arr, int low, int interm, int hight)
{
	int u = 0, i = low, j = interm + 1;
	int len = hight - low + 1;
	int *tmp = new int [len];

	while (i <= interm && j <= hight)
		if (arr[i] <= arr[j])
			tmp[u++] = arr[i++];
		else if (arr[i] > arr[j])
			tmp[u++] = arr[j++];

	if (i <= interm)
		for (;i <= interm; i++, u++)
			tmp[u] = arr[i];
	else if (j <= hight)
		for (;j <= hight; j++, u++)
			tmp[u] = arr[j];

	for (int e = low; e <= hight; e++)
		arr[e] = tmp[e-low];

	delete [] tmp;
}

void merge(int *arr, int low, int hight)
{
	if (low >= hight)
		return;
	int interm = (low + hight) / 2;
	merge(arr, low, interm);
	merge(arr, interm + 1, hight);
	merge_sort(arr, low, interm, hight);
}
                                                                                                                                                                                                                                                                                                                                                                                                                                               ./struct_stack.h                                                                                    0000664 0001751 0001751 00000001227 14247621651 013057  0                                                                                                    ustar   andre                           andre                                                                                                                                                                                                                  #ifndef STRUCT_STACK_H
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
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         