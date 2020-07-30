/*
Ciencia da Computacao - Pucminas
Pedro Henrique Lima Carvalho
Matricula: 651230
AEDs 2

TP03 - Q04
*/

//dependencias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ----------------------------------- Personagem  ---------------------------------

/**
* Struct Personagem
*/
typedef struct Personagem{

//atributos
	char* nome;
	int altura;
	double peso;
	char* corDoCabelo;
	char* corDaPele;
	char* corDosOlhos;
	char* anoNascimento;
	char* genero;
	char* homeworld;

} Personagem;


//declaracoes

void mallocPerson (Personagem* p_person);

void preencherPersonagem(Personagem* p_person, char* s);


//construtores

/*
*constructor1
*@param todos atributos
*@return Personagem*
*/
Personagem* constructor1 (char* nome, int altura, double peso, char* corDoCabelo,
		   char* corDaPele, char* corDosOlhos, char* anoNascimento,
		   char* genero, char* homeworld){

	Personagem* p_person = (Personagem*) malloc(sizeof(Personagem)*1);
	p_person->nome = nome;
	p_person->altura = altura;
	p_person->peso = peso;
	p_person->corDoCabelo = corDoCabelo;
	p_person->corDaPele = corDaPele;
	p_person->corDosOlhos = corDosOlhos;
	p_person->anoNascimento = anoNascimento;
	p_person->genero = genero;
	p_person->homeworld = homeworld;

	return(p_person);
}

/*
*constructor2
*@param char* endereco arquivo
*@return Personagem
*/
Personagem* constructor2(char* endereco){
	//declaracoes
	FILE* arquivo = fopen(endereco, "r");
	Personagem* p_person = (Personagem*) malloc(sizeof(Personagem)*1);

	//teste
	if (arquivo==NULL)
		printf("%s\n", "Erro ao abrir arquivo");
	else{
		char* lida = (char*) malloc(sizeof(char)*1000);
		fgets(lida, 999, arquivo); 	
		lida[strlen(lida)-1]='\0';
		
		//alocar memoria
		mallocPerson(p_person);

		//preencher personagem			
		preencherPersonagem(p_person, lida);		
	}

	return (p_person);
}

/*
*removeChar
*@param char, char*
*/
void removeChar (char c, char* s){
	int pre = 0;
	int pos = 0;
		
	while (s[pre]!='\0'){
		if (s[pre]!=c){
			s[pos] = s[pre];
			pos++;
		}
		pre++;
	}
	s[pos]='\0';
}

/*
*mallocPerson
*@param Personagem*
*/
void mallocPerson (Personagem* p_person){
	p_person->nome = (char*) malloc(sizeof(char)*100);
	p_person->corDoCabelo = (char*) malloc(sizeof(char)*100);
	p_person->corDaPele = (char*) malloc(sizeof(char)*100);
	p_person->corDosOlhos = (char*) malloc(sizeof(char)*100);
	p_person->anoNascimento = (char*) malloc(sizeof(char)*100);
	p_person->genero = (char*) malloc(sizeof(char)*100);
	p_person->homeworld = (char*) malloc(sizeof(char)*100);
}

/*
*freePerson
*@param Personagem*
*/
void freePerson (Personagem* p_person){
	free(p_person->nome);
	free(p_person->corDoCabelo);
	free(p_person->corDaPele);
	free(p_person->corDosOlhos);
	free(p_person->anoNascimento);
	free(p_person->genero);
	free(p_person->homeworld);

}


