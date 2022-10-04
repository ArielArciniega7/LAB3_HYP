/***************************************************************************************************
 // FileName:        Adc_freq.cpp
 // Program version: Dev-C++ 5.11
 // Company:         TECNM - ITCH
 // Description:     Laboratorio_3 Configuracion ADC
 // Authors:         ERNESTO ARIEL ARCINIEGA RIVERA 19060765
 // Updated:         3/10/2022
 // Version: 		 1.0
 **************************************************************************************************/
#include "Adc_freq.hpp"
//constructor 
Adc_freq::Adc_freq(){
	
}
//metodo polimorfico

void Adc_freq::Freq_muestreo(int freq){
	Adc::Freq_muestreo(freq);
	_ack2=Adc::getAck();
	cout<<"CALCULANDO EL FS..."<<endl;
	_ack2 = (8000000/_ack2);
	Adc::Freq_muestreo(_ack2);
}

