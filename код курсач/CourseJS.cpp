#include "CourseJS.h"

void CourseJS::LoadOrdersFromFile(vector<Zapis>& Zapiss)
{
	FILE* f = fopen("CourseJS", "rb");
	if (f == NULL)
	{
		cout << "No file Orderslist! You can create a new file" << endl;
		return;
	}

	Zapiss.clear();
	int n;
	CourseJS order;
	fread(&n, sizeof(int), 1, f);
	Zapis::SetCounter(n);

	for (int i = 0; i < n; i++)
	{
		fread(&order, sizeof(CourseJS), 1, f);
		Zapiss.push_back(order);
	}
	fclose(f);
}

void SaveOrdersToFile(vector<Zapis>& Zapiss)
{
	FILE* f = fopen("CourseJS", "wb");
	if (f == NULL)
	{
		cout << "ошибка. невозможно сохранить изменения в файл!" << endl;
		return;
	}

	int n = Zapiss.size();
	fwrite(&n, sizeof(int), 1, f);
	fwrite(Zapiss.data(), sizeof(CourseJS), n, f);
	fclose(f);
}

void CreateNewOrder(vector<Zapis>& Zapiss)
{
	CourseJS order;
	order.Input();
	Zapiss.push_back(order);
}