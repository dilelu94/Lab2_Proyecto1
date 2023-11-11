#ifndef FUNCIONESGLOBALES_H_INCLUDED
#define FUNCIONESGLOBALES_H_INCLUDED

#include <windows.h>

void cargarCadena(char *palabra, int tam)
{
    int i = 0;
    fflush(stdin);
    for (i = 0; i < tam; i++)
    {
        palabra[i] = cin.get();
        if (palabra[i] == '\n')
            break;
    }
    palabra[i] = '\0';
    fflush(stdin);
}

void separadorDoble()
{
    cout << "========================================" << endl;
}
void separadorSimple()
{
    cout << "----------------------------------------" << endl;
}

void textcolor(int colorTexto = 15, int colorFondo = 0)
{
    int color = colorTexto + colorFondo * 16;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

#endif // FUNCIONESGLOBALES_H_INCLUDED