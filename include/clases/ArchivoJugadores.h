#ifndef ARCHIVOJUGADORES_H_INCLUDED
#define ARCHIVOJUGADORES_H_INCLUDED

/* #pragma once */

#include <cstring>

#include "../funciones/funcionesGlobales.h"
#include "Jugador.h"

/* #include "CargarPersona.h" */

class ArchivoJugadores
{
private:
  char rutaYNombre[40];

public:
  ArchivoJugadores(const char *nombreDelArchivo, const char *ruta);
  ~ArchivoJugadores();
  bool AgregarRegistro(Jugador &reg);
  bool GuardarJugador();
  bool ListarJugadores();
  bool ExisteDNI(int dni);
  bool ListarJugadorPorDNI();
  int BuscarRegistro();
  bool ModificarFechaInscripcion(int pos);
  bool BajaLogicaJugador(int pos);
  bool CopiaDeSeguridad();
  bool RestaurarBackUp();
  bool RestablecerDatosDeInicio();
};

ArchivoJugadores::ArchivoJugadores(const char *nombreDelArchivo = "jugadores.dat", const char *ruta = "../../registros/")
{
  // Combinamos la ruta con el nombre del archivo
  strcpy(this->rutaYNombre, ruta);
  strcat(this->rutaYNombre, nombreDelArchivo);
}

ArchivoJugadores::~ArchivoJugadores()
{
}

bool ArchivoJugadores::AgregarRegistro(Jugador &reg)
{
  FILE *pJugador;
  pJugador = fopen(this->rutaYNombre, "ab");
  if (pJugador == NULL)
  {
    return false;
  }
  bool grabo = fwrite(&reg, sizeof(Jugador), 1, pJugador);
  fclose(pJugador);
  return grabo;
}

bool ArchivoJugadores::GuardarJugador()
{
  Jugador reg;
  if (!reg.Cargar())
  {
    return false;
  }
  reg.setEstado(true); // Cambiar el estado a true antes de agregar el registro

  if (ExisteDNI(reg.getDNI()))
  {
    system("cls");
    textcolor(4, 0);
    separadorSimple();
    cout << "YA EXISTE UN JUGADOR CON ESE DNI" << endl;
    separadorSimple();
    textcolor(15, 0);
    cout << "1 - PARA INGRESAR OTRA PERSONA" << endl;
    cout << "0 - PARA VOLVER AL MENU PRINCIPAL" << endl;
    int opcion;
    cin >> opcion;
    if (opcion == 1)
    {
      GuardarJugador();
    }
    else
    {
      return false;
    }
  }
  else if (AgregarRegistro(reg))
  {
    system("cls");
    textcolor(2, 0);
    separadorSimple();
    cout << "REGISTRO AGREGADO :)" << endl;
    separadorSimple();
    textcolor(15, 0);
    return true;
  }
  else
  {
    cout << "ERROR DE ARCHIVO" << endl;
    return false;
  }
  return 0;
}

bool ArchivoJugadores::ListarJugadores()
{
  FILE *pJugador;
  Jugador aux;
  pJugador = fopen(rutaYNombre, "rb");
  if (pJugador == NULL)
  {
    cout << "ERROR DE ARCHIVO" << endl;
    return false;
  }
  while (fread(&aux, sizeof(Jugador), 1, pJugador) == 1)
  {
    if (aux.getEstado() == true)
    {
      aux.Mostrar();
      cout << endl;
    }
  }
  fclose(pJugador);
  return true;
}

bool ArchivoJugadores::ExisteDNI(int dni)
{
  FILE *p;
  Jugador reg;
  bool existe = false;
  p = fopen(rutaYNombre, "rb");
  if (p == NULL)
  {
    cout << "DNI ERROR DE ARCHIVO" << endl;
    return false;
  }
  while (fread(&reg, sizeof(Jugador), 1, p) == 1)
  {
    if (reg.getDNI() == dni)
    {
      existe = true;
      break; // Se encontró un registro con el mismo DNI, no es necesario continuar la búsqueda.
    }
  }
  fclose(p);
  return existe;
}

bool ArchivoJugadores::ListarJugadorPorDNI()
{
  FILE *pJugador;
  Jugador aux;
  pJugador = fopen(rutaYNombre, "rb");
  if (pJugador == NULL)
  {
    cout << "ERROR DE ARCHIVO" << endl;
    return false;
  }
  int dni;
  cout << "INGRESE DNI A BUSCAR: ";
  cin >> dni;
  system("cls");
  textcolor(14, 0);
  separadorSimple();
  cout << "RESULTADO DE LA BUSQUEDA: " << endl;
  separadorSimple();
  textcolor(15, 0);
  bool encontrado = false;
  while (fread(&aux, sizeof(Jugador), 1, pJugador) == 1)
  {
    if (aux.getDNI() == dni && aux.getEstado() == true)
    {
      aux.Mostrar();
      cout << endl;
      encontrado = true;
    }
  }
  if (!encontrado)
  {
    textcolor(4, 0);
    separadorSimple();
    cout << "NO COINCIDE CON NINGUN DNI EXISTENTE" << endl;
    separadorSimple();
    textcolor(15, 0);
    cout << "1 - PARA INGRESAR OTRO DNI" << endl;
    cout << "0 - PARA VOLVER" << endl;
    int opcion;
    cin >> opcion;
    if (opcion == 1)
    {
      system("cls");
      textcolor(14, 0);
      return ListarJugadorPorDNI();
    }
    else
    {
      return false;
    }
  }
  fclose(pJugador);
  return true;
}

