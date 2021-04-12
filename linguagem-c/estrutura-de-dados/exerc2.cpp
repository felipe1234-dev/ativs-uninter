#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define A 0.618

struct Aluno {
    int RU;
    char email[50];
    char nomeDoAluno[50];
};

typedef struct Aluno Aluno;

// Função hash 
int h(int k, int m);

int main() {
    
    
    return 0;
}

int h(int k, int m) {
    return floor(m*(k*A - floor(k*A)));
}
