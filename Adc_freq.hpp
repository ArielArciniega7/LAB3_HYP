/***************************************************************************************************
 // FileName:        Adc_freq.hpp
 // Program version: Dev-C++ 5.11
 // Company:         TECNM - ITCH
 // Description:     Laboratorio_3 Configuracion ADC
 // Authors:         ERNESTO ARIEL ARCINIEGA RIVERA 19060765
 // Updated:         3/10/2022
 // Version: 		 1.0
 **************************************************************************************************/
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
