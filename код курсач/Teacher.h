#pragma once
#ifndef Teacher_h
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
#include "User.h"
using namespace std;

class Teacher: public User
{
public:
	Teacher();
	Teacher(string name, string password, string phoneNumber, string email, int age);

	static bool TeacherSearch(string teacherName);
	static void AccountTeacher(string teacherName);
	static void EditTeacher(string teacherName);
	/*static void AllTeachersView();*/
};

#endif









