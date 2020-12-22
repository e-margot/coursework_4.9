#include "Director.h"


void Director::Construct(Builder& builder)
{
	// 1. ������� �������
	builder.CreateProduct();
	builder.setType();
	//builder.setIsMil(); //  type of military apparatus - ��� �������� ��������
	//builder.setWeihht();// takeoff weight - �������� �����
	//builder.setEngine(); //type of engines - ��� ����������
	//builder.setNumEngine(); //number of engines - ���������� ����������
	//builder.setWings(); // number of wings - ����� �������
	//builder.setArrangW();//arrangement of wings - ������������ �������
	//builder.setChassis(); // type of chassis - ��� �����
	//builder.setSpeed();//flight speed - �������� ������
	//builder.setTakeoff();//��� ������
	//builder.setLanding();//��� �������
	//builder.setControl(); //����� ����������
	//builder.setCrew();//������(�����)
	//builder.setYear(); //��� ������������
	//builder.setWeapon();//��� ����������
	//builder.ofile();//��� ����������
	//builder.ifile();
}

void Director::Edit(Builder &builder) {
	cout << "�������� ��������" << endl;
	cout << "1.	������� ��� �����������\n2.	��� �������� ��������, ��� ������������ ��������\n3.	�������� �����\n4.	��� ����������\n5.	����� ����������\n6.	���������� �������\n7.	������������ �������\n8.	��� �����\n9.	�������� ������\n10.	�� ���� ������\n11.		�������\n12.	������ ����������\n13.	������(����� �������)\n14.	��� ������������\n15.	��� ����������" << endl;
	int ch = 0;
	cin >> ch;
	switch (ch) {
	case 1:
		builder.setType();
		break;
	case 2:
		builder.setIsMil(); //  type of military apparatus - ��� �������� ��������
		break;
	case 3:
		builder.setWeihht();// takeoff weight - �������� �����
		break;
	case 4:
		builder.setEngine(); //type of engines - ��� ����������
		break;
	case 5:
		builder.setNumEngine(); //number of engines - ���������� ����������
		break;
	case 6:
		builder.setWings(); // number of wings - ����� �������
		break;
	case 7:
		builder.setArrangW();//arrangement of wings - ������������ �������
		break;
	case 8:
		builder.setChassis(); // type of chassis - ��� �����
		break;
	case 9:
		builder.setSpeed();//flight speed - �������� ������
		break;
	case 10:
		builder.setTakeoff();//��� ������
		break;
	case 11:
		builder.setLanding();//��� �������
		break;
	case 12:
		builder.setControl(); //����� ����������
		break;
	case 13:
		builder.setCrew();//������(�����)
		break;
	case 14:
		builder.setYear(); //��� ������������
		break;
	case 15:
		builder.setWeapon();//��� ����������
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
		if (product[i]->machine == "�������")
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
		if (product[i]->machine == "�������")
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