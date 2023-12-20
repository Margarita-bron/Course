#include "FileManager.h"

/*string FileManager::ADMINFILE = "Adminslist";
string FileManager::CLIENTFILE = "Userslist";
string FileManager::TEACHERFILE = "Teacherlist";
char* FileManager::LESSONSFILE = "list";*/


void FileManager::SaveOrdersToFileLIST(vector<Zapis>& Zapiss)
{
	FILE* f = fopen("list", "wb");
	if (f == NULL)
	{
		cout << "Ошибка! Невозможно сохранить изменения в файл." << endl;
		return;
	}

	int n = Zapiss.size();
	fwrite(&n, sizeof(int), 1, f);
	fwrite(Zapiss.data(), sizeof(Zapis), n, f);
	fclose(f);
}

void FileManager::LoadOrdersFromFileLIST(vector<Zapis>& Zapiss)
{
	FILE* f = fopen("list", "rb");
	if (f == NULL)
	{
		cout << "Данного файла не существует! Создайте новый файл." << endl;
		return;
	}

	Zapiss.clear();
	int n;
	Zapis order;
	fread(&n, sizeof(int), 1, f);
	Zapis::SetCounter(n);

	for (int i = 0; i < n; i++)
	{
		fread(&order, sizeof(Zapis), 1, f);
		Zapiss.push_back(order);
	}
	fclose(f);
}

void FileManager::Creat(FILE* f, char* name)
{
	if ((f = fopen(name, "wb")) == NULL)
	{
		cout << "Error" << endl;
		return;
	}
	fclose(f);
	return;
}