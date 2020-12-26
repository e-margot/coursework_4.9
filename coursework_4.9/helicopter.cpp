#include "helicopter.h"

bool helicopter::isNum(float num) {
	if (num > 0)
		return true;
	else return false;
}
void helicopter::setMachine() {
	currentBuilder->machine = "Вертолет";
}

helicopter::helicopter()
{
	currentBuilder = nullptr;
}

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
			currentBuilder->isMilitary = "Гражданский";
			break;
		}
		else if (ch == 2) {
			currentBuilder->isMilitary = "Военный";
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

void helicopter::setWeapon() {
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
/*void helicopter::ifile() {
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
}//тип вооружения*/

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

void helicopter::toCurrBuild(Conveyor* product) {
	currentBuilder->machine = product->machine;
	currentBuilder->type = product->type;
	currentBuilder->isMilitary = product->isMilitary;
	currentBuilder->weihht = product->weihht;
	currentBuilder->engine = product->engine;
	currentBuilder->NumEngine = product->NumEngine;
	currentBuilder->speed = product->speed;
	currentBuilder->takeoff = product->takeoff;
	currentBuilder->landing = product->landing;
	currentBuilder->control = product->control;
	currentBuilder->crew = product->crew;
	currentBuilder->year = product->year;
	currentBuilder->weapon = product->weapon;
}

void helicopter::Get() {
	cout << "Тип: " << currentBuilder->type << endl;
	cout << "Тип военного или гражданского аппарата: " << currentBuilder->isMilitary << endl;
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
	cout << "Тип вооружения: " << currentBuilder->weapon << endl;
	cout << "----------------\n";
}

void helicopter::ifile(vector <Conveyor*>& product) {
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
