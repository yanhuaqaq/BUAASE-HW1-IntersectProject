

#include <iostream>
#include <string>
#include <fstream> 
#include <vector>
#include <set>
#include "Line.h"
#include "circle.h"

using namespace std;


Line::Line(int x0, int y0, int x1, int y1)//利用直线上两点确定直线一般式方程
{
	A = (double)y1 - (double)y0;
	B = (double)x0 - (double)x1;
	C = (double)x1 * (double)y0 - (double)x0 * (double)y1;
}

bool Line::isParallel(Line line) //判断是否平行
{
	double d;
	d = A * line.B - B * line.A;
	return d == 0;
}
pair<double, double> Line::findIntersection(Line line) //找到两直线交点
{
	double d;
	d = A * line.B - B * line.A;
	double x;
	double y;
	x = (B * line.C - line.B * C) / d;
	y = (C * line.A - line.C * A) / d;
	return make_pair(x,y);
}

Circle::Circle(int _x, int _y, int _r) {
	x = (double)_x;
	y = (double)_y;
	r = (double)_r;
}

bool Circle::isIntersectWithLine(Line line) {
	double d;
	d = (line.A * x + line.B * y + line.C) / sqrt(line.A * line.A + line.B * line.B);
	return d <= r;
}

void Circle::findIntersectWithLine(set<pair<double, double>>* points, Line line) {
	if (line.B != (double)0) {
		double k = -line.A / line.B;
		double b1 = -line.C / line.B;
		double s = b1 - y;
		double a = k * k + 1;
		double b = 2 * x - 2 * k * s;
		double c = x * x + s * s - r * r;
		double tmp = sqrt(b * b - 4 * a * c);
		if (tmp == (double)0) {
			double x1 = b / (2 * a);
			double y1 = k * x1 + b1;
			points->insert(make_pair(x1, y1));
		}
		else {
			double x1 = (b + tmp) / (2 * a);
			double y1 = k * x1 + b1;
			points->insert(make_pair(x1, y1));
			double x2 = (b - tmp) / (2 * a);
			double y2 = k * x2 + b1;
			points->insert(make_pair(x2, y2));

		}
	}
	else {
		double p = - line.C / line.A;
		double q = sqrt(r * r - (p - x) * (p - x));
		if (q == (double)0) {
			points->insert(make_pair(p, y));
		}
		else {
			double y1 = y + q;
			points->insert(make_pair(p, y1));
			double y2 = y - q;
			points->insert(make_pair(p, y2));
		}
	}
}

bool Circle::isIntersectWithCircle(Circle circle) {
	double x_d = x - circle.x;
	double y_d = y - circle.y;
	double d = sqrt(x_d * x_d + y_d * y_d);
	return (d <= (r + circle.r) && d >= fabs(r - circle.r));

}

void Circle::findIntersectWithCircle(set<pair<double, double>>* points, Circle circle) {
	double x1 = circle.x;
	double y1 = circle.y;
	double r1 = circle.r;
	double a = (2 * (x1 - x));
	double b = (2 * (y1 - y));
	double c = (x * x + y * y - r * r) - (x1 * x1 + y1 * y1 - r1 * r1);
	Line line(a, b, c);
	findIntersectWithLine(points, line);
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
	vector<Circle> circles;
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
			if (!circles.empty()) {
				for (size_t i = 0; i < circles.size(); i++)
				{
					if (circles.at(i).isIntersectWithLine(line)) {
						circles.at(i).findIntersectWithLine(&points, line);
					}
				}
			}
			lines.push_back(line);
		}
		else if (ch == 'C') {
			int x, y, r;
			infile >> x >> y >> r;
			Circle circle(x, y, r);
			if (!lines.empty()) {
				for (size_t i = 0; i < lines.size(); i++) {
					if (circle.isIntersectWithLine(lines.at(i))) {
						circle.findIntersectWithLine(&points, lines.at(i));
					}
				}
			}
			if (!circles.empty()) {
				for (size_t i = 0; i < circles.size(); i++)
				{
					if (circles.at(i).isIntersectWithCircle(circle)) {
						circles.at(i).findIntersectWithCircle(&points, circle);
					}
				}
			}
			circles.push_back(circle);
		}
	}
	outfile << points.size();
	
}

