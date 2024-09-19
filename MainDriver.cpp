#include <limits>
#include <iostream>
#include <cstdlib>
#include <string>
#include "characterCreator.h"
#include "ItemContainer.h"
#include "Item.h"
#include "Helmet.h"
#include "Weapon.h"
#include "Shield.h"
#include "CharacterObserver.h"
#include "Map.h"
#include "Belt.h"
#include <time.h>
#include "MapObserver.h"
#include "MapEditor.h"
#include "LeveledMapBuilder.h"
#include "MapBuilder.h"
#include "HealthPotion.h"
#include "StrengthPotion.h"
#include "Campaign.h"
#include "MapEditor.h"
#include "CharacterEditor.h"
#include <vector>
#include <array>
#include "Logger.h"
#include <map>



// things to do
// 1. Fix the potions thing (methods were chagned just need to pre make a bunch of potion files)
// 2. Allow users to choose characters to place in map (not done, need to be tested and fixed), auto fill if not (need to test)
// 3. Finish the attacking  (sort of done , not tested must make sure opponents health is affected)
// 4. do the logging (not done) (just need to add it everywhere class is made)
// 5. look over everything see whats missing (not done)
// 6. character should be able to pick up armor off dead opponent (done but not tested)

//ADD LOGS TO EVERYTHING (EX: picking up items and equiping/unequiping items should be loged what the item is )


using namespace std;

// wont need this method
// use this method a couple of times changin name of the file and make some files
// maybe add potions/ to the url to put in potions folder
void selectPotions() {
    std::string filename;
    std::cout << "Enter the name of the file to save the selected potions: ";
    std::cin >> filename;

    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        std::cout << "Select which potions you want to include in the game:" << std::endl;
        std::cout << "1. Health Potion" << std::endl;
        std::cout << "2. Strength Potion" << std::endl;
        std::cout << "3. Wisdom Potion" << std::endl;
        std::cout << "4. Constitution Potion" << std::endl;
        std::cout << "5. Intelligence Potion" << std::endl;
        std::cout << "6. Charisma Potion" << std::endl;
        std::cout << "7. Armor_Class Potion" << std::endl;
        std::cout << "8. Attack_Bonus Potion" << std::endl;
        std::cout << "9. Damage_Bonus Potion" << std::endl;

        int choice;
        std::vector<std::string> selectedPotions;
        do {
            std::cout << "Enter the number corresponding to the potion (0 to finish): ";
            std::cin >> choice;
            if (choice >= 1 && choice <= 9) { // Changed from 10 to 9 since there are only 9 potions
                selectedPotions.push_back(std::to_string(choice));
            }
        } while (choice != 0);

        for (const std::string& potion : selectedPotions) {
            outFile << potion << std::endl;
        }

        std::cout << "Selected potions have been saved to file." << std::endl;
        outFile.close();
    } else {
        std::cout << "Unable to open file." << std::endl;
    }
}

std::vector<ItemType> loadSelectedPotions() {
    std::vector<ItemType> selectedPotions;

    std::string filename;
    std::cout << "Enter the filename to load selected potions from: ";
    std::cin >> filename;

    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        std::string line;
        while (getline(inFile, line)) {
            int potionType = std::stoi(line);
            switch (potionType) {
                case 1:
                    selectedPotions.push_back(ItemType::HEALTH_POTION);
                    break;
                case 2:
                    selectedPotions.push_back(ItemType::STRENGTH_POTION);
                    break;
                case 3:
                    selectedPotions.push_back(ItemType::WISDOM_POTION);
                    break;
                case 4:
                    selectedPotions.push_back(ItemType::CONSTITUTION_POTION);
                    break;
                case 5:
                    selectedPotions.push_back(ItemType::INTELLIGENCE_POTION);
                    break;
                case 6:
                    selectedPotions.push_back(ItemType::CHARISMA_POTION);
                    break;
                case 7:
                    selectedPotions.push_back(ItemType::ARMOR_CLASS_POTION);
                    break;
                case 8:
                    selectedPotions.push_back(ItemType::ATTACK_BONUS_POTION);
                    break;
                case 9:
                    selectedPotions.push_back(ItemType::DAMAGE_BONUS_POTION);
                    break;
                default:
                    std::cout << "Invalid potion type: " << potionType << std::endl;
            }
        }
        inFile.close();
    } else {
        std::cout << "Unable to open file. No potions loaded." << std::endl;
    }

    return selectedPotions;
}

