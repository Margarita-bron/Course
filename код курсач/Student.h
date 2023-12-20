#pragma once
#ifndef Student_h
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

class Student : public User
{
public:
	int groupName;
	Student();
	Student(string name, string password, string phoneNumber, string email, int age);
	int groupNameGet();
	void groupNameSet(int groupName);

	static bool UserSearch(string adminName);
	static void AccountUser(string userName);
	static void EditClient(string adminName);
	static void AllUsersView();
};
#endif // !Student_h

