# 17ClassB
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

/*******************************
*
* Yahtzee
*
* Starter code by Paul Wilkins
* Last Modified: 11/18/2013
*
*newly modified: 2/11/17; Jonathon Tupper
*******************************/

using namespace std;

void printRoll(int n1, int n2, int n3, int n4, int n5);
bool askReroll(int n);
void printSeparator();
void printScore(int onesScore, int twosScore, int threesScore, int foursScore,
	int fivesScore, int sixesScore, int threeOfAKind,
	int fourOfAKind, int fullHouse, int smallStraight,
	int largeStraight, int yahtzee, int chance);
void printScoreLine(string name, int score);
int getScoreOption(int onesScore, int twosScore, int threesScore, int foursScore,
	int fivesScore, int sixesScore, int threeOfAKind,
	int fourOfAKind, int fullHouse, int smallStraight,
	int largeStraight, int yahtzee, int chance);
int tabulateDice(int n, int d1, int d2, int d3, int d4, int d5);

const int NUM_CATEGORIES = 13;
const int SIDES = 6;
const int EMPTY = -1;
enum Category {
	ONES = 1, TWOS, THREES, FOURS, FIVES, SIXES, THREE_OF_A_KIND,
	FOUR_OF_A_KIND, FULL_HOUSE, SMALL_STRAIGHT, LARGE_STRAIGHT,
	YAHTZEE, CHANCE
};

//function prototypes
int scoreOnes(int ones, int twos, int threes, int fours, int fives, int sixes);
int scoreTwos(int ones, int twos, int threes, int fours, int fives, int sixes);
int scoreThrees(int ones, int twos, int threes, int fours, int fives, int sixes);
int scoreFours(int ones, int twos, int threes, int fours, int fives, int sixes);
int scoreFives(int ones, int twos, int threes, int fours, int fives, int sixes);
int scoreSixes(int ones, int twos, int threes, int fours, int fives, int sixes);
int scoreThreeOfAKind(int ones, int twos, int threes, int fours, int fives, int sixes);
int scoreFourOfAKind(int ones, int twos, int threes, int fours, int fives, int sixes);
int scoreFullHouse(int ones, int twos, int threes, int fours, int fives, int sixes);
int scoreSmallStraight(int ones, int twos, int threes, int fours, int fives, int sixes);
int scoreLargeStraight(int ones, int twos, int threes, int fours, int fives, int sixes);
int scoreYahtzee(int ones, int twos, int threes, int fours, int fives, int sixes);
int scoreChance(int ones, int twos, int threes, int fours, int fives, int sixes);

//helper function prototypes
int getScore(int multiplier, int num);
int ofAKind (int numOfAKind, int ones, int twos, int threes, int fours, int fives, int sixes);
bool straight (int sSize, int ones, int twos, int threes, int fours, int fives, int sixes);


