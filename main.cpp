#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio2.h>
#include "tad.h"

// void recuperarArq(TpDescritor &Desc){
// 	// TpTime *ListaT = Desc.Inicio, regT;
// 	// TpJogador regJ;
// 	// FILE * ptr = fopen("Times.txt","r");
// 	// if(ptr!=NULL){
// 	// 	fscanf(ptr,"%s ",&regT.NomeT);
// 	// 	fscanf(ptr,"%s ",&regJ.NomeJ);
// 	// 	while(!feof(ptr)){
// 	// 		cadTime(Desc,regT.NomeT);
// 	// 		fscanf(ptr,"%s ",&regJ.NomeJ);

			
// 	// 		fscanf(ptr,"\n");
// 	// 		fscanf(ptr,"%s ",&regT.NomeT);
// 	// 		fscanf(ptr,"%[^;]",&regJ.NomeJ);
// 	// 	}
		
// 	// }
// 	// else{
		
// 	// }
// 	fclose(ptr);
// }


char menu(){
	system("cls");
	printf("## MENU ##\n");
	printf("[A] - CADASTRAR TIMES\n");
	printf("[B] - CADASTRAR JOGADORES\n");
	printf("[C] - EXIBIR TIMES\n");
	printf("[D] - EXIBIR JOGADORES\n");
	printf("[E] - EXCLUIR TIMES\n");
	printf("[F] - EXCLUIR JOGADORES\n");
	//printf("[G] - ");
	//printf("[H] - ");
	//printf("[I] - ");
	printf("[ESC] - SAIR\n");
	printf("OPCAO: ");
	
	return toupper(getch());
}


int main(){
	TpDescritor Desc;
	TpTime Lista;
	TpJogador ListaJ;
	char op,aux;

	
	inicializar(Desc);
	//recuperarArq(Desc);
	do{
		op=menu();
		switch(op){
			case 'A' :
				system("cls"); 
				printf("## CADASTRO DE TIMES\n");
				printf("Digite o nome do time: ");fflush(stdin);
				gets(Lista.NomeT);

				while(strcmp(buscarTime(Desc,Lista.NomeT).NomeT,Lista.NomeT)==0){
					printf("## Time ja existe ##\n");
					printf("Digite o nome do time: ");fflush(stdin);
					gets(Lista.NomeT);
				}
			
				cadTime(Desc,Lista.NomeT);
			
			break;
			case 'B' : 
				system("cls"); 
				printf("## CADASTRO DE JOGADORES\n");
				printf("Digite o nome do time: ");fflush(stdin);
				gets(Lista.NomeT);

				while(strcmp(buscarTime(Desc,Lista.NomeT).NomeT,Lista.NomeT)!=0){
					printf("## Time Nao existe ##\n");
					printf("Digite o nome do time: ");fflush(stdin);
					gets(Lista.NomeT);
				}
				
				do{
				
					printf("Digite o nome do Jogador: ");fflush(stdin);
					gets(ListaJ.NomeJ);

					while(strcmp(buscarJog(Desc,Lista.NomeT,ListaJ.NomeJ).NomeJ,ListaJ.NomeJ)==0){
						printf("## Jogador ja existe ##\n");
						printf("Digite o nome do Jogador: ");fflush(stdin);
						gets(ListaJ.NomeJ);
					}
				
				
					cadJogador(Desc,Lista.NomeT,ListaJ.NomeJ);
					system("cls");
					printf("pressione algo diferente de esc para cadastrar mais jogadores\n");
					aux=getch();
				}while(aux!=27);
			break;
			case 'C' : exibir(Desc);getch();
			
			break;
			case 'D' :exibirJ(Desc);getch();
			
			break;
			case 'E' :
				system("cls");
				printf("## EXCLUIR TIMES ##\n");
				printf("Digite o nome do time: ");fflush(stdin);
				gets(Lista.NomeT);

				while(strcmp(buscarTime(Desc,Lista.NomeT).NomeT,Lista.NomeT)!=0){
					printf("## Time Nao existe ##\n");
					printf("Digite o nome do time: ");fflush(stdin);
					gets(Lista.NomeT);
				}
				excluirT(Desc,Lista.NomeT);
			
			break;
			case 'F' :
				system("cls");
				printf("## EXCLUIR JOGADORES ##\n");
				printf("Digite o nome do time: ");fflush(stdin);
				gets(Lista.NomeT);

				while(strcmp(buscarTime(Desc,Lista.NomeT).NomeT,Lista.NomeT)!=0){
					printf("## Time Nao existe ##\n");
					printf("Digite o nome do time: ");fflush(stdin);
					gets(Lista.NomeT);
				}
				
				printf("Digite o nome do Jogador: ");fflush(stdin);
				gets(ListaJ.NomeJ);

				while(strcmp(buscarJog(Desc,Lista.NomeT,ListaJ.NomeJ).NomeJ,ListaJ.NomeJ)!=0){
					printf("## Jogador Nao existe ##\n");
					printf("Digite o nome do Jogador: ");fflush(stdin);
					gets(ListaJ.NomeJ);
				}
				
				excluirJog(Desc,Lista.NomeT,ListaJ.NomeJ);
				
			break;
		}
		
		
	}while(op!=27);
	
	return 0;
}
