/*
Ciencia da Computacao - Pucminas
Pedro Henrique Lima Carvalho
Matricula: 651230
AEDs 2

TP03 - Q03
*/

//dependencias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
//------------------------------------ Celula ----------------------------------------------

/**
*struct Celula
*/
typedef struct Celula{
 
 //atributos 
	Personagem* elemento;
	Celula* prox;

}Celula;

 //construtor
	Celula* construtorCelula (Personagem* p){
		Celula* cel = (Celula*) malloc(sizeof(Celula));
		
		cel->elemento = p;
		cel->prox = NULL;
		
		return cel;
	}

//------------------------------- Fila Flexivel "Circular" ---------------------------------

/**
*struct Fila
*/
typedef struct Fila{
 
//atributos
	Celula* primeiro;
	Celula* ultimo;
}Fila;

//construtor
/**
*construtorFila - inicializa uma Fila
*@param int tamanho
*@return list*
*/
Fila* construtorFila (int size){

	Fila* p_fila;

	if (size < 1){
		printf("%s\n", "Erro - Tamanho da Lista Invalido");
	}
	else{
		p_fila = (Fila*) malloc (sizeof(Fila)*1);	
		p_fila->primeiro = construtorCelula (NULL);

		Celula* c = p_fila->primeiro;
		for(int i=0; i<size; i++){
			c->prox = construtorCelula(NULL);
			c=c->prox;
		}
		
		c->prox=p_fila->primeiro;
		p_fila->ultimo = p_fila->primeiro;
	}
	return p_fila;
}

//metodos

/**
*desenfileirar - remove um elemento inicio da fila
*@return Personagem*
*/
Personagem* desenfileirar (Fila* p_fila){
	Personagem* p_person;

	if (p_fila->primeiro == p_fila->ultimo){
		printf("%s\n", "Erro - fila Vazia");
	}
	else{
		Celula* tmp = p_fila->primeiro;
		p_fila->primeiro = p_fila->primeiro->prox;
		p_person = tmp->elemento;
		tmp->elemento=NULL;
		
	}
	return p_person;
}

//declaracao de mediaAlturas
void mediaAltura(Fila* p_fila);

/**
*enfileirar - insere um elemento no final da fila
*@param Fila* Personagem*
*/
void enfileirar(Fila* p_fila, Personagem* p_person){
	if (p_fila->ultimo->prox != p_fila->primeiro){

		p_fila->ultimo->elemento = p_person;
		p_fila->ultimo=p_fila->ultimo->prox;

		//media alturas
		mediaAltura(p_fila);

	}
	else{
		Personagem* p = desenfileirar (p_fila);
		freePerson(p);
		enfileirar(p_fila, p_person);
	}
	
	
}

/**
*mostrar fila
*@param Fila*
*/
void mostrar(Fila* p_fila){
	int j=0;
	for (Celula* i=p_fila->primeiro; i!=p_fila->ultimo; i=i->prox, j++){
		printf("%s%d%s", "[", j, "] ");
		imprimir(i->elemento);
	} 
}

/**
*comandos - executa os comandos contidos em uma string
*@param Fila*. char* com comando
*/
void comandos (Fila* p_fila, char* input){
	char* cmd;
	char* path;
	Personagem* p_person;

	cmd = strtok(input, " ");

	if (strcmp(cmd, "I")==0){
		path = strtok (NULL, " ");
		p_person = constructor2(path);
		enfileirar(p_fila, p_person);
	}	

	if (strcmp(cmd, "R")==0){
		p_person = desenfileirar(p_fila);
		printf("%s%s\n", "(R) ", p_person->nome);
		freePerson(p_person);
	}
}

/**
*freeFila - libera a memoria da fila
*@param Lista*
*/
void freeFila (Fila* p_fila){
	
	Celula* i = p_fila->primeiro;
	while (i!=p_fila->ultimo){
		freePerson(i->elemento);
	}
	p_fila->ultimo=NULL;
	
	Celula* j = i = p_fila->primeiro->prox;
	while(i!=p_fila->primeiro){
		j=j->prox;
		free(i);
		i=j;
	}
	free(p_fila->primeiro);
	free(p_fila);
}

/**
*mediaAlturas
*@param Fila*
*/
void mediaAltura(Fila* p_fila){
	double m = 0.0;
	int ocupados = 0;
	for (Celula* i=p_fila->primeiro; i!=p_fila->ultimo; i=i->prox){
		m = m + i->elemento->altura;
		ocupados++;
	}
	m = m/(ocupados);
	
	if (m-(int)m >= 0.5)
		m += 0.5;
	printf("%d\n",(int) m);
}


//----------------------------------- Main ---------------------------------


/**
*Metodo main
*/
int  main(void){
        
	Fila* p_fila = construtorFila(5);

	Personagem* p;
	char* input = (char*) malloc(sizeof(char) * 100);

	fgets(input, 99, stdin);
	input[strlen(input)-1]='\0';
		
	while(!isFim(input)){
		p = constructor2(input);
		enfileirar(p_fila, p);
		fgets(input, 99, stdin);
		input[strlen(input)-1]='\0';
	}	
	int n = 0;

	fgets(input, 99, stdin);
	input[strlen(input)-1]='\0';
	sscanf(input, "%d", &n);

	for (int i=0; i<n; i++){
		fgets(input, 99, stdin);
		input[strlen(input)-1]='\0';
		comandos(p_fila, input);
	}
	mostrar(p_fila);
	freeFila(p_fila);
}	