int main()
{

	int die1, die2, die3, die4, die5;
	bool redo1, redo2, redo3, redo4, redo5;

	int ones, twos, threes, fours, fives, sixes;

	int onesScore, twosScore, threesScore, foursScore, fivesScore, sixesScore;
	int threeOfAKind;
	int fourOfAKind;
	int fullHouse;
	int smallStraight;
	int largeStraight;
	int yahtzee;
	int chance;

	onesScore = twosScore = threesScore = foursScore = fivesScore = sixesScore = EMPTY;
	threeOfAKind = fourOfAKind = fullHouse = smallStraight = largeStraight = yahtzee = chance = EMPTY;

	cout << "Welcome to Yahtzee!" << endl;
	srand(time(0));



	for (int turn = 0; turn < NUM_CATEGORIES; turn++)
	{
		int round = 1;
		ones = twos = threes = fours = fives = sixes = 0;
		die1 = rand() % SIDES + 1;
		die2 = rand() % SIDES + 1;
		die3 = rand() % SIDES + 1;
		die4 = rand() % SIDES + 1;
		die5 = rand() % SIDES + 1;

		printRoll(die1, die2, die3, die4, die5);

		do
		{
			redo1 = askReroll(1);
			redo2 = askReroll(2);
			redo3 = askReroll(3);
			redo4 = askReroll(4);
			redo5 = askReroll(5);

			if (redo1)
			{
				die1 = rand() % SIDES + 1;
			}
			if (redo2)
			{
				die2 = rand() % SIDES + 1;
			}
			if (redo3)
			{
				die3 = rand() % SIDES + 1;
			}
			if (redo4)
			{
				die4 = rand() % SIDES + 1;
			}
			if (redo5)
			{
				die5 = rand() % SIDES + 1;
			}

			printRoll(die1, die2, die3, die4, die5);
			round++;
		} while ((redo1 || redo2 || redo3 || redo4 || redo5) && round < 3);

		ones = tabulateDice(1, die1, die2, die3, die4, die5);
		twos = tabulateDice(2, die1, die2, die3, die4, die5);
		threes = tabulateDice(3, die1, die2, die3, die4, die5);
		fours = tabulateDice(4, die1, die2, die3, die4, die5);
		fives = tabulateDice(5, die1, die2, die3, die4, die5);
		sixes = tabulateDice(6, die1, die2, die3, die4, die5);

		int scoreOption = getScoreOption(onesScore, twosScore, threesScore, foursScore,
			fivesScore, sixesScore, threeOfAKind,
			fourOfAKind, fullHouse, smallStraight,
			largeStraight, yahtzee, chance);

		switch (scoreOption)
		{
		case ONES:
		onesScore = scoreOnes(ones, twos, threes, fours, fives, sixes);
		break;
		case TWOS:
		twosScore = scoreTwos(ones, twos, threes, fours, fives, sixes);
		break;
		case THREES:
		threesScore = scoreThrees(ones, twos, threes, fours, fives, sixes);
		break;
		case FOURS:
		foursScore = scoreFours(ones, twos, threes, fours, fives, sixes);
		break;
		case FIVES:
		fivesScore = scoreFives(ones, twos, threes, fours, fives, sixes);
		break;
		case SIXES:
		sixesScore = scoreSixes(ones, twos, threes, fours, fives, sixes);
		break;
		case THREE_OF_A_KIND:
		threeOfAKind = scoreThreeOfAKind(ones, twos, threes, fours, fives, sixes);
		break;
		case FOUR_OF_A_KIND:
		fourOfAKind = scoreFourOfAKind(ones, twos, threes, fours, fives, sixes);
		break;
		case FULL_HOUSE:
		fullHouse= scoreFullHouse(ones, twos, threes, fours, fives, sixes);
		break;
		case SMALL_STRAIGHT:
		smallStraight = scoreSmallStraight(ones, twos, threes, fours, fives, sixes);
		break;
		case LARGE_STRAIGHT:
		largeStraight = scoreLargeStraight(ones, twos, threes, fours, fives, sixes);
		break;
		case YAHTZEE:
		yahtzee = scoreYahtzee(ones, twos, threes, fours, fives, sixes);
		break;
		case CHANCE:
		chance = scoreChance(ones, twos, threes, fours, fives, sixes);
		break;
		}

		printScore(onesScore, twosScore, threesScore, foursScore, fivesScore, sixesScore,
			threeOfAKind, fourOfAKind, fullHouse, smallStraight, largeStraight, yahtzee, chance);
	}
}

/*********************************************************
*
* printRoll
* ------------------
* This function prints out the current state of the dice,
* with blank lines before and after the print-out.
*
*********************************************************/
void printRoll(int n1, int n2, int n3, int n4, int n5)
{
	cout << endl;
	cout << "Your roll is:" << endl;
	cout << n1 << " " << n2 << " " << n3 << " " << n4 << " " << n5 << endl;
	cout << endl;
}

