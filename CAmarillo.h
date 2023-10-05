#pragma once
#include "Circulo.h"

int minivector[6] = { -3,-2,-1,1,2,3 };

class CAmarillo : public Circulo {
public:
	CAmarillo(int px , int py) {
		//Los DX y DY son la direccion a la que van y muy aparte de decir por donde van tambien es su  velocidad
		//Sus X y Sus Y tienen que tomar el valor de el rojo o el verde ya que el amarillo sale con la colicion por ende no puede ser un random
		dx = minivector[rand() % 6];
		dy = minivector[rand() % 6];
		width = 5;
		height = 4;
		x = px;
		y = py;
		ID = 1;
	}

	void draw() {
		Console::ForegroundColor = ConsoleColor::Yellow;
		Console::SetCursorPosition(x, y+0); cout << " *** ";
		Console::SetCursorPosition(x, y+1); cout << "*   *";
		Console::SetCursorPosition(x, y+2); cout << "*   *";
		Console::SetCursorPosition(x, y+3); cout << " *** ";
	}

	//El amarillo sale del rebote por eso sale esto
	void rebound() {
		dx *= -1;
		dy *= -1;
	}

};