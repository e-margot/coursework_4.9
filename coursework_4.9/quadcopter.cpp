#include "quadcopter.h"


bool quadcopter::isNum(float num) {
	if (num > 0)
		return true;
	else return false;
}
void quadcopter::setMachine() {
	currentBuilder->machine = "Квадрокоптер";
}

void quadcopter::setType() {
	cout << "Тип аппарата" << endl;
	cout << ">> ";
	getline(cin, currentBuilder->type);
	system("cls");
}

void quadcopter::setWeihht() {
	do {
		string tmp;
		cout << "Введите взлетную массу" << endl;
		cout << ">> ";
		getline(cin, tmp);
		currentBuilder->weihht = atoi(tmp.c_str());
		system("cls");
	} while (!isNum(currentBuilder->weihht));
}



void quadcopter::setSpeed() {
	do {
		string tmp;
		cout << "Введите скорость полета" << endl;
		cout << ">> ";
		getline(cin, tmp);
		currentBuilder->speed = atoi(tmp.c_str());
		system("cls");
	} while (!isNum(currentBuilder->speed));
}


void quadcopter::setControl() {
	cout << "Введите способ управления" << endl;
	cout << ">> ";
	getline(cin, currentBuilder->control);
	system("cls");
}



void quadcopter::setYear() {
	do {
		string tmp;
		cout << "Введите год производства" << endl;
		cout << ">> ";
		getline(cin, tmp);
		currentBuilder->year = atoi(tmp.c_str());
		system("cls");
	} while ((currentBuilder->year) < 1920 || (currentBuilder->year) > 2020);
}




/*----------------------------------------------*/

quadcopter::quadcopter()
{
	currentBuilder = nullptr;
}

void quadcopter::CreateProduct()
{
	currentBuilder = new Conveyor();
}

// Метод, возвращающий продукт для клиента
Conveyor* quadcopter::GetResult() {
	return currentBuilder;
}

// Деструктор
quadcopter::~quadcopter()
{
	if (currentBuilder != nullptr)
		delete currentBuilder;
}


void quadcopter::ofile() {
	ofstream fout;
	fout.open("qudro.txt", ios_base::app);
	fout << "Тип: " << currentBuilder->type << endl;
	fout << "Тип аппарата: " << currentBuilder->isMilitary << endl;
	fout << "Взлетная масса: " << currentBuilder->weihht << endl;
	fout << "Скорость полета: " << currentBuilder->speed << endl;
	fout << "Способ управления: " << currentBuilder->control << endl;
	fout << "Год производства: " << currentBuilder->year << endl;
	fout.close();
}

void quadcopter::toCurrBuild(Conveyor* product) {
	currentBuilder->machine = product->machine;
	currentBuilder->type = product->type;
	currentBuilder->isMilitary = product->isMilitary;
	currentBuilder->weihht = product->weihht;
	currentBuilder->speed = product->speed;
	currentBuilder->control = product->control;
	currentBuilder->year = product->year;
}

void quadcopter::Get() {
	cout << "Тип: " << currentBuilder->isMilitary << endl;
	cout << "Тип аппарата: " << currentBuilder->type << endl;
	cout << "Взлетная масса: " << currentBuilder ->weihht << endl;
	cout << "Скорость полета: " << currentBuilder->speed << endl;
	cout << "Способ управления: " << currentBuilder->control << endl;
	cout << "Год производства: " << currentBuilder->year << endl;
	cout << "----------------\n";
}
void quadcopter::ifile(vector <Conveyor*>& product) {
	string str;
	ifstream fin;
	currentBuilder = new Conveyor();
	fin.open("qudro.txt", ios::in);
	try {
		if (!fin.is_open())
			throw 1;

		if (fin.peek() == EOF)
			throw 1;
	}
	catch (int i)
	{
		cout << "Не удалось открыть файл." << endl;
		return;
	}
	int count = 1, pos = 0;
	while (fin.peek() != EOF)
	{
		getline(fin, str);

		currentBuilder->machine = "Квадрокоптер";

		switch (count)
		{
		case 1:
			try {
				if (pos = str.find("Тип: ") != 0) throw 1;
				currentBuilder->isMilitary = str.substr(5);
			}
			catch (int i) {
				currentBuilder->isMilitary = "-";
			}
			break;
		case 2:
			try {
				if (pos = str.find("Тип аппарата: ") != 0) throw 1;
				currentBuilder->type = str.substr(14);
			}
			catch (int i) {
				currentBuilder->type = "-";
			}

			break;
		case 3:
			try {
				if (pos = str.find("Взлетная масса: ") != 0)
					throw 1;
				str = str.substr(16);

				currentBuilder->weihht = atoi(str.c_str());
				if (!isNum(currentBuilder->weihht))
					throw 1;

			}
			catch (int i) {
				currentBuilder->weihht = 0;
			}
			break;
		case 4:
			try {
				if (pos = str.find("Скорость полета: ") != 0)
					throw 1;

				str = str.substr(17);

				currentBuilder->speed = atoi(str.c_str());
				if (!isNum(currentBuilder->speed))
					throw 1;
			}
			catch (int i) {
				currentBuilder->speed = 0;
			}
			break;
		case 5:
			try {
				if (pos = str.find("Способ управления: ") != 0) throw 1;

				currentBuilder->control = str.substr(11);
			}
			catch (int i) {
				currentBuilder->control = "-";
			}
			break;
		case 6:
			try {
				if (pos = str.find("Год производства: ") != 0)
					throw 1;

				str = str.substr(18);

				currentBuilder->year = atoi(str.c_str());
				if ((currentBuilder->year) < 2000 || currentBuilder->year > 2020)
					throw 1;
			}
			catch (int i) {
				currentBuilder->year = 2020;
			}
			product.push_back(currentBuilder);
			count = 0;
			currentBuilder = new Conveyor();
			break;
		default:
			break;
		}
		count++;
	}
	fin.close();
}
