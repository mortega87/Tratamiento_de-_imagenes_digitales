#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <video.h>
#include <imagen.h>
#include <string.h>
#include <imagenES.h>
#include <list>

using namespace std;


int main(int argc, char * argv[]){
  
      Video<Imagen<unsigned char> > vid;
      unsigned char * image, *image2, *aux_image;
      int nf, nc, nf2, nc2, n1, n2, p = 0;
      double iteraciones, pixel_cambiar = 0.0;
      char * origen, * des;
      
      
      char destino[30], extension[4], nombre[10];
      sprintf(extension, "%s", ".pgm");
      sprintf(nombre, "%s", "vacas");
      
      if(argc != 4){
	  cerr << "Error: Numero incorrecto de parametros.\n";
	  cerr << "Uso: ./rebobinar <origen> <destino> <iteraciones>\n";
	  exit (1);
      }
      
      origen = argv[1];
      des = argv[2];
      iteraciones = atoi(argv[3]);
      
      
      /* Transformamos a TDA Imagen la imagen origen y la introducimos en el video */
      image = LeerImagenPGM (origen, nf, nc);
      if (!image){
	 cerr << "Error: No pudo leerse la imagen." << endl;
	 cerr << "Terminando la ejecucion del programa." << endl;
	 exit (1);	
      }
	
	
      /* Tomamos la imagen que será el destino del morphing */
      image2 = LeerImagenPGM (des, nf2, nc2);
      if (!image){
	 cerr << "Error: No pudo leerse la imagen." << endl;
	 cerr << "Terminando la ejecucion del programa." << endl;
	 exit (1);	
      }
      
      
      /* Para comprobar que no hagamos cambios en la misma posicion */
      int marcado[nf][nc];
      for(int e = 0; e < nf; e++){
	  for(int t = 0; t < nc; t++)
	      marcado[e][t] = 0;
      }
      
      
      Imagen<unsigned char> img(image, nf, nc), img2(image2, nf2, nc2);
      Imagen<unsigned char> img_aux(image, nf, nc);
      vid.set(img);     
      pixel_cambiar = (int) ((double)((nf * nc)/iteraciones) + 0.5);
      
      for(int i = 0; i < iteraciones; i++){	  
	  for(int j = 0; j < pixel_cambiar;p++){
	      n1 = random() % nf;
	      n2 = random() % nc;
	      	      
	      
	      if(p == 0){
		  img_aux.set(n1,n2,img2(n1,n2));
		  j++;
		  marcado[n1][n2] = 1;
	      }
	      else{
		
		  if(marcado[n1][n2] == 0){	
		      img_aux.set(n1,n2,img2(n1,n2));
		      j++;	
		      marcado[n1][n2] = 1;
		  }
		 	 
	      }   
	      
	  }
	  
	  vid.set(img_aux);
      }
      
      
      
      for(int z = 0; z < vid.numero_fotogramas(); z++){
	  sprintf(destino, "%s%d%s", nombre, z, extension);
	  img_aux = vid(z);
	  
	  image2 = img_aux.ConvertirImagen();// Pasamos la imagen a unsigned char * para poder llamar al metodo EscribirImagenPGM
	  
	  if (EscribirImagenPGM (destino, image2, nf2, nc2))
	      cout  << "La imagen se guardo en " << destino << endl;
	  else{
	      cerr << "Error: No pudo guardarse la imagen." << endl;
	      cerr << "Terminando la ejecucion del programa." << endl;
	      exit (2);
	  }
	  
	  
      }          
      
      return 0;
      
}
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  