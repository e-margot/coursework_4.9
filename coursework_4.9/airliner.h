#pragma once
#include "Conveyor.h"
#include "Builder.h"

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
	void setMachine();
	void toCurrBuild(Conveyor * product);
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
	void Get();
	Conveyor* GetResult();
	// Деструктор

};