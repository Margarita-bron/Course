#include "User.h"

	User::User()//����������� �� ���������
	{
		/*id = 0;*/
		age = 0;
		name = "0";
		password = "0";
		phoneNumber = "0";
		email = "0";
	}
	User::User(User& node)//����������� �����������
	{

		/*id = node.id;*/
		age = node.age;
		name = move(node.name);
		password = move(node.password);
		phoneNumber = move(node.phoneNumber);
		email = move(node.email);
	}
	User::User(string name, string password, string phoneNumber, string email, int age)
	{
		/*this->id = id;*/
		this->age = age;
		this->name = name;
		this->password = password;
		this->phoneNumber = phoneNumber;
		this->email = email;
	}

	/*int User::IDGet()
	{
		return id;
	}*/
	int User::ageGet()
	{
		return age;
	}
	string User::nameGet()
	{
		return name;
	}
	string User::emailGet()
	{
		return email;
	}
	string User::phoneNumberGet()
	{
		return phoneNumber;
	}
	string User::passwordGet()
	{
		return password;
	}
	/*void User::IDSet(int id) { this->id = id; };*/
	void User::nameSet(string name) { this->name = name; }
	void User::phoneNumberSet(string phoneNumber) { this->phoneNumber = phoneNumber; }
	void User::emailSet(string email) { this->email = email; }
	void User::ageSet(int age) { this->age = age; }

string User::PasswordEntering()
{
	string pass;
	int ch = 0;               // ���������� ��� �������.
	while (true)                // �������� ������������ �����.
	{
		ch = _getch();        // �������� ��� ������� ������� � ����������.
		if (ch == 13)         // ��������� Enter �� ���������� �����.
		{
			break;         // ���������� �����.
		}
		if (ch == 8)     // ��������� Backspace �� �������� ��������.
		{
			cout << char(8) << ' ' << char(8);
			if (!pass.empty())
			{
				pass.erase(pass.length() - 1);//�������� ���������� ������� ������(������� ������� ������������ ��� ��������)
			}
		}
		else
		{
			cout << '*';
			pass += (char)ch;
		}
	}
	return pass;
}

 bool User::isValidEmail(const std::string& email) {
	const std::regex pattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");

	return std::regex_match(email, pattern);
}

 bool User::isValidPhoneNumber(const std::string& phoneNumber) {
	const std::regex pattern(R"(^\+375\d{9}$)");

	return std::regex_match(phoneNumber, pattern);
}



