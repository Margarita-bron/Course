#include "Student.h"

Student::Student() {
	groupName = 0;
	age = 0;
	name = "0";
	password = "0";
	phoneNumber = "0";
	email = "0";
}

Student::Student(int groupName, string name, string password, string phoneNumber, string email, int age) {
	this->groupName = groupName;
	this->age = age;
	this->name = name;
	this->password = password;
	this->phoneNumber = phoneNumber;
	this->email = email;
}
	
Student::Student(Student& node)//����������� �����������
{
	groupName = node.groupName;
	age = node.age;
	name = move(node.name);
	password = move(node.password);
	phoneNumber = move(node.phoneNumber);
	email = move(node.email);
}

int Student::groupNameGet()
{
	return groupName;
}

void Student::groupNameSet(int groupName) { this->groupName = groupName; }



bool Student::UserSearch(string userName)
{
	FILE* f;
	Student* client;
	bool userEnter = false;
	if ((f = fopen("Userslist", "rb+")) == NULL)
	{
		cout << "Error" << endl;
		return userEnter;
	}
	int amount = _filelength(_fileno(f)) / sizeof(Student);
	client = new Student[amount];
	fread(client, sizeof(Student), amount, f);
	if (amount > 0)
	{
		for (int i = 0; i < amount; i++)
		{
			if (client[i].nameGet() == userName)
			{
				cout << "������� ������ ������������:" << endl;
				string userPassword;
				userPassword = PasswordEntering();
				cout << endl;
				if (client[i].passwordGet() == userPassword)
				{
					cout << "���� �������� �������!" << endl;
					userEnter = true;
				}
				else
				{
					cout << "����� �������� ������!" << endl;
					fclose(f);
					return userEnter;
				}
				break;
			}
		}
		if (!userEnter)
		{
			cout << "������������ � ����� ������ �� ����������!" << endl;
		}
	}
	else
	{
		cout << "������������ � ����� ������ �� ����������!" << endl;
	}
	fclose(f);
	return userEnter;
}

void Student::AccountUser(string userName)
{
	FILE* f;
	Student* client;
	if ((f = fopen("Userslist", "rb")) == NULL)
	{
		cout << "Error" << endl;
		return;
	}
	int amount = _filelength(_fileno(f)) / sizeof(Student);
	client = new Student[amount];
	fread(client, sizeof(Student), amount, f);
	cout << "������ ������: " << endl;
	if (amount > 0)
	{
		for (int i = 0; i < amount; i++)
		{
			if (client[i].nameGet() == userName)
			{
				cout << "���: " << client[i].nameGet() << endl;
				cout << "����� ��������: " << client[i].phoneNumberGet() << endl;
				//cout << "Email: " << client[i].emailGet() << endl;
				cout << "�������: " << client[i].ageGet() << endl;
				break;
			}
		}
	}
	fclose(f);
}

void Student::EditClient(string userName)
{
	FILE* f;
	Student client;
	int amount;

	if ((f = fopen("Userslist", "rb+")) == NULL) // ��������� ���� ��� ������ � ������
	{
		cout << "Error" << endl;
		return;
	}

	amount = _filelength(_fileno(f)) / sizeof(Student);

	for (int i = 0; i < amount; i++)
	{
		fread(&client, sizeof(Student), 1, f); // ������ ������ ������������ �� �����

		if (client.nameGet() == userName) // ������� ������������ �� �����
		{
			cout << "Current data: " << endl
				<< "Name: " << client.nameGet() << endl
				<< "Phone number: " << client.phoneNumberGet() << endl
				<< "Email: " << client.emailGet() << endl
				<< "Age: " << client.ageGet() << endl;

			cout << "Enter new data: " << endl;

			// ����������� � ������������ ����� ������ � ���������� �� � ��������������� ���� ������� User
			string newName, newEmail, newPhoneNumber;
			int newAge;

			string pusht;
			getline(cin, pusht);//��������

			cout << "New name: ";
			getline(cin, newName);

			cout << "New phone number: ";

			while (!isValidPhoneNumber(newPhoneNumber)) {
				cout << "������� ������ �����������." << endl;
				getline(cin, newPhoneNumber);
			}

			cout << "New email: ";
			getline(cin, newEmail);

			while (!isValidEmail(newEmail)) {
				cout << "Email ������ �����������." << endl;
				getline(cin, newEmail);
			}

			cout << "New age: ";
			while (!(cin >> newAge) || (cin.peek() != '\n') || (newAge < 17 || newAge>24))
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "����� ���������� ������� (�� 17 �� 24)" << endl;
			} // ������� ����� �����

			// ���������� setter-�������, ����� �������� ���� ������� User
			client.nameSet(newName.c_str());
			client.phoneNumberSet(newPhoneNumber);
			client.emailSet(newEmail);
			client.ageSet(newAge);

			// ���������� ����������� ������ User ������� � ����
			fseek(f, i * sizeof(Student), SEEK_SET);
			fwrite(&client, sizeof(Student), 1, f);

			cout << "Data has been updated!" << endl;

			break;
		}
	}

	fclose(f);
}


void Student::AllUsersView()
{
	FILE* f;
	Student* client;
	if ((f = fopen("Userslist", "rb")) == NULL)
	{
		cout << "Error" << endl;
		return;
	}
	int amount = _filelength(_fileno(f)) / sizeof(Student);
	client = new Student[amount];
	fread(client, sizeof(Student), amount, f);
	if (amount > 0)
	{
		cout << "    ��������: " << endl;
		for (int i = 0; i < amount; i++)
		{
			fread(&client, sizeof(Student), 1, f);
			cout << "���: " << client[i].nameGet() << endl
				<< "����� ��������: " << client[i].phoneNumberGet() << endl
				//<< "Email: " << client[i].emailGet() << endl
				<< "�������: " << client[i].ageGet() << endl << endl;
		}
	}
	else
	{
		cout << "There is no users!" << endl;
	}
	fclose(f);
}