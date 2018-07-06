#include <stdio.h>
#include <stdlib.h>

#define TOPE 4
#define PHAT "E:\\PUNTEROS\\miArchivo2.txt"//directorio,
#define PHAT2 "E:\\PUNTEROS\\listadeinvitados.txt"
#define PHAT3 "E:\\PUNTEROS\\listadeinvitados3.txt"


int main()
{
    int salir=0;
    int opcion;

    while(salir==0)
    {

        imprimirMenu();
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                AgregarInvitados();
                break;
            case 2:
                verInvitados();
                break;
            case 3:
                salir=1;
                break;
        }

    }

    return 0;
}


void AgregarInvitados()
{
    FILE* pArchivo;

    pArchivo=fopen(PHAT2,"a");
    char nombre[100];


    if(pArchivo!=NULL)
    {
        printf("ingrese nombre de invitados\n");
        fflush(stdin);
        gets(nombre);

        fprintf(pArchivo,"%s \n",nombre);
        fclose(pArchivo);

    }



}

void verInvitados()
{
    FILE* pArchivo;

    char cadena[100];

    pArchivo=fopen(PHAT2,"r");
    if(pArchivo!=NULL)
    {

        while(!feof(pArchivo))
        {
            //puts(cadena);
            fgets(cadena,100,pArchivo);
            if(feof(pArchivo))
            {
                break;
            }
            puts(cadena);

        }

         fclose(pArchivo);
    }




}


void imprimirMenu()
{
    printf("\n----------------------------\n");
    printf("1-agregar invitados\n");
    printf("2-ver invitados\n");
    printf("3-salir\n");


}
