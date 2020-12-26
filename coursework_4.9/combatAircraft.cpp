#include "combatAircraft.h"
#include "combatAircraft.h"


bool combatAircraft:: isNum(float num) {
	if (num > 0)
		return true;
	else return false;
}
void combatAircraft::setIsMil() {
	currentBuilder->isMilitary = "Военный";
}
void combatAircraft::setType() {
	cout << "Тип военного аппарата" << endl;
	cout << ">> ";
	getline(cin, currentBuilder->type);
	system("cls");
}
void combatAircraft::setWeihht() {
	do {
		string tmp;
		cout << "Введите взлетную массу" << endl;
		cout << ">> ";
		getline(cin, tmp);
		currentBuilder->weihht = atoi(tmp.c_str());
		system("cls");
	} while (!isNum(currentBuilder->weihht));
}

void combatAircraft::setEngine() {
	cout << "Введите тип двигателей" << endl;
	cout << ">> ";
	getline(cin, currentBuilder->engine);
	system("cls");
}

void combatAircraft::setNumEngine() {
	do {
		string tmp;
		cout << "Введите количество двигателей" << endl;
		cout << ">> ";
		getline(cin, tmp);
		currentBuilder->NumEngine = atoi(tmp.c_str());
		system("cls");
	} while (!isNum(currentBuilder->NumEngine));
} 

void combatAircraft::setWings() {
	do {
		string tmp;
		cout << "Введите количество крыльев" << endl;
		cout << ">> ";
		getline(cin, tmp);
		currentBuilder->wings = atoi(tmp.c_str());
		system("cls");
	} while (!isNum(currentBuilder->wings));
}

void combatAircraft::setArrangW() {
	cout << "Введите расположение крыльев" << endl;
	cout << ">> ";
	getline(cin, currentBuilder->arrangW);
	system("cls");
}

void combatAircraft::setChassis() {
	cout << "Введите тип шасси" << endl;
	cout << ">> ";
	getline(cin, currentBuilder->chassis);
	system("cls");
}

void combatAircraft::setSpeed() {
	do {
		string tmp;
		cout << "Введите скорость полета" << endl;
		cout << ">> ";
		getline(cin, tmp);
		currentBuilder->speed = atoi(tmp.c_str());
		system("cls");
	} while (!isNum(currentBuilder->speed));
}

void combatAircraft::setTakeoff() {
	cout << "Введите тип взлета" << endl;
	cout << ">> ";
	getline(cin, currentBuilder->takeoff);
	system("cls");
}

void combatAircraft::setLanding() {
	cout << "Введите тип посадки" << endl;
	cout << ">> ";
	getline(cin, currentBuilder->landing);
	system("cls");
}


void combatAircraft::setControl() {
	cout << "Введите способ управления" << endl;
	cout << ">> ";
	getline(cin, currentBuilder->control);
	system("cls");
}

void combatAircraft::setCrew() {
	do {
		string tmp;
		cout << "Введите экипаж (число челоовек)" << endl;
		cout << ">> ";
		getline(cin, tmp);
		currentBuilder->crew = atoi(tmp.c_str());
		system("cls");
	} while (!isNum(currentBuilder->crew));
}

void combatAircraft::setYear() {
	do {
		string tmp;
		cout << "Введите год производства" << endl;
		cout << ">> ";
		getline(cin, tmp);
		currentBuilder->year = atoi(tmp.c_str());
		system("cls");
	} while ((currentBuilder->year) < 1920 || (currentBuilder->year) > 2020);
}




void combatAircraft::setWeapon() {
	cout << "Введите тип вооружения" << endl;
	cout << ">> ";
	getline(cin, currentBuilder->weapon);
	system("cls");
}





/*----------------------------------------------*/



void combatAircraft::ofile() {
	ofstream fout;
	fout.open("combatAircraft.txt", ios_base::app);
	fout << "Тип: " << currentBuilder->isMilitary << endl;
	fout << "Тип военного апппарата: " << currentBuilder->type << endl;
	fout << "Взлетная масса: " << currentBuilder->weihht << endl;
	fout << "Тип двигателей: " << currentBuilder->engine << endl;
	fout << "Число двигателей: " << currentBuilder->NumEngine << endl;
	fout << "Количество крыльев:" << currentBuilder->wings << endl;
	fout << "Расположение крыльев: " << currentBuilder->arrangW << endl;
	fout << "Тип шасси: " << currentBuilder->chassis << endl;
	fout << "Скорость полета: " << currentBuilder->speed << endl;
	fout << "По типу взлета: " << currentBuilder->takeoff << endl;
	fout << "По типу посадки: " << currentBuilder->landing << endl;
	fout << "Способ управление: " << currentBuilder->control << endl;
	fout << "Экипаж (число человек): " << currentBuilder->crew << endl;
	fout << "Год производства: " << currentBuilder->year << endl;
	fout << "Тип вооружения: " << currentBuilder->weapon << endl;
	fout.close();
}

