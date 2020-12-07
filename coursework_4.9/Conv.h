#pragma once
#include <string>
/* онвейер сборки летательных аппаратов
Aircraft assembly conveyor*/
/*airliner, combat aircraft, helicopter, quadcopter
пассажирский самолет, боевой самолет, вертолет, квадрокоптер
*/

/*military or civilian, type of military apparatus,
type of civilian apparatus, takeoff weight, type of engines, number of engines, number of wings, 
arrangement of wings, type of chassis, flight speed, 
by type of takeoff and landing, method of control, crew (number of people), 
year of production , type of weapon*/

class Conveyor {
protected:
	string type; //military or civilian - военный или гражданский
	string Mil;//  type of military apparatus - тип военного аппарата
	string Civ; //type of civilian apparatus - тип гражданского аппарата
	float weihht; // takeoff weight - взлетна€ масса
	string engine; //type of engines - тип двигателей
	int engine; //number of engines - количество двигателей
	int wings; // number of wings - число крыльев
	string arrangW; //arrangement of wings - расположение крыльев
	string chassis; // type of chassis - тип шасси
	float speed;//flight speed - скорость полета
	string takeoff;//тип взлета
	string landing;//тип посадки
	string control; //метод управлени€
	int crew; //экипаж(число)
	int year; //год производства
	string weapon; //тип вооружени€
public:
	Conveyor();
	virtual ~Conveyor();
	virtual void set();
	virtual void get();
	virtual void del();
	virtual void edit();
	virtual void ofile();
	virtual void ifile();
};

