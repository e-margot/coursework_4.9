#pragma once
#include "Conveyor.h"
#include "Builder.h"

class quadcopter : public Builder
{
private:
	Conveyor* currentBuilder;

public:
	// �����������
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