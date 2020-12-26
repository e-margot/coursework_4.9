#pragma once
#include "Conveyor.h"
#include "Builder.h"

class airliner : public Builder
{
private:
	Conveyor* currentBuilder;
public:
	airliner();
	~airliner();
	void CreateProduct() override;
	void setMachine() override;
	void toCurrBuild(Conveyor * product) override;
	void setType() override;
	void setIsMil() override;
	void setWeihht() override;
	void setEngine() override;
	void setNumEngine() override;
	void setWings() override;
	void setArrangW() override;
	void setChassis() override;
	void setSpeed() override;
	void setTakeoff()override;
	void setLanding() override;
	void setControl() override;
	void setCrew() override;
	void setYear() override;
	void setWeapon() override {};
	void ofile() override;
	void Get() override;
	bool isNum(float num) override;
	void ifile(vector<Conveyor*>& product);
	Conveyor* GetResult();
};