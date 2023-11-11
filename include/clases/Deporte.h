#ifndef DEPORTE_H_INCLUDED
#define DEPORTE_H_INCLUDED

#include <cstring>

#include "ArchivoDeportes.h"
#include "CargarDeporte.h"

class Deporte
{
private:
  int id; // automatico +1
  char nombre[30];
  int tipo;         // (1 - 21) tipo de pais dice en el pdf???
  int anioDeOrigen; // (1800 - actual)
  bool estado;      // true: activo, false: inactivo
public:
  Deporte();
  ~Deporte();
  void Cargar();
  void Mostrar();
  bool getEstado() { return estado; }
  void setEstado(bool estado) { this->estado = estado; }
  void setId(int id) { this->id = id; }
  void setAnioDeOrigen(int anioDeOrigen) { this->anioDeOrigen = anioDeOrigen; }
  int getId() { return id; }
  int getTipo() { return tipo; }
  int getAnioDeOrigen() { return anioDeOrigen; }
  bool GuardarDeporte();
};

Deporte::Deporte()
{
  id = 0;
  strcpy(nombre, "Sin Nombre");
  tipo = 0;
  anioDeOrigen = 0;
  estado = true;
}

Deporte::~Deporte()
{

}

void Deporte::Cargar()
{
  CargarDeporte cargar;
  cargar.Nombre(nombre, 30);
  tipo = cargar.Tipo();
  anioDeOrigen = cargar.AnioDeOrigen();
}

void Deporte::Mostrar()
{
  cout << "ID: " << id << endl;
  cout << "NOMBRE: " << nombre << endl;
  cout << "TIPO: " << tipo << endl;
  cout << "ANIO DE ORIGEN: " << anioDeOrigen << endl;
}

#endif // DEPORTE_H_INCLUDED