#pragma once
#include <iostream>
using namespace System::Drawing;
class Personaje
{
private:
	int x, y, velx, vely, idx, idy, W, H, indice;

public:
	Personaje(int w, int h, int x, int y) :W(w), H(h), x(x), y(y),
		velx(20), vely(20), idx(0), idy(0) {
		indice = rand() % 2;
	}
	~Personaje(){}
	void draw(Graphics^gr, Bitmap^bmp){
		Rectangle seccionMostrar = Rectangle(idx * W, idy * H, W, H);
		Rectangle zoom = Rectangle(x, y, W, H);
		gr->DrawImage(bmp, zoom, seccionMostrar, GraphicsUnit::Pixel);
	}
	void mover(Graphics^gr){
		if (indice == 0) {//MOVIMIENTO HORINZONTAL
			if (x + W + velx<0 || x + W + velx>gr->VisibleClipBounds.Width)
				velx *= -1;
			if (velx > 0)idy = 2; //mirar hacia la derecha
			if (velx < 0)idy = 1; //mirar hacia la izquierda
			//movimiento
			x += velx;
		}
		else {//movimiento  horizontal
			if (y + vely + H<0 || y + vely + H> gr->VisibleClipBounds.Height)
				vely *= -1;
			if (vely > 0)idy = 1; //Mira hacia arriba
			if (vely < 0)idy = 3; //Mirar hacia abajo
			//movimiento en y 
			y += vely;
		}
		idx++;
		if (idx++ > 3)idx = 0;
	}

};