#include "VectorCirculosr.h"

int main() {
	Console::SetWindowSize(WIDTH, HEIGHT);
	Console::CursorVisible = false;
	srand(time(NULL));

	VectorCIRCULOS* obj = new VectorCIRCULOS();

	obj->generarCirculos();
	int v,m, tecla;

	do {
		obj->clearPersonaje(); // CLEAR
		if (kbhit()) {
			tecla = getch();
			if (tecla == 224) {
				tecla = getch();
				obj->movePersonaje(tecla); // MOVE
			}
		}
		obj->drawPersonaje();//DRAW

		obj->clearAll();
		obj->moveAll();
		obj->drawALL();

		v = obj->lookVidas();

		Console::SetCursorPosition(WIDTH - 12, HEIGHT - 2); // -9 por los caracteres que tiene "Vidas: "
		cout << "Vidas: " << v;

		m = obj->lookMonedas();

		Console::SetCursorPosition(WIDTH - 12, HEIGHT - 3); // -12 por los caracteres que tiene "Monedas "
		cout << "Monedas: " << m;

		obj->ColisionRojo_Verde();
		obj->colisionCRojo_Personaje();
		obj->colisionCVerde_Personaje();
		obj->colisionAmarillo_Personaje(); 
		_sleep(100);

	} while (v > 0);
	system("cls");
	Console::SetCursorPosition(WIDTH / 2, HEIGHT / 2); //MITAD DE LA PANTALLA
	cout << "GAME OVER";
}