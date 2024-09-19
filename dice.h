#ifndef DICE_H_
#define DICE_H_

#include <string>

/**
 * @file dice.h
 * @brief Header file for the Dice class.
 * 
 * @details This file declares the Dice class, which provides support for rolling dice in the game.
 */

/**
 * @class dice
 * @brief Provides support for rolling dice.
 * 
 * @details The Dice class allows rolling any number of dice of one kind at once using a specific format.
 */
class dice {
public:
    /**
     * @brief Rolls dice based on the provided dice string.
     * 
     * @param diceString The string representing the dice to roll (e.g., "3d6+2").
     * @return The result of rolling the dice as an integer value.
     * 
     * @details This method parses the dice string, rolls the individual dice, adds any modifier, and returns the result.
     */
    static int roll(std::string diceString);

private:
    /**
     * @brief Rolls a specific number of dice with a given number of sides.
     * 
     * @param numDice The number of dice to roll.
     * @param sides The number of sides each die has.
     * @return The total result of rolling the dice.
     * 
     * @details This method generates random numbers for each die roll and sums them up to return the total result.
     */
    static int rollDice(int numDice, int sides);
};

#endif /* DICE_H_ */

