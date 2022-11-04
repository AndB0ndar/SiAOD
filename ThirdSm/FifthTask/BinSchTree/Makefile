SRCMODULES = 
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
	valgrind -s --tool=memcheck ./main 2> VL_LOG.txt 1> STDOUT.txt

debag: main
	gdb ./main

clean:
	rm -f *.o *.mk main VL_LOG.txt STDOUT.txt
