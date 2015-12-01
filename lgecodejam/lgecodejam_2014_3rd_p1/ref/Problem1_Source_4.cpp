
// Ramesh: Program 1 

#include "stdafx.h"

#include <iostream>
#include <stdio.h>
#include <conio.h>

#include <iostream>
#include <stdio.h>

int crossings[200001];
int size;

int func(int x, int y)
{
	int xx = x;
	int yy = y;
	if(x == y || x == 1 || y == 1) return 1;
	for( int i = x; i >= 1; i = crossings[i] )
	{
		if(i == 0)
		return -1; 
		else if (y == i)
		return 1;
	}

	y = xx;
	x = yy;
	for( i = x; i >= 1; i = crossings[i] )
	{
		if(i == 0)
		return -1; 
		else if (y == i)
		return 1;
	}
	return -1;
}

int main()
{
	int testcases, noofcrossings, noofqueries;
	scanf("%d", &testcases);
	for(int j = 0; j < testcases; j++)
	{
		scanf("%d %d", &noofcrossings, &noofqueries);
		memset(crossings, 0, noofcrossings);
		int x, y;
		for(int i = 0; i < noofcrossings-1 ; i++)
		{
			scanf("%d %d", &x, &y);
			crossings[y] = x;
		}
		for( i = 0; i < noofqueries ; i++)
		{
			scanf("%d %d", &x, &y);
			if(1 == func(x, y))
				printf("1\n");
			else
				printf("0\n");
		}
	}
}
