/*
	Nombre del archivo:    main.cpp
	Version del programa:  Dev-C++ 5.11.
	Escuela:			   TecNM campus Chihuahua.
	Descripcion:           Simulación de la configuración de un ADC.
	Autor:      	       Ivan Urbina.
					       V 1.0
*/

#include <iostream>
#include <stdlib.h>
#include "ADC.hpp"

using namespace std;

short i,cantidad,bits,n_canal;
float frec;
float voltaje;

int main()
{
	cout<<"Introduce el numero de canales que deseas utilizar: "<<endl;
	cin>>cantidad;
	
	do					//Validacion de datos
	{
		cout<<"Intoduce la resolucion deseada (8,10,12)"<<endl;
		cin>>bits;
		fflush(stdin);
		
		if(!(bits == 8||bits == 10||bits == 12))
			cout<<"Resolucion no permitida"<<endl;	
		
	}while(!(bits == 8||bits == 10||bits == 12));

	ADC::resolucion(bits);
	cout<<"Intoduce la frecuencia de muestreo (MHz)"<<endl;
	cin>>frec;
	ADC::resolucion(bits);
	ADC::frecuencia(frec);
	ADC canales [cantidad];		//Creacion de objetos segun los canales a usar
	

	for(i=0;i<cantidad;i++)
	{
		do 
		{
			cout<<"Introduce que canal deseas usar (1-32)"<<endl;
			cin>>n_canal;
			canales[i].setname(n_canal);
			
			if(n_canal>32||n_canal == 0)
				cout<<"No existe canal"<<endl;
				
		}while(n_canal>32||n_canal == 0);
	}

	for(i=0;i<cantidad;i++)
	{
		cout<<"Introduce el valor a medir del canal: "<<i+1<<endl;
		fflush(stdin);
		
		do					//Validacion de datos
		{
			cin>>voltaje;	//Lectura del voltaje de cada canal
			
			if(voltaje>3.3)
				cout<<"Voltaje mayor a 3.3"<<endl;
			
		}while(voltaje>3.3);
		
		canales[i].captura(voltaje);
	}
	
	for(i=0;i<cantidad;i++)		//Ciclo for para la impresion de datos
	{
		cout<<"El valor digital del canal AN"<<canales[i].getname();
		cout<<",con frecuencia de muestreo de "<<ADC::getf();
		cout<<" MHz";
		cout<<": "<<canales[i].conversion()<<endl;
	}
	return 0;
}