/*
*clone
*@param Personagem*
*@return Personagem*
*/
Personagem* clone(Personagem* p_person){
	//delcaracoes
	Personagem* p_clone = (Personagem*) malloc(sizeof(Personagem)*1);
	
	//alocar memoria para clone
	mallocPerson(p_clone);
	
	strcpy(p_clone->nome, p_person->nome);
	p_clone->altura = p_person->altura;	
	p_clone->peso = p_person->peso;
	strcpy(p_clone->corDoCabelo, p_person->corDoCabelo);
	strcpy(p_clone->corDaPele, p_person->corDaPele);
	strcpy(p_clone->corDosOlhos, p_person->corDosOlhos);
	strcpy(p_clone->anoNascimento, p_person->anoNascimento);
	strcpy(p_clone->genero, p_person->genero);
	strcpy(p_clone->homeworld, p_person->homeworld);
	
	return (p_clone);
}

/*
*imprimir
*/
void imprimir(Personagem* p_person){

	printf("%s%s", " ## ", p_person->nome);
	printf("%s%d", " ## ", p_person->altura);
	printf("%s%g", " ## ", p_person->peso);
	printf("%s%s", " ## ", p_person->corDoCabelo);
	printf("%s%s", " ## ", p_person->corDaPele);
	printf("%s%s", " ## ", p_person->corDosOlhos);
	printf("%s%s", " ## ", p_person->anoNascimento);
	printf("%s%s", " ## ", p_person->genero);
	printf("%s%s", " ## ", p_person->homeworld);
	printf(" ## \n");

	}


/*
*ler
*@param Personagem*
*@return char*
*/
char*  ler(Personagem* p_person){
	char buffer[50];
	char* lida = (char*) malloc(sizeof(char)*1000);
	
	strcat(lida, " ## ");
	strcat(lida, p_person->nome);
	
	strcat(lida, " ## ");
	sprintf(buffer, "%d", p_person->altura);
	strcat(lida, buffer);	
	
	strcat(lida, " ## ");
	strcat(lida, buffer);
	sprintf(buffer, "%g", p_person->peso);
	
	strcat(lida, " ## ");
	strcat(lida, p_person->corDoCabelo);

	strcat(lida, " ## ");
	strcat(lida, p_person->corDaPele);
	
	strcat(lida, " ## ");
	strcat(lida, p_person->corDosOlhos);
	
	strcat(lida, " ## ");
	strcat(lida, p_person->anoNascimento);
	
	strcat(lida, " ## ");
	strcat(lida, p_person->genero);
	
	strcat(lida, " ## ");
	strcat(lida, p_person->homeworld);

	strcat(lida, " ## ");
			
	return(lida);	
}

/**
*isFim - verifica FIM
*@param char*
*@return boolean
*/
bool isFim(char* s){
	return (strcmp(s, "FIM") == 0);
}


/**
*preencherPersonagem - Separa os atributos do personagem de uma String
*@param Personagem*, char*
*/
void preencherPersonagem(Personagem* p_person, char* s){
	char buffer[9][100];
	int c_buffer= 0;
	int c_s=0;
	int init = 0;
	int end = -1;
		
	for (int i=0; i<9; i++){
		init=end+1;
		while (s[init]!='\''){
			init++;
		}
		end=init+1;
		while (s[end]!='\''){
			end++;
		}
		init=end+1;
		while (s[init]!='\''){
			init++;
		}
		end=init+1;
		while (s[end]!='\''){
			end++;
		}
		
		c_s=init+1;
		while(c_s<end){
			buffer[i][c_buffer] = s[c_s];
			buffer[i][c_buffer+1]='\0';
			c_buffer++;
			c_s++;
		}
		c_buffer=0;
	}

	strcpy(p_person->nome, buffer[0]);
	
	if (0 == sscanf(buffer[1], "%d", &p_person->altura))//testar unknown
		p_person->altura=0;

	removeChar(',', buffer[2]); //retirar virgula do peso	
	if (0 == sscanf(buffer[2], "%lf", &p_person->peso))//testar unknown
		p_person->peso=0;

	strcpy(p_person->corDoCabelo, buffer[3]);
	strcpy(p_person->corDaPele, buffer[4]);
	strcpy(p_person->corDosOlhos, buffer[5]);
	strcpy(p_person->anoNascimento, buffer[6]);
	strcpy(p_person->genero, buffer[7]);
	strcpy(p_person->homeworld, buffer[8]);
		
}

