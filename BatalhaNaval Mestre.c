#include <stdio.h>
#define TAMANHO 10 // Definir Tamanho da matriz em 10x10


void inicializarTabuleiro(char tabuleiro[TAMANHO][TAMANHO]) { // Recursão para iniciar o tabuleiro
    for (int i = 0; i < TAMANHO; i++) // Loop para definir casas da 'água'
        for (int j = 0; j < TAMANHO; j++)
            tabuleiro[i][j] = '0'; 
            for (int i = 0; i < 3; i++){ // Loop para inserir navios em diagonal
                tabuleiro[i][i] = '3';
             } for (int i = 6; i < 9; i++){
                tabuleiro[i][i] = '3';
            }
            tabuleiro[0][9] = '3'; // Código direto para navios em vertical e diagonal
            tabuleiro[1][9] = '3';
            tabuleiro[2][9] = '3';

            tabuleiro[7][0] = '3';
            tabuleiro[7][1] = '3';
            tabuleiro[7][2] = '3';
            
}

// Recursão para código do Cone
void desenharCone(char tabuleiro[TAMANHO][TAMANHO]) {
    int centro = TAMANHO / 2; // Local do centro
    for (int i = 0; i < 3; i++) {
        for (int j = centro - i; j <= centro + i; j++) {
            if (j >= 0 && j < TAMANHO) {
                tabuleiro[i][j] = '5';
            }
        }
    }
}
// Recursão para código da Cruz
void desenharcruz(char tabuleiro[TAMANHO][TAMANHO]){
    int centrolinha = TAMANHO - 6; // Local da linha
    int centrocoluna = TAMANHO - 8; // Local da coluna

    for (int i = centrolinha - 1; i <= centrolinha + 1; i++){
        for (int j = centrocoluna - 2; j <= centrocoluna + 2; j++) {
            if (i == centrolinha || j == centrocoluna) {
                tabuleiro[i][j] = '5';
            }
        }
    }
}

// Recursão para código do Octaedro
void desenharoctaedro(char tabuleiro[TAMANHO][TAMANHO]){
    int centrolinha = TAMANHO - 4; // Local da linha
    int centrocoluna = TAMANHO - 2; // Local da coluna

    for (int i = centrolinha - 1; i <= centrolinha + 1; i++){
        for (int j = centrocoluna - 1; j <= centrocoluna + 1; j++) {
            if (i == centrolinha || j == centrocoluna) {
                tabuleiro[i][j] = '5';
            }
        }
    }
}

// Mostra o tabuleiro final
void mostrarTabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    printf("   ");
    for (int i = 0; i < TAMANHO; i++) printf("%d ", i);
    printf("\n");

    for (int i = 0; i < TAMANHO; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAMANHO; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char tabuleiro[TAMANHO][TAMANHO];

    inicializarTabuleiro(tabuleiro); // Chama o inicio do tabuleiro
    desenharCone(tabuleiro);       // Insere o cone no tabuleiro
    desenharcruz(tabuleiro);       // Insere a cruz no tabuleiro
    desenharoctaedro(tabuleiro);   // Insere o Octaedro no tabuleiro

    printf("=== BATALHA NAVAL COM CONE, CRUZ E OCTAEDRO ===\n"); // Título
    mostrarTabuleiro(tabuleiro); // Printa o tabuleiro com navios, água e habilidades

    return 0;
}


