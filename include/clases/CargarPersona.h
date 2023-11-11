#ifndef CARGARPERSONA_H_INCLUDED
#define CARGARPERSONA_H_INCLUDED

#include "ArchivoJugadores.h"

class CargarPersona
{
private:
public:
  bool Nombre(char *nombre, int tam);
  bool Apellido(char *apellido, int tam);
  bool Email(char *email, int tam);
  bool NumeroDeTelefono(char *numero, int tam);
  bool DNI();
};

bool CargarPersona::Nombre(char *nombre, int tam)
{
  cout << "INGRESE NOMBRE: ";
  cargarCadena(nombre, tam);
  if (nombre[0] < 65 || nombre[0] > 90) // ascii 65 = A, 90 = Z
  {
    textcolor(4, 0);
    separadorSimple();
    cout << "EL NOMBRE DEBE COMENZAR CON MAYUSCULA" << endl;
    separadorSimple();
    textcolor(15, 0);
    cout << endl;
    cout << "1. PARA INTENTAR NUEVAMENTE" << endl;
    cout << "0. PARA VOLVER" << endl;
    int opcion;
    cin >> opcion;
    if (opcion == 1)
    {
      return Nombre(nombre, tam);
    }
    else
    {
      return false;
    }
  }
  return true;
}

bool CargarPersona::Apellido(char *apellido, int tam)
{
  cout << "INGRESE APELLIDO: ";
  cargarCadena(apellido, tam);
  if (apellido[0] < 65 || apellido[0] > 90)
  {
    textcolor(4, 0);
    separadorSimple();
    cout << "EL APELLIDO DEBE COMENZAR CON MAYUSCULA" << endl;
    separadorSimple();
    textcolor(15, 0);
    cout << endl;
    cout << "1. PARA INTENTAR NUEVAMENTE" << endl;
    cout << "0. PARA VOLVER" << endl;
    int opcion;
    cin >> opcion;
    if (opcion == 1)
    {
      return Apellido(apellido, tam);
    }
    else
    {
      return false;
    }
  }
  return true;
}

bool CargarPersona::Email(char *email, int tam) // sin validaciones todavia
{
  cout << "INGRESE EMAIL: ";
  cargarCadena(email, tam);
  return true;
}

bool CargarPersona::NumeroDeTelefono(char *numero, int tam)
{
  cout << "INGRESE NUMERO DE TELEFONO: ";
  cargarCadena(numero, tam);
  if (strlen(numero) < 8)
  {
    textcolor(4, 0);
    separadorSimple();
    cout << "EL NUMERO DEBE TENER AL MENOS 8 DIGITOS" << endl;
    separadorSimple();
    textcolor(15, 0);
    cout << endl;
    cout << "1. PARA INTENTAR NUEVAMENTE" << endl;
    cout << "0. PARA VOLVER" << endl;
    int opcion;
    cin >> opcion;
    if (opcion == 1)
    {
      return NumeroDeTelefono(numero, tam);
    }
    else
    {
      return false;
    }
  }
  return true;
}

//no puedo incluir ArchivoJugadores.h porque me da error de que no esta incluida cuando si lo hago xd
/* bool CargarPersona::DNI()
{
  ArchivoJugadores archivoJugador;
  int DNI;
  cout << "INGRESE DNI: ";
  cin >> DNI;
  bool existe = archivoJugador.ExisteDNI();
  if (existe)
  {
    cout << "El DNI ingresado ya existe" << endl;
    return false;
  }
  return false;
} */

#endif // CARGARPERSONA_H_INCLUDED