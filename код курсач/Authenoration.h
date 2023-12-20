#pragma once
#ifndef Authenoration_h
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
#include "User.h"
#include "Admin.h"
#include "Teacher.h"
#include "Zapis.h"
#include "Input.h"
using namespace std;

class Authenoration
{
public:
	friend int menu_u();
	static bool UserEnter(FILE* f);
	friend int menu_a();
	static bool AdminEnter(FILE* f);
	friend int menu_t();
	static bool TeacherEnter(FILE* f);
};


#endif // !Authenoration_h
