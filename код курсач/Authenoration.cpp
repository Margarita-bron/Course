#include "Authenoration.h"

int menu_u() {
	int key = 0;
	int code;
	do {
		system("cls");
		key = (key + 13) % 13;
		cout << "------------------------------------WELCOME-----------------------------------------" << endl;

		if (key == 0) cout << "-> �������������� ������ ������" << endl;
		else  cout << "   �������������� ������ ������" << endl;

		if (key == 1) cout << "-> �������� ������ ������" << endl;
		else  cout << "   �������� ������ ������" << endl;

		if (key == 2) cout << "-> ����������� ����������" << endl;
		else  cout << "   ����������� ����������" << endl;

		if (key == 3) cout << "-> ����������� ���������� ������� (�������)" << endl;
		else  cout << "   ����������� ���������� ������� (�������)" << endl;

		if (key == 4) cout << "-> ����������� �� ���������� �������" << endl;
		else  cout << "   ����������� �� ���������� �������" << endl;

		if (key == 5) cout << "-> ����� ������� �� �������" << endl;
		else  cout << "   ����� ������� �� �������" << endl;

		if (key == 6) cout << "-> ����� ������� �� �������" << endl;
		else  cout << "   ����� ������� �� �������" << endl;

		if (key == 7) cout << "-> ����� ������� �� ID" << endl;
		else  cout << "   ����� ������� �� ID" << endl;

		if (key == 8) cout << "-> ���������� �� �������" << endl;
		else cout << "   ���������� �� �������" << endl;

		if (key == 9) cout << "-> ���������� �� �������" << endl;
		else cout << "   ���������� �� �������" << endl;

		if (key == 10) cout << "-> ���������� �� ID" << endl;
		else cout << "   ���������� �� ID" << endl;

		if (key == 11) cout << "-> �������������� �������" << endl;
		else  cout << "   �������������� �������" << endl;

		if (key == 12) cout << "-> �����" << endl;
		else  cout << "   �����" << endl;

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

bool Authenoration::UserEnter(FILE* f)
{
	string userName;
	int variant;
	cout << "        ����\n";
	cout << "������� ��� ������������:" << endl;
	cin >> userName;
	if (User::UserSearch(userName))
	{
		while (true) {
			vector<Zapis> Zapiss;
			LoadOrdersFromFile(Zapiss);
			cout << "        ������ �������\n";
			variant = menu_u();
			switch (variant)
			{
			case 0:
				User::EditClient(userName);
				system("pause");
				break;
			case 1:
				User::AccountUser(userName);
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
				SaveOrdersToFile(Zapiss);
				system("pause");
				break;
			case 12:
				SaveOrdersToFile(Zapiss);
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
		if (key == 0) cout << "-> �������� ������ ������" << endl;
		else  cout << "   �������� ������ ������" << endl;

		if (key == 1) cout << "-> �������������� ������ ������" << endl;
		else  cout << "   �������������� ������ ������" << endl;

		if (key == 2) cout << "-> �������� ����������� �������" << endl;
		else  cout << "   �������� ����������� �������" << endl;

		if (key == 3) cout << "-> ����� ���������� � ���� �������������" << endl;
		else  cout << "   ����� ���������� � ���� �������������" << endl;

		if (key == 4) cout << "-> �������� ���������� � ���� �������������" << endl;
		else  cout << "   �������� ���������� � ���� �������������" << endl;

		if (key == 5) cout << "-> �������� ���������� � ���������� ������������" << endl;
		else  cout << "   �������� ���������� � ���������� ������������" << endl;

		if (key == 6) cout << "-> ����������� ����������" << endl;
		else  cout << "   ����������� ����������" << endl;

		if (key == 7) cout << "-> ����������� ���������� ������� (�������)" << endl;
		else  cout << "   ����������� ���������� ������� (�������)" << endl;

		if (key == 8) cout << "-> ����������� �� ���������� �������" << endl;
		else  cout << "   ����������� �� ���������� �������" << endl;

		if (key == 9) cout << "-> ����� ������� �� �������" << endl;
		else  cout << "   ����� ������� �� �������" << endl;

		if (key == 10) cout << "-> ����� ������� �� �������" << endl;
		else  cout << "   ����� ������� �� �������" << endl;

		if (key == 11) cout << "-> ����� ������� �� ID" << endl;
		else  cout << "   ����� ������� �� ID" << endl;

		if (key == 12) cout << "-> ���������� �� �������" << endl;
		else cout << "   ���������� �� �������" << endl;

		if (key == 13) cout << "-> ���������� �� �������" << endl;
		else cout << "   ���������� �� �������" << endl;

		if (key == 14) cout << "-> ���������� �� ID" << endl;
		else cout << "   ���������� �� ID" << endl;

		if (key == 15) cout << "-> ������������� ������" << endl;
		else cout << "   ������������� ������" << endl;

		if (key == 16) cout << "-> ������� ������" << endl;
		else cout << "   ������� ������" << endl;

		if (key == 17) cout << "-> �������������� �������" << endl;
		else  cout << "   �������������� �������" << endl;

		if (key == 18) cout << "-> �����" << endl;
		else  cout << "   �����" << endl;

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

bool Authenoration::AdminEnter(FILE* f)
{
	string adminName, userName;
	int variant;
	cout << "        ����\n";
	cout << "������� ��� ��������������:" << endl;
	cin >> adminName;
	if (Admin::AdminSearch(adminName))
	{
		while (true) {
			cout << "        ������ �������\n";
			vector<Zapis> Zapiss;
			LoadOrdersFromFile(Zapiss);
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
				SaveOrdersToFile(Zapiss);
				system("pause");
				break;
			case 3:
				User::AllUsersView();
				system("pause");
				break;
			case 4:
				User::DeleteUsers();
				system("pause");
				break;
			case 5:
				cout << "������� ��� ������������ ��� ��������: ";
				cin >> userName;
				User::DeleteUser(userName);
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
				SaveOrdersToFile(Zapiss);
				system("pause");
				break;
			case 16:
				deleteZapisBy(Zapiss);
				ViewAllOrders(Zapiss);
				SaveOrdersToFile(Zapiss);
				system("pause");
				break;
			case 17:
				SearchByLessonAndDate(Zapiss);
				system("pause");
				break;
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
		if (key == 0) cout << "-> �������� ������ ������" << endl;
		else  cout << "   �������� ������ ������" << endl;

		if (key == 1) cout << "-> �������������� ������ ������" << endl;
		else  cout << "   �������������� ������ ������" << endl;

		if (key == 2) cout << "-> �������� ����������� �������" << endl;
		else  cout << "   �������� ����������� �������" << endl;

		if (key == 3) cout << "-> ����� ���������� � ���� �������������" << endl;
		else  cout << "   ����� ���������� � ���� �������������" << endl;

		if (key == 4) cout << "-> ����������� ����������" << endl;
		else  cout << "   ����������� ����������" << endl;

		if (key == 5) cout << "-> ����������� ���������� ������� (�������)" << endl;
		else  cout << "   ����������� ���������� ������� (�������)" << endl;

		if (key == 6) cout << "-> ����������� �� ���������� �������" << endl;
		else  cout << "   ����������� �� ���������� �������" << endl;

		if (key == 7) cout << "-> ����� ������� �� �������" << endl;
		else  cout << "   ����� ������� �� �������" << endl;

		if (key == 8) cout << "-> ����� ������� �� �������" << endl;
		else  cout << "   ����� ������� �� �������" << endl;

		if (key == 9) cout << "-> ����� ������� �� ID" << endl;
		else  cout << "   ����� ������� �� ID" << endl;

		if (key == 10) cout << "-> ���������� �� �������" << endl;
		else cout << "   ���������� �� �������" << endl;

		if (key == 11) cout << "-> ���������� �� �������" << endl;
		else cout << "   ���������� �� �������" << endl;

		if (key == 12) cout << "-> ���������� �� ID" << endl;
		else cout << "   ���������� �� ID" << endl;

		if (key == 13) cout << "-> ������������� ������" << endl;
		else cout << "   ������������� ������" << endl;

		if (key == 14) cout << "-> ������� ������" << endl;
		else cout << "   ������� ������" << endl;

		if (key == 15) cout << "-> �����" << endl;
		else  cout << "   �����" << endl;

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

bool Authenoration::TeacherEnter(FILE* f)
{
	string teacherName, userName;
	int variant;
	cout << "        ����\n";
	cout << "������� ��� �������������:" << endl;
	cin >> teacherName;
	if (Teacher::TeacherSearch(teacherName))
	{
		while (true) {
			cout << "        ������ �������\n";
			vector<Zapis> Zapiss;
			LoadOrdersFromFile(Zapiss);
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
				SaveOrdersToFile(Zapiss);
				system("pause");
				break;
			case 3:
				User::AllUsersView();
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
				SaveOrdersToFile(Zapiss);
				system("pause");
				break;
			case 14:
				deleteZapisByFIO(Zapiss);
				ViewAllOrders(Zapiss);
				SaveOrdersToFile(Zapiss);
				system("pause");
				break;
			case 15:
				exit(0);
			}
		}

	}
}