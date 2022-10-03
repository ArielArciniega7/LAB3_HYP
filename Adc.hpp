#pragma once
#include <iostream>
#include <string>
#define VREF 3.3;

using namespace std;


//Creacion de la clase padre
class Adc{
	private: //ATRIBUTOS
		string _nombre;
		float _volts; //voltaje
		float _dato; //guarda valor digital
		float _freq;
		int _ack;
		static int _reso;
	public: //METODOS
		Adc(); //CONSTRUCTOR
		void captura(); //nombra el canal 
		void print(); //define el canal
		void lectura(); //conversion digital
		virtual void Freq_muestreo(int); //metodo poliformico
		static void setReso();
		void mostrarDatos();
		int getAck(); //getter
};
