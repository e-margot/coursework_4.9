#include <iostream>
using namespace std;
// Класс, который есть продуктом
class Conveyor
{
public:
	//int lopasti; // часть 1
	//int engine; // часть 2
	string type; //military or civilian - военный или гражданский
	string Mil;//  type of military apparatus - тип военного аппарата
	string Civ; //type of civilian apparatus - тип гражданского аппарата
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
};

// Класс, который реализует интерфейс с клиентом
//определяем сеттеры
class Builder
{
public:
	virtual void CreateProduct() {}
	virtual void setType(string type) {}//military or civilian - военный или гражданский
	virtual void setMil(string Mil) {}//  type of military apparatus - тип военного аппарата
	virtual void setCiv(string Civ) {} //type of civilian apparatus - тип гражданского аппарата
	virtual void setWeihht(float weihht) {} // takeoff weight - взлетная масса
	virtual void setEngine(string engine) {} //type of engines - тип двигателей
	virtual void setEngine(int NumEngine) {} //number of engines - количество двигателей
	virtual void setWings(int wings) {} // number of wings - число крыльев
	virtual void setArrangW(string arrangW) {}//arrangement of wings - расположение крыльев
	virtual void setChassis(string chassis) {} // type of chassis - тип шасси
	virtual void setSpeed(float speed) {}//flight speed - скорость полета
	virtual void setTakeoff(string takeoff) {}//тип взлета
	virtual void setLanding(string landing) {}//тип посадки
	virtual void setControl(string control) {} //метод управления
	virtual void setCrew(int crew) {}//экипаж(число)
	virtual void setYear(int year) {} //год производства
	virtual void SetWeapon(string weapon) {}//тип вооружения
	/*virtual void BuildLopasti(int lopasti) { }
	virtual void BuildEngine(int engine) { }*/
	virtual Conveyor* GetResult() { return nullptr; }
};

// Класс, который есть конкретным строителем
class helicopter : public Builder
{
private:
	Conveyor* currentBuilder;

public:
	// Конструктор
	helicopter()
	{
		currentBuilder = nullptr;
	}

	// Реализация виртуальных методов
	virtual void CreateProduct()
	{
		cout << "helicopter::CreateProduct()" << endl;
		currentBuilder = new Conveyor();
	}
	virtual void setType(string type) {
		currentBuilder->type = type;
	}//military or civilian - военный или гражданский

	virtual void setMil(string Mil) {
		currentBuilder->Mil = Mil;
	}//  type of military apparatus - тип военного аппарата

	virtual void setCiv(string Civ) {
		currentBuilder->Civ = Civ;
	} //type of civilian apparatus - тип гражданского аппарата

	virtual void setWeihht(float weihht) {
		currentBuilder->weihht = weihht;
	} // takeoff weight - взлетная масса

	virtual void setEngine(string engine) {
		currentBuilder->engine = engine;
	} //type of engines - тип двигателей

	virtual void setEngine(int engine) {
		currentBuilder->NumEngine = engine;
	} //number of engines - количество двигателей

	virtual void setWings(int wings) {
		currentBuilder->wings = wings;
	} // number of wings - число крыльев

	virtual void setArrangW(string arrangW) {
		currentBuilder->arrangW = arrangW;
	}//arrangement of wings - расположение крыльев

	virtual void setChassis(string chassis) {
		currentBuilder->chassis = chassis;
	} // type of chassis - тип шасси

	virtual void setSpeed(float speed) {
		currentBuilder->speed = speed;
	}//flight speed - скорость полета

	virtual void setTakeoff(string takeoff) {
		currentBuilder->takeoff = takeoff;
	}//тип взлета

	virtual void setLanding(string landing) {
		currentBuilder->takeoff = landing;
	}//тип посадки

	virtual void setControl(string control) {
		currentBuilder->control = control;
	} //метод управления

	virtual void setCrew(int crew) {
		currentBuilder->crew = crew;
	}//экипаж(число)

