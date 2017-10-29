#include<iostream>
#include<stdlib.h>

using namespace std;

struct Rect
{
	int x,y,w,h,z;
	Rect(int x=0, int y=0, int z=0, int h=0);
};

struct Point
{
	int x,y;
	Point(int x=0, int y=0);
};
