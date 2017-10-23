#include "funciones.h"
#include <stdio.h>
#include <string.h>

int agregarPelicula(eMovie movie[], int sizeMovie)
{
    char tit[50];
    char gen[50];
    int dur;
    char desc[250];
    int punt;
    char link[250];
    int i;
    int flag = 0;

    /*FILE* archivo;
    archivo = fopen("peliculas.dat","wb");
    if(archivo == NULL)
    {
        return 1;
    }*/
    printf("== AGREGAR PELICULA ==\n\n");
    printf("Titulo: ");
    fflush(stdin);
    scanf("%50[^\n]s",&tit);

    printf("Genero: ");
    fflush(stdin);
    scanf("%50[^\n]s",&gen);

    printf("Duracion: ");
    fflush(stdin);
    scanf("%d",&dur);

    printf("Descripcion: ");
    getchar();
    fflush(stdin);
    scanf("%250[^\n]s",&desc);

    printf("Puntuacion: ");
    fflush(stdin);
    scanf("%d",&punt);

    printf("Link de imagen de portada: ");
    getchar();
    fflush(stdin);
    scanf("%250[^\n]s",&link);

    fflush(stdin);

    for(i=0;i<sizeMovie;i++)
    {
        if(movie[i].estado == 0)
        {
            movie[i].id = i+1;
            strcpy(movie[i].titulo,tit);
            strcpy(movie[i].genero,gen);
            movie[i].duracion = dur;
            strcpy(movie[i].descripcion,desc);
            movie[i].puntaje = punt;
            strcpy(movie[i].linkImagen,link);
            movie[i].estado = 1;
            flag = 1;
            break;
        }
    }
    if(flag == 0)
        return 1;

    /*for(i=0;i<sizeMovie;i++)
    {
        if(movie[i].estado != 0)
        printf("%s - %s - %d - %s - %d - %s\n",movie[i].titulo,movie[i].genero,movie[i].duracion,movie[i].descripcion,movie[i].puntaje,movie[i].linkImagen);
    }*/
    system("pause");
    return 0;
}

int guardar(eMovie* movie, int sizeMovie)
{
    FILE* archivo;

    archivo = fopen("peliculas.dat","wb");
    if(archivo == NULL)
    {
        return 1;
    }

    fwrite(movie,sizeof(eMovie),sizeMovie,archivo);

    fclose(archivo);

    system("pause");
}

int cargar(eMovie* movie, int sizeMovie)
{
    FILE* archivo;

    archivo = fopen("peliculas.dat","rb");
    if(archivo == NULL)
    {
        archivo = fopen("peliculas.dat","wb");
        if(archivo == NULL)
        {
            return 1;
        }
    }

    fread(movie,sizeof(eMovie),sizeMovie,archivo);

    fclose(archivo);
    return 0;
}

int borrarPelicula(eMovie* movie, int sizeMovie)
{
    int i;
    int idP;
    int flag = 0;
    int retorno;

    for(i=0;i<sizeMovie;i++)
    {
        if(movie[i].estado != 0)
            printf("%d - %s\n",movie[i].id,movie[i].titulo);
    }
    printf("\nIngrese la id de la pelicula que quiere borrar:\n");
    scanf("%d",&idP);

    for(i=0;i<sizeMovie;i++)
    {
        if(movie[i].estado != 0 && movie[i].id == idP)
        {
            movie[i].estado = 0;
            movie[i].id = 0;
            flag = 1;
            break;
        }
    }

    if(flag==0) //si no existe la id
        return 1;

    retorno = guardar(movie,sizeMovie);
    if(retorno==1)
        return 1;

    printf("Borrado exitoso!\n");
    system("cls");
    mostrarPeliculas(movie,sizeMovie,2);
    printf("\n");
    system("pause");

    return 0;
}


