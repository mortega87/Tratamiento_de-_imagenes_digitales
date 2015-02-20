/**
  * @file imagen.cpp
  * @brief Fichero con definiciones para el TDA Imagen
  *
  *
  */


#include <cassert>

#include <imagen.h>

using namespace std;


template <class T>
Imagen<T>::Imagen(){
	
	filas = 0;
	cols = 0;
	img = new T *;
  
}

/*----------------------------------------------------------------------------------------*/

template <class T>
Imagen<T>::Imagen(int fils, int columnas){
	
	filas = fils;
	cols = columnas;
	
	img = new T*[filas];
	
	for(int i = 0; i < filas; i++){
		img[i] = new T[cols];
		for(int j = 0; j < cols; j++)
		    img[i][j] = 0;
	}		

}

/*----------------------------------------------------------------------------------------*/

template <class T>
Imagen<T>::Imagen(unsigned char *image, int fils, int columnas){
	
	filas = fils;
	cols = columnas;
	
	img = new T*[filas];
	
	for(int i = 0, s = 0; i < filas; i++){
		img[i] = new T[cols];
		for(int j = 0; j < cols; j++, s++)
		    img[i][j] = image[s];
	}		

}

/*-----------------------------------------------------------------------------------------*/

template <class T>
Imagen<T>::Imagen(const Imagen &Img){
	
	filas = Img.filas;
	cols = Img.cols;
	
	img = new T*[filas];
	
	for(int i = 0; i < filas; i++){
		img[i] = new T[cols];
		for(int c = 0; c < cols; c++)
		    img[i][c] = Img.img[i][c];
	}
			
}


/*-----------------------------------------------------------------------------------------*/

