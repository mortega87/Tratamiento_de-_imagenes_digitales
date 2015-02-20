#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <video.h>
#include <imagen.h>
#include <string.h>
#include <imagenES.h>
#include <stack>

using namespace std;

int main(int argc, char * argv[]){
  
      Video<Imagen<unsigned char> > vid, aux_vid;
      stack<Imagen<unsigned char> > pila_fotogramas;
      unsigned char * image, *image2;
      int nf, nc, segundos;
      
      
      char nombre[20], nombre2[20], destino[20], nombre_nuevo2[20], extension[4];
      sprintf(nombre2, "%s", "football");
      sprintf(nombre_nuevo2, "%s", "futbol");
      sprintf(extension, "%s", ".pgm");
      
      if(argc != 2){
	  cerr << "Error: Numero incorrecto de parametros.\n";
	  cerr << "Uso: ./rebobinar <segundos>\n";
	  exit (1);
      }
    
      segundos = atoi(argv[1]);
      
      /* Metemos los fotgramas necesarios en el video para los segundos que nos diga el usuario, para ello transformamos los ficheros PGM en TDA Imagen */
      for(int i = 0; i < 24 * segundos; i++){ 
	  sprintf(nombre, "%s%04d%s", nombre2, i, extension);
      
	  // Leer la imagen del fichero de entrada
	  image = LeerImagenPGM (nombre, nf, nc);
	  if (!image){
	    cerr << "Error: No pudo leerse la imagen." << endl;
	    cerr << "Terminando la ejecucion del programa." << endl;
	    exit (1);
	  }
	  
	  Imagen<unsigned char> img(image, nf, nc);
	  vid.set(img);	  
      }
      
      
      /* Introducimos ahora los videos al reves para el efecto de rebobinado */
      for(int k = 0; k < vid.numero_fotogramas(); k++)
	   pila_fotogramas.push(vid(k));
	   
      while(!pila_fotogramas.empty()){
	   aux_vid.set(pila_fotogramas.top());
	   pila_fotogramas.pop();
      }
      
      
      /* Pasamos los fotogramas del video a formato PGM */
      for(int j = 0; j < 120; j++){
	  sprintf(destino, "%s%d%s", nombre_nuevo2, j, extension);
	  Imagen<unsigned char> iaux = aux_vid(j);
	  
	  image2 = iaux.ConvertirImagen();// Pasamos la imagen a unsigned char * para poder llamar al metodo EscribirImagenPGM
	  
	  // Guardar la imagen resultado en el fichero
	  if (EscribirImagenPGM (destino, image2, nf, nc))
	      cout  << "La imagen se guardo en " << destino << endl;
	  else{
	      cerr << "Error: No pudo guardarse la imagen." << endl;
	      cerr << "Terminando la ejecucion del programa." << endl;
	      exit (2);
	  }	  
      }
      
          
      // Liberar la imagen
      delete [] image, image2;
      
      
      return 0;
      
}