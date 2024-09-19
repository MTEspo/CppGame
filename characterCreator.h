/**
 * @file characterCreator.h
 * @brief Character Creator for a Role-Playing Game (RPG)
 * 
 * This file defines the `characterCreator` class, which is responsible for creating and managing RPG characters.
 * The class utilizes game rules for character creation and management, drawing from sources such as d20 Modern and Pathfinder SRD.
 * It is designed to be flexible for use in various RPG systems, with a focus on modularity and ease of extension.
 * 
 * @version 1.0
 * @date 2024-02-12
 * @author Mario Thomas Esposito
 */

#ifndef CHARACTERCREATOR_H
#define CHARACTERCREATOR_H

#include <string> // Used for string operations, such as handling equipment names.
#include "ItemContainer.h" // Custom class for managing a character's items.
#include "Observable.h"
#include "Logger.h"
#include "Map.h"


/**
 * @class characterCreator
 * @brief Manages character creation and stats in an RPG setting.
 * 
 * The `characterCreator` class encapsulates all functionality necessary for creating and managing a character in an RPG.
 * It includes methods for setting and retrieving character attributes, managing health points, armor class, attack and damage bonuses,
 * and handling character equipment through an `ItemContainer`.
 * 
 * ## Game Rules:
 * The implementation is based on game mechanics from d20 Modern and Pathfinder, including ability score modifiers and combat statistics calculations.
 * 
 * ## Design:
 * The class is designed with private member variables to store character statistics and an `ItemContainer` object to manage the character's inventory.
 * Public methods allow for character manipulation and retrieval of stats, supporting extensible character customization.
 * 
 * ## Libraries:
 * - `<string>`: Utilized for managing text-based data, such as character names and equipment.
 * - "ItemContainer.h": A custom class designed to handle a character's inventory, illustrating the use of object-oriented principles for extensibility.
 * 
 * ## Rationale:
 * The standard library `<string>` is chosen for its robust support for string manipulation, critical for handling character-related text data.
 * The custom `ItemContainer` class demonstrates encapsulation and the use of classes to modularize functionality, making the character creation process more manageable and adaptable to different RPG systems.
 */

class Map;
class characterCreator : public Observable{
private:
    bool isAlive;
    std::string startDie;
    int level;
    int maxHP;
    int hitPoints;
    int strength;
    int strMod;
    int dexterity;
    int dexMod;
    int constitution;
    int consMod;
    int intelligence;
    int intelMod;
    int wisdom;
    int wisMod;
    int charisma;
    int chaMod;
    int armorClass;
    int attackBonus;
    int damageBonus;
    ItemContainer backpack;
    ItemContainer equipment;
    void applyPotionBonus(const Enchantment& enchantment);
    Logger* logger;

public:
    characterCreator();
    characterCreator(Logger* log);
    ItemContainer& openBackpack();
    ItemContainer& openEquipment();
    void addItem(Item* item);
    void equipItem(int index); 
    void unequipItem(int index);
    void inspectEquipment(int index);
    void inspectBackpackItem(int index);
    int setScore();
    int setModifier(int abilityScore);
    int setHP();
    int setArmorClass(int armorBuff);
    int setAttackBonus(int attackBuff);
    int setDamageBonus(int damageBuff);
    int getArmorClass() const;
    int getAttackBonus() const;
    int getChaMod() const;
    void setChaMod(int chaMod);
    int getCharisma() const;
    void setCharisma(int charisma);
    int getConsMod() const;
    void setConsMod(int consMod);
    int getConstitution() const;
    void setConstitution(int constitution);
    int getDamageBonus() const;
    int getDexMod() const;
    void setDexMod(int dexMod);
    int getDexterity() const;
    void setDexterity(int dexterity);
    int getHitPoints() const;
    void setHitPoints(int hitPoints);
    int getIntelligence() const;
    void setIntelligence(int intelligence);
    int getIntelMod() const;
    void setIntelMod(int intelMod);
    bool getIsAlive() const;
    void setIsAlive(bool isAlive);
    int getLevel() const;
    void setLevel(int level);
    int getStrength() const;
    void setStrength(int strength);
    int getStrMod() const;
    void setStrMod(int strMod);
    int getWisdom() const;
    void setWisdom(int wisdom);
    int getWisMod() const;
    void setWisMod(int wisMod);
    void attackWithSword(int x , int y,Map &map);
    void attackWithBow(int x, int y,Map &map);
    void enemyAttack(characterCreator* mainCharacter);
    void setLogger(Logger* logger);
    Item* generateRandomItemType();
};

#endif