void combatAircraft::ifile(vector <Conveyor*>& product) {
	string str;
	ifstream fin;
	currentBuilder = new Conveyor();
	fin.open("combatAircraft.txt", ios::in);
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

		currentBuilder->machine = "Военный";

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
				if (pos = str.find("Тип военного аппарата: ") != 0) throw 1;
				currentBuilder->type = str.substr(27);
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
				if (pos = str.find("Тип двигателей: ") != 0) throw 1;
				currentBuilder->engine = str.substr(16);
			}
			catch (int i) {
				currentBuilder->engine = "-";
			}
			break;
		case 5:
			try {
				if (pos = str.find("Число двигателей: ") != 0) throw 1;

				str = str.substr(18);

				currentBuilder->NumEngine = atoi(str.c_str());
				if (!isNum(currentBuilder->NumEngine))
					throw 1;
			}
			catch (int i) {
				currentBuilder->NumEngine = 0;
			}
			break;
		case 6:
			try {
				if (pos = str.find("Количество крыльев: ") != 0) throw 1;

				str = str.substr(20);

				currentBuilder->wings = atoi(str.c_str());
				if (!isNum(currentBuilder->wings))
					throw 1;

			}
			catch (int i) {
				currentBuilder->wings = 0;
			}
			break;
		case 7:
			try {
				if (pos = str.find("Расположение крыльев: ") != 0) throw 1;
				currentBuilder->arrangW = str.substr(22);
			}
			catch (int i) {
				currentBuilder->arrangW = "-";
			}
			break;
		case 8:
			try {
				if (pos = str.find("Тип шасси: ") != 0) throw 1;

				currentBuilder->chassis = str.substr(11);
			}
			catch (int i) {
				currentBuilder->chassis = "-";
			}
			break;
		case 9:
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
		case 10:
			try {
				if (pos = str.find("По типу взлета: ") != 0) throw 1;

				currentBuilder->takeoff = str.substr(16);
			}
			catch (int i) {
				currentBuilder->takeoff = "-";
			}
			break;
		case 11:
			try {
				if (pos = str.find("По типу посадки: ") != 0) throw 1;

				currentBuilder->landing = str.substr(17);
			}
			catch (int i) {
				currentBuilder->landing = "-";
			}
			break;
		case 12:
			try {
				if (pos = str.find("Способ управления: ") != 0) throw 1;

				currentBuilder->control = str.substr(11);
			}
			catch (int i) {
				currentBuilder->control = "-";
			}
			break;
		case 13:
			try {
				if (pos = str.find("Экипаж (число человек): ") != 0)
					throw 1;

				str = str.substr(24);

				currentBuilder->crew = atoi(str.c_str());
				if (!isNum(currentBuilder->crew))
					throw 1;
			}
			catch (int i) {
				currentBuilder->crew = 0;
			}
			break;
		case 14:
			try {
				if (pos = str.find("Год производства: ") != 0)
					throw 1;

				str = str.substr(18);

				currentBuilder->year = atoi(str.c_str());
				if ((currentBuilder->year) < 1920 || currentBuilder->year > 2020)
					throw 1;
			}
			catch (int i) {
				currentBuilder->year = 2020;
			}
			
			break;
		case 15: 
			try {
				if (pos = str.find("Тип вооружения: ") != 0) throw 1;

				currentBuilder->weapon = str.substr(16);
			}
			catch (int i) {
				currentBuilder->weapon = "-";
			}
			product.push_back(currentBuilder);
			count = 0;
			currentBuilder = new Conveyor();
		default:
			break;
		}
		count++;
	}
	fin.close();
}

combatAircraft::combatAircraft()
{
	currentBuilder = nullptr;
}
void combatAircraft::CreateProduct()
{
	currentBuilder = new Conveyor();
}
Conveyor*combatAircraft::GetResult()
{
	return currentBuilder;
}
combatAircraft::~combatAircraft()
{
	if (currentBuilder != nullptr)
		delete currentBuilder;
}

void combatAircraft::setMachine() {
	currentBuilder->machine = "Военный";
}
void combatAircraft::toCurrBuild(Conveyor* product)
{
	currentBuilder->machine = product->machine;
	currentBuilder->type = product->type;
	currentBuilder->isMilitary = product->isMilitary;
	currentBuilder->weihht = product->weihht;
	currentBuilder->engine = product->engine;
	currentBuilder->NumEngine = product->NumEngine;
	currentBuilder->wings = product->wings;
	currentBuilder->arrangW = product->arrangW;
	currentBuilder->chassis= product->chassis;
	currentBuilder->speed = product->speed;
	currentBuilder->takeoff = product->takeoff;
	currentBuilder->landing = product->landing;
	currentBuilder->control = product->control;
	currentBuilder->crew = product->crew;
	currentBuilder->year = product->year;
	currentBuilder->weapon = product->weapon;
}

void combatAircraft::Get() {
	cout << "Тип: " << currentBuilder->isMilitary << endl;
	cout << "Тип военного апппарата: " << currentBuilder->type << endl;
	cout << "Взлетная масса: " << currentBuilder->weihht << endl;
	cout << "Тип двигателей: " << currentBuilder->engine << endl;
	cout << "Число двигателей: " << currentBuilder->NumEngine << endl;
	cout << "Количество крыльев:" << currentBuilder->wings << endl;
	cout << "Расположение крыльев: " << currentBuilder->arrangW << endl;
	cout << "Тип шасси: " << currentBuilder->chassis << endl;
	cout << "Скорость полета: " << currentBuilder->speed << endl;
	cout << "По типу взлета: " << currentBuilder->takeoff << endl;
	cout << "По типу посадки: " << currentBuilder->landing << endl;
	cout << "Способ управление: " << currentBuilder->control << endl;
	cout << "Экипаж (число человек): " << currentBuilder->crew << endl;
	cout << "Год производства: " << currentBuilder->year << endl;
	cout << "Тип вооружения: " << currentBuilder->weapon << endl;
	cout << "----------------\n";
}

