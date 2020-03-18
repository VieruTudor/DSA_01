#include <exception>
#include "BagIterator.h"
#include "Bag.h"
#include <iostream>
using namespace std;


BagIterator::BagIterator(const Bag& c): bag(c)
{
	currentIndex = 0;
	currentFrequency = 0;
	first();
}

void BagIterator::first() {
	//TODO - Implementation
	int i;
	for (i = 0; i < bag.bagCapacity && bag.bag[i] == 0; i++)
		;
	
	currentIndex = i;
	if (i < bag.bagCapacity)
	{
		currentFrequency = bag.bag[i];
	}
}

void BagIterator::print(){
	cout << currentIndex << "\n" << bag.bagCapacity << "\n";
}

void BagIterator::next() {
	int i = 0;
	if (!valid())
		throw exception();
	if (currentFrequency > 0)
		currentFrequency--;
	if (currentFrequency == 0)
	{
		currentIndex++;
		while (currentIndex < bag.bagCapacity && bag.bag[currentIndex] == 0)
		{
			currentIndex++;
		}
		if (currentIndex == bag.bagCapacity)
			return;
		else
			currentFrequency = bag.bag[currentIndex];
	}
}

bool BagIterator::valid() const {
	//TODO - Implementation
	
	if (currentIndex < bag.bagCapacity)
		return true;
	return false;
}


TElem BagIterator::getCurrent() const
{
	if (valid())
		return currentIndex + bag.minValue;
	else
		throw exception();
	
}
