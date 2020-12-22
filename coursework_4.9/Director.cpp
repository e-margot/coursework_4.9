#include "Director.h"


void Director::Construct(Builder& builder)
{
	// 1. Создать продукт
	builder.CreateProduct();
	builder.setType();
	//builder.setIsMil(); //  type of military apparatus - тип военного аппарата
	//builder.setWeihht();// takeoff weight - взлетная масса
	//builder.setEngine(); //type of engines - тип двигателей
	//builder.setNumEngine(); //number of engines - количество двигателей
	//builder.setWings(); // number of wings - число крыльев
	//builder.setArrangW();//arrangement of wings - расположение крыльев
	//builder.setChassis(); // type of chassis - тип шасси
	//builder.setSpeed();//flight speed - скорость полета
	//builder.setTakeoff();//тип взлета
	//builder.setLanding();//тип посадки
	//builder.setControl(); //метод управления
	//builder.setCrew();//экипаж(число)
	//builder.setYear(); //год производства
	//builder.setWeapon();//тип вооружения
	//builder.ofile();//тип вооружения
	//builder.ifile();
}

void Director::Edit(Builder &builder) {
	cout << "Выберите параметр" << endl;
	cout << "1.	военный или гражданский\n2.	тип военного аппарата, тип гражданского аппарата\n3.	взлетная масса\n4.	тип двигателей\n5.	число двигателей\n6.	количество крыльев\n7.	расположение крыльев\n8.	тип шасси\n9.	скорость полета\n10.	по типу взлета\n11.		посадки\n12.	способ управления\n13.	экипаж(число человек)\n14.	год производства\n15.	тип вооружения" << endl;
	int ch = 0;
	cin >> ch;
	switch (ch) {
	case 1:
		builder.setType();
		break;
	case 2:
		builder.setIsMil(); //  type of military apparatus - тип военного аппарата
		break;
	case 3:
		builder.setWeihht();// takeoff weight - взлетная масса
		break;
	case 4:
		builder.setEngine(); //type of engines - тип двигателей
		break;
	case 5:
		builder.setNumEngine(); //number of engines - количество двигателей
		break;
	case 6:
		builder.setWings(); // number of wings - число крыльев
		break;
	case 7:
		builder.setArrangW();//arrangement of wings - расположение крыльев
		break;
	case 8:
		builder.setChassis(); // type of chassis - тип шасси
		break;
	case 9:
		builder.setSpeed();//flight speed - скорость полета
		break;
	case 10:
		builder.setTakeoff();//тип взлета
		break;
	case 11:
		builder.setLanding();//тип посадки
		break;
	case 12:
		builder.setControl(); //метод управления
		break;
	case 13:
		builder.setCrew();//экипаж(число)
		break;
	case 14:
		builder.setYear(); //год производства
		break;
	case 15:
		builder.setWeapon();//тип вооружения
		break;
	}
}

void Director::Del(Builder& builder) {

}

void Director::Get(Builder& builder) {
	builder.getType();
}

void Director::File(Builder& builder) {
	builder.ofile();
}
/*void Director::Edit(vector <Conveyor*> product) {
	for (size_t i = 0; i < product.size(); i++)
	{
		if (product[i]->machine == "Военный")
			for (size_t j = 0; j < product[i]->machine.size(); j++)
			{
				//f_ca << product[i]->machine[j] << endl;

			}
		if (product[i]->machine == "")
			for (size_t j = 0; j < product[i]->machine.size(); j++)
			{
				//f_h << product[i]->machine[j] << endl;
			}
		if (product[i]->machine == "Machine: Quadrobike")
			for (size_t j = 0; j < product[i]->machine.size(); j++)
			{
				//f_air << product[i]->machine[j] << endl;
			}
		if (product[i]->machine == "Machine: Quadrobike")
			for (size_t j = 0; j < product[i]->machine.size(); j++)
			{
				//f_quadr << product[i]->machine[j] << endl;
			}
	}
}
*/

/*void Director::File(vector <Conveyor*> product) {
	/*ofstream f_ca, f_quadr, f_h, f_air;
	f_ca.open("combatAircraft.txt", ios_base::app);
	f_h.open("helic.txt", ios_base::app);
	f_air.open("airliner.txt", ios_base::app);
	f_quadr.open("qudro.txt", ios_base::app);

	for (size_t i = 0; i < product.size(); i++)
	{
		if (product[i]->machine == "Военный")
			for (size_t j = 0; j < product[i]->machine.size(); j++)
			{
				//f_ca << product[i]->machine[j] << endl;

			}
		if (product[i]->machine == "")
			for (size_t j = 0; j < product[i]->machine.size(); j++)
			{
				//f_h << product[i]->machine[j] << endl;
			}
		if (product[i]->machine == "Machine: Quadrobike")
			for (size_t j = 0; j < product[i]->machine.size(); j++)
			{
				//f_air << product[i]->machine[j] << endl;
			}
		if (product[i]->machine == "Machine: Quadrobike")
			for (size_t j = 0; j < product[i]->machine.size(); j++)
			{
				//f_quadr << product[i]->machine[j] << endl;
			}
	}
	f_ca.close();
	f_h.close();
	f_air.close();
	f_quadr.close();
}*/