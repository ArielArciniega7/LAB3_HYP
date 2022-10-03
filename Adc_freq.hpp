#pragma once
#include <iostream>
#include <string>
#include "Adc.hpp"

using namespace std;

//creacion de clase hija

class Adc_freq : public Adc{
	private:
		int _ack2; //PRIVATIVO DE LA CLASE HIJA
	public:
		Adc_freq(); //constructor por oficio
		void Freq_muestreo(int); //metodo polimorfico
};
