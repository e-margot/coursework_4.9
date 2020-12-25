#pragma once
#include "Conveyor.h"
#include "Builder.h"

class quadcopter : public Builder{
private:
	Conveyor* currentBuilder;

public:
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
	void Get();
//	void Get(Conveyor* product);
	void ofile();
	void ifile();
	void toCurrBuild(Conveyor* product);
};