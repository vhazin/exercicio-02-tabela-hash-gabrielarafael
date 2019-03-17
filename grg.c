#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct no{

   int elemento;

   struct no *proximo;
};

typedef struct no No;


 typedef struct Lista {

    No *inicio;
    };



void inserir_lista(struct Lista *lista , int Elemento){
    No *no_inserir = calloc(1,sizeof(No));
    no_inserir->elemento = Elemento;
    if(lista->inicio == NULL){
    lista->inicio = no_inserir;
    }
    else {

    No *passo = lista->inicio;

    while(passo->proximo != NULL)

        passo = passo->proximo;

    passo->proximo = no_inserir;
    }
}



void inserir_hash(struct Lista *lista[],int elemento,int tamanho){

    inserir_lista(lista[elemento%tamanho],elemento);

}


typedef struct Lista liste;
printhash(liste *lista[],int tamanho){
    int a;
    for( a = 0;a<tamanho;a++){
        verlista(lista[a],a);
        printf("\n");
    }
}

verlista(liste* lista,int index){

    No *no_aux = lista->inicio;
    printf("%d -> ",index);
    while(no_aux != NULL){

        printf("%d -> ",no_aux->elemento);
        no_aux =no_aux->proximo;
    }
    printf("\\");

}

int main()
{

    int casos_testes;

    scanf("%d",&casos_testes);

    int loop_for = 0;

    int *elemento_base = malloc(casos_testes*sizeof(int));

    int *chaves_armazenadas = malloc(casos_testes*sizeof(int));

    int **elementos = (int**)malloc(casos_testes*(sizeof(int*)));

    for(loop_for = 0; loop_for< casos_testes ;loop_for++){


        scanf("%d %d",&elemento_base[loop_for],&chaves_armazenadas[loop_for]);
        int iterador;

        char string[casos_testes][200*4-1];

        fflush(stdin);

        elementos[loop_for] = malloc(chaves_armazenadas[loop_for]*sizeof(int));

        scanf("%[^\n]",string[loop_for]);

        char *separacao = strtok(string[loop_for]," ");
        for(iterador = 0;iterador <chaves_armazenadas[loop_for];iterador++){

            elementos[loop_for][iterador] = atoi(separacao);

            separacao = strtok(NULL," ");
        }

        }

        for(loop_for = 0; loop_for< casos_testes ;loop_for++){
        int iterador;
        printf("\n");

        liste *lista[elemento_base[loop_for]] ;

        for (iterador = 0 ; iterador < elemento_base[loop_for];iterador++){
            lista[iterador] = calloc(1,sizeof(liste));
        }

        for(iterador=0;iterador<chaves_armazenadas[loop_for];iterador++){
            inserir_hash(lista,elementos[loop_for][iterador],sizeof(lista)/sizeof(lista[0]));
        }

        printhash(lista,sizeof(lista)/sizeof(lista[0]));
        }
     return 0;
    }

