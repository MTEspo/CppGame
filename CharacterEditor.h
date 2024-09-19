#ifndef CHARACTEREDITOR_H
#define CHARACTEREDITOR_H

#include "characterCreator.h"

/**
 * @brief The CharacterEditor class provides functionality for creating, editing, and saving characters.
 */
class CharacterEditor {
public:
    /**
     * @brief Creates a new character.
     * 
     * @return A pointer to the newly created character.
     */
    static void createNewCharacter(Logger* log);

    /**
     * @brief Loads a character from a file.
     * 
     * @return A pointer to the loaded character, or nullptr if the character cannot be loaded.
     */
    static characterCreator* loadCharacter(Logger* log);

private:
    /**
     * @brief Writes a character to a file.
     * 
     * @param character A pointer to the character to be saved.
     * @return true if the character is successfully saved, false otherwise.
     */
    static bool writeCharacterToFile(characterCreator* character);
};


#endif