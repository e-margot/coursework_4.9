#include "airliner.h"



void airliner::setIsMil() {
	currentBuilder->isMilitary = false;
}
void airliner::setType() {
	string type;
	cout << "Enter type of plane" << endl;
	cin >> type;
	currentBuilder->type = type;
}//military or civilian - ������� ��� �����������


void airliner::setWeihht() {
	float weihht;
	cout << "������� �������� �����" << endl;
	cin >> weihht;
	currentBuilder->weihht = weihht;
} // takeoff weight - �������� �����

void airliner::setEngine() {
	string engine;
	cout << "������� ��� ����������" << endl;
	cin >> engine;
	currentBuilder->engine = engine;
} //type of engines - ��� ����������

void airliner::setNumEngine() {
	int engine;
	cout << "������� ���������� ����������" << endl;
	cin >> engine;
	currentBuilder->NumEngine = engine;
} //number of engines - ���������� ����������

void airliner::setWings() {
	int wings;
	cout << "������� ���������� �������" << endl;
	cin >> wings;
	currentBuilder->wings = wings;
} // number of wings - ����� �������

void airliner::setArrangW() {
	string arrangW;
	cout << "������� ������������ �������" << endl;
	cin >> arrangW;
	currentBuilder->arrangW = arrangW;
}//arrangement of wings - ������������ �������

void airliner::setChassis() {
	string chassis;
	cout << "������� ��� �����" << endl;
	cin >> chassis;
	currentBuilder->chassis = chassis;
} // type of chassis - ��� �����

void airliner::setSpeed() {
	float speed;
	cout << "������� �������� ������" << endl;
	cin >> speed;
	currentBuilder->speed = speed;
}//flight speed - �������� ������

void airliner::setTakeoff() {
	string takeoff;
	cout << "������� ��� ������" << endl;
	cin >> takeoff;
	currentBuilder->takeoff = takeoff;
}//��� ������

void airliner::setLanding() {
	string landing;
	cout << "������� ��� �������" << endl;
	cin >> landing;
	currentBuilder->takeoff = landing;
}//��� �������


void airliner::setControl() {
	string control;
	cout << "������� ������ ����������" << endl;
	cin >> control;
	currentBuilder->control = control;
} //����� ����������

void airliner::setCrew() {
	int crew;
	cout << "������� ������ (����� ��������)" << endl;
	cin >> crew;
	currentBuilder->crew = crew;
}//������(�����)

void airliner::setYear() {
	int year;
	cout << "������� ��� ������������" << endl;
	cin >> year;
	currentBuilder->year = year;
} //��� ������������

void airliner::ofile() {
	ofstream fout;
	fout.open("airliner.txt", ios_base::app);
	fout << "���: " << currentBuilder->type << endl;
	fout << "��� ������������ ��������: " << currentBuilder->isMilitary << endl;
	fout << "�������� �����: " << currentBuilder->weihht << endl;
	fout << "��� ����������: " << currentBuilder->engine << endl;
	fout << "����� ����������: " << currentBuilder->NumEngine << endl;
	fout << "���������� �������: " << currentBuilder->wings << endl;
	fout << "������������ �������: " << currentBuilder->arrangW << endl;
	fout << "��� �����: " << currentBuilder->chassis << endl;
	fout << "�������� ������: " << currentBuilder->speed << endl;
	fout << "�� ���� ������: " << currentBuilder->takeoff << endl;
	fout << "�� ���� �������: " << currentBuilder->landing << endl;
	fout << "������ ����������: " << currentBuilder->control << endl;
	fout << "������ (����� �������): " << currentBuilder->crew << endl;
	fout << "��� ������������:" << currentBuilder->year << endl;
}//��� ����������
void airliner::ifile() {}//��� ����������
Conveyor* airliner::GetResult()
{
	return currentBuilder;
}
airliner::~airliner()
{
	if (currentBuilder != nullptr)
		delete currentBuilder;
}
void airliner::CreateProduct()
{
	cout << "������� ������� �" << endl;
	currentBuilder = new Conveyor();
}
airliner::airliner()
{
	currentBuilder = nullptr;
}