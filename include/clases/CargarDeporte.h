#ifndef CARGARDEPORTE_H_INCLUDED
#define CARGARDEPORTE_H_INCLUDED

#include <cstring>
#include <ctime>

#include "../funciones/funcionesGlobales.h"

class CargarDeporte
{
private:
public:
  /* int Id(); */
  void Nombre(char nombre[30], int tam);
  int Tipo();
  int AnioDeOrigen();
};

/* int CargarDeporte::Id()
{
  ArchivoDeportes archivoDeportes;
  int ultimoId = archivoDeportes.ObtenerUltimoId();
  if (ultimoId == -1)
  {
    cout << "No se encontraron registros en el archivo. Se generará un nuevo ID igual a 1." << endl;
    return 1;
  }
  int nuevoId = ultimoId + 1;
  return nuevoId;
}
 */

void CargarDeporte::Nombre(char nombre[30], int tam)
{
  cout << "INGRESE NOMBRE: ";
  cargarCadena(nombre, tam);
}

int CargarDeporte::Tipo()
{
  int tipo;
  cout << "INGRESE TIPO: ";
  cin >> tipo;

  while (tipo < 1 || tipo > 21)
  {
    textcolor(4, 0);
    separadorSimple();
    cout << "Tipo invalido. Ingrese un tipo valido: " << endl;
    separadorSimple();
    textcolor(15, 0);
    cin >> tipo;
  }

  return tipo;
}

int CargarDeporte::AnioDeOrigen()
{
  int anioDeOrigen;
  cout << "INGRESE ANIO DE ORIGEN: ";
  cin >> anioDeOrigen;

  // obtener anio actual
  time_t tiempoActual = time(nullptr);
  tm *fechaActual = localtime(&tiempoActual);
  int anioActual = fechaActual->tm_year + 1900;

  while (anioDeOrigen < 1800 || anioDeOrigen > anioActual)
  {
    textcolor(4, 0);
    separadorSimple();
    cout << "Anio de origen invalido. Ingrese un anio valido: " << endl;
    separadorSimple();
    textcolor(15, 0);
    cin >> anioDeOrigen;
  }

  return anioDeOrigen;
}


#endif // CARGARDEPORTE_H_INCLUDED