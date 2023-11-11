/// Ejercicio: Trabajo N° 1 - Parte 1 Archivos
/// Autor: Diego Leonel Luque
/// Fecha: 07/09/2023
/// Comentario:

#include <iostream>
#include <cstdlib>

using namespace std;

#include "..\include\funciones\funcionesGlobales.h"
#include "..\include\subMenus\MenuJugadores.h"
#include "..\include\subMenus\MenuDeportes.h"
#include "..\include\subMenus\MenuConfiguracion.h"
#include "..\include\subMenus\reportes.h"

enum Color
{
  cNEGRO = 0,
  cAZUL = 1,
  cVERDE = 2,
  cCIAN = 3,
  cROJO = 4,
  cMAGENTA = 5,
  cMARRON = 6,
  cGRIS_CLARO = 7,
  cGRIS = 8,
  cAZUL_CLARO = 9,
  cVERDE_CLARO = 10,
  cCIAN_CLARO = 11,
  cROJO_CLARO = 12,
  cMAGENTA_CLARO = 13,
  cAMARILLO = 14,
  cBLANCO = 15
};

int main()
{
  textcolor(15, 0);
  int opcion;
  while (true)
  {
    system("cls");
    separadorDoble();
    cout << "\t MENU PRINCIPAL" << endl;
    separadorDoble();
    cout << endl;
    cout << "1. MENU JUGADORES" << endl;
    cout << "2. MENU DEPORTES" << endl;
    cout << "3. REPORTES" << endl;
    cout << "4. CONFIGURACION" << endl;
    separadorSimple();
    cout << "0. FIN DEL PROGRAMA" << endl;
    cout << endl;
    cout << "SELECCIONE UNA DE LAS OPCIONES: ";
    cin >> opcion;
    system("cls");
    switch (opcion)
    {
    case 1:
      MenuJugadores menuJugadores;
      menuJugadores.MostrarMenu();
      system("pause");
      break;
    case 2:
      MenuDeportes menuDeportes;
      menuDeportes.MostrarMenu();
      system("pause");
      break;
    case 3:
      Reportes menuReportes;
      menuReportes.MostrarMenu();
      system("pause");
      break;
    case 4:
      MenuConfiguracion menuConfiguracion;
      menuConfiguracion.MostrarMenu();
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

  system("pause");
  return 0;
}
