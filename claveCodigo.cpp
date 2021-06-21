#include <iostream>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <string.h>
#include <string>  

using namespace std;




int validaCadena(string cadena)
{
	int i;
	for (int i = 0; i < cadena.length(); i++)
	{
		if (!(cadena[i] >= 65 && cadena[i] <= 90 || cadena[i] >= 97 && cadena[i] <= 122)) {
			cout << "solo ingresa caracteres" << endl;
			return 0;
		}
	}
	return 1;
}

int validaSoloRyA(string cadena)
{
	int i;
	for (int i = 0; i < cadena.length(); i++)
	{
		if (!(cadena[i] == 'A' || cadena[i] =='R')) {
			cout << "solo A o R" << endl;
			return 0;
		}
	}
	return 1;
}

double ObtienenumeroDecimal(string cadena)
{
	
	string mensaje="hola";
	double nuemroDecimal=0 ;
	string numeroBinario = "";
	int digitoBinario1=-1;
	int digitoBinario2=-1;
	int digitoBinario3=-1;
	int digitoBinario4=-1;
	int digitoBinario5=-1;
	

	
	if (cadena.substr(0, 3) == "ARA")digitoBinario1 = 0;
	if (cadena.substr(0, 3) == "RAR")digitoBinario1 = 1;

	if (cadena.substr(3, 3) == "ARA")digitoBinario2 = 0;
	if (cadena.substr(3, 3) == "RAR")digitoBinario2 = 1;

	if (cadena.substr(6, 3) == "ARA")digitoBinario3 = 0;
	if (cadena.substr(6, 3) == "RAR")digitoBinario3 = 1;

	if (cadena.substr(9, 3) == "ARA")digitoBinario4 = 0;
	if (cadena.substr(9, 3) == "RAR")digitoBinario4 = 1;

	if (cadena.substr(12, 3) == "ARA")digitoBinario5 = 0;
	if (cadena.substr(12, 3) == "RAR")digitoBinario5 = 1;

		
	if (digitoBinario1 == -1 || digitoBinario2 == -1 || digitoBinario3 == -1 || digitoBinario4 == -1 || digitoBinario5 == -1) {

		nuemroDecimal = 0;
	}
	else {
		numeroBinario = to_string(digitoBinario1) + to_string(digitoBinario2) + to_string(digitoBinario3) + to_string(digitoBinario4) + to_string(digitoBinario5);

		nuemroDecimal = digitoBinario1 * pow(2, 4) + digitoBinario2 * pow(2, 3) + digitoBinario3 * pow(2, 2) + digitoBinario4 * pow(2, 1) + digitoBinario5 * pow(2, 0);

	}
	
	
	return nuemroDecimal;
}


bool DeterminarSIesPrimo(int numeroBinario) {
	// Casos especiales
	if (numeroBinario == 0 || numeroBinario == 1 || numeroBinario == 4) return false;
	for (int x = 2; x < numeroBinario / 2; x++) {
		if (numeroBinario % x == 0) return false;
	}
	// Si no se pudo dividir por ninguno de los de arriba, sí es primo
	return true;
}


int  main()
{
	string cadena;
	int validacion;
	int validacionRyA;
	double numeroDecimal;
	bool esPrimo;

	do {
		do {
			cout << "ingrese 15 caracteres  solo 'A' || 'R' como clave " << endl;
			cin >> cadena;
			for (int i = 0; i < cadena.length(); i++)
			{
				cadena[i] = toupper(cadena[i]);
			}
			validacion = validaCadena(cadena);
			validacionRyA = validaSoloRyA(cadena);

		} while (validacion == 0 || validacionRyA == 0 || cadena.size() != 15);

		numeroDecimal = ObtienenumeroDecimal(cadena);
		esPrimo = DeterminarSIesPrimo(numeroDecimal);


		if (esPrimo)
		{

			cout << "clave correcta" << endl;
		}
		else
		{

			cout << "clave incorrecta" << endl;
		}

	} while (!esPrimo);
	
}



