# portfolio
My portfolio

Simplepoly:
The c++ files included define a simplepoly (polynomial) class, implemented in a linked list. The driver file, when run, provides instructions on how to use the class. A couple transcripts are provided that show how the class behaves when certain instructions are given.

Yahtzee:
This project creates a single-player yahtzee game. The dice are rolled and printed, the user is asked to input which score category they would like to score. This repeats until all categories are filled. Then, the total score is printed.
Contributors: Josiah Bates, Alden Bodak, Dylan Coleman
The program itself contains four classes: die, dice, scoreCard, and game. Each class works as expected. Die class has a face that can be rolled. Dice class has 5 dice, all of which can be rolled. The dice class also allows you to count the number of any specific face within the set of dice, making it easy to figure out which score categories are met, and which aren't. The scorecard class contains all score categories, including which of them have been filled and with what scores. The game class has a set of 5 dice and a scorecard. The play method repeatedly rolls dice, and prompts the user to input their choice for score category. The score is then added to the scorecard in the correct category. All input is verified before it is used.
Building: A Makefile is used to build the project. It only has two options: all, which builds the driver but does not actually make the user play a full game, and test_file, which builds and runs the tests to make sure they all pass.
Testing: The catch2 header file is used to run the tests. It was fairly easy to integrate, because it only needs the header file to be included in the tests.cpp file. It also helps to pinpoint exactly which tests do not pass, and why they do not pass. It has various test cases, with various sections, and each test case requries that a certain boolean or equality to be true in order for the test to pass and run correctly.

BGSU Polling Tool:
My Senior capstone project is currently available to see at http://csvm20.cs.bgsu.edu. It may change location as future groups work on it.
