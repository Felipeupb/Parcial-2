#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int Mayor(int *arr,int size);
int Menor(int *arr,int size);
float Promedio(int *arr,int size);


//leer una archivo hasta el final
int main(void){


	FILE *inFile = fopen("./arrinfo.txt","r");
	if (inFile == NULL){
		perror("open file fails: ");
		return(EXIT_FAILURE);
	}

	char buffer[64];
	char *status = NULL;

	do{
		status = fgets(buffer, sizeof(buffer),inFile);
		if(status != NULL){
			printf("%s",buffer);
		}
	}while (status !=NULL);
		printf("\n");

		fclose(inFile);

	//guardar el renglon
	int val;
	char *token = strtok(buffer, " ");
	int i = 0;


	int arrtemp[30];//este programa tendtra una limitacion de 30 datos
	int a = 0;
	while(token != NULL ){
	// printf("token[%d]: %s\n",i,token);

		errno = 0;
		int successItems = sscanf(token,"%d",&val);
		if(successItems == 1){
	// printf("val: %d\n", val);
			arrtemp[a]=val;
			a++;

		}

		token = strtok(NULL, " ");
		i++;
	}
//arreglos
	int * parr = malloc(sizeof(int)*i);

	for(int j = 0;j<i;j++)
	{
		parr[j]=arrtemp[j];

	}
// for(int j = 0;j<i;j++)
// {
// printf("parr[%d]= %d\n",j,parr[j]);

//}
	int ma =Mayor(parr,i);
	int me =Menor(parr,i);
	float prom =Promedio(parr,i);

	FILE * flujo = fopen("./resultados.txt","w");
	if(flujo ==NULL)
	{
		perror("Error en la creacion del archivo \n\n");
	}else
	{
		fprintf(flujo,"mayor = %d /menor = %d /promedio = %.2f ",ma,me,prom);
	}
	fclose(flujo);

	free(parr);
	return(EXIT_SUCCESS);
	}
	int Mayor( int *arr,int size){
		int mayor = arr[0];
		for ( int i=0; i<size ;i++)
		{
			if (arr[i]> mayor){
				mayor=arr[i];
			}

		}
		printf("El mayor es %d\n", mayor);
		return mayor;
	}
	int Menor( int *arr,int size){
		int menor = arr[0];
		for ( int i=0; i<size ;i++)
		{
			if (arr[i]<menor){
				menor=arr[i];
			}

		}
		printf("El menor es %d\n", menor);
		return menor;
	}
	float Promedio( int *arr,int size){
		int sumatoria = 0;
		float prom;
		for ( int i=0; i<size ;i++)
		{
			sumatoria +=arr[i];

		}
	prom =(float)sumatoria/size;
	printf("El promedio es %.2f\n", prom);
	return prom;
}


