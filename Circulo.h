#pragma once
#include<iostream>
#include<conio.h>
#include<time.h>
#include<vector>

using namespace std;
using namespace System;

//WIDTH = ANCHO
//HEITH = LARGO

#define WIDTH 120
#define HEIGHT 40

class Circulo {
protected:
	int x, y, dx, dy, width, height, ID;
public:
	Circulo() {}

	void move() {
		//Esto es un movimiento en rebote de pantalla
		if (x + dx < 0 || x + dx + width > WIDTH)
			dx *= -1;
		if (y + dy < 0 || y + dy + height > HEIGHT)
			dy *= -1;

		//Update X e Y
		x += dx;
		y += dy;
	}

	void clear() {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				Console::SetCursorPosition(x + j, y + i);
				cout << " ";
			}
		}

	}
	//El dibujar como polimorfismo ( Esto hace que el metodo dibujar solamente se declare para poder llamarlo pero se desarrola en cada una de las clases q una crea)
	//Declaramos un metodo con nombre igual pero con forma de actuar (codigo) distinta
	virtual void draw() {} // Polimorfismo porque el DRAW es diferente para todos

	int getID() { return ID; }
	int getX() { return x; }
	int getY() { return y; }
	int getWIDTH() { return width; }
	int getHeight() { return height; }





};