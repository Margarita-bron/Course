#pragma once
#ifndef User_h
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
using namespace std;
class User
{
public:
	int id;
	string name;
	string password;
	string phoneNumber;
	string email;
	int age;
	User();
	User(User& node);
	User(string name, string password, string phoneNumber, string email, int age);
	int IDGet();
	int ageGet();
	string nameGet();
	string emailGet();
	string phoneNumberGet();
	string passwordGet();
	void IDSet(int id);
	void nameSet(string name);
	void phoneNumberSet(string phoneNumber);
	void emailSet(string email);
	void ageSet(int age);

	static string PasswordEntering();
	static bool isValidEmail(const std::string& email);
	static bool isValidPhoneNumber(const std::string& phoneNumber);
};
#endif // !User_h

