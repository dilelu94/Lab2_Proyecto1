#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED

#include "ArchivoJugadores.h"
#include "ArchivoDeportes.h"

class Configuracion
{
private:
public:
  void CopiaDeSeguridadJugadores();
  void CopiaDeSeguridadDeportes();
  void RestaurarBackUpJugadores();
  void RestaurarBackUpDeportes();
  void RestablecerDatosDeInicio();
};

void Configuracion::CopiaDeSeguridadJugadores()
{
  ArchivoJugadores archivoJugador;
  bool exito = archivoJugador.CopiaDeSeguridad();
  if (exito)
  {
    textcolor(2, 0);
    separadorSimple();
    cout << "COPIA DE SEGURIDAD REALIZADA CON EXITO" << endl;
    separadorSimple();
    textcolor(15, 0);
  }
  else
  {
    textcolor(4, 0);
    separadorSimple();
    cout << "ERROR AL REALIZAR LA COPIA DE SEGURIDAD" << endl;
    separadorSimple();
    textcolor(15, 0);
  }
}

void Configuracion::CopiaDeSeguridadDeportes()
{
  ArchivoDeportes archivoDeportes;
  bool exito = archivoDeportes.CopiaDeSeguridad();
  if (exito)
  {
    textcolor(2, 0);
    separadorSimple();
    cout << "COPIA DE SEGURIDAD REALIZADA CON EXITO" << endl;
    separadorSimple();
    textcolor(15, 0);
  }
  else
  {
    textcolor(4, 0);
    separadorSimple();
    cout << "ERROR AL REALIZAR LA COPIA DE SEGURIDAD" << endl;
    separadorSimple();
    textcolor(15, 0);
  }
}

void Configuracion::RestaurarBackUpJugadores()
{
  ArchivoJugadores archivoJugador;
  bool exito = archivoJugador.RestaurarBackUp();
  if (exito)
  {
    textcolor(2, 0);
    separadorSimple();
    cout << "ARCHIVO RESTAURADO CON EXITO" << endl;
    separadorSimple();
    textcolor(15, 0);
  }
  else
  {
    textcolor(4, 0);
    separadorSimple();
    cout << "ERROR AL RESTAURAR EL ARCHIVO" << endl;
    separadorSimple();
    textcolor(15, 0);
  }
}

void Configuracion::RestaurarBackUpDeportes()
{
  ArchivoDeportes archivoDeportes;
  bool exito = archivoDeportes.RestaurarBackUp();
  if (exito)
  {
    textcolor(2, 0);
    separadorSimple();
    cout << "ARCHIVO RESTAURADO CON EXITO" << endl;
    separadorSimple();
    textcolor(15, 0);
  }
  else
  {
    textcolor(4, 0);
    separadorSimple();
    cout << "ERROR AL RESTAURAR EL ARCHIVO" << endl;
    separadorSimple();
    textcolor(15, 0);
  }
}

void Configuracion::RestablecerDatosDeInicio()
{
  ArchivoJugadores archivoJugador;
  ArchivoDeportes archivoDeportes;
  bool exito = archivoJugador.RestablecerDatosDeInicio() && archivoDeportes.RestablecerDatosDeInicio();
  if (exito)
  {
    textcolor(2, 0);
    separadorSimple();
    cout << "ARCHIVOS RESTABLECIDOS CON EXITO" << endl;
    separadorSimple();
    textcolor(15, 0);
  }
  else
  {
    textcolor(4, 0);
    separadorSimple();
    cout << "ERROR AL RESTABLECER LOS ARCHIVOS" << endl;
    separadorSimple();
    textcolor(15, 0);
  }
}

#endif // CONFIGURACION_H_INCLUDED