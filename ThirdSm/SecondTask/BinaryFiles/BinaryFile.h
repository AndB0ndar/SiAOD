#ifndef MODUL_H
#define MODUL_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>
#include "Phone.h"

const char msg0[] = "1. преобразование тестовых данных из текстового файла в двоичный файл;\n";
const char msg1[] = "2. преобразование данных из двоичного файла в текстовый;\n";
const char msg2[] = "3. вывод всех записей двоичного файла;\n";
const char msg3[] = "4. доступ к записи по ее порядковому номеру в файле, используя механизм прямого доступа к записи в двоичном файле;\n";
const char msg4[] = "5. удаление записи с заданным значением ключа, выполнить путем замены на последнюю запись.\n";


class BinaryFile {
public:
    void Write(std::string name, std::vector<Phone> autos);
    void Read(std::string name, std::vector<Phone> &autos);
    void Output(std::string name);
    const Phone& Get(std::string name, int index) const;
    void DellPhone(std::string name, int index);
};

#endif
