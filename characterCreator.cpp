#include "characterCreator.h"
#include <cstdlib>
#include <cmath>
#include <iostream>
#include "dice.h"
#include "Map.h"
#include "Helmet.h"
#include "Weapon.h"
#include "Armor.h"
#include "Ring.h"
#include "Boots.h"
#include "Belt.h"
#include "Shield.h"
#include "StrengthPotion.h"
#include "HealthPotion.h"
#include "DexterityPotion.h"
#include "ConstitutionPotion.h"
#include "IntelligencePotion.h"
#include "WisdomPotion.h"
#include "CharismaPotion.h"
#include "ArmorClassPotion.h"
#include "AttackBonusPotion.h"
#include "DamageBonusPotion.h"
#include "Item.h"
#include <cstdlib> // Include for rand() function
#include <ctime>

characterCreator::characterCreator() : isAlive(true), startDie("3d6"), level(1) {
    strength = setScore();

    strMod = setModifier(strength);

    dexterity = setScore();
    dexMod = setModifier(dexterity);
    constitution = setScore();
    consMod = setModifier(constitution);
    intelligence = setScore();
    intelMod = setModifier(intelligence);
    wisdom = setScore();
    wisMod = setModifier(wisdom);
 
    charisma = setScore();
    chaMod = setModifier(charisma);
    hitPoints = setHP();
    maxHP = hitPoints;
    armorClass = setArmorClass(0);
    attackBonus = setAttackBonus(0);
    damageBonus = setDamageBonus(0);
}

characterCreator::characterCreator(Logger* log) : isAlive(true), startDie("3d6"), level(1),logger(log){
    strength = setScore();
    strMod = setModifier(strength);
    dexterity = setScore();
    dexMod = setModifier(dexterity);
    constitution = setScore();
    consMod = setModifier(constitution);
    intelligence = setScore();
    intelMod = setModifier(intelligence);
    wisdom = setScore();
    wisMod = setModifier(wisdom);
    charisma = setScore();
    chaMod = setModifier(charisma);
    hitPoints = setHP();
    maxHP = hitPoints;
    armorClass = setArmorClass(0);
    attackBonus = setAttackBonus(0);
    damageBonus = setDamageBonus(0);
}

ItemContainer& characterCreator::openBackpack() {
    return backpack;
}

ItemContainer& characterCreator::openEquipment() {
    return equipment;
}

void characterCreator::addItem(Item* item) {
    backpack.addItem(item);
}

void characterCreator::equipItem(int index) {
    if (index >= 0 && index < backpack.getItemCount()) {
        Item* itemToEquip = backpack.getItem(index);
        if (itemToEquip) {
            ItemType itemType = itemToEquip->getType();
            if (itemType == ItemType::HEALTH_POTION || 
                itemType == ItemType::STRENGTH_POTION || 
                itemType == ItemType::DEXTERITY_POTION || 
                itemType == ItemType::CONSTITUTION_POTION || 
                itemType == ItemType::INTELLIGENCE_POTION || 
                itemType == ItemType::WISDOM_POTION || 
                itemType == ItemType::CHARISMA_POTION || 
                itemType == ItemType::ARMOR_CLASS_POTION || 
                itemType == ItemType::ATTACK_BONUS_POTION || 
                itemType == ItemType::DAMAGE_BONUS_POTION) {
                    applyPotionBonus(itemToEquip->getEnchantment());
                    backpack.removeItem(index);
            } else {
                for (const auto& item : equipment.getItems()) {
                    if (item && item->getType() == itemType) {
                        std::cout << "An item of this type is already equipped." << std::endl;
                        return;
                    }
                }
                equipment.addItem(backpack.removeItem(index));
            }
        } else {
            std::cout << "Invalid index for backpack." << std::endl;
        }
    } else {
        std::cout << "Invalid index for backpack." << std::endl;
    }
}


void characterCreator::applyPotionBonus(const Enchantment& enchantment) {
    switch (enchantment.type) {
        case EnhancementType::HEALTH:
            if(getHitPoints()+enchantment.bonus>maxHP){setHitPoints(maxHP);}
            else{setHitPoints(getHitPoints() + enchantment.bonus);}
            break;
        case EnhancementType::STRENGTH:
            setStrength(getStrength() + enchantment.bonus);
            break;
        case EnhancementType::DEXTERITY:
            setDexterity(getDexterity() + enchantment.bonus);
            break;
        case EnhancementType::CONSTITUTION:
            setConstitution(getConstitution() + enchantment.bonus);
            break;
        case EnhancementType::INTELLIGENCE:
            setIntelligence(getIntelligence() + enchantment.bonus);
            break;
        case EnhancementType::WISDOM:
            setWisdom(getWisdom() + enchantment.bonus);
            break;
        case EnhancementType::CHARISMA:
            setCharisma(getCharisma() + enchantment.bonus);
            break;
        case EnhancementType::ARMOR_CLASS:
            setArmorClass(getArmorClass() + enchantment.bonus);
            break;
        case EnhancementType::ATTACK_BONUS:
            setAttackBonus(getAttackBonus() + enchantment.bonus);
            break;
        case EnhancementType::DAMAGE_BONUS:
            setDamageBonus(getDamageBonus() + enchantment.bonus);
            break;
        default:
            std::cout << "Unknown enhancement type for potion." << std::endl;
            break;
    }
}


