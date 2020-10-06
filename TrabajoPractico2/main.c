#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "ArrayEmployee.h"

#define TAM 5

Employee list[TAM];
Employee listSortSectors[TAM];
int operacion = 0;
int finish = 0;
int idGeneral = 1;
int main()
{
    initMenu();
    return 0;
}

void initMenu(){
    while(finish == 0){
        showOperations();
        printf("\n\nPresione cualquier tecla para continuar");
        getch();
        system("cls");
    }
}

void showOperations(){
    int operation = 0;
    printf("**MENU**\n\n");
    printf("1 - Dar de alta\n");
    printf("2 - Modificar\n");
    printf("3 - Dar de baja\n");
    printf("4 - Informar\n");
    printf("5 - Salir\n");
    printf("\nSeleccione una operacion: ");
    fflush(stdin);
    scanf("%d", &operacion);

    checkOperation(operacion);
}

void checkOperation(int operation){
    Employee employee;
    int idToUpdate;
    int idToRemove;
    switch(operation){
    case 1:
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(employee.name);
        printf("Ingrese apellido: ");
        fflush(stdin);
        gets(employee.lastName);
        printf("Ingrese salario: ");
        fflush(stdin);
        scanf("%f", &employee.salary);
        printf("Ingrese sector: ");
        fflush(stdin);
        scanf("%d", &employee.sector);
        if(addEmployee(list, TAM, idGeneral, employee.name, employee.lastName, employee.salary, employee.sector) == 0){
            printf("\nEmpleado agregado correctamente\n");
            idGeneral++;
        } else {
            printf("\nError al cargar empleado\n");
        }
        break;
    case 2:
        if(isEmpty(list, TAM) == 0){
            printf("Ingrese ID del empleado: ");
            fflush(stdin);
            scanf("%d", &idToUpdate);

            if(findEmployeeById(list, TAM, idToUpdate) == 0){
                printf("Ingrese nuevo nombre: ");
                fflush(stdin);
                gets(employee.name);
                printf("Ingrese nuevo apellido: ");
                fflush(stdin);
                gets(employee.lastName);
                printf("Ingrese nuevo salario: ");
                fflush(stdin);
                scanf("%f", &employee.salary);
                printf("Ingrese nuevo sector: ");
                fflush(stdin);
                scanf("%d", &employee.sector);
                if(updateEmployee(list, TAM, idToUpdate, employee.name, employee.lastName, employee.salary, employee.sector) == 0){
                    printf("\Actualizacion de empleado exitosa\n");
                } else {
                    printf("\nNo se ha podido realizar la operacion\n");
                }
            } else {
                printf("\nID no valido\n");
            }
        } else {
            printf("\nNo se ha encontrado registros de empleados\n");
        }
        break;
    case 3:
        if(isEmpty(list, TAM) == 0){
            printf("Ingrese ID del empleado: ");
            fflush(stdin);
            scanf("%d", &idToRemove);
            if(removeEmployee(list, TAM, idToRemove) == 0){
                printf("\nSe ha removido los datos del empleador\n");
            } else {
                printf("\nNo se ha podido realizar la operacion. Reintente\n");
            }
        } else {
            printf("\nNo se ha encontrado registros de empleados\n");
        }
        break;
    case 4:
        if(isEmpty(list, TAM) == 0){
            printEmployees(list, TAM);
            showSortOptions();
        } else {
            printf("\nNo se ha encontrado registros de empleados\n");
        }
        break;
    case 5:
        finish = 1;
        break;
    default:
        printf("\nIngrese una opcion valida\n");
        break;
    }
}
void showSortOptions(){
    int i;
    int operationType = -1;
    int orderType = -1;

    printf("\n\nCero(0) para ordenar por sector | (1) para salir del informe: ");
    fflush(stdin);
    scanf(" %d", &operationType);
    switch(operationType){
    case 0:
        printf("\nOrdenar por sector Ascendente(0) Descendente(1): ");
        fflush(stdin);
        scanf(" %d", &orderType);
        system("cls");
        if (sortEmployeesBySector(list, TAM, orderType) == 0){
            printf("\nLa lista se ha ordenado exitosamente\n");
        } else {
            printf("\nOpcion no valida\n");
        }
        break;
    case 1:
        break;
    default:
        printf("\nOpcion no valida\n");
        break;
    }
}
