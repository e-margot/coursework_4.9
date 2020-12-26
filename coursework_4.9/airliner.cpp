#include "airliner.h"

bool airliner::isNum(float num) {
	if (num > 0)
		return true;
	else return false;
}
void airliner::setIsMil() {
	currentBuilder->isMilitary = "Гражданский";
}
void airliner::setType() {
	cout << "Тип гражданского аппарата: " << endl;
	cout << ">> ";
	getline(cin, currentBuilder->type);
	system("cls");
}

void airliner::setWeihht() {
	do {
		string tmp;
		cout << "Введите взлетную массу" << endl;
		cout << ">> ";
		getline(cin, tmp);
		currentBuilder->weihht = atoi(tmp.c_str());
		system("cls");
	} while (!isNum(currentBuilder->weihht));
} 

void airliner::setEngine() {
	cout << "Введите тип двигателей" << endl;
	cout << ">> ";
	getline(cin, currentBuilder->engine);
	system("cls");
}

void airliner::setNumEngine() {
	do {
		string tmp;
		cout << "Введите количество двигателей" << endl;
		cout << ">> ";
		getline(cin, tmp);
		currentBuilder->NumEngine = atoi(tmp.c_str());
		system("cls");
	} while (!isNum(currentBuilder->NumEngine));
} //number of engines - количество двигателей

void airliner::setWings() {
	do {
		string tmp;
		cout << "Введите количество крыльев" << endl;
		cout << ">> ";
		getline(cin, tmp);
		currentBuilder->wings = atoi(tmp.c_str());
		system("cls");
	} while (!isNum(currentBuilder->wings));
} 

void airliner::setArrangW() {
	cout << "Введите расположение крыльев" << endl;
	cout << ">> ";
	getline(cin, currentBuilder->arrangW);
	system("cls");
}

void airliner::setChassis() {
	cout << "Введите тип шасси" << endl;
	cout << ">> ";
	getline(cin, currentBuilder->chassis);
	system("cls");
}

void airliner::setSpeed() {
	do {
		string tmp;
		cout << "Введите скорость полета" << endl;
		cout << ">> ";
		getline(cin, tmp);
		currentBuilder->speed = atoi(tmp.c_str());
		system("cls");
	} while (!isNum(currentBuilder->speed));
}

void airliner::setTakeoff() {
	cout << "Введите тип взлета" << endl;
	cout << ">> ";
	getline(cin, currentBuilder->takeoff);
	system("cls");
}

void airliner::setLanding() {
	cout << "Введите тип посадки" << endl;
	cout << ">> ";
	getline(cin, currentBuilder->landing);
	system("cls");
}


void airliner::setControl() {
	cout << "Введите способ управления" << endl;
	cout << ">> ";
	getline(cin, currentBuilder->control);
	system("cls");
}

void airliner::setCrew() {
	do {
		string tmp;
		cout << "Введите экипаж (число челоовек)" << endl;
		cout << ">> ";
		getline(cin, tmp);
		currentBuilder->crew = atoi(tmp.c_str());
		system("cls");
	} while (!isNum(currentBuilder->crew));
}

void airliner::setYear() {
	do {
		string tmp;
		cout << "Введите год производства" << endl;
		cout << ">> ";
		getline(cin, tmp);
		currentBuilder->year = atoi(tmp.c_str());
		system("cls");
	} while ((currentBuilder->year)<1920 || (currentBuilder->year) > 2020);
}

void airliner::ofile() {
	ofstream fout;
	fout.open("airliner.txt", ios_base::app);
	fout << "Тип: " << currentBuilder->isMilitary << endl;
	fout << "Тип гражданского аппарата: " << currentBuilder->type << endl;
	fout << "Взлетная масса: " << currentBuilder->weihht << endl;
	fout << "Тип двигателей: " << currentBuilder->engine << endl;
	fout << "Число двигателей: " << currentBuilder->NumEngine << endl;
	fout << "Количество крыльев: " << currentBuilder->wings << endl;
	fout << "Расположение крыльев: " << currentBuilder->arrangW << endl;
	fout << "Тип шасси: " << currentBuilder->chassis << endl;
	fout << "Скорость полета: " << currentBuilder->speed << endl;
	fout << "По типу взлета: " << currentBuilder->takeoff << endl;
	fout << "По типу посадки: " << currentBuilder->landing << endl;
	fout << "Способ управления: " << currentBuilder->control << endl;
	fout << "Экипаж (число человек): " << currentBuilder->crew << endl;
	fout << "Год производства: " << currentBuilder->year << endl;
	fout.close();
}

void airliner::ifile(vector <Conveyor*>& product) {
	string str;
	ifstream fin;
	currentBuilder = new Conveyor();
	fin.open("airliner.txt", ios::in);
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

		currentBuilder->machine = "Пассажирский";

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
				if (pos = str.find("Тип гражданского аппарата: ") != 0) throw 1;
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
Conveyor* airliner::GetResult()
{
	return currentBuilder;
}
airliner::~airliner()
{
	if (currentBuilder != nullptr)
		delete currentBuilder;
}
void airliner::CreateProduct()
{
	currentBuilder = new Conveyor();
}
airliner::airliner()
{
	currentBuilder = nullptr;
	
}
void airliner::setMachine() {
	currentBuilder->machine = "Пассажирский";
}


void airliner::toCurrBuild(Conveyor* product) {

	currentBuilder->machine = product->machine;
	currentBuilder->type = product->type;
	currentBuilder->isMilitary = product->isMilitary;
	currentBuilder->weihht = product->weihht;
	currentBuilder->engine = product->engine;
	currentBuilder->NumEngine = product->NumEngine;
	currentBuilder->wings = product->wings;
	currentBuilder->arrangW = product->arrangW;
	currentBuilder->chassis = product->chassis;
	currentBuilder->speed = product->speed;
	currentBuilder->takeoff = product->takeoff;
	currentBuilder->landing = product->landing;
	currentBuilder->control = product->control;
	currentBuilder->crew = product->crew;
	currentBuilder->year = product->year;
}

void airliner::Get() {
	cout << "Тип: " << currentBuilder->isMilitary << endl;
	cout << "Тип гражданского аппарата: " << currentBuilder->type << endl;
	cout << "Взлетная масса: " << currentBuilder->weihht << endl;
	cout << "Тип двигателей: " << currentBuilder->engine << endl;
	cout << "Число двигателей: " << currentBuilder->NumEngine << endl;
	cout << "Количество крыльев: " << currentBuilder->wings << endl;
	cout << "Расположение крыльев: " << currentBuilder->arrangW << endl;
	cout << "Тип шасси: " << currentBuilder->chassis << endl;
	cout << "Скорость полета: " << currentBuilder->speed << endl;
	cout << "По типу взлета: " << currentBuilder->takeoff << endl;
	cout << "По типу посадки: " << currentBuilder->landing << endl;
	cout << "Способ управления: " << currentBuilder->control << endl;
	cout << "Экипаж (число человек): " << currentBuilder->crew << endl;
	cout << "Год производства: " << currentBuilder->year << endl;
	cout << "----------------\n";
}
