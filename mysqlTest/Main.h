#pragma once

#include <vector>
#include "stdafx.h"
#include <mysql.h>
#include <iostream>
#include "Light.h"

using namespace std;

class Main
{
private:

	vector<Light> lights;

	int id = 1;
	int on = 0;
	int bri = 2;
	int sat = 10;
	string effect = "none";
	int red = 100;
	int green = 100;
	int blue = 100;

public:

	Main();

	void addLights(vector<Light>& vector, int vectorSize);

	void getData();
	void putData();




};