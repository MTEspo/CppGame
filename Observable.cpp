#include "Observable.h"
#include "Observer.h"

void Observable::addObserver(Observer* observer) {
    observers.push_front(observer);
}

void Observable::removeObserver(Observer* observer) {
    observers.remove(observer);
}

void Observable::notify() {
    for (auto& observer : observers) {
        observer->update();
    }
}
