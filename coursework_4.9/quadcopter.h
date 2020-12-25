#pragma once
#include "Conveyor.h"
#include "Builder.h"

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
	void setMachine();
	void setType();
	void setIsMil();
	void setWeihht();
	void setSpeed();
	void setControl();
	void setYear();
	void ofile();
	void ifile();
	void Edit(Conveyor* product);
};