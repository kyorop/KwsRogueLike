#include "RandExtended.h"
#include <ctime>
#include <cstdlib>

void SRand();

int GetRand(int max)
{
	return GetRandInRange(0, max);
}

int GetRandInRange(int min, int max)
{
	SRand();
	return min + rand() % (max - min + 1);
}

std::vector<int> GetRandomNumberFromArray(std::vector<int>* intArray, int num)
{
	SRand();
	int arraySize = intArray->size();
	int currentNum = arraySize;
	int lastIndex = arraySize - 1;
	std::vector<int> retArray;
	for (int i = currentNum; i >= 1; i--)
	{
		int gottenIndex = rand() % i;
		if (gottenIndex == lastIndex)
			continue;
		int gottenNum = (*intArray)[gottenIndex];
		for (int j = gottenIndex; j < arraySize; j++)
		{
			intArray[j] = intArray[j + 1];
		}
		(*intArray)[lastIndex] = gottenNum;
		retArray.push_back(gottenNum);
	}

	return retArray;
}

void SRand()
{
	static bool isSeedGiven = false;
	if (!isSeedGiven)
	{
		srand((unsigned int)time(nullptr));
		isSeedGiven = true;
	}
}