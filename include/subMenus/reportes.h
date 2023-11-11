#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

#include <cstring>

#include "../funciones/funcionesGlobales.h"

#include "../clases/ArchivoJugadores.h"
#include "../clases/Jugador.h"

#include "../clases/ArchivoDeportes.h"
#include "../clases/Deporte.h"

class NoDocentes
{
public:
  int dni;
  char nombre[30];
  char apellido[30];
  Fecha fechaInscripcion;

NoDocentes(int dni = 0, const char nombre[30] = "omitido", const char apellido[30] = "omitido", const Fecha &fechaInscripcion = Fecha())
    : dni(dni), fechaInscripcion(fechaInscripcion)
{
    strncpy(this->nombre, nombre, 30);
    this->nombre[29] = '\0';

    strncpy(this->apellido, apellido, 30);
    this->apellido[29] = '\0';
}
  void escribirEnArchivo()
  {
    FILE *p = fopen("../../registros/jugadores_no_docentes.dat", "ab");
    if (p == NULL)
    {
      cout << "ERROR AL ABRIR EL ARCHIVO JUGADORES NO DOCENTES" << endl;
      return;
    }
    fwrite(this, sizeof(NoDocentes), 1, p);
    fclose(p);
  }
};

class Reportes
{
private:
public:
  bool MostrarMenu();
};

// Listar la cantidad de jugadores inscriptos en cada uno de los deportes
void contarJugadoresDeCadaDeporte()
{
  FILE *p = fopen("../../registros/jugadores.dat", "rb");
  if (p == NULL)
  {
    cout << "ERROR AL ABRIR EL ARCHIVO JUGADORES" << endl;
    return;
  }
  Jugador registro;
  int cont[21] = {0};
  while (fread(&registro, sizeof(Jugador), 1, p))
  {
    if (registro.getEstado())
    {
      cont[registro.getDeporte() - 1]++;
    }
  }
  fclose(p);
  for (int i = 0; i < 21; i++)
  {
    if (cont[i] > 0)
    {
      cout << "DEPORTE: " << i + 1 << " CANTIDAD: " << cont[i] << endl;
    }
  }
}

// Generar un archivo con los no docentes que participan de equipos cuyos números sean menores a 15. Cada registro del archivo nuevo debe tener el siguiente formato:
// DNI, nombre, apellido y fecha de inscripción

void generarArchivoNoDocentes()
{
  FILE *p = fopen("../../registros/jugadores.dat", "rb");
  FILE *archivoSalida = fopen("jugadores_no_docentes.bin", "wb");

  if (p == NULL || archivoSalida == NULL)
  {
    cout << "ERROR AL ABRIR EL ARCHIVO JUGADORES O ARCHIVO DE SALIDA" << endl;
    return;
  }

  Jugador registro;
  while (fread(&registro, sizeof(Jugador), 1, p))
  {
    if (registro.getEstado() && registro.getNumeroDeEquipo() < 15 && registro.getClaustro() == 3)
    {
      NoDocentes noDocente(
          registro.getDNIPersona(),
          registro.getNombre(),
          registro.getApellido(),
          registro.getFechaInscripcion());
      noDocente.escribirEnArchivo();
    }
  }
  system("cls");
  textcolor(2, 0);
  separadorSimple();
  cout << "ARCHIVO GENERADO CON EXITO" << endl;
  separadorSimple();
  textcolor(15, 0);

  fclose(p);
  fclose(archivoSalida);
}

bool Reportes::MostrarMenu()
{
  int opcion;
  while (true)
  {
    system("cls");
    separadorDoble();
    cout << "\t MENU REPORTES" << endl;
    separadorDoble();
    cout << endl;
    cout << "1. JUGADORES INSCRIPTOS EN CADA DEPORTE" << endl;
    cout << "2. GENERAR ARCHIVO NO DOCENTES EQUIPO MENOR A 15" << endl;
    separadorSimple();
    cout << "0. VOLVER AL MENU PRINCIPAL" << endl;
    cout << endl;
    cout << "OPCION: ";
    cin >> opcion;
    system("cls");
    switch (opcion)
    {
    case 1:
      textcolor(14, 0);
      separadorSimple();
      cout << "JUGADORES INSCRIPTOS EN CADA DEPORTE" << endl;
      separadorSimple();
      textcolor(15, 0);
      contarJugadoresDeCadaDeporte();
      system("pause");
      break;
    case 2:
      textcolor(14, 0);
      separadorSimple();
      cout << "OPCION 2:" << endl;
      separadorSimple();
      textcolor(15, 0);
      generarArchivoNoDocentes();
      system("pause");
      break;
    case 0:
      return 0;
      break;
    default:
      cout << "OPCION INCORRECTA" << endl;
      system("pause");
      break;
    }

    return true;
  }
}
#endif // REPORTES_H_INCLUDED