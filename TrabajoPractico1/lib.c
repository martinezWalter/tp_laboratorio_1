#include "lib.h"

int funcSuma(int numA, int numB){
    return numA + numB;
}

int funcResta(int numA, int numB){
    return numA - numB;
}

int funcDivision(int numA, int numB){
    return numA / numB;
}

int funcMultiplicacion(int numA, int numB){
    return numA * numB;
}

int funcFactorial(int num){
    int factorial = 1;
    while(num != 0){
        factorial = factorial * num;
        num--;
    }
    return factorial;
}

int validateInputNumber(char numero[]){
    int i;
    for(i = 0; i<strlen(numero); i++){
        if(!isdigit(numero[i]) && !(numero[0] == '-')){
            return 0;
        }
    }
    return 1;
}