/*********************************************************
*
* askReroll
* ------------------
* This function ask the user if they'd like to reroll one
* one of the dice.  The function takes an integer which is
* the number of the die being rerolled, and returns true if
* the die should be rerolled, false otherwise.  The integer
* argument is used only for instruction display, this function
* does not actually reroll any dice.  Responses accepted are
* 'Y', 'N', 'y', and 'n'.
*
*********************************************************/
bool askReroll(int n)
{
	char ch;
	while (true)
	{
		cout << "Would you like to reroll die " << n << "? (Y/N) ";
		cin >> ch;
		switch (ch)
		{
		case 'Y': case 'y':
			return true;
		case 'N': case 'n':
			return false;
		default:
			cout << "Invalid response" << endl;
		}
	}

}



/********************************
*
* printScore
* --------------------
* This function prints out the complete score table
* for the yahtzee game in its current state.
*
********************************/
void printScore(int onesScore, int twosScore, int threesScore, int foursScore,
	int fivesScore, int sixesScore, int threeOfAKind,
	int fourOfAKind, int fullHouse, int smallStraight,
	int largeStraight, int yahtzee, int chance)
{
	printSeparator();
	printScoreLine("Ones", onesScore);
	printSeparator();
	printScoreLine("Twos", twosScore);
	printSeparator();
	printScoreLine("Threes", threesScore);
	printSeparator();
	printScoreLine("Fours", foursScore);
	printSeparator();
	printScoreLine("Fives", fivesScore);
	printSeparator();
	printScoreLine("Sixes", sixesScore);
	printSeparator();
	printScoreLine("Three of a kind", threeOfAKind);
	printSeparator();
	printScoreLine("Four of a kind", fourOfAKind);
	printSeparator();
	printScoreLine("Full House", fullHouse);
	printSeparator();
	printScoreLine("Small Straight", smallStraight);
	printSeparator();
	printScoreLine("Large Straight", largeStraight);
	printSeparator();
	printScoreLine("Yahtzee", yahtzee);
	printSeparator();
	printScoreLine("Chance", chance);
	printSeparator();
}

/********************************
*
* printSeperator
* --------------------
* This helper function prints out a single
* separator line used as part of the score
* printing function.
*
********************************/
void printSeparator()
{
	cout << "+-------------------+-------+" << endl;
}

/********************************
*
* printScoreLine
* --------------------
* This function prints out a single line of the score.
* The string argument is the name of the category, while
* the in is the value of the score.  The category name is left
* aligned, while the score value is right aligned.
*
********************************/
void printScoreLine(string name, int score)
{
	cout << "| " << left << setw(18) << name << "| ";
	if (score >= 0)
	{
		cout << right << setw(5) << score;
	}
	else
	{
		cout << "     ";
	}
	cout << " |" << endl;
}

/********************************
*
* getScoreOption
* --------------------
* This function gets the score category which the player wishes to score
* with the current roll.  The function ensures that the response corresponds
* to a valid category.  It also check to make sure that the selected category
* has not yet been scored (unscored categories contain the value EMPTY).
*
********************************/
int getScoreOption(int onesScore, int twosScore, int threesScore, int foursScore,
	int fivesScore, int sixesScore, int threeOfAKind,
	int fourOfAKind, int fullHouse, int smallStraight,
	int largeStraight, int yahtzee, int chance)
{
	int ans;
	bool valid = false;
	cout << "Here are the categories: " << endl;
	cout << "1. Ones" << endl;
	cout << "2. Twos" << endl;
	cout << "3. Threes" << endl;
	cout << "4. Fours" << endl;
	cout << "5. Fives" << endl;
	cout << "6. Sixes" << endl;
	cout << "7. Three of a kind" << endl;
	cout << "8. Four of a kind" << endl;
	cout << "9. Full House" << endl;
	cout << "10. Small Straight" << endl;
	cout << "11. Large Straight" << endl;
	cout << "12. Yahtzee" << endl;
	cout << "13. Chance" << endl;
	do
	{
		cout << "How would you like to score this? ";
		cin >> ans;
		while (ans < 0 || ans > NUM_CATEGORIES)
		{
			cout << "Please enter a number between 1 and " << NUM_CATEGORIES << ": ";
			cin >> ans;
		}
		switch (ans)
		{
		case ONES:
			if (onesScore == EMPTY) valid = true;
			break;
		case TWOS:
			if (twosScore == EMPTY) valid = true;
			break;
		case THREES:
			if (threesScore == EMPTY) valid = true;
			break;
		case FOURS:
			if (foursScore == EMPTY) valid = true;
			break;
		case FIVES:
			if (fivesScore == EMPTY) valid = true;
			break;
		case SIXES:
			if (sixesScore == EMPTY) valid = true;
			break;
		case THREE_OF_A_KIND:
			if (threeOfAKind == EMPTY) valid = true;
			break;
		case FOUR_OF_A_KIND:
			if (fourOfAKind == EMPTY) valid = true;
			break;
		case FULL_HOUSE:
			if (fullHouse == EMPTY) valid = true;
			break;
		case SMALL_STRAIGHT:
			if (smallStraight == EMPTY) valid = true;
			break;
		case LARGE_STRAIGHT:
			if (largeStraight == EMPTY) valid = true;
			break;
		case YAHTZEE:
			if (yahtzee == EMPTY) valid = true;
			break;
		case CHANCE:
			if (chance == EMPTY) valid = true;
			break;
		}
		if (!valid)
		{
			cout << "That category has already been used" << endl;
		}
	} while (!valid);

	return ans;
}

