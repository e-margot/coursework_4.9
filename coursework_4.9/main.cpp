#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "windows.h"
using namespace std;
class Conveyor
{
public:
	bool isMilitary; //������� ��� �����������
	string type; //military or civilian - ��� ������� ��� �����������
	float weihht; // takeoff weight - �������� �����
	string engine; //type of engines - ��� ����������
	int NumEngine; //number of engines - ���������� ����������
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
	Conveyor();
	~Conveyor();
};
Conveyor::Conveyor() {
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
	virtual void ofile() {};//����� � ����
	virtual void ifile() {};//���������� � �����
	virtual Conveyor* GetResult() { return nullptr; };
};
class airliner : public Builder
{
private:
	Conveyor* currentBuilder;

public:
	// �����������
	airliner();
	~airliner();
	// ���������� ����������� �������
	void CreateProduct();
	void setType();
	void setIsMil();
	void setWeihht();
	void setEngine();
	void setNumEngine();
	void setWings();
	void setArrangW();
	void setChassis();
	void setSpeed();
	void setTakeoff();
	void setLanding();
	void setControl();
	void setCrew();
	void setYear();
	void ofile();
	void ifile();//��� ����������
	Conveyor* GetResult();
	// ����������

};

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
	fout.open("helic.txt", ios_base::app);
	fout << currentBuilder->type << endl;
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


class combatAircraft : public Builder
{
private:
	Conveyor* currentBuilder;

public:
	// �����������
	combatAircraft();
	~combatAircraft();
	void CreateProduct();
	Conveyor* GetResult();
	void setType();
	void setIsMil();
	void setWeihht();
	void setEngine();
	void setNumEngine();
	void setWings();
	void setArrangW();
	void setChassis();
	void setSpeed();
	void setTakeoff();
	void setLanding();
	void setControl();
	void setCrew();
	void setYear();
	void SetWeapon();
	void ofile();
	void ifile();

};

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
	fout.open("helic.txt", ios_base::app);
	fout << currentBuilder->type << endl;
}//��� ����������
void combatAircraft::ifile() {}//��� ����������

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


class Director
{
public:
	// �����, �������������� �����
	void Construct(Builder& builder);
};
void Director::Construct(Builder& builder)
{
	// 1. ������� �������
	builder.CreateProduct();
	builder.setType();
	builder.ofile();
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


class helicopter : public Builder {
private:
	Conveyor* currentBuilder;

public:
	// �����������
	helicopter();
	~helicopter();
	// ���������� ����������� �������
	void CreateProduct();
	void setType();
	void setIsMil();
	void setWeihht();
	void setEngine();
	void setNumEngine();
	void setWings();
	void setArrangW();
	void setChassis();
	void setSpeed();
	void setTakeoff();
	void setLanding();
	void setControl();
	void setCrew();
	void setYear();
	void SetWeapon();
	void ofile();
	void ifile();
	// ��������� ����� 1
		//virtual void BuildLopasti(int lopasti)
		//{
		//	cout << "helicopter::currentBuilder->lopasti = " << lopasti << endl;
		//	currentBuilder->lopasti = lopasti;
		//}

		//// ��������� ����� 2
		//virtual void BuildEngine(int engine)
		//{
		//	cout << "helicopter::currentBuilder->engine = " << engine << endl;
		//	currentBuilder->engine = engine;
		//}

		// �����, ������������ ������� ��� �������
	virtual Conveyor* GetResult();
	// ����������

};

helicopter::helicopter()
{
	currentBuilder = nullptr;
}

// ���������� ����������� �������
void helicopter::CreateProduct()
{
	currentBuilder = new Conveyor();
}

void helicopter::setIsMil() {
	int ch;
	while (true) {
		cout << "���:" << endl;
		cout << "1) �����������;" << endl;
		cout << "2) �������;" << endl;
		cin >> ch;
		if (ch == 1) {
			currentBuilder->isMilitary = false;
			break;
		}
		else if (ch == 2) {
			currentBuilder->isMilitary = true;
			break;
		}
		else {
			cout << "������ ������� �����������" << endl;
		}
	}
}
void helicopter::setType() {
	string type;
	cout << "Enter type of plane" << endl;
	cin >> type;
	currentBuilder->type = type;
}//military or civilian - ������� ��� �����������


void helicopter::setWeihht() {
	float weihht;
	cout << "������� �������� �����" << endl;
	cin >> weihht;
	currentBuilder->weihht = weihht;
} // takeoff weight - �������� �����

void helicopter::setEngine() {
	string engine;
	cout << "������� ��� ����������" << endl;
	cin >> engine;
	currentBuilder->engine = engine;
} //type of engines - ��� ����������

void helicopter::setNumEngine() {
	int engine;
	cout << "������� ���������� ����������" << endl;
	cin >> engine;
	currentBuilder->NumEngine = engine;
} //number of engines - ���������� ����������

void helicopter::setWings() {
	int wings;
	cout << "������� ���������� �������" << endl;
	cin >> wings;
	currentBuilder->wings = wings;
} // number of wings - ����� �������

void helicopter::setArrangW() {
	string arrangW;
	cout << "������� ������������ �������" << endl;
	cin >> arrangW;
	currentBuilder->arrangW = arrangW;
}//arrangement of wings - ������������ �������

void helicopter::setChassis() {
	string chassis;
	cout << "������� ��� �����" << endl;
	cin >> chassis;
	currentBuilder->chassis = chassis;
} // type of chassis - ��� �����

void helicopter::setSpeed() {
	float speed;
	cout << "������� �������� ������" << endl;
	cin >> speed;
	currentBuilder->speed = speed;
}//flight speed - �������� ������

void helicopter::setTakeoff() {
	string takeoff;
	cout << "������� ��� ������" << endl;
	cin >> takeoff;
	currentBuilder->takeoff = takeoff;
}//��� ������

void helicopter::setLanding() {
	string landing;
	cout << "������� ��� �������" << endl;
	cin >> landing;
	currentBuilder->takeoff = landing;
}//��� �������


void helicopter::setControl() {
	string control;
	cout << "������� ������ ����������" << endl;
	cin >> control;
	currentBuilder->control = control;
} //����� ����������

void helicopter::setCrew() {
	int crew;
	cout << "������� ������ (����� ��������)" << endl;
	cin >> crew;
	currentBuilder->crew = crew;
}//������(�����)

void helicopter::setYear() {
	int year;
	cout << "������� ��� ������������" << endl;
	cin >> year;
	currentBuilder->year = year;
} //��� ������������

void helicopter::SetWeapon() {
	string weapon;
	cout << "������� ��� ����������" << endl;
	cin >> weapon;
	currentBuilder->weapon = weapon;
}//��� ����������
void helicopter::ofile() {
	ofstream fout;
	fout.open("helic.txt", ios_base::app);
	fout << currentBuilder->type << endl;
}//��� ����������
void helicopter::ifile() {}//��� ����������

Conveyor* helicopter::GetResult()
{
	return currentBuilder;
}
//void helicopter::del() {
//	if (currentBuilder != nullptr)
//		delete currentBuilder;
//	i--;
//}
// ����������
helicopter::~helicopter()
{
	if (currentBuilder != nullptr)
		delete currentBuilder;
}
class quadcopter : public Builder
{
private:
	Conveyor* currentBuilder;

public:
	// �����������
	quadcopter();
	void CreateProduct();
	Conveyor* GetResult();
	~quadcopter();
	void setType();
	void setIsMil();
	void setWeihht();
	void setSpeed();
	void setControl();
	void setYear();
	void ofile();
	void ifile();
};
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
	fout.open("helic.txt", ios_base::app);
	fout << currentBuilder->type << endl;
}//��� ����������
void quadcopter::ifile() {}//��� ����������



