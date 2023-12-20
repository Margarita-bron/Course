#include "Admin.h"

Admin::Admin() :User() {}

Admin::Admin(string name, string password, string phoneNumber, string email, int age)
	:User(name, password, phoneNumber, email, age) {}

Admin::Admin(Admin& node)
	:User(node) {}


bool Admin::AdminSearch(string adminName)
{
	FILE* f;
	Admin* admin;
	bool adminEnter = false;
	if ((f = fopen("Adminslist", "rb+")) == NULL)
	{
		cout << "Error" << endl;
		return adminEnter;
	}
	int amount = _filelength(_fileno(f)) / sizeof(Admin);
	admin = new Admin[amount];
	fread(admin, sizeof(Admin), amount, f);
	if (amount > 0)
	{
		for (int i = 0; i < amount; i++)
		{
			if (admin[i].nameGet() == adminName)
			{
				cout << "Введите пароль:" << endl;
				string adminPassword;
				adminPassword = PasswordEntering();
				cout << endl;
				if (admin[i].passwordGet() == adminPassword)
				{
					cout << "Вход выполнен успешно!" << endl;
					adminEnter = true;
				}
				else
				{
					cout << "Введён неверный пароль!" << endl;
					fclose(f);
					return adminEnter;
				}
				break;
			}
		}
		if (!adminEnter)
		{
			cout << "Админа с таким именем не существует!" << endl;
		}
	}
	else
	{
		cout << "Админа с таким именем не существует!" << endl;
	}
	fclose(f);
	return adminEnter;
}



void Admin::AccountAdmin(string userName)
{
	FILE* f;
	Admin* admin;
	if ((f = fopen("Adminslist", "rb")) == NULL)
	{
		cout << "Error" << endl;
		return;
	}
	int amount = _filelength(_fileno(f)) / sizeof(Admin);
	admin = new Admin[amount];
	fread(admin, sizeof(Admin), amount, f);
	cout << "Личные данные: " << endl;
	if (amount > 0)
	{
		for (int i = 0; i < amount; i++)
		{
			if (admin[i].nameGet() == userName)
			{
				cout << "Имя: " << admin[i].nameGet() << endl;
				cout << "Номер телефона: " << admin[i].phoneNumberGet() << endl;
				//cout << "Email: " << admin[i].emailGet() << endl;
				cout << "Возраст: " << admin[i].ageGet() << endl;
				break;
			}
		}
	}
	fclose(f);
}

void Admin::EditAdmin(string adminName)
{
	FILE* f;
	Admin admin;
	int amount;

	if ((f = fopen("Adminslist", "rb+")) == NULL) // открываем файл для чтения и записи
	{
		cout << "Error" << endl;
		return;
	}

	amount = _filelength(_fileno(f)) / sizeof(Admin);

	for (int i = 0; i < amount; i++)
	{
		fread(&admin, sizeof(Admin), 1, f); // читаем одного пользователя из файла

		if (admin.nameGet() == adminName) // находим пользователя по имени
		{
			cout << "Current data: " << endl
				<< "Name: " << admin.nameGet() << endl
				<< "Phone number: " << admin.phoneNumberGet() << endl
				<< "Email: " << admin.emailGet() << endl
				<< "Age: " << admin.ageGet() << endl;

			cout << "Enter new data: " << endl;

			// запрашиваем у пользователя новые данные и записываем их в соответствующие поля объекта User
			string newName, newPhoneNumber;
			int newAge;

			string pusht;
			getline(cin, pusht);

			cout << "New name: ";
			getline(cin, newName);

			cout << "New phone number: ";
			getline(cin, newPhoneNumber);

			while (!isValidPhoneNumber(newPhoneNumber)) {
				cout << "Телефон введен некорректно." << endl;
				getline(cin, newPhoneNumber);
			}

			string newEmail;
			cout << "New email: ";
			getline(cin, newEmail);

			while (!isValidEmail(newEmail)) {
				cout << "Email введен корректно." << endl;
				getline(cin, newEmail);
			}


			cout << "New age: ";
			while (!(cin >> newAge) || (cin.peek() != '\n') || (newAge < 17 || newAge>99))
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "Введите корректный возраст (от 17 ло 99)" << endl;
			}

			// используем setter-функции, чтобы обновить поля объекта User
			admin.nameSet(newName.c_str());
			admin.phoneNumberSet(newPhoneNumber);
			admin.emailSet(newEmail);
			admin.ageSet(newAge);

			// записываем обновленный объект User обратно в файл
			fseek(f, i * sizeof(Admin), SEEK_SET);
			fwrite(&admin, sizeof(Admin), 1, f);

			cout << "Data has been updated!" << endl;

			break;
		}
	}

	fclose(f);
}

void Admin::DeleteUsers()
{
	FILE* f;
	User client;
	if ((f = fopen("Userslist", "rb+")) == NULL)
	{
		cout << "Error" << endl;
		return;
	}
	int amount = _filelength(_fileno(f)) / sizeof(User);
	if (_chsize(_fileno(f), 0) == -1)
	{
		cout << "Error" << endl;
	}
	fclose(f);
}

void Admin::DeleteUser(string userName)
{
	FILE* f;
	User* client;
	User client2;
	User temp;
	if ((f = fopen("Userslist", "rb+")) == NULL)
	{
		cout << "Error" << endl;
		return;
	}
	int amount = _filelength(_fileno(f)) / sizeof(User);
	client = new User[amount];
	fread(client, sizeof(User), amount, f);

	for (int i = 0; i < amount; i++)
	{
		if (client[i].nameGet() == userName)
		{
			for (int j = i; j < amount - 1; j++)
			{
				client[j] = client[j + 1];
			}
			break;
		}
	}
	fclose(f);
	if ((f = fopen("Userslist", "wb")) == NULL)
	{
		cout << "Error" << endl;
		return;
	}
	fwrite(client, sizeof(User), amount - 1, f);

	fclose(f);
}
/*
void Admin::AllTeachersView()
{
	FILE* f;
	Teacher* teacher;
	if ((f = fopen("Teacherlist", "rb")) == NULL)
	{
		cout << "Error" << endl;
		return;
	}
	int amount = _filelength(_fileno(f)) / sizeof(Teacher);
	teacher = new Teacher[amount];
	fread(teacher, sizeof(Teacher), amount, f);
	if (amount > 0)
	{
		cout << "    Преподаватели: " << endl;
		for (int i = 0; i < amount; i++)
		{
			fread(&teacher, sizeof(Teacher), 1, f);
			cout << "Имя: " << teacher[i].nameGet() << endl
				<< "Номер телефона: " << teacher[i].phoneNumberGet() << endl
				//<< "Email: " << teacher[i].emailGet() << endl
				<< "Возраст: " << teacher[i].ageGet() << endl << endl;
		}
	}
	else
	{
		cout << "There is no users!" << endl;
	}
	fclose(f);
}*/