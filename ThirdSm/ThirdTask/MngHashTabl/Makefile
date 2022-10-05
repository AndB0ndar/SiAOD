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

clean:
	rm -f *.o *.mk main
