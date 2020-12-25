#include "airliner.h"

void airliner::setIsMil() {
	currentBuilder->isMilitary = "�����������";
}
void airliner::setType() {
	cout << "��� ������������ ��������: " << endl;
	getline(cin, currentBuilder->type);
}

void airliner::setWeihht() {
	string tmp;
	cout << "������� �������� �����" << endl;
	getline(cin, tmp);
	currentBuilder->weihht = atoi(tmp.c_str());
} 

void airliner::setEngine() {
	cout << "������� ��� ����������" << endl;
	getline(cin, currentBuilder->engine);
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
	currentBuilder->landing = landing;
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
	fout << "��� ������������: " << currentBuilder->year << endl;
	//fout << "----------------\n";
	fout.close();
}

void airliner::ifile(vector <Conveyor*>& product) {
	string str;
	ifstream fin;
	currentBuilder = new Conveyor();
	fin.open("airliner.txt", ios::in);

	if (!fin.is_open())
		throw exception("���� �� ������� �������!\n");

	if (fin.peek() == EOF)
		throw exception("�a�� ����!\n");
	int count = 1, pos = 0;
	while (fin.peek() != EOF) 
	{
		getline(fin, str);

		currentBuilder->machine = "������������";

		switch (count)
		{
		case 1:
			if (pos = str.find("���: ") != 0) throw exception("������ ��������\n");
				
			currentBuilder->type = str.substr(5);
			break;
		case 2:
			if (pos = str.find("��� ������������ ��������: ") != 0) throw exception("������ ��������\n");

			currentBuilder->isMilitary = str.substr(27);
			break;
		case 3:
			if (pos = str.find("�������� �����: ") != 0)
				throw exception("������ ��������\n");

			str = str.substr(16);

			currentBuilder->weihht = atoi(str.c_str()); 
			if (currentBuilder->weihht < 0)
				throw exception("�������� �� ����������\n");
			break;
		case 4:
			if (pos = str.find("��� ����������: ") != 0) throw exception("������ ��������\n");

			currentBuilder->engine = str.substr(16);
			break;
		case 5:
			if (pos = str.find("����� ����������: ") != 0) throw exception("������ ��������\n");

			str = str.substr(18);

			currentBuilder->NumEngine = atoi(str.c_str());
			if (currentBuilder->NumEngine < 0)
				throw exception("�������� �� ����������\n");
			break;
		case 6:
			if (pos = str.find("���������� �������: ") != 0) throw exception("������ ��������\n");

			str = str.substr(20);

			currentBuilder->wings = atoi(str.c_str());
			if (currentBuilder->wings < 0)
				throw exception("�������� �� ����������\n");
			break;
		case 7:
			if (pos = str.find("������������ �������: ") != 0) throw exception("������ ��������\n");

			currentBuilder->arrangW = str.substr(22);
			break;
		case 8:
			if (pos = str.find("��� �����: ") != 0) throw exception("������ ��������\n");

			currentBuilder->chassis = str.substr(11);
			break;
		case 9:
			if (pos = str.find("�������� ������: ") != 0)
				throw exception("������ ��������\n");

			str = str.substr(17);

			currentBuilder->speed = atoi(str.c_str());
			if (currentBuilder->speed < 0)
				throw exception("�������� �� ����������\n");
			break;
		case 10:
			if (pos = str.find("�� ���� ������: ") != 0) throw exception("������ ��������\n");

			currentBuilder->takeoff = str.substr(17);
			
			break;
		case 11:
			if (pos = str.find("�� ���� �������: ") != 0) throw exception("������ ��������\n");

			currentBuilder->landing = str.substr(16);
			break;
		case 12:
			if (pos = str.find("������ ����������: ") != 0) throw exception("������ ��������\n");

			currentBuilder->control = str.substr(11);
			break;
		case 13:
			if (pos = str.find("������ (����� �������): ") != 0)
				throw exception("������ ��������\n");

			str = str.substr(24);

			currentBuilder->crew = atoi(str.c_str());
			if (currentBuilder->crew < 0)
				throw exception("�������� �� ����������\n");
			break;
		case 14:
			if (pos = str.find("��� ������������: ") != 0)
				throw exception("������ ��������\n");

			str = str.substr(18);

			currentBuilder->year = atoi(str.c_str());
			if ((currentBuilder->year) < 1920 || currentBuilder->year > 2020)
				throw exception("�������� �� ����������\n");
			product.push_back(currentBuilder);
			count = 0;
			currentBuilder = new Conveyor();
			break;
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
	cout << "��� ������������: " << currentBuilder->year << endl;
	cout << "----------------\n";
}
