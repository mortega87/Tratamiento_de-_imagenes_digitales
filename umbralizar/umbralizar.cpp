#include <iostream>
#include <cstring>
#include <cstdlib>

#include <imagenES.h>
#include <imagen.h>

using namespace std;

int main (int argc, char *argv[]){
  
      char *origen, *destino; // nombres de los ficheros
      
      unsigned char *image, *image2;
      int nf, nc, t1, t2, j, k; // (nf,nc) numero de filas y columnas; (t1,t2) valores del intervalo de la umbralizacion

      // Comprobar validez de la llamada
      if (argc != 5){
	cerr << "Error: Numero incorrecto de parametros.\n";
	cerr << "Uso: ./umbralizar <FichImagenOriginal> <FichImagenDestino> <T1> <T2>\n";
	exit (1);
      }

      origen  = argv[1];
      destino = argv[2];
      t1 = atoi(argv[3]);
      t2 = atoi(argv[4]);

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
      
      // Calculamos la umbralizacion 
      Imagen<unsigned char> i(image, nf, nc); // Tambien se podría hacer usando el metodo EscribirEnImagen pero haciendo la llamada al constructor Imagen<unsigned char> i(nf,nc)
      Imagen<unsigned char> iaux(nf,nc);
      Imagen<unsigned char>::iterator_fila it_f, itaux_f;
      Imagen<unsigned char>::iterator_fila::iterator_columna it_c, itaux_c;
                 
      
      for(it_f = i.begin(), itaux_f = iaux.begin(), j = 0; j < i.num_filas(); ++it_f, ++itaux_f, j++){
	    for(it_c = (*it_f).begin(), itaux_c = (*itaux_f).begin(), k = 0; k < i.num_columnas(); ++it_c, ++itaux_c, k++){
		if((t1 < *it_c) && (*it_c < t2))
		    *itaux_c = *it_c;
		else
		    *itaux_c = 255;
	    }
      }
      
      
      image2 = iaux.ConvertirImagen(); // Pasamos la imagen a unsigned char * para poder llamar al metodo EscribirImagenPGM
	
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
      
      
      
      
      
      
      
      