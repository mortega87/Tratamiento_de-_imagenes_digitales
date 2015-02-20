/**
  * @file video.cpp
  * @brief Fichero con definiciones para el TDA Video
  *
  *
  */


#include <cassert>
#include <list>
#include <video.h>
#include <imagen.h>

using namespace std;


template <class T>
Video<T>::Video(){
    
      num_fotogramas = 0;
      
}

/*----------------------------------------------------------------------------------------*/

template <class T>
Video<T>::Video(list<T> &l){
  
      num_fotogramas = l.size();
      fotogramas = l;
      
}

/*----------------------------------------------------------------------------------------*/

template <class T>
Video<T>::Video(const Video &vid){
  
      fotogramas = vid.fotogramas;
      
}

/*----------------------------------------------------------------------------------------*/

template <class T>
Video<T>::~Video(){
  
      num_fotogramas = 0;
      fotogramas.clear();
      
}

/*----------------------------------------------------------------------------------------*/

template <class T>
int Video<T>::numero_fotogramas() const{
  
      return num_fotogramas;
      
}

/*----------------------------------------------------------------------------------------*/

template <class T>
T & Video<T>::operator()(int n){
  
      assert(num_fotogramas > 0);
      assert(num_fotogramas > n);
      
      typename list<T>::iterator it;
      it = fotogramas.begin();
      
      for(int i = 0; i < n; i++)
	  it++;
      
      return *it;
      
}

/*----------------------------------------------------------------------------------------*/
	
template <class T>
const T & Video<T>::operator()(int n) const{
  
      assert(num_fotogramas > 0);
      assert(num_fotogramas > n);
      
      typename list<T>::iterator it;
      it = fotogramas.begin();
      
      for(int i = 0; i < n; i++)
	  it++;
      
      return *it;
      
}

/*----------------------------------------------------------------------------------------*/

template <class T>
Video<T>& Video<T>::operator=(const Video<T> &Vid){
  
      num_fotogramas = Vid.num_fotogramas;
      fotogramas = Vid.fotogramas;
      
}

/*----------------------------------------------------------------------------------------*/

template <class T>
void Video<T>::set(int n, const T &f){
  
      assert(num_fotogramas > 0);
      assert(num_fotogramas > n);
      
      typename list<T>::iterator it;
      it = fotogramas.begin();
      
      for(int i = 0; i < n - 1; i++)
	  it++;
      
      it = fotogramas.erase(it);
      fotogramas.insert(it,f);
      num_fotogramas++;
      
}

/*----------------------------------------------------------------------------------------*/

template <class T>
void Video<T>::set(const T &f){
  
      fotogramas.push_back(f);
      num_fotogramas++;
      
}

/*----------------------------------------------------------------------------------------*/

template <class T>
bool Video<T>::operator==(const Video<T> &V){
  
      return (fotogramas == V.fotogramas);
      
}

/*----------------------------------------------------------------------------------------*/

template <class T>
bool Video<T>::operator!=(const Video<T> &V){
  
      return (fotogramas != V.fotogramas);
      
}

/*----------------------------------------------------------------------------------------*/

template <class T>
typename Video<T>::iterator Video<T>::Insertar(typename Video<T>::iterator it, const T &I){
  
      return fotogramas.insert(it,I);
      
}

/*-----------------------------------------------------------------------------------------*/	
/*******************************************************************************************/
/*			      IMPLEMENTACIÓN CLASE ITERATOR			     */
/******************************************************************************************/
/*-----------------------------------------------------------------------------------------*/
		
template <class T>
Video<T>::iterator::iterator(){
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
Video<T>::iterator::iterator(typename list<T>::iterator aux){
  
      aux_fotogramas = aux;
      
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
Video<T>::iterator::iterator(const iterator & i){
  
      aux_fotogramas = i.aux_fotogramas;
      
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
bool Video<T>::iterator::operator!=(const iterator & i) const{
  
      if(aux_fotogramas != i.aux_fotogramas)
	  return true;
      else
	  return false;
      
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
bool Video<T>::iterator::operator==(const iterator & i) const{
  
      return !(aux_fotogramas != i.aux_fotogramas);
      
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
typename Video<T>::iterator & Video<T>::iterator::operator=(const iterator & i){
  
      aux_fotogramas = i.aux_fotogramas;
      
      return *this;
      
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
T & Video<T>::iterator::operator*(){
  
      return *aux_fotogramas;
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
typename Video<T>::iterator & Video<T>::iterator::operator++(){
  
     ++aux_fotogramas;     
     
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
typename Video<T>::iterator Video<T>::begin(){
    
      return fotogramas.begin();
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
typename Video<T>::iterator Video<T>::end(){
  
      return fotogramas.end();
	
}

/*-----------------------------------------------------------------------------------------*/	
/*******************************************************************************************/
/*			      IMPLEMENTACIÓN CLASE CONST_ITERATOR			     */
/******************************************************************************************/
/*-----------------------------------------------------------------------------------------*/

		
template <class T>
Video<T>::const_iterator::const_iterator(){
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
Video<T>::const_iterator::const_iterator(typename list<T>::const_iterator aux){
  
      aux_fotogramas = aux;
      
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
Video<T>::const_iterator::const_iterator(const const_iterator & i){
  
      aux_fotogramas = i.aux_fotogramas;
      
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
bool Video<T>::const_iterator::operator!=(const const_iterator & i) const{
  
      if(aux_fotogramas != i.aux_fotogramas)
	  return true;
      else
	  return false;
      
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
bool Video<T>::const_iterator::operator==(const const_iterator & i) const{
  
      return !(aux_fotogramas != i.aux_fotogramas);
      
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
typename Video<T>::const_iterator & Video<T>::const_iterator::operator=(const const_iterator & i){
  
      aux_fotogramas = i.aux_fotogramas;
      
      return *this;
      
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
T & Video<T>::const_iterator::operator*(){
  
      return *aux_fotogramas;
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
typename Video<T>::const_iterator & Video<T>::const_iterator::operator++(){
  
     ++aux_fotogramas;
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
typename Video<T>::const_iterator Video<T>::begin() const{
    
      return fotogramas.begin();
}

/*-----------------------------------------------------------------------------------------*/

template <class T>
typename Video<T>::const_iterator Video<T>::end() const{
  
      return fotogramas.end();
	
}

/*-----------------------------------------------------------------------------------------*/	