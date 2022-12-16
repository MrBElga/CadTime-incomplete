#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct TpJogador{
	char NomeJ[30];
	TpJogador *prox;
};

struct TpTime{
	char NomeT[35];
	TpJogador *ListaJ;
	TpTime *prox, *ant;
};

struct TpDescritor{
	int Qtde;
	TpTime *Inicio, *Fim;
};

void inicializar(TpDescritor &Desc){
	Desc.Qtde = 0;
	Desc.Inicio = Desc.Fim = NULL;
}

TpTime *novoTime(char Nome[]){
	TpTime *Caixa = new TpTime;
	strcpy(Caixa->NomeT,Nome);
	Caixa->ant = Caixa->prox = NULL;
	Caixa->ListaJ = NULL;
	return Caixa;
}

void cadTime(TpDescritor &Desc, char Nome[]){
	TpTime *Lista = Desc.Inicio, *Caixa, *P;
	Desc.Qtde++;
	
	Caixa = novoTime(Nome);
	if(Desc.Inicio==NULL){//vazio
		Desc.Inicio = Desc.Fim = Caixa;
	}
	else if(strcmp(Lista->NomeT,Nome)>0){//inicio
		Desc.Inicio->ant = Caixa;
		Caixa->prox = Desc.Inicio;
		Desc.Inicio = Caixa;
	}
	else if(strcmp(Desc.Fim->NomeT,Nome)<0){
		Desc.Fim->prox = Caixa;
		Caixa->ant = Desc.Fim->ant;
		Desc.Fim = Caixa;
	}
	else{
		P = Lista->prox;
		while(P != NULL && strcmp(P->NomeT,Nome)<0)
			P = P->prox;
		Caixa->prox = P;
		Caixa->ant = P->ant;
		P->ant->prox = Caixa;
		P->ant= Caixa;
	}
}

void exibir(TpDescritor Desc){
	TpTime *Lista = Desc.Inicio;
	system("cls");
	printf("## TIMES ##\n");
	while(Lista != NULL){
		printf("%s",Lista->NomeT);
		Lista = Lista->prox;
		printf("\n");
	}
}

TpTime buscarTime(TpDescritor Desc, char Nome[]){
	TpTime *Lista = Desc.Inicio,reg;
	
	while(Lista != NULL && strcmp(Lista->NomeT,Nome)!=0)
		Lista = Lista->prox;
	if(Lista != NULL)
		reg = *Lista;
		
	return reg;
}

TpJogador *novoJogador(char Nome[]){
	TpJogador *Caixa = new TpJogador;
	
	strcpy(Caixa->NomeJ, Nome);
	Caixa->prox = NULL;
	
	return Caixa;
}

void cadJogador(TpDescritor &Desc,char NomeT[],char NomeJ[]){
	TpTime *ListaT = Desc.Inicio;
	TpJogador *ListaJ, *Caixa, *P, *Ant;
	
	Caixa = novoJogador(NomeJ); 
	
	while(ListaT != NULL && strcmp(ListaT->NomeT,NomeT)!=0)
		ListaT = ListaT->prox;
		
	ListaJ = ListaT->ListaJ;
	
	if(ListaJ == NULL){
		ListaJ = Caixa;
	}
	else if(strcmp(ListaJ->NomeJ,NomeJ)>0){
		Caixa->prox = ListaJ;
		ListaJ = Caixa;
	}
	else{
		P=ListaJ->prox;
		Ant = ListaJ;
		while(P!=NULL && strcmp(P->NomeJ,NomeJ)<0){
			Ant = P;
			P = P->prox;
		}
		if(P != NULL){
			Caixa->prox = P;
			Ant->prox = Caixa;
		}
		else{
			Ant->prox = Caixa;
		}
	}
	ListaT->ListaJ = ListaJ;
}

TpJogador exibirJ(TpDescritor Desc){
	TpTime *ListaT = Desc.Inicio;
	TpJogador *ListaJ;
	system("cls");
	printf("## TIMES E JOGADORES\n");
	while(ListaT!=NULL){
		printf("##------ %s ------##\n\n",ListaT->NomeT);
		if(ListaT->ListaJ==NULL)
			printf("## --Nao Ha Jogadores-- ##\n");
		ListaJ = ListaT->ListaJ;
		while(ListaJ!=NULL){
			printf("%s \n",ListaJ->NomeJ);
			ListaJ = ListaJ->prox;
		}
		printf("\n##----------------------------##\n\n");
		ListaT = ListaT->prox;
	}
}

TpJogador buscarJog(TpDescritor Desc, char NomeT[], char NomeJ[]){
	TpTime *ListaT = Desc.Inicio;
	TpJogador *ListaJ,reg;
	
	while(ListaT!=NULL && strcmp(ListaT->NomeT,NomeT)!=0){
		ListaT = ListaT->prox;
	}	
	ListaJ = ListaT->ListaJ;
	while(ListaJ!=NULL && strcmp(ListaJ->NomeJ,NomeJ)!=0){
		ListaJ = ListaJ->prox;
	}
	if(ListaJ!=NULL)
		reg = *ListaJ;
	return reg;
}

void excluirJog(TpDescritor &Desc, char NomeT[], char NomeJ[]){
	TpTime *ListaT = Desc.Inicio;
	TpJogador *Lista, *Ant, *aux;
	
	while(ListaT!=NULL && strcmp(ListaT->NomeT,NomeT)!=0)
		ListaT=ListaT->prox;
	
	Lista=ListaT->ListaJ;
	aux=Lista;
	
	if(strcmp(Lista->NomeJ,NomeJ)==0){//primeiro
		ListaT->ListaJ = Lista->prox;
		delete(aux);
	}
	else{
		Ant = Lista;
		aux = Lista->prox;
		while(strcmp(aux->NomeJ,NomeJ)!=0 && aux!=NULL){
			Ant = aux;
			aux = aux->prox;
		}
		if(aux != NULL){
			Ant->prox = aux->prox;
			delete(aux);
		}
		else{
			 Ant->prox = NULL;
			 delete(aux);
		}
	}

}

void excluirT(TpDescritor &Desc,char NomeT[]){
	TpTime *Lista = Desc.Inicio,*aux;
	TpJogador *ListaJ;
	Desc.Qtde--;
	
	while(Lista!=NULL && strcmp(Lista->NomeT,NomeT)!=0)
		Lista = Lista->prox;
	ListaJ = Lista->ListaJ;
	while(ListaJ!=NULL){
		excluirJog(Desc,NomeT,ListaJ->NomeJ);
		ListaJ=ListaJ->prox;
	}
	
	aux = Lista;
	if(Desc.Qtde==0){
		Desc.Inicio = Desc.Fim = NULL;
		delete(aux);
	}
	else if(strcmp(Desc.Inicio->NomeT,NomeT)==0){
		Desc.Inicio->ant = NULL;
		Desc.Inicio = Desc.Inicio->prox;
		delete(aux);
	}
	else if(strcmp(Desc.Fim->NomeT,NomeT)==0){
		Desc.Fim->ant->prox = NULL;
		Desc.Fim=Desc.Fim->ant;
		delete(aux); 
	}
	else{
		aux->ant->prox = aux->prox;
		aux->prox->ant = aux->ant;
		delete(aux);
	}
}
