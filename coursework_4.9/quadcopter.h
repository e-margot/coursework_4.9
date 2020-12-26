#pragma once
#include "Conveyor.h"
#include "Builder.h"

class quadcopter : public Builder{
private:
	Conveyor* currentBuilder;

public:
	quadcopter();
	~quadcopter();
	void CreateProduct() override;
	void setMachine() override;
	void setType() override;
	void setIsMil() override  {};
	void setWeihht() override;
	void setControl() override;
	void setYear() override;
	void Get() override;
	void ofile() override;
	void setEngine() override {};
	void setNumEngine() override {};
	void setWings() override {};
	void setArrangW() override {};
	void setChassis() override {};
	void setSpeed() override;
	void setTakeoff()override {};
	void setLanding() override {};
	void setCrew() override {};
	void setWeapon() override {};
	bool isNum(float num) override;
	void ifile(vector<Conveyor*>& product);
	void toCurrBuild(Conveyor* product) override;
	Conveyor* GetResult();
};