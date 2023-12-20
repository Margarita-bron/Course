#pragma once
#ifndef Date
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cstring>
#include <vector>
#include <sstream>
#include <io.h>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <regex>
using namespace std;

class Date
{
public:
	int day;
	int month;
	int year;
public:
	Date();
	Date(int day, int month, int year);
	int GetDay();
	int GetMonth();
	int GetYear();
	void Input();

	bool operator<(const Date& other) const;
	bool operator==(const Date& other) const;
	bool operator<=(const Date& other) const;
	bool operator>=(const Date& other) const;

	friend istream& operator>>(istream& in, const Date& date);
	friend ostream& operator<<(ostream& out, const Date& date);
};
#endif // !Date


