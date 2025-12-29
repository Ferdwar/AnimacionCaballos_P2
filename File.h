#pragma once
#include <iostream>
#include<fstream>
#include<string>
using namespace System;
using namespace std;
class File
{
private:
	ofstream fileWrite;
	ifstream fileRead;
	string text;
	int n, x, y;
public:
	File(){}
	~File(){}
	void readData() {
		fileRead.open("Configuraicion.txt", ios::in);
		if (fileRead.fail()) {
			fileRead.close();
			fileWrite.open("Configuracion.tx", ios::out);
			fileWrite << "10";//n
			fileWrite << "200";//x
			fileWrite << "100";//y
			fileWrite.close();
			//volvemos a abrir el archivo para la lectura
			fileRead.open("Configuracion.txt", ios::in);
		}
		getline(fileRead, text);
		n = atoi(text.c_str());
		getline(fileRead, text);
		x = atoi(text.c_str());
		getline(fileRead, text);
		y = atoi(text.c_str());
		fileRead.close();
	}
	int getN() { return n; }
	int getX() { return x; }
	int getY() { return y; }


};
