testBinF.o: testBinF.cpp BinaryFile.h Phone.h
BinaryFile.o: BinaryFile.cpp BinaryFile.h Phone.h TextFile.h
Phone.o: Phone.cpp Phone.h
TextFile.o: TextFile.cpp TextFile.h Phone.h
