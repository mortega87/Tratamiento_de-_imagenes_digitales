/**
  *   
  * @file imagen.h
  * @brief Fichero cabecera del Tipo imagen
  * @author Manuel Jesús García Manday
  * 
  */

#ifndef _IMAGEN_H_
#define _IMAGEN_H_


#include <iostream>
using namespace std;

/**
 *  @brief Tipo Imagen
 *
 * Una instancia de imagen es una matriz formada por doble puntero,
 * donde la primera posicion hace referencia a la primera posicion de la matriz.
 * Con filas hacemos referencia al numero de filas que la matriz va a contener
 * y con cols hacemos referencia al numero de columnas.
 * 
 */


template <class T>
class Imagen{
	private:
	
		int filas;
		int cols;
		T **img;
		
	public:
	
		/**
		* @brief Constructor por defecto
		* 
		* Crear una imagen en memoria con filas y columnas inicializadas a 0
		*/	
		Imagen();
		
		/**
		* @brief Constructor por parametros
		* @param filas indica el numero de filas
		* @param columnas indica el numero de columnas
		* 
		* Crear una imagen en memoria con "filas" filas y "cols" columnas
		*/		
		Imagen(int filas, int columnas);
		
		/**
		* @brief Constructor por parametros
		* @param filas indica el numero de filas
		* @param columnas indica el numero de columnas
		* @param image contiene los datos con los que se rellenará la matriz
		* Crear una imagen en memoria con "filas" filas y "cols" columnas, y con los datos que tenga image
		*/		
		Imagen(unsigned char *image, int filas, int columnas);
		
		/**
		 * @brief Constructor de copias
		 * @param Img es la matriz original
		 */		
		Imagen(const Imagen &Img); 
		
		/**
		 * @brief Destructor de la clase Imagen
		 */		
		~Imagen();
		
		/**
		 * @brief Calcular el numero de filas de la imagen
		 * @return int, Numero de filas de la imagen
		 */		
		int num_filas() const;
		
		/**
		 * @brief Calcular el numero de columnas de la imagen
		 * @return int, Numero de columnas de la imagen
		 */		
		int num_columnas() const;
		
		/**
		 * @brief Devuelve el valor del pixel en ("fila","col") de la imagen
		 * @param fila es la fila de la imagen 
		 * @param col es la columna de la imagen
		 * @return una referencia al pixel en (fila,col)
		 */		
		T & operator()(int fila, int col);
		
		/**
		 * @brief Devuelve el valor del pixel en ("fila","col") de la imagen
		 * @param fila es la fila de la imagen 
		 * @param col es la columna de la imagen
		 * @return una referencia al pixel en (fila,col) 
		 */		
		const T & operator()(int fila, int col) const;
		
		/**
		 * @brief Operador de asignacion para tipo Imagen
		 * @param Img es la imagen original
		 * @return Devuelve una referencia a imagen 
		 */		
		Imagen<T>& operator=(const Imagen<T> &Img);
		
		/**
		  * @brief Modificamos el valor de un pixel
		  * @param f es el numero de fila
		  * @param c es el numero de columna
		  * @param v es el nuevo elemento a insertar en la matriz
		*/		
		void set(int f, int c, const T &v);		
		
		/**
		  * @brief Operador de comparación de igualdad
		  * @param I Imagen con la que se desea comparar.
		  * @return Devuelve \e true si la imagen receptora tiene el mismo numero
		  * de filas y columnas, y en el mismo orden en los elementos de cada posicion,
		  * y \e false en caso contrario.
		  *
		  * La operación se realiza en tiempo O(n).
		*/
		bool operator==(const Imagen<T> &I);
		
		/**
		  * @brief Operador de comparación de desigualdad
		  * @param I Imagen con la que se desea comparar.
		  * @return Devuelve \e true si la imagen receptora no tiene el mismo numero
		  * de filas y columnas, y no tiene el mismo orden en los elementos de cada posicion,
		  * y \e false en caso contrario.
		  *
		  * La operación se realiza en tiempo O(n).
		*/
		bool operator!=(const Imagen<T> &I);
		
		/**
		  * @brief Función para escribir en un objeto Imagen
		  * @param I unsigned char que se escribirá en un TDA Imagen
		  * @return Devuelve la referencia al objeto imagen al que se le 
		  * introduce los valores que contiene el unsigned char
		*/
		Imagen<T>& EscribirEnImagen(unsigned char *image);
		
		/**
		  * @brief Función para pasar un objeto Imagen a un unsigned char
		  * @return Devuelve un unsigned char que contendrá los valores que
		  * contenía el objeto TDA Imagen 
		  *
		*/
		unsigned char * ConvertirImagen();
		
		
		class iterator_fila{	
		    private:
			  T** data_filas;
			  iterator_fila(T** m);
			  friend class Imagen<T>;
		    public:
			  iterator_fila();
			  iterator_fila(const iterator_fila & i);
			  bool operator!=(const iterator_fila & i) const;
			  bool operator==(const iterator_fila & i) const;
			  iterator_fila & operator=(const iterator_fila & i);
			  iterator_fila & operator*();
			  iterator_fila & operator++();
			  
		    class iterator_columna{
			  private:
				T* data_columnas;
				iterator_columna(T* maux);
				friend class Imagen<T>::iterator_fila;
			  public:
				iterator_columna();
				iterator_columna(const iterator_columna & c);
				bool operator!=(const iterator_columna & c) const;
				bool operator==(const iterator_columna & c) const;
				iterator_columna & operator=(const iterator_columna & c);
				bool operator==(const T* c) const;
				T & operator*();
				T & operator++();				
		    };
		    
		    iterator_columna begin();
		    iterator_columna end();
		}; 
		
		class const_iterator_fila{	
		    private:
			  T** data_filas;
			  const_iterator_fila(T** m);
			  friend class Imagen<T>;
		    public:
			  const_iterator_fila();
			  const_iterator_fila(const const_iterator_fila & i);
			  bool operator!=(const const_iterator_fila & i) const;
			  bool operator==(const const_iterator_fila & i) const;
			  const_iterator_fila & operator=(const const_iterator_fila & i);
			  const_iterator_fila & operator*();
			  const_iterator_fila & operator++();
			  
		    class const_iterator_columna{
			  private:
				T* data_columnas;
				const_iterator_columna(T* maux);
				friend class Imagen<T>::const_iterator_fila;
			  public:
				const_iterator_columna();
				const_iterator_columna(const const_iterator_columna & c);
				bool operator!=(const const_iterator_columna & c) const;
				bool operator==(const const_iterator_columna & c) const;
				const_iterator_columna & operator=(const const_iterator_columna & c);
				bool operator==(const T* c) const;
				T & operator*();
				T & operator++();				
		    };
		    
		    const_iterator_columna begin() const;
		    const_iterator_columna end() const;
		}; 
		
		iterator_fila begin();
		iterator_fila end();
		const_iterator_fila begin() const;
		const_iterator_fila end() const;
};

#include "imagen.cpp"

#endif

/* Fin Fichero: imagen.h */
		
		
