#include"PhoneBook.h"

//счетчки количества абонентов в книге
int countabon = 5;

//порядковый номер абонент в кгине
int number = 1;

//Первоначальное заполнение абонентской книги
Contact* p = new Contact[countabon]
{
	{number++, "Алексеев Юрий Игоревич", "89995395848", "273562", "Гитара", "netcracker"},
	{number++, "Березин Иван Сергеевич", "89053885014", "273563", "Машины", "Кафедра Систем в обучении"},
	{number++, "Колесников Иван Сергеевич", "89378631211", "273564", "Стихи", "Кафедра систем в обучении"},
	{number++, "Голощапова Ирина Александровна", "89873168715", "273565", "Таблицы, Стихи", "Neoflex"},
	{number++, "Будаев Илья Ренатович", "89274638201", "230193", "Полежать в кровати", "1C битрикс"}
};

string* MenuItems()
{
	string* item = new string[5];
	item[0] = "Телефонная книга";
	item[1] = "Добавление абонента";
	item[2] = "Удаление абонента";
	item[3] = "Поиск абонента";
	item[4] = "Выход из программы";
	return item;
}

void gotoxy(int xpos, int ypos)  // это для курсора импорт из библиотеки 
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos; scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}

void MenuFun1()
{
	system("cls");
	int sort_var;

	cout << "Телефонная книга" << endl;

	for (size_t i = 0; i < countabon; i++)
	{
		p[i].ShowPhoneBook(p, countabon);

	}

	cout << "          _______________________________________" << endl;
	cout << "         |   Отсортировать по ФИО      -     1   |" << endl;
	cout << "         |---------------------------------------|" << endl;
	cout << "         |   Отсортировать по Хобби    -     2   |" << endl;
	cout << "         |---------------------------------------|" << endl;
	cout << "         |   Отсортировать по Работе   -     3   |" << endl;
	cout << "         |_______________________________________|" << endl << endl;
	

	cout << "Введите номер сортировки и нажмите Enter: ";
	cin >> sort_var;
	cout << endl;

	switch (sort_var) {
	case 1:

		p->SortAbonent(p, countabon);

		for (size_t i = 0; i < countabon; i++)
		{
			p[i].ShowPhoneBook(p, countabon);

		}
		break;

	case 2:

		p->SortHobby(p, countabon);

		for (size_t i = 0; i < countabon; i++)
		{
			p[i].ShowPhoneBook(p, countabon);

		}
		break;

	case 3:

		p->SortJob(p, countabon);

		for (size_t i = 0; i < countabon; i++)
		{
			p[i].ShowPhoneBook(p, countabon);

		}
		break;

		default: 
			system("cls");
			MenuItems();		
			cout << "Вы ввели некорректное значени и сломали программу. Switch-то интовый, перезапускайте теперь";
			break;
			
	}

	_getch();
	cout << endl;
	system("cls");
	cout << endl;
}

void MenuFun2()
{
	system("cls");

	p->AddAbon(p, &countabon, &number);

	_getch();
	cout << endl;
	system("cls");
	cout << endl;
}

void MenuFun3()
{
	system("cls");

	p->DelAbon(p, &countabon, &number);

	_getch();
	cout << endl;
	system("cls");
	cout << endl;
}

void MenuFun4()
{
	system("cls");

	char charsearch[30] = "";

	cout << "Введите Фамилию, имя или отчество абонента: ";
	cin.getline(charsearch, 30);

	p->SearchAbon(p, charsearch, countabon);

	_getch();
	cout << endl;
	system("cls");
	cout << endl;
}

void ExitOption()
{
	delete[]p;
	gotoxy(30, 15);
	cout << "Выход..." << endl;
	_getch();
	cout << endl;
	exit(0);
	cout << endl;
}

void ChangeCursorStatus(bool Visible) // для курсора 
{
	CONSOLE_CURSOR_INFO* c = new CONSOLE_CURSOR_INFO;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	if (Visible)
	{
		c->bVisible = TRUE;
		c->dwSize = 0;
	}
	else
	{
		c->bVisible = FALSE;
		c->dwSize = 1;
	}

	SetConsoleCursorInfo(h, c);
}

