#include "Zapis.h"
#include "FileManager.h"
#include "Input.h"


	char Zapis::GetFIO() {
		return FIO[30];
	}
	void Zapis::Information()
	{
		cout << "|" << setw(10) << id
			<< " |" << setw(10) << Input::MaxLenght(Lesson, 10)
			<< " |" << setw(30) << Input::MaxLenght(FIO, 30)
			<< " |" << setw(10) << lessdate
			<< " |" << setw(8);

		if (solved)
			cout << "Done";
		else
			cout << " ";

		cout << " |" << endl;
	}
	int Zapis::GetId() {
		return id;
	}
	Date Zapis::GetLessDate() {
		return lessdate;
	}
	bool Zapis::GetSolved() {
		return solved;
	}
	void Zapis::Input()
	{
		counter++;
		id = counter;

		cout << "������� ���������� � ����� ������ �� �������: " << endl;
		Input::InputString("�������: ", Lesson, 9);
		Input::InputString("��� ��������: ", FIO, 29);
		cout << "���� �������: ";
		lessdate.Input();

		solved = false;
	}

	void Zapis::MarkSolved() {
		solved = true;
	}

	void Zapis::SetCounter(int value) {
		counter = value;
	}

	void Zapis::PrintLine() {
		cout << "+" << "-----------"
			<< "+" << "-----------"
			<< "+" << "-------------------------------"
			<< "+" << "-----------"
			<< "+" << "---------"
			<< "+" << endl;
	}

	void Zapis::PrintHeader() {
		PrintLine();
		cout << "|" << setw(10) << "id"
			<< " |" << setw(10) << "�������"
			<< " |" << setw(30) << "�������������"
			<< " |" << setw(10) << "����"
			<< " |" << setw(8) << "������"
			<< " |" << endl;
		PrintLine();
	}

int Zapis::Zapis::counter = 0;


void ViewAllOrders(vector<Zapis>& Zapiss)
{
	Zapis::PrintHeader();
	if (Zapiss.size() > 0)
		for (int i = 0; i < Zapiss.size(); i++)
		{
			Zapiss[i].Information();
			Zapis::PrintLine();
		}
	else cout << "������� �� ���������";
}

void CreateNewOrder(vector<Zapis>& Zapiss)
{
	Zapis order;
	order.Input();
	Zapiss.push_back(order);
}

void ViewFinishedOrders(vector<Zapis>& Zapiss)
{
	for (int i = 0; i < Zapiss.size(); i++)
	{
		if (Zapiss[i].GetSolved() == true)
			Zapiss[i].Information();
	}
}

void ViewFailedOrders(vector<Zapis>& Zapiss)
{
	for (int i = 0; i < Zapiss.size(); i++)
	{
		if (Zapiss[i].GetSolved() == false)
			Zapiss[i].Information();
	}

}

void MarkCompleted(vector<Zapis>& Zapiss)
{
	int id = Input::InputInt("������� ����� ������������ �������: ",0,0);
	bool found = false;
	for (int i = 0; i < Zapiss.size(); i++)
	{
		if (Zapiss[i].GetId() == id) {
			Zapiss[i].MarkSolved();
			found = true;
			break;
		}
	}
	if (!found) {
		cout << "������! ����� ������� �� �������!" << endl;
	}
}

// ������� ������ ������� �� �������

vector<Zapis> searchByLesson(const vector<Zapis>& Zapiss, const string& lesson) {
	vector<Zapis> result;
	for (int i = 0; i < Zapiss.size(); i++) {
		if (strcmp(Zapiss[i].Lesson, lesson.c_str()) == 0) {
			result.push_back(Zapiss[i]);
		}
	}
	return result;
}

void SearchByLesson(vector<Zapis>& Zapiss) {
	string searchLesson;
	cout << "������� ������� ��� ������ �������: ";
	cin >> searchLesson;

	vector<Zapis> searchResult = searchByLesson(Zapiss, searchLesson);

	if (searchResult.empty()) {
		cout << "������ � ��������� " << searchLesson << " �� �������." << endl;
		return;
	}

	cout << "���������� ������:\n";
	for (int i = 0; i < searchResult.size(); i++) {
		cout << searchResult[i].FIO << " " << searchResult[i].Lesson << " " << searchResult[i].id << "\n";
	}
}

vector<Zapis> searchByID(const vector<Zapis>& Zapiss, const int& id) {
	vector<Zapis> result;
	for (int i = 0; i < Zapiss.size(); i++) {
		if (Zapiss[i].id == id) {
			result.push_back(Zapiss[i]);
		}
	}
	return result;
}

