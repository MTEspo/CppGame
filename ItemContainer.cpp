#include "ItemContainer.h"
#include <iostream>
using namespace std;
// Add an item to the container
void ItemContainer::addItem(Item* item) {
    items.push_back(item);
    count++;
}

// Return pointer to item at the specified index
// Returns nullptr if the index is out of bounds
Item* ItemContainer::getItem(int index) const {
    if (index >= 0 && index < items.size()) {
        return items[index];
    } else {
        return nullptr;
    }
}

// Return the count of items in the container
int ItemContainer::getItemCount() {
    return count;
}

bool ItemContainer::isEmpty() const {
    return items.empty();
}

// Return reference to vector of items
const vector<Item*>& ItemContainer::getItems() const {
    return items;
}

void ItemContainer::showItemList() {
    for (int i = 0; i < getItemCount(); ++i) {
        Item* item = getItem(i);
        if (item) {
            Enchantment enchantment = item->getEnchantment();
            cout << "Item " << i << ": Item type: " << Item::itemTypeToString(item->getType())
                 << ", Enchantment type: " << Item::enchantmentTitle(enchantment.type)
                 << ", Bonus: " << enchantment.bonus << endl;
        }
    }
}

int ItemContainer::size() const {
    return items.size();
}

Item* ItemContainer::removeItem(int index) {
    Item* removedItem = nullptr;
    if (index >= 0 && index < items.size()) {
        removedItem = items[index];
        items.erase(items.begin() + index);
        count--;
    }
    return removedItem;
}
