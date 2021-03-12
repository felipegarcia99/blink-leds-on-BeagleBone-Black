#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <cstring>
#include <cerrno>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctime>

using namespace std;

void delay(float tempo);
void exportar_gpio(int porta);
void direction_out(int porta);
void ligar_led(int porta);
void desligar_led(int porta);

int main(){
	int led1 = 50;
	int led2 = 51;

	exportar_gpio(50);
	exportar_gpio(51);
	direction_out(50);
	direction_out(51);

	while (1){
		ligar_led(50);
		delay(0.5);
		desligar_led(50);
		ligar_led(51);
		delay(0.5);
		desligar_led(51);
	}
}


void delay(float tempo){
	usleep(tempo * 1000000);
}

void exportar_gpio(int porta){
	fstream fs;
	string portastr = to_string(porta);
	cout << "Exportando gpio" + portastr << endl;
	cout << ("cd /sys/class/gpio && echo " + portastr + " > export").c_str() << endl;
	system(("cd /sys/class/gpio && echo " + portastr + " > export").c_str());
}

void direction_out(int porta){
	fstream fs;
	string portastr = to_string(porta);
	cout << "Declarando direction out" + portastr << endl;
	//fs.open("/sys/class/gpio/gpio " + portastr + " /direction");
	fs.open("/sys/devices/platform/ocp/4804c000.gpio/gpiochip1/gpio/gpio" + portastr + "/direction");
	/*fs << "out";
	fs.close();*/
	
    if (fs.fail()) {
        cerr << "Declaração do direction falhou. Erro: " << strerror(errno) << '\n';
    } else {
        cerr << "Declaração do direction feita com sucesso\n";
        fs << "out";
		fs.close();
    }
}

void ligar_led(int porta){
	fstream fs;
	string portastr = to_string(porta);
	//cout << "Ligando led" + portastr << endl;
	//fs.open("/sys/class/gpio/gpio " + portastr + " /value");
	fs.open("/sys/devices/platform/ocp/4804c000.gpio/gpiochip1/gpio/gpio" + portastr + "/value");
	fs << "1";
	fs.close();
}

void desligar_led(int porta){
	fstream fs;
	string portastr = to_string(porta);
	//cout << "Desligando led" + portastr << endl;
	fs.open("/sys/devices/platform/ocp/4804c000.gpio/gpiochip1/gpio/gpio" + portastr + "/value");
	fs << "0";
	fs.close();
}
