#include "combatAircraft.h"

void combatAircraft::setIsMil() {
	currentBuilder->isMilitary = true;
}

void combatAircraft::setType() {
	string type;
	cout << "Тип летательного аппарата: " << endl;
	cin >> type;
	currentBuilder->type = type;
}//military or civilian - военный или гражданский

void combatAircraft::setWeihht() {
	float weihht;
	cout << "Введите взлетную массу" << endl;
	cin >> weihht;
	currentBuilder->weihht = weihht;
} // takeoff weight - взлетная масса

void combatAircraft::setEngine() {
	string engine;
	cout << "Введите тип двигателей" << endl;
	cin >> engine;
	currentBuilder->engine = engine;
} //type of engines - тип двигателей

void combatAircraft::setNumEngine() {
	int engine;
	cout << "Введите количество двигателей" << endl;
	cin >> engine;
	currentBuilder->NumEngine = engine;
} //number of engines - количество двигателей

void combatAircraft::setWings() {
	int wings;
	cout << "Введите количество крыльев" << endl;
	cin >> wings;
	currentBuilder->wings = wings;
} // number of wings - число крыльев

void combatAircraft::setArrangW() {
	string arrangW;
	cout << "Введите расположение крыльев" << endl;
	cin >> arrangW;
	currentBuilder->arrangW = arrangW;
}//arrangement of wings - расположение крыльев

void combatAircraft::setChassis() {
	string chassis;
	cout << "Введите тип шасси" << endl;
	cin >> chassis;
	currentBuilder->chassis = chassis;
} // type of chassis - тип шасси

void combatAircraft::setSpeed() {
	float speed;
	cout << "Введите скорость полета" << endl;
	cin >> speed;
	currentBuilder->speed = speed;
}//flight speed - скорость полета

void combatAircraft::setTakeoff() {
	string takeoff;
	cout << "Введите тип взлета" << endl;
	cin >> takeoff;
	currentBuilder->takeoff = takeoff;
}//тип взлета

void combatAircraft::setLanding() {
	string landing;
	cout << "Введите тип посадки" << endl;
	cin >> landing;
	currentBuilder->takeoff = landing;
}//тип посадки


void combatAircraft::setControl() {
	string control;
	cout << "Введите способ управления" << endl;
	cin >> control;
	currentBuilder->control = control;
} //метод управления

void combatAircraft::setCrew() {
	int crew;
	cout << "Введите экипаж (число челоовек)" << endl;
	cin >> crew;
	currentBuilder->crew = crew;
}//экипаж(число)

void combatAircraft::setYear() {
	int year;
	cout << "Введите год производства" << endl;
	cin >> year;
	currentBuilder->year = year;
} //год производства

void combatAircraft::SetWeapon() {
	string weapon;
	cout << "Введите тип вооружения" << endl;
	cin >> weapon;
	currentBuilder->weapon = weapon;
}//тип вооружения

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
}//тип вооружения

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