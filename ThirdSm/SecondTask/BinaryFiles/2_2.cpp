#include <iostream>
#include <string>
#include <fstream>
#include "module.h"

using namespace std;

enum { pr_exit, conv_ttb, conv_btt, out_bf, access, remove_rc };

int main()
{
	string textf, binf;

	cout << "Name for text file: ";
	cin >> textf;
	cout << "Name for binary file: ";
	cin >> binf;

	ifstream ft, fb;
	ft.open(textf, ios::in);
	fb.open(binf, ios::in | ios::binary);
	if (ft.fail() || fb.fail()) {
		cout << "файл не открыт";
		return 1;
	}
	ft.close();
	fb.close();
	ifstream fbb;
	fbb.open(binf, ios::in | ios::binary);

	cout << "Command:" << endl;
	cout << msg0 << msg1 << msg2 << msg3 << msg4;
	cout << "(arbon) ";
	phone_owner *pw;
	string number;
	int cmd;
	while (cin >> cmd) {
		switch (cmd) {
		case pr_exit:
			return 0;
		case conv_ttb:
			converting_text_to_binary(textf, binf);
			break;
		case conv_btt:
			converting_binary_to_text(binf, textf);
			break;
		case out_bf:
			out_bin_file(binf);
			break;
		case access:
			int index;
			cout << "enter index: ";
			cin >> index;
			pw = get(binf, index);
			cout << pw->number << " ;";
			cout << pw->address << " ;";
			cout << pw->name << endl;
			break;
		case remove_rc:
			cout << "enter line: ";
			cin.get();
			getline(cin, number);
			remove_record(binf, number);
			break;
		default:
			break;
		}
		if(!fbb.good()) {
			cout << "Ошибка ввода" << endl;
			return 1;
		}
		cout << "(arbon) ";
	}

	return 0;
}