void generarPagina(eMovie movie[], char nombre[], int sizeMovie)
{
    int i;
    FILE* archivo;
    //int tamBuffer = 1000*sizeMovie;
    //char buffer[tamBuffer]={};
    //char buffer[20000]={};
    char* buffer;
    char punt[10];
    char dur[10];
    int cont = 0;

    buffer = (char*)malloc(sizeof(char)*(sizeMovie*1000));
    if(buffer == NULL)
    {
        printf("\nNo se pudo generar la pagina.\n");
    }
    else
    {
        strcat(buffer,"<!DOCTYPE html><html lang='es'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><title>Lista peliculas</title><link href='css/bootstrap.min.css' rel='stylesheet'><link href='css/custom.css' rel='stylesheet'></head><body style='background-color:#000'><div class='container'><div class='row'>");
        for(i=0;i<sizeMovie;i++)
        {
            if(movie[i].estado != 0)
            {
                if(cont==3)
                {
                    strcat(buffer,"</div><div class='row'>");
                    cont=0;
                }
                strcat(buffer,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='");
                strcat(buffer, movie[i].linkImagen);
                strcat(buffer,"' alt=''></a><h3 style='text-align:center'><a href='#'>");
                strcat(buffer, movie[i].titulo);
                strcat(buffer, "</a></h3><ul><li>Género:");
                strcat(buffer, movie[i].genero);
                strcat(buffer,"</li><li>Puntaje:");
                itoa(movie[i].puntaje,punt,10);
                strcat(buffer, punt);
                strcat(buffer,"</li><li>Duración:");
                itoa(movie[i].duracion,dur,10);
                strcat(buffer, dur);
                strcat(buffer,"</li></ul><p>");
                strcat(buffer, movie[i].descripcion);
                strcat(buffer,"</p></article>");
                cont++;
            }
        }
        strcat(buffer,"</div></div><script src='js/jquery-1.11.3.min.js'></script><script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'></script><script src='js/holder.min.js'></script></body></html>");

        archivo = fopen(nombre,"wb");
        if(archivo == NULL)
        {
            printf("No se pudo generar el archivo...");
            system("pause");
        }

        fprintf(archivo,buffer);
        fclose(archivo);
        free(buffer);
    }
}

void mostrarPeliculas(eMovie* movie, int sizeMovie,int num)
{
    int i;

    if(num == 1)
    {
        for(i=0;i<sizeMovie;i++)
        {
            if((movie+i)->estado != 0)
            printf("---> %s\n - %s\n - %d\n - %s\n - %d\n - %s\n\n",(movie+i)->titulo,(movie+i)->genero,(movie+i)->duracion,(movie+i)->descripcion,(movie+i)->puntaje,(movie+i)->linkImagen);
        }
    }
    else
    {
        for(i=0;i<sizeMovie;i++)
        {
            if((movie+i)->estado != 0)
            printf("%d - %s\n",(movie+i)->id,(movie+i)->titulo);
        }
    }

}

int modificarPelicula(eMovie* movie, int sizeMovie)
{
    int i;
    int idP;
    char tit[50];
    char gen[50];
    int dur;
    char desc[250];
    int punt;
    char link[250];
    int seleccion;
    int iPelicula;
    int flag = 0;
    char seguir = 's';

    mostrarPeliculas(movie,sizeMovie,2);
    printf("\nIngrese el id de la pelicula que desea modificar: ");
    scanf("%d",&idP);

    for(i=0;i<sizeMovie;i++)
    {
        if((movie+i)->estado != 0 && (movie+i)->id == idP)
        {
            iPelicula = i;
            flag = 1;
            break;
        }
    }
    if(flag==0) //si no existe la id
        return 1;

    while(seguir == 's')
    {
        printf("MODIFICAR PELICULA\n\n");
        printf("1- Titulo: %s\n",(movie+iPelicula)->titulo);
        printf("2- Genero: %s\n",(movie+iPelicula)->genero);
        printf("3- Duracion: %d\n",(movie+iPelicula)->duracion);
        printf("4- Descripcion: %s\n",(movie+iPelicula)->descripcion);
        printf("5- Puntaje: %d\n",(movie+iPelicula)->puntaje);
        printf("6- Imagen\n");
        printf("7- Salir a menu principal\n\n");
        printf("Elija lo que desea modificar: ");
        scanf("%d",&seleccion);

        switch(seleccion)
        {
        case 1:
            printf("\nIngrese titulo nuevo: ");
            fflush(stdin);
            scanf("%50[^\n]s",&tit);
            strcpy((movie+iPelicula)->titulo,tit);
            printf("1- Titulo: %s\n",(movie+iPelicula)->titulo);
            printf("Desea seguir modificando la pelicula? S/N ");
            seguir = tolower(seguir);
            fflush(stdin);
            scanf("%c",&seguir);
            break;
        case 2:
            printf("\nIngrese el genero nuevo: ");
            fflush(stdin);
            scanf("%50[^\n]s",&gen);
            strcpy((movie+iPelicula)->genero,gen);
            printf("Desea seguir modificando la pelicula? S/N ");
            seguir = tolower(seguir);
            fflush(stdin);
            scanf("%c",&seguir);
            break;
        case 3:
            printf("\nIngrese la nueva duracion: ");
            fflush(stdin);
            scanf("%d",&dur);
            (movie+iPelicula)->duracion = dur;
            printf("Desea seguir modificando la pelicula? S/N ");
            seguir = tolower(seguir);
            fflush(stdin);
            scanf("%c",&seguir);
            break;
        case 4:
            printf("\nIngrese la nueva descripcion: ");
            fflush(stdin);
            scanf("%250[^\n]s",&desc);
            strcpy((movie+iPelicula)->descripcion,desc);
            printf("Desea seguir modificando la pelicula? S/N ");
            seguir = tolower(seguir);
            fflush(stdin);
            scanf("%c",&seguir);
            break;
        case 5:
            printf("\nIngrese el nuevo puntaje: ");
            fflush(stdin);
            scanf("%d",&punt);
            (movie+iPelicula)->puntaje = punt;
            printf("Desea seguir modificando la pelicula? S/N ");
            seguir = tolower(seguir);
            fflush(stdin);
            scanf("%c",&seguir);
            break;
        case 6:
            printf("\nIngrese el nuevo link de la imagen: ");
            fflush(stdin);
            scanf("%250[^\n]s",&link);
            strcpy((movie+iPelicula)->linkImagen,link);
            printf("Desea seguir modificando la pelicula? S/N ");
            seguir = tolower(seguir);
            fflush(stdin);
            scanf("%c",&seguir);
            break;
        case 7:
            seguir = 'n';
            break;
        default:
            printf("\nSeleccion incorrecta!\n");
            break;
        }
    }
    if(flag==0) //si no existe la id
        return 1;

    //printf("---> %s\n - %s\n - %d\n - %s\n - %d\n - %s\n\n",(movie+iPelicula)->titulo,(movie+iPelicula)->genero,(movie+iPelicula)->duracion,(movie+iPelicula)->descripcion,(movie+iPelicula)->puntaje,(movie+iPelicula)->linkImagen);
    system("pause");

}
