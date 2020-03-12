#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag& c): bag(c)
{
	currentIndex = 0;
	currentFrequency = 0;
}

void BagIterator::first() {
	//TODO - Implementation
	int i;
	for (i = 0; i < bag.bagCapacity && bag.bag[i] == 0; i++)
		;
	if (i < bag.bagCapacity)
	{
		currentIndex = i;
		currentFrequency = bag.bag[i];
	}
	else
	{
		throw exception();
	}
}
void BagIterator::next() {
	
	int i = 0;
	if (!valid())
		throw exception();
	
	if (currentFrequency > 0)
		currentFrequency--;
	/// 0 0 0 1 4 0 1
	if(currentFrequency == 0)
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
	if (currentIndex < bag.bagCapacity)
		return currentIndex + bag.minValue;
	else
		throw exception();
	
}
