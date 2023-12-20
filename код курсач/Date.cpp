#include "Date.h"

	Date::Date()
	{
		day = 0;
		month = 0;
		year = 0;
	}
	Date::Date(int day, int month, int year)
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}
	int Date::GetDay() {
		return day;
	}
	int Date::GetMonth() {
		return month;
	}
	int Date::GetYear() {
		return year;
	}
	void Date::Input()
	{
		cout << "Введите дату в формате ДД.MM.ГГГГ: ";
		string date;
		getline(cin, date);
		if (date.empty()) {
			getline(cin, date);
		}

		istringstream iss(date);
		char dot;
		iss >> day >> dot >> month >> dot >> year;
		if (iss.fail() || date.size() > 10 || dot != '.' || day < 1 || day > 31 || month < 1 || month > 12 || year < 2023 || year > 2025) {
			cout << "Ошибка! Попробуйте еще раз!" << endl;
			Input();
		}
	}

	bool Date::operator<(const Date& other) const
	{
		if (year < other.year)
			return true;
		if (year > other.year)
			return false;

		if (month < other.month)
			return true;
		if (month > other.month)
			return false;

		if (day < other.day)
			return true;
		if (day > other.day)
			return false;

		return false;
	}

	bool Date::operator==(const Date& other) const
	{
		return day == other.day && month == other.month && year == other.year;
	}

	bool Date::operator<=(const Date& other) const
	{
		return *this < other || *this == other;
	}

	bool Date::operator>=(const Date& other) const
	{
		return !(*this < other);
	}

	ostream& operator<<(ostream& out, const Date& date)
	{
	ostringstream oss;
	oss << date.day << '.' << date.month << '.' << date.year;
	out << oss.str();
	return out;
	}

	istream& operator>>(istream& in, Date& date) {
	string input;
	getline(in, input);
	istringstream iss(input);
	char dot;
	iss >> date.day >> dot >> date.month >> dot >> date.year;
	return in;
	}