#ifndef ARCHIVODEPORTES_H_INCLUDED
#define ARCHIVODEPORTES_H_INCLUDED

#include <cstring>

#include "..\funciones\funcionesGlobales.h"
#include "Deporte.h"

#include "CargarDeporte.h"

class ArchivoDeportes
{
private:
  char rutaYNombre[40];

public:
  ArchivoDeportes(const char *nombreDelArchivo, const char *ruta);
  ~ArchivoDeportes();
  bool AgregarRegistro(Deporte &reg);
  bool GuardarDeporte();
  bool ListarDeportes();
  bool ExisteId(int id);
  bool ListarDeportePorId();
  int BuscarRegistro();
  bool ModificarFechaDeOrigen(int pos);
  bool BajaLogicaDeporte(int pos);
  int ObtenerUltimoId();
  bool ObtenerEstado(int pos);
  int ObtenerPosicion(int id);
  bool CopiaDeSeguridad();
  bool RestaurarBackUp();
  bool RestablecerDatosDeInicio();

};

ArchivoDeportes::ArchivoDeportes(const char *nombreDelArchivo = "deportes.dat", const char *ruta = "../../registros/")
{
  strcpy(this->rutaYNombre, ruta);
  strcat(this->rutaYNombre, nombreDelArchivo);
}

ArchivoDeportes::~ArchivoDeportes()
{
}

bool ArchivoDeportes::AgregarRegistro(Deporte &reg)
{
  FILE *pDeporte;
  pDeporte = fopen(this->rutaYNombre, "ab");
  if (pDeporte == NULL)
  {
    return false;
  }
  bool grabo = fwrite(&reg, sizeof(Deporte), 1, pDeporte);
  fclose(pDeporte);
  return grabo;
}

