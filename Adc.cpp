#include "Adc.hpp"
//Constructor
Adc::Adc(){
	_nombre="";
}
/*GETTERS*/

int Adc::getAck(){
	return _ack;
}
/*SETTERS*/

void Adc::Freq_muestreo(int freq){
	_ack = freq;
}
/*METODOS GENERALES*/

void Adc::captura(){ //CAPTURA DE DATOS
	cout<<endl<<"Canal que se leera (AN1 - AN32): ";
	cin>>_nombre;
	
}

void Adc::print(){ //CANAL DEFINIDO
	cout<<"Canal definido: "<<_nombre<<endl;
}
 
void Adc::lectura(){	 //CONVERSION DIGITAL
	cout<<endl<<"Lectura analoga (0 - 3.3v) del "<<_nombre<<": ";
	cin>>_volts;
	if(_volts< 0 || _volts >3.3){
		cout<<"Lectura invalida";
		exit(0);
	}
	if(_reso==8) _dato = (_volts*255.0)/VREF;  //PARA RESOLUCION DE 8 BITS
	if(_reso==10) _dato = (_volts*1023.0)/VREF; //PARA RESOLUCION DE 10 BITS
	if(_reso==12) _dato = (_volts*4095.0)/VREF; //RESOLUCION DE 12 BITS
}

void Adc::setReso(){ //Metodo statico para establecer la resolucion
	cout<<"Resolucion del ADC (8,10,12 bits): ";
	cin>> _reso;
	if(_reso != 8 && _reso != 10 && _reso != 12){
		cout<<"Resolucion invalida";
		exit(0);
	}
}
void Adc::mostrarDatos(){ //IMPRIME DATOS
	cout<<"Canal "<<_nombre <<" recibio "<<_volts <<"v "<<" lo convirtio a " <<_dato<<" con una frecuencia de "<<_ack<<"Hz "<<endl;
}

