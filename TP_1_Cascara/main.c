#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int num1=0,num2=0;
    //int sum;

    while(seguir=='s')
    {
        system("cls");
        printf("####################################################\n#");
        printf("\t\t\t\t\t\t   #\n");
        printf("#\t1) Ingresar 1er operando (A=%d)",num1);
        printf("\t\t   #\n");
        printf("#\t2) Ingresar 2do operando (B=%d)",num2);
        printf("\t\t   #\n");
        printf("#\t3) Calcular la suma (A+B)");
        printf("\t\t   #\n");
        printf("#\t4) Calcular la resta (A-B)");
        printf("\t\t   #\n");
        printf("#\t5) Calcular la division (A/B)");
        printf("\t\t   #\n");
        printf("#\t6) Calcular la multiplicacion (A*B)");
        printf("\t   #\n");
        printf("#\t7) Calcular el factorial (A!)");
        printf("\t\t   #\n");
        printf("#\t8) Calcular todas las operaciones");
        printf("\t   #\n");
        printf("#\t9) Salir");
        printf("\t\t\t\t   #\n#");
        printf("\t\t\t\t\t\t   #\n");
        printf("####################################################\n\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                num1=ingresaNumero();
                break;
            case 2:
                system("cls");
                num2=ingresaNumero();
                break;
            case 3:
                system("cls");
                suma(num1,num2);
                printf("\n");
                system("pause");
                break;
            case 4:
                system("cls");
                resta(num1,num2);
                printf("\n");
                system("pause");
                break;
            case 5:
                system("cls");
                division(num1,num2);
                printf("\n");
                system("pause");
                break;
            case 6:
                system("cls");
                multiplicacion(num1,num2);
                printf("\n");
                system("pause");
                break;
            case 7:
                system("cls");
                factorial(num1);
                printf("\n");
                system("pause");
                break;
            case 8:
                system("cls");
                suma(num1,num2);
                resta(num1,num2);
                multiplicacion(num1,num2);
                division(num1,num2);
                factorial(num1);
                printf("\n");
                system("pause");
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
