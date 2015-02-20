#include <iostream>
#include <cstring>
#include <cstdlib>

#include <imagenES.h>
#include <imagen.h>

using namespace std;

int main (int argc, char *argv[]){
  
      char *origen, *destino; // nombres de los ficheros
      
      unsigned char *image, *image2;
      int nf, nc, a = 0, b = 0, j, k, valor; // (nf,nc) numero de filas y columnas
      double var, cociente, max, min; //(max, min) extremos del nuevo rango de la imagen
      
      // Comprobar validez de la llamada
      if (argc != 5){
	cerr << "Error: Numero incorrecto de parametros.\n";
	cerr << "Uso: ./contraste <FichImagenOriginal> <FichImagenDestino> <min> <max>\n";
	exit (1);
      }

      origen  = argv[1];
      destino = argv[2];
      min = atoi(argv[3]);
      max = atoi(argv[4]);

      cout << endl;
      cout << "Fichero origen: " << origen << endl;
      cout << "Fichero resultado: " << destino << endl;
      
      // Leer la imagen del fichero de entrada
      image = LeerImagenPGM (origen, nf, nc);
      if (!image){
	  cerr << "Error: No pudo leerse la imagen." << endl;
	  cerr << "Terminando la ejecucion del programa." << endl;
	  exit (1);
      }
      
      // Mostrar los parametros calculados por LeerImagenPGM()
      cout << endl;
      cout << "Dimensiones de " << origen << ":" << endl;  
      cout << "   Imagen   = " << nf  << " filas x " << nc << " columnas " << endl;
      
      // Calculamos el constraste 
      Imagen<unsigned char> i(image, nf, nc) ;
      Imagen<unsigned char> iaux(nf, nc);
      Imagen<unsigned char>::iterator_fila it_f, iaux_f;
      Imagen<unsigned char>::iterator_fila::iterator_columna it_c, iaux_c;
  
           
          
      // Buscamos el rango de niveles de gris de la imagen original
      it_f = i.begin();
      it_c = (*it_f).begin();
      a = b = *it_c;
      ++it_c;
      
      for(j = 1; j < i.num_filas(); ++it_f, j++){
	    for(k = 1; k < i.num_columnas(); ++it_c, k++){
		 if(*it_c <= a)
		      a = *it_c;
		 
		 if(*it_c > b)
		      b = *it_c;
	    }
      }
		   
		   
		     
      cociente = (max - min) / (b - a);
      
      for(it_f = i.begin(), iaux_f = iaux.begin(), j = 0; j < i.num_filas(); ++it_f, ++iaux_f, j++){
	    for(it_c = (*it_f).begin(), iaux_c = (*iaux_f).begin(), k = 0; k < i.num_columnas(); ++it_c, ++iaux_c, k++){
		var = min + (double) (cociente * (*it_c - a));	   
		*iaux_c = (double) (int) (var + 0.5);
	    }	   
      }
	  
      
      image2 = iaux.ConvertirImagen();// Pasamos la imagen a unsigned char * para poder llamar al metodo EscribirImagenPGM
      	 
	
	
      // Guardar la imagen resultado en el fichero
      if (EscribirImagenPGM (destino, image2, nf, nc))
	  cout  << "La imagen se guardo en " << destino << endl;
      else{
	  cerr << "Error: No pudo guardarse la imagen." << endl;
	  cerr << "Terminando la ejecucion del programa." << endl;
	  exit (2);
      }
      
      // Liberar la imagen
      delete [] image, image2;
	
      return 0;
      
}
      