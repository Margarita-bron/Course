#pragma once
#ifndef Registration_h
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

class Registration:public User
{
public:

	static void AddUser();
	static void AddAdmin();
	static void AddTeacher();

	friend void Creat(FILE* f, char* name);
};

#endif // !Registration_h