void SearchByID(vector<Zapis>& Zapiss) {
	int searchID;
	cout << "������� ID ��� ������ �������: ";
	while (!(cin >> searchID) || (cin.peek() != '\n') || (searchID <= 0))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "����� ���������� ID (�����)" << endl;
	}

	vector<Zapis> searchResult = searchByID(Zapiss, searchID);

	if (searchResult.empty()) {
		cout << "������ � ID " << searchID << " �� �������." << endl;
		return;
	}

	cout << "���������� ������:\n";
	for (int i = 0; i < searchResult.size(); i++) {
		cout << searchResult[i].FIO << " " << searchResult[i].Lesson << " " << searchResult[i].id << "\n";
	}
}

int partition0(vector<Zapis>& Zapiss, int low, int high) {
	const char* pivot = Zapiss[high].FIO;
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		if (strcmp(Zapiss[j].FIO, pivot) < 0) {
			i++;
			swap(Zapiss[i], Zapiss[j]);
		}
	}
	swap(Zapiss[i + 1], Zapiss[high]);
	return (i + 1);
}

void Quicksort(vector<Zapis>& Zapiss, int low, int high) {
	if (low < high) {
		int pi = partition0(Zapiss, low, high);
		Quicksort(Zapiss, low, pi - 1);
		Quicksort(Zapiss, pi + 1, high);
	}
}

void sortVectorByFio(vector<Zapis>& Zapiss) {
	const size_t size = Zapiss.size();
	Quicksort(Zapiss, 0, size - 1);
}

void sortirovkaFIO(vector<Zapis>& Zapiss) {
	sortVectorByFio(Zapiss);

	cout << "ID\tLesson\t\tFIO\n";
	cout << "-----------------------------------\n";

	for (const auto& zapis : Zapiss) {
		// ����� ������ ������ � ��������� �������
		cout << zapis.id << "\t" << zapis.Lesson << "\t\t" << zapis.FIO << "\n";
	}
}

int partition(vector<Zapis>& Zapiss, int low, int high) {
	const char* pivot = Zapiss[high].Lesson;
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		int cmpResult = strcmp(Zapiss[j].Lesson, pivot);
		if (cmpResult < 0 || (cmpResult == 0 && Zapiss[j].id < Zapiss[high].id)) {
			i++;
			swap(Zapiss[i], Zapiss[j]);
		}
	}
	swap(Zapiss[i + 1], Zapiss[high]);
	return (i + 1);
}

void quickSort(vector<Zapis>& Zapiss, int low, int high) {
	if (low < high) {
		int pi = partition(Zapiss, low, high);
		quickSort(Zapiss, low, pi - 1);
		quickSort(Zapiss, pi + 1, high);
	}
}

void sortVectorByLesson(vector<Zapis>& Zapiss) {
	const size_t size = Zapiss.size();
	quickSort(Zapiss, 0, size - 1);
}

void sortirovkaLesson(vector<Zapis>& Zapiss) {
	sortVectorByLesson(Zapiss);

	// ����� ���������� �������
	cout << "ID\tLesson\t\tFIO\n";
	cout << "-----------------------------------\n";

	for (const auto& zapis : Zapiss) {
		// ����� ������ ������ � ��������� �������
		cout << zapis.id << "\t" << zapis.Lesson << "\t\t" << zapis.FIO << "\n";
	}
}

int partition1(vector<Zapis>& Zapiss, int low, int high) {
	int pivot = Zapiss[high].id;
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		if (Zapiss[j].id < pivot) {
			i++;
			swap(Zapiss[i], Zapiss[j]);
		}
	}
	swap(Zapiss[i + 1], Zapiss[high]);
	return (i + 1);
}

void QuickSort(vector<Zapis>& Zapiss, int low, int high) {
	if (low < high) {
		int pi = partition1(Zapiss, low, high);
		QuickSort(Zapiss, low, pi - 1);
		QuickSort(Zapiss, pi + 1, high);
	}
}

void sortVectorByID(vector<Zapis>& Zapiss) {
	const size_t size = Zapiss.size();
	QuickSort(Zapiss, 0, size - 1);
}

void sortirovkaID(vector<Zapis>& Zapiss) {
	sortVectorByID(Zapiss);

	cout << "ID\tLesson\t\tFIO\n";
	cout << "-----------------------------------\n";

	for (const auto& zapis : Zapiss) {
		// ����� ������ ������ � ��������� �������
		cout << zapis.id << "\t" << zapis.Lesson << "\t\t" << zapis.FIO << "\n";
	}
}

vector<Zapis> searchBySurname(const vector<Zapis>& Zapiss, const string& surname) {
	vector<Zapis> result;
	for (int i = 0; i < Zapiss.size(); i++) {
		if (strcmp(Zapiss[i].FIO, surname.c_str()) == 0) {
			result.push_back(Zapiss[i]);
		}
	}
	return result;
}

