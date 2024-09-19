#ifndef OBSERVER_H
#define OBSERVER_H

class Observable; // Forward declaration of Observable class

/**
 * @brief The Observer class represents an object that observes changes in an Observable object.
 * 
 * This class provides an interface for implementing observers that need to respond to changes 
 * in an Observable object.
 */
class Observer {
public:
    /**
     * @brief Virtual destructor for the Observer class.
     */
    virtual ~Observer() {}

    /**
     * @brief Update method called when the observed object changes.
     * 
     * This method is called by the Observable object when it undergoes a change.
     */
    virtual void update() = 0;
};

#endif
