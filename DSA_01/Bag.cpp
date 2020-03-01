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
}


void Bag::add(TElem elem) {
    // TODO
    // 4 big cases
    // 1. size is 0, then you can set minValue = maxValue = elem and put 1 there
    // 2. elem is in [minValue, maxValue] => increment the value of the corresponding (PAY ATTENTION) index
    // 3. elem is larger than maxValue => need enlargement of bag[] (how many extra elements?) and copy the existing elems
    // 4. elem is smaller than minValue => need enlargement of bag[] and copying the elems (with an offset, which is the offset?)
}

bool Bag::remove(TElem elem) {
    // TODO
    // you should check if the element is in your stored interval
    // if it is, then check if appears for 1 or more times
    // if it does, then just decrement the number of occurences of that number
    // NOTE: please pay attention to the index you need to refer to
}


bool Bag::search(TElem elem) const {
    // TODO
    // you should check if the element is in your stored interval
    // if it is, then check if appears for 1 or more times
    // if it's not, then it's clear it won't ever be found
}

int Bag::nrOccurrences(TElem elem) const {
    // TODO
    // you should check if the element is in your stored interval
    // if it is, then its number of occurences is stored in bag[]
    //     note: bag[elem] is incorrect, try to find the real index which you can refer to
    // if it's not, then for sure it appears 0 times in the bag (doesn't appear at all)
}


int Bag::size() const {
    // TODO
    // "ce-i in mana nu-i minciuna"
    // so, if you keep the size separately, doesn't make it faster
    // than counting stuff?
}


bool Bag::isEmpty() const {
    // TODO
    // try to refer to the size of the bag
    // when is the bag empty?
    return false;
}

BagIterator Bag::iterator() const {
    // OK!
    return BagIterator(*this);
}


Bag::~Bag() {
    // OK!
    delete bag;
}

