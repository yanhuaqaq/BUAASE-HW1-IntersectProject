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
	double A;
	double B;
	double C;//ֱ��һ��ʽ����Ax+By+C=0;
	Line(int x0, int y0, int x1, int y1);
	bool isParallel(Line line);//�ж��Ƿ�ƽ��
	pair<double, double> findIntersection(Line line) ;

};

