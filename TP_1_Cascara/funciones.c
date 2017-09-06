int ingresaNumero()//pide al usuario ingresar un numero entero y lo devuelve
{
    int num;
    printf("Ingrese un numero:\n");
    scanf("%d", &num);
    return num;
}

void suma(int n1,int n2)//suma dos numeros enteros y devuelve el resultado
{
    printf("\nResultado de la suma: %d\n",n1+n2);
}

void resta(int n1,int n2)
{
    printf("\nResultado de la resta: %d\n",n1-n2);
}

void division(int n1,int n2)
{
    float result;
    if(n2==0)
    {
        printf("\nError. Ingrese un numero diferente a 0.\n");
    }
    else
    {
        result=(float)n1/(float)n2;
        printf("\nResultado de la division: %.1f\n",result);
    }
}

void multiplicacion(int n1,int n2)
{
    printf("\nResultado de la multiplicacion: %d\n",n1*n2);
}

void factorial(int n1)
{
    int acum=1;
    int i;
    int aux;
    aux = n1;
    aux = abs(aux);
    for(i=aux;i>0;i--)
        {
            acum*=i;
        }
    if(n1>=0)
    {
        printf("\nResultado del factorial de %d: %d\n",n1,acum);
    }
    else
    {
        printf("\nResultado del factorial de %d: -%d\n",n1,acum);
    }

}
