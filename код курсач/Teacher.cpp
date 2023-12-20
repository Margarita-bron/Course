#include "Teacher.h"

Teacher::Teacher() :User() {}

Teacher::Teacher(string name, string password, string phoneNumber, string email, int age)
	:User(name, password, phoneNumber, email, age) {}

Teacher::Teacher(Teacher& node)
	:User(node) {}

bool Teacher::TeacherSearch(string teacherName)
{
	FILE* f;
	Teacher* teacher;
	bool teacherEnter = false;
	if ((f = fopen("Teacherlist", "rb+")) == NULL)
	{
		cout << "Error" << endl;
		return teacherEnter;
	}
	int amount = _filelength(_fileno(f)) / sizeof(Teacher);
	teacher = new Teacher[amount];
	fread(teacher, sizeof(Teacher), amount, f);
	if (amount > 0)
	{
		for (int i = 0; i < amount; i++)
		{
			if (teacher[i].nameGet() == teacherName)
			{
				cout << "Введите пароль:" << endl;
				string teacherPassword;
				teacherPassword = PasswordEntering();
				cout << endl;
				if (teacher[i].passwordGet() == teacherPassword)
				{
					cout << "Вход выполнен успешно!" << endl;
					teacherEnter = true;
				}
				else
				{
					cout << "Введён неверный пароль!" << endl;
					fclose(f);
					return teacherEnter;
				}
				break;
			}
			else cout << "Преподавателя с таким именем не существует!" << endl;
		}
		if (!teacherEnter)
		{
			cout << "Преподавателя с таким именем не существует!" << endl;
		}
	}
	else
	{
		cout << "Преподавателя с таким именем не существует!" << endl;
	}
	fclose(f);
	return teacherEnter;
}


void Teacher::AccountTeacher(string teacherName)
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
	cout << "Личные данные: " << endl;
	if (amount > 0)
	{
		for (int i = 0; i < amount; i++)
		{
			if (teacher[i].nameGet() == teacherName)
			{
				cout << "Имя: " << teacher[i].nameGet() << endl;
				cout << "Номер телефона: " << teacher[i].phoneNumberGet() << endl;
				//cout << "Email: " << teacher[i].emailGet() << endl;
				cout << "Возраст: " << teacher[i].ageGet() << endl;
				break;
			}
		}
	}
	fclose(f);
}

void Teacher::EditTeacher(string teacherName)
{
	FILE* f;
	Teacher teacher;
	int amount;

	if ((f = fopen("Teacherlist", "rb+")) == NULL) // открываем файл для чтения и записи
	{
		cout << "Error" << endl;
		return;

	}
	amount = _filelength(_fileno(f)) / sizeof(Teacher);
	
	for (int i = 0; i < amount; i++)
	{
		fread(&teacher, sizeof(Teacher), 1, f); // читаем одного пользователя из файла

		if (teacher.nameGet() == teacherName) // находим пользователя по имени
		{
			cout << "Current data: " << endl
				<< "Name: " << teacher.nameGet() << endl
				<< "Phone number: " << teacher.phoneNumberGet() << endl
				<< "Email: " << teacher.emailGet() << endl
				<< "Age: " << teacher.ageGet() << endl;

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
			teacher.nameSet(newName.c_str());
			teacher.phoneNumberSet(newPhoneNumber);
			teacher.emailSet(newEmail);
			teacher.ageSet(newAge);

			// записываем обновленный объект User обратно в файл
			fseek(f, i * sizeof(Teacher), SEEK_SET);
			fwrite(&teacher, sizeof(Teacher), 1, f);

			cout << "Data has been updated!" << endl;

			break;
		}
	}

	fclose(f);
}

/*void Teacher::AllTeachersView()
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