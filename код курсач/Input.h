#pragma once
#ifndef Input_h
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
#include <vector>
#include <sstream>
#include <io.h>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <regex>
#include "Date.h"
using namespace std;
class Input
{
public:
	static int InputInt(string info, int min, int max);
	static float InputFloat(string info);
	static void InputString(string info, char* buf, int maxlen);
	static string MaxLenght(const char* str, int len);
};
#endif // !Input


