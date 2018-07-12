#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Empleado.h"

int parser_parseEmpleados(char* fileName, ArrayList* listaEmpleados)
{
    int retorno = -1;
    char id[128];
    char nombre[128];
    char horasTrabajadas[128];
    int aux;

    S_Empleado* auxiliarEmpleado;

    FILE* fp = fopen(fileName, "r");
    if(fp!= NULL)
    {
        retorno = 0;

        fscanf(fp,"%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas);

        do
        {
           aux=fscanf(fp,"%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas);


           if(aux!=3)
            break;

            auxiliarEmpleado = Empleado_new();
            Empleado_setId(auxiliarEmpleado, atoi(id));
            Empleado_setNombre(auxiliarEmpleado, nombre);
            Empleado_setHorasTrabajadas(auxiliarEmpleado, atoi(horasTrabajadas));
            al_add(listaEmpleados, auxiliarEmpleado);
        } while(!feof(fp));
        retorno = 1;

        fclose(fp);
    }


    return retorno;
}
