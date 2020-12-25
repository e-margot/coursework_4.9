#include "quadcopter.h"

quadcopter::quadcopter()
{
	currentBuilder = nullptr;
}

void quadcopter::CreateProduct()
{
	currentBuilder = new Conveyor();
}
void quadcopter::setMachine() {
	currentBuilder->machine = "������������";
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
	fout << "----------------\n";
	fout.close();
}//��� ����������
void quadcopter::ifile() {
	char line[100][100];
	ifstream fin;
	fin.open("qudro.txt", ios::in);
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


void quadcopter::toCurrBuild(Conveyor* product) {
	currentBuilder->machine = product->machine;
	currentBuilder->type = product->type;
	currentBuilder->isMilitary = product->isMilitary;
	currentBuilder->weihht = product->weihht;
	currentBuilder->speed = product->speed;
	currentBuilder->control = product->control;
	currentBuilder->year = product->year;
}
void quadcopter::Get() {
	cout << "���: " << currentBuilder->type << endl;
	cout << "��� ������������: " << currentBuilder->isMilitary << endl;
	cout << "���: " << currentBuilder ->weihht << endl;
	cout << "��������: " << currentBuilder->speed << endl;
	cout << "����������: " << currentBuilder->control << endl;
	cout << "��� ������������: " << currentBuilder->year << endl;
	cout << "----------------\n";
}