/********************************
*
* tabulateDice
* --------------------
* This function calculates and returns the number of dice
* which show the value n.
*
********************************/
int tabulateDice(int n, int d1, int d2, int d3, int d4, int d5)
{
	int ans = 0;
	if (d1 == n) ans++;
	if (d2 == n) ans++;
	if (d3 == n) ans++;
	if (d4 == n) ans++;
	if (d5 == n) ans++;
	return ans;
}

/********************************
*
* getScore Helper Function
* --------------------
* This function returns the count multiplied by the multiplier
*
********************************/
int getScore(int multiplier, int num)
{
	return multiplier*num;
}

/********************************
*
* scoreOnes
* --------------------
* This function returns the ones score multiplied by 1,
* since it's just the same I left out the multiplication
*
********************************/
int scoreOnes(int ones, int twos, int threes, int fours, int fives, int sixes)
{
    return getScore(1, ones);
}
/********************************
*
* scoreTwos
* --------------------
* This function returns the twos multiplied by 2 to get the twos score
*
********************************/
int scoreTwos(int ones, int twos, int threes, int fours, int fives, int sixes)
{
    return getScore(2, twos);
}

/********************************
*
* scoreThrees
* --------------------
* This function returns the threes multiplied by 3 to get the threes score
*
********************************/
int scoreThrees(int ones, int twos, int threes, int fours, int fives, int sixes)
{
    return getScore(3, threes);
}

/********************************
*
* scoreFours
* --------------------
* This function returns the fours multiplied by 4 to get the fours score
*
********************************/
int scoreFours(int ones, int twos, int threes, int fours, int fives, int sixes)
{
    return getScore(4, fours);
}

/********************************
*
* scoreFives
* --------------------
* This function returns the fives multiplied by 5 to get the Fives score
*
********************************/
int scoreFives(int ones, int twos, int threes, int fours, int fives, int sixes)
{
    return getScore(5, fives);
}

/********************************
*
* scoreSixes
* --------------------
* This function returns the sixes multiplied by 6 to get the sixes score
*
********************************/
int scoreSixes(int ones, int twos, int threes, int fours, int fives, int sixes)
{
    return getScore(6, sixes);
}

