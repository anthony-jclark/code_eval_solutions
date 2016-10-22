
EXENAME = longestlines.out
CXXFLAGS = -Wall -std=c++14
TESTHEADER = ../../../extras/Catch/single_include/

all:program test

program:
	@echo "Compiling the main program"
	@echo "Adding extension .out to the binary for .gitignore"
	$(CXX) $(CXXFLAGS) -o $(EXENAME) longestLines.cpp

test:
	@echo "Compiling the test executable"
	$(CXX) $(CXXFLAGS) -o test_$(EXENAME) -I$(TESTHEADER) test_longestLines.cpp

clean:
	@echo "No object files to clean for this project"

distclean: clean
	$(RM) $(EXENAME)
	$(RM) test_$(EXENAME)
