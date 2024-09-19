#include "CharacterObserver.h"
#include <iostream>


CharacterObserver::CharacterObserver(characterCreator* character) {
    this->character = character;
}
void CharacterObserver::update() {
    displayCharacterInfo();
}

void CharacterObserver::displayCharacterInfo() {
    std::cout << "Character Information:" << std::endl;
    std::cout << "======================" << std::endl;
    std::cout << "Strength: " << character->getStrength() << std::endl;
    std::cout << "Dexterity: " << character->getDexterity() << std::endl;
    std::cout << "Constitution: " << character->getConstitution() << std::endl;
    std::cout << "Intelligence: " << character->getIntelligence() << std::endl;
    std::cout << "Wisdom: " << character->getWisdom() << std::endl;
    std::cout << "Charisma: " << character->getCharisma() << std::endl;
    std::cout << "Hit Points: " << character->getHitPoints() << std::endl;
    std::cout << "Armor Class: " << character->getArmorClass() << std::endl;
    std::cout << "Attack Bonus: " << character->getAttackBonus() << std::endl;
    std::cout << "Damage Bonus: " << character->getDamageBonus() << std::endl;
    std::cout << std::endl;

    ItemContainer& equipment = character->openEquipment();
    if (!equipment.isEmpty()) {
        std::cout << "Equipment:" << std::endl;
        std::cout << "----------" << std::endl;
        int index = 0;
        for (const auto& item : equipment.getItems()) {
            std::cout << index << ". " << Item::itemTypeToString(item->getType()) << std::endl;
            index++;
        }
    } else {
        std::cout << "The equipment is empty." << std::endl;
    }

    std::cout << std::endl;

    ItemContainer& backpack = character->openBackpack();
    if (!backpack.isEmpty()) {
        std::cout << "Backpack Contents:" << std::endl;
        std::cout << "------------------" << std::endl;
        int index = 0;
        for (const auto& item : backpack.getItems()) {
            std::cout << index << ". " << Item::itemTypeToString(item->getType()) << std::endl;
            index++;
        }
    } else {
        std::cout << "The backpack is empty." << std::endl;
    }
}

