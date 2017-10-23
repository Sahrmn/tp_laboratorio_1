#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define TAM 10

int main()
{
    char seguir='s';
    int opcion=0;
    int i;
    eMovie peliculas[TAM];
    int comprobacion;

    for(i=0;i<TAM;i++)
    {
        peliculas[i].id = 0;
        peliculas[i].estado = 0;
    }

    comprobacion = cargar(peliculas,TAM);
    if(comprobacion == 1)
                {
                    printf("No se pudo cargar las peliculas.");
                    system("pause");
                }

    while(seguir=='s')
    {
        system("cls");
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Guardar\n");
        printf("6- Mostrar peliculas\n");
        printf("7- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                comprobacion = agregarPelicula(peliculas,TAM);
                if(comprobacion == 1)
                {
                    printf("No se pudo agregar la pelicula.");
                    system("pause");
                }
                break;
            case 2:
                system("cls");
                comprobacion = borrarPelicula(peliculas,TAM);
                if(comprobacion == 1)
                {
                    printf("\nNo se pudo borrar la pelicula.\n");
                    system("pause");
                }
                break;
            case 3: // modificar pelicula
                system("cls");
                comprobacion = modificarPelicula(peliculas,TAM);
                if(comprobacion == 1)
                {
                    printf("\nNo se encontro el id de la pelicula.\n");
                    system("pause");
                }
                break;
            case 4: //generar pagina web
                generarPagina(peliculas,"index.html",TAM);
                printf("\nPagina generada con exito!\n");
                system("pause");
               break;
            case 5: //guardar datos cargados
                comprobacion = guardar(peliculas, TAM);
                if(comprobacion == 1)
                {
                    printf("No se pudo guardar el archivo.");
                    system("pause");
                }
                if(comprobacion == 0)
                {
                    printf("\nGuardado correctamente!\n");
                    system("pause");
                }
                break;
            case 6:
                mostrarPeliculas(peliculas,TAM,1);
                system("pause");
                break;
            case 7:
                seguir = 'n';
                break;
            default:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
