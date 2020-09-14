#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include "lib.h"

int main()
{
    char estado = 'n';
    char inputA[20];
    char inputB[20];
    int numeroA;
    int numeroB;
    char operacion;
    char salir = 'n';
    int estadoSalir = 0;

    while(estado == 'n') {
        system ("CLS");
        printf("**Opciones**\n");
        printf("A - Suma\n");
        printf("B - Resta\n");
        printf("C - Division\n");
        printf("D - Multiplicacion\n");
        printf("E - Factorial\n");
        printf("F - Salir\n");
        printf("Eliga una opcion: ");
        fflush(stdin);
        scanf(" %c", &operacion);

        if(operacion == 'f'){
            estadoSalir = 0;
            while(estadoSalir == 0){
                system("cls");
                printf("Esta seguro que desea salir?(S/N): ");
                fflush(stdin);
                scanf(" %c", &salir);

                switch(salir){
                case 's':
                    /*exit(EXIT_SUCCESS);*/
                    estadoSalir = 1;
                    estado = 's';
                    break;
                case 'n':
                    estadoSalir = 1;
                    break;
                default:
                    printf("No valido, ingrese de nuevo");
                    getch();
                }
            }
        } else if (operacion == 'a' || operacion == 'b' || operacion == 'c' || operacion == 'd' || operacion == 'e' ){
            printf("Ingrese el primer numero: ");
            fflush(stdin);
            scanf("%s", &inputA);
            printf("Ingrese el segundo numero: ");
            fflush(stdin);
            scanf("%s", &inputB);

            if(validateInputNumber(inputA) == 0 || validateInputNumber(inputB) == 0){
                printf("\nINGRESE SOLO NUMEROS");
                getch();
            } else {
                numeroA = atoi(inputA);
                numeroB = atoi(inputB);
                switch(operacion){
                case 'a':
                    printf("El resultado de A+B es: %d", funcSuma(numeroA, numeroB));
                    printf("\nPresione cualquier tecla para continuar\n");
                    getch();
                    break;

                case 'b':
                    printf("El resultado de A-B es: %d", funcResta(numeroA, numeroB));
                    printf("\nPresione cualquier tecla para continuar\n");
                    getch();
                    break;

                case 'c':
                    printf("El resultado de A/B es: %d", funcDivision(numeroA, numeroB));
                    printf("\nPresione cualquier tecla para continuar\n");
                    getch();
                    break;
                case 'd':
                    printf("El resultado de A*B es: %d", funcMultiplicacion(numeroA, numeroB));
                    printf("\nPresione cualquier tecla para continuar\n");
                    getch();
                    break;

                case 'e':
                    if(numeroA > 0 && numeroB > 0){
                        printf("El factorial de A es: %d y El factorial de B es: %d", funcFactorial(numeroA), funcFactorial(numeroB));
                        printf("\nPresione cualquier tecla para continuar\n");
                        getch();
                    } else {
                        printf("El numero negativo no es permitido para esta operacion");
                        printf("\nPresione cualquier tecla para continuar\n");
                        getch();
                    }
                    break;
                }
            }
        } else {
            printf("\nOpcion ingresada no valida, vuelva a intentarlo\n");
            getch();
        }
    }
    return 0;
}
