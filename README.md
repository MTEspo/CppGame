GAME NOTE: All maps are made with Character in top left and Door in bottom right, this cannot be changed/edited. This is default & final
Installation
    - Ensure g++ can be used to run the code
    - Ensure the cppUnit library is accessible

Compiling Test Cases
    g++ -o testCharacterCreator TestCharacterCreator.cpp characterCreator.cpp -lcppunit
    g++ -o testDice TestDice.cpp dice.cpp -lcppunit
    g++ -o testItem TestItem.cpp Item.cpp -lcppunit
    g++ -o testItemContainer TestItemContainer.cpp ItemContainer.cpp Helmet.cpp Shield.cpp Armor.cpp Boots.cpp Ring.cpp Weapon.cpp Item.cpp -lcppunit

Running Test Cases
    ./testCharacterCreator
    ./testDice
    ./testItem
    ./testItemContainer


Compile Main Driver
    g++ -o mainDriver mainDriver.cpp characterCreator.cpp ItemContainer.cpp Item.cpp Helmet.cpp Weapon.cpp Shield.cpp Map.cpp Cell.cpp dice.cpp Belt.cpp MapObserver.cpp CharacterObserver.cpp Observer.h Observable.cpp MapEditor.cpp Campaign.cpp LeveledMapBuilder.cpp MapBuilder.h

Running Main Driver
    ./mainDriver