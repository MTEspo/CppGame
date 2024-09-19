#include "dice.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <regex>

using namespace std;

int dice::roll(string diceString) {
    regex pattern("(\\d+)d(4|6|8|10|12|20|100)(\\+(\\d+))?");
    smatch match;

    if (regex_match(diceString, match, pattern)) {
        int numDice = stoi(match[1]);
        int sides = stoi(match[2]);
        int modifier = 0;
        if (match[4].matched) {
            modifier = stoi(match[4]);
        }

        return rollDice(numDice, sides) + modifier;
    } else {
        cerr << "Invalid dice string format: " << diceString << endl;
        return -1;
    }
};

int dice::rollDice(int numDice, int sides) {
    int total = 0;
    for (int i = 0; i < numDice; ++i) {
        total += rand() % sides + 1;
    }
    return total;
};
