//Exercício 1
#include <stdio.h>
int main() { 
    int p; //dá início à variável p de pedidos 
    int cont; //cont de controle 
    int compra[100][2] = {{0,0}};  
    //cria uma array 2D para gravar o item e a quantidade de unidades 
    /*só se pode colocar itens em arrays que tenham 
    um tamanho definido, por isso pus um número alto como 100 */ 
    /*Pois ele é suficientemente alto para ninguém exceder 
    o limite de compras */
     
    //algumas coisas para estilizar 
    char margem[] = "       "; 
    char bordado[] = "/**************************"; 
    char fimBordado[] = "************************/"; 
     
    /*só mostra o meu RU para eu mesmo me achar 
    junto com as informações para finalização de compra */
    printf("\n%sMeu RU: 3344308\n\n%sDigite algum número que não esteja entre 1-7 para efetuar
compra.\n", margem,margem); 
     
    //começa um loop 
    for (p = 0; p < 100; p++) { 
        printf("\n%s%s\n%sPedido %d\n", margem, bordado, margem, (p+1)); 
        printf("\n%sQual item você quer?\n%sItem ", margem, margem); 
        scanf("%d", &cont); 
        //primeiro pergunta pelo item desejado e envia para cont
        //o código abaixo verifica se cont está entre 1-7 ou não 
        //se não, termina o loop com break e passa para a próxima linha 
        if(cont > 7 || cont < 1) break; 
        //caso o valor tenha passado no teste 
        compra[p][0] = cont; 
        //...ele envia o número do item que tá gravado em cont para a compra de número p  

        /*e na casa 
        "[0]" onde fica gravado o número do item 
        na segunda dimensão da array */
        cont = 0; 
        //zera cont para continuar a ser usado no próximo loop. 
        printf("\n\n%sQuantas unidades?\n%sUnidade(s): ", margem, margem); 
        scanf("%d", &compra[p][1]); 
        /*Em seguida, pede para o usuário enviar a quantidade de 
        unidades do item desejada */
        /*e o manda para a compra de número p na casa 1 na segunda 
        dimensão da array, onde se guarda as unidades, "[1]" */
        printf("\n%s%s\n\n", margem, fimBordado); 
    } 
    
    printf("\n\n%sVocê comprou...\n\n", margem); 
    
    char produto[][100] = { 
        "cachorro(s)-quente",  
        "X-salada(s)", 
        "X-bacon(s)", 
        "misto(s)", 
        "prato(s) de salada", 
        "garrafa(s) de água", 
        "copo(s) de refrigerante"
    }; 

    /*Vamos dar nomes aos bois... Quando a lista de itens comprados 
    for apresentada, no lugar aparecerá o nome equivalente */
     
    float preco[] = { 
        5.00, 8.79, 
        9.99, 6.89, 
        4.80, 3.29, 
        4.99
    }; 
    //Os preços deles 
    float total = 0; //Este vai guardar o total a pagar 
     
    /*Agora um loop para listar os produtos comprados e atualizar 
    com os preços a variável total */
    for (cont = 0; cont < p; cont++) { 
        int item = compra[cont][0]; 
        printf("\n%s%d %s, R$ %.2f cada;\n", margem, 
        //vai mostrar como "8 misto(s), R$ 6.89 cada;" 
        /*%.2f formata a variável do tipo float, .2 significa 
        "mostrar apenas 2 decimais" */
        compra[cont][1], produto[(item-1)], preco[(item-1)]); 
        /*os -1 servem para ajustar com a questão de as arrays começarem 
        com 0 e não 1 */ 
        total = total + preco[(item-1)]*compra[cont][1];  
        /*atualiza a variável total, somando o valor anterior 
  ao preço do item vezes as unidades */
    } 
    printf("\n\n%sTotal a se pagar R$ %.2f", margem, total); 
    /*diz o total a se pagar quando, finalmente, a variável total for 
    completamente atualizada */
    return 0; 
}
