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
	cout << "Тип военного аппарата: " << endl;
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
	fout << "Тип: " << currentBuilder->type << endl;
	fout << "Тип военного апппарата: " << currentBuilder->isMilitary << endl;
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
	fout << "----------------\n";
	fout.close();
}

void combatAircraft::ifile() {
	char line[100][100];
	ifstream fin;
	fin.open("combatAircraft.txt", ios::in);
	if (!fin)
	{
		cout << "Файл не открыт\n\n";
		return;
	}
	int count = 0;
	while (fin.getline(line[count], 100)) count++;
	for (int j = 0; j < count; j++)
	{
		cout << line[j] << endl;
	}
	system("pause");
	fin.close();
}//тип вооружения

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
	cout << "Тип: " << currentBuilder->type << endl;
	cout << "Тип военного апппарата: " << currentBuilder->isMilitary << endl;
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

void combatAircraft::ifile(vector <Conveyor*>& product) {
	string str;
	ifstream fin;
	currentBuilder = new Conveyor();
	fin.open("combatAircraft.txt", ios::in);

	if (!fin.is_open())
		throw exception("Файл не удалось открыть!\n");

	if (fin.peek() == EOF)
		throw exception("Фaйл пуст!\n"); //не вызывать искл, а просто выходить
	int count = 1, pos = 0;
	while (fin.peek() != EOF)
	{
		getline(fin, str);

		currentBuilder->machine = "Пассажирский";

		switch (count)
		{
		case 1:
			if (pos = str.find("Тип: ") != 0) throw exception("Пустое значение\n");

			currentBuilder->type = str.substr(5);
			break;
		case 2:
			if (pos = str.find("Тип гражданского аппарата: ") != 0) throw exception("Пустое значение\n");

			currentBuilder->isMilitary = str.substr(27);
			break;
		case 3:
			if (pos = str.find("Взлетная масса: ") != 0)
				throw exception("Пустое значение\n");

			str = str.substr(16);

			currentBuilder->weihht = atoi(str.c_str());
			if (!isNum(currentBuilder->weihht))
				throw exception("Значение не определено\n");
			break;
		case 4:
			if (pos = str.find("Тип двигателей: ") != 0) throw exception("Пустое значение\n");

			currentBuilder->engine = str.substr(16);
			break;
		case 5:
			if (pos = str.find("Число двигателей: ") != 0) throw exception("Пустое значение\n");

			str = str.substr(18);

			currentBuilder->NumEngine = atoi(str.c_str());
			if (!isNum(currentBuilder->NumEngine))
				throw exception("Значение не определено\n");
			break;
		case 6:
			if (pos = str.find("Количество крыльев: ") != 0) throw exception("Пустое значение\n");

			str = str.substr(20);

			currentBuilder->wings = atoi(str.c_str());
			if (!isNum(currentBuilder->wings))
				throw exception("Значение не определено\n");
			break;
		case 7:
			if (pos = str.find("Расположение крыльев: ") != 0) throw exception("Пустое значение\n");

			currentBuilder->arrangW = str.substr(22);
			break;
		case 8:
			if (pos = str.find("Тип шасси: ") != 0) throw exception("Пустое значение\n");

			currentBuilder->chassis = str.substr(11);
			break;
		case 9:
			if (pos = str.find("Скорость полета: ") != 0)
				throw exception("Пустое значение\n");

			str = str.substr(17);

			currentBuilder->speed = atoi(str.c_str());
			if (!isNum(currentBuilder->speed))
				throw exception("Значение не определено\n");
			break;
		case 10:
			if (pos = str.find("По типу взлета: ") != 0) throw exception("Пустое значение\n");

			currentBuilder->takeoff = str.substr(17); //искл

			break;
		case 11:
			if (pos = str.find("По типу посадки: ") != 0) throw exception("Пустое значение\n");

			currentBuilder->landing = str.substr(16);
			break;
		case 12:
			if (pos = str.find("Способ управления: ") != 0) throw exception("Пустое значение\n");

			currentBuilder->control = str.substr(11);
			break;
		case 13:
			if (pos = str.find("Экипаж (число человек): ") != 0)
				throw exception("Пустое значение\n");

			str = str.substr(24);

			currentBuilder->crew = atoi(str.c_str());
			if (!isNum(currentBuilder->crew))
				throw exception("Значение не определено\n");
			break;
		case 14:
			if (pos = str.find("Год производства: ") != 0)
				throw exception("Пустое значение\n");

			str = str.substr(18);

			currentBuilder->year = atoi(str.c_str());
			if ((currentBuilder->year) < 1920 || currentBuilder->year > 2020)
				throw exception("Значение не определено\n");
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