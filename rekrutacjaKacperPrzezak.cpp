// rekrutacjaKacperPrzezak.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
#include <iterator>
#include <limits>

struct indexMaxNeighbor
{
	unsigned int minValueIndex;
	unsigned int maxLeftIndex ;
	unsigned int maxRightIndex ;


	indexMaxNeighbor()
	{
		maxLeftIndex = NULL;
		maxRightIndex = NULL;
		minValueIndex = NULL;
	}

	indexMaxNeighbor(unsigned int minValueIndexArg, unsigned int maxLeftIndexArg,unsigned int maxRightIndexArg)
	{
		minValueIndex = minValueIndexArg;
		maxLeftIndex = maxLeftIndexArg;
		maxRightIndex = maxRightIndexArg;

	}
};

using namespace std;

int size = 10;
unsigned maxValue = 20;

unsigned int minValue ;

vector<unsigned int> valueVector;
vector<unsigned int> indexesOfMinVector;
vector<indexMaxNeighbor> maxNeighbourIndex;

void initVectorWithRandomValue()
{
	srand(time(NULL));

	unsigned int tempValue = 0;

	for( int i=0; i < size ; i++ )
	{		
		tempValue = rand() % maxValue;
		valueVector.push_back(tempValue);	
	}

}

void printContentOfMinIndexVector()
{
	cout<<"\nindex of min vector content\n";

	for(int i =0;i<indexesOfMinVector.size();i++)	
	{
		cout<<"\n"<<indexesOfMinVector[i];
	}

	cout<<"\nend of min index vector content\n\n";
}

void printContentOfVector()
{
	cout<<"\nVector content\n";

	for(int i =0;i<valueVector.size();i++)	
	{
		cout<<"\n"<<valueVector[i];
	}

	cout<<"\nend of vector content\n\n";
}

unsigned int getMinValue()
{
	minValue =  numeric_limits<unsigned int>::max();

	//get min value
	for(int i =0;i<valueVector.size();i++)
	{
		if ( valueVector[i] < minValue )
		{
			minValue = valueVector[i];
		}
	}

	return minValue;
}

void setIndexOfLocalMinToVector()
{
	for( auto index =0; index < valueVector.size(); index++)
	{
		if ( valueVector[index] == minValue )
		{
			indexesOfMinVector.push_back(index);
		}
	}

}

//consider create one generic method
unsigned int getMaxLeftNeighborIndex(unsigned int indexOfMinValue)
{

	//todo valide this or try catch
	int localMax = valueVector[indexOfMinValue];
	unsigned int resultIndex = NULL;


	
	for( int index = indexOfMinValue; index >= 0 ; index-- )
	{
		if(valueVector[index] > localMax)
		{
			localMax = valueVector[index];
			resultIndex = index;
		}

		//consider equal 
		if(valueVector[index] <= localMax && index != indexOfMinValue )
		{
			break;
		}
	}

	return resultIndex;

}

unsigned int getMaxRightNeighborIndex(unsigned int indexOfMinValue)
{
	//todo valide this or try catch
	int localMax = valueVector[indexOfMinValue];

	unsigned int resultRightMaxIndex = NULL; 

	
	for( int index = indexOfMinValue; index  < valueVector.size(); index++ )
	{
		if(valueVector[index] > localMax)
		{
			localMax = valueVector[index];
			resultRightMaxIndex = index;
		}

		//consider equal 
		if(valueVector[index] <= localMax && index != indexOfMinValue )
		{
			break;
		}
	}


	return resultRightMaxIndex;

}

void initNeighbourhoodVector()
{
	unsigned int tempMaxLeftNeighborIndex = NULL;
	
	unsigned int tempMaxRightNeighborIndex = NULL;


	for( int i=0 ;i < indexesOfMinVector.size() ; i++ )
	{
		tempMaxLeftNeighborIndex = getMaxLeftNeighborIndex(indexesOfMinVector[i]);

		tempMaxRightNeighborIndex = getMaxRightNeighborIndex(indexesOfMinVector[i]);

	}


}

int _tmain(int argc, _TCHAR* argv[])
{

	initVectorWithRandomValue();

	printContentOfVector();

	minValue = getMinValue();
	
	cout<<"\nMin Value is equal "<<minValue<<endl;

	setIndexOfLocalMinToVector();
	//get index of min value

	
	initNeighbourhoodVector();


	
	

	system("pause");

	return 0;
}

