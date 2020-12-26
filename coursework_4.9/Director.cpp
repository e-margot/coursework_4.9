#include "Director.h"


void Director::Construct(Builder& builder){
	builder.CreateProduct();
	builder.setMachine();
	builder.setType();
	builder.setIsMil(); //  type of military apparatus - ��� �������� ��������
	builder.setWeihht();// takeoff weight - �������� �����
	builder.setEngine(); //type of engines - ��� ����������
	builder.setNumEngine(); //number of engines - ���������� ����������
	builder.setWings(); // number of wings - ����� �������
	builder.setArrangW();//arrangement of wings - ������������ �������
	builder.setChassis(); // type of chassis - ��� �����
	builder.setSpeed();//flight speed - �������� ������
	builder.setTakeoff();//��� ������
	builder.setLanding();//��� �������
	builder.setControl(); //����� ����������
	builder.setCrew();//������(�����)
	builder.setYear(); //��� ������������
	builder.setWeapon();//��� ����������
	//builder.ofile();//��� ����������
	//builder.ifile();

}
void Director::EditProduct(Conveyor* product, Builder& builder){
	builder.CreateProduct();
	builder.toCurrBuild(product); 
	cout << "�������� ��������" << endl;
	cout << "1.	������� ��� �����������\n2.	��� �������� ��������, ��� ������������ ��������\n3.	�������� �����\n4.	��� ����������\n5.	����� ����������\n6.	���������� �������\n7.	������������ �������\n8.	��� �����\n9.	�������� ������\n10.	�� ���� ������\n11.	�� ���� �������\n12.	������ ����������\n13.	������(����� �������)\n14.	��� ������������\n15.	��� ����������" << endl;
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
	if (product->machine == "�������") { return 2; }
	else if (product->machine == "������������") { return 1; }
	else if (product->machine == "������������") { return 3; }
	else if (product->machine == "��������") { return 4; }
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