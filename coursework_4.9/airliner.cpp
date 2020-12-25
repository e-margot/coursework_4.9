#include "airliner.h"

void airliner::setIsMil() {
	currentBuilder->isMilitary = false;
}
void airliner::setType() {
	string type;
	cout << "��� ������������ ��������: " << endl;
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
	//fout << "----------------\n";
	fout.close();
}

void airliner::ifile(vector <Conveyor*>& product) {
	//char line[100][100]; 
	string str;
	ifstream fin;
	currentBuilder = new Conveyor();
	fin.open("airliner.txt", ios::in);

	if (!fin.is_open())
		throw exception("���� �� ������� �������!\n");

	if (fin.peek() == EOF)
		throw exception("���� ����!\n");
	int count = 1, pos = 0;
	while (fin.peek() != EOF) // Read data from file
	{
		getline(fin, str);
		//if (str.empty()) continue;
	
		currentBuilder->machine = "������������";
		//14 �����   
		switch (count)
		{
		case 1:
			if (pos = str.find("���: ") != 0) throw exception("wer\n");
				
			currentBuilder->type = str.substr(5);
			break;
		case 2:
			break;
		case 3:
			if (pos = str.find("�������� �����: ") != 0)
				throw exception("\n");

			str = str.substr(6);
			/*if (!num_valid(tmp))
				throw exception("\n");*/

			currentBuilder->weihht = atoi(str.c_str()); // Convert string to integer
			if (currentBuilder->weihht < 0)
				throw exception("qweq\n");
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			break;
		case 11:
			break;
		case 12:
			break;
		case 13:
			break;
		case 14:
			product.push_back(currentBuilder);
			count = 0;
			currentBuilder = new Conveyor();
		default:
			break;
		}
		count++;
	}
	
	/*if (!fin)
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
	system("pause");*/
	fin.close();
}
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
	currentBuilder = new Conveyor();
}
airliner::airliner()
{
	currentBuilder = nullptr;
	
}
void airliner::setMachine() {
	currentBuilder->machine = "������������";
}


void airliner::toCurrBuild(Conveyor* product) {

	currentBuilder->machine = product->machine;
	currentBuilder->type = product->type;
	currentBuilder->isMilitary = product->isMilitary;
	currentBuilder->weihht = product->weihht;
	currentBuilder->engine = product->engine;
	currentBuilder->NumEngine = product->NumEngine;
	currentBuilder->wings = product->wings;
	currentBuilder->arrangW = product->arrangW;
	currentBuilder->chassis = product->chassis;
	currentBuilder->speed = product->speed;
	currentBuilder->takeoff = product->takeoff;
	currentBuilder->landing = product->landing;
	currentBuilder->control = product->control;
	currentBuilder->crew = product->crew;
	currentBuilder->year = product->year;
}

void airliner::Get() {
	cout << "���: " << currentBuilder->type << endl;
	cout << "��� ������������ ��������: " << currentBuilder->isMilitary << endl;
	cout << "�������� �����: " << currentBuilder->weihht << endl;
	cout << "��� ����������: " << currentBuilder->engine << endl;
	cout << "����� ����������: " << currentBuilder->NumEngine << endl;
	cout << "���������� �������: " << currentBuilder->wings << endl;
	cout << "������������ �������: " << currentBuilder->arrangW << endl;
	cout << "��� �����: " << currentBuilder->chassis << endl;
	cout << "�������� ������: " << currentBuilder->speed << endl;
	cout << "�� ���� ������: " << currentBuilder->takeoff << endl;
	cout << "�� ���� �������: " << currentBuilder->landing << endl;
	cout << "������ ����������: " << currentBuilder->control << endl;
	cout << "������ (����� �������): " << currentBuilder->crew << endl;
	cout << "��� ������������:" << currentBuilder->year << endl;
	//cout << "----------------\n";
}