	virtual void setYear(int year) {
		currentBuilder->year = year;
	} //год производства

	virtual void SetWeapon(string weapon) {
		currentBuilder->weapon = weapon;

	}//тип вооружения

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
	virtual Conveyor* GetResult()
	{
		return currentBuilder;
	}

	// Деструктор
	~helicopter()
	{
		if (currentBuilder != nullptr)
			delete currentBuilder;
	}
};

class combatAircraft : public Builder
{
private:
	Conveyor* currentBuilder;

public:
	// Конструктор
	combatAircraft()
	{
		currentBuilder = nullptr;
	}

	// Реализация виртуальных методов
	virtual void CreateProduct()
	{
		cout << "helicopter::CreateProduct()" << endl;
		currentBuilder = new Conveyor();
	}

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
	virtual Conveyor* GetResult()
	{
		return currentBuilder;
	}

	// Деструктор
	~combatAircraft()
	{
		if (currentBuilder != nullptr)
			delete currentBuilder;
	}
};

class airliner : public Builder
{
private:
	Conveyor* currentBuilder;

public:
	// Конструктор
	airliner()
	{
		currentBuilder = nullptr;
	}

	// Реализация виртуальных методов
	virtual void CreateProduct()
	{
		cout << "helicopter::CreateProduct()" << endl;
		currentBuilder = new Conveyor();
	}

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
	virtual Conveyor* GetResult()
	{
		return currentBuilder;
	}

	// Деструктор
	~airliner()
	{
		if (currentBuilder != nullptr)
			delete currentBuilder;
	}
};

class quadcopter : public Builder
{
private:
	Conveyor* currentBuilder;

public:
	// Конструктор
	quadcopter()
	{
		currentBuilder = nullptr;
	}

	// Реализация виртуальных методов
	virtual void CreateProduct()
	{
		cout << "helicopter::CreateProduct()" << endl;
		currentBuilder = new Conveyor();
	}



	// Построить часть 2
	//virtual void BuildEngine(int engine)
	//{
	//	cout << "quadcopter::currentBuilder->engine = " << engine << endl;
	//	currentBuilder->engine = engine;
	//}

	// Метод, возвращающий продукт для клиента
	virtual Conveyor* GetResult()
	{
		return currentBuilder;
	}

	// Деструктор
	~quadcopter()
	{
		if (currentBuilder != nullptr)
			delete currentBuilder;
	}
};
// Класс - распорядитель
class Director
{
public:
	// Метод, конструирующий части
	void Construct(Builder& builder)
	{
		// 1. Создать продукт
		builder.CreateProduct();

		//// 2. Построить часть 1
		//builder.BuildLopasti(25);

		//// 3. Построить часть 2
		//builder.BuildEngine(777);
	}
};

int main()
{
	int N = 0;
	cout << "Enter N" << endl;
	cin >> N;
	// Функция main() в данном случае выступает клиентом
	// 1. Объявить указатель на продукт, который нужно получить
	Conveyor** product = new Conveyor*[N]; //builder

	// 2. Создать конкретный экземпляр класса helicopter и заполнить значениями
	helicopter Helic; //concrete builder
	quadcopter Quadr1;
	quadcopter Quadr2;

	// 3. Создать класс-распорядитель и сконфигурировать его продуктом B
	Director D;
	D.Construct(Helic); // сконфигурировать
	D.Construct(Quadr1); // сконфигурировать
	D.Construct(Quadr2); // сконфигурировать

	// 4. После конфигурирования, передать созданный продукт клиенту
	product[0] = Helic.GetResult();
	product[1] = Quadr1.GetResult();
	product[2] = Quadr2.GetResult();

	// 5. Вывести значение продукта для контроля
	/*cout << "product->lopasti = " << product->lopasti << endl;
	cout << "product->engine = " << product->engine << endl;*/
	system("pause");
	return 0;
}