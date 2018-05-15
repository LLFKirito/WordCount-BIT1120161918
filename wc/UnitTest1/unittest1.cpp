#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\wc\define.h"
#include "..\wc\define.cpp"
#include "..\wc\fundamental.h"
#include "..\wc\fundamental.cpp"
#include "..\wc\extended.h"
#include "..\wc\extended.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int examine_1 = check_file_name("..\\UnitTest1\\TestCase\\test3.c");
			int examine_2 = check_file_name("..\\UnitTest1\\TestCase\\test4.cpp");
			int examine_3 = check_file_name("..\\UnitTest1\\TestCase\\test8.py");
			int examine_4 = check_file_name("..\\UnitTest1\\TestCase\\1120161918.txt");
			int examine_5 = check_file_name("..\\UnitTest1\\TestCase\\1120161922.cpp");
			
			Assert::AreEqual(examine_1 == 1, true);
			Assert::AreEqual(examine_2 == 1, true);
			Assert::AreEqual(examine_3 == 1, true);
			Assert::AreEqual(examine_4 == -1, true);
			Assert::AreEqual(examine_5 == -1, true);
		}
		
		TEST_METHOD(TestMethod2)
		{
			int examine_1 = check_order("-c");
			int examine_2 = check_order("-w");
			int examine_3 = check_order("-l");
			int examine_4 = check_order("-a");
			int examine_5 = check_order("-cxxcsc");
			int examine_6 = check_order("c");
			
			Assert::AreEqual(examine_1 == 1, true);
			Assert::AreEqual(examine_2 == 1, true);
			Assert::AreEqual(examine_3 == 1, true);
			Assert::AreEqual(examine_4 == 1, true);
			Assert::AreEqual(examine_5 == -1, true);
			Assert::AreEqual(examine_6 == -1, true);
		}
		
		TEST_METHOD(TestMethod3)
		{
			char file[] = "..\\UnitTest1\\TestCase\\test1.c";
			int num_ch = count_character(file);
			
			Assert::AreEqual(num_ch == 36, true);
		}
		
		TEST_METHOD(TestMethod4)
		{
			char file[] = "..\\UnitTest1\\TestCase\\test1.c";
			int num_w = count_word(file);
			
			Assert::AreEqual(num_w == 6, true);
		}
		
		TEST_METHOD(TestMethod5)
		{
			char file[] = "..\\UnitTest1\\TestCase\\test1.c";
			int num_l = count_line(file);
			
			Assert::AreEqual(num_l == 5, true);
		}
		
		TEST_METHOD(TestMethod6)
		{
			char file[] = "..\\UnitTest1\\TestCase\\test2.c";
			int num_ch = count_character(file);
			int num_w = count_word(file);
			int num_l = count_line(file);
			
			Assert::AreEqual(num_ch == 44, true);
			Assert::AreEqual(num_w == 7, true);
			Assert::AreEqual(num_l == 5, true);
		}
		
		TEST_METHOD(TestMethod7)
		{
			char file[] = "..\\UnitTest1\\TestCase\\test3.c";
			int num_bl = count_blankline(file);
			int num_nl = count_noteline(file);
			int num_cl = count_codeline(file);
			
			Assert::AreEqual(num_bl == 2, true);
			Assert::AreEqual(num_nl == 0, true);
			Assert::AreEqual(num_cl == 3, true);
		}
		
		TEST_METHOD(TestMethod8)
		{
			char file[] = "..\\UnitTest1\\TestCase\\test4.cpp";
			int num_ch = count_character(file);
			int num_w = count_word(file);
			int num_l = count_line(file);
			int num_bl = count_blankline(file);
			int num_nl = count_noteline(file);
			int num_cl = count_codeline(file);
			
			Assert::AreEqual(num_ch == 224, true);
			Assert::AreEqual(num_w == 52, true);
			Assert::AreEqual(num_l == 15, true);
			Assert::AreEqual(num_bl == 2, true);
			Assert::AreEqual(num_nl == 0, true);
			Assert::AreEqual(num_cl == 13, true);
		}
		
		TEST_METHOD(TestMethod9)
		{
			char file[] = "..\\UnitTest1\\TestCase\\test5.cpp";
			int num_ch = count_character(file);
			int num_w = count_word(file);
			int num_l = count_line(file);
			int num_bl = count_blankline(file);
			int num_nl = count_noteline(file);
			int num_cl = count_codeline(file);
			
			Assert::AreEqual(num_ch == 338, true);
			Assert::AreEqual(num_w == 81, true);
			Assert::AreEqual(num_l == 37, true);
			Assert::AreEqual(num_bl == 15, true);
			Assert::AreEqual(num_nl == 0, true);
			Assert::AreEqual(num_cl == 22, true);
		}
		
		TEST_METHOD(TestMethod10)
		{
			char file[] = "..\\UnitTest1\\TestCase\\test6.cpp";
			int num_ch = count_character(file);
			int num_w = count_word(file);
			int num_l = count_line(file);
			int num_bl = count_blankline(file);
			int num_nl = count_noteline(file);
			int num_cl = count_codeline(file);
			
			Assert::AreEqual(num_ch == 210, true);
			Assert::AreEqual(num_w == 47, true);
			Assert::AreEqual(num_l == 21, true);
			Assert::AreEqual(num_bl == 7, true);
			Assert::AreEqual(num_nl == 0, true);
			Assert::AreEqual(num_cl == 14, true);
		}
		
		TEST_METHOD(TestMethod11)
		{
			char file[] = "..\\UnitTest1\\TestCase\\test9.py";
			int num_ch = count_character(file);
			int num_w = count_word(file);
			int num_l = count_line(file);
			int num_bl = count_blankline(file);
			int num_nl = count_noteline(file);
			int num_cl = count_codeline(file);
			
			Assert::AreEqual(num_ch == 202, true);
			Assert::AreEqual(num_w == 25, true);
			Assert::AreEqual(num_l == 19, true);
			Assert::AreEqual(num_bl == 2, true);
			Assert::AreEqual(num_nl == 0, true);
			Assert::AreEqual(num_cl == 17, true);
		}
		
	};
}