struct CharacterPosition {
    characterCreator* character;
    int x;
    int y;
};

int main() {
    

    Logger logger("log.txt");


    srand(static_cast<unsigned int>(time(nullptr)));

    
    Campaign pre_campaign;
    Map* map1 = new Map(5, 5);
    map1->setCell(1, 1, CellType::CHEST);
    Map* map2 = new Map(5, 5);
    map2->setCell(2, 2, CellType::CHEST);
    pre_campaign.addMap(map1);
    pre_campaign.addMap(map2);

    int choice;
    characterCreator* character;
    Campaign* campaign;
    do {
        std::cout << "\n\n===== Game Menu =====\n";
        std::cout << "1. Create Campaign\n";
        std::cout << "2. Create Character\n";
        std::cout << "3. Start Game\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch(choice) {
            case 1:
                std::cout<<"\n\n===== Creating Campaign =====\n\n";
                Campaign::createUserCampaign();
                break;
            case 2:
                CharacterEditor::createNewCharacter(&logger);
                break;
            case 3:
                character = CharacterEditor::loadCharacter(&logger);
                campaign = Campaign::loadUserCreatedCampaign();
                choice = 5;
                break;
            case 4:
                std::cout << "Exiting program...\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    } while(choice != 5);

    int decision;
    CharacterObserver observer(character);
    character->addObserver(&observer);
    Map* currentMap;
    std::vector<ItemType> potions = loadSelectedPotions();

    currentMap = campaign->getCurrentMap();
    int num_opp = currentMap->countOpponents();
    std::vector<std::array<int, 2>> opponentCoordinates = currentMap->getOpponentCoordinates();
    std::vector<std::pair<std::array<int, 2>, characterCreator>> characters;

    for (int i = 0; i < num_opp; i++) {
            int x_co = opponentCoordinates[i][0];
            int y_co = opponentCoordinates[i][1];
            std::cout << "Opponent " << i + 1 << " coordinates: (" << x_co << ", " << y_co << ")" << std::endl;
            characterCreator* character = CharacterEditor::loadCharacter(&logger);
            characters.push_back(std::make_pair(std::array<int, 2>{x_co, y_co}, *character));
        }
    currentMap->setCharacters(characters);
    currentMap->setSelectedPotions(potions);
    currentMap->printMap();
    currentMap->setLogger(&logger);

    while (currentMap) {
    std::cout << "Enter your choice (1 for move, 2 for attack, 3 for equip item, 0 to exit): ";
    int decision;
    std::cin >> decision;

    if(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a number." << std::endl;
        continue;
    }

    switch (decision) {
        case 1: {
            currentMap->printMap();

            char move;
            std::cout << "Move (W=up, A=left, S=down, D=right): ";
            std::cin >> move;
            int x = 0, y = 0;

            switch (move) {
                case 'W': case 'w':
                    y = -1;
                    break;
                case 'A': case 'a':
                    x = -1;
                    break;
                case 'S': case 's':
                    y = 1;
                    break;
                case 'D': case 'd':
                    x = 1;
                    break;
                default: 
                    std::cout << "Invalid input" << std::endl;
                    continue; 
            }

            std::pair<int, int> characterPosition = currentMap->findCharacter();
            if (currentMap->canCharacterMoveToNextMap(characterPosition.first + x, characterPosition.second + y)) {
                currentMap = campaign->getNextMap();
                int num_opp = currentMap->countOpponents();
                std::vector<std::array<int, 2>> opponentCoordinates = currentMap->getOpponentCoordinates();
                std::vector<std::pair<std::array<int, 2>, characterCreator>> characters;

                for (int i = 0; i < num_opp; i++) {
                        int x_co = opponentCoordinates[i][0];
                        int y_co = opponentCoordinates[i][1];
                        std::cout << "Opponent " << i + 1 << " coordinates: (" << x_co << ", " << y_co << ")" << std::endl;
                        characterCreator* character = CharacterEditor::loadCharacter(&logger);
                        characters.push_back(std::make_pair(std::array<int, 2>{x_co, y_co}, *character));
                    }
                currentMap->setLogger(&logger);
                currentMap->setCharacters(characters);
                currentMap->setSelectedPotions(potions);
            } else {
                if(!currentMap){std::cout<<"\n\n ===== Campaign Completed ====="; exit(0);}
                currentMap->moveCharacter(x, y, *character);
                currentMap->printMap();
            }
            break;
        }
        case 2:
            currentMap->printMap();
            int x, y, choice;
            std::cout << "Enter the x coordinate: ";
            std::cin >> x;
            std::cout << "Enter the y coordinate: ";
            std::cin >> y;
            std::cout << "Choose your weapon:" << std::endl;
            std::cout << "1. Sword" << std::endl;
            std::cout << "2. Bow" << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (choice == 1) {
                character->attackWithSword(x,y,*currentMap);
            } else if (choice == 2) {
                character->attackWithBow(x,y,*currentMap);
            } else {
                std::cout << "Invalid choice. Please choose 1 or 2." << std::endl;
            }

    if (choice == 1) {
        
    } else if (choice == 2) {
        std::cout << "You chose Bow." << std::endl;
    } else {
        std::cout << "Invalid choice. Please choose 1 or 2." << std::endl;
    }
            break;

        case 3: {
            character->notify();
            int itemOption;
            do {
                std::cout << "Choose an option:\n";
                std::cout << "1. Inspect backpack item\n";
                std::cout << "2. Inspect equipment item\n";
                std::cout << "3. Equip item\n";
                std::cout << "4. Unequip item\n";
                std::cout << "5. Exit\n";
                std::cout << "Enter your choice: ";
                std::cin >> itemOption;

                switch (itemOption) {
                    case 1: {
                        character->notify();
                        int backpackIndex;
                        std::cout << "Enter the index of the backpack item you want to inspect: ";
                        std::cin >> backpackIndex;
                        character->inspectBackpackItem(backpackIndex);
                        break;
                    }
                    case 2: {
                        character->notify();
                        int equipmentIndex;
                        std::cout << "Enter the index of the equipment item you want to inspect: ";
                        std::cin >> equipmentIndex;
                        character->inspectEquipment(equipmentIndex);
                        break;
                    }
                    case 3: {
                        character->notify();
                        int backpackIndex;
                        std::cout << "Enter the index of the item in your backpack that you want to equip: ";
                        std::cin >> backpackIndex;
                        character->equipItem(backpackIndex);
                        break;
                    }
                    case 4: {
                        character->notify();
                        int equipmentIndex;
                        std::cout << "Enter the index of the equipment item you want to unequip: ";
                        std::cin >> equipmentIndex;
                        character->unequipItem(equipmentIndex);
                        break;
                    }
                    case 5:
                        std::cout << "Exiting item management menu...\n";
                        break;
                    default:
                        std::cout << "Invalid option. Please enter a number between 1 and 5.\n";
                        break;
                }
            } while (itemOption != 5); 
            break;
        }

        case 0: { // Exit condition
            std::cout << "Exiting the game..." << std::endl;
            currentMap = nullptr; 
            break;
        }
        default:{
            std::cout << "Unknown choice." << std::endl;
            break;
        }
    }
}

    

     return 0;
}