int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	int N = 0, choose = 0, i = 0;
	bool loop = true;
	cout << "Enter N" << endl;
	cin >> N;
	// ������� main() � ������ ������ ��������� ��������
	// 1. �������� ��������� �� �������, ������� ����� ��������
	Conveyor** product = new Conveyor*[N]; //builder
	helicopter Helic; //concrete builder
	quadcopter Quadr;
	airliner Air;
	combatAircraft CA;
	Director D;
	do {
		system("cls");
		cout << "�������� ��� ������������ ��������:" << endl;
		cout << "1) ������������ �������" << endl;
		cout << "2) ������� �������" << endl;
		cout << "3) ��������" << endl;
		cout << "4) ������������" << endl;
		cout << "5) �����" << endl;
		cin >> choose;
		switch (choose) {
		case 1:
			D.Construct(Air); // ����������������
			product[i] = Air.GetResult();
			i++;
			break;
		case 2:
			D.Construct(CA); // ����������������
			product[i] = CA.GetResult();
			i++;
			break;
		case 3:
			D.Construct(Helic); // ����������������
			product[i] = Helic.GetResult();
			i++;
			break;
		case 4:
			D.Construct(Quadr); // ����������������
			product[i] = Quadr.GetResult();
			i++;
			break;
		case 5:
			loop = false;
		default:
			loop = false;
		}
		if (i == N) { //�������� �� �������
			cout << "���� ���" << endl;
			loop = false;
		}

	} while (loop);
	system("cls");
	for (int j = 0; j < i; j++) {
		//cout << product[j]->type << endl;
	}
	// 2. ������� ���������� ��������� ������ helicopter � ��������� ����������

	// 3. ������� �����-������������� � ���������������� ��� ��������� B
	//Director D;
	//D.Construct(Helic); // ����������������
	//D.Construct(Quadr1); // ����������������
	//D.Construct(Quadr2); // ����������������

	//// 4. ����� ����������������, �������� ��������� ������� �������
	//product[0] = Helic.GetResult();
	//product[1] = Quadr1.GetResult();
	//product[2] = Quadr2.GetResult();

	// 5. ������� �������� �������� ��� ��������
	/*cout << "product->type = " << product->type << endl;
	cout << "product->engine = " << product->engine << endl;*/
	/*for (int j = 0; j < i; j++)
	{
		delete[] product[j];
	}*/
	delete[] product;

	system("pause");
	return 0;
}