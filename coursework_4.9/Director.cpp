#include "Director.h"


void Director::Construct(Builder& builder){
	builder.CreateProduct();
	builder.setMachine();
	builder.setType();
	builder.setIsMil(); //  type of military apparatus - тип военного аппарата
	builder.setWeihht();// takeoff weight - взлетная масса
	builder.setEngine(); //type of engines - тип двигателей
	builder.setNumEngine(); //number of engines - количество двигателей
	builder.setWings(); // number of wings - число крыльев
	builder.setArrangW();//arrangement of wings - расположение крыльев
	builder.setChassis(); // type of chassis - тип шасси
	builder.setSpeed();//flight speed - скорость полета
	builder.setTakeoff();//тип взлета
	builder.setLanding();//тип посадки
	builder.setControl(); //метод управления
	builder.setCrew();//экипаж(число)
	builder.setYear(); //год производства
	builder.setWeapon();//тип вооружения
	//builder.ofile();//тип вооружения
	//builder.ifile();

}
void Director::EditProduct(Conveyor* product, Builder& builder){
	builder.CreateProduct();
	builder.toCurrBuild(product); 
	cout << "Выберите параметр" << endl;
	cout << "1.	военный или гражданский\n2.	тип военного аппарата, тип гражданского аппарата\n3.	взлетная масса\n4.	тип двигателей\n5.	число двигателей\n6.	количество крыльев\n7.	расположение крыльев\n8.	тип шасси\n9.	скорость полета\n10.	по типу взлета\n11.	по типу посадки\n12.	способ управления\n13.	экипаж(число человек)\n14.	год производства\n15.	тип вооружения" << endl;
	int ch = 0;
	cin >> ch;
	switch (ch) {
	case 1:
		builder.setType();
		break;
	case 2:
		builder.setIsMil();
	    break;
	case 3:
		builder.setWeihht();
		break;
	case 4:
		builder.setEngine();
		break;
	case 5:
		builder.setNumEngine(); 
		break;
	case 6:
		builder.setWings();
		break;
	case 7:
		builder.setArrangW();
		break;
	case 8:
		builder.setChassis(); 
		break;
	case 9:
		builder.setSpeed();
		break;
	case 10:
		builder.setTakeoff();
		break;
	case 11:
		builder.setLanding();
		break;
	case 12:
		builder.setControl(); 
		break;
	case 13:
		builder.setCrew();
		break;
	case 14:
		builder.setYear();
		break;
	case 15:
		builder.setWeapon();
		break;
	}
}


void Director::GetProduct(Conveyor * product, Builder & builder) {
	builder.CreateProduct();
	builder.toCurrBuild(product);
	builder.Get();
}

void Director::clrFile() {
	ofstream f_ca, f_quadr, f_h, f_air;
	f_ca.open("combatAircraft.txt", ios_base::trunc);
	f_h.open("helic.txt", ios_base::trunc);
	f_air.open("airliner.txt", ios_base::trunc);
	f_quadr.open("qudro.txt", ios_base::trunc);
	f_ca.close();
	f_h.close();
	f_air.close();
	f_quadr.close();
}

void Director::File(Builder& builder) {
	builder.ofile();
}

int Director::check(Conveyor* product) {
	if (product->machine == "Военный") { return 2; }
	else if (product->machine == "Пассажирский") { return 1; }
	else if (product->machine == "Квадрокоптер") { return 3; }
	else if (product->machine == "Вертолет") { return 4; }
	else return -1;
}

void Director::FileRead(vector <Conveyor*>& product, Builder& builder)
{
	builder.ifile(product);
}
void Director::FileWrite(Conveyor * product, Builder & builder){
	builder.CreateProduct();
	builder.toCurrBuild(product);
	builder.ofile();
}