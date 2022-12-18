#define CATCH_CONFIG_MAIN

#include <iostream>
#include "../yahtzee.h"
#include "../tests/catch.h"

TEST_CASE("Testing Die Class", "[die]") {
	die test_die;
	SECTION("testing constructor") {
		REQUIRE(test_die.getFace() == 1);
	}
	SECTION("testing roll method") {
		test_die.roll();
		REQUIRE(test_die.getFace());
		REQUIRE(test_die.getFace() <= 6);
		REQUIRE(test_die.getFace() >= 1);
	}
}

TEST_CASE("Testing Dice Class", "[dice]") {
	dice test_dice;
	SECTION("testing constructor") {
		REQUIRE(test_dice.numOf(1) == 5);
	}
	SECTION("testing numOf") {
		REQUIRE(test_dice.numOf(2) == 0);
		REQUIRE(test_dice.numOf(3) == 0);
		REQUIRE(test_dice.numOf(4) == 0);
		REQUIRE(test_dice.numOf(5) == 0);
		REQUIRE(test_dice.numOf(6) == 0);
	}
	SECTION("Testing roll_all") {
		test_dice.rollAll();
		REQUIRE(test_dice.numOf(0) == 0);
		REQUIRE(test_dice.numOf(7) == 0);
	}
	SECTION("Testing full house") {
		REQUIRE(test_dice.fullHouse() == 25);
	}
	SECTION("Testing yahtzee") {
		REQUIRE(test_dice.yahtzee() == 50);
	}
	SECTION("Testing Large Straight") {
		REQUIRE(test_dice.largeStraight() == 0);
	}
	SECTION("Testing small straight") {
		REQUIRE(test_dice.smallStraight() == 0);
	}
	SECTION("Testing chance") {
		REQUIRE(test_dice.chance() == 5);
	}
	SECTION("Testing 3 of a kind") {
		REQUIRE(test_dice.threeOfAKind() == 5);
	}
	SECTION("Testing 4 of a kind") {
		REQUIRE(test_dice.fourOfAKind() == 5);
	}
}
TEST_CASE("Testing scoreCard class", "[scoreCard]") {
	scoreCard test;
	SECTION("Testing constructor") {
		REQUIRE(test.totalScore() == 0);
		for (int i = 0; i < 13; i++) {
			REQUIRE(!(test.getFilled(i)));
		}
	}
	SECTION("testing addScore and getFilled") {
		test.addScore(30, 0);
		REQUIRE(test.totalScore() == 30);
		REQUIRE(test.getFilled(0));
		test.addScore(20, 1);
		REQUIRE(test.totalScore() == 50);
		REQUIRE(test.getFilled(1));
	}
	SECTION("Testing allFilled") {
		for (int i = 0; i < 12; i++) {
			test.addScore(20, i);
		}
		REQUIRE(test.totalScore() == 275);
		REQUIRE(!(test.allFilled()));
		test.addScore(20, 12);
		REQUIRE(test.totalScore() == 295);
		REQUIRE(test.allFilled());
	}
	SECTION("Testing bonus") {
		test.addScore(62, 0);
		REQUIRE(test.bonus() == 0);
		test.addScore(1, 1);
		REQUIRE(test.bonus() == 35);
		test.addScore(5, 2);
		REQUIRE(test.bonus() == 35);
	}
}
TEST_CASE("Testing Game Class", "[game]") {
	game test_game;
	dice test_dice;
	dice test_gameDice;
	SECTION("testing case 0") {
		REQUIRE(test_dice.numOf(1) <= 5);
	}
	SECTION("testing case 1") {
		REQUIRE(test_dice.numOf(2) <= 10);
	}
	SECTION("testing case 2") {
		REQUIRE(test_dice.numOf(3) <= 15);
	}
	SECTION("testing case 3") {
		REQUIRE(test_dice.numOf(4) <= 20);
	}
	SECTION("testing case 4") {
		REQUIRE(test_dice.numOf(5) <= 25);
	}
	SECTION("testing case 5") {
		REQUIRE(test_dice.numOf(6) <= 30);
	}
	SECTION("testing case 6") {
		REQUIRE(test_gameDice.threeOfAKind() <= 30);
	}
	SECTION("testing case 7") {
		REQUIRE(test_gameDice.fourOfAKind() <= 30);
	}
	SECTION("testing case 8") {
		REQUIRE(test_gameDice.fullHouse() == 25);
	}
	SECTION("testing case 9") {
		REQUIRE(test_gameDice.smallStraight() <= 30);
	}
	SECTION("testing case 10") {
		REQUIRE(test_gameDice.largeStraight() <= 30);
	}
	SECTION("testing case 11") {
		REQUIRE(test_gameDice.yahtzee() == 50);
	}
	SECTION("testing case 12") {
		REQUIRE(test_gameDice.chance() <= 30);
	}
}
