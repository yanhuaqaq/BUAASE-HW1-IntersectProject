

#include <iostream>
#include <string>
#include <fstream> 
#include <vector>
#include <set>
#include "Line.h"

using namespace std;


Line::Line(int x0, int y0, int x1, int y1)//利用直线上两点确定直线一般式方程
{
	A = y1 - y0;
	B = x0 - x1;
	C = x1 * y0 - x0 * y1;
}

bool Line::isParallel(Line line) //判断是否平行
{
	int d;
	d = A * line.B - B * line.A;
	return d == 0;
}
pair<double, double> Line::findIntersection(Line line) //找到两直线交点
{
	int d;
	d = A * line.B - B * line.A;
	double x;
	double y;
	x = (B * line.C - line.B * C) / d;
	y = (C * line.A - line.C * A) / d;
	return make_pair(x,y);
}

int main(int argc,  const char* argv[])
{
	string in_file;
	string out_file;
	for (int i = 0; i < argc; i++) {//命令行参数处理
		if (argv[i][0] == '-') {
			if (argv[i][1] == 'i') {
				in_file += argv[i + 1];
			}
			else if (argv[i][1] == 'o') {
				out_file += argv[i + 1];
			}
		}
	}


	ifstream infile;
	ofstream outfile;
	infile.open(in_file, ios::in);
	outfile.open(out_file, ios::out);


	int n;
	infile >> n;
	vector<Line> lines;
	set<pair<double, double>> points;
	while (n--) {
		char ch;
		infile >> ch;
		if (ch == 'L') {//读取直线坐标
			int x0;
			int x1;
			int y0;
			int y1;
			infile >> x0 >> y0 >> x1 >> y1;
			Line line(x0, y0, x1, y1);
			if (!lines.empty()) {//判断是否为第一条直线
				for (size_t i = 0; i < lines.size(); i++) {
					if (!line.isParallel(lines.at(i))) {
						points.insert(line.findIntersection(lines.at(i)));
					}
				}//计算该直线与容器中所有直线的交点并加入points
			}
			lines.push_back(line);
		}
	}
	outfile << points.size();
	
}

