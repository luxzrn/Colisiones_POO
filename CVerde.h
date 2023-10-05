#pragma once
#include "Circulo.h"
class CVerde : public Circulo {

public:
	CVerde() {
		//Los DX y DY son la direccion a la que van y muy aparte de decir por donde van tambien es su  velocidad
		dx = 2;
		dy = 0;
		width = 5;
		height = 4;
		x = rand() % (WIDTH - width);
		y = rand() % (HEIGHT - height);
		ID = 3;
	}

	void draw() {
		Console::ForegroundColor = ConsoleColor::Green;
		Console::SetCursorPosition(x, y + 0); cout << " *** ";
		Console::SetCursorPosition(x, y + 1); cout << "** **";
		Console::SetCursorPosition(x, y + 2); cout << "** **";
		Console::SetCursorPosition(x, y + 3); cout << " *** ";
	}

};