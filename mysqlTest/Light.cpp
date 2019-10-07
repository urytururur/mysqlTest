#include "Light.h"

Light::Light(int idI, int onI, int briI, int satI, double xI, double yI, string effectI, int redI, int greenI, int blueI)
{
	id = idI;
	on = onI;
	bri = briI;
	sat = satI;
	x = xI;
	y = yI;
	effect = effectI;
	red = redI;
	green = greenI;
	blue = blueI;
}

int Light::getId()
{
	return id;
}
void Light::setId(int value)
{
	id = value;
}

bool Light::getOn()
{
	return on;
}
void Light::setOn(bool value)
{
	on = value;
}

int Light::getBri()
{
	return bri;
}
void Light::setBri(int value)
{
	bri = value;
}

int Light::getSat()
{
	return sat;
}
void Light::setSat(int value)
{
	sat = value;
}

double Light::getX()
{
	return x;
}
void Light::setX(double value)
{
	x = value;
}

double Light::getY()
{
	return y;
}
void Light::setY(double value)
{
	y = value;
}

string Light::getEffect()
{
	return effect;
}
void Light::setEffect(string value)
{
	effect = value;
}

int Light::getRed()
{
	return red;
}
void Light::setRed(int value)
{
	red = value;
}

int Light::getGreen()
{
	return green;
}
void Light::setGreen(int value)
{
	green = value;
}

int Light::getBlue()
{
	return blue;
}
void Light::setBlue(int value)
{
	blue = value;
}