#pragma once
//Colision personaje-CROJO pierde vidas
//Colision Personaje -CVerde - gana vidas
//Colision Personaje-CAmarillo el circulo rebota y gana 10 monedas
//El personaje se mueve con teclas

#include<iostream>

using namespace std;
using namespace System;
class Personaje {
private:
	int x, y, dx, dy, width, height, vidas , monedas;
public:
	Personaje() {
		
		width = 3;
		height = 4;
		x = 60;
		y = 40 - height;
		dx = 0;
		dy = 0;
		vidas = 3;
		monedas = 0;
	}

	 void drawP() {
		 Console::ForegroundColor = ConsoleColor::DarkCyan;
		 Console::SetCursorPosition(x, y + 0); cout << " ° ";
		 Console::SetCursorPosition(x, y + 1); cout << "_|_";
		 Console::SetCursorPosition(x, y + 2); cout << "_|_";
	 }

	 void clearP() {
		 for (int i = 0; i < height; i++) {
			 for (int j = 0; j < width; j++) {
				 Console::SetCursorPosition(x + j, y + i);
				 cout << " ";
			 }
		 }
	 }

	 void moveP(int tecla) {
		 switch (tecla)
		 {
		 case 72: dx = 0; dy = -1; break; //Arriba
		 case 80: dx = 0; dy = 1; break; // Abajo
		 case 75: dx = -1; dy = 0; break;//Izquierda
		 case 77: dx = 1; dy = 0; break;  //Derecha
		 }
		 //Comprobar los limites
		 if (x + dx < 0 || x + dx + width > 120)
			 dx *= -1;
		 if (y + dy < 0 || y + dy + height >40)
			 dy *= -1;

		 x += dx;
		 y += dy;

	 }

	 int getX() { return x; }
	 int getY() { return y; }
	 int getWidth() { return width; }
	 int getHeight() { return height; }
	 int getVidas() { return vidas; }
	 void ganaVidas() { vidas++; }
	 void pierdeVidas() { vidas--; x = 60; y = 40 - height; dx = 0; dy = 0; } // Pierde vidas y retorna a su posicion inicial
	 void ganaModenas() { monedas += 10; }
	int getMonedas() { return monedas; }

};