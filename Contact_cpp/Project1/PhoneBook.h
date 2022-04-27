#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <string.h>
#include <conio.h>
#include <iomanip>
#include <cstdlib>

using namespace std;

class Contact
{

private:
	int number;
	char* FIO;
	char* MobPhone;
	char* HomePhone;
	char* Hobby;
	char* Job;

public:
	Contact();
	Contact(int _number, const char* _fio, const char* _mobphone, const char* _homephone, const char* _hobby, const char* _job);

	//конструктор копирования
	Contact(const Contact& obj);

	//поиск абонента
	void SearchAbon(Contact* p, char const* charsearch, int const countabon);

	//добавление абонента
	void AddAbon(Contact*& p, int* countabon, int* _number);

	//удаление абонента
	void DelAbon(Contact*& p, int* countabon, int* _number);

	//деструктор
	~Contact();

	//печать книги абонентов
	void ShowPhoneBook(Contact* p, int const countabon);
	void SortAbonent(Contact* p, int const countabon); // все сортировки в самой книге
	void SortHobby(Contact* p, int const countabon);
	void SortJob(Contact* p, int const countabon);
	int Getnumber();
	char GetFIO();
	char GetMobPhone();
	char GetHomePhone();
	char GetHobby();
	char GetJob();
};


void gotoxy(int, int);
void ChangeCursorStatus(bool);
void MenuFun1();
void MenuFun2();
void MenuFun3();
void MenuFun4();
void ExitOption();
