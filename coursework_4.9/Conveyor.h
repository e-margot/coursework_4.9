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
	string isMilitary; 
	string type; 
	float weihht; 
	string engine;
	int NumEngine; 
	int wings; 
	string arrangW; 
	string chassis; 
	float speed;
	string takeoff;
	string landing;
	string control; 
	int crew; 
	int year; 
	string weapon; 
	Conveyor();
	~Conveyor();
};