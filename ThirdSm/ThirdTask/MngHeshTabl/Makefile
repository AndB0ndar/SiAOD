SRCMODULES = testHeshT.cpp HeshTable.cpp
OBJMODULES = $(SRCMODULES:.cpp=.o)
CXXFLAGS = -Wall -g

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
testHeshT: $(OBJMODULES)
	$(CXX) $(CXXFLAGS) $^ -o $@

ifneq (clean, &(MAKECMDGOALS))
-include deps.mk
endif

deps.mk: $(SRCMODULES)
	$(CXX) -MM $^ > $@

run: testHeshT
	./testHeshT

error: testHeshT
	valgrind -s --tool=memcheck --leak-check=full ./testHeshT 2> VL_LOG.txt 1> STDOUT.txt

clean:
	rm -f *.o *.mk testHeshT