template <class T>
Imagen<T>::~Imagen(){
	
	for(int f = 0; f < filas; f++)
		delete img[f];
	delete [] img;
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
int Imagen<T>::num_filas() const{
	return filas;
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
int Imagen<T>::num_columnas() const{
	return cols;
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
T & Imagen<T>::operator()(int fila, int col){
	
	assert((fila >= 0) && (fila <= filas));
	assert((col >= 0) && (col <= cols));
 
	return img[fila][col];
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
const T & Imagen<T>::operator()(int fila, int col) const{
	
	assert((fila >= 0) && (fila < filas));
	assert((col >= 0) && (col < cols));
 
	return *(img[fila][col]);
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
Imagen<T>& Imagen<T>::operator=(const Imagen<T> &I){
	
	if((filas == I.filas) && (cols == I.cols))
	    for(int i = 0; i < filas; i++)
		for(int j = 0; j < cols; j++)
		    img[i][j] = I.img[i][j];
		
	return *this;
		
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
bool Imagen<T>::operator==(const Imagen<T> &I){
  
	if((filas != I.filas) || (cols != I.cols))
	    return false;
	
	for(int i = 0; i < filas; i++){
	    for(int j = 0; j < cols; j++)
		if(img[i][j] != I.img[i][j])
		    return false;
	}
	
	return true;
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
bool Imagen<T>::operator!=(const Imagen<T> &I){
  
	return !(*this != I);
}
			
/*-----------------------------------------------------------------------------------------*/

template <class T>
void Imagen<T>::set(int f, int c, const T &v){
		
	img[f][c] = v;
		
}	

/*-----------------------------------------------------------------------------------------*/

template <class T>
Imagen<T>& Imagen<T>::EscribirEnImagen(unsigned char *image){
  
       
      for(int i = 0, s = 0; i < filas; i++){
	  for(int j = 0; j < cols; j++, s++){
	      img[i][j] = image[s];
	  }
      }
      
      
      return *this;
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
unsigned char * Imagen<T>::ConvertirImagen(){
      unsigned char * im = new unsigned char[filas*cols]; 
  
      for(int i = 0, s = 0; i < filas; i++){
	  for(int j = 0; j < cols; j++, s++)
	      im[s] = img[i][j];
      }
      
      return im;
}

/*-----------------------------------------------------------------------------------------*/	
/*******************************************************************************************/
/*			      IMPLEMENTACIÓN CLASE ITERATOR_FILA			     */
/******************************************************************************************/
/*-----------------------------------------------------------------------------------------*/
		
template <class T>
Imagen<T>::iterator_fila::iterator_fila(){
    
	data_filas = new T*;
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
Imagen<T>::iterator_fila::iterator_fila(T** aux){
  
	data_filas = aux;
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
Imagen<T>::iterator_fila::iterator_fila(const iterator_fila & i){
  
	data_filas = i.data_filas;
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
bool Imagen<T>::iterator_fila::operator!=(const iterator_fila & i) const{
  
	if(data_filas != i.data_filas)
	    return true;
	else
	    return false;
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
bool Imagen<T>::iterator_fila::operator==(const iterator_fila & i) const{
  
      return !(data_filas != i.data_filas);
}

/*-----------------------------------------------------------------------------------------*/
    
template <class T>
typename Imagen<T>::iterator_fila & Imagen<T>::iterator_fila::operator=(const iterator_fila & i){
  
      data_filas = i.data_filas;
    
      return *this;
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
typename Imagen<T>::iterator_fila & Imagen<T>::iterator_fila::operator*(){
  
         
      return *this;
    
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
typename Imagen<T>::iterator_fila & Imagen<T>::iterator_fila::operator++(){
  
     data_filas++;
      
     return *this;
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
typename Imagen<T>::iterator_fila Imagen<T>::begin(){
  
      return iterator_fila(img);
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
typename Imagen<T>::iterator_fila Imagen<T>::end(){
  
	T** aux_img = img;
        for(int i = 0; i < filas; i++)
	    aux_img++;
	
	return iterator_fila(aux_img);
	
}

/*-----------------------------------------------------------------------------------------*/	
/*******************************************************************************************/
/*			      IMPLEMENTACIÓN CLASE CONST_ITERATOR_FILA			     */
/******************************************************************************************/
/*-----------------------------------------------------------------------------------------*/
		
template <class T>
Imagen<T>::const_iterator_fila::const_iterator_fila(){
    
	data_filas = new T*;
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
Imagen<T>::const_iterator_fila::const_iterator_fila(T** aux){
  
	data_filas = aux;
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
Imagen<T>::const_iterator_fila::const_iterator_fila(const const_iterator_fila & i){
  
	data_filas = i.data_filas;
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
bool Imagen<T>::const_iterator_fila::operator!=(const const_iterator_fila & i) const{
  
	if(data_filas != i.data_filas)
	    return true;
	else
	    return false;
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
bool Imagen<T>::const_iterator_fila::operator==(const const_iterator_fila & i) const{
  
      return !(data_filas != i.data_filas);
}

/*-----------------------------------------------------------------------------------------*/
    
template <class T>
typename Imagen<T>::const_iterator_fila & Imagen<T>::const_iterator_fila::operator=(const const_iterator_fila & i){
  
      data_filas = i.data_filas;
    
      return *this;
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
typename Imagen<T>::const_iterator_fila & Imagen<T>::const_iterator_fila::operator*(){
  
         
      return *this;
    
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
typename Imagen<T>::const_iterator_fila & Imagen<T>::const_iterator_fila::operator++(){
  
     data_filas++;
      
     return *this;
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
typename Imagen<T>::const_iterator_fila Imagen<T>::begin() const{
  
      return const_iterator_fila(img);
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
typename Imagen<T>::const_iterator_fila Imagen<T>::end() const{
  
	T** aux_img = img;
        for(int i = 0; i < filas; i++)
	    aux_img++;
	
	return const_iterator_fila(aux_img);
	
}

/*-----------------------------------------------------------------------------------------*/
/*******************************************************************************************/
/*			      IMPLEMENTACIÓN CLASE ITERATOR_COLUMNA			     */
/******************************************************************************************/
/*-----------------------------------------------------------------------------------------*/

template <class T>
Imagen<T>::iterator_fila::iterator_columna::iterator_columna(){
  
      data_columnas = new T;
      
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
Imagen<T>::iterator_fila::iterator_columna::iterator_columna(T* maux){
  
      data_columnas = maux;
      
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
Imagen<T>::iterator_fila::iterator_columna::iterator_columna(const iterator_columna & c){
  
      data_columnas = c.data_columnas;
      
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
bool Imagen<T>::iterator_fila::iterator_columna::operator!=(const iterator_columna & c) const{
  
      if(data_columnas != c.data_columnas)
	  return true;
      else
	  return false;
	
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
bool Imagen<T>::iterator_fila::iterator_columna::operator==(const iterator_columna & c) const{
  
      return !(*this != c);
	
}

template <class T>
bool Imagen<T>::iterator_fila::iterator_columna::operator==(const T * c) const{
  
      if(data_columnas == c)
	 return true;
      else
	 return false;
	
}
/*-----------------------------------------------------------------------------------------*/

template <class T>
typename Imagen<T>::iterator_fila::iterator_columna & Imagen<T>::iterator_fila::iterator_columna::operator=(const iterator_columna & c){
  
      data_columnas = c.data_columnas;
      
      return *this;
      
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
T & Imagen<T>::iterator_fila::iterator_columna::operator*(){
  
      return *data_columnas;
      
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
T & Imagen<T>::iterator_fila::iterator_columna::operator++(){
  
      data_columnas++;
      return *data_columnas;
      
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
typename Imagen<T>::iterator_fila::iterator_columna Imagen<T>::iterator_fila::begin(){
  
      return iterator_columna(*data_filas);
      
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
typename Imagen<T>::iterator_fila::iterator_columna Imagen<T>::iterator_fila::end(){
  
      T* aux = *data_filas;
      int nc = img.num_columnas();
      for(int i = 0; i < nc; i++)
	  aux++;
      
      return iterator_columna(aux);
    
}

/*-----------------------------------------------------------------------------------------*/
/*******************************************************************************************/
/*			      IMPLEMENTACIÓN CLASE CONST_ITERATOR_COLUMNA			     */
/******************************************************************************************/
/*-----------------------------------------------------------------------------------------*/

template <class T>
Imagen<T>::const_iterator_fila::const_iterator_columna::const_iterator_columna(){
  
      data_columnas = new T;
      
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
Imagen<T>::const_iterator_fila::const_iterator_columna::const_iterator_columna(T* maux){
  
      data_columnas = maux;
      
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
Imagen<T>::const_iterator_fila::const_iterator_columna::const_iterator_columna(const const_iterator_columna & c){
  
      data_columnas = c.data_columnas;
      
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
bool Imagen<T>::const_iterator_fila::const_iterator_columna::operator!=(const const_iterator_columna & c) const{
  
      if(data_columnas != c.data_columnas)
	  return true;
      else
	  return false;
	
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
bool Imagen<T>::const_iterator_fila::const_iterator_columna::operator==(const const_iterator_columna & c) const{
  
      return !(*this != c);
	
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
bool Imagen<T>::const_iterator_fila:: const_iterator_columna::operator==(const T * c) const{
  
      if(data_columnas == c)
	 return true;
      else
	 return false;
	
}
/*-----------------------------------------------------------------------------------------*/

template <class T>
typename Imagen<T>::const_iterator_fila::const_iterator_columna & Imagen<T>::const_iterator_fila::const_iterator_columna::operator=(const const_iterator_columna & c){
  
      data_columnas = c.data_columnas;
      
      return *this;
      
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
T & Imagen<T>::const_iterator_fila::const_iterator_columna::operator*(){
  
      return *data_columnas;
      
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
T & Imagen<T>::const_iterator_fila::const_iterator_columna::operator++(){
  
      data_columnas++;
      return *data_columnas;
      
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
typename Imagen<T>::const_iterator_fila::const_iterator_columna Imagen<T>::const_iterator_fila::begin() const{
  
      return const_iterator_columna(*data_filas);
      
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
typename Imagen<T>::const_iterator_fila::const_iterator_columna Imagen<T>::const_iterator_fila::end() const{
  
      T* aux = *data_filas;
      int nc = img.num_columnas();
      for(int i = 0; i < nc; i++)
	  aux++;
      
      return const_iterator_columna(aux);
    
}

/*-----------------------------------------------------------------------------------------*/
