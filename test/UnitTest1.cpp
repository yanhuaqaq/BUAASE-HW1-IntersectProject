#include "pch.h"
#include "CppUnitTest.h"
#include "..\IntersectProject\Line.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestLine1)//�������������ɵ�ֱ��һ��ʽ�����Ƿ���ȷ(�����)
		{
			Line line(2, 1, 3, 4);
			Assert::AreEqual(line.A, (double)3);
			Assert::AreEqual(line.B, (double)-1);
			Assert::AreEqual(line.C, (double)-5);
			Line line1(6, 3, 17, 26);
			Assert::AreEqual(line1.A, (double)23);
			Assert::AreEqual(line1.B, (double)-11);
			Assert::AreEqual(line1.C, (double)-105);
			Line line2(227, 533, 179, 265);
			Assert::AreEqual(line2.A, (double)-268);
			Assert::AreEqual(line2.B, (double)48);
			Assert::AreEqual(line2.C, (double)35252);
		}
		TEST_METHOD(TestLine2)//�������������ɵ�ֱ��һ��ʽ�����Ƿ���ȷ(�������)
		{
			Line line(12367, 533, 23674, 533);//AΪ0
			Assert::AreEqual(line.A, (double)0);
			Assert::AreEqual(line.B, (double)-11307);
			Assert::AreEqual(line.C, (double)6026631);
			Line line1(233, 675, 233, 1263);//BΪ0
			Assert::AreEqual(line1.A, (double)588);
			Assert::AreEqual(line1.B, (double)0);
			Assert::AreEqual(line1.C, (double)-137004);
		}
		TEST_METHOD(TestLine3)//�������������ɵ�ֱ��һ��ʽ�����Ƿ���ȷ(�߽����)
		{
			Line line(-99999, -98993, 99999, 98899);
			Assert::AreEqual(line.A, (double)197892);
			Assert::AreEqual(line.B, (double)-199998);
			Assert::AreEqual(line.C, (double)-9399906);
			Line line1(-99999, 98721, 100000, -98982);//BΪ0
			Assert::AreEqual(line1.A, (double)-197703);
			Assert::AreEqual(line1.B, (double)-199999);
			Assert::AreEqual(line1.C, (double)-26001018);
		}

		TEST_METHOD(TestParallel1)//����ƽ��(�����)
		{
			Line line1(1, 2, -5, -4);
			Line line2(-9, -8, 234, 235);
			Assert::AreEqual(line1.isParallel(line2), true);
		}
		TEST_METHOD(TestParallel2)//����ƽ��(�����)
		{
			Line line1(1, 3, 20, 16);
			Line line2(-89, 21, 312, 235);
			Assert::AreEqual(line1.isParallel(line2), false);
		}
		TEST_METHOD(TestParallel3)//����ƽ��(�������)
		{
			Line line1(1, 2, 3, 2);
			Line line2(234, 56, -2384, 56);
			Assert::AreEqual(line1.isParallel(line2), true);//AΪ0
			Line line3(1, 283, 1, -2283);
			Line line4(-89, 1237, -89, 2325);
			Assert::AreEqual(line3.isParallel(line4), true);//BΪ0
		}
		TEST_METHOD(TestParallel4)//����ƽ��(�������)
		{
			Line line1(1, 2, 3, 2);
			Line line2(-89, 1237, -89, 2325);
			Assert::AreEqual(line1.isParallel(line2), false);
		}
		TEST_METHOD(TestIntersect1)//���Խ���(�����)
		{
			Line line1(1, 2, 7, 2);
			Line line2(7, 2, -89, 2325);
			double x = (double)7;
			double y = (double)2;
			Assert::AreEqual(line1.findIntersection(line2).first, x);
			Assert::AreEqual(line1.findIntersection(line2).second, y);
		}
		TEST_METHOD(TestIntersect2)//���Խ���(�����)
		{
			Line line1(1, 2, 23, 42);
			Line line2(2, -42, -1, -54);
			double x = (double)23;
			double y = (double)42;
			Assert::AreEqual(line1.findIntersection(line2).first, x);
			Assert::AreEqual(line1.findIntersection(line2).second, y);
		}
		TEST_METHOD(TestIntersect3)//���Խ���(�߽����)
		{
			Line line1(-99999, 98721, 100000, -98982);
			Line line2(0, 1018, 100, 918);
			double x = (double)100000;
			double y = (double)(-98982);
			Assert::AreEqual(line1.findIntersection(line2).first, x);
			Assert::AreEqual(line1.findIntersection(line2).second, y);
		}
	};
}
