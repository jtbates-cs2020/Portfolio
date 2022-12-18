##################################################
# Makefile for yahtzee project

#variables
GPP = g++
HDR = yahtzee.h yahtzee.cpp

#compile yahtzee class
#driver file is used just to give the compiler a main to work with
all: $(HDR) yahtzee_driver.cpp
	$(GPP) yahtzee_driver.cpp yahtzee.cpp -o yahtzee
	echo "In makefile: Succesfully built yahtzee class"

#build tests and run them
test_file: ./tests/tests.cpp $(HDR)
	$(GPP) ./tests/tests.cpp $(HDR) ./tests/catch.h -I./tests -o ./tests/tests_exe
	echo "In makefile: Tests succesfully built. Now running tests"
	./tests/tests_exe