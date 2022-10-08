main.o: main.cpp Data.h BinFl/BinaryFile.h BinFl/Phone.h BinFl/Phone.h \
 MngHeshTabl/HeshTable.h
Data.o: Data.cpp Data.h BinFl/BinaryFile.h BinFl/Phone.h BinFl/Phone.h \
 MngHeshTabl/HeshTable.h
BinaryFile.o: BinFl/BinaryFile.cpp BinFl/BinaryFile.h BinFl/Phone.h \
 BinFl/TextFile.h
Phone.o: BinFl/Phone.cpp BinFl/Phone.h
TextFile.o: BinFl/TextFile.cpp BinFl/TextFile.h BinFl/Phone.h
HeshTable.o: MngHeshTabl/HeshTable.cpp MngHeshTabl/HeshTable.h
