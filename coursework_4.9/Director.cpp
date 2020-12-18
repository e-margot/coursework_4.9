#include "Director.h"


void Director::Construct(Builder& builder)
{
	// 1. ������� �������
	builder.CreateProduct();
	builder.setType();
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
	builder.ofile();//��� ����������
	builder.ifile();
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