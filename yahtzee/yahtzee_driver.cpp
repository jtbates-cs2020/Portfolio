#include "yahtzee.h"
#include <iostream>

int main() {
	cout << "Yahtzee\n";
	cout << "The following score categories are associated with the respective integers: \n";
	cout << "[0->Ones] " << " [1->Twos] " << " [2->Threes] " << " [3->Fours] " << " [4->Fives] " << " [5->Sixes] " << " [6->Three Of A Kind] \n";
	cout << "[7->Four Of A Kind] " << " [8->Full House] " << " [9->Small Straight] " << " [10->Large Straight] " << " [11->Yahtzee] " << " [12->Chance] \n";
	game mainGame;
	mainGame.play();
	cout << "\nPress any key to exit ";
	cin.get();
	cin.get();
}