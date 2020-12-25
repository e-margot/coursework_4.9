#include "Conveyor.h"


Conveyor::Conveyor() {
	machine = "";
	isMilitary = false; //Военный или гражданский
	type = ""; //military or civilian - тип военный или гражданский
	weihht = 0; // takeoff weight - взлетная масса
	engine = ""; //type of engines - тип двигателей
	NumEngine = 0; //number of engines - количество двигателей
	wings = 0; // number of wings - число крыльев
	arrangW = ""; //arrangement of wings - расположение крыльев
	chassis = ""; // type of chassis - тип шасси
	speed = 0;//flight speed - скорость полета
	takeoff = "";//тип взлета
	landing = "";//тип посадки
	control = ""; //метод управления
	crew = 0; //экипаж(число)
	year = 0; //год производства
	weapon = ""; //тип вооружения
}
Conveyor::~Conveyor() {

}
string Conveyor::getMashine() {

	return machine;
}

Conveyor::Conveyor(const Conveyor& obj) {


}