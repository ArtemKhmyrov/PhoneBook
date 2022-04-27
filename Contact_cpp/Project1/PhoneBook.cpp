#include "PhoneBook.h"
#include <vector>

Contact::Contact()
{
	number = 0;
	FIO = new char[3]{ "No" };
	MobPhone = new char[3]{ "No" };
	HomePhone = new char[3]{ "No" };
	Hobby = new char[3]{ "No" };
	Job = new char[3]{ "No" };
}

Contact::Contact(int _number, const char* _fio, const char* _mobphone, const char* _homephone, const char* _hobby, const char* _job)
{
	// strlen = lenght только возвращает ее длину 
	int count_fio, count_mobphone, count_homephone, count_hobby, count_job;
	count_fio = strlen(_fio);
	count_mobphone = strlen(_mobphone);
	count_homephone = strlen(_homephone);
	count_hobby = strlen(_hobby);
	count_job = strlen(_job);

	FIO = new char[count_fio + 1];
	MobPhone = new char[count_mobphone + 1];
	HomePhone = new char[count_homephone + 1];
	Hobby = new char[count_hobby + 1];
	Job = new char[count_job + 1];

	number = _number;
	strcpy(FIO, _fio);
	strcpy(MobPhone, _mobphone);
	strcpy(HomePhone, _homephone);
	strcpy(Hobby, _hobby);
	strcpy(Job, _job);
}

Contact::~Contact() // для удаления 
{
	delete[]FIO;
	delete[]MobPhone;
	delete[]HomePhone;
	delete[]Hobby;
	delete[]Job;
}

void Contact::AddAbon(Contact*& p, int* countabon, int* _number) // добавление 
{
	Contact* temp = new Contact[*countabon + 1];

	char _fio, _mobphone, _homephone, _hobby, _job;

	int numbertmp = *_number;

	for (size_t i = 0; i < *countabon; i++)
	{
		temp[i].number = p[i].number;

		_fio = strlen(p[i].FIO);
		_mobphone = strlen(p[i].MobPhone);
		_homephone = strlen(p[i].HomePhone);
		_hobby = strlen(p[i].Hobby);
		_job = strlen(p[i].Job);

		temp[i].FIO = new char[_fio + 1];
		temp[i].MobPhone = new char[_mobphone + 1];
		temp[i].HomePhone = new char[_homephone + 1];
		temp[i].Hobby = new char[_hobby + 1];
		temp[i].Job = new char[_job + 1];

		strcpy(temp[i].FIO, p[i].FIO);
		strcpy(temp[i].MobPhone, p[i].MobPhone);
		strcpy(temp[i].HomePhone, p[i].HomePhone);
		strcpy(temp[i].Hobby, p[i].Hobby);
		strcpy(temp[i].Job, p[i].Job);
	}


	temp[*countabon].number = numbertmp;

	char buff[800];

	cout << endl;

	cout << "Введите ФИО: ";
	cin.getline(buff, 800);
	_fio = strlen(buff);
	temp[*countabon].FIO = new char[_fio + 1];
	strcpy(temp[*countabon].FIO, buff);

	cout << endl;

	cout << "Введите мобильный номер телефона: ";
	cin.getline(buff, 800);
	_mobphone = strlen(buff);
	temp[*countabon].MobPhone = new char[_mobphone + 1];
	strcpy(temp[*countabon].MobPhone, buff);

	cout << endl;

	cout << "Введите домашний номер телефона: ";
	cin.getline(buff, 800);
	_homephone = strlen(buff);
	temp[*countabon].HomePhone = new char[_homephone + 1];
	strcpy(temp[*countabon].HomePhone, buff);

	cout << endl;

	cout << "Введите хобби: ";
	cin.getline(buff, 800);
	_hobby = strlen(buff);
	temp[*countabon].Hobby = new char[_hobby + 1];
	strcpy(temp[*countabon].Hobby, buff);

	cout << endl;

	cout << "Введите работу: ";
	cin.getline(buff, 800);
	_job = strlen(buff);
	temp[*countabon].Job = new char[_job + 1];
	strcpy(temp[*countabon].Job, buff);

	cout << endl;

	(*countabon)++;
	(*_number)++;

	delete[]p;

	p = temp;

	cout << "Изменения внесены...\n";
	cout << "Нажми любую кнопку для возврата к меню.";
}


