#pragma once
#include"Personaje.h"
#include <vector>
using namespace std;
class Controlador
{
private:
	vector<Personaje*>personajes;
public:
	Controlador(){}
	~Controlador(){}
	void addPersonaje(Personaje*objP) {
		personajes.push_back(objP);
	}
	void moverPersonaje(Graphics^gr ) {
		for (int i = 0; i < personajes.size(); i++)
			personajes[i]->mover(gr);
	}
	void dibujarPersonaje(Graphics^gr, Bitmap^bmp) {
		for (int i = 0; i < personajes.size();i++)
			personajes[i]->draw(gr, bmp);
	}
	int getPersonaje() {
		return personajes.size();
	}


};

