#ifndef MENUJUGADORES_H_INCLUDED
#define MENUJUGADORES_H_INCLUDED

#include "..\funciones\funcionesGlobales.h"
#include "..\clases\ArchivoJugadores.h"

class MenuJugadores
{
private:
public:
  bool MostrarMenu();
};

bool MenuJugadores::MostrarMenu()
{
  ArchivoJugadores archivoJugadores("jugadores.dat", "../../registros/");
  int opcion;
  while (true)
  {
    system("cls");
    separadorDoble();
    cout << "\t MENU JUGADORES" << endl;
    separadorDoble();
    cout << endl;
    cout << "1. AGREGAR JUGADOR" << endl;
    cout << "2. LISTAR JUGADOR POR DNI" << endl;
    cout << "3. LISTAR TODOS LOS JUGADORES" << endl;
    cout << "4. MODIFICAR FECHA DE INSCRIPCION" << endl;
    cout << "5. ELIMINAR REGISTRO DE JUGADOR" << endl;
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
      cout << "AGREGAR JUGADOR:" << endl;
      separadorSimple();
      textcolor(15, 0);
      archivoJugadores.GuardarJugador();
      system("pause");
      break;
    case 2:
      textcolor(14, 0);
      separadorSimple();
      cout << "LISTAR JUGADOR POR DNI:" << endl;
      separadorSimple();
      textcolor(15, 0);
      archivoJugadores.ListarJugadorPorDNI();
      system("pause");
      break;
    case 3:
      textcolor(14, 0);
      separadorSimple();
      cout << "LISTA DE JUGADORES REGISTRADOS:" << endl;
      separadorSimple();
      textcolor(15, 0);
      archivoJugadores.ListarJugadores();
      system("pause");
      break;
    case 4:
      textcolor(14, 0);
      separadorSimple();
      cout << "INGRESE DNI DEL JUGADOR A MODIFICAR:" << endl;
      separadorSimple();
      textcolor(15, 0);
      archivoJugadores.ModificarFechaInscripcion(archivoJugadores.BuscarRegistro());
      system("pause");
      break;
    case 5:
      separadorSimple();
      // tambien da de alta si esta dado de baja
      cout << "INGRESE DNI DEL JUGADOR A DAR DE BAJA:" << endl; // no olvidarme de esto
      separadorSimple();
      archivoJugadores.BajaLogicaJugador(archivoJugadores.BuscarRegistro());
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

#endif // MENUJUGADORES_H_INCLUDED