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
	string machine;
	string isMilitary; //������� ��� �����������
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
	//string getMashine();
	//Conveyor(const Conveyor & obj);
};