int ArchivoJugadores::BuscarRegistro()
{
  int dni;
  cin >> dni;

  FILE *p = fopen(rutaYNombre, "rb");
  if (p == NULL)
  {
    cout << "ERROR DE ARCHIVO" << endl;
    return -2;
  }
  Jugador reg;
  int posicionDelRegistro = 0;
  while (fread(&reg, sizeof reg, 1, p) == 1)
  {
    if (reg.getDNI() == dni)
    {
      fclose(p);
      return posicionDelRegistro;
    }
    posicionDelRegistro++;
  }
  fclose(p);
  return -1;
}

bool ArchivoJugadores::ModificarFechaInscripcion(int pos)
{
  if (pos == -1)
  {
    system("cls");
    textcolor(4, 0);
    separadorSimple();
    cout << "NO EXISTE UN JUGADOR CON ESE DNI" << endl;
    separadorSimple();
    textcolor(15, 0);
    return false;
  }
  else
  {
    FILE *p = fopen(rutaYNombre, "rb+");
    if (p == NULL)
    {
      cout << "ERROR DE ARCHIVO MODIFICAR FECHA" << endl;
      fclose(p);
      return false;
    }

    Jugador reg;
    fseek(p, sizeof(Jugador) * pos, SEEK_SET);
    if (fread(&reg, sizeof(Jugador), 1, p) != 1)
    {
      fclose(p);
      return false;
    }

    reg.CargarFecha();

    fseek(p, sizeof(Jugador) * pos, SEEK_SET);
    if (fwrite(&reg, sizeof(Jugador), 1, p) != 1)
    {
      fclose(p);
      return false; // No se pudo escribir el registro modificado
    }

    fclose(p);
  }
  system("cls");
  textcolor(2, 0);
  separadorSimple();
  cout << "FECHA MODIFICADA EXITOSAMENTE :)" << endl;
  separadorSimple();
  textcolor(15, 0);
  return true; // Fecha modificada exitosamente
}

bool ArchivoJugadores::BajaLogicaJugador(int pos)
{
  if (pos == -1)
  {
    system("cls");
    textcolor(4, 0);
    separadorSimple();
    cout << "NO EXISTE UN JUGADOR CON ESE DNI" << endl;
    separadorSimple();
    textcolor(15, 0);
    return false;
  }
  else
  {
    FILE *p = fopen(rutaYNombre, "rb+");
    if (p == NULL)
    {
      cout << "ERROR DE ARCHIVO MODIFICAR FECHA" << endl;
      fclose(p);
      return false;
    }

    Jugador reg;
    fseek(p, sizeof(Jugador) * pos, SEEK_SET);
    if (fread(&reg, sizeof(Jugador), 1, p) != 1)
    {
      fclose(p);
      return false;
    }

    reg.setEstado(false);

    fseek(p, sizeof(Jugador) * pos, SEEK_SET);
    if (fwrite(&reg, sizeof(Jugador), 1, p) != 1)
    {
      fclose(p);
      return false; // No se pudo escribir el registro modificado
    }
    fclose(p);
  }
  system("cls");
  textcolor(2, 0);
  separadorSimple();
  cout << "BAJA EXITOSA :)" << endl;
  separadorSimple();
  textcolor(15, 0);
  return true;
}

bool ArchivoJugadores::CopiaDeSeguridad()
{
  FILE *pJugador;
  pJugador = fopen(rutaYNombre, "rb");
  if (pJugador == NULL)
  {
    cout << "ERROR DE ARCHIVO" << endl;
    return false;
  }
  FILE *pCopia;
  pCopia = fopen("../../registros/jugadores_backup.bkp", "wb");
  if (pCopia == NULL)
  {
    cout << "ERROR DE ARCHIVO" << endl;
    fclose(pCopia);
    return false;
  }
  Jugador registro;
  while (fread(&registro, sizeof(Jugador), 1, pJugador) == 1)
  {
    fwrite(&registro, sizeof(Jugador), 1, pCopia);
  }
  fclose(pJugador);
  fclose(pCopia);
  return true;
}

bool ArchivoJugadores::RestaurarBackUp()
{
  FILE *pJugador;
  pJugador = fopen(rutaYNombre, "wb");
  if (pJugador == NULL)
  {
    cout << "ERROR DE ARCHIVO" << endl;
    return false;
  }
  FILE *pCopia;
  pCopia = fopen("../../registros/jugadores_backup.bkp", "rb");
  if (pCopia == NULL)
  {
    cout << "ERROR DE ARCHIVO" << endl;
    fclose(pCopia);
    return false;
  }
  Jugador registro;
  while (fread(&registro, sizeof(Jugador), 1, pCopia) == 1)
  {
    fwrite(&registro, sizeof(Jugador), 1, pJugador);
  }
  fclose(pJugador);
  fclose(pCopia);
  return true;
}

bool ArchivoJugadores::RestablecerDatosDeInicio()
{
  FILE *pJugador;
  pJugador = fopen(rutaYNombre, "wb");
  if (pJugador == NULL)
  {
    cout << "ERROR DE ARCHIVO" << endl;
    return false;
  }
  FILE *pCopia;
  pCopia = fopen("../../registros/jugadores_datosInicio.dat", "rb");
  if (pCopia == NULL)
  {
    cout << "ERROR DE ARCHIVO" << endl;
    fclose(pCopia);
    return false;
  }
  Jugador registro;
  while (fread(&registro, sizeof(Jugador), 1, pCopia) == 1)
  {
    fwrite(&registro, sizeof(Jugador), 1, pJugador);
  }
  fclose(pJugador);
  fclose(pCopia);
  return true;
}

// testigos de como se escribio esto: dios, mi gato, yo

#endif // ARCHIVOJUGADORES_H_INCLUDED