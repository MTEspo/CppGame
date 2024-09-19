#include <fstream>
#include <iostream>
#include <sstream>
#include "CharacterEditor.h"

void CharacterEditor::createNewCharacter(Logger* log) {
    characterCreator* newCharacter = new characterCreator(log);
    
    const int maxPointsPerStat = 30;
    int totalPoints = 80;
    int remainingPoints = totalPoints;
    
    int strengthPoints = 0, dexterityPoints = 0, constitutionPoints = 0;
    int intelligencePoints = 0, wisdomPoints = 0, charismaPoints = 0;
   
    
    std::cout << "Remaining points: " << remainingPoints << std::endl;
    
    // Loop for each stat input
    while (true) {
        std::cout << "Strength (max " << std::min(maxPointsPerStat, remainingPoints) << " points available): ";
        std::cin >> strengthPoints;
        if (strengthPoints < 0 || strengthPoints > std::min(maxPointsPerStat, remainingPoints)) {
            std::cout << "Invalid input. Please enter a number between 0 and " << std::min(maxPointsPerStat, remainingPoints) << std::endl;
        } else {
            newCharacter->setStrength(strengthPoints);
            remainingPoints -= strengthPoints;
            break; // Exit the loop if a valid input is provided
        }
    }
    
    std::cout << "Remaining points: " << remainingPoints << std::endl;
    
    // Repeat the same process for each stat
    while (true) {
        std::cout << "Dexterity (max " << std::min(maxPointsPerStat, remainingPoints) << " points available): ";
        std::cin >> dexterityPoints;
        if (dexterityPoints < 0 || dexterityPoints > std::min(maxPointsPerStat, remainingPoints)) {
            std::cout << "Invalid input. Please enter a number between 0 and " << std::min(maxPointsPerStat, remainingPoints) << std::endl;
        } else {
            newCharacter->setDexterity(dexterityPoints);
            remainingPoints -= dexterityPoints;
            break;
        }
    }

    std::cout << "Remaining points: " << remainingPoints << std::endl;
    
    // Repeat the process for Constitution
    while (true) {
        std::cout << "Constitution (max " << std::min(maxPointsPerStat, remainingPoints) << " points available): ";
        std::cin >> constitutionPoints;
        if (constitutionPoints < 0 || constitutionPoints > std::min(maxPointsPerStat, remainingPoints)) {
            std::cout << "Invalid input. Please enter a number between 0 and " << std::min(maxPointsPerStat, remainingPoints) << std::endl;
        } else {
            newCharacter->setConstitution(constitutionPoints);
            remainingPoints -= constitutionPoints;
            break;
        }
    }
    
    std::cout << "Remaining points: " << remainingPoints << std::endl;
    
    // Repeat the process for Intelligence
    while (true) {
        std::cout << "Intelligence (max " << std::min(maxPointsPerStat, remainingPoints) << " points available): ";
        std::cin >> intelligencePoints;
        if (intelligencePoints < 0 || intelligencePoints > std::min(maxPointsPerStat, remainingPoints)) {
            std::cout << "Invalid input. Please enter a number between 0 and " << std::min(maxPointsPerStat, remainingPoints) << std::endl;
        } else {
            newCharacter->setIntelligence(intelligencePoints);
            remainingPoints -= intelligencePoints;
            break;
        }
    }
    
std::cout << "Remaining points: " << remainingPoints << std::endl;
    
    // Repeat the process for Wisdom
    while (true) {
        std::cout << "Wisdom (max " << std::min(maxPointsPerStat, remainingPoints) << " points available): ";
        std::cin >> wisdomPoints;
        if (wisdomPoints < 0 || wisdomPoints > std::min(maxPointsPerStat, remainingPoints)) {
            std::cout << "Invalid input. Please enter a number between 0 and " << std::min(maxPointsPerStat, remainingPoints) << std::endl;
        } else {
            newCharacter->setWisdom(wisdomPoints);
            remainingPoints -= wisdomPoints;
            break;
        }
    }
    
    std::cout << "Remaining points: " << remainingPoints << std::endl;
    
    // Repeat the process for Charisma
    while (true) {
        std::cout << "Charisma (max " << std::min(maxPointsPerStat, remainingPoints) << " points available): ";
        std::cin >> charismaPoints;
        if (charismaPoints < 0 || charismaPoints > std::min(maxPointsPerStat, remainingPoints)) {
            std::cout << "Invalid input. Please enter a number between 0 and " << std::min(maxPointsPerStat, remainingPoints) << std::endl;
        } else {
            newCharacter->setCharisma(charismaPoints);
            remainingPoints -= charismaPoints;
            break;
        }
    }
    
    std::cout << "Remaining points: " << remainingPoints << std::endl;
    
    
    
    writeCharacterToFile(newCharacter);
    
}



bool CharacterEditor::writeCharacterToFile(characterCreator* character) {
    std::string characterName;
    std::cout << "Enter character name: ";
    std::cin >> characterName;

    std::string filename = "characters/character_" + characterName;
    std::ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << " for writing." << std::endl;
        return false;
    }


    outputFile << character->getStrength() << std::endl;
    outputFile << character->getDexterity() << std::endl;
    outputFile << character->getConstitution() << std::endl;
    outputFile << character->getIntelligence() << std::endl;
    outputFile << character->getWisdom() << std::endl;
    outputFile << character->getCharisma() << std::endl;


    outputFile.close();
    std::cout << "Character saved to file: " << filename << std::endl;
    delete character;
    return true;
}

characterCreator* CharacterEditor::loadCharacter(Logger* log) {
    std::string characterName;
    std::cout << "Enter the name of the character you want to load: ";
    std::cin >> characterName;

    std::string filename = "characters/character_" + characterName;
    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << " for reading." << std::endl;
        return nullptr;
    }

    int strength = 0, dexterity = 0, constitution = 0;
    int intelligence = 0, wisdom = 0, charisma = 0;


    // Read each attribute from the file
    if (!(inputFile >> strength >> dexterity >> constitution >> intelligence >> wisdom
                >> charisma)) {
        std::cerr << "Error: Unable to read character stats from file." << std::endl;
        return nullptr;
    }

    inputFile.close();

    characterCreator* loadedCharacter = new characterCreator(log);
    loadedCharacter->setStrength(strength);
    loadedCharacter->setDexterity(dexterity);
    loadedCharacter->setConstitution(constitution);
    loadedCharacter->setIntelligence(intelligence);
    loadedCharacter->setWisdom(wisdom);
    loadedCharacter->setCharisma(charisma);


    std::cout << "Character loaded successfully." << std::endl;
    return loadedCharacter;
}





