#include "quadcopter.h"

quadcopter::quadcopter()
{
	currentBuilder = nullptr;
}

void quadcopter::CreateProduct()
{
	cout << "������� ������� �" << endl;
	currentBuilder = new Conveyor();
}


// �����, ������������ ������� ��� �������
Conveyor* quadcopter::GetResult()
{
	return currentBuilder;
}

// ����������
quadcopter::~quadcopter()
{
	if (currentBuilder != nullptr)
		delete currentBuilder;
}

void quadcopter::setIsMil() {
	currentBuilder->isMilitary = false;

}
void quadcopter::setType() {
	string type;
	cout << "Enter type of plane" << endl;
	cin >> type;
	currentBuilder->type = type;
}//military or civilian - ������� ��� �����������


void quadcopter::setWeihht() {
	float weihht;
	cout << "������� �������� �����" << endl;
	cin >> weihht;
	currentBuilder->weihht = weihht;
} // takeoff weight - �������� �����


void quadcopter::setSpeed() {
	float speed;
	cout << "������� �������� ������" << endl;
	cin >> speed;
	currentBuilder->speed = speed;
}//flight speed - �������� ������



void quadcopter::setControl() {
	string control;
	cout << "������� ������ ����������" << endl;
	cin >> control;
	currentBuilder->control = control;
} //����� ����������


void quadcopter::setYear() {
	int year;
	cout << "������� ��� ������������" << endl;
	cin >> year;
	currentBuilder->year = year;
} //��� ������������

void quadcopter::ofile() {
	ofstream fout;
	fout.open("qudro.txt", ios_base::app);
	fout << "���: " << currentBuilder->type << endl;
	fout << "��� ������������: " << currentBuilder->isMilitary << endl;
	fout << "���: " << currentBuilder->weihht << endl;
	fout << "��������: " << currentBuilder->speed << endl;
	fout << "����������: " << currentBuilder->control << endl;
	fout << "��� ������������: " << currentBuilder->year << endl;
}//��� ����������
void quadcopter::ifile() {}//��� ����������

