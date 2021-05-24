#include<stdio.h>
#include<stdlib.h>

int main() {
	int p,i,j,n,da,grado,rept,met,aux;
	float x[50][51];
	float Temp, punto, resultado, ref;
	printf("\n Programa de interpolacion por  diferencias divididas \n");
	printf("\nNombres de los integrante \n");
    printf("\n Adrian Urtez Montoya \n");
    printf("\n Itzel Alexandra Tabaco Gonzalez \n");
    printf("\n Roberto Cervantes Gonzalez\n");
    printf("\n Verenice Tania Silva Velazco \n");
	do {
			
	printf("\nNumero de puntos registrados: ");
	scanf("%i",&p);	
	for(i=0;i<p;i++){
		
		printf("Ingresa tu x%i: ",i);
		scanf("%f",&x[i][0]);
		
	
	}

	
	for(i=0;i<p;i++){
		
		for(j=0;j<p-1;j++){
		   
		      if(x[j+1][0]<x[j][0]){

                        Temp=x[j][0];

                       x[j][0]=x[j+1][0];

                        x[j+1][0]=Temp;}
 
		}
	}
	
	
		
	for(i=0;i<p;i++){
		
	
		printf("\nIngresa el  F(x) de %.3f: ",x[i][0]);
		scanf("%f",&x[i][1]);

	}
	
		for(i=0;i<p;i++){
		
		for(j=0;j<2;j++){
		    printf("%f\t",x[i][j]);
		}
			printf("\n");
		
	}
	
	printf("Sus datos son correcto?: 1) Si  2)No:   ");
	scanf("%d",&da);
	system("cls");
	 }while(da==2);
	
		
		for(j=2;j<p+1;j++){
		
		for(i=0;i<p;i++){
		
			x[i][j] = (x[i+1][j-1]-x[i][j-1])/(x[i+j-1][0]-x[i][0]);
				
	}
	}
	
	printf("Que desea realizar?: 1)Diferencias dividias: ");
	scanf("%i",&met);
	if(met==1){
	
	do{

		do {
			system("cls");
		printf("\nQue punto desea interpolar?: ");
		scanf("%f",&punto);
		if(punto < x[0][0] || punto > x[p-1][0]){
			
			printf("\nEl punto no esta dentro de la tabla\t ");
			system("pause");
		
		}
	
		} while(punto < x[0][0] || punto > x[p-1][0]);
	
		do {
			
		printf("\nCual es el grado quiere que sea el grado del polinomio? ");
		scanf("%d",&grado);
		if(p<=grado||grado<1)
			printf("\nNo hay puntos suficientes para ese polinomio: ");
		} while(p<=grado||grado<1);
	
	
	if(p<=5){
			aux = grado +2;
		printf("Tabla de diferencias divididas:\n");
		for(i=0;i<grado;i++){
		
	for(j=0;j<aux;j++){
			printf("%f\t",x[i][j]);
			
	}
		aux = aux- 1;

	printf("\n");
	}
	}

	



	ref = x[0][1];
	
	
	for(i=0;i<grado;i++){
	
		resultado = x[0][i+2];
			for(j=0;j<i+1;j++){	
				
			resultado*=(punto-x[j][0]);
	}

		
		
		ref+=resultado;
	}
	
	
	printf("\nResultado para %f con un polinomio de grado %i: %f",punto,grado,ref);
	printf("\nLe gustaria interpolar para otro punto o otro grado de polinomiio con la misma tabla? 1)Si 2)No:  ");
	scanf("%i",&rept);
}while(rept==1);
}
	else
	printf("Esa opcion no esta disponible ");
	

return 0;
}

