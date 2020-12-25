#include "helicopter.h"

void helicopter::setMachine() {
	currentBuilder->machine = "Вертолет";
}

helicopter::helicopter()
{
	currentBuilder = nullptr;
}

// Реализация виртуальных методов
void helicopter::CreateProduct()
{
	currentBuilder = new Conveyor();
}

void helicopter::setIsMil() {
	int ch;
	while (true) {
		cout << "Тип:" << endl;
		cout << "1) Гражданский;" << endl;
		cout << "2) Военный;" << endl;
		cin >> ch;
		if (ch == 1) {
			currentBuilder->isMilitary = false;
			break;
		}
		else if (ch == 2) {
			currentBuilder->isMilitary = true;
			break;
		}
		else {
			cout << "Данные введены некорректно" << endl;
		}
	}
}
void helicopter::setType() {
	string type;
	cout << "Enter type of plane" << endl;
	cin >> type;
	currentBuilder->type = type;
}//military or civilian - военный или гражданский


void helicopter::setWeihht() {
	float weihht;
	cout << "Введите взлетную массу" << endl;
	cin >> weihht;
	currentBuilder->weihht = weihht;
} // takeoff weight - взлетная масса

void helicopter::setEngine() {
	string engine;
	cout << "Введите тип двигателей" << endl;
	cin >> engine;
	currentBuilder->engine = engine;
} //type of engines - тип двигателей

void helicopter::setNumEngine() {
	int engine;
	cout << "Введите количество двигателей" << endl;
	cin >> engine;
	currentBuilder->NumEngine = engine;
} //number of engines - количество двигателей

void helicopter::setWings() {
	int wings;
	cout << "Введите количество крыльев" << endl;
	cin >> wings;
	currentBuilder->wings = wings;
} // number of wings - число крыльев

void helicopter::setArrangW() {
	string arrangW;
	cout << "Введите расположение крыльев" << endl;
	cin >> arrangW;
	currentBuilder->arrangW = arrangW;
}//arrangement of wings - расположение крыльев

void helicopter::setChassis() {
	string chassis;
	cout << "Введите тип шасси" << endl;
	cin >> chassis;
	currentBuilder->chassis = chassis;
} // type of chassis - тип шасси

void helicopter::setSpeed() {
	float speed;
	cout << "Введите скорость полета" << endl;
	cin >> speed;
	currentBuilder->speed = speed;
}//flight speed - скорость полета

void helicopter::setTakeoff() {
	string takeoff;
	cout << "Введите тип взлета" << endl;
	cin >> takeoff;
	currentBuilder->takeoff = takeoff;
}//тип взлета

void helicopter::setLanding() {
	string landing;
	cout << "Введите тип посадки" << endl;
	cin >> landing;
	currentBuilder->takeoff = landing;
}//тип посадки


void helicopter::setControl() {
	string control;
	cout << "Введите способ управления" << endl;
	cin >> control;
	currentBuilder->control = control;
} //метод управления

void helicopter::setCrew() {
	int crew;
	cout << "Введите экипаж (число челоовек)" << endl;
	cin >> crew;
	currentBuilder->crew = crew;
}//экипаж(число)

void helicopter::setYear() {
	int year;
	cout << "Введите год производства" << endl;
	cin >> year;
	currentBuilder->year = year;
} //год производства

void helicopter::SetWeapon() {
	string weapon;
	cout << "Введите тип вооружения" << endl;
	cin >> weapon;
	currentBuilder->weapon = weapon;
}//тип вооружения
void helicopter::ofile() {
	ofstream fout;
	fout.open("helic.txt", ios_base::app);
	fout << "Тип: " << currentBuilder->type << endl;
	fout << "Тип военного или гражданского аппарата: " << currentBuilder->isMilitary << endl;
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
	fout << "Тип вооружения: " << currentBuilder->weapon << endl;
	fout << "----------------\n";
	fout.close();
}//тип вооружения
void helicopter::ifile() {
	char line[100][100];
	ifstream fin;
	fin.open("helic.txt", ios::in);
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

Conveyor* helicopter::GetResult()
{
	return currentBuilder;
}
//void helicopter::del() {
//	if (currentBuilder != nullptr)
//		delete currentBuilder;
//	i--;
//}
// Деструктор
helicopter::~helicopter()
{
	if (currentBuilder != nullptr)
		delete currentBuilder;
}

void helicopter::Edit(Conveyor* product) {

	currentBuilder->machine = product->machine;

}