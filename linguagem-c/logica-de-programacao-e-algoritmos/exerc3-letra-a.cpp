//Exercício 3 .a
#include <stdio.h>  

int main() 
{ 
    char margem[] = "       "; //margem para deixar o texto alinhado e estético
    
    //algum texto inicial sem motivo algum 
    printf("\n%sIsso aqui é um analisador de texto. Comece inicializando quantos nomes ou", margem); 
    printf("\n%scadeias de caracteres você quer analisar por vez.", margem);  
    printf("\n%s(atenção: limite máximo de 10 cadeias de 10 caracteres cada)", margem);
    
    int c, cads, carac; //iniciar as variáveis c, cads e carac
    /*
        1.c vai controlar os loops;
        2.cads nos dá o número de cadeias a serem analisadas (M)
        3.o número de caracteres máximo para cada (N)
        CadsXCarac = MxN
    */
    printf("\n\n%sNúmero de cadeias: ", margem); 
    scanf("%d", &cads); //é solicitado ao usuário que defina o calor para cads
    
    //se o valor enviado for maior que 10 ou menor que 1...
    if (cads > 10 || cads < 1) {
        
        //...ele é pego dentro de um loop, que destranca somente quando o valor
        //enviado está dentro dos requisitos (maior que 1 e menor que 10)
        for (c=0; c<1; c=0) { 
            printf("\n%sValor inválido! Digite um número entre 1 e 10: ", margem); 
            scanf("%d", &cads); 
            if (cads <= 10 && cads >= 1) break;
            //veja que aqui, a cada fim de loop, o código testa constantemente a condição
            //quando ela for sucedida o loop quebra, caso contrário, o loop vai se repetir 
            //novamente, hence why it's infinite
        } 
    } 
    printf("\n%sNúmero de caracteres por cadeia: ", margem); 
    scanf("%d", &carac); //é solicitado ao usuário que defina o valor para carac
    
    //se o valor enviado for maior que 10 ou menor que 1...
    if (carac > 10 || carac < 1) {
        
        //...ele é pego dentro de um loop, que destranca somente quando o valor
        //enviado está dentro dos requisitos (maior que 1 e menor que 10)
        for (c=0; c<1; c=0) { 
            printf("\n%sValor inválido! Digite um número entre 1 e 10: ", margem); 
            scanf("%d", &carac); 
          
            if (carac <= 10 && carac >= 1) break; 
            //veja que aqui, a cada fim de loop, o código testa constantemente a condição
            //quando ela for sucedida o loop quebra, caso contrário, o loop vai se repetir 
            //novamente, hence why it's infinite
        } 
    }
    
    //assim que os valores forem definidos
    //uma array 2D ou matriz é construída por cima desses valores
    //ela terá a função de guardar cada cadeia de caracteres a ser analisada
    char cadeias[cads][carac]; 
    
    printf("\n\n%sAgora. Digite a(s) cadeia(s) completa(s): \n", margem); 
     
    
    //um loop se efetuará para o usuário definir cada cadeia
    for (c=0; c<cads; c++) { 
        printf("\n%sCadeia %d: ", margem, c+1); 
        scanf(" %[^\n]s", cadeias[c]); //"%[^\n]" é código Regex para 'qualquer caractere ("
[]") exceto ("^") newlines ("\n")'
        //usei para que o scanf aceite cadeias com espaços em branco também
        /*
            Tem um fato curioso também.
            Quando fiz essa parte do código.
            Esse scanf acima estava sendo pulado automaticamente.
            Pesquisei, pesquisei e pesquisei, e encontrei que 
            scanfs do tipo string podem aceitar espaço vazio também,
            vários scanfs em ordem podem causar esse efeito,
            logo, a solução era acrescentar um espaço antes,
            ou seja: "%[^\n]" vira " %[^\n]".
            
            Sinceramente, eu não tenho certeza do porquê, mas,
            posteriormente, eu vou procurar entender melhor
            o porquê disto.
        */
        
        /*
            c começa com zero
            scanf envia o valor informado pelo usuário para
            cadeias[0]
            c é incrementado
            scanf enviará agora para cadeias[1]
            esse ciclo continuará até que c se torne igual a cads,
            que é o número de cadeias que o usuário pediu para serem 
            analisadas.
            
            Cada caractere enviado no scanf ocupa uma casa diferente
            na segunda dimensão. Ex:
            
                "Felipe"
                F -> cadeias[x][0]
                e -> cadeias[x][1]
                l -> cadeias[x][2]
                ...
                
            E assim sucessivamente, pois o scanf faz isso automaticamente. 
            Ele realoca automaticamente.
        */
    } 
    
    
    //Agora uma tabela será gerada para mostrar os resultados
    //Esse loop continua contanto que c seja menor que cads,
    //que é o número de cadeias a serem analisadas, porque...
    for (c=0; c<cads; c++) {
       
        //...ele tem como função criar o cabeçalho de cada tabela.
        //Cada cadeia terá sua tabela, com seu cabeçalho.
        printf("\n\n%sCadeia %d", margem, c+1);  
        printf("\n%s\"%s\"", margem, cadeias[c]); 
        printf("\n"); 
        printf("\n%s _________________________________ ", margem); 
        printf("\n%s|               |                 |", margem); 
        printf("\n%s|   Caractere   |   Ocorrências   |", margem); 
        printf("\n%s|_______________|_________________|", margem); 
         
        //Agora esse é o loop para criar o corpo da tabela.
        //Será gerada uma linha da tabela para cada caractere da sequência,
        //por isso "c2>carac".
        for (int c2=0; c2<carac; c2++) {
            
            //aqui contará as ocorrências de um caractere
            int ocurs = 0; 
            for (int c3=0; c3<carac; c3++) { 
                if (cadeias[c][c2] == cadeias[c][c3])  
                    ocurs++;
                /*
                    a linha de cima significa:
                    
                    "Se o caractere da linha for igual ao primeiro caractere da seguência (c3 = 0),
                    ocurs ganha mais um.
                    Se o caractere da linha for igual ao segundo caractere da seguência (c3++, c3 = 1),
                    ocurs ganha mais um"
                    
                    Ocurs gravará o número de ocorrências.
                    
                    O loop continua até que c3 não seja mais menor que carac.
                */
            }
            
            printf("\n%s|               |                 |", margem); 
            printf("\n%s|       \"%c\"     |        %d        |", margem, cadeias[c][c2], ocurs); 
            printf("\n%s|_______________|_________________|", margem); 
            
            //cria a linha, juntando o caractere com o número de ocorrências recém contado
            //esses espaços aleatórios são para ajustar os limitadores da tabela
na visão do terminal
        } 
    } 
     
    return 0; 
}
