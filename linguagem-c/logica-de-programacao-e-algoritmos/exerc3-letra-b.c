//Exercício 3.b 

#include <stdio.h>

int funcao(char ch) {
    /*como o que vai ser retornado é um valor numérico, 
    taquei int, mas também poderia ser float ou double*/
    if (ch >= 'A' && ch <= 'Z') 
    //verifica se char está entre os caracteres A e Z do alfabeto maiúsculo
        return ch/10; 
    else //caso contrário 
        return ch*2; 
}

int main() { 
   char ch; //inicializa a variável char
   printf("\nDigite o char : "); 
   scanf("%c", &ch);
   //pede ao usuário um valor para ch    
   printf("%d", funcao(ch));  
   //printa o resultado de ch  
   return (0); 
} 
