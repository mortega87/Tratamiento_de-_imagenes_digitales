/**
  *   
  * @file video.h
  * @brief Fichero cabecera del Tipo video
  * @author Manuel Jesús García Manday
  * 
  */

#ifndef _VIDEO_H_
#define _VIDEO_H_


#include <iostream>
#include <imagen.h>
#include <list>
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
class Video{
	private:
	
		int num_fotogramas;
		list<T> fotogramas;
		
	public:
	
		/**
		* @brief Constructor por defecto
		* 
		* Crear una video en memoria con número de fotogramas inicializados a 0
		*/	
		Video();
		
		/**
		* @brief Constructor por parametros
		* @param l indica la lista de fotogramas que contendrá el video
		* 
		*/		
		Video(list<T> &l);
		
		/**
		 * @brief Constructor de copias
		 * @param Vid es el video original
		 */		
		Video(const Video &Vid); 
		
		/**
		 * @brief Destructor de la clase Video
		 */		
		~Video();
		
		/**
		 * @brief Calcular el numero de fotogramas del video
		 * @return int, Numero de fotogramas del video
		 */		
		int numero_fotogramas() const;
		
		/**
		 * @brief Devuelve un fotograma
		 * @param n es la posicion del fotograma
		 * @return una referencia al fotograma (n)
		 */		
		T & operator()(int n);
		
		/**
		 * @brief Devuelve un fotograma
		 * @param n es la posicion del fotograma
		 * @return una referencia al fotograma (n)
		 */		
		const T & operator()(int n) const;
		
		/**
		 * @brief Operador de asignacion para tipo Video
		 * @param Vid es el video original
		 * @return Devuelve una referencia a video 
		 */		
		Video<T>& operator=(const Video<T> &Vid);
		
		/**
		  * @brief Modificamos el valor de un fotograma
		  * @param n es el número de fotograma
		  * @param i es el nuevo elemento a insertar en la lista
		*/		
		void set(int f, const T &i);	
		
		/**
		  * @brief Insertamos un fotograma
		  * @param i es el nuevo elemento a insertar en la lista
		*/		
		void set(const T &i);
		
		/**
		  * @brief Operador de comparación de igualdad
		  * @param V Video con el que se desea comparar.
		  * @return Devuelve \e true si el video receptor tiene el mismo numero
		  * de fotogramas, y si son iguales cada fotograma,
		  * y \e false en caso contrario.
		  *
		  * La operación se realiza en tiempo O(n).
		*/
		bool operator==(const Video<T> &V);
		
		/**
		  * @brief Operador de comparación de desigualdad
		  * @param V Video con el que se desea comparar.
		  * @return Devuelve \e true si el video receptor no tiene el mismo numero
		  * de fotogramas, y si son iguales cada fotograma,
		  * y \e false en caso contrario.
		  *
		  * La operación se realiza en tiempo O(n).
		*/
		bool operator!=(const Video<T> &V);
		
		/**
		  * @brief Insertar un nuevo fotograma
		  * @param I fotograma que se insertara
		  * @return Devuelve la referencia al objeto Video al que se le 
		  * introduce el fotograma
		*/
		typename Video<T>::iterator Insertar(typename Video<T>::iterator it, const T &I);
		
			
		class iterator{	
		    private:
			  typename list<T>::iterator aux_fotogramas;
			  iterator(typename list<T>::iterator m);
			  friend class Video<T>;
		    public:
			  iterator();
			  iterator(const iterator & i);
			  bool operator!=(const iterator & i) const;
			  bool operator==(const iterator & i) const;
			  iterator & operator=(const iterator & i);
			  T & operator*();
			  iterator & operator++();		    
		}; 
		
		iterator begin();
		iterator end();
		
		class const_iterator{	
		    private:
			  typename list<T>::iterator aux_fotogramas;
			  const_iterator(typename list<T>::const_iterator m);
			  friend class Video<T>;
		    public:
			  const_iterator();
			  const_iterator(const const_iterator & i);
			  bool operator!=(const const_iterator & i) const;
			  bool operator==(const const_iterator & i) const;
			  const_iterator & operator=(const const_iterator & i);
			  T & operator*();
			  const_iterator & operator++();		    
		}; 
		
		const_iterator begin() const;
		const_iterator end() const;
};

#include "video.cpp"

#endif

/* Fin Fichero: video.h */
		
		
