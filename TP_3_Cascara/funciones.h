#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    int id;
    char titulo[50];
    char genero[50];
    int duracion;
    char descripcion[250];
    int puntaje;
    char linkImagen[250];
    int estado;
}eMovie;

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @param tamaño de la estructura pasada por parametro
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(eMovie[],int);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 * \param tamaño de la estructura pasada por parametro
 */
int borrarPelicula(eMovie*, int);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 * \param tamaño de la estructura pasada por parametro
 */
void generarPagina(eMovie[], char[],int);

#endif // FUNCIONES_H_INCLUDED


/** \brief Guarda los datos ingresados o modificados en un fichero
 *
 * \param la lista de peliculas a ser agregadas en el archivo
 * \param tamaño de la estructura pasada por parametro
 * \return retorna 1 o 0 de acuerdo a si pudo guardar las peliculas o no
 *
 */
int guardar(eMovie*,int);


/** \brief Carga desde un archivo las peliculas en un estructura o crea el archivo si no existiera
 *
 * \param la lista de peliculas a ser agregadas del archivo
 * \param tamaño de la estructura pasada por parametro
 * \return retorna 1 o 0 de acuerdo a si pudo cargar las peliculas o no
 *
 */
int cargar(eMovie*, int);


/** \brief Lista las peliculas cargadas hasta el momento
 *
 * \param lista de peliculas a ser mostradas
 * \param cantidad de peliculas
 * \param opcion de mostrar - 1 para mostrar todos los campos y 2 para mostrar solo id y titulo de pelicula
 *
 */
void mostrarPeliculas(eMovie*, int, int);


/** \brief Pide id de una pelicula y muestra un menu de seleccion para modificar la pelicula
 *
 * \param lista de peliculas a ser mostradas
 * \param cantidad de peliculas
 * \return Retorna 1 si no encontro el id
 *
 */
int modificarPelicula(eMovie*, int);
