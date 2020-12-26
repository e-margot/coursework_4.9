#include "quadcopter.h"

bool quadcopter::isNum(float num) {
	if (num > 0)
		return true;
	else return false;
}
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
Conveyor* quadcopter::GetResult() {
	return currentBuilder;
}

// Деструктор
quadcopter::~quadcopter()
{
	if (currentBuilder != nullptr)
		delete currentBuilder;
}

void  quadcopter:: setIsMil() {
	currentBuilder->isMilitary = "";

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
/*void quadcopter::ifile() {
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
}//тип вооружения*/

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
void quadcopter::ifile(vector <Conveyor*>& product) {
	string str;
	ifstream fin;
	currentBuilder = new Conveyor();
	fin.open("airliner.txt", ios::in);

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
