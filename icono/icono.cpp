#include <iostream>
#include <cstring>
#include <cstdlib>

#include <imagenES.h>
#include <imagen.h>

using namespace std;

int main (int argc, char *argv[]){
  
      char *origen, *destino; // nombres de los ficheros
      
      unsigned char *image, *image2;      
      int i, j, k, v, l, s, t, m, aux, aux2, nf, nc, cont, nf2, nc2, n;
      double media = 0.0;
      
      // Comprobar validez de la llamada
      if (argc != 5){
	cerr << "Error: Numero incorrecto de parametros.\n";
	cerr << "Uso: ./icono <FichImagenOriginal> <FichImagenDestino> <nf> <nc>\n";
	exit (1);
      }

      origen  = argv[1];
      destino = argv[2];
      nf2 = atoi(argv[3]);
      nc2 = atoi(argv[4]);

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
      
      // Calculamos el icono
      Imagen<unsigned char> imgorigen(image, nf, nc); // Tambien se podría hacer usando el metodo EscribirEnImagen pero haciendo la llamada al constructor Imagen<unsigned char> i(nf,nc)
      Imagen<unsigned char> iaux(nf2,nc2);
      Imagen<unsigned char>::iterator_fila it_f;
      Imagen<unsigned char>::iterator_fila::iterator_columna it_c;
      
      
      
      for(i = 0, t = 0, s = 1; i < nf2; i++, s++, t++){
	 for(j = 0, m = 0, v = 1; j < nc2; j++, m++, v++){
	    aux = nf2 * s;
	    aux2 = nc2 * v;
	    if(aux > nf)
		aux = nf;
	    
	    if(aux2 > nc)
		aux2 = nc;
	    
	    it_f = imgorigen.begin();
	    for(n = 0; n < nf2 * t; n++)
		++it_f;	    
	    
	    for(k = nf2 * t, cont = 0; k < aux; k++, ++it_f){
		it_c = (*it_f).begin();
		for(n = 0; n < nc2 * m; n++)
		    ++it_c;
		
		for(l = nc2 * m; l < aux2; l++, cont++,++it_c)
		    media += *it_c;
	    }
	    media = (int) ((double)(media/cont) + 0.5);
	    iaux.set(i,j,media);
	    media = 0.0;
	 }
      }
		 
		 
      image2 = iaux.ConvertirImagen();// Pasamos la imagen a unsigned char * para poder llamar al metodo EscribirImagenPGM
	
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
      
      
      
      
      
      
      
      