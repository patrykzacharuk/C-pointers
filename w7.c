#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	if(argc<2){
		printf("Error(ERROR): error.");
		exit(2);
	}
	FILE *handle=fopen(argv[1], "r");
	if(handle==NULL){
		exit(2);
	}
	int i=0, j=0;
	char buffer;
	char **arr;
	arr=malloc(100*sizeof(char));
	for(i=0; i<100; i++){
		arr[i]=malloc(100*sizeof(char));
	}
	for(i=0; i<100; i++){
		for(j=0; j<100; j++)
			arr[i][j]=0;
	}


	i=0; j=0;
	while((buffer=getc(handle))!=EOF){
		while(buffer!='\0' || buffer!=EOF){ /*DODALEM DRUGI 
		WARUNEK JAKBY WCZYTYWALO OSTATNIA LINIE W PLIKU I 
		SPAC MI SIE CHCE I NIE WIEM CZY TO POTRZEBNE*/
			arr[i][j]=buffer;
			j++;
			buffer=getc(handle); //TO DODALEM BO NIE ZMIENIALO ZNAKU
		}
		arr[i][j+1]='\0';
		i++;
	}
	fclose(handle);
	for(i=0; i<100; i++){
		free(arr[i]);
	}
	free(arr);

	return 0;
}