/********************************
*
* ofAKind Helper Function
* --------------------
* This function checks to see if any of the counts are equal to the requested
* number of a kind and returns the count multiplied by the number of a kind
*
********************************/
int ofAKind (int numOfAKind, int ones, int twos, int threes, int fours, int fives, int sixes)
{
    if(ones == numOfAKind)  return ones*numOfAKind;
    if(twos == numOfAKind) return twos*numOfAKind;
    if(threes == numOfAKind)return threes*numOfAKind;
    if(fours == numOfAKind)return fours*numOfAKind;
    if(fives == numOfAKind) return fives*numOfAKind;
    if(sixes == numOfAKind)  return sixes*numOfAKind;
    return 0;
}
/********************************
*
* scoreThreeOfAKind
* --------------------
* This function returns the result of ofAKind with 3 as the numOfAKind argument
* to see if there is 3 of a kind
*
********************************/
int scoreThreeOfAKind(int ones, int twos, int threes, int fours, int fives, int sixes)
{
    return ofAKind (3, ones, twos, threes, fours, fives, sixes);
}

/********************************
*
* scoreFourOfAKind
* --------------------
* This function returns the result of ofAKind with 4 as the numOfAKind argument
* to see if there is 4 of a kind
*
********************************/
int scoreFourOfAKind(int ones, int twos, int threes, int fours, int fives, int sixes)
{
    return ofAKind (4, ones, twos, threes, fours, fives, sixes);
}

/********************************
*
* scoreFullHouse
* --------------------
* This function returns 25 (the score for a full house) if there is 3 of a kind
* and 2 of a kind at the same time
*
********************************/
int scoreFullHouse(int ones, int twos, int threes, int fours, int fives, int sixes)
{
    if(ofAKind(3, ones, twos, threes, fours, fives, sixes) && ofAKind(2, ones, twos, threes, fours, fives, sixes)) return 25;
    return 0;
}

/********************************
*
* straight Helper Function
* --------------------
* This function stores all the counts into an array, then checks for consecutive numbers
* up to the sSize number by shifting the point of reference one by one up to the remainder
* of six divided by the requested number of consecutive rolls (sSize) to keep it within the
* bounds of the array numRoll is not used to set the bounds of the array because you can't
* initialize a dynamic array
*
********************************/
bool straight (int sSize, int ones, int twos, int threes, int fours, int fives, int sixes)
{
    int numRoll = 6;
    int shifts = numRoll%sSize;
    int rolls [6] = {ones, twos, threes, fours, fives, sixes};

    for (int curShift = 0; curShift < shifts; curShift++){
        int straightCount = 0;
        for (int i = curShift; i < numRoll; i++){
            if (rolls[i] > 0) straightCount++;
            else {
                    if(straightCount > 0) straightCount = 0;
            }
        }
        if(straightCount >= sSize) return true;
    }

    return false;
}
/********************************
*
* scoreSmallStraight
* --------------------
* This function returns the result of straight with 4 as the consecutive
* number count and returns 30 (score for a small straight) if there is a small straight
*
********************************/
int scoreSmallStraight(int ones, int twos, int threes, int fours, int fives, int sixes)
{
    if(straight(4, ones, twos, threes, fours, fives, sixes)) return 30;
    return 0;
}
/********************************
*
* scoreLargeStraight
* --------------------
* This function returns the result of straight with 5 as the consecutive
* number count and returns 40 (score for a small straight) if there is a small straight
*
********************************/
int scoreLargeStraight(int ones, int twos, int threes, int fours, int fives, int sixes)
{
    if(straight(5, ones, twos, threes, fours, fives, sixes)) return 40;
    return 0;
}
/********************************
*
* scoreYahtzee
* --------------------
* This function gets the result of ofAKind with 5 as the numOfAKind argument
* to see if there is 5 of a kind or a yahtzee then returns 50 (score for a yahtzee) if there is 5 of a kind
*
********************************/
int scoreYahtzee(int ones, int twos, int threes, int fours, int fives, int sixes)
{
    int y = ofAKind(5, ones, twos, threes, fours, fives, sixes)/5;
    if(y == 5) return 50;
    return 0;
}
/********************************
*
* scoreYahtzee
* --------------------
* multiplies each counter by it's counted value then adds them together and returns the result
*
********************************/
int scoreChance(int ones, int twos, int threes, int fours, int fives, int sixes)
{
    return ones + twos*2 + threes*3 + fours*4 + fives*5 + sixes*6;
}
