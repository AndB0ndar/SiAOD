SRCMODULES = main.cpp Data.cpp ./BinFl/BinaryFile.cpp ./BinFl/Phone.cpp ./BinFl/TextFile.cpp ./MngHeshTabl/HeshTable.cpp
OBJMODULES = $(SRCMODULES:.cpp=.o)
CXXFLAGS = -Wall -g

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
main: $(OBJMODULES)
	$(CXX) $(CXXFLAGS) $^ -o $@

ifneq (clean, &(MAKECMDGOALS))
-include deps.mk
endif

deps.mk: $(SRCMODULES)
	$(CXX) -MM $^ > $@

run: main
	./main

error: main
	valgrind --tool=memcheck ./main 2> VL_LOG.txt 1> STDOUT.txt

debag: main
	gdb ./main

clean:
	rm -f *.o *.mk main
