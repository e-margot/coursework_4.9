#include "combatAircraft.h"

void combatAircraft::setIsMil() {
	currentBuilder->isMilitary = true;
}

void combatAircraft::setType() {
	string type;
	cout << "Enter type of plane" << endl;
	cin >> type;
	currentBuilder->type = type;
}//military or civilian - ������� ��� �����������

void combatAircraft::setWeihht() {
	float weihht;
	cout << "������� �������� �����" << endl;
	cin >> weihht;
	currentBuilder->weihht = weihht;
} // takeoff weight - �������� �����

void combatAircraft::setEngine() {
	string engine;
	cout << "������� ��� ����������" << endl;
	cin >> engine;
	currentBuilder->engine = engine;
} //type of engines - ��� ����������

void combatAircraft::setNumEngine() {
	int engine;
	cout << "������� ���������� ����������" << endl;
	cin >> engine;
	currentBuilder->NumEngine = engine;
} //number of engines - ���������� ����������

void combatAircraft::setWings() {
	int wings;
	cout << "������� ���������� �������" << endl;
	cin >> wings;
	currentBuilder->wings = wings;
} // number of wings - ����� �������

void combatAircraft::setArrangW() {
	string arrangW;
	cout << "������� ������������ �������" << endl;
	cin >> arrangW;
	currentBuilder->arrangW = arrangW;
}//arrangement of wings - ������������ �������

void combatAircraft::setChassis() {
	string chassis;
	cout << "������� ��� �����" << endl;
	cin >> chassis;
	currentBuilder->chassis = chassis;
} // type of chassis - ��� �����

void combatAircraft::setSpeed() {
	float speed;
	cout << "������� �������� ������" << endl;
	cin >> speed;
	currentBuilder->speed = speed;
}//flight speed - �������� ������

void combatAircraft::setTakeoff() {
	string takeoff;
	cout << "������� ��� ������" << endl;
	cin >> takeoff;
	currentBuilder->takeoff = takeoff;
}//��� ������

void combatAircraft::setLanding() {
	string landing;
	cout << "������� ��� �������" << endl;
	cin >> landing;
	currentBuilder->takeoff = landing;
}//��� �������


void combatAircraft::setControl() {
	string control;
	cout << "������� ������ ����������" << endl;
	cin >> control;
	currentBuilder->control = control;
} //����� ����������

void combatAircraft::setCrew() {
	int crew;
	cout << "������� ������ (����� ��������)" << endl;
	cin >> crew;
	currentBuilder->crew = crew;
}//������(�����)

void combatAircraft::setYear() {
	int year;
	cout << "������� ��� ������������" << endl;
	cin >> year;
	currentBuilder->year = year;
} //��� ������������

void combatAircraft::SetWeapon() {
	string weapon;
	cout << "������� ��� ����������" << endl;
	cin >> weapon;
	currentBuilder->weapon = weapon;
}//��� ����������

void combatAircraft::ofile() {
	ofstream fout;
	fout.open("combatAircraft.txt", ios_base::app);
	fout << "���: " << currentBuilder->type << endl;
	fout << "��� �������� ���������: " << currentBuilder->isMilitary << endl;
	fout << "�������� �����: " << currentBuilder->weihht << endl;
	fout << "��� ����������: " << currentBuilder->engine << endl;
	fout << "����� ����������: " << currentBuilder->NumEngine << endl;
	fout << "���������� �������:" << currentBuilder->wings << endl;
	fout << "������������ �������: " << currentBuilder->arrangW << endl;
	fout << "��� �����: " << currentBuilder->chassis << endl;
	fout << "�������� ������: " << currentBuilder->speed << endl;
	fout << "�� ���� ������: " << currentBuilder->takeoff << endl;
	fout << "�� ���� �������: " << currentBuilder->landing << endl;
	fout << "������ ����������: " << currentBuilder->control << endl;
	fout << "������ (����� �������): " << currentBuilder->crew << endl;
	fout << "��� ������������: " << currentBuilder->year << endl;
	fout << "��� ����������: " << currentBuilder->weapon << endl;
	fout << "----------------\n";
	fout.close();
}//��� ����������

void combatAircraft::ifile() {
	char line[100][100];
	ifstream fin;
	fin.open("combatAircraft.txt", ios::in);
	if (!fin)
	{
		cout << "���� �� ������\n\n";
		return;
	}
	int count = 0;
	while (fin.getline(line[count], 100)) count++;
	for (int j = 0; j < count; j++)
	{
		cout << line[j] << endl;
	}
	system("pause");
	fin.close();
}//��� ����������

combatAircraft::combatAircraft()
{
	currentBuilder = nullptr;
}
void combatAircraft::CreateProduct()
{
	cout << "�������" << endl;
	currentBuilder = new Conveyor();
}
Conveyor*combatAircraft::GetResult()
{
	return currentBuilder;
}
combatAircraft::~combatAircraft()
{
	if (currentBuilder != nullptr)
		delete currentBuilder;
}

void combatAircraft::getType(){
	// << currentBuilder->type << endl;
}
