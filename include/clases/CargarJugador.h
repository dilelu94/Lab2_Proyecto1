#ifndef CARGARJUGADOR_H_INCLUDED
#define CARGARJUGADOR_H_INCLUDED

#include "../funciones/funcionesGlobales.h"
#include "ArchivoDeportes.h"

class CargarJugador
{
private:
public:
  int Claustro();
  int Deporte();
  int NumeroDeEquipo();
  float Matricula();
  void FechaValida(Fecha &fecha);
  Fecha FechaValida();
};

int CargarJugador::Claustro()
{
  int claustro;
  do
  {
    cout << "INGRESE CLAUSTRO (1, 2, 3 o 4): ";
    cin >> claustro;

    if (claustro < 1 || claustro > 4)
    {
      textcolor(4, 0);
      separadorSimple();
      cout << "El valor de claustro debe ser 1, 2, 3 o 4. Por favor, intente nuevamente." << endl;
      separadorSimple();
      textcolor(15, 0);
    }
    else
    {
      return claustro;
    }

  } while (claustro < 1 || claustro > 4);
  return 0;
}

int CargarJugador::Deporte()
{
  ArchivoDeportes archivoDeportes("deportes.dat", "../../registros/");
  int ultimoId = archivoDeportes.ObtenerUltimoId();

  if (ultimoId == -1)
  {
    textcolor(4, 0);
    separadorSimple();
    cout << "NO HAY DEPORTES REGISTRADOS TODAVIA!!!" << endl;
    cout << "INGRESE DEPORTES ANTES DE AGREGAR JUGADORES :)" << endl;
    separadorSimple();
    textcolor(15, 0);
    system("pause");
    return -1; // Sale de la función si ultimoId es -1 y devuelve -1
  }

  int deporte;
  cout << "INGRESE DEPORTE: (Entre 1 y " << ultimoId << " tenga en cuenta los que estan dados de baja):";
  cin >> deporte;

  do
  {
    if (archivoDeportes.ExisteId(deporte) == false)
    {
      system("cls");
      textcolor(4, 0);
      separadorSimple();
      cout << "NO EXISTE DEPORTE REGISTRADO CON ESE ID" << endl;
      separadorSimple();
      textcolor(15, 0);
      separadorSimple();
      cout << "INGRESE DEPORTE: (Entre 1 y " << ultimoId << "):" << endl;
      separadorSimple();
      cin >> deporte;
    }
    else
    {//validar tambien que el deporte tenga estado = true
      if (archivoDeportes.ObtenerEstado(archivoDeportes.ObtenerPosicion(deporte)) == false)
      {
        system("cls");
        textcolor(4, 0);
        separadorSimple();
        cout << "EL DEPORTE INGRESADO ESTA DADO DE BAJA" << endl;
        separadorSimple();
        textcolor(15, 0);
        separadorSimple();
        cout << "INGRESE DEPORTE: (Entre 1 y " << ultimoId << ", VERIFIQUE LOS DEPORTES DADOS DE BAJA):" << endl;
        separadorSimple();
        cin >> deporte;
      }
      else
      {
        return deporte;
      }
      
    }

  } while (archivoDeportes.ExisteId(deporte) == false && ultimoId != -1);

  return 0;
}

int CargarJugador::NumeroDeEquipo()
{
  int numeroDeEquipo;
  do
  {
    cout << "INGRESE NUMERO DE EQUIPO: ";
    cin >> numeroDeEquipo;

    if (numeroDeEquipo < 1)
    {
      textcolor(4, 0);
      separadorSimple();
      cout << "El valor de numero de equipo debe ser mayor a 0. Por favor, intente nuevamente." << endl;
      separadorSimple();
      textcolor(15, 0);
    }
    else
    {
      return numeroDeEquipo;
    }
  } while (numeroDeEquipo < 1);
  return 0; // Nunca se va a ejecutar esta linea, pero hay un warning que me molestaba mucho si no pongo esto.
}

float CargarJugador::Matricula()
{
  float matricula;
  do
  {
    cout << "INGRESE MATRICULA: ";
    cin >> matricula;

    if (matricula < 0)
    {
      textcolor(4, 0);
      separadorSimple();
      cout << "El valor de matricula debe ser mayor o igual a 0. Por favor, intente nuevamente." << endl;
      separadorSimple();
      textcolor(15, 0);
    }
    else
    {
      return matricula;
    }
  } while (matricula < 0);
  return 0;
}

Fecha CargarJugador::FechaValida()
{
  Fecha fecha;
  bool fechaValida = false;

  while (!fechaValida)
  {
    fecha.Cargar();

    // Obtener la fecha actual
    time_t tiempoActual = time(nullptr);
    tm *fechaActual = localtime(&tiempoActual);

    // Verificar si la fecha ingresada es igual o anterior a la fecha actual
    if (fecha.getAnio() > fechaActual->tm_year + 1900 ||                                                                                        // Año futuro
        (fecha.getAnio() == fechaActual->tm_year + 1900 && fecha.getMes() > fechaActual->tm_mon + 1) ||                                         // Mismo año pero mes futuro
        (fecha.getAnio() == fechaActual->tm_year + 1900 && fecha.getMes() == fechaActual->tm_mon + 1 && fecha.getDia() > fechaActual->tm_mday)) // Mismo año y mes pero día futuro
    {
      textcolor(4, 0);
      separadorSimple();
      cout << "La fecha ingresada es mayor que la fecha actual. Inténtelo de nuevo." << endl;
      separadorSimple();
      textcolor(15, 0);
    }
    else
    {
      fechaValida = true;
    }
  }
  return fecha;
}

#endif // CARGARJUGADOR_H_INCLUDED
