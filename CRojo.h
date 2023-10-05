#pragma once
#include "Circulo.h"

class CRojo : public Circulo {
public:
	CRojo() {
		//Los DX y DY son la direccion a la que van y muy aparte de decir por donde van tambien es su  velocidad
		dx = 0;
		dy = 2;
		width = 5;
		height = 4;
		x = rand() % (WIDTH - width);
		y = rand() % (HEIGHT - height);
		ID = 2;
	}

	void draw() {
		Console::ForegroundColor = ConsoleColor::Red;
		Console::SetCursorPosition(x, y + 0); cout << " *** ";
		Console::SetCursorPosition(x, y + 1); cout << "*****";
		Console::SetCursorPosition(x, y + 2); cout << "*****";
		Console::SetCursorPosition(x, y + 3); cout << " *** ";
	}

};