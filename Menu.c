#include <stdio.h>
#include <stdlib.h>
#include "getsValids.h"

int menu_mostrarmenu()
{
    int opcion;


   do{
        printf("MENU\n\nOpciones:\n1)Opcion 1\n2)Opcion 2\n3)Opcion 3\n4)Opcion 4\n5)Opcion 5\n6)Opcion 6\n7)Opcion 7\n8)Opcion 8\n9)Opcion 9\n10)Opcion 10\n\n11)SALIR");

        get_validInt("\n\nSeleccione una Opcion: ","\nEsa no es una opcion valida",&opcion,1,11,3);

        switch(opcion)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;

        }

        system("cls");

    }while(opcion!=11);

    return 0;
}
