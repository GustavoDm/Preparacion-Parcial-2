#include <stdio.h>
#include <stdlib.h>
#include "entidad"

int file_parser(File *pFile, ArrayList *this)
{

 FILE *pFile;
 ArrayList *auxEntidad;

    char Nombre[50];
    char Apellido[50];
    int Id;
    int resultado;

 pFile = fopen("data.csv","r");

    if(pFile!=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%d",Nombre,Apellido,Id);

        do
        {
          resultado = fscanf(pFile,"%[^,],%[^,],%d",Nombre,Apellido,Id);

        if(resultado!=3)
            break;

        auxEntidad=entidad_new();

        entidad_setNombre(auxEntidad, Nombre);
        entidad_setApellido(auxEntidad,Apellido);
        entidad_setId(auxEntidad,atoi(Id));

        al_add(this, auxEntidad);

        fclose(fp);

        }while(!feof(pFile))
    }

 }

 int file_generarArchivo(char* fileName, ArrayList* lista)
{
    int retorno = -1;
    int i;
    char nombre[128];
    char mail[128];
    Destinatario* auxDest;

    if(fileName != NULL && lista != NULL)
    {
        FILE* fp = fopen(fileName, "w");

        if(fp != NULL)
        {
            for(i = 0; i < al_len(lista); i++)
            {
                auxDest = al_get(lista, i);
                destinatario_getName(auxDest, nombre);
                destinatario_getEmail(auxDest, mail);
                fprintf(fp, "%s - %s\n", nombre, mail);
            }
            retorno = 0;
            fclose(fp);
        }
    }
    return retorno;
}

int file_saveAll(ArrayList* listaSocios)
{
    FILE* pFile;
    Socio* pSocio;
    int i;
    pFile = fopen(ARCHIVO_SOCIOS,"wb");

    if(pFile != NULL)
    {
        for(i=0; i < al_len(listaSocios); i++)
        {
            pSocio = al_get(listaSocios,i);
            fwrite(pSocio,sizeof(Socio),1,pFile);
        }
        fclose(pFile);

    }
    return 0;
}


int file_readAll(ArrayList* listaSocios)
{
    FILE* pFile;
    Socio auxSocio;
    Socio* pSocio;
    int maxId = 0;
    pFile = fopen(ARCHIVO_SOCIOS,"rb");

    if(pFile != NULL)
    {
        do //no hacer while porque primero hay q saber si fread pudo leer
        {
            if(fread(&auxSocio,sizeof(Socio),1,pFile) == 1)  //& direccion de memoria de la variable socio creada
            {
                pSocio = soc_new(auxSocio.nombre,auxSocio.apellido,auxSocio.dni,auxSocio.id,auxSocio.estado);
                al_add(listaSocios,pSocio);
                if(maxId<auxSocio.id)
                    maxId = auxSocio.id;
            }

        }while (!feof(pFile));

    return maxId;
    }
    return -1;
}
