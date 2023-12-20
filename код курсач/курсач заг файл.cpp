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
#include "User.h"
#include "Teacher.h"
#include "Admin.h"
#include "Zapis.h"
#include "Student.h"
#include "FileManager.h"
using namespace std;

HANDLE stdOut = GetStdHandle(STD_OUTPUT_HANDLE);
void GoToXY(short x, short y) {

	SetConsoleCursorPosition(stdOut, { x,y });
}

int menu_u() {
	int key = 0;
	int code;
	do {
		system("cls");
		key = (key + 13) % 13;
		cout << "------------------------------------WELCOME-----------------------------------------" << endl;

		if (key == 0) cout << "-> Редактирование личных данных" << endl;
		else  cout << "   Редактирование личных данных" << endl;

		if (key == 1) cout << "-> Просмотр личных данных" << endl;
		else  cout << "   Просмотр личных данных" << endl;

		if (key == 2) cout << "-> Просмотреть расписание" << endl;
		else  cout << "   Просмотреть расписание" << endl;

		if (key == 3) cout << "-> Просмотреть пройденные занятия (рейтинг)" << endl;
		else  cout << "   Просмотреть пройденные занятия (рейтинг)" << endl;

		if (key == 4) cout << "-> Просмотреть не пройденные занятия" << endl;
		else  cout << "   Просмотреть не пройденные занятия" << endl;

		if (key == 5) cout << "-> Поиск записей по фамилии" << endl;
		else  cout << "   Поиск записей по фамилии" << endl;

		if (key == 6) cout << "-> Поиск записей по занятию" << endl;
		else  cout << "   Поиск записей по занятию" << endl;

		if (key == 7) cout << "-> Поиск записей по ID" << endl;
		else  cout << "   Поиск записей по ID" << endl;

		if (key == 8) cout << "-> Сортировка по фамилии" << endl;
		else cout << "   Сортировка по фамилии" << endl;

		if (key == 9) cout << "-> Сортировка по занятию" << endl;
		else cout << "   Сортировка по занятию" << endl;

		if (key == 10) cout << "-> Сортировка по ID" << endl;
		else cout << "   Сортировка по ID" << endl;

		if (key == 11) cout << "-> Индивидуальное задание" << endl;
		else  cout << "   Индивидуальное задание" << endl;

		if (key == 12) cout << "-> Выход" << endl;
		else  cout << "   Выход" << endl;

		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	return key;
}

bool UserEnter(FILE* f)
{
	string userName;
	int variant;
	cout << "        Вход\n";
	cout << "Введите имя пользователя:" << endl;
	cin >> userName;
	if (Student::UserSearch(userName))
	{
		while (true) {
			vector<Zapis> Zapiss;
			FileManager::LoadOrdersFromFileLIST(Zapiss);
			cout << "        Личный кабинет\n";
			variant = menu_u();
			switch (variant)
			{
			case 0:
				Student::EditClient(userName);
				system("pause");
				break;
			case 1:
				Student::AccountUser(userName);
				system("pause");
				break;
			case 2:
				ViewAllOrders(Zapiss);
				system("pause");
				break;
			case 3:
				ViewFinishedOrders(Zapiss);
				system("pause");
				break;
			case 4:
				ViewFailedOrders(Zapiss);
				system("pause");
				break;
			case 5:
				SearchByFIO(Zapiss);
				system("pause");
				break;
			case 6:
				SearchByLesson(Zapiss);
				system("pause");
				break;
			case 7:
				SearchByID(Zapiss);
				system("pause");
				break;
			case 8:
				sortirovkaFIO(Zapiss);
				system("pause");
				break;
			case 9:
				sortirovkaLesson(Zapiss);
				system("pause");
				break;
			case 10:
				sortirovkaID(Zapiss);
				system("pause");
				break;
			case 11:
				CreateNewOrder(Zapiss);
				FileManager::SaveOrdersToFileLIST(Zapiss);
				system("pause");
				break;
			case 12:
				FileManager::SaveOrdersToFileLIST(Zapiss);
				return 0;
			}
		}
	}
}



int menu_a()
{
	int key = 0;
	int code;
	do {
		system("cls");
		key = (key + 19) % 19;
		cout << "------------------------------------WELCOME-----------------------------------------" << endl;
		if (key == 0) cout << "-> Просмотр личных данных" << endl;
		else  cout << "   Просмотр личных данных" << endl;

		if (key == 1) cout << "-> Редактирование личных данных" << endl;
		else  cout << "   Редактирование личных данных" << endl;

		if (key == 2) cout << "-> Отметить прохождение задания" << endl;
		else  cout << "   Отметить прохождение задания" << endl;

		if (key == 3) cout << "-> Вывод информации о всех пользователях" << endl;
		else  cout << "   Вывод информации о всех пользователях" << endl;

		if (key == 4) cout << "-> Удаление информации о всех пользователях" << endl;
		else  cout << "   Удаление информации о всех пользователях" << endl;

		if (key == 5) cout << "-> Удаление информации о конкретном пользователе" << endl;
		else  cout << "   Удаление информации о конкретном пользователе" << endl;

		if (key == 6) cout << "-> Просмотреть расписание" << endl;
		else  cout << "   Просмотреть расписание" << endl;

		if (key == 7) cout << "-> Просмотреть пройденные занятия (рейтинг)" << endl;
		else  cout << "   Просмотреть пройденные занятия (рейтинг)" << endl;

		if (key == 8) cout << "-> Просмотреть не пройденные занятия" << endl;
		else  cout << "   Просмотреть не пройденные занятия" << endl;

		if (key == 9) cout << "-> Поиск записей по фамилии" << endl;
		else  cout << "   Поиск записей по фамилии" << endl;

		if (key == 10) cout << "-> Поиск записей по занятию" << endl;
		else  cout << "   Поиск записей по занятию" << endl;

		if (key == 11) cout << "-> Поиск записей по ID" << endl;
		else  cout << "   Поиск записей по ID" << endl;

		if (key == 12) cout << "-> Сортировка по фамилии" << endl;
		else cout << "   Сортировка по фамилии" << endl;

		if (key == 13) cout << "-> Сортировка по занятию" << endl;
		else cout << "   Сортировка по занятию" << endl;

		if (key == 14) cout << "-> Сортировка по ID" << endl;
		else cout << "   Сортировка по ID" << endl;

		if (key == 15) cout << "-> Редактировать запись" << endl;
		else cout << "   Редактировать запись" << endl;

		if (key == 16) cout << "-> Удалить запись" << endl;
		else cout << "   Удалить запись" << endl;

		if (key == 17) cout << "-> Индивидуальное задание" << endl;
		else  cout << "   Индивидуальное задание" << endl;

		/*if (key == 18) cout << "-> Список преподавателей" << endl;
		else  cout << "    Список преподавателей" << endl;*/

		if (key == 18) cout << "-> Выход" << endl;
		else  cout << "   Выход" << endl;

		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	return key;
}

bool AdminEnter(FILE* f)
{
	string adminName, userName;
	int variant;
	cout << "        Вход\n";
	cout << "Введите имя администратора:" << endl;
	cin >> adminName;
	if (Admin::AdminSearch(adminName))
	{
		while (true) {
			cout << "        Личный кабинет\n";
			vector<Zapis> Zapiss;
			FileManager::LoadOrdersFromFileLIST(Zapiss);
			variant = menu_a();
			switch (variant)
			{
			case 0:
				Admin::AccountAdmin(adminName);
				system("pause");
				break;
			case 1:
				Admin::EditAdmin(adminName);
				system("pause");
				break;
			case 2:
				ViewAllOrders(Zapiss);
				MarkCompleted(Zapiss);
				FileManager::SaveOrdersToFileLIST(Zapiss);
				system("pause");
				break;
			case 3:
				Student::AllUsersView();
				system("pause");
				break;
			case 4:
				Admin::DeleteUsers();
				system("pause");
				break;
			case 5:
				cout << "Введите имя пользователя для удаления: ";
				cin >> userName;
				Admin::DeleteUser(userName);
				system("pause");
				break;
			case 6:
				ViewAllOrders(Zapiss);
				system("pause");
				break;
			case 7:
				ViewFinishedOrders(Zapiss);
				system("pause");
				break;
			case 8:
				ViewFailedOrders(Zapiss);
				system("pause");
				break;
			case 9:
				SearchByFIO(Zapiss);
				system("pause");
				break;
			case 10:
				SearchByLesson(Zapiss);
				system("pause");
				break;
			case 11:
				SearchByID(Zapiss);
				system("pause");
				break;
			case 12:
				sortirovkaFIO(Zapiss);
				system("pause");
				break;
			case 13:
				sortirovkaLesson(Zapiss);
				system("pause");
				break;
			case 14:
				sortirovkaID(Zapiss);
				system("pause");
				break;
			case 15:
				EditZapis(Zapiss);
				FileManager::SaveOrdersToFileLIST(Zapiss);
				system("pause");
				break;
			case 16:
				deleteZapisBy(Zapiss);
				ViewAllOrders(Zapiss);
				FileManager::SaveOrdersToFileLIST(Zapiss);
				system("pause");
				break;
			case 17:
				SearchByLessonAndDate(Zapiss);
				system("pause");
				break;
			/*case 18:
				Teacher::AllTeachersView();
				system("pause");
				break;
				*/
			case 18:
				exit(0);
			}
		}
	}
}

int menu_t()
{
	int key = 0;
	int code;
	do {
		system("cls");
		key = (key + 19) % 19;
		cout << "------------------------------------WELCOME-----------------------------------------" << endl;
		if (key == 0) cout << "-> Просмотр личных данных" << endl;
		else  cout << "   Просмотр личных данных" << endl;

		if (key == 1) cout << "-> Редактирование личных данных" << endl;
		else  cout << "   Редактирование личных данных" << endl;

		if (key == 2) cout << "-> Отметить прохождение задания" << endl;
		else  cout << "   Отметить прохождение задания" << endl;

		if (key == 3) cout << "-> Вывод информации о всех пользователях" << endl;
		else  cout << "   Вывод информации о всех пользователях" << endl;

		if (key == 4) cout << "-> Просмотреть расписание" << endl;
		else  cout << "   Просмотреть расписание" << endl;

		if (key == 5) cout << "-> Просмотреть пройденные занятия (рейтинг)" << endl;
		else  cout << "   Просмотреть пройденные занятия (рейтинг)" << endl;

		if (key == 6) cout << "-> Просмотреть не пройденные занятия" << endl;
		else  cout << "   Просмотреть не пройденные занятия" << endl;

		if (key == 7) cout << "-> Поиск записей по фамилии" << endl;
		else  cout << "   Поиск записей по фамилии" << endl;

		if (key == 8) cout << "-> Поиск записей по занятию" << endl;
		else  cout << "   Поиск записей по занятию" << endl;

		if (key == 9) cout << "-> Поиск записей по ID" << endl;
		else  cout << "   Поиск записей по ID" << endl;

		if (key == 10) cout << "-> Сортировка по фамилии" << endl;
		else cout << "   Сортировка по фамилии" << endl;

		if (key == 11) cout << "-> Сортировка по занятию" << endl;
		else cout << "   Сортировка по занятию" << endl;

		if (key == 12) cout << "-> Сортировка по ID" << endl;
		else cout << "   Сортировка по ID" << endl;

		if (key == 13) cout << "-> Редактировать запись" << endl;
		else cout << "   Редактировать запись" << endl;

		if (key == 14) cout << "-> Удалить запись" << endl;
		else cout << "   Удалить запись" << endl;

		if (key == 15) cout << "-> Выход" << endl;
		else  cout << "   Выход" << endl;

		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	return key;
}

bool TeacherEnter(FILE* f)
{
	string teacherName, userName;
	int variant;
	cout << "        Вход\n";
	cout << "Введите имя преподавателя:" << endl;
	cin >> teacherName;
	if (Teacher::TeacherSearch(teacherName))
	{
		while (true) {
			cout << "        Личный кабинет\n";
			vector<Zapis> Zapiss;
			FileManager::LoadOrdersFromFileLIST(Zapiss);
			variant = menu_t();
			switch (variant)
			{
			case 0:
				Teacher::AccountTeacher(teacherName);
				system("pause");
				break;
			case 1:
				Teacher::EditTeacher(teacherName);
				system("pause");
				break;
			case 2:
				ViewAllOrders(Zapiss);
				MarkCompleted(Zapiss);
				FileManager::SaveOrdersToFileLIST(Zapiss);
				system("pause");
				break;
			case 3:
				Student::AllUsersView();
				system("pause");
				break;
			case 4:
				ViewAllOrders(Zapiss);
				system("pause");
				break;
			case 5:
				ViewFinishedOrders(Zapiss);
				system("pause");
				break;
			case 6:
				ViewFailedOrders(Zapiss);
				system("pause");
				break;
			case 7:
				SearchByFIO(Zapiss);
				system("pause");
				break;
			case 8:
				SearchByLesson(Zapiss);
				system("pause");
				break;
			case 9:
				SearchByID(Zapiss);
				system("pause");
				break;
			case 10:
				sortirovkaFIO(Zapiss);
				system("pause");
				break;
			case 11:
				sortirovkaLesson(Zapiss);
				system("pause");
				break;
			case 12:
				sortirovkaID(Zapiss);
				system("pause");
				break;
			case 13:
				EditZapis(Zapiss);
				FileManager::SaveOrdersToFileLIST(Zapiss);
				system("pause");
				break;
			case 14:
				deleteZapisByFIO(Zapiss);
				ViewAllOrders(Zapiss);
				FileManager::SaveOrdersToFileLIST(Zapiss);
				system("pause");
				break;
			case 15:
				exit(0);
			}
		}

	}
}

int menu() {
	int key = 0;
	int code;
	do {
		system("cls");
		GoToXY(10, 5);
		key = (key + 6) % 6;
		cout << "WELCOME" << endl;

		if (key == 0) cout << "-> Вход пользователя" << endl;
		else  cout << "   Вход пользователя" << endl;

		if (key == 1) cout << "-> Вход администратора" << endl;
		else  cout << "   Вход администратора" << endl;

		if (key == 2) cout << "-> Вход преподавателя" << endl;
		else  cout << "   Вход преподавателя" << endl;

		if (key == 3) cout << "-> Регистрация пользователя" << endl;
		else  cout << "   Регистрация пользователя" << endl;

		if (key == 4) cout << "-> Регистрация администратора" << endl;
		else  cout << "   Регистрация администратора" << endl;

		if (key == 5) cout << "-> Регистрация преподавателя" << endl;
		else  cout << "   Регистрация преподавателя" << endl;

		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	return key;
}

void AddUser()
{
	FILE* f;
	string nameA, password, email, phoneNumber;
	int age, groupNumber = 0;
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
	Student client(groupNumber,nameA, password, phoneNumber, email, age);
	fwrite(&client, sizeof(Student), 1, f);
	cout << "Регистрация нового пользователя прошла успешно!" << endl;
	fclose(f);
}

void AddAdmin()
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

void AddTeacher()
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

int main()
{

	GoToXY(10, 5);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	FILE* f = NULL;
	string password;
	/*clock_t start = clock();
	cout << "Loading Please Wait";
	while ((clock() - start) / (double)CLOCKS_PER_SEC < 5.0)
	{
		Sleep(100);
		std::cout << "." << std::flush;
		Sleep(100);
		std::cout << "." << std::flush;
		Sleep(100);
		std::cout << "." << std::flush;
		Sleep(100);
		std::cout << "\b\b\b   \b\b\b" << std::flush;
	}*/
	int variant = menu();
	Student student;
	student.nameGet();


	switch (variant)
	{
	case 0:
		UserEnter(f);
		break;
	case 1:
		AdminEnter(f);
		break;
	case 2:
		TeacherEnter(f);
		break;
	case 3:
		AddUser();
		break;
	case 4:
		cout << "Введите секретный код: ";

		password = User::PasswordEntering();
		cout << endl;
		if (password == "1111")
		{
			AddAdmin();
		}
		else
		{
			cout << "Введён неверный код!" << endl;
		}
		break;
	case 5:
		cout << "Введите секретный код: ";

		password = User::PasswordEntering();
		cout << endl;
		if (password == "2222")
		{
			AddTeacher();
		}
		else
		{
			cout << "Введён неверный код!" << endl;
		}
		break;
	default:
		cout << "Выход!";
		return 0;
	}
}

