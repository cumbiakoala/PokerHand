// Name: Millan Figueroa
// Course: CIS 006 Intro to Programming
// CRN: 44574
// Date: 11/01/17
// Assignment: Pokerhand

#include <iostream>
using namespace std;

const int CARDS_SIZE = 5; //Number of cards in array

bool containsPair(int hand[]);
bool containsTwoPair(int hand[]);
bool containsThreeOfaKind(int hand[]);
bool containsStraight(int hand[]);
bool containsFullHouse(int hand[]);
bool containsFourOfaKind(int hand[]);

main()
{

int hand[CARDS_SIZE];

// Get user to input 5 cards 2-9.

    cout << "Enter five numeric cards, no face cards. Use 2-9." << endl;
    for (int x = 0; x < CARDS_SIZE; x++)
    {
        cout << "Card " << x + 1 << ": ";
        cin >> hand[x];
    }

    if (containsFourOfaKind(hand))
        cout << "Four of a kind!" << endl;
    else if (containsFullHouse(hand) || containsThreeOfaKind(hand))
        cout << "Full House!" << endl;
    else if (containsStraight(hand))
        cout << "Straight!" << endl;
    else if (containsThreeOfaKind(hand))
        cout << "Three of a kind!" << endl;
    else if (containsTwoPair(hand))
        cout << "Two Pair!" << endl;
    else if (containsPair(hand))
        cout << "Pair!" << endl;
    else
        cout << "High Card!" << endl;
        cout << endl;
}

//To see if hand contains four of a kind.

bool containsFourOfaKind(int hand[])
{
    int card_countr = 1;
    for (int x = 0; x < 2; x++, card_countr = 1)
        for (int y = x + 1; y < CARDS_SIZE; y++) {
            if (hand[y] == hand[x])
                card_countr++;
            if (card_countr == 4)
                return true;
        }
    return false;
}


//To see if hand contains a full house.

bool containsFullHouse(int hand[])
{
    if (hand[0] == hand[1] && hand[2] == hand[3] && hand[3] == hand[4])
        return true;
    else if (hand[0] == hand[1] && hand[1] == hand[2] && hand[3] == hand[4])
        return true;
    return false;
}


//To see if hand contains a straight.

bool containsStraight(int hand[])
{
    for (int x = 0; x < CARDS_SIZE -1; x++)
        if (hand[x] != hand[x+1] - 1)
            return false;
    return true;
}


//To see if hand contains three of a kind.

bool containsThreeOfaKind(int hand[])
{
    int card_countr = 1;
    for (int x = 0; x < 3; x++, card_countr = 1)
        for (int y = x + 1; y < CARDS_SIZE; y++) {
            if (hand[y] == hand[x])
                card_countr++;
            if (card_countr == 3)
                return true;
        }
    return false;
}


//To see if hand contains two pair.

bool containsTwoPair(int hand[])
{
    bool firstPair = false;
    bool secondPair = false;

    for (int x = 0; x < CARDS_SIZE -1; x++)
        for (int y = x + 1; y < CARDS_SIZE; y++){
            if (hand[x] == hand[y]) {
                if (!firstPair)
                    firstPair = true;
                else
                    secondPair = true;
                break;
            }
        }
    return firstPair && secondPair;
}


//To see if hand contains a pair.

bool containsPair(int hand[])
{
    for (int x = 0; x < CARDS_SIZE -1; x++)
        for (int y = x + 1; y < CARDS_SIZE; y++)
            if (hand[x] == hand[y])
                return true;
    return false;
}