/**
*compare - compara dois Personagens de acordo com a operacao. Nome como desempate
*@param Lista*, Persongem* 1, Personagem* 2, int operacao
*@return double <0 se 1 menor que 2, 0 se iguais, >0 se 1 maior que 2
*/
double compare(Personagem* p_person1, Personagem* p_person2, int op){
	double resp = 0;
	
	switch(op){
		case 1:
		 resp = p_person1->altura - p_person2->altura;
		 break;
		case 2:
		 resp = p_person1->peso - p_person2->peso;
		 break;
		case 3:
		 resp = strcmp(p_person1->corDoCabelo, p_person2->corDoCabelo);
		 break;
		case 4:
		 resp = strcmp(p_person1->corDaPele, p_person2->corDaPele);
		 break;
		case 5:
		 resp = strcmp(p_person1->corDosOlhos, p_person2->corDosOlhos);
		 break;
		case 6:
		 resp = strcmp(p_person1->anoNascimento, p_person2->anoNascimento);
		 break;
		case 7:
		 resp = strcmp(p_person1->genero, p_person2->genero);
		 break;
		case 8:
		 resp = strcmp(p_person1->homeworld, p_person2->homeworld);
		 break;
		default:
		 resp = strcmp(p_person1->nome, p_person2->nome);

	}
	
	if (resp == 0){
		resp = strcmp(p_person1->nome, p_person2->nome);
	}

	return resp;
} 


//------------------------------------ Celula ----------------------------------------------

/**
*struct Celula
*/
typedef struct Celula{
 
 //atributos
	Celula* ant;
	Personagem* elemento;
	Celula* prox;

}Celula;

 //construtor
	Celula* construtorCelula (Personagem* p){
		Celula* cel = (Celula*) malloc(sizeof(Celula));
		
		cel->ant = NULL;
		cel->elemento = p;
		cel->prox = NULL;
		
		return cel;
	}

//------------------------------- Lista Flexivel -------------------------------------------

/**
*struct Lista
*/
typedef struct Lista{
 
//atributos
	Celula* primeiro;
	Celula* ultimo;
}Lista;

//construtor
/**
*construtorLista - inicializa uma Lista
*@param int tamanho
*@return list*
*/
Lista* construtorLista (){

	Lista* p_lista;
	p_lista = (Lista*) malloc (sizeof(Lista));	
	p_lista->primeiro = construtorCelula (NULL);
	p_lista->ultimo = p_lista->primeiro;
	
	return p_lista;
}

//metodos

/**
*removerInicio - remove um elemento inicio da lista
*@return Personagem*
*/
Personagem* RemoverInicio (Lista* p_lista){
	Personagem* p_person;

	if (p_lista->primeiro == p_lista->ultimo){
		printf("%s\n", "Erro - Lista Vazia");
	}
	else{
		Celula* tmp = p_lista->primeiro;
		p_lista->primeiro = p_lista->primeiro->prox;
		p_person = p_lista->primeiro->elemento;
		p_lista->primeiro->ant=NULL;
		p_lista->primeiro->elemento=NULL;
		free(tmp);
		
	}
	return p_person;
}


/**
*inserirFim - insere um elemento no final da lista
*@param Lista* Personagem*
*/
void inserirFim(Lista* p_lista, Personagem* p_person){
	
	p_lista->ultimo->prox = construtorCelula(p_person);
	p_lista->ultimo->prox->ant = p_lista->ultimo;
	p_lista->ultimo=p_lista->ultimo->prox;		
}

/**
*mostrar lista
*@param Lista*
*/
void mostrar(Lista* p_lista){
	int j=0;
	for (Celula* i=p_lista->primeiro->prox; i!=NULL; i=i->prox, j++){
		printf("%s%d%s", "[", j, "] ");
		imprimir(i->elemento);
	} 
}

