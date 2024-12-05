Jogo da velha

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void board(char houses[3][3]) {
    printf("\n");
    printf("\t %c  | %c  | %c \n", houses[0][0], houses[0][1], houses[0][2]);
    printf("\t----+----+----\n");
    printf("\t %c  | %c  | %c \n", houses[1][0], houses[1][1], houses[1][2]);
    printf("\t----+----+----\n");
    printf("\t %c  | %c  | %c \n", houses[2][0], houses[2][1], houses[2][2]);
}

void choice(int option) {
    switch(option) {
        case 1:
            printf("Iniciando o jogo...\n");
            system("pause");
            break;
            
        case 2:
        	printf("\nCRIADORES:\n");
        	printf("\nJoão Arthur\n");
        	printf("Tiago Carneiro\n");
        	printf("Adriel Saretto\n");
        	printf("Gabriel de Souza\n");
        	system("pause");
			system("cls");	
        	break;
        	
        case 3:
            printf("Saindo...\n");
            exit(0);
            break;
            
        default:
            printf("Opção inválida!\n");
            system("pause");
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    int option;

    while (1) {
        printf("\t\t\t\t#########################################################\n");
        printf("\t\t\t\t#                                                       #\n");
        printf("\t\t\t\t#             Bem vindo ao jogo da velha!!              #\n");
        printf("\t\t\t\t#                                                       #\n");
        printf("\t\t\t\t#########################################################\n");

        printf("\n\t\t\t\t                   1- Iniciar jogo                      \n");
        printf("\t\t\t\t                   2- Creditos                             \n");
        printf("\t\t\t\t                   3- Sair                        \n");
        printf("\t\t\t\t                                                       \n");
        printf("\t\t\t\t                   Opção: ");
       
	    if (scanf("%d", &option) != 1) {
            printf("Entrada inválida! Por favor, insira um número.\n");
            clear_input_buffer();
            system("pause");
            system("cls");
            continue;
        }

        system("cls");
        choice(option);

        if (option == 1) {
            game();
        }
    }
}
