#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

int file_parser(File *pFile, ArrayList *this);
int file_generarArchivo(char* fileName, ArrayList* this);
int file_saveAll(ArrayList* listaSocios);

#endif // FILE_H_INCLUDED
