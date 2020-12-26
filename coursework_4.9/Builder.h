#pragma once
#include "Conveyor.h"

class Builder {
public:
	Builder() { };
	virtual ~Builder() {};
	virtual void CreateProduct() = 0;
	virtual void setMachine() = 0;
	virtual void setType() = 0;
	virtual void setIsMil() = 0;
	virtual void setWeihht() = 0;
	virtual void setEngine() = 0;
	virtual void setNumEngine() = 0; 
	virtual void setWings() = 0;
	virtual void setArrangW() = 0;
	virtual void setChassis() = 0;
	virtual void setSpeed() = 0;
	virtual void setTakeoff() = 0;
	virtual void setLanding() = 0;
	virtual void setControl() = 0; 
	virtual void setCrew() = 0;
	virtual void setYear() = 0; 
	virtual void setWeapon() = 0;
	virtual void ofile() = 0;
	virtual bool isNum(float num) = 0;
	virtual void ifile(vector <Conveyor*>& product) = 0;
	virtual void Get() = 0;
	virtual void toCurrBuild(Conveyor* product) = 0;
	virtual Conveyor* GetResult() { return nullptr; };
};