void characterCreator::unequipItem(int index) {
    if (index >= 0 && index < equipment.getItemCount()) {
        backpack.addItem(equipment.removeItem(index));
    } else {
        std::cout << "Invalid index for equipment." << std::endl;
    }
}

void characterCreator::inspectEquipment(int index) {
    if (index >= 0 && index < equipment.getItemCount()) {
        Item* item = equipment.getItem(index);
        if (item) {
            std::cout << "Item Type: " << Item::itemTypeToString(item->getType()) << std::endl;
            Enchantment enchantment = item->getEnchantment();
            std::cout << "Enchantment: " << Item::enchantmentTitle(enchantment.type)
                      << " (Bonus: " << enchantment.bonus << ")" << std::endl;
        } else {
            std::cout << "Invalid index for equipment." << std::endl;
        }
    } else {
        std::cout << "Invalid index for equipment." << std::endl;
    }
}

void characterCreator::inspectBackpackItem(int index) {
    if (index >= 0 && index < backpack.getItemCount()) {
        Item* item = backpack.getItem(index);
        if (item) {
            std::cout << "Item Type: " << Item::itemTypeToString(item->getType()) << std::endl;
            Enchantment enchantment = item->getEnchantment();
            std::cout << "Enchantment: " << Item::enchantmentTitle(enchantment.type)
                      << " (Bonus: " << enchantment.bonus << ")" << std::endl;
        } else {
            std::cout << "Invalid index for backpack." << std::endl;
        }
    } else {
        std::cout << "Invalid index for backpack." << std::endl;
    }
}

int characterCreator::setScore() {
    int roll = dice::roll(startDie);
    logger->write("You rolled a "+ roll);
    return roll;
}

int characterCreator::setModifier(int abilityScore) {
    return static_cast<int>((abilityScore / 2) - 5);
}

int characterCreator::setHP() {
    hitPoints = level * (10 + consMod);
    return hitPoints;
}

int characterCreator::setArmorClass(int armorBuff) {
    armorClass = armorBuff + 10 + dexMod;
    return armorClass;
}

int characterCreator::setAttackBonus(int attackBuff) {
    attackBonus = std::abs((level * (dexMod + strMod)) + attackBuff);
    return attackBonus;
}

int characterCreator::setDamageBonus(int damageBuff) {
    damageBonus = strMod + damageBuff;
    return damageBonus;
}

int characterCreator::getArmorClass() const {
    int totalArmorClass = armorClass;
    for (const auto& item : equipment.getItems()) {
        if (item) {
            Enchantment enchantment = item->getEnchantment();
            if (enchantment.type == EnhancementType::ARMOR_CLASS) {
                totalArmorClass += enchantment.bonus;
            }
        }
    }
    return totalArmorClass;
}

int characterCreator::getAttackBonus() const {
    int totalAttackBonus = attackBonus;
    for (const auto& item : equipment.getItems()) {
        if (item) {
            Enchantment enchantment = item->getEnchantment();
            if (enchantment.type == EnhancementType::ATTACK_BONUS) {
                totalAttackBonus += enchantment.bonus;
            }
        }
    }
    return totalAttackBonus;
}

int characterCreator::getChaMod() const {
    return chaMod;
}

void characterCreator::setChaMod(int chaMod) {
    this->chaMod = chaMod;
}

int characterCreator::getCharisma() const {
    int totalCharisma = charisma;
    for (const auto& item : equipment.getItems()) {
        if (item) {
            Enchantment enchantment = item->getEnchantment();
            if (enchantment.type == EnhancementType::CHARISMA) {
                totalCharisma += enchantment.bonus;
            }
        }
    }
    return totalCharisma;
}

void characterCreator::setCharisma(int charisma) {
    this->charisma = charisma;
}

int characterCreator::getConsMod() const {
    return consMod;
}

void characterCreator::setConsMod(int consMod) {
    this->consMod = consMod;
}

int characterCreator::getConstitution() const {
    int totalConstitution = constitution;
    for (const auto& item : equipment.getItems()) {
        if (item) {
            Enchantment enchantment = item->getEnchantment();
            if (enchantment.type == EnhancementType::CONSTITUTION) {
                totalConstitution += enchantment.bonus;
            }
        }
    }
    return totalConstitution;
}

