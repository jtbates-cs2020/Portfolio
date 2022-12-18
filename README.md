# portfolio
My portfolio

Simplepoly:
The c++ files included define a simplepoly (polynomial) class, implemented in a linked list. The driver file, when run, provides instructions on how to use the class. A couple transcripts are provided that show how the class behaves when certain instructions are given.

Yahtzee:
This project creates a single-player yahtzee game. The dice are rolled and printed, the user is asked to input which score category they would like to score. This repeats until all categories are filled. Then, the total score is printed.
Contributors: Josiah Bates, Alden Bodak, Dylan Coleman
The program itself contains four classes: die, dice, scoreCard, and game. Each class works as expected. Die class has a face that can be rolled. Dice class has 5 dice, all of which can be rolled. The dice class also allows you to count the number of any specific face within the set of dice, making it easy to figure out which score categories are met, and which aren't. The scorecard class contains all score categories, including which of them have been filled and with what scores. The game class has a set of 5 dice and a scorecard. The play method repeatedly rolls dice, and prompts the user to input their choice for score category. The score is then added to the scorecard in the correct category. All input is verified before it is used.
