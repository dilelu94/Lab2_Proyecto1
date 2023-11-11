#ifndef MENUCONFIGURACION_H_INCLUDED
#define MENUCONFIGURACION_H_INCLUDED

#include "../funciones/funcionesGlobales.h"
#include "../clases/Configuracion.h"

class MenuConfiguracion
{
private:
public:
  bool MostrarMenu();
};

bool MenuConfiguracion::MostrarMenu()
{
  Configuracion configurar;
  int opcion;
  while (true)
  {
    system("cls");
    separadorDoble();
    cout << "\t MENU CONFIGURACION" << endl;
    separadorDoble();
    cout << endl;
    cout << "1. COPIA DE SEGURIDAD DEL ARCHIVO DE JUGADORES" << endl;
    cout << "2. COPIA DE SEGURIDAD DEL ARCHIVO DE DEPORTES" << endl;
    cout << "3. RESTAURAR EL ARCHIVO DE JUGADORES" << endl;
    cout << "4. RESTAURAR EL ARCHIVO DE DEPORTES" << endl;
    cout << "5. ESTABLECER DATOS DE INICIO" << endl;
    separadorSimple();
    cout << "0. VOLVER AL MENU PRINCIPAL" << endl;
    cout << endl;
    cout << "OPCION: ";
    cin >> opcion;
    system("cls");
    switch (opcion)
    {
    case 1:
      configurar.CopiaDeSeguridadJugadores();
      system("pause");
      break;
    case 2:
      configurar.CopiaDeSeguridadDeportes();
      system("pause");
      break;
    case 3:
      configurar.RestaurarBackUpJugadores();
      system("pause");
      break;
    case 4:
      configurar.RestaurarBackUpDeportes();
      system("pause");
      break;
    case 5:
      configurar.RestablecerDatosDeInicio();
      system("pause");
      break;
    case 0:
      return false;
      break;
    default:
      cout << "OPCION INCORRECTA" << endl;
      system("pause");
      break;
    }
  }
}

#endif // MENUCONFIGURACION_H_INCLUDED