#ifndef CHARACTEROBSERVER_H
#define CHARACTEROBSERVER_H

#include "Observer.h" // Include necessary header file(s)
#include "characterCreator.h"

/**
 * @brief The CharacterObserver class represents an observer that observes changes in a character.
 * 
 * It inherits from the Observer class and implements the update method to display character information
 * whenever the observed character changes.
 */
class CharacterObserver : public Observer {
public:
    /**
     * @brief Constructor for the CharacterObserver class.
     * 
     * @param character Pointer to the character object to observe.
     */
    CharacterObserver(characterCreator* character);

    /**
     * @brief Update method to be called when the observed character changes.
     * 
     * Overrides the update method of the base class (Observer) to display character information.
     */
    void update() override;

private:
    characterCreator* character; /**< Pointer to the character being observed. */

    /**
     * @brief Helper method to display character information.
     * 
     * This method is called internally to display information about the observed character.
     */
    void displayCharacterInfo();
};

#endif
