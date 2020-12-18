#pragma once
#include "Conveyor.h"

class Builder {
public:
	Builder() { };
	virtual ~Builder() {};
	virtual void CreateProduct() {};
	virtual void setType() {};//military or civilian - ������� ��� �����������
	virtual void setIsMil() {}; //  type of military apparatus - ��� �������� ��������
	virtual void setWeihht() {};// takeoff weight - �������� �����
	virtual void setEngine() {};  //type of engines - ��� ����������
	virtual void setNumEngine() {}; //number of engines - ���������� ����������
	virtual void setWings() {}; // number of wings - ����� �������
	virtual void setArrangW() {};//arrangement of wings - ������������ �������
	virtual void setChassis() {}; // type of chassis - ��� �����
	virtual void setSpeed() {};//flight speed - �������� ������
	virtual void setTakeoff() {};//��� ������
	virtual void setLanding() {};//��� �������
	virtual void setControl() {}; //����� ����������
	virtual void setCrew() {};//������(�����)
	virtual void setYear() {}; //��� ������������
	virtual void setWeapon() {};//��� ����������
	virtual void delType() {};//��������
	virtual void ofile() {};//����� � ����
	virtual void ifile() {};//���������� � �����
	virtual Conveyor* GetResult() { return nullptr; };
};