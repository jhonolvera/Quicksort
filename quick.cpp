#include <stdio.h>

void menu();
void inicializar(int *unarray, int lalong);
void rellenar(int *unarray, int lalong);
void imprimir(int *unarray, int lalong);
int maximo(int *unarray, int lalong);
int minimo(int *unarray, int lalong);
int media(int *unarray, int lalong);
void ordenarmayor(int *unarray, int lalong);
void ordenarmenor(int *unarray, int lalong);
void Quicksort (int *unarray, int izq, int der);
int pivot (int *unarray, int izq, int der);

#define N 10

int main(){
   int opc;
   int miarray[N];
   int may, men, med;
   int longitudarray;

   inicializar(miarray,N);

   do {
	menu();
	scanf("%d",&opc);
	switch(opc) {
		case 1:
			rellenar(miarray,N);
		
		case 0: break;
		default:
			printf("\n ¡¡ Introduce una opcion valida !! \n");
	}
   } while(opc != 0);
}

void menu() {
        printf ("\nIntroduce una opcion:\n");
        printf ("1.- Introducir el  elementos\n");
        printf ("0.- Salir\n");
        printf ("Opcion: ");
}

void inicializar(int *unarray, int lalong) {
   int cont;
   
   for (cont=0;cont<lalong;cont++) {
	unarray[cont]=0;
   }
}

void rellenar(int *unarray, int lalong) {
   int cont;
   for (cont=0;cont<lalong;cont++) {
	printf("Introduce el numero para %d casilla: ",cont);
	scanf("%d", &unarray[cont]);
   }
}

void imprimir(int *unarray, int lalong) {
   int cont;
   for (cont=0;cont<lalong;cont++) {
        printf("En casilla %d esta el número %d.\n", cont, unarray[cont]);
   }
}

int maximo(int *unarray,int lalong) {
  int cont,m;

  m=unarray[0];

  for (cont=0;cont<lalong;cont++) {
    if(unarray[cont] > m)
        m=unarray[cont];
  }
  return m;
}

int minimo(int *unarray,int lalong) {
  int cont,m;

  m=unarray[0];

  for (cont=0;cont<lalong;cont++) {
    if(unarray[cont] < m)
        m=unarray[cont];
  }
  return m;
}

int media(int *unarray,int lalong) {
  int cont,total=0,med;

  for (cont=0;cont<lalong;cont++) {
     total=total+unarray[cont];
  }
  med=total/lalong;
  return med;
}

void ordenarmenor(int *unarray, int lalong) {
	 int aux, i, j;
 
	 for (i = 0; i < lalong -1 ; i++) {
	 	 for (j = i + 1; j < lalong ; j++) {
 	  	 	 if (unarray[i] > unarray[j]) {
		 	 	aux = unarray[i];
		 	 	unarray[i] = unarray[j];
		 	 	unarray[j] = aux;
		 	 }
		}	 
	 }
}

void ordenarmayor(int *unarray, int lalong) {
         int aux, i, j;
 
         for (i = 0; i < lalong -1 ; i++) {
                 for (j = i + 1; j < lalong ; j++) {
                         if (unarray[i] < unarray[j]) {
                                aux = unarray[i];
                                unarray[i] = unarray[j];
                                unarray[j] = aux;
                         }
                } 
         }
}

int pivot(int *unarray, int izq, int der)
{
    int i;
    int pivote, valor_pivote;
    int aux;
 
    pivote = izq;
    valor_pivote = unarray[pivote];
    for (i=izq+1; i<=der; i++){
        if (unarray[i] < valor_pivote){
                pivote++;    
                aux=unarray[i];
                unarray[i]=unarray[pivote];
                unarray[pivote]=aux;
 
        }
    }
    aux=unarray[izq];
    unarray[izq]=unarray[pivote];
    unarray[pivote]=aux;
    return pivote;
} 
 
void Quicksort(int *unarray, int izq, int der)
{
     int pivote;
     if(izq < der){
        pivote=pivot(unarray, izq, der);
        Quicksort(unarray, izq, pivote-1);
        Quicksort(unarray, pivote+1, der);
     }  
} 
