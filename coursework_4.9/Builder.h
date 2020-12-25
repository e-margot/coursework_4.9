#pragma once
#include "Conveyor.h"

class Builder {
public:
	Builder() { };
	virtual ~Builder() {};
	virtual void CreateProduct() {};
	virtual void setMachine() {};
	virtual void setType() {};//military or civilian - военный или гражданский
	virtual void setIsMil() {}; //  type of military apparatus - тип военного аппарата
	virtual void setWeihht() {};// takeoff weight - взлетная масса
	virtual void setEngine() {};  //type of engines - тип двигателей
	virtual void setNumEngine() {}; //number of engines - количество двигателей
	virtual void setWings() {}; // number of wings - число крыльев
	virtual void setArrangW() {};//arrangement of wings - расположение крыльев
	virtual void setChassis() {}; // type of chassis - тип шасси
	virtual void setSpeed() {};//flight speed - скорость полета
	virtual void setTakeoff() {};//тип взлета
	virtual void setLanding() {};//тип посадки
	virtual void setControl() {}; //метод управления
	virtual void setCrew() {};//экипаж(число)
	virtual void setYear() {}; //год производства
	virtual void setWeapon() {};//тип вооружения
	virtual void delType() {};//удаление
	virtual void ofile() {};//вывод в файл
	virtual void ifile(vector <Conveyor*>& product) {};//считывание с файла
	virtual void Get() {};//считывание с файла
	virtual void toCurrBuild(Conveyor* product) {};
	//virtual void Edit(Conveyor* product) {};//записать в новый объет тот объект который мы хотим изменить
	virtual Conveyor* GetResult() { return nullptr; };
};