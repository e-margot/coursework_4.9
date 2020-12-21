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
	void getType();

};