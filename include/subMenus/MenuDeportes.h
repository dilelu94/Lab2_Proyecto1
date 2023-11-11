#ifndef MENUDEPORTES_H_INCLUDED
#define MENUDEPORTES_H_INCLUDED

#include "..\funciones\funcionesGlobales.h"
#include "..\clases\ArchivoDeportes.h"

class MenuDeportes
{
private:
public:
  bool MostrarMenu();
};

bool MenuDeportes::MostrarMenu()
{
  ArchivoDeportes archivoDeportes("deportes.dat", "../../registros/");
  textcolor(15, 0);
  int opcion;
  while (true)
  {
    system("cls");
    separadorDoble();
    cout << "\t MENU DEPORTES" << endl;
    separadorDoble();
    cout << endl;
    cout << "1. AGREGAR DEPORTE" << endl;
    cout << "2. LISTAR DEPORTE POR ID" << endl;
    cout << "3. LISTAR TODO" << endl;
    cout << "4. MODIFICAR ANIO DE ORIGEN" << endl;
    cout << "5. ELIMINAR REGISTRO" << endl;
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
      cout << "AGREGAR DEPORTE:" << endl;
      separadorSimple();
      textcolor(15, 0);
      archivoDeportes.GuardarDeporte();
      system("pause");
      break;
    case 2:
      textcolor(14, 0);
      separadorSimple();
      cout << "LISTAR DEPORTE POR ID:" << endl;
      separadorSimple();
      textcolor(15, 0);
      archivoDeportes.ListarDeportePorId();
      system("pause");
      break;
    case 3:
      textcolor(14, 0);
      separadorSimple();
      cout << "LISTA DE DEPORTES REGISTRADOS:" << endl;
      separadorSimple();
      textcolor(15, 0);
      archivoDeportes.ListarDeportes();
      system("pause");
      break;
    case 4:
      textcolor(14, 0);
      separadorSimple();
      cout << "INGRESE ID DEL DEPORTE A MODIFICAR:" << endl;
      separadorSimple();
      textcolor(15, 0);
      archivoDeportes.ModificarFechaDeOrigen(archivoDeportes.BuscarRegistro());
      system("pause");
      break;
    case 5:
      separadorSimple();
      cout << "INGRESE ID DEL DEPORTE A DAR DE BAJA:" << endl;
      separadorSimple();
      archivoDeportes.BajaLogicaDeporte(archivoDeportes.BuscarRegistro());
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
  }
}

#endif // MENUDeporteS_H_INCLUDED