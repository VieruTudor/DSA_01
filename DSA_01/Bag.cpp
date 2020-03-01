#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;

const int MAX_SIZE = 100005;
Bag::Bag() {
	//TODO - Implementation
	bag = new int[1];
	bagSize = 1;
	bag[0] = 0;
	minValue = 0;
	maxValue = 0;
}


void Bag::add(TElem elem) {
	//TODO - Implementation
	if (elem > maxValue) {
		int newBagSize = bagSize + elem - maxValue;
		int* newBag = new int[newBagSize];

		for (int i = 0; i < bagSize; i++)
			newBag[i] = this->bag[i];

		newBag[newBagSize - 1] = 1;

		delete bag;
		this->bag = newBag;
		bagSize = newBagSize;
	}
	else if (elem < minValue) {
		int shift = abs(minValue - elem);
		int newBagSize = bagSize + shift;
		int* newBag = new int[newBagSize];

		for (int i = 0; i < bagSize; i++)
			newBag[shift + i] = bag[i];

		newBag[0] = 1;

		delete bag;
		this->bag = newBag;
		bagSize = newBagSize;
	}
	else
		bag[elem]++;



}

bool Bag::remove(TElem elem) {
	//TODO - Implementation

	return false;
}


bool Bag::search(TElem elem) const {
	return false;
}

int Bag::nrOccurrences(TElem elem) const {
	//TODO - Implementation
	return bag[elem];
}


int Bag::size() const {
	//TODO - Implementation
	int notEmptyElem = 0;
	for (int i = 0; i < bagSize; i++)
		if (bag[i] != 0)
			notEmptyElem += bag[i];

	return notEmptyElem;

}


bool Bag::isEmpty() const {
	//TODO - Implementation
	int notEmptyElem = 0;
	for (int i = 0; i < bagSize; i++)
		if (bag[i] != 0)
			notEmptyElem++;
	if (notEmptyElem == 0)
		return true;
	return false;
}

BagIterator Bag::iterator() const {
	//TODO - Implementation
	return BagIterator(*this);
}


Bag::~Bag() {
	//TODO - Implementation
	delete bag;
}

