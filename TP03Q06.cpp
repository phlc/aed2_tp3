/*
Ciencia da Computacao - Pucminas
Pedro Henrique Lima Carvalho
Matricula: 651230
AEDs 2

TP03 - Q06
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

//------------------------------- Pilha Flexivel --------------------------------------------

/**
*struct Pilha
*/
typedef struct Pilha{
 
//atributos
	Celula* topo;
}Pilha;

//construtor
/**
*construtorPilha - inicializa uma Pilha
*@return list*
*/

Pilha* construtorPilha (){
	Pilha* p_pilha= (Pilha*) malloc(sizeof(Pilha));
	return p_pilha;
}

//metodos

/**
*desempilhar - remove um elemento da pilha
*@return Personagem*
*/
Personagem* desempilhar (Pilha* p_pilha){
	Personagem* p_person;

	if (p_pilha->topo == NULL){
		printf("%s\n", "Erro - Pilha Vazia");
	}
	else{
		p_person = p_pilha->topo->elemento;
		Celula* tmp = p_pilha->topo;
		p_pilha->topo=p_pilha->topo->prox;
		free(tmp);
		
	}
	return p_person;
}

/**
*empilhar - insere um elemento na pilha
*@param Pilha* Personagem*
*/
void empilhar(Pilha* p_pilha, Personagem* p_person){
		Celula* tmp = construtorCelula(p_person);
		tmp->prox=p_pilha->topo;
		p_pilha->topo=tmp;
}

/**
*mostrar pilha
*@param Pilha*
*/
void mostrar(Pilha* p_pilha){
	int j=0;
	for (Celula* i=p_pilha->topo; i!=NULL; i=i->prox, j++){
		printf("%s%d%s", "[", j, "] ");
		imprimir(i->elemento);
	} 
}

/**
*zerarPeso
*@param Pilha*
*/
void zerarPeso(Pilha* p_pilha){
	for (Celula* i=p_pilha->topo; i!=NULL; i=i->prox){
		i->elemento->peso=0.0;
	}
}

/**
*mostrarRec - mostrar a pilha recursiva
*@param Pilha*, Celula*
*@return int posicao
*/
int mostrarRec(Pilha* p_pilha, Celula* i){
	int pos = 0;
	if (i!=NULL){
		pos = mostrarRec(p_pilha, i->prox);
		printf("%s%d%s", "[", pos, "] ");
		imprimir(i->elemento);
		pos++; 
	}
	return pos;
}

/**
*mostrarInv - a pilha invertida
*@param Pilha*
*/
void mostrarInv(Pilha* p_pilha){
	mostrarRec(p_pilha, p_pilha->topo);
}

/**
*comandos - executa os comandos contidos em uma string
*@param Pilha*. char* com comando
*/
void comandos (Pilha* p_pilha, char* input){
	char* cmd;
	char* path;
	Personagem* p_person;

	cmd = strtok(input, " ");

	if (strcmp(cmd, "I")==0){
		path = strtok (NULL, " ");
		p_person = constructor2(path);
		empilhar(p_pilha, p_person);
	}	

	if (strcmp(cmd, "R")==0){
		p_person = desempilhar(p_pilha);
		printf("%s%s\n", "(R) ", p_person->nome);
		freePerson(p_person);
	}
}

/**
*freePilha - libera a memoria da pilha
*@param Lista*
*/
void freePilha (Pilha* p_pilha){
	
	Celula* i = p_pilha->topo;
	if (i!=NULL){
		for (Celula* j = i->prox; j!=NULL; j=j->prox){
			freePerson(i->elemento);
			free(i);
			i=j;
		}	
		freePerson(i->elemento);
		free(i);
	}
	free(p_pilha);
}


//----------------------------------- Main ---------------------------------


/**
*Metodo main
*/
int  main(void){
        
	Pilha* p_pilha = construtorPilha();

	Personagem* p;
	char* input = (char*) malloc(sizeof(char) * 100);

	fgets(input, 99, stdin);
	input[strlen(input)-1]='\0';
		
	while(!isFim(input)){
		p = constructor2(input);
		empilhar(p_pilha, p);
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
		comandos(p_pilha, input);
	}
	zerarPeso(p_pilha);
	mostrarInv(p_pilha);
	freePilha(p_pilha);
}	


