/*
	Nombre del archivo:    ADC.hpp
	Version del programa:  Dev-C++ 5.11.
	Escuela:			   TecNM campus Chihuahua.
	Descripcion:           Declaraci�n de clase para la creaci�n de objetos ADC.
	Autor:      	       Ivan Urbina.
					       V 1.0
*/

#pragma once
#include <iostream>

using namespace std;

class ADC
{
	private:
		static unsigned int rs;		//Resoluci�n 8,10 o 12v
		static  float hz;			//Frecuencia de muestreo
		float v;					//Voltaje a convertir 0-3.3v
		unsigned int o;				//Salida en bits seg�n resoluci�n
		short name;
	
	public:
		Canal(){};					//Constructor por defecto
//------------------------------------------SETTERS------------------------------------------
		static void resolucion (int);
		static void frecuencia(float);
		void captura (float);
		void setname(short);
//------------------------------------------GETTERS------------------------------------------		
		static float getf();
		unsigned int conversion();
		short getname();
};

