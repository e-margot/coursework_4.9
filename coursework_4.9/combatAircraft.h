#pragma once
#include "Conveyor.h"
#include "Builder.h"

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
	void setWeapon();
	void ofile();
	void ifile();
	void Get();
	bool isNum(float num) override;
	void toCurrBuild(Conveyor* product);
	void ifile(vector<Conveyor*>& product);
};