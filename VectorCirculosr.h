#pragma once
#include "Circulo.h"
#include "CAmarillo.h"
#include "CRojo.h"
#include "CVerde.h"
#include "Personaje.h"

//WIDTH = ANCHO
//HEITH = LARGO

class VectorCIRCULOS { // Paso 1 para personaje 
protected:
	vector<Circulo*>vCirculos; // Paso 1 para Circulo
	Personaje* oPersonaje; // Paso 2 para personaje

public:


	VectorCIRCULOS() { // Paso 3 para personaje
		oPersonaje = new Personaje();
	}

	void drawPersonaje() { // Paso 4 para personaje
		oPersonaje->drawP();
	}

	void clearPersonaje() { // Paso 5 para personaje
		oPersonaje->clearP();
	}

	void movePersonaje(char tecla) { // Paso 6 para personaje
		oPersonaje->moveP(tecla);
	}


	void generarCirculos() { // Paso 2 para circulo
		for (int i = 0; i < 3; i++) {
			vCirculos.push_back(new CRojo()); // 10 porque es el doble de 5 (width de rojo) y 8 porque es el doble de 4 (height de rojo)
		}

		for (int i = 0; i < 6; i++) {
			vCirculos.push_back(new CVerde()); //10 porque es el doble de 5 (width de verde) y 8 porque es el doble de 4 (height de verde)
		}

	}

	void drawALL() {
		for (int i = 0; i < vCirculos.size(); i++) {
			vCirculos[i]->draw();
		}
	}

	void moveAll() {
		for (int i = 0; i < vCirculos.size(); i++) {
			vCirculos[i]->move();
		}
	}

	void clearAll() {
		for (int i = 0; i < vCirculos.size(); i++) {
			vCirculos[i]->clear();
		}
	}

	void ColisionRojo_Verde() { // Colision Rojo con Verde
		if (vCirculos.size() >= 2) {
			for (int i = 0; i < vCirculos.size() - 1; i++)
			{
				for (int j = i + 1; j < vCirculos.size(); j++)
				{
					if (vCirculos[i]->getID() == 2 && vCirculos[j]->getID() == 3 ||
						vCirculos[i]->getID() == 3 && vCirculos[i]->getID() == 2) // COmprueba si es verde o Rojo || o Rojo y verde
					{
						int x1 = vCirculos[i]->getX();
						int y1 = vCirculos[i]->getY();
						int w1 = vCirculos[i]->getWIDTH();
						int h1 = vCirculos[i]->getHeight();

						int x2 = vCirculos[j]->getX();
						int y2 = vCirculos[j]->getY();
						int w2 = vCirculos[j]->getWIDTH();
						int h2 = vCirculos[j]->getHeight();

						if (!(x1 + w1<x2 || x1>x2 + w2 || y1 + h1<y2 || y1>y2 + h2))
						{
							vCirculos[i]->clear();
							vCirculos[j]->clear();
							vCirculos.erase(vCirculos.begin() + i);
							vCirculos.erase(vCirculos.begin() + (j - 1));
							vCirculos.push_back(new CAmarillo(x1, y1));

						}

					}
				}
			}
		}
	}

	//Colision CRojo_Personaje PIERDO VIDAS
	void colisionCRojo_Personaje() {
		if (vCirculos.size() >= 1) {
			for (int i = 0; i < vCirculos.size(); i++)
			{
				if (vCirculos[i]->getID() == 2) {
					int x1 = vCirculos[i]->getX();
					int y1 = vCirculos[i]->getY();
					int w1 = vCirculos[i]->getWIDTH();
					int h1 = vCirculos[i]->getHeight();

					int x2 = oPersonaje->getX();
					int y2 = oPersonaje->getY();
					int w2 = oPersonaje->getWidth();
					int h2 = oPersonaje->getHeight();

					if (!(x1 + w1<x2 || x1>x2 + w2 || y1 + h1<y2 || y1>y2 + h2)) {
						oPersonaje->clearP();
						oPersonaje->pierdeVidas();
					}
				}
			}
		}
	}

	//Colision CVerde_Personaje GANO VIDAS
	void colisionCVerde_Personaje() {
		if (vCirculos.size() >= 1) {
			for (int i = 0; i < vCirculos.size(); i++) 
			{
				if (vCirculos[i]->getID() == 3) {
					int x1 = vCirculos[i]->getX();
					int y1 = vCirculos[i]->getY();
					int w1 = vCirculos[i]->getWIDTH();
					int h1 = vCirculos[i]->getHeight();

					int x2 = oPersonaje->getX();
					int y2 = oPersonaje->getY();
					int w2 = oPersonaje->getWidth();
					int h2 = oPersonaje->getHeight();

					if (!(x1 + w1<x2 || x1>x2 + w2 || y1 + h1<y2 || y1>y2 + h2)) {
						oPersonaje->ganaVidas();
						vCirculos[i]->clear();
						vCirculos.erase(vCirculos.begin() + i);
					}
				}
			}
		}
	}

	//Colisiona con circulo amarillo y gana monedas y rebota
	void colisionAmarillo_Personaje() {
		if (vCirculos.size() >= 1) {
			for (int i = 0; i < vCirculos.size(); i++) {
				if (vCirculos[i]->getID() == 1) {
					int x1 = vCirculos[i]->getX();
					int y1 = vCirculos[i]->getY();
					int w1 = vCirculos[i]->getWIDTH();
					int h1 = vCirculos[i]->getHeight();

					int x2 = oPersonaje->getX();
					int y2 = oPersonaje->getY();
					int w2 = oPersonaje->getWidth();
					int h2 = oPersonaje->getHeight();

					if (!(x1 + w1<x2 || x1>x2 + w2 || y1 + h1<y2 || y1>y2 + h2)) {
						oPersonaje->ganaModenas();
						((CAmarillo*)vCirculos[i])->rebound();

					}
				}
			}
		}
	}

	int lookVidas() { return oPersonaje->getVidas(); }
	int lookMonedas() { return oPersonaje->getMonedas(); }

};