#include "Conveyor.h"
#include "Builder.h"

class helicopter : public Builder {
private:
	Conveyor* currentBuilder;

public:
	helicopter();
	~helicopter();
	void CreateProduct() override;
	void setMachine() override;
	void setType() override;
	void setIsMil() override;
	void setWeihht() override;
	void setEngine() override;
	void setNumEngine() override;
	void setSpeed() override;
	void setTakeoff() override;
	void setLanding() override;
	void setControl() override;
	void setCrew() override;
	void setYear() override;
	void setWeapon() override;
	void ofile() override;
	void Get() override;
	void setWings() override {};
	void setArrangW() override {};
	void setChassis() override {};
	bool isNum(float num) override;
	void ifile(vector<Conveyor*>& product);
	void toCurrBuild(Conveyor* product) override;
	Conveyor* GetResult();


};