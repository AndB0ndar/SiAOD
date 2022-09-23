#include <iostream>
#include <string>
#include <time.h>
#include "module.h"

using namespace std;

enum { create, out, addAfter, get_to_index, count, addBefor };

char msg0[] = "\t0. создание текстового файла кодировки ASCII, содержащего десятичные числа по несколько чисел на строке;\n";
char msg1[] = "\t1. вывод содержимого текстового файла;\n";
char msg2[] = "\t2. добавление новой строки в конец файла;\n";
char msg3[] = "\t3. прочитать значение числа, указав его порядковый номер в файле, и вернуть его значение;\n";
char msg4[] = "\t4. определить количество чисел в файле;\n";
char msg5[] = "\t5. добавить в файл новую строку перед первой строкой. Путем создания нового файла.\n";

int main()
{
	srand(time(0));
	string name_file, line;
	int index;
	int cmd;

	cout << "Enter name file:" << endl;
	cin >> name_file;

	cout << "Command:" << endl;
	cout << msg0 << msg1 << msg2 << msg3 << msg4 << msg5;
	cout << "(arbon) ";
	while (cin >> cmd) {
		switch (cmd) {
		case create:
			create_file(name_file);
			break;
		case out:
			cout << "file:" << endl;
			out_file(name_file);
			break;
		case addAfter:
			cout << "enter line: ";
			cin.get();
			getline(cin, line);
			add_after(name_file, line);
			break;
		case get_to_index:
			cout << "enter index: ";
			cin >> index;
			cout << geti(name_file, index) << endl;
			break;
		case count:
			cout << "count = " << count_figure(name_file) << endl;
			break;
		case addBefor:
			cout << "enter line: ";
			cin.get();
			getline(cin, line);
			add_befor(name_file, line);
			break;
		default:
			break;
		}
		cout << "(arbon) ";
	}

	return 0;
}
