#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;

Bag::Bag() {
    //TODO - Implementation
    bag = new int[1];
    bagSize = 0;
    bagCapacity = 1;
    bag[0] = 0;
    minValue = 0;
    maxValue = 0;
    /// abs(elem - minValue) MAGIC FORMULA !!!
}

void Bag::Print() {
    for (int i = 0; i < bagCapacity; i++)
        cout << bag[i] << " ";
}
/// case 1 : O(1)
/// case 2 : O(newBagCapacity), where newBagCapacity is the size of the new array
/// case 3 : O(newBagCapacity)
void Bag::add(TElem elem) {
    // TODO
    // 3 CASES
    // 1. elem is in [minValue, maxValue] => increment the value of the corresponding (PAY ATTENTION) index
    // 2. elem is larger than maxValue => need enlargement of bag[] (how many extra elements?) and copy the existing elems
    // 3. elem is smaller than minValue => need enlargement of bag[] and copying the elems (with an offset, which is the offset?)
    if (elem >= minValue && elem <= maxValue)
    {
        bag[abs(elem - minValue)]++;
        bagSize++;
    }
    if (elem > maxValue)
    {
        int newBagCapacity = bagCapacity + elem - maxValue;
        int* newBag = new int[newBagCapacity];
        
        for (int i = 0; i < newBagCapacity; i++)
            newBag[i] = 0;

        for (int i = 0; i < bagCapacity; i++)
            newBag[i] = bag[i];

        bagCapacity = newBagCapacity;
        newBag[newBagCapacity - 1] = 1;
        bagSize++;
        maxValue = elem;
        delete bag;
        this->bag = newBag;
    }
    if (elem < minValue)
    {
        int shiftValue = abs(elem - minValue);
        int newBagCapacity = bagCapacity + shiftValue;
        int* newBag = new int[newBagCapacity];
        
        for (int i = 0; i < newBagCapacity; i++)
            newBag[i] = 0;

        for (int i = 0; i < bagCapacity; i++)
            newBag[i + shiftValue] = bag[i];

        newBag[0] = 1;
        minValue = elem;
        bagCapacity = newBagCapacity;
        bagSize++;
        delete bag;
        this->bag = newBag;
    }

}
/// O(1)
bool Bag::remove(TElem elem) {
    // TODO
    // you should check if the element is in your stored interval
    // if it is, then check if appears for 1 or more times
    // if it does, then just decrement the number of occurences of that number
    // NOTE: please pay attention to the index you need to refer to
    if (elem < minValue || elem > maxValue)
        return false;
    if (bag[abs(elem - minValue)] == 0)
        return false;
    else
    {
        bag[abs(elem - minValue)]--;
        bagSize--;
        return true;
    } 
}

/// O(1)
bool Bag::search(TElem elem) const {
    // TODO
    // you should check if the element is in your stored interval
    // if it is, then check if appears for 1 or more times
    // if it's not, then it's clear it won't ever be found  
    if (elem < minValue)
        return false;
    if (elem > maxValue)
        return false;
    else
    {
        if (bag[abs(elem - minValue)] >= 1)
            return true;
    }
    return false;


}
/// O(1)
int Bag::nrOccurrences(TElem elem) const {
    // TODO
    // you should check if the element is in your stored interval
    // if it is, then its number of occurences is stored in bag[]
    //     note: bag[elem] is incorrect, try to find the real index which you can refer to
    // if it's not, then for sure it appears 0 times in the bag (doesn't appear at all)
    if (elem < minValue || elem > maxValue)
        return false;
    return bag[abs(elem - minValue)];
}

/// O(1)
int Bag::size() const {
    // TODO
    // "ce-i in mana nu-i minciuna"
    return bagSize;
}

/// O(1)
bool Bag::isEmpty() const {
    // TODO
    // try to refer to the size of the bag
    // when is the bag empty?
    return bagSize == 0;
}

BagIterator Bag::iterator() const {
    // OK!
    return BagIterator(*this);
}


Bag::~Bag() {
    // OK!
    delete bag;
}

