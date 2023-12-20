#include "Input.h"

int Input::InputInt(string info, int min, int max)
{
	cout << info;
	int value;
	string str;
	getline(cin, str);
	if (str == "") {
		getline(cin, str);
	}
	istringstream iss(str);
	string tail;
	int res = (iss >> value) && !(iss >> tail);
	if (!res || value < 0)
	{
		return InputInt("Ошибка! Попробуйте еще раз: ", min, max);
	}
	if (min != 0 || max != 0) {
		if (value < min) {
			cout << "Не может быть меньше " << min << endl;
			return InputInt("Попробуйте еще раз: ", min, max);
		}
		if (value > max) {
			cout << "Не может быть больше " << max << endl;
			return InputInt("Попробуйте еще раз: ", min, max);
		}
	}
	return value;
}

float Input::InputFloat(string info)
{
	cout << info;
	float value;
	string str;
	getline(cin, str);
	if (str == "") {
		getline(cin, str);
	}
	istringstream iss(str);
	string tail;
	int res = (iss >> value) && !(iss >> tail);
	if (!res || value < 0)
	{
		return InputInt("Ошибка! Попробуйте еще раз: ", 0, 0);
	}

	return value;
}

void Input::InputString(string info, char* buf, int maxlen) {
	cout << info;
	string str;
	getline(cin, str);
	if (str == "") {
		getline(cin, str);
	}
	strcpy(buf, str.substr(0, maxlen).c_str());
}

string Input::MaxLenght(const char* str, int len) {
	string s(str);
	if (s.size() < len)
		return s;
	return s.substr(0, len);
}