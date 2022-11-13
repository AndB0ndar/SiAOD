main.o: main.cpp ../BinFl/BinaryFile.h ../BinFl/Phone.h Tree.h
Tree.o: Tree.cpp Tree.h Phone.h
Phone.o: Phone.cpp Phone.h
BinaryFile.o: BinaryFile.cpp BinaryFile.h Phone.h TextFile.h
TextFile.o: TextFile.cpp TextFile.h Phone.h
