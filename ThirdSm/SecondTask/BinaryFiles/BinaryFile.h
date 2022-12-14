#ifndef MODUL_H
#define MODUL_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>
#include "Phone.h"

const char msg0[] = "0. преобразование тестовых данных из текстового файла в двоичный файл;\n";
const char msg1[] = "1. преобразование данных из двоичного файла в текстовый;\n";
const char msg2[] = "2. вывод всех записей двоичного файла;\n";
const char msg3[] = "3. доступ к записи по ее порядковому номеру в файле, используя механизм прямого доступа к записи в двоичном файле;\n";
const char msg4[] = "4. удаление записи с заданным значением ключа, выполнить путем замены на последнюю запись;\n";
const char msg5[] = "5. Сформировать текстовый файл из фамилий владельцев, чьи номера начинаются с введенных первых трех цифр (например, 434);\n";
const char msg6[] = "6. Удалить сведения о владельцах телефонов, которые начинаются с заданной цифры;\n";


class BinaryFile {
	std::string name;
public:
	BinaryFile(const std::string nm): name(nm) {}
    void Write(const std::vector<Phone> phs);
    void Read(std::vector<Phone> &phs);
    void Output();
    const Phone& Get(const unsigned index) const;
    void DellPhone(const unsigned index);
	void GenNwFile(const std::string num, const std::string name);
	void DellCertPhone(const char ch);
};

#endif
