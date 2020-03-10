#pragma once
#include <iostream>
#include <string>
#include <fstream> 
#include <vector>
#include <set>

using namespace std;

class Line
{
public:
	int A;
	int B;
	int C;//直线一般式方程Ax+By+C=0;
	Line(int x0, int y0, int x1, int y1);
	bool isParallel(Line line);//判断是否平行
	pair<double, double> findIntersection(Line line) ;

};

