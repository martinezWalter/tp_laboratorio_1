#include "ArrayEmployee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Employee* employees;

int initEmployees(Employee* list, int len){
    size_t NumberOfElements = sizeof(list)/sizeof(list[len]);
    if (list != NULL && NumberOfElements > 0) {

        return 1;
    }
    return 0;
}

int addEmployee(Employee* list, int len, int id, char name[51], char lastName[51], float salary, int sector){
    int error = -1;
    int indice;
    Employee employee;

    if (len > 0 && id > 0){
        indice = buscarLibre(list, len);
        if(indice == -1){
            printf("\nEl sistema esta completo\n");
        } else {
            employee.isEmpty = 1;
            strcpy(employee.name, name);
            strcpy(employee.lastName, lastName);
            employee.salary = salary;
            employee.sector = sector;
            employee.id = id;

            list[indice] = employee;
            error = 0;
        }
    } else {
        printf("null");
    }
    return error;
}

int findEmployeeById(Employee* list, int len, int id){
    int i;
    for(i = 0; i<len; i++){
        if(list[i].id == id){
            return 0;
        }
    }
    return -1;
}

int printEmployees(Employee* list, int len){
    int error = -1;
    int i;
    printf("  ID  |  NOMBRE  |  APELLIDO  |  SALARIO  |  SECTOR  ");
    for(i=0;i<len;i++){
        if(list[i].id > 0){
            mostrarDatosEmployee(list[i]);
            error = 0;
        }
    }
    return error;
}

int buscarLibre(Employee* list, int tam){
    int indice = -1;
    int i;
    for(i=0;i<tam;i++){
        if(list[i].isEmpty == 0){
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarDatosEmployee(Employee employee){
    printf("\n  %d        %s        %s     %.2f     %d     ", employee.id, employee.name, employee.lastName, employee.salary, employee.sector);
}

int removeEmployee(Employee* list, int len, int id){
    int error = -1;
    int i;
    int j;
    for(i = 0; i<len; i++){
        if(id == list[i].id){
            for(j=i;j<len;j++){
                list[j]=list[j+1];
            }
            len--;
            i--;
            error = 0;
        }
    }
    return error;
}

int updateEmployee(Employee* list, int len, int id, char name[51], char lastName[51], float salary, int sector){
    int i;
    for(i = 0; i<len; i++){
        if(list[i].id == id){
            list[i].isEmpty = 1;
            strcpy(list[i].name, name);
            strcpy(list[i].lastName, lastName);
            list[i].salary = salary;
            list[i].sector = sector;
            return 0;
        }
    }
    return -1;
}
int sortEmployeesBySector(Employee* list, int len, int order){
    int error = -1;
    int i;
    int j;
    Employee flag;

    for(i = 0; i < len; i++) {
        for (j = i + 1; j < len; j++){
            if(order == 0){
                if (list[i].sector > list[j].sector) {
                    flag =  list[i];
                    list[i] = list[j];
                    list[j] = flag;
                }
                error = 0;
            } else if (order == 1){
                if (list[i].sector < list[j].sector) {
                    flag =  list[i];
                    list[i] = list[j];
                    list[j] = flag;
                }
                error = 0;
            }
        }
    }
    if(error == 0){
        printEmployees(list, len);
    }
    return error;
}

int isEmpty(Employee* list, int len){
    int isEmpty = -1;
    int i;
    for(i = 0; i<len; i++){
        if(list[i].isEmpty == 1){
            isEmpty = 0;
            break;
        }
    }
    return isEmpty;
}
