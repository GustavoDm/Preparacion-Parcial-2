#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"

int generarArchivo(char* fileName, ArrayList* lista);

int main()
{
     ArrayList* listaDestinatarios;
    listaDestinatarios = al_newArrayList();

    ArrayList* listaNegra;
    listaNegra = al_newArrayList();

    menu_mostrarmenu();
    return 0;
}
