#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "windows.h"

using namespace std;

class Conveyor
{
public:
	/*std::vector<std::string> fly;
	void ListParts()const {
		std::cout << "Product info: " << std::endl;
		for (size_t i = 0; i < fly.size(); i++) {
			if (fly[i] == fly.back()) {
				std::cout << fly[i];
			}
			else {
				std::cout << fly[i] << std::endl;
			}
		}
		std::cout << "\n\n";
	}*/
	string machine;
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
	string getMashine();
	Conveyor(const Conveyor & obj);
};