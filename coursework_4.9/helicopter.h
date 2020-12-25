#include "Conveyor.h"
#include "Builder.h"

class helicopter : public Builder {
private:
	Conveyor* currentBuilder;

public:
	// Конструктор
	helicopter();
	~helicopter();
	// Реализация виртуальных методов
	void CreateProduct();
	void setMachine();
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
	void Edit(Conveyor* product);
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