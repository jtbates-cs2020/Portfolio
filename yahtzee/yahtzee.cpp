#include <iostream>
#include <stdlib.h>
#include "yahtzee.h"
using namespace std;

die::die() {
		face = 1;
		srand(time(0));
}

void die::roll() {
	face = (rand() % 6 + 1);
}

int die::getFace() {
	return face;
}

void dice::rollAll() {
		for (int i = 0; i < 5; ++i) {
			playDice[i].roll();
		}
}
void dice::print() {
		for (int i = 0; i < 5; i++) {
			cout << playDice[i].getFace() << ' ';
		}
		cout << endl;
}
int dice::chance() {
	int total = 0;
	for (int i = 0; i < 5; i++) {
		total += playDice[i].getFace();
	}
	return total;
}
int dice::threeOfAKind() {
	for (int i = 1; i <= 6; i++) {
		if (numOf(i) >= 3) return chance();
	}
	return 0;
}
int dice::fourOfAKind() {
	for (int i = 1; i <= 6; i++) {
		if (numOf(i) >= 4) return chance();
	}
	return 0;
}
int dice::numOf(int face) {
	int total = 0;
	for (int i = 0; i < 5; i++) {
		if (playDice[i].getFace() == face) total++;
	}
	return total;
}

int dice::fullHouse() {
	for (int i = 1; i <= 6; i++) {
		if (numOf(i) == 1) return 0;
		if (numOf(i) == 4) return 0;
	}
	return 25;
}

int dice::yahtzee() {
	for (int i = 1; i <= 6; i++) {
		if (numOf(i) == 5) return 50;
	}
	return 0;
}

int dice::largeStraight() {
	if (numOf(1) && numOf(2) && numOf(3) && numOf(4) && numOf(5)) return 40;
	if (numOf(2) && numOf(3) && numOf(4) && numOf(5) && numOf(6)) return 40;
	return 0;
}

int dice::smallStraight() {
	if (numOf(1) && numOf(2) && numOf(3) && numOf(4)) return 30;
	if (numOf(2) && numOf(3) && numOf(4) && numOf(5)) return 30;
	if (numOf(3) && numOf(4) && numOf(5) && numOf(6)) return 30;
	return 0;
}

scoreCard::scoreCard() {
	for (int i = 0; i < 13; i++) {
		score[i] = 0;
		filled[i] = false;
	}
}

void scoreCard::addScore(int score, int choice) {
		this->score[choice] = score;
		filled[choice] = true;
};

int scoreCard::bonus() {
	int total = 0;
	for (int i = 0; i < 6; i++) {
		total += score[i];
	}
	if (total >= 63) {
		cout << "Bonus added!\n";
		return 35;
	}
	else return 0;
}
int scoreCard::totalScore() {
	int scoreTotal = 0;
	for (int i = 0; i < 13; i++) {
		scoreTotal += score[i];
	}
	scoreTotal += bonus();
	return scoreTotal;
}

bool scoreCard::getFilled(int category) {
	return filled[category];
}

bool scoreCard::allFilled() {
	for (int i = 0; i < 13; i++) {
		if (!(this->filled[i])) return false;
	}
	return true;
}

void game::play() {
	int scoreToAdd = 0;
	int choice = 0;
	while (!(gameScoreCard.allFilled())) {
		gameDice.rollAll();
		gameDice.print();
		cout << "Enter your score category choice: ";
		cin >> choice;
		while (choice < 0 || choice > 12) {
			cout << "Enter a valid number: ";
			cin >> choice;
		}
		while (gameScoreCard.getFilled(choice)) {
			cout << "Enter a category that has not been filled: ";
			cin >> choice;
		}
		switch (choice) {
		case 0:
			scoreToAdd = gameDice.numOf(1);
			cout << "Aces; ";
			break;
		case 1:
			scoreToAdd = 2 * gameDice.numOf(2);
			cout << "Twos; ";
			break;
		case 2:
			scoreToAdd = 3 * gameDice.numOf(3);
			cout << "Threes; ";
			break;
		case 3:
			scoreToAdd = 4 * gameDice.numOf(4);
			cout << "Fours; ";
			break;
		case 4:
			scoreToAdd = 5 * gameDice.numOf(5);
			cout << "Fives; ";
			break;
		case 5:
			scoreToAdd = 6 * gameDice.numOf(6);
			cout << "Sixes; ";
			break;
		case 6:
			scoreToAdd = gameDice.threeOfAKind();
			cout << "Three of a kind; ";
			break;
		case 7:
			scoreToAdd = gameDice.fourOfAKind();
			cout << "Four of a kind; ";
			break;
		case 8:
			scoreToAdd = gameDice.fullHouse();
			cout << "Full house; ";
			break;
		case 9:
			scoreToAdd = gameDice.smallStraight();
			cout << "Small straight; ";
			break;
		case 10:
			scoreToAdd = gameDice.largeStraight();
			cout << "Large straight; ";
			break;
		case 11:
			scoreToAdd = gameDice.yahtzee();
			cout << "Yahtzee; ";
			break;
		case 12:
			scoreToAdd = gameDice.chance();
			cout << "Chance; ";
			break;
		}
		cout << "Score: " << scoreToAdd << endl;
		gameScoreCard.addScore(scoreToAdd, choice);
	}
	cout << "Game completed. Total Score: " << gameScoreCard.totalScore() << endl;
}
