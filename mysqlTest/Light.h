#pragma once
#include <string>

using namespace std;

class Light
{
private:

	int id, bri, sat, red, green, blue;
	double  x, y;
	bool on;
	string effect;

public:

	Light(int idI, int onI, int briI, int satI, double xI, double yI, string effectI, int redI, int greenI, int blueI);

	int getId();
	void setId(int value);

	int getBri();
	void setBri(int value);

	bool getOn();
	void setOn(bool value);

	int getSat();
	void setSat(int value);

	double getX();
	void setX(double value);

	double getY();
	void setY(double value);

	int getRed();
	void setRed(int value);

	int getGreen();
	void setGreen(int value);

	int getBlue();
	void setBlue(int value);

	string getEffect();
	void setEffect(string value);
};