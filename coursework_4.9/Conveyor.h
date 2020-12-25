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
	bool isMilitary; //Военный или гражданский
	string type; //military or civilian - тип военный или гражданский
	float weihht; // takeoff weight - взлетная масса
	string engine; //type of engines - тип двигателей
	int NumEngine; //number of engines - количество двигателей
	int wings; // number of wings - число крыльев
	string arrangW; //arrangement of wings - расположение крыльев
	string chassis; // type of chassis - тип шасси
	float speed;//flight speed - скорость полета
	string takeoff;//тип взлета
	string landing;//тип посадки
	string control; //метод управления
	int crew; //экипаж(число)
	int year; //год производства
	string weapon; //тип вооружения
	Conveyor();
	~Conveyor();
	string getMashine();
	Conveyor(const Conveyor & obj);
};