SRCMODULES = main.cpp HashTable.cpp
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
	valgrind -s --tool=memcheck --leak-check=full ./main 2> VL_LOG.txt 1> STDOUT.txt

clean:
	rm -f *.o *.mk main
