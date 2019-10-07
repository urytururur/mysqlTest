// 
//-------MYSQL----------
//OBS! Det behövdes läggas till bibliotek och dependencies för att detta program skulle funka!

#include "Main.h"

#include "stdafx.h"
#include <mysql.h>
#include <iostream>
#include "Light.h"
#include <string>

using namespace std;
int qstate;

Main::Main()
{
	addLights(lights, 3);

	//getData();
	putData();
}

void finish_with_error(MYSQL* con)
{
	fprintf(stderr, "%s\n", mysql_error(con));
	mysql_close(con);
	exit(1);
}

int main(int argc, char** argv)
{
	Main main = Main();
	return 0;
}

void Main::addLights(vector<Light>& vector, int vectorSize)
{
	for (int i = 0; i < vectorSize; i++)
	{
		Light newLight = Light(i + 1, true, 1, 1, 0.5, 0.5, "none", 1, 1, 1);
		cout << newLight.getX();
		vector.push_back(newLight);
	}
}

void Main::getData()
{
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	conn = mysql_init(0);

	conn = mysql_real_connect(conn, "155.4.151.137", "remoteuser", "urytururur", "test1", 3306, NULL, 0);

	if (conn) {
		puts("Successful connection to database!");

		string query = "SELECT * FROM lights";
		const char* q = query.c_str();

		qstate = mysql_query(conn, q);
		if (!qstate)
		{
			res = mysql_store_result(conn);

			int i = 0;
			while (row = mysql_fetch_row(res))
			{

				lights[i].setOn(stoi(row[1]));
				lights[i].setBri(stoi(row[2]));
				lights[i].setSat(stoi(row[3]));
				lights[i].setX(stod(row[4]));
				lights[i].setY(stod(row[5]));
				lights[i].setEffect(row[6]);
				lights[i].setRed(stoi(row[7]));
				lights[i].setGreen(stoi(row[8]));
				lights[i].setBlue(stoi(row[9]));

				cout << "ID: " << lights[i].getId() << endl;
				cout << "ON: " << lights[i].getOn() << endl;
				cout << "BRI: " << lights[i].getBri() << endl;
				cout << "SAT: " << lights[i].getSat() << endl;
				cout << "X: " << lights[i].getX() << endl;
				cout << "Y: " << lights[i].getY() << endl;
				cout << "EFFECT: " << lights[i].getEffect() << endl << endl;
				cout << "RED: " << lights[i].getRed() << endl;
				cout << "GREEN: " << lights[i].getGreen() << endl;
				cout << "BLUE: " << lights[i].getBlue() << endl << endl;

				i++;
			}
		}
		else
		{
			cout << "Query failed: " << mysql_error(conn) << endl;
		}
	}
	else {
		puts("Connection to database has failed!");
	}
}

void Main::putData()
{
	MYSQL* con = mysql_init(NULL);

	if (con == NULL)
	{
		fprintf(stderr, "%s\n", mysql_error(con));
	}

	if (mysql_real_connect(con, "155.4.151.137", "remoteuser", "urytururur",
		"test1", 0, NULL, 0) == NULL)
	{
		finish_with_error(con);
	}

	for (int i = 0; i < lights.size(); i++)
	{
		//preparing update-statement
		string queryString = "UPDATE `lights` SET `on` = " + to_string(lights[i].getOn()) + ", `bri` = " + to_string(lights[i].getBri()) + ", `sat` = " + to_string(lights[i].getSat()) + ", `x` = " + to_string(lights[i].getX()) + ", `y` = " + to_string(lights[i].getY()) + ", `effect` = '" + lights[i].getEffect() + "'" ", `red` = " + to_string(lights[i].getRed()) + ", `green` = " + to_string(lights[i].getGreen()) + ", `blue` = " + to_string(lights[i].getBlue()) + " WHERE `lights`.`id` = " + to_string(lights[i].getId()) + ";";
		cout << queryString;
		const char* queryCharArray = queryString.c_str(); //converting to stringarray

		//Sending query
		if (mysql_query(con, queryCharArray)) {
			finish_with_error(con);
		}
	}

	mysql_close(con);
}