main.o: main.cpp BinaryFile.h Phone.h ../MngHashTabl/HashTable.h
BinaryFile.o: BinaryFile.cpp BinaryFile.h Phone.h \
 ../MngHashTabl/HashTable.h TextFile.h
Phone.o: Phone.cpp Phone.h
TextFile.o: TextFile.cpp TextFile.h Phone.h
HashTable.o: ../MngHashTabl/HashTable.cpp ../MngHashTabl/HashTable.h
