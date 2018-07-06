#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"


typedef struct
{
  int id;
  char nombre[50];
  char direccion[70];
  int horas;
  int sueldo;

}eEmpleado;

eEmpleado* newParamEmpleado(char* direccion,char* name,int id);
int empleadoCompara(void* pEmployeeA,void* pEmployeeB);
void funcionparacomparar(void* empleado);
eEmpleado* newParamEmpleado2(char* direccion,char* name,int id,int horas,int sueldo);
void employee_print2(eEmpleado* this);

int main()
{
     char idAux[65];
    char nameAux[65];
    char direccionAux[65];
    char horasAux[20];
    char sueldoAux[20];
    int id;
    int horas;
    int sueldo;
    int cant;
    int i=0;

    ArrayList* listaEmpleados;
    FILE* pArchivoEmpleados;
    FILE* pArchivoEscritura;

    eEmpleado* empleadoAux;


    listaEmpleados=al_newArrayList();

    //pArchivoEmpleados = fopen("MOCK_DATA.csv", "r");
    pArchivoEmpleados = fopen("MOCK_DATA (3).csv", "r");

    if(pArchivoEmpleados == NULL)
    {
        printf("Error al abrir el fichero\n");
        exit(1);
    }

    while(!feof(pArchivoEmpleados))
    {
        cant=fscanf(pArchivoEmpleados, "%[^,] , %[^,] , %[^,] ,%[^,] ,%[^\n] \n", idAux, nameAux, direccionAux,horasAux,sueldoAux);
        ///cant = fscanf(pArchivoEmpleados, "%[^,] , %[^,] , %[^\n] \n", idAux, nameAux, direccionAux);primera parte

        if( cant != 5)
        {

            if(feof(pArchivoEmpleados))
            {
                break;
            }
            else
            {
                printf("Problema para leer el archivo\n");

                break;
            }
        }
        id = atoi(idAux);
        horas=atoi(horasAux);
        sueldo=atoi(sueldoAux);

        empleadoAux=newParamEmpleado2(direccionAux,nameAux,id,horas,sueldo);

        //listaEmpleados->add(listaEmpleados,empleadoAux);
        listaEmpleados->set(listaEmpleados, i,empleadoAux);
        //employee_print(empleadoAux);
        i++;

    }

    listaEmpleados->sort(listaEmpleados,empleadoCompara,1);
    for(int j=0;j<10;j++)
    ///for(int j=0;j<1000;j++)primera parte
    {
        empleadoAux=listaEmpleados->get(listaEmpleados,j);
        employee_print2(empleadoAux);
    }

    listaEmpleados->map(listaEmpleados,funcionparacomparar);

printf("\n\n");

    for(int j=0;j<10;j++)
    ///for(int j=0;j<1000;j++)primera parte
    {
        empleadoAux=listaEmpleados->get(listaEmpleados,j);
        employee_print2(empleadoAux);
    }


    fclose(pArchivoEmpleados);

    ///TERCERA PARTE
    for(int i=0;i<listaEmpleados->size;i++)
    {
        guardarEmpleado(listaEmpleados->get(listaEmpleados,i),"sueldos.csv");
    }













    return 0;
}


eEmpleado* newParamEmpleado2(char* direccion,char* name,int id,int horas,int sueldo)
{
    eEmpleado* empleado;

    if(direccion!=NULL&&name!=NULL)
    {
            empleado=(eEmpleado*)malloc(sizeof(eEmpleado));
            if(empleado!=NULL)
            {
                strcpy(empleado->direccion,direccion);
                strcpy(empleado->nombre ,name);
                empleado->id=id;
                empleado->horas=horas;
                empleado->sueldo=sueldo;
            }


    }
    return empleado;
}




/**primera parte
eEmpleado* newParamEmpleado(char* direccion,char* name,int id)
{
    eEmpleado* empleado;

    if(direccion!=NULL&&name!=NULL)
    {
            empleado=(eEmpleado*)malloc(sizeof(eEmpleado));
            if(empleado!=NULL)
            {
                strcpy(empleado->direccion,direccion);
                strcpy(empleado->nombre ,name);
                empleado->id=id;
            }


    }
    return empleado;
}
*/

int empleadoCompara(void* pEmployeeA,void* pEmployeeB)
{
    //castear a empleado
    return strcmp(((eEmpleado*)pEmployeeA)->nombre,((eEmpleado*)pEmployeeB)->nombre);
}

/**primera parte
void employee_print(eEmpleado* this)
{
    if(this != NULL)
    printf("%d-%s-%s\n",this->id,this->nombre,this->direccion);
}
*/

void employee_print2(eEmpleado* this)
{
    if(this != NULL)
    printf("%d---%s---%s---%d----%d\n",this->id,this->nombre,this->direccion,this->horas,this->sueldo);
}


void funcionparacomparar(void* empleado)
{
    int sueldo;
    if(((eEmpleado*)empleado)->horas<=120)
    {
        sueldo=180*((eEmpleado*)empleado)->horas;
    }
    else if(120>((eEmpleado*)empleado)->horas&&((eEmpleado*)empleado)->horas<=160)
    {
        sueldo=240*((eEmpleado*)empleado)->horas;
    }
    else
    {
        sueldo=350*((eEmpleado*)empleado)->horas;
    }

    ((eEmpleado*)empleado)->sueldo=sueldo;


}

void guardarEmpleado(eEmpleado* empleado,char* path)
{
    FILE* f;
    f=fopen(path,"a");
    if(f!=NULL)
    {
         fprintf( f, "%s;\t%s;\t%d;\t%d;\t%d\n", empleado->nombre,empleado->direccion,empleado->horas,empleado->id,empleado->sueldo);
        //fwrite(log,sizeof(S_LogEntry),1,f);

        fclose(f);
    }


}

