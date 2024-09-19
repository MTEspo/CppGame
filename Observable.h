#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <forward_list>
#include "Observer.h"

class Observer; // Forward declaration of Observer class

/**
 * @brief The Observable class represents an object that can be observed by observers.
 * 
 * This class provides functionality to manage a list of observers and notify them of changes.
 */
class Observable {
private:
    std::forward_list<Observer*> observers; // List of observers

public:
    /**
     * @brief Virtual destructor for the Observable class.
     */
    virtual ~Observable() {}

    /**
     * @brief Adds an observer to the list of observers.
     * 
     * @param observer Pointer to the observer to add.
     */
    virtual void addObserver(Observer* observer);

    /**
     * @brief Removes an observer from the list of observers.
     * 
     * @param observer Pointer to the observer to remove.
     */
    virtual void removeObserver(Observer* observer);

    /**
     * @brief Notifies all observers of a change.
     */
    virtual void notify();
};

#endif
