#pragma once
#include <iostream>
#include <string>
#include <fstream> 
#include <vector>
#include <set>
#include "Line.h"

using namespace std;

class Circle {

public:
	double x, y, r;
	Circle(int _x, int _y, int _r);
	bool isIntersectWithLine(Line line);
	void findIntersectWithLine(set<pair<double, double>>* points, Line line);

	bool isIntersectWithCircle(Circle circle);
	void findIntersectWithCircle(set<pair<double, double>>* points, Circle circle);

};