#include "Conveyor.h"
#include "Builder.h"

class helicopter : public Builder {
private:
	Conveyor* currentBuilder;

public:
	helicopter();
	~helicopter();
	void CreateProduct();
	void setMachine();
	void setType();
	void setIsMil();
	void setWeihht();
	void setEngine();
	void setNumEngine();
	void setSpeed();
	void setTakeoff();
	void setLanding();
	void setControl();
	void setCrew();
	void setYear();
	void SetWeapon();
	void ofile();
	void ifile();
	void Get();
	void toCurrBuild(Conveyor* product);
	Conveyor* GetResult();
};