#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include <ctime>

#include "../funciones/funcionesGlobales.h"

class Fecha
{
private:
    int dia, mes, anio;

public:
    Fecha(int dia, int mes, int anio);
    bool EsFechaValida();
    void Cargar();
    void Mostrar();
    void mostrarEnLinea();
    void setDia(int d);
    void setMes(int m);
    void setAnio(int a);
    int getDia() { return dia; }
    int getMes() { return mes; }
    int getAnio() { return anio; }
};

Fecha::Fecha(int dia = 0, int mes = 0, int anio = 0)
{
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

void Fecha::Cargar()
{
    do
    {
        cout << "DIA: ";
        cin >> dia;
        cout << "MES: ";
        cin >> mes;
        cout << "ANIO: ";
        cin >> anio;

        if (!EsFechaValida())
        { // Verifica si la fecha NO es válida
            system("cls");
            textcolor(4, 0);
            separadorSimple();
            cout << "Fecha no valida. Por favor, ingrese una fecha correcta. "
                    "Ingreso: ";
            mostrarEnLinea();
            separadorSimple();
            textcolor(15, 0);
        }
    } while (!EsFechaValida()); // Continúa el bucle si la fecha NO es válida
}

bool Fecha::EsFechaValida()
{
    if (anio <= 0)
    {
        return false; // El año no puede ser negativo
    }

    if (mes < 1 || mes > 12)
    {
        return false; // El mes debe estar entre 1 y 12
    }

    if (dia < 1)
    {
        return false; // El día no puede ser negativo
    }

    // Verificar si el día es válido para el mes actual
    if (mes == 2)
    {
        // Febrero tiene 28 o 29 días dependiendo de si es un año bisiesto
        if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0))
        {
            if (dia > 29)
            {
                return false; // Año bisiesto, febrero tiene 29 días
            }
        }
        else
        {
            if (dia > 28)
            {
                return false; // Año no bisiesto, febrero tiene 28 días
            }
        }
    }
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        if (dia > 30)
        {
            return false; // Meses con 30 días
        }
    }
    else
    {
        if (dia > 31)
        {
            return false; // Meses con 31 días
        }
    }

    // Si llegamos aca, la fecha es válida
    return true;
}

void Fecha::Mostrar()
{
    cout << "DIA: " << dia << endl;
    cout << "MES: " << mes << endl;
    cout << "ANIO: " << anio << endl;
}

void Fecha::mostrarEnLinea()
{
    cout << dia << "/" << mes << "/" << anio << endl;
}

void Fecha::setDia(int d)
{
    if (d >= 1 && d <= 31)
        dia = d;
    else
        dia = -1;
}

void Fecha::setMes(int m)
{
    if (m >= 1 && m <= 12)
        mes = m;
    else
        mes = -1;
}

void Fecha::setAnio(int a)
{
    if (a != 0)
        anio = a;
    else
        anio = -1;
}
#endif // FECHA_H_INCLUDED
