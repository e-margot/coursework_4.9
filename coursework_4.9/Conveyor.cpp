#include "Conveyor.h"


Conveyor::Conveyor() {
	machine = "";
	isMilitary = false; //������� ��� �����������
	type = ""; //military or civilian - ��� ������� ��� �����������
	weihht = 0; // takeoff weight - �������� �����
	engine = ""; //type of engines - ��� ����������
	NumEngine = 0; //number of engines - ���������� ����������
	wings = 0; // number of wings - ����� �������
	arrangW = ""; //arrangement of wings - ������������ �������
	chassis = ""; // type of chassis - ��� �����
	speed = 0;//flight speed - �������� ������
	takeoff = "";//��� ������
	landing = "";//��� �������
	control = ""; //����� ����������
	crew = 0; //������(�����)
	year = 0; //��� ������������
	weapon = ""; //��� ����������
}
Conveyor::~Conveyor() {

}
string Conveyor::getMashine() {

	return machine;
}

Conveyor::Conveyor(const Conveyor& obj) {


}