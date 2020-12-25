#include "quadcopter.h"

quadcopter::quadcopter()
{
	currentBuilder = nullptr;
}

void quadcopter::CreateProduct()
{
	currentBuilder = new Conveyor();
}
void quadcopter::setMachine() {
	currentBuilder->machine = "Квадрокоптер";
}

// Метод, возвращающий продукт для клиента
Conveyor* quadcopter::GetResult()
{
	return currentBuilder;
}

// Деструктор
quadcopter::~quadcopter()
{
	if (currentBuilder != nullptr)
		delete currentBuilder;
}

void quadcopter::setIsMil() {
	currentBuilder->isMilitary = false;

}
void quadcopter::setType() {
	string type;
	cout << "Enter type of plane" << endl;
	cin >> type;
	currentBuilder->type = type;
}//military or civilian - военный или гражданский


void quadcopter::setWeihht() {
	float weihht;
	cout << "Введите взлетную массу" << endl;
	cin >> weihht;
	currentBuilder->weihht = weihht;
} // takeoff weight - взлетная масса


void quadcopter::setSpeed() {
	float speed;
	cout << "Введите скорость полета" << endl;
	cin >> speed;
	currentBuilder->speed = speed;
}//flight speed - скорость полета



void quadcopter::setControl() {
	string control;
	cout << "Введите способ управления" << endl;
	cin >> control;
	currentBuilder->control = control;
} //метод управления


void quadcopter::setYear() {
	int year;
	cout << "Введите год производства" << endl;
	cin >> year;
	currentBuilder->year = year;
} //год производства

void quadcopter::ofile() {
	ofstream fout;
	fout.open("qudro.txt", ios_base::app);
	fout << "Тип: " << currentBuilder->type << endl;
	fout << "Тип гражданского: " << currentBuilder->isMilitary << endl;
	fout << "Вес: " << currentBuilder->weihht << endl;
	fout << "Скорость: " << currentBuilder->speed << endl;
	fout << "Управление: " << currentBuilder->control << endl;
	fout << "Год производства: " << currentBuilder->year << endl;
	fout << "----------------\n";
	fout.close();
}//тип вооружения
void quadcopter::ifile() {
	char line[100][100];
	ifstream fin;
	fin.open("qudro.txt", ios::in);
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
	cout << "Тип: " << currentBuilder->type << endl;
	cout << "Тип гражданского: " << currentBuilder->isMilitary << endl;
	cout << "Вес: " << currentBuilder ->weihht << endl;
	cout << "Скорость: " << currentBuilder->speed << endl;
	cout << "Управление: " << currentBuilder->control << endl;
	cout << "Год производства: " << currentBuilder->year << endl;
	cout << "----------------\n";
}