#ifndef OPTION4_H
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
