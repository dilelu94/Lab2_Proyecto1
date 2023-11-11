#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

#include <cstring>
#include "Persona.h"
#include "Fecha.h"
#include "CargarJugador.h"

class Jugador : public Persona
{
private:
  int claustro;           // 1: docente, 2: alumno, 3: no docente, 4: graduado
  int deporte;            // Entre 1 y 10
  int numeroDeEquipo;     // entero y positivo
  Fecha fechaInscripcion; // Fecha
  float matricula;        // $
  bool estado;            // true: activo, false: inactivo
public:
  Jugador();
  ~Jugador();
  bool Cargar();
  void CargarFecha();
  void Mostrar();
  bool getEstado() { return estado; }
  void setEstado(bool estado) { this->estado = estado; }
  int getDeporte() { return deporte; }
  int getNumeroDeEquipo() { return numeroDeEquipo; }
  int getClaustro() { return claustro; }
  char *getNombrePersona() { return getNombre(); }
  char *getApellidoPersona() { return getApellido(); }
  int getDNIPersona() { return getDNI(); }
  Fecha getFechaInscripcion() { return fechaInscripcion; }

};

Jugador::Jugador()
{
  claustro = 0;
  deporte = 0;
  numeroDeEquipo = 0;
  matricula = 0;
  estado = true;
}

Jugador::~Jugador()
{

}

bool Jugador::Cargar()
{
  if (!Persona::Cargar())
  {
    return false;
  }
  CargarJugador cargar;
  claustro = cargar.Claustro();
  deporte = cargar.Deporte();
  if (deporte == -1)
  {
    return false;
  }
  numeroDeEquipo = cargar.NumeroDeEquipo();
  fechaInscripcion = cargar.FechaValida();
  matricula = cargar.Matricula();
  return true;
}

void Jugador::CargarFecha()
{
  CargarJugador cargar;
  fechaInscripcion = cargar.FechaValida();
}

void Jugador::Mostrar()
{
  Persona::Mostrar();
  cout << "CLAUSTRO: " << claustro << endl;
  cout << "DEPORTE: " << deporte << endl;
  cout << "NUMERO DE EQUIPO: " << numeroDeEquipo << endl;
  cout << "FECHA DE INSCRIPCION: ";
  fechaInscripcion.mostrarEnLinea();
  cout << "MATRICULA: " << matricula << endl;
}

#endif // JUGADOR_H_INCLUDED