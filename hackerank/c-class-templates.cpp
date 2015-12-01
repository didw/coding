#include <iostream>

using namespace std;


template <class T>
class AddElements {
    T element;
public:
    AddElements(T arg) { element = arg; }
    T add(T arg) {
        return element + arg;
    }
    T concatenate(T arg) {
        return this->add(arg);
    }
};