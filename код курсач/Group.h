#pragma once
#ifndef Group_h
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
#include <vector>
#include "Student.h"
#include "User.h"
#include "Admin.h"



class Group
{
private:
    std::vector<Student> students;
public:
    Group(vector<Student> &students, int groupName) {
		FILE* f;
		Student* client;
		if ((f = fopen("Userslist", "rb+")) == NULL)
		{
			cout << "Error" << endl;
		}
		int amount = _filelength(_fileno(f)) / sizeof(Student);
		client = new Student[amount];
		fread(client, sizeof(Student), amount, f);
		if (amount > 0)
		{
			for (int i = 0; i < amount; i++)
			{
				if (client[i].groupNameGet() == groupName)
				{
					
				}
			}
		}
		else
		{
			cout << "В данной группе нет студентов" << endl;
		}
		fclose(f);
	}

    /*void addStudent(Student student) {
        students.push_back(student);
    }

    void removeStudent(Student student) {
        students.erase(std::remove(students.begin(), students.end(), student), students.end());
    }


    void addStudent(const std::string& name, int id) {
        students.emplace_back(name, id);
    }

    
	Student getStudent(string userName)
	{
		FILE* f;
		Student client;
		int amount;

		if ((f = fopen("Userslist", "rb+")) == NULL) // открываем файл для чтения и записи
		{
			cout << "Error" << endl;
			return;
		}

		amount = _filelength(_fileno(f)) / sizeof(Student);

		for (int i = 0; i < amount; i++)
		{
			fread(&client, sizeof(Student), 1, f); // читаем одного пользователя из файла

			if (client.nameGet() == userName) // находим пользователя по имени
			{
				cout << "Current data: " << endl
					<< "Name: " << client.nameGet() << endl
					<< "Phone number: " << client.phoneNumberGet() << endl
					<< "Email: " << client.emailGet() << endl
					<< "Age: " << client.ageGet() << endl;
			}
		}

		fclose(f);
	}*/
    
};
#endif // !Group_h



