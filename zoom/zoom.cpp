#include <iostream>
#include <cstring>
#include <cstdlib>

#include <imagenES.h>
#include <imagen.h>

using namespace std;

int main (int argc, char *argv[]){
  
      char *origen, *destino; // nombres de los ficheros
      
      unsigned char *image, *image2;
      int nf, nc, nf2, nc2, x1, y1, x2, y2, j, k, nf3, nc3; // (nf,nc) numero de filas y columnas; (x1,y1) coordenadas de la esquina superior izquierda; (x2,y2) coordenadas de la esquina superior derecha
           
      // Comprobar validez de la llamada
      if (argc != 7){
	cerr << "Error: Numero incorrecto de parametros.\n";
	cerr << "Uso: ./zoom <FichImagenOriginal> <FichImagenDestino> <x1> <y1> <x2> <y2>\n";
	exit (1);
      }

      origen  = argv[1];
      destino = argv[2];
      x1 = atoi(argv[3]);
      y1 = atoi(argv[4]);
      x2 = atoi(argv[5]);
      y2 = atoi(argv[6]);

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
      
      // Calculamos el zoom
      Imagen<unsigned char> i(image, nf, nc); // Tambien se podría hacer usando el metodo EscribirEnImagen pero haciendo la llamada al constructor Imagen<unsigned char> i(nf,nc)
      
      // calculamos las dimensiones que tendrá la nueva imagen
      nf2 = (2 * ((x2 - x1) + 1)) - 1;
      nc2 = (2 * ((y2 - y1) + 1)) - 1;
      Imagen<unsigned char> iaux(nf2, nc2);
      Imagen<unsigned char>::iterator_fila it_f, itaux_f;
      Imagen<unsigned char>::iterator_fila::iterator_columna it_c, itaux_c;
      
      
      // Almacenamos los valores
      for(it_f = i.begin(), itaux_f = iaux.begin(), j = 0; j < nf2; ++it_f, ++itaux_f, j += 2){
	   for(it_c = (*it_f).begin(), itaux_c = (*itaux_f).begin(), k = 0; k < nc2; ++it_c, ++itaux_c, k += 2) 
		iaux.set(j,k,*it_c);
      }
      
           
    
      // Metemos los 0
      for(it_f = i.begin(), itaux_f = iaux.begin(), j = 0; j < nf2; ++it_f, ++itaux_f, j++){
	   for(it_c = (*it_f).begin(), itaux_c = (*itaux_f).begin(), k = 0; k < nc2; ++it_c, ++itaux_c, k++){
	      if(j%2 == 0){
		  if(k%2 != 0)
		      iaux.set(j,k,0);
	      }
	      else
		  iaux.set(j,k,0);
	   }
      }
	      
	      
           
      // Interpolamos las filas pares
      for(it_f = i.begin(), itaux_f = iaux.begin(), j = 0; j < nf2; ++it_f, ++itaux_f, j++){
	   for(it_c = (*it_f).begin(), itaux_c = (*itaux_f).begin(), k = 0; k < nc2; ++it_c, ++itaux_c, k++){
		if(j%2 == 0){
		    if(k%2 != 0)
			  iaux.set(j,k, (int) ((iaux(j,k-1) + iaux(j,k+1) / 2) + 0.5));
		}
	    }
      }
      
      // Interpolamos las filas impares
      for(it_f = i.begin(), itaux_f = iaux.begin(), j = 0; j < nf2; ++it_f, ++itaux_f, j++){
	   for(it_c = (*it_f).begin(), itaux_c = (*itaux_f).begin(), k = 0; k < nc2; ++it_c, ++itaux_c, k++){
		if(j%2 != 0)
		    iaux.set(j,k, (int) ((iaux(j-1,k) + iaux(j+1,k)) / 2) + 0.5);
	    }
      }
	
	

      image2 = iaux.ConvertirImagen();
	
      // Guardar la imagen resultado en el fichero
      if (EscribirImagenPGM (destino, image2, nf2, nc2))
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