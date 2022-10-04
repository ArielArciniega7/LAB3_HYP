/***************************************************************************************************
 // FileName:        main.cpp
 // Program version: Dev-C++ 5.11
 // Company:         TECNM - ITCH
 // Description:     Laboratorio_3 Configuracion ADC
 // Authors:         ERNESTO ARIEL ARCINIEGA RIVERA 19060765
 // Updated:         3/10/2022
 // Version: 		 1.0
 **************************************************************************************************/
#include <iostream>
#include "Adc.hpp"
#include "Adc_freq.hpp"

/*VARIABLES GLOBALES*/
int Adc::_reso=0;

	
/*FUNCION MAIN*/

int main() {
	int n,i,x;
	int y;
	cout<<"CONFIGURACION DE UN ADC"<<endl;
	cout<<"SELECCIONE LA FORMA DE OBTENER FRECUENCIA"<<endl;
	cout<<"PARA INTRODUCIRLA USTED MISMO (1) PARA CALCULARLA (2): "; //Menu para elegir
	cin>>x;
	if(x>2 ||  x<1 ){	//VALIDACION DE LA ENTRADA DEL MENU
		cout<<"NUMERO INVALIDO DE MENU"<<endl;
		exit(0);
	}
	
	cout<<"Introduce el numero de canales a leer: "; //INTRODUCIR NUMERO DE CANALES
	cin>>n;
	if(n ==false){
		cout<<"Numero invalido"<<endl;
		exit(0);
	}
	Adc::setReso(); //METODO ESTATICO PARA ESTABLECER LA RESOLUCION
	
	if(x==1){	//OPCION 1 DEL MENU
		cout<<"Introduza el valor de frecuencia de muestreo: ";
		cin>>y;
		if(y ==false){ //VALIDACION DE DATOS
			cout<<"Numero invalido"<<endl;
			exit(0);
		}
		
		Adc c[n]; 	//CREACION DE UN ARREGLO DE OBJETOS PADRE
		for(i=0;i<n;i++){	 //FOR PARA LA CAPTURA Y USAR EL METODO POLIMORFICO
			c[i].captura();
			c[i].Freq_muestreo(y);	//METODO POLIMORFICO
		}
	
		for(i=0;i<n;i++){ //Impresion de datos para definir canales
			c[i].print();	
		}
	
		for(i=0;i<n;i++){ //Conversion a valor digital 
			c[i].lectura();	
		}
		
		for(i=0;i<n;i++){ //Impresion de datos de los canales
			c[i].mostrarDatos();	
		}	
	}
	
	if(x==2){ //OPCION 2 DEL MENU
		cout<<"Introduza el valor de ACK: ";  //INTRODUCE VALOR DE ACK
		cin>>y;
		if(y !=2 && y !=4 && y!=8 && y!= 16 && y!=32 && y!=64){ //validacion de datos
			cout<<"Numero invalido"<<endl;
			exit(0);
		}
		
		Adc_freq c2[n];	//CREACION DE UN ARREGLO DE OBJETOS DE LA CLASE HIJA
		for(i=0;i<n;i++){	 //DEFINICION DEL CANAL
			c2[i].captura();
			c2[i].Freq_muestreo(y);	
		}
	
		for(i=0;i<n;i++){ //Impresion de datos
			c2[i].print();	
		}
	
		for(i=0;i<n;i++){ //Conversion a valor digital
			c2[i].lectura();	
		}
		
		for(i=0;i<n;i++){ //Impresion de datos
			c2[i].mostrarDatos();	
		}	
	}
	
	return 0;
}
