#pragma once
#ifndef Zapis_h
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

class Zapis
{
public:

	static int counter;
	int id;
	char Lesson[10];
	char FIO[30];
	Date lessdate;
	bool solved;
	char GetFIO();
	void Information();
	int GetId();
	Date GetLessDate();
	bool GetSolved();
	void Input();

	void MarkSolved();

	static void SetCounter(int value);
	static void PrintLine();
	static void PrintHeader();

	friend void ViewAllOrders(vector<Zapis>& Zapiss);
	friend void CreateNewOrder(vector<Zapis>& Zapiss);
	friend void ViewFinishedOrders(vector<Zapis>& Zapiss);
	friend void ViewFailedOrders(vector<Zapis>& Zapiss);
	friend void MarkCompleted(vector<Zapis>& Zapiss);
	friend vector<Zapis> searchByLesson(const vector<Zapis>& Zapiss, const string& lesson);
	friend void SearchByLesson(vector<Zapis>& Zapiss);
	friend vector<Zapis> searchByID(const vector<Zapis>& Zapiss, const int& id);
	friend void SearchByID(vector<Zapis>& Zapiss);
	friend int partition0(vector<Zapis>& Zapiss, int low, int high);
	friend void Quicksort(vector<Zapis>& Zapiss, int low, int high);
	friend void sortVectorByFio(vector<Zapis>& Zapiss);
	friend void sortirovkaFIO(vector<Zapis>& Zapiss);
	friend int partition(vector<Zapis>& Zapiss, int low, int high);
	friend void quickSort(vector<Zapis>& Zapiss, int low, int high);
	friend void sortVectorByLesson(vector<Zapis>& Zapiss);
	friend void sortirovkaLesson(vector<Zapis>& Zapiss);
	friend int partition1(vector<Zapis>& Zapiss, int low, int high);
	friend void QuickSort(vector<Zapis>& Zapiss, int low, int high);
	friend void sortVectorByID(vector<Zapis>& Zapiss);

	friend void sortirovkaID(vector<Zapis>& Zapiss);
	friend vector<Zapis> searchBySurname(const vector<Zapis>& Zapiss, const string& surname);
	friend void SearchByFIO(vector<Zapis>& Zapiss);
	friend int pathToSearch(int variant);
	friend void EditZapisBySyrname(vector<Zapis>& Zapiss);
	friend void EditZapisByLesson(vector<Zapis>& Zapiss);
	friend void EditZapisByID(vector<Zapis>& Zapiss);
	friend void EditZapis(vector<Zapis>& Zapiss);
	friend void deleteZapis(vector<Zapis>& Zapiss, int index);
	friend void deleteZapisByLesson(vector<Zapis>& Zapiss);
	friend void deleteZapisByID(vector<Zapis>& Zapiss);
	friend void deleteZapisByFIO(vector<Zapis>& Zapiss);
	friend void deleteZapisBy(vector<Zapis>& Zapiss);
	friend vector<Zapis> searchByLessonAndDate(const vector<Zapis>& Zapiss, const string& lesson, const Date& searchDate);
	friend void SearchByLessonAndDate(vector<Zapis>& Zapiss);
};
#endif // !Zapis