#pragma once
#ifndef Admin_h
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
#include "Teacher.h"
using namespace std;

class Admin: public User
{
public:
	friend class Teacher;
	Admin();
	Admin(string name, string password, string phoneNumber, string email, int age);

	static bool AdminSearch(string adminName);
	static void AccountAdmin(string userName);
	static void EditAdmin(string adminName);
	static void DeleteUsers();
	static void DeleteUser(string userName);
};
#endif // !Admin_h

