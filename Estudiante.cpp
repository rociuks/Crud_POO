#include "Persona.cpp"
#include <iostream>

using namespace std;

class Estudiante : Persona {
private: string cod;
	   // constructor
public:
	Estudiante() {
	}
	Estudiante(string nom, string ape, string dir, int tel, string c) : Persona(nom, ape, dir, tel) {
		cod = c;
	}

	// METODOS
	//set (modificar)
	void setCod(string c) { cod = c; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }

	//get (mostrar)
	string getCod() { return cod; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
		
};