bool ArchivoDeportes::GuardarDeporte()
{
  Deporte reg;
  reg.Cargar();
  reg.setEstado(true);
  int ultimoId = ObtenerUltimoId();
  if (ultimoId > 0)
  {
    reg.setId(ultimoId + 1);
  }
  else
  {
    reg.setId(1);
  } // una porqueria esto pero bueno

  if (ExisteId(reg.getId()))
  {
    system("cls");
    textcolor(4, 0);
    separadorSimple();
    cout << "YA EXISTE UN DEPORTE CON ESE ID" << endl;
    separadorSimple();
    textcolor(15, 0);
    cout << "1 - PARA INGRESAR OTRO DEPORTE" << endl;
    cout << "0 - PARA VOLVER AL MENU PRINCIPAL" << endl;
    int opcion;
    cin >> opcion;
    if (opcion == 1)
    {
      GuardarDeporte();
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

bool ArchivoDeportes::ListarDeportes()
{
  FILE *pDeporte;
  Deporte aux;
  pDeporte = fopen(rutaYNombre, "rb");
  if (pDeporte == NULL)
  {
    cout << "ERROR DE ARCHIVO" << endl;
    return false;
  }
  while (fread(&aux, sizeof(Deporte), 1, pDeporte) == 1)
  {
    if (aux.getEstado() == true)
    {
      aux.Mostrar();
      cout << endl;
    }
  }
  fclose(pDeporte);
  return true;
}

bool ArchivoDeportes::ExisteId(int id)
{
  FILE *p;
  Deporte reg;
  bool existe = false;
  p = fopen(rutaYNombre, "rb");
  if (p == NULL)
  {
    cout << "ID ERROR DE ARCHIVO" << endl;
    return false;
  }
  while (fread(&reg, sizeof(Deporte), 1, p) == 1)
  {
    if (reg.getId() == id)
    {
      existe = true;
      break;
    }
  }
  fclose(p);
  return existe;
}

bool ArchivoDeportes::ListarDeportePorId()
{
  FILE *pDeporte;
  Deporte aux;
  pDeporte = fopen(rutaYNombre, "rb");
  if (pDeporte == NULL)
  {
    cout << "ERROR DE ARCHIVO" << endl;
    return false;
  }
  int id;
  cout << "INGRESE ID A BUSCAR: ";
  cin >> id;
  system("cls");
  textcolor(14, 0);
  separadorSimple();
  cout << "RESULTADO DE LA BUSQUEDA: " << endl;
  separadorSimple();
  textcolor(15, 0);
  bool encontrado = false;
  while (fread(&aux, sizeof(Deporte), 1, pDeporte) == 1)
  {
    if (aux.getId() == id && aux.getEstado() == true)
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
    cout << "NO COINCIDE CON NINGUN ID EXISTENTE" << endl;
    separadorSimple();
    textcolor(15, 0);
    cout << "1 - PARA INGRESAR OTRO ID" << endl;
    cout << "0 - PARA VOLVER" << endl;
    int opcion;
    cin >> opcion;
    if (opcion == 1)
    {
      system("cls");
      textcolor(14, 0);
      return ListarDeportePorId();
    }
    else
    {
      return false;
    }
  }
  fclose(pDeporte);
  return true;
}

int ArchivoDeportes::BuscarRegistro()
{
  int id;
  cin >> id;

  FILE *p = fopen(rutaYNombre, "rb");
  if (p == NULL)
  {
    cout << "ERROR DE ARCHIVO" << endl;
    return -2;
  }
  Deporte reg;
  int posicionDelRegistro = 0;
  while (fread(&reg, sizeof reg, 1, p) == 1)
  {
    if (reg.getId() == id)
    {
      fclose(p);
      return posicionDelRegistro;
    }
    posicionDelRegistro++;
  }
  fclose(p);
  return -1;
}

bool ArchivoDeportes::ModificarFechaDeOrigen(int pos)
{
  if (pos == -1)
  {
    system("cls");
    textcolor(4, 0);
    separadorSimple();
    cout << "NO EXISTE UN DEPORTE CON ESE ID" << endl;
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
      return false;
    }

    Deporte reg;
    fseek(p, sizeof(Deporte) * pos, SEEK_SET);
    if (fread(&reg, sizeof(Deporte), 1, p) != 1)
    {
      fclose(p);
      return false;
    }

    CargarDeporte cargar;
    reg.setAnioDeOrigen(cargar.AnioDeOrigen());

    fseek(p, sizeof(Deporte) * pos, SEEK_SET);
    if (fwrite(&reg, sizeof(Deporte), 1, p) != 1)
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

bool ArchivoDeportes::BajaLogicaDeporte(int pos)
{
  if (pos == -1)
  {
    system("cls");
    textcolor(4, 0);
    separadorSimple();
    cout << "NO EXISTE UN DEPORTE CON ESE ID" << endl;
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
      return false;
    }

    Deporte reg;
    fseek(p, sizeof(Deporte) * pos, SEEK_SET);
    if (fread(&reg, sizeof(Deporte), 1, p) != 1)
    {
      fclose(p);
      return false;
    }

    reg.setEstado(false);

    fseek(p, sizeof(Deporte) * pos, SEEK_SET);
    if (fwrite(&reg, sizeof(Deporte), 1, p) != 1)
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

int ArchivoDeportes::ObtenerUltimoId()
{
  FILE *p = fopen(rutaYNombre, "rb");
  if (p == NULL)
  {
    cout << "ERROR DE ARCHIVO" << endl;
    return -1; // o un valor que indique error
  }
  Deporte reg;
  int ultimoId = -1; // Inicializa con un valor que indique que no se encontró ningún ID aún
  while (fread(&reg, sizeof reg, 1, p) == 1)
  {
    int regId = reg.getId();
    if (regId > ultimoId)
    {
      ultimoId = regId;
    }
  }
  fclose(p);
  return ultimoId;
}

bool ArchivoDeportes::ObtenerEstado(int pos)
{
  FILE *p = fopen(rutaYNombre, "rb");
  if (p == NULL)
  {
    cout << "ERROR DE ARCHIVO" << endl;
    return false;
  }
  Deporte reg;
  fseek(p, sizeof(Deporte) * pos, SEEK_SET);
  if (fread(&reg, sizeof(Deporte), 1, p) != 1)
  {
    fclose(p);
    return false;
  }
  fclose(p);
  return reg.getEstado();
}

int ArchivoDeportes::ObtenerPosicion(int id)
{
  FILE *p = fopen(rutaYNombre, "rb");
  if (p == NULL)
  {
    cout << "ERROR DE ARCHIVO" << endl;
    return -1; // o un valor que indique error
  }
  Deporte reg;
  int posicion = 0;
  while (fread(&reg, sizeof reg, 1, p) == 1)
  {
    if (reg.getId() == id)
    {
      fclose(p);
      return posicion;
    }
    posicion++;
  }
  fclose(p);
  return -1;
}

bool ArchivoDeportes::CopiaDeSeguridad()
{
  FILE *pDeportes;
  pDeportes = fopen(this->rutaYNombre, "rb");
  if (pDeportes == NULL)
  {
    cout << "ERROR DE ARCHIVO" << endl;
    return false;
  }
  FILE *pCopia;
  pCopia = fopen("../../registros/deportes_backup.bkp", "wb");
  if (pCopia == NULL)
  {
    cout << "ERROR DE ARCHIVO" << endl;
    fclose(pDeportes);
    return false;
  }
  Deporte reg;
  while (fread(&reg, sizeof(Deporte), 1, pDeportes))
  {
    fwrite(&reg, sizeof(Deporte), 1, pCopia);
  }
  fclose(pDeportes);
  fclose(pCopia);
  return true;
}

bool ArchivoDeportes::RestaurarBackUp()
{
  FILE *pDeporte;
  pDeporte = fopen(rutaYNombre, "wb");
  if (pDeporte == NULL)
  {
    cout << "ERROR DE ARCHIVO" << endl;
    return false;
  }
  FILE *pCopia;
  pCopia = fopen("../../registros/deportes_backup.bkp", "rb");
  if (pCopia == NULL)
  {
    cout << "ERROR DE ARCHIVO" << endl;
    fclose(pCopia);
    return false;
  }
  Deporte registro;
  while (fread(&registro, sizeof(Deporte), 1, pCopia) == 1)
  {
    fwrite(&registro, sizeof(Deporte), 1, pDeporte);
  }
  fclose(pDeporte);
  fclose(pCopia);
  return true;
}

bool ArchivoDeportes::RestablecerDatosDeInicio()
{
  FILE *pDeporte;
  pDeporte = fopen(rutaYNombre, "wb");
  if (pDeporte == NULL)
  {
    cout << "ERROR DE ARCHIVO" << endl;
    return false;
  }
  FILE *pCopia;
  pCopia = fopen("../../registros/deportes_datosInicio.dat", "rb");
  if (pCopia == NULL)
  {
    cout << "ERROR DE ARCHIVO" << endl;
    fclose(pCopia);
    return false;
  }
  Deporte registro;
  while (fread(&registro, sizeof(Deporte), 1, pCopia) == 1)
  {
    fwrite(&registro, sizeof(Deporte), 1, pDeporte);
  }
  fclose(pDeporte);
  fclose(pCopia);
  return true;
}

#endif // ARCHIVODEPORTES_H_INCLUDED