void characterCreator::setConstitution(int constitution) {
    this->constitution = constitution;
}

int characterCreator::getDamageBonus() const {
    int totalDamageBonus = damageBonus;
    for (const auto& item : equipment.getItems()) {
        if (item) {
            Enchantment enchantment = item->getEnchantment();
            if (enchantment.type == EnhancementType::DAMAGE_BONUS) {
                totalDamageBonus += enchantment.bonus;
            }
        }
    }
    return totalDamageBonus;
}

int characterCreator::getDexMod() const {
    return dexMod;
}

void characterCreator::setDexMod(int dexMod) {
    this->dexMod = dexMod;
}

int characterCreator::getDexterity() const {
    int totalDexterity = dexterity;
    for (const auto& item : equipment.getItems()) {
        if (item) {
            Enchantment enchantment = item->getEnchantment();
            if (enchantment.type == EnhancementType::DEXTERITY) {
                totalDexterity += enchantment.bonus;
            }
        }
    }
    return totalDexterity;
}

void characterCreator::setDexterity(int dexterity) {
    this->dexterity = dexterity;
}

int characterCreator::getHitPoints() const {
    return hitPoints;
}

void characterCreator::setHitPoints(int hitPoints) {
    this->hitPoints = hitPoints;
}

int characterCreator::getIntelligence() const {
    int totalIntelligence = intelligence;
    for (const auto& item : equipment.getItems()) {
        if (item) {
            Enchantment enchantment = item->getEnchantment();
            if (enchantment.type == EnhancementType::INTELLIGENCE) {
                totalIntelligence += enchantment.bonus;
            }
        }
    }
    return totalIntelligence;
}


void characterCreator::setIntelligence(int intelligence) {
    this->intelligence = intelligence;
}

int characterCreator::getIntelMod() const {
    return intelMod;
}

void characterCreator::setIntelMod(int intelMod) {
    this->intelMod = intelMod;
}

bool characterCreator::getIsAlive() const {
    return isAlive;
}

void characterCreator::setIsAlive(bool isAlive) {
    this->isAlive = isAlive;
}

int characterCreator::getLevel() const {
    return level;
}

void characterCreator::setLevel(int level) {
    this->level = level;
}

int characterCreator::getStrength() const {
    int totalStrength = strength;
    for (const auto& item : equipment.getItems()) {
        if (item) {
            Enchantment enchantment = item->getEnchantment();
            if (enchantment.type == EnhancementType::STRENGTH) {
                totalStrength += enchantment.bonus;
            }
        }
    }
    return totalStrength;
}

void characterCreator::setStrength(int strength) {
    this->strength = strength;
}

int characterCreator::getStrMod() const {
    return strMod;
}

void characterCreator::setStrMod(int strMod) {
    this->strMod = strMod;
}

int characterCreator::getWisdom() const {
    int totalWisdom = wisdom;
    for (const auto& item : equipment.getItems()) {
        if (item) {
            Enchantment enchantment = item->getEnchantment();
            if (enchantment.type == EnhancementType::WISDOM) {
                totalWisdom += enchantment.bonus;
            }
        }
    }
    return totalWisdom;
}

void characterCreator::setLogger(Logger* logger) {
        this->logger = logger;
    }


void characterCreator::setWisdom(int wisdom) {
    this->wisdom = wisdom;
}

int characterCreator::getWisMod() const {
    return wisMod;
}

void characterCreator::setWisMod(int wisMod) {
    this->wisMod = wisMod;
}

// call the map method to check if in range
// then call the getCharacterAt and pass the coordinates will either return a set character or a random if never set
void characterCreator::attackWithSword(int x, int y,Map &map){
    int range = 1;
    if(map.isOpponentInRange(range)){
        characterCreator* opp = map.getCharacterAtCoordinates(x,y);
        int attackDamage = (dice::roll("1d20")) + this->getAttackBonus();
        logger->write("You rolled a "+ attackDamage);
        opp->setHitPoints((opp->getHitPoints()) - attackDamage);
        logger->write("You hit the opponent for " + std::to_string(attackDamage) + " damage!");
        if((opp->getHitPoints())<=0){
            logger->write("You have defeated opponent at coordinates x: "+std::to_string(x)+", y: "+std::to_string(y));
            logger->write("You have leveled up to level "+std::to_string(this->level));
            this->setLevel(this->getLevel()+1);
            this->maxHP = this->maxHP + 1;
            map.setCell(x,y,CellType::EMPTY);
            map.deleteCharacterAtCoordinates(x,y);
            this->backpack.addItem(this->generateRandomItemType());

            return;
        }
        opp->enemyAttack(this);
        std::cout << "\n\nCURRENT HEALTH == " << std::to_string(this->getHitPoints())<<std::endl;
        return;
    }

    std::cout<<"\nOPPONENT NOT IN RANGE\n";

}

