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

int mark_position(char houses[3][3], char player, char position) {
    for (int l = 0; l < 3; l++) {
        for (int c = 0; c < 3; c++) {
            if (position == houses[l][c]) {
                houses[l][c] = player;
                return 1;
            }
        }
    }
    return 0;
}

char check_victory(char houses[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (houses[i][0] == houses[i][1] && houses[i][1] == houses[i][2]) return houses[i][0];
        if (houses[0][i] == houses[1][i] && houses[1][i] == houses[2][i]) return houses[0][i];
    }
    
    if ((houses[0][0] == houses[1][1] && houses[1][1] == houses[2][2]) ||
        (houses[0][2] == houses[1][1] && houses[1][1] == houses[2][0])) return houses[1][1];
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (houses[i][j] != 'X' && houses[i][j] != 'O') return ' ';
        }
    }
    return 'D';
}

void game() {
	
    char houses[3][3] = {{'7', '8', '9'},
                        {'4', '5', '6'},
                        {'1', '2', '3'}};

    int position;
    char player = 'X';
    char result = ' ';

    for (int play = 0; play < 9; play++) {
        
		board(houses);
		
        printf("Jogador %c, digite a posição desejada (1-9): ", player);
        scanf("%d", &position);
        clear_input_buffer();

        if (position < 1 || position > 9) {
            printf("Posição inválida. Escolha uma posição entre 1 e 9.\n");
            play--;
            continue;
        }

        if (!mark_position(houses, player, position + '0')) {
            printf("Posição já ocupada. Escolha outra posição.\n");
            play--;
            system("pause");
            system("cls");
            continue;
        }
        system("cls");

        result = check_victory(houses);
        if (result != ' ') break;

        player = (player == 'X') ? 'O' : 'X';
    }

    board(houses);

    if (result == 'X' || result == 'O') {
        printf("Jogador %c venceu!\n", result);
        printf("Retornando ao MENU!\n");
		system("pause");
    	system("cls");
    } else if (result == 'D') {
        printf("Empate!\n");
        printf("Retornando ao MENU!\n");
		system("pause");
    	system("cls");
    } else {
        printf("Erro: jogo não terminado!\n");
    }
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    setlocale(LC_ALL, "Portuguese");

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