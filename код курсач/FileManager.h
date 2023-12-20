#pragma once
#ifndef FileManager_h
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
#include "Teacher.h"
#include "Admin.h"
#include "Zapis.h"
#include "Student.h"
using namespace std;

class FileManager
{
public:
	/*static string ADMINFILE;
	static string CLIENTFILE;
	static string TEACHERFILE;*/
	static const char* LESSONSFILE;

	static void SaveOrdersToFileLIST(vector<Zapis>& Zapiss);
	static void LoadOrdersFromFileLIST(vector<Zapis>& Zapiss);
	static void Creat(FILE* f, char* name);
};
#endif