void characterCreator::attackWithBow(int x, int y,Map &map){
    int range = 2;
    if(map.isOpponentInRange(range)){
        characterCreator* opp = map.getCharacterAtCoordinates(x,y);
        int attackDamage = ((dice::roll("1d20"))/2) + getAttackBonus();
        logger->write("You rolled a "+ attackDamage);
        opp->setHitPoints((opp->getHitPoints()) - attackDamage);
        logger->write("You hit the opponent for " + std::to_string(attackDamage) + " damage!");
        if((opp->getHitPoints())<=0){
            logger->write("You have defeated opponent at coordinates x: "+std::to_string(x)+", y: "+std::to_string(y));
            logger->write("You have leveled up to level "+std::to_string(this->level));
            this->setLevel(this->getLevel()+1);
            this->maxHP = this->maxHP + 1;
            map.setCell(x,y,CellType::EMPTY);
            map.deleteCharacterAtCoordinates(x,y);
            this->backpack.addItem(this->generateRandomItemType()); // add logging for this
            return;
        }
        opp->enemyAttack(this);
        std::cout << "\n\nCURRENT HEALTH == " << std::to_string(this->getHitPoints())<<std::endl;
        return;
    }
    std::cout<<"\nOPPONENT NOT IN RANGE\n";
}

void characterCreator::enemyAttack(characterCreator* mainCharacter){
    int attackDamage = dice::roll("1d10");
    logger->write("The opponent rolled a "+ std::to_string(attackDamage));
    std::cout<<"\nOPPONENT HITS INFLICTS "+std::to_string(attackDamage)+" DAMAGE!"<<std::endl;
    mainCharacter->setHitPoints((mainCharacter->getHitPoints()) - attackDamage);
    logger->write("You have taken "+std::to_string(attackDamage)+" damage!");
    if((mainCharacter->getHitPoints())<=0){
        mainCharacter->setIsAlive(false);
        logger->write("Game Over!");
        std::cout<< "Your opponent killed you. Game over!" <<std::endl;
        exit(0);
    }
}

Item* characterCreator::generateRandomItemType() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    ItemType items[7]; 
    items[0] = ItemType::HELMET;
    items[1] = ItemType::WEAPON;
    items[2] = ItemType::ARMOR;
    items[3] = ItemType::BOOTS;
    items[4] = ItemType::RING;
    items[5] = ItemType::SHIELD;
    items[6] = ItemType::BELT;

    int randomIndex = std::rand() % 7; 
    ItemType selectedItemType = items[randomIndex];
    Item* item = nullptr;
            switch (selectedItemType) {
                case ItemType::HELMET:
                    item = new Helmet(); 
                    break;
                case ItemType::ARMOR:
                    item = new Armor(); 
                    break;
                case ItemType::BOOTS:
                    item = new Boots(); 
                    break;
                case ItemType::SHIELD:
                    item = new Shield(); 
                    break;
                case ItemType::BELT:
                    item = new Belt(); 
                    break;
                case ItemType::RING:
                    item = new Ring(); 
                    break;
                case ItemType::WEAPON:
                    item = new Weapon(); 
                    break;
                case ItemType::HEALTH_POTION:
                    item = new HealthPotion(); 
                    break;
                case ItemType::STRENGTH_POTION:
                    item = new StrengthPotion(); 
                    break;
                case ItemType::DEXTERITY_POTION:
                    item = new DexterityPotion(); 
                    break;
                case ItemType::CONSTITUTION_POTION:
                    item = new ConstitutionPotion(); 
                    break;
                case ItemType::INTELLIGENCE_POTION:
                    item = new IntelligencePotion(); 
                    break;
                case ItemType::WISDOM_POTION:
                    item = new WisdomPotion(); 
                    break;
                case ItemType::CHARISMA_POTION:
                    item = new CharismaPotion(); 
                    break;
                case ItemType::ARMOR_CLASS_POTION:
                    item = new ArmorClassPotion(); 
                    break;
                case ItemType::ATTACK_BONUS_POTION:
                    item = new AttackBonusPotion(); 
                    break;
                case ItemType::DAMAGE_BONUS_POTION:
                    item = new DamageBonusPotion(); 
                    break;

                default:
                    std::cout << "Unknown item type." << std::endl;
                    break;
            }
    std::cout<<"\n\n**ITEM FOUND**\n"<<std::endl;
    Enchantment enchantment = item->getEnchantment();
    logger->write("Item found, "+Item::itemTypeToString(item->getType())+" with "+Item::enchantmentTitle(enchantment.type)+" with bonus: "+std::to_string(enchantment.bonus));
    return item;
}

