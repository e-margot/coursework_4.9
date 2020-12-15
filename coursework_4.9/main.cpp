#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "windows.h"
using namespace std;
class Conveyor
{
public:
	bool isMilitary; //Военный или гражданский
	string type; //military or civilian - тип военный или гражданский
	float weihht; // takeoff weight - взлетная масса
	string engine; //type of engines - тип двигателей
	int NumEngine; //number of engines - количество двигателей
	int wings; // number of wings - число крыльев
	string arrangW; //arrangement of wings - расположение крыльев
	string chassis; // type of chassis - тип шасси
	float speed;//flight speed - скорость полета
	string takeoff;//тип взлета
	string landing;//тип посадки
	string control; //метод управления
	int crew; //экипаж(число)
	int year; //год производства
	string weapon; //тип вооружения
	Conveyor();
	~Conveyor();
};
Conveyor::Conveyor() {
	isMilitary = false; //Военный или гражданский
	type = ""; //military or civilian - тип военный или гражданский
	weihht = 0; // takeoff weight - взлетная масса
	engine = ""; //type of engines - тип двигателей
	NumEngine = 0; //number of engines - количество двигателей
	wings = 0; // number of wings - число крыльев
	arrangW = ""; //arrangement of wings - расположение крыльев
	chassis = ""; // type of chassis - тип шасси
	speed = 0;//flight speed - скорость полета
	takeoff = "";//тип взлета
	landing = "";//тип посадки
	control = ""; //метод управления
	crew = 0; //экипаж(число)
	year = 0; //год производства
	weapon = ""; //тип вооружения
}
Conveyor::~Conveyor() {

}

class Builder {
public:
	Builder() { };
	virtual ~Builder() {};
	virtual void CreateProduct() {};
	virtual void setType() {};//military or civilian - военный или гражданский
	virtual void setIsMil() {}; //  type of military apparatus - тип военного аппарата
	virtual void setWeihht() {};// takeoff weight - взлетная масса
	virtual void setEngine() {};  //type of engines - тип двигателей
	virtual void setNumEngine() {}; //number of engines - количество двигателей
	virtual void setWings() {}; // number of wings - число крыльев
	virtual void setArrangW() {};//arrangement of wings - расположение крыльев
	virtual void setChassis() {}; // type of chassis - тип шасси
	virtual void setSpeed() {};//flight speed - скорость полета
	virtual void setTakeoff() {};//тип взлета
	virtual void setLanding() {};//тип посадки
	virtual void setControl() {}; //метод управления
	virtual void setCrew() {};//экипаж(число)
	virtual void setYear() {}; //год производства
	virtual void setWeapon() {};//тип вооружения
	virtual void ofile() {};//вывод в файл
	virtual void ifile() {};//считывание с файла
	virtual Conveyor* GetResult() { return nullptr; };
};
class airliner : public Builder
{
private:
	Conveyor* currentBuilder;

public:
	// Конструктор
	airliner();
	~airliner();
	// Реализация виртуальных методов
	void CreateProduct();
	void setType();
	void setIsMil();
	void setWeihht();
	void setEngine();
	void setNumEngine();
	void setWings();
	void setArrangW();
	void setChassis();
	void setSpeed();
	void setTakeoff();
	void setLanding();
	void setControl();
	void setCrew();
	void setYear();
	void ofile();
	void ifile();//тип вооружения
	Conveyor* GetResult();
	// Деструктор

};

void airliner::setIsMil() {
	currentBuilder->isMilitary = false;
}
void airliner::setType() {
	string type;
	cout << "Enter type of plane" << endl;
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
	fout.open("helic.txt", ios_base::app);
	fout << currentBuilder->type << endl;
}//тип вооружения
void airliner::ifile() {}//тип вооружения
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
	cout << "создали самолет №" << endl;
	currentBuilder = new Conveyor();
}
airliner::airliner()
{
	currentBuilder = nullptr;
}


class combatAircraft : public Builder
{
private:
	Conveyor* currentBuilder;

public:
	// Конструктор
	combatAircraft();
	~combatAircraft();
	void CreateProduct();
	Conveyor* GetResult();
	void setType();
	void setIsMil();
	void setWeihht();
	void setEngine();
	void setNumEngine();
	void setWings();
	void setArrangW();
	void setChassis();
	void setSpeed();
	void setTakeoff();
	void setLanding();
	void setControl();
	void setCrew();
	void setYear();
	void SetWeapon();
	void ofile();
	void ifile();

};

void combatAircraft::setIsMil() {
	currentBuilder->isMilitary = true;

}
void combatAircraft::setType() {
	string type;
	cout << "Enter type of plane" << endl;
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
	fout.open("helic.txt", ios_base::app);
	fout << currentBuilder->type << endl;
}//тип вооружения
void combatAircraft::ifile() {}//тип вооружения

