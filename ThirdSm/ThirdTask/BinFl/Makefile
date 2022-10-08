SRCMODULES = testBinF.cpp BinaryFile.cpp Phone.cpp TextFile.cpp
OBJMODULES = $(SRCMODULES:.cpp=.o)
CXXFLAGS = -Wall -g

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
testBinF: $(OBJMODULES)
	$(CXX) $(CXXFLAGS) $^ -o $@

ifneq (clean, &(MAKECMDGOALS))
-include deps.mk
endif

deps.mk: $(SRCMODULES)
	$(CXX) -MM $^ > $@

run: testBinF
	./testBinF

error: testBinF
	valgrind --tool=memcheck ./testBinF 2> VL_LOG.txt 1> STDOUT.txt

debag: testBinF
	gdb ./testBinF

clean:
	rm -f *.o *.mk testBinF
