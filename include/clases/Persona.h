#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

/* #pragma once */

#include <cstring>

#include "CargarPersona.h"
#include "..\funciones\funcionesGlobales.h"

/* #include "ArchivoJugadores.h" */

class Persona
{
private:
  char nombre[30], apellido[30];
  char email[30], telefono[30];
  int DNI;

public:
  Persona();
  ~Persona();
  bool Cargar();
  void Mostrar();
  void setNombre(char *nombre) { strcpy(this->nombre, nombre); }
  void setApellido(char *apellido) { strcpy(this->apellido, apellido); }
  void setEmail(char *email) { strcpy(this->email, email); }
  void setTelefono(char *telefono) { strcpy(this->telefono, telefono); }
  void setDNI(int DNI) { this->DNI = DNI; }
  char *getNombre() { return nombre; }
  char *getApellido() { return apellido; }
  char *getEmail() { return email; }
  char *getTelefono() { return telefono; }
  int getDNI() { return DNI; }
};

Persona::Persona() // Constructor
{
  strcpy(nombre, "Sin nombre");
  strcpy(apellido, "Sin apellido");
  strcpy(email, "Sin email");
  strcpy(telefono, "Sin telefono");
  DNI = 0;
}

Persona::~Persona() // Destructor
{
}

bool Persona::Cargar()
{
  CargarPersona cargar;
  if (!cargar.Nombre(nombre, 30))
  {
    return false;
  }
  if (!cargar.Apellido(apellido, 30))
  {
    return false;
  }
  if (!cargar.Email(email, 30))
  {
    return false;
  }
  if (!cargar.NumeroDeTelefono(telefono, 30))
  {
    return false;
  }

  cout << "INGRESE DNI: ";
  cin >> DNI;

  /* cargar.DNI(); */

  return true; // Si se completó la carga sin problemas, devolvemos true.
}

void Persona::Mostrar()
{
  cout << "NOMBRE: ";
  cout << nombre << endl;
  cout << "APELLIDO: ";
  cout << apellido << endl;
  cout << "EMAIL: ";
  cout << email << endl;
  cout << "TELEFONO: ";
  cout << telefono << endl;
  cout << "DNI: ";
  cout << DNI << endl;
}

#endif // PERSONA_H_INCLUDED