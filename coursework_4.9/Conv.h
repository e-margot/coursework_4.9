#pragma once
#include <string>
/*�������� ������ ����������� ���������
Aircraft assembly conveyor*/
/*airliner, combat aircraft, helicopter, quadcopter
������������ �������, ������ �������, ��������, ������������
*/

/*military or civilian, type of military apparatus,
type of civilian apparatus, takeoff weight, type of engines, number of engines, number of wings, 
arrangement of wings, type of chassis, flight speed, 
by type of takeoff and landing, method of control, crew (number of people), 
year of production , type of weapon*/

class Conveyor {
protected:
	string type; //military or civilian - ������� ��� �����������
	string Mil;//  type of military apparatus - ��� �������� ��������
	string Civ; //type of civilian apparatus - ��� ������������ ��������
	float weihht; // takeoff weight - �������� �����
	string engine; //type of engines - ��� ����������
	int engine; //number of engines - ���������� ����������
	int wings; // number of wings - ����� �������
	string arrangW; //arrangement of wings - ������������ �������
	string chassis; // type of chassis - ��� �����
	float speed;//flight speed - �������� ������
	string takeoff;//��� ������
	string landing;//��� �������
	string control; //����� ����������
	int crew; //������(�����)
	int year; //��� ������������
	string weapon; //��� ����������
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