void Contact::DelAbon(Contact*& p, int* countabon, int* _number) // удаление абонента 
{
	char _fio, _mobphone, _homephone, _hobby, _job;

	int numbertmp = *_number;

	int p_count = 0;

	//порядковый номер для удаления
	int delnumber;

	//счетчик был ли удален абонент
	int countdel = 0;

	cout << "Введите порядковый номер абонента для удаления: ";
	cin >> delnumber;
	cin.ignore();

	for (size_t i = 0; i < *countabon; i++)
	{
		if (p[i].number == delnumber)
		{
			(*countabon)--;
			countdel++;
		}
	}

	Contact* temp = new Contact[*countabon];

	for (size_t i = 0; i < *countabon; i++)
	{
		if (p[p_count].number == delnumber)
		{
			p_count++;
			i--;
		}

		else if (p[p_count].number != delnumber)
		{
			temp[i].number = p[p_count].number;

			_fio = strlen(p[p_count].FIO);
			_mobphone = strlen(p[p_count].MobPhone);
			_homephone = strlen(p[p_count].HomePhone);
			_hobby = strlen(p[p_count].Hobby);
			_job = strlen(p[p_count].Job);

			temp[i].FIO = new char[_fio + 1];
			temp[i].MobPhone = new char[_mobphone + 1];
			temp[i].HomePhone = new char[_homephone + 1];
			temp[i].Hobby = new char[_hobby + 1];
			temp[i].Job = new char[_job + 1];

			strcpy(temp[i].FIO, p[p_count].FIO);
			strcpy(temp[i].MobPhone, p[p_count].MobPhone);
			strcpy(temp[i].HomePhone, p[p_count].HomePhone);
			strcpy(temp[i].Hobby, p[p_count].Hobby);
			strcpy(temp[i].Job, p[p_count].Job);

			p_count++;
		}
	}

	if (countdel)
	{
		cout << "Изменения внесены...\n";
	}

	delete[]p;
	p = temp;

	if (!countdel)
	{
		cout << "Абонент не найден.\n";
		cout << "Нажми любую кнопку для возврата к меню.";
	}
}

Contact::Contact(const Contact& obj)
{

	FIO = new char[strlen(obj.FIO) + 1];
	MobPhone = new char[strlen(obj.MobPhone) + 1];
	HomePhone = new char[strlen(obj.HomePhone) + 1];
	Hobby = new char[strlen(obj.Hobby) + 1];
	Job = new char[strlen(obj.Job) + 1];

	number = obj.number;
	strcpy(FIO, obj.FIO);
	strcpy(MobPhone, obj.MobPhone);
	strcpy(HomePhone, obj.HomePhone);
	strcpy(Hobby, obj.Hobby);
	strcpy(Job, obj.Job);
}

void Contact::SearchAbon(Contact* p, char const* charsearch, int const countabon)  // поиск абонента по ФИО
{
	int countsearch = 0;

	for (size_t i = 0; i < countabon; i++)
	{
		char* temp = strstr(p[i].FIO, charsearch);

		if (temp)
		{
			countsearch++;

			if (countsearch == 1)
			{
				cout << "По запросу " << '"' << charsearch << '"' << " ныйдены следующие абоненты: " << endl;
			}

			cout << p[i].number << ". " << p[i].FIO << ". " << p[i].MobPhone << ". " << p[i].HomePhone << ". " << p[i].Hobby << ". " << p[i].Job << ". " << endl;
		}
	}

	if (countsearch < 1)
	{
		cout << "Абонентов не найдено" << endl;
		cout << "Нажми любую кнопку для возврата к меню.";
	}
}

struct forsort { // чтоб не запутаться куда что кладется 
	char* name;
	char* hobby;
	char* job;
	int number;
	char* mobphone;
	char* homephone;
};

