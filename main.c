#include <stdio.h>

#define MEM_SIZE 16

// Registradores
int AC = 0; // Acumulador
int PC = 0; // Contador de Programa

// Memória
int memory[MEM_SIZE] = {0}; // Memória com 16 células

// Função para adicionar dois números e armazenar o resultado em AC
void add(int operand) {
    AC += operand;
}

// Função para imprimir o estado atual do processador
void print_state() {
    printf("PC: %d\n", PC);
    printf("AC: %d\n", AC);
    printf("Memory: ");
    for (int i = 0; i < MEM_SIZE; ++i) {
        printf("%d ", memory[i]);
    }
    printf("\n");
}

int main() {
    // Programa de exemplo - uma simples adição
    memory[0] = 1;  // Carregar valor para AC
    memory[1] = 10; // Operando para adição
    memory[2] = 2;  // Somar com o valor no AC
    memory[3] = 10; // Operando para adição
    memory[4] = 0;  // Parar

    // Loop de execução do programa
    while (1) {
        int instruction = memory[PC];
        int operand = memory[PC + 1];
        PC += 2; // Avança para a próxima instrução

        switch (instruction) {
            case 0: // Parar
                printf("Programa encerrado.\n");
                print_state();
                return 0;
            case 1: // Carregar valor para AC
                AC = operand;
                break;
            case 2: // Somar com o valor no AC
                printf("%d\n",operand);
                add(operand);
                break;
            default:
                printf("Instrução inválida: %d\n", instruction);
                return 1;
        }
    }

    return 0;
}
