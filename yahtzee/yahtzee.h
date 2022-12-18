#ifndef YAHTZEE_DEC
#define YAHTZEE_DEC

#include <iostream>
#include <stdlib.h>
using namespace std;

class die {
	int face;
public:
	die();
	void roll();
	int getFace();
};

class dice {
	die playDice[5];
public:
	int numOf(int face);
	int fullHouse();
	int yahtzee();
	int largeStraight();
	int smallStraight();
	void rollAll();
	void print();
	int chance();
	int threeOfAKind();
	int fourOfAKind();
};

class scoreCard {
private:
	int score[13];
	bool filled[13];
public:
	scoreCard();
	bool getFilled(int category);
	bool allFilled();
	void addScore(int score, int choice);
	int bonus();
	int totalScore();
};

class game {
private:
	dice gameDice;
	scoreCard gameScoreCard;
public:
	void play();
};

#endif