void Contact::SortAbonent(Contact* p, int const countabon)
{
	vector <forsort> ARR;

	for (size_t i = 0; i < countabon; i++) 
	{
		forsort X;
		X.name = p[i].FIO;
		X.job = p[i].Job;
		X.hobby = p[i].Hobby;
		X.homephone = p[i].HomePhone;
		X.mobphone = p[i].MobPhone;
		X.number = p[i].number;
		ARR.push_back(X);
	}

	for (int i = 0; i < ARR.size(); i++) { 
		for (int j = i + 1; j < ARR.size(); j++)
			if (strcmp(ARR[i].name, ARR[j].name) > 0) {
				forsort tmp = ARR[i];
				ARR[i] = ARR[j];
				ARR[j] = tmp;
			}
	}

	for (size_t i = 0; i < countabon; i++) 
	{
		p[i].number = ARR[i].number;
		p[i].FIO = ARR[i].name;
		p[i].MobPhone = ARR[i].mobphone;
		p[i].HomePhone = ARR[i].homephone;
		p[i].Hobby = ARR[i].hobby;
		p[i].Job = ARR[i].job;
	}
}

void Contact::SortHobby(Contact* p, int const countabon)
{
	vector <forsort> ARR;

	for (size_t i = 0; i < countabon; i++) 
	{
		forsort X;
		X.name = p[i].FIO;
		X.job = p[i].Job;
		X.hobby = p[i].Hobby;
		X.homephone = p[i].HomePhone;
		X.mobphone = p[i].MobPhone;
		X.number = p[i].number;
		ARR.push_back(X);
	}

	for (int i = 0; i < ARR.size(); i++) { // Сортируем вектор
		for (int j = i + 1; j < ARR.size(); j++)
			if (strcmp(ARR[i].hobby, ARR[j].hobby) > 0) {
				forsort tmp = ARR[i];
				ARR[i] = ARR[j];
				ARR[j] = tmp;
			}
	}

	for (size_t i = 0; i < countabon; i++) 
	{
		p[i].number = ARR[i].number;
		p[i].FIO = ARR[i].name;
		p[i].MobPhone = ARR[i].mobphone;
		p[i].HomePhone = ARR[i].homephone;
		p[i].Hobby = ARR[i].hobby;
		p[i].Job = ARR[i].job;
	}
}

void Contact::SortJob(Contact* p, int const countabon)
{
	vector <forsort> ARR;

	for (size_t i = 0; i < countabon; i++) // Выгруз базы в вектор своей структуры
	{
		forsort X;
		X.name = p[i].FIO;
		X.job = p[i].Job;
		X.hobby = p[i].Hobby;
		X.homephone = p[i].HomePhone;
		X.mobphone = p[i].MobPhone;
		X.number = p[i].number;
		ARR.push_back(X);
	}


	for (int i = 0; i < ARR.size(); i++) { // Сортируем вектор
		for (int j = i + 1; j < ARR.size(); j++)
			if (strcmp(ARR[i].job, ARR[j].job) > 0) {
				forsort tmp = ARR[i];
				ARR[i] = ARR[j];
				ARR[j] = tmp;
			}
	}

	for (size_t i = 0; i < countabon; i++) // Напрямую заменяем значение бдшки на отсортированные
	{
		p[i].number = ARR[i].number;
		p[i].FIO = ARR[i].name;
		p[i].MobPhone = ARR[i].mobphone;
		p[i].HomePhone = ARR[i].homephone;
		p[i].Hobby = ARR[i].hobby;
		p[i].Job = ARR[i].job;
	}
}


void Contact::ShowPhoneBook(Contact* p, int const countabon) // Вывод абонента 
{
	//SortAbonent(p, countabon);
	cout << number << ". ";
	cout << "ФИО: " << FIO;
	cout << endl;
	cout << "   Мобильный телефон: " << MobPhone;
	cout << endl;
	cout << "   Домашний телефон: " << HomePhone;
	cout << endl;
	cout << "   Хобби: " << Hobby;
	cout << endl;
	cout << "   Работа: " << Job;
	cout << endl;
	cout << endl;
}

int Contact::Getnumber()
{
	return number;
}

char Contact::GetFIO()
{
	return *FIO;
}

char Contact::GetMobPhone()
{
	return *MobPhone;
}

char Contact::GetHomePhone()
{
	return *HomePhone;
}

char Contact::GetHobby()
{
	return *Hobby;
}

char Contact::GetJob()
{
	return *Job;
}