void SearchByFIO(vector<Zapis>& Zapiss) {
	string searchSurname;
	cout << "������� ������� ������������� ��� ������ �������: ";
	cin >> searchSurname;

	vector<Zapis> searchResult = searchBySurname(Zapiss, searchSurname);

	if (searchResult.empty()) {
		cout << "������ � �������� " << searchSurname << " �� �������." << endl;
		return;
	}

	cout << "���������� ������:\n";
	for (int i = 0; i < searchResult.size(); i++) {
		cout << searchResult[i].FIO << " " << searchResult[i].Lesson << " " << searchResult[i].id << "\n";
	}
}

int pathToSearch(int variant)
{
	int key = 0;
	int code;
	do {
		system("cls");
		key = (key + 3) % 3;
		if (key == 0) cout << "-> ����� ������ �� �������" << endl;
		else  cout << "   ����� ������� �� �������" << endl;

		if (key == 1) cout << "-> ����� ������ �� �������" << endl;
		else  cout << "   ����� ������� �� �������" << endl;

		if (key == 2) cout << "-> ����� ������ �� ID" << endl;
		else  cout << "   ����� ������� �� ID" << endl;

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

void EditZapisBySyrname(vector<Zapis>& Zapiss) {
	string searchSurname;
	cout << "������� ������� ��� ������ ������: ";
	cin >> searchSurname;

	vector<Zapis> searchResult = searchBySurname(Zapiss, searchSurname);

	if (searchResult.empty()) {
		cout << "������ � �������� " << searchSurname << " �� �������." << endl;
		return;
	}

	// ����� ����������� ������
	cout << "���������� ������:\n";
	for (int i = 0; i < searchResult.size(); i++) {
		cout << i + 1 << ". " << searchResult[i].FIO << " " << searchResult[i].Lesson << " " << searchResult[i].id << "\n";
	}

	int choice;
	cout << "�������� ����� ������, ������� ����� ���������������: ";
	cin >> choice;

	if (choice < 1 || choice > searchResult.size()) {
		cout << "�������� �����." << endl;
		return;
	}

	// �������������� ��������� ������
	Zapis& editedZapis = searchResult[choice - 1];
	cout << "������� ����� ������" << endl;

	cout << "  �������: ";
	cin >> editedZapis.FIO;

	cout << "  ����: ";
	cin >> editedZapis.Lesson;

	// ������ ��������� � ������
	for (int i = 0; i < Zapiss.size(); i++) {
		if (Zapiss[i].id == editedZapis.id) {
			Zapiss[i] = editedZapis;
			break;
		}
	}

	// ���������� ��������� � ����
	FileManager::SaveOrdersToFileLIST(Zapiss);
}

void EditZapisByLesson(vector<Zapis>& Zapiss) {
	string searchLesson;
	cout << "������� ������� ��� ������ �������: ";
	cin >> searchLesson;

	vector<Zapis> searchResult = searchByLesson(Zapiss, searchLesson);

	if (searchResult.empty()) {
		cout << "������ � ��������� " << searchLesson << " �� �������." << endl;
		return;
	}

	cout << "���������� ������:\n";
	for (int i = 0; i < searchResult.size(); i++) {
		cout << i + 1 << ". " << searchResult[i].FIO << " " << searchResult[i].Lesson << " " << searchResult[i].id << "\n";
	}

	int choice;
	cout << "�������� ����� ������, ������� ����� ���������������: ";
	cin >> choice;

	if (choice < 1 || choice > searchResult.size()) {
		cout << "�������� �����." << endl;
		return;
	}

	// �������������� ��������� ������
	Zapis& editedZapis = searchResult[choice - 1];
	cout << "������� ����� ������" << endl;

	cout << "  �������: ";
	cin >> editedZapis.FIO;

	cout << "  ����: ";
	cin >> editedZapis.Lesson;

	// ������ ��������� � ������
	for (int i = 0; i < Zapiss.size(); i++) {
		if (Zapiss[i].id == editedZapis.id) {
			Zapiss[i] = editedZapis;
			break;
		}
	}

	// ���������� ��������� � ����
	FileManager::SaveOrdersToFileLIST(Zapiss);
}

void EditZapisByID(vector<Zapis>& Zapiss) {
	int searchID;
	cout << "������� ID ��� ������ �������: ";
	while (!(cin >> searchID) || (cin.peek() != '\n') || (searchID <= 0))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "����� ���������� ID (�����)" << endl;
	}

	vector<Zapis> searchResult = searchByID(Zapiss, searchID);

	if (searchResult.empty()) {
		cout << "������ � ID " << searchID << " �� �������." << endl;
		return;
	}

	cout << "���������� ������:\n";
	for (int i = 0; i < searchResult.size(); i++) {
		cout << i + 1 << ". " << searchResult[i].FIO << " " << searchResult[i].Lesson << " " << searchResult[i].id << "\n";
	}
	int choice;
	cout << "�������� ����� ������, ������� ����� ���������������: ";
	cin >> choice;

	if (choice < 1 || choice > searchResult.size()) {
		cout << "�������� �����." << endl;
		return;
	}
	// �������������� ��������� ������
	Zapis& editedZapis = searchResult[0];
	cout << "������� ����� ������" << endl;

	cout << "  �������: ";
	cin >> editedZapis.FIO;

	cout << "  ����: ";
	cin >> editedZapis.Lesson;

	// ������ ��������� � ������
	for (int i = 0; i < Zapiss.size(); i++) {
		if (Zapiss[i].id == editedZapis.id) {
			Zapiss[i] = editedZapis;
			break;
		}
	}

	// ���������� ��������� � ����
	FileManager::SaveOrdersToFileLIST(Zapiss);
}

void EditZapis(vector<Zapis>& Zapiss) {
	int variant;
	variant = pathToSearch(1);
	switch (variant)
	{
	case 0:
		EditZapisBySyrname(Zapiss);
		system("pause");
		break;
	case 1:
		EditZapisByLesson(Zapiss);
		system("pause");
		break;
	case 2:
		EditZapisByID(Zapiss);
		system("pause");
		break;

	default:
		break;
	}
}

void deleteZapis(vector<Zapis>& Zapiss, int index) {
	Zapiss.erase(Zapiss.begin() + index);
}

void deleteZapisByLesson(vector<Zapis>& Zapiss) {
	string searchDate;
	cout << "������� ������� ��� ������ ������: ";
	cin >> searchDate;

	vector<Zapis> searchResult = searchByLesson(Zapiss, searchDate);

	int index = -1;
	for (int i = 0; i < Zapiss.size(); i++) {
		if (strcmp(Zapiss[i].Lesson, searchDate.c_str()) == 0) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		cout << "������ �� �������\n";
	}
	else {
		deleteZapis(Zapiss, index);
		cout << "������ �������\n";
	}
}

void deleteZapisByID(vector<Zapis>& Zapiss) {
	int searchDate;
	cout << "������� ID ��� ������ ������: ";
	cin >> searchDate;

	vector<Zapis> searchResult = searchBySurname(Zapiss, to_string(searchDate));

	int index = -1;
	for (int i = 0; i < Zapiss.size(); i++) {
		if (Zapiss[i].id == searchDate) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		cout << "������ �� �������\n";
	}
	else {
		deleteZapis(Zapiss, index);
		cout << "������ �������\n";
	}
}

void deleteZapisByFIO(vector<Zapis>& Zapiss) {
	string searchDate;
	cout << "������� ������� ������������� ��� ������ ������: ";
	cin >> searchDate;

	vector<Zapis> searchResult = searchBySurname(Zapiss, searchDate);

	int index = -1;
	for (int i = 0; i < Zapiss.size(); i++) {
		if (strcmp(Zapiss[i].FIO, searchDate.c_str()) == 0) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		cout << "������ �� �������\n";
	}
	else {
		deleteZapis(Zapiss, index);
		cout << "������ �������\n";
	}
}

void deleteZapisBy(vector<Zapis>& Zapiss) {
	int variant;
	variant = pathToSearch(0);
	switch (variant)
	{
	case 0:
		deleteZapisByFIO(Zapiss);
		ViewAllOrders(Zapiss);
		FileManager::SaveOrdersToFileLIST(Zapiss);
		system("pause");
		break;
	case 1:
		deleteZapisByLesson(Zapiss);
		ViewAllOrders(Zapiss);
		FileManager::SaveOrdersToFileLIST(Zapiss);
		system("pause");
		break;
	case 2:
		deleteZapisByID(Zapiss);
		ViewAllOrders(Zapiss);
		FileManager::SaveOrdersToFileLIST(Zapiss);
		system("pause");
		break;

	default:
		break;
	}
}

vector<Zapis> searchByLessonAndDate(const vector<Zapis>& Zapiss, const string& lesson, const Date& searchDate)
{
	vector<Zapis> result;
	for (const auto& zapis : Zapiss) {
		if (strcmp(zapis.Lesson, lesson.c_str()) == 0 && zapis.lessdate >= searchDate) {
			result.push_back(zapis);
		}
	}
	return result;
}

void SearchByLessonAndDate(vector<Zapis>& Zapiss) {
	string searchLesson;
	Date searchDate;

	cout << "������� �������� �������: ";
	cin >> searchLesson;
	searchDate.Input();


	vector<Zapis> searchResult = searchByLessonAndDate(Zapiss, searchLesson, searchDate);

	// ����� ����������� ������
	cout << "���������� ������:\n";
	cout << "ID\tLesson\t\tFIO\n";
	cout << "-----------------------------------\n";
	for (const auto& zapis : searchResult) {
		cout << zapis.id << "\t" << zapis.Lesson << "\t\t" << zapis.FIO << "\n";
	}
}

