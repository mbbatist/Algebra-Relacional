//Aluna: Mariana Brito Batista

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char **separar(char line[], char pfinal) {

    int i, j, k, contador = 0;
    for(i=0,contador=0;i<strlen(line);i++)
    if(line[i] == pfinal)
    contador++;
    char  aux[contador][20];
    char **retornavel = (char**)malloc(contador*sizeof(char));
    if(contador)
    {
        for(i=0; i<=contador; i++ )
        *(retornavel + i) = (char*)malloc(40*sizeof(char));
        for(i=0,k=0,j=0; i < strlen(line); i++)
        if(line[i] != pfinal)
        {
            aux[k][j] = line[i];
            j++;
        }
        else
        {
            aux[k][j] = 0;

            k++;
            j=0;
        }

        aux[k][j] = 0;
        for(i=0;i<=contador;i++)
        *(retornavel+i) = strcpy(*(retornavel+i), aux[i]);
        return retornavel;
    }
}


int main(){
    int n=100;
    FILE *file;
    file = fopen("clientes.txt", "r+");
    char clientes[n][n];
    int j,i = 0;
    int found = 0;
    int exist = 0;
    char **end_rodrigo, **aux;
    while( fgets(clientes[i], sizeof(clientes), file) != NULL && i < n)
    {
       end_rodrigo = separar(clientes[i], ';');
        if(exist == 0 && strcmp(end_rodrigo[0], "Rodrigo Alves") == 0)
        {
            exist = 1;
            found = i;
        }
        i++;
    }
    if(exist == 1)
    {
        end_rodrigo = separar(clientes[found], ';');
        for(j = 0; j < i; j++)
        {
            aux = separar(clientes[j], ';');
            if( strcmp(end_rodrigo[1], aux[1]) == 0 && strcmp(end_rodrigo[2], aux[2]) == 0)
            {
                printf("%s\n",aux[0]);
            }
        }
    }
    else
    {
        printf("Não há outros com esse endereço!");
    }
fclose(file);
return 0;
}