combatAircraft::combatAircraft()
{
	currentBuilder = nullptr;
}
void combatAircraft::CreateProduct()
{
	cout << "военный" << endl;
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


class Director
{
public:
	// Метод, конструирующий части
	void Construct(Builder& builder);
};
void Director::Construct(Builder& builder)
{
	// 1. Создать продукт
	builder.CreateProduct();
	builder.setType();
	builder.ofile();
	builder.setType();
	builder.setIsMil(); //  type of military apparatus - тип военного аппарата
	builder.setWeihht();// takeoff weight - взлетная масса
	builder.setEngine(); //type of engines - тип двигателей
	builder.setNumEngine(); //number of engines - количество двигателей
	builder.setWings(); // number of wings - число крыльев
	builder.setArrangW();//arrangement of wings - расположение крыльев
	builder.setChassis(); // type of chassis - тип шасси
	builder.setSpeed();//flight speed - скорость полета
	builder.setTakeoff();//тип взлета
	builder.setLanding();//тип посадки
	builder.setControl(); //метод управления
	builder.setCrew();//экипаж(число)
	builder.setYear(); //год производства
	builder.setWeapon();//тип вооружения
	builder.ofile();//тип вооружения
	builder.ifile();
}


class helicopter : public Builder {
private:
	Conveyor* currentBuilder;

public:
	// Конструктор
	helicopter();
	~helicopter();
	// Реализация виртуальных методов
	void CreateProduct();
	void setType();
	void setIsMil();
	void setWeihht();
	void setEngine();
	void setNumEngine();
	void setWings();
	void setArrangW();
	void setChassis();
	void setSpeed();
	void setTakeoff();
	void setLanding();
	void setControl();
	void setCrew();
	void setYear();
	void SetWeapon();
	void ofile();
	void ifile();
	// Построить часть 1
		//virtual void BuildLopasti(int lopasti)
		//{
		//	cout << "helicopter::currentBuilder->lopasti = " << lopasti << endl;
		//	currentBuilder->lopasti = lopasti;
		//}

		//// Построить часть 2
		//virtual void BuildEngine(int engine)
		//{
		//	cout << "helicopter::currentBuilder->engine = " << engine << endl;
		//	currentBuilder->engine = engine;
		//}

		// Метод, возвращающий продукт для клиента
	virtual Conveyor* GetResult();
	// Деструктор

};

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
	fout << currentBuilder->type << endl;
}//тип вооружения
void helicopter::ifile() {}//тип вооружения

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
class quadcopter : public Builder
{
private:
	Conveyor* currentBuilder;

public:
	// Конструктор
	quadcopter();
	void CreateProduct();
	Conveyor* GetResult();
	~quadcopter();
	void setType();
	void setIsMil();
	void setWeihht();
	void setSpeed();
	void setControl();
	void setYear();
	void ofile();
	void ifile();
};
quadcopter::quadcopter()
{
	currentBuilder = nullptr;
}

void quadcopter::CreateProduct()
{
	cout << "создали квадрик №" << endl;
	currentBuilder = new Conveyor();
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
	fout.open("helic.txt", ios_base::app);
	fout << currentBuilder->type << endl;
}//тип вооружения
void quadcopter::ifile() {}//тип вооружения



int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	int N = 0, choose = 0, i = 0;
	bool loop = true;
	cout << "Enter N" << endl;
	cin >> N;
	// Функция main() в данном случае выступает клиентом
	// 1. Объявить указатель на продукт, который нужно получить
	Conveyor** product = new Conveyor*[N]; //builder
	helicopter Helic; //concrete builder
	quadcopter Quadr;
	airliner Air;
	combatAircraft CA;
	Director D;
	do {
		system("cls");
		cout << "Выберите тип летательного аппарата:" << endl;
		cout << "1) Пассажирский самолет" << endl;
		cout << "2) Военный самолет" << endl;
		cout << "3) Вертолет" << endl;
		cout << "4) Квадрокоптер" << endl;
		cout << "5) Выход" << endl;
		cin >> choose;
		switch (choose) {
		case 1:
			D.Construct(Air); // сконфигурировать
			product[i] = Air.GetResult();
			i++;
			break;
		case 2:
			D.Construct(CA); // сконфигурировать
			product[i] = CA.GetResult();
			i++;
			break;
		case 3:
			D.Construct(Helic); // сконфигурировать
			product[i] = Helic.GetResult();
			i++;
			break;
		case 4:
			D.Construct(Quadr); // сконфигурировать
			product[i] = Quadr.GetResult();
			i++;
			break;
		case 5:
			loop = false;
		default:
			loop = false;
		}
		if (i == N) { //проверка на дурочка
			cout << "Мест нет" << endl;
			loop = false;
		}

	} while (loop);
	system("cls");
	for (int j = 0; j < i; j++) {
		//cout << product[j]->type << endl;
	}
	// 2. Создать конкретный экземпляр класса helicopter и заполнить значениями

	// 3. Создать класс-распорядитель и сконфигурировать его продуктом B
	//Director D;
	//D.Construct(Helic); // сконфигурировать
	//D.Construct(Quadr1); // сконфигурировать
	//D.Construct(Quadr2); // сконфигурировать

	//// 4. После конфигурирования, передать созданный продукт клиенту
	//product[0] = Helic.GetResult();
	//product[1] = Quadr1.GetResult();
	//product[2] = Quadr2.GetResult();

	// 5. Вывести значение продукта для контроля
	/*cout << "product->type = " << product->type << endl;
	cout << "product->engine = " << product->engine << endl;*/
	/*for (int j = 0; j < i; j++)
	{
		delete[] product[j];
	}*/
	delete[] product;

	system("pause");
	return 0;
}