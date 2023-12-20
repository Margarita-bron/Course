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
	cout << "Введите имя: ";
	cin >> nameA;
	cout << "Введите пароль: ";
	cin >> password;
	cout << "Введите номер телефона: ";
	cin >> phoneNumber;
	while (!User::isValidPhoneNumber(phoneNumber)) {
		cout << "Телефон введен некорректно." << endl;
		cin >> phoneNumber;
	}
	cout << "Введите email: ";
	cin >> email;
	while (!User::isValidEmail(email)) {
		cout << "Email введен некорректно." << endl;
		cin >> email;
	}
	age = Zapis::InputInt("Введите возраст: ", 15, 99);
	User client(nameA, password, phoneNumber, email, age);
	fwrite(&client, sizeof(User), 1, f);
	cout << "Регистрация нового пользователя прошла успешно!" << endl;
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
	cout << "Введите имя: ";
	cin >> nameA;
	cout << "Введите пароль: ";
	cin >> password;
	cout << "Введите номер телефона: ";
	cin >> phoneNumber;
	while (!User::isValidPhoneNumber(phoneNumber)) {
		cout << "Телефон введен некорректно." << endl;
		cin >> phoneNumber;
	}
	cout << "Введите email: ";
	cin >> email;
	while (!User::isValidEmail(email)) {
		cout << "Email введен корректно." << endl;
		cin >> email;
	}
	cout << "Введите возраст: ";
	cin >> age;
	Admin admin(nameA, password, phoneNumber, email, age);
	fwrite(&admin, sizeof(Admin), 1, f);
	cout << "Регистрация прошла успешно!" << endl;
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
	cout << "Введите имя: ";
	cin >> nameA;
	cout << "Введите пароль: ";
	cin >> password;
	cout << "Введите номер телефона: ";
	cin >> phoneNumber;
	while (!User::isValidPhoneNumber(phoneNumber)) {
		cout << "Телефон введен некорректно." << endl;
		cin >> phoneNumber;
	}
	cout << "Введите email: ";
	cin >> email;
	while (!User::isValidEmail(email)) {
		cout << "Email введен корректно." << endl;
		cin >> email;
	}
	cout << "Введите возраст: ";
	cin >> age;
	Teacher teacher(nameA, password, phoneNumber, email, age);
	fwrite(&teacher, sizeof(Teacher), 1, f);
	cout << "Регистрация прошла успешно!" << endl;
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