/**mostrar2 - fila sem posicao
*@param Fila*
*/
void mostrar2(Lista* p_lista){
	for (Celula* i=p_lista->primeiro->prox; i!=NULL; i=i->prox){
		imprimir(i->elemento);
	}
}


/**
*freeLista - libera a memoria da Lista
*@param Lista*
*/
void freeLista (Lista* p_Lista){
	
	Celula* i = p_Lista->primeiro->prox;
	free(p_Lista->primeiro);
	p_Lista->ultimo=NULL;
	if (i!=NULL){
		for (Celula* j = i->prox; j!=NULL; j=j->prox){
			freePerson(i->elemento);
			free(i);
			i=j;
		}	
		freePerson(i->elemento);
		free(i);
	}
	free(p_Lista);
}

/**
*swap - troca de posicao dois elementos da lista
*@param Celula* i, Celula* j
*/
void swap(Celula* i, Celula* j){
	Personagem* buffer = i->elemento;
	i->elemento = j->elemento;
	j->elemento = buffer;
}

/**
*getPivo - retorna o Personagem* pivo
*@param Celula* i, Celula* j
*@return Personagem* p_person
*/
Personagem* getPivo (Celula* i, Celula* j){
	int tam = 0;
	Celula* tmp;
	for (tmp=i; tmp!=j; tmp=tmp->prox, tam++);

	tam=tam/2;
	
	tmp=i;
	for(int k=0; k<tam; k++){
		tmp=tmp->prox;
	}
	return(tmp->elemento);
}

/**
*QuickSort - quicksort
*@param Celula* esq, Celula* dir, int log[]
*/
void quickSort (Celula* esq, Celula* dir, int log[]){
	
	Celula* i = esq;
	Celula* j = dir;

	Personagem* pivo = getPivo(i, j);
       
	while (i->ant!=j && j->prox!=i && i->ant!=j->prox){
		
		log[0]+=2;		

		while (compare(i->elemento, pivo, 3)<0.0){
			i=i->prox;

			log[0]++;
		}
		while (compare(j->elemento, pivo, 3)>0.0){
			j=j->ant;

			log[0]++;
		}

		if(i->ant!=j && j->prox!=i && i->ant!=j->prox){
			swap(i,j);
			i=i->prox;
			j=j->ant;

			log[1]+=3;
		}
	}

        if (j->prox!=esq && j!=esq){
		quickSort(esq, j, log);
	}
	if (i!=dir && i!=NULL){
		quickSort(i, dir, log);
	}

	
}

/**
*ordenarQuickSort - ordena a lista pelo metodo quicksort
*@param Lista* p_lista, int log[]
*/	
void ordenarQuickSort(Lista* p_lista, int log[]){
	quickSort(p_lista->primeiro->prox, p_lista->ultimo, log);
}

//----------------------------------- Main ---------------------------------


/**
*Metodo main
*/
int  main(void){
        
	Lista* p_lista = construtorLista();
	int log[] = {0,0};
	Personagem* p;
	char* input = (char*) malloc(sizeof(char) * 100);

	fgets(input, 99, stdin);
	input[strlen(input)-1]='\0';
		
	while(!isFim(input)){
		p = constructor2(input);
		inserirFim(p_lista, p);
		fgets(input, 99, stdin);
		input[strlen(input)-1]='\0';
	}	
	clock_t inicio = clock();
	ordenarQuickSort(p_lista, log);
	clock_t fim = clock();

	mostrar2(p_lista);

	double segundos = (fim - inicio) / (double)CLOCKS_PER_SEC / 1000.0;

	//arquivo log
	FILE* arq = fopen("651230_quicksort2.txt", "wt");
	fprintf (arq, "%s\t%d\t%d\t%lf","651230", log[0], log[1], segundos);
	fclose(arq);

	freeLista(p_lista);
}	


