#include "BinaryFile.h"
#include "TextFile.h"

using namespace std;

enum { conv_ttb, conv_btt, out_bf, access, remove_rc };

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
	//ifstream fbb;
	//fbb.open(binf, ios::in | ios::binary);

	BinaryFile binfl(binf);
	TextFile txtfl(textf);
	int index;
	vector<Phone> phones;

	cout << "Command:" << endl;
	cout << msg0 << msg1 << msg2 << msg3 << msg4;
	cout << "(arbon) ";
	int cmd;
	while (cin >> cmd) {
		switch (cmd) {
		case conv_ttb:
			txtfl.Read(phones);
			for (Phone ph: phones) {
				cout << ph.String() << endl;
			}
			binfl.Write(phones);
			phones.clear();
			break;
		case conv_btt:
			binfl.Read(phones);
			for (Phone ph: phones) {
				cout << ph.String() << endl;
			}
			txtfl.Write(phones);
			phones.clear();
			break;
		case out_bf:
			binfl.Output();
			break;
		case access:
			cout << "Enter index: ";
			cin >> index;
			cout << "Phone: " << endl;
			cout << binfl.Get(index).String();
			break;
		case remove_rc:
			cout << "Enter index: ";
			cin >> index;
			binfl.DellPhone(index);
			break;
		default:
			return 0;
		}
		/*
		if(!fbb.good()) {
			cout << "Ошибка ввода" << endl;
			return 1;
		}
		*/
		cout << "(arbon) ";
	}

	return 0;
}
