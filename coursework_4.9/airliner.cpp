#include "airliner.h"

void airliner::setIsMil() {
	currentBuilder->isMilitary = false;
}
void airliner::setType() {
	string type;
	cout << "Тип летательного аппарата: " << endl;
	cin >> type;
	currentBuilder->type = type;
}//military or civilian - военный или гражданский

void airliner::setWeihht() {
	float weihht;
	cout << "Введите взлетную массу" << endl;
	cin >> weihht;
	currentBuilder->weihht = weihht;
} // takeoff weight - взлетная масса

void airliner::setEngine() {
	string engine;
	cout << "Введите тип двигателей" << endl;
	cin >> engine;
	currentBuilder->engine = engine;
} //type of engines - тип двигателей

void airliner::setNumEngine() {
	int engine;
	cout << "Введите количество двигателей" << endl;
	cin >> engine;
	currentBuilder->NumEngine = engine;
} //number of engines - количество двигателей

void airliner::setWings() {
	int wings;
	cout << "Введите количество крыльев" << endl;
	cin >> wings;
	currentBuilder->wings = wings;
} // number of wings - число крыльев

void airliner::setArrangW() {
	string arrangW;
	cout << "Введите расположение крыльев" << endl;
	cin >> arrangW;
	currentBuilder->arrangW = arrangW;
}//arrangement of wings - расположение крыльев

void airliner::setChassis() {
	string chassis;
	cout << "Введите тип шасси" << endl;
	cin >> chassis;
	currentBuilder->chassis = chassis;
} // type of chassis - тип шасси

void airliner::setSpeed() {
	float speed;
	cout << "Введите скорость полета" << endl;
	cin >> speed;
	currentBuilder->speed = speed;
}//flight speed - скорость полета

void airliner::setTakeoff() {
	string takeoff;
	cout << "Введите тип взлета" << endl;
	cin >> takeoff;
	currentBuilder->takeoff = takeoff;
}//тип взлета

void airliner::setLanding() {
	string landing;
	cout << "Введите тип посадки" << endl;
	cin >> landing;
	currentBuilder->takeoff = landing;
}//тип посадки


void airliner::setControl() {
	string control;
	cout << "Введите способ управления" << endl;
	cin >> control;
	currentBuilder->control = control;
} //метод управления

void airliner::setCrew() {
	int crew;
	cout << "Введите экипаж (число челоовек)" << endl;
	cin >> crew;
	currentBuilder->crew = crew;
}//экипаж(число)

void airliner::setYear() {
	int year;
	cout << "Введите год производства" << endl;
	cin >> year;
	currentBuilder->year = year;
} //год производства

void airliner::ofile() {
	ofstream fout;
	fout.open("airliner.txt", ios_base::app);
	fout << "Тип: " << currentBuilder->type << endl;
	fout << "Тип гражданского аппарата: " << currentBuilder->isMilitary << endl;
	fout << "Взлетная масса: " << currentBuilder->weihht << endl;
	fout << "Тип двигателей: " << currentBuilder->engine << endl;
	fout << "Число двигателей: " << currentBuilder->NumEngine << endl;
	fout << "Количесвто крыльев: " << currentBuilder->wings << endl;
	fout << "Расположение крыльев: " << currentBuilder->arrangW << endl;
	fout << "Тип шасси: " << currentBuilder->chassis << endl;
	fout << "Скорость полета: " << currentBuilder->speed << endl;
	fout << "По типу взлета: " << currentBuilder->takeoff << endl;
	fout << "По типу посадки: " << currentBuilder->landing << endl;
	fout << "Способ управления: " << currentBuilder->control << endl;
	fout << "Экипаж (число человек): " << currentBuilder->crew << endl;
	fout << "Год производства:" << currentBuilder->year << endl;
	//fout << "----------------\n";
	fout.close();
}

void airliner::ifile(vector <Conveyor*>& product) {
	//char line[100][100]; 
	string str;
	ifstream fin;
	currentBuilder = new Conveyor();
	fin.open("airliner.txt", ios::in);

	if (!fin.is_open())
		throw exception("Файл не удалось открыть!\n");

	if (fin.peek() == EOF)
		throw exception("Фвйл пуст!\n");
	int count = 1, pos = 0;
	while (fin.peek() != EOF) // Read data from file
	{
		getline(fin, str);
		//if (str.empty()) continue;
	
		currentBuilder->machine = "Пассажирский";
		//14 полей   
		switch (count)
		{
		case 1:
			if (pos = str.find("Тип: ") != 0) throw exception("wer\n");
				
			currentBuilder->type = str.substr(5);
			break;
		case 2:
			break;
		case 3:
			if (pos = str.find("Взлетная масса: ") != 0)
				throw exception("\n");

			str = str.substr(6);
			/*if (!num_valid(tmp))
				throw exception("\n");*/

			currentBuilder->weihht = atoi(str.c_str()); // Convert string to integer
			if (currentBuilder->weihht < 0)
				throw exception("qweq\n");
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			break;
		case 11:
			break;
		case 12:
			break;
		case 13:
			break;
		case 14:
			product.push_back(currentBuilder);
			count = 0;
			currentBuilder = new Conveyor();
		default:
			break;
		}
		count++;
	}
	
	/*if (!fin)
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
	system("pause");*/
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
	cout << "Тип: " << currentBuilder->type << endl;
	cout << "Тип гражданского аппарата: " << currentBuilder->isMilitary << endl;
	cout << "Взлетная масса: " << currentBuilder->weihht << endl;
	cout << "Тип двигателей: " << currentBuilder->engine << endl;
	cout << "Число двигателей: " << currentBuilder->NumEngine << endl;
	cout << "Количесвто крыльев: " << currentBuilder->wings << endl;
	cout << "Расположение крыльев: " << currentBuilder->arrangW << endl;
	cout << "Тип шасси: " << currentBuilder->chassis << endl;
	cout << "Скорость полета: " << currentBuilder->speed << endl;
	cout << "По типу взлета: " << currentBuilder->takeoff << endl;
	cout << "По типу посадки: " << currentBuilder->landing << endl;
	cout << "Способ управления: " << currentBuilder->control << endl;
	cout << "Экипаж (число человек): " << currentBuilder->crew << endl;
	cout << "Год производства:" << currentBuilder->year << endl;
	//cout << "----------------\n";
}
