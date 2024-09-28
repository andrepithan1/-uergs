/*PROGRAMA ... ORDENACAO DE LISTA DUPLAMENTE ENCADEADA COM PONTEIROS DE INICIO E FIM

opcao 3 - ordenacao simples - ordenacao trocando os valores de endereco

opcao 4 - ordenacao dos nos - ordena e troca todo o enderecamento dos nos e atualiza os ponteiros de inicio e fim

ps.: usar ou uma ou outra (pois cada vez que fizer a opcao ele fara a ordenacao definitiva)

BUBBLE SORT*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int dado;
	struct nodo *endprox;
	struct nodo *endanterior;
}no;

void criaLista(no **prim, no **ult)
{
	*prim = NULL;
	*ult = NULL;
}

int menu()
{
	int op;
	printf("\n\n\tMenu \n");
	printf("\n\t1-Inserir no fim\n\t2-Remover do inicio\n\t3-Ordenacao simples\n\t4-Ordenacao dos ponteiros\n\t5-Imprimir\n\t6-Fim");
	printf("\n\n\tDigite uma opcao: ");
	scanf("%d",&op);
	
	while(op < 1 || op > 6)
	{
		printf("\n\n\tMenu \n");
		printf("\n\t1-Inserir no fim\n\t2-Remover do inicio\n\t3-Ordenacao dos valores\n\t4-Ordenacao dos ponteiros\n\t5-Imprimir\n\t6-Fim");
		printf("\n\n\tDigite uma opcao: ");
		scanf("%d",&op);
	}
	return op;
}

void removeUnicoElem(no **prim, no **ult)
{
	free((*prim));	
	*prim = NULL;
	*ult = NULL;
}

void insereListaVazia(no **prim, no *novo, no **ult)
{
	novo->endanterior = NULL;						
	*ult = novo;
}

void removeInicio(no **prim, no **ult)
{
	no *remover = *prim;
	if(*prim == NULL)
	{
		printf("\n\tNao pode remover de uma lista vazia\n");
	}
	else
	{
		*prim = (*prim)->endprox;								//atualiza o endereço para o proximo
		
		 if (*prim == NULL)
	    {
	        *ult = NULL;										//Se a lista ficar vazia após a remoção
	    }
	    else
	    {
	        (*prim)->endanterior = NULL;						//ATUALIZA PONTEIRO
	    }
		free(remover);	
		printf("\n\tElemento removido com sucesso\n");
	}
}

void insereFim(no **prim, int val, no **ult)					//fila, lista, FiFo (first in , first out)
{
	no *pAux, *novo;										
	pAux = *prim;
	novo = (no *) malloc (sizeof (no));
	*ult = novo;
	if (novo == NULL)
	{
	  	printf ("\n\tNao conseguiu alocar endereco");
	}
	else
	{
		novo->dado = val;									//insere o valor
	    novo->endprox = NULL;								//na ultima posição, por isso aponta para NULL
		if (*prim == NULL)
		{
			novo->endanterior = NULL;						//se for o unico elemento o anterior recebe NULL e
			*prim = novo;									//end primeiro recebe novo elemento;
		}
		else
		{
		   while (pAux->endprox != NULL)					//preciso andar com o ponteiro auxiliar para nao perder o endereço do ponteiro principal
		   {
		      pAux = pAux->endprox;							//percorre a lista ate o final NULL
		   }
		    pAux->endprox = novo;							// ultimo elemento e
		    novo->endanterior = pAux;						// anterior aponta para o elemento anterior
		}	
    }
}


int contaElementos(no *prim)							//fila, lista, FiFo (first in , first out)
{
	no *pAux;											
	int cont=0;
	pAux = prim;

	if (prim == NULL)
	{
		return 0;
	}
	else
	{
	   while (pAux->endprox != NULL)					
	   {
	      cont++;
		  pAux = pAux->endprox;							//percorre a lista, CONTANDO, ate o final NULL
	   }
	   
	return cont + 1;   
	}
}


void trocaValor(no **prim1, no **prim2)					//funcao troca os valores entre dois nos
{
	int aux;
	
	aux = (*prim1)->dado;
	(*prim1)->dado = (*prim2)->dado;
	(*prim2)->dado = aux;
}


void ordenarBubbleSort(no **prim, no **ult)				//funcao que ordena trocando os valores dos enderecos de memoria
{
    int trocado;
    no *pAux;
    no *fim = *ult; 

    if (*prim == NULL)
        printf("\n\tLista vazia!!!\n");
    else
    {
	    do
		{
	        trocado = 0;
	        pAux = *prim;
	
	        while (pAux != fim)
			{
	            if (pAux->endprox != NULL  &&  pAux->dado > pAux->endprox->dado)
				{
	                trocaValor(&pAux, &pAux->endprox);			//chama funcao para fazer a troca (end, endprox)
	                trocado = 1;
	            }
	            pAux = pAux->endprox;
	        }
	
	        fim = fim->endanterior;       						//Bublle sort
	
	    } while (trocado);										//troca = 0, significa que não houve troca e a lista ja está ordenada
	}
}


void trocaNos(no **prim, no **ult, no *no1, no *no2)
{
    if (no1 == no2) 					
	{
		printf("\n\tNao ha troca a ser feita");
	}
	else
	{
	        			
        if (no1->endanterior != NULL)						
            no1->endanterior->endprox = no2;			
        else
            *prim = no2;  									//Se primeiro no, atualiza ponteiro

        if (no2->endprox != NULL)							
            no2->endprox->endanterior = no1;
        else
        	*ult = no1;										//Se ultimo no atualiza ponteiro
        
		no1->endprox = no2->endprox;
		no2->endanterior = no1->endanterior;
		no2->endprox = no1;
		no1->endanterior = no2;   
	}
}


void ordenarBubbleSortPonteiros(no **prim, no **ult)
{
    int trocado;
    no *pAux;
    no *fim = NULL; 								

    if (*prim == NULL)
        printf("\n\tLista vazia!!!\n");
    else
    {
	    do 
		{
	        trocado = 0;
	        pAux = *prim;
	
	        while (pAux->endprox != fim)
			{
	            if (pAux->dado > pAux->endprox->dado)
				{
	                trocaNos(prim, ult, pAux, pAux->endprox);
	                trocado = 1;
	            } else
	                pAux = pAux->endprox;
	        }
	        fim = pAux; 									// Atualizacao do fim para o último elemento já ordenado
	    } while (trocado);
	}
}


void imprimeLista(no *prim, no *ult)
{
	no *pAux = prim;									
	if (prim == NULL)
	{
		printf ("\n\tLista Vazia");
		printf ("\n\tpInicio = %d \t\tpFim = %d\n\n", prim, ult);
	}
	else
	{
	printf ("\n\tLISTA DUPLAMENTE ENCADEADA\n");
	printf ("\n\tpInicio = %d \t\tpFim = %d\n\n", prim, ult);
	printf ("\t EndAnt \tEndereco      Dado \tEndProx\n");
	do
		{
		    printf ("\n\t%08d \t%08d \t%d \t%08d", pAux->endanterior, pAux, pAux->dado, pAux->endprox);
			pAux = pAux->endprox;
	    } while (pAux != NULL);	
	}
}


main()
{
	no *primeiro, *ultimo;												
	int opcao, valor, novo;	
	
	criaLista(&primeiro, &ultimo);
	if (primeiro == NULL)
	{
		printf ("\n\tCriou lista vazia\n");	
	}
	
	opcao = menu();
	
	while (opcao != 6)
	{
		switch(opcao)
		{
			case 1:	
					printf("\n\tDigite o valor a ser inserido: ");
					scanf("%d",&valor);
					
					insereFim(&primeiro, valor, &ultimo);													
				break;
			case 2:
					removeInicio(&primeiro, &ultimo);
				break;
			case 3:
					ordenarBubbleSort(&primeiro, &ultimo);
				break;
			case 4:
					ordenarBubbleSortPonteiros(&primeiro, &ultimo);
				break;
			case 5:
					printf("\n\n\tLISTA ATUAL\n");
					imprimeLista(primeiro, ultimo);	
				break;
		}
		opcao = menu();
	}
}
					