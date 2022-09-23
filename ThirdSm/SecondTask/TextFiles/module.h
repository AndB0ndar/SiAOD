#ifndef MODUL_ONE_H
#define MODUL_ONE_H

#include <string>

void create_file(std::string name_file);

void out_file(std::string name_file);

void add_after(std::string name_file, std::string new_line);

int geti(std::string name_file, int index);

int count_figure(std::string name_file);

void add_befor(std::string name_file, std::string new_line);
#endif
