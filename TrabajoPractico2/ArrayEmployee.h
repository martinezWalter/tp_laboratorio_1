#ifndef ARRAYEMPLOYEE_H_INCLUDED
#define ARRAYEMPLOYEE_H_INCLUDED

struct {
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}typedef Employee;

void mostrarDatosEmployee(Employee employee);

int initEmployees(Employee* list, int len);
int addEmployee(Employee*, int len, int id, char name[], char lastName[], float salary, int sector);
int findEmployeeById(Employee* list, int len, int id);
int printEmployees(Employee* list, int len);
int buscarLibre(Employee* list, int tam);
int removeEmployee(Employee* list, int len, int id);
int sortEmployeesBySector(Employee* list, int len, int order);
int updateEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector);
int isExistEmployee(Employee* list, int len, int id);
int isEmpty(Employee* list, int len);
#include "ArrayEmployee.c"
#endif // ARRAYEMPLOYEE_H_INCLUDED
