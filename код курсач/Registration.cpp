#include "Registration.h"

void Registration::AddUser()
{
	FILE* f;
	string nameA, password, email, phoneNumber;
	int age;
	if ((f = fopen("Userslist", "ab")) == NULL)
	{
		cout << "Error" << endl;
		return;
	}
	cout << "������� ���: ";
	cin >> nameA;
	cout << "������� ������: ";
	cin >> password;
	cout << "������� ����� ��������: ";
	cin >> phoneNumber;
	while (!User::isValidPhoneNumber(phoneNumber)) {
		cout << "������� ������ �����������." << endl;
		cin >> phoneNumber;
	}
	cout << "������� email: ";
	cin >> email;
	while (!User::isValidEmail(email)) {
		cout << "Email ������ �����������." << endl;
		cin >> email;
	}
	age = Zapis::InputInt("������� �������: ", 15, 99);
	User client(nameA, password, phoneNumber, email, age);
	fwrite(&client, sizeof(User), 1, f);
	cout << "����������� ������ ������������ ������ �������!" << endl;
	fclose(f);
}

void Registration::AddAdmin()
{
	FILE* f;
	string nameA, password, email, phoneNumber;
	int age;
	if ((f = fopen("Adminslist", "ab")) == NULL)
	{
		cout << "Error" << endl;
		return;
	}
	cout << "������� ���: ";
	cin >> nameA;
	cout << "������� ������: ";
	cin >> password;
	cout << "������� ����� ��������: ";
	cin >> phoneNumber;
	while (!User::isValidPhoneNumber(phoneNumber)) {
		cout << "������� ������ �����������." << endl;
		cin >> phoneNumber;
	}
	cout << "������� email: ";
	cin >> email;
	while (!User::isValidEmail(email)) {
		cout << "Email ������ ���������." << endl;
		cin >> email;
	}
	cout << "������� �������: ";
	cin >> age;
	Admin admin(nameA, password, phoneNumber, email, age);
	fwrite(&admin, sizeof(Admin), 1, f);
	cout << "����������� ������ �������!" << endl;
	fclose(f);
}

void Registration::AddTeacher()
{
	FILE* f;
	string nameA, password, email, phoneNumber;
	int age;
	if ((f = fopen("Teacherlist", "ab")) == NULL)
	{
		cout << "Error" << endl;
		return;
	}
	cout << "������� ���: ";
	cin >> nameA;
	cout << "������� ������: ";
	cin >> password;
	cout << "������� ����� ��������: ";
	cin >> phoneNumber;
	while (!User::isValidPhoneNumber(phoneNumber)) {
		cout << "������� ������ �����������." << endl;
		cin >> phoneNumber;
	}
	cout << "������� email: ";
	cin >> email;
	while (!User::isValidEmail(email)) {
		cout << "Email ������ ���������." << endl;
		cin >> email;
	}
	cout << "������� �������: ";
	cin >> age;
	Teacher teacher(nameA, password, phoneNumber, email, age);
	fwrite(&teacher, sizeof(Teacher), 1, f);
	cout << "����������� ������ �������!" << endl;
	fclose(f);
}

void Creat(FILE* f, char* name)
{
	if ((f = fopen(name, "wb")) == NULL)
	{
		cout << "Error" << endl;
		return;
	}
	fclose(f);
	return;
}