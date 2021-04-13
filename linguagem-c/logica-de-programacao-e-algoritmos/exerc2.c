//Exercício 2
#include <stdio.h>
//permite comparação entre strings (cadeias de caracteres) 
#include <string.h>

int main() { 
    //margem 
    char margem[] = "       "; 
    //vai conter a capacidade máxima do reservatório 
    int max; 
    //algum texto inicial 
    printf("\n%sGerador de Relatório Anual - Reservatório de Água ABC", margem); 
    printf("\n\n%sInforme a capacidade máxima do reservatório em milímetros: ", margem); 
    //usuário informa a capacidade do reservatório 
    scanf("%d", &max); 
    printf("\n%sO reservatório possui %d mm de capacidade.", margem, max); 
    //pedirá que o usuário confirme que o valor está certo 
    printf("\n%sConfirme se o valor indicado está correto.", margem); 
    printf("\n\n%sO valor é esse?\n%sPor favor, digite apenas \"Sim\" ou \"Não\": ", margem, margem); 
     
    //r de resposta, conterá a resposta dada pelo usuário 
    char r[] = "";  
    scanf("%s", r); 
     
    //inicia a variável de controle 
    int c; 
    
    //o loop foi feito para tal seja infinito 
    for (c=0; c<1; c=0) { 
        
        /*mas ele quebra assim que esta condição for verdadeira 
          logo o fato do loop ser infinito se torna irrelevante*/
          
        if(!strcmp(r, "Sim") || !strcmp(r, "Não")) break; 
        
        /*essa função é da biblioteca string.h, usada para comparar strings 
          o objetivo aqui é verificar se a resposta do usuário foi "Sim" ou "Não" 
          caso contrário, o texto avisa que só se deve ser respondido com "Sim" ou "Não" 
          e pede a informação novamente*/
          
        printf("\n\n%sDigite apenas \"Sim\" ou \"Não\": ", margem); 
        //usei o "backslash" para escapar as aspas duplas
        scanf("%s", r); 
    } 
    
    /*assim que saiu do loop vai testar se a resposta é "Não" 
      para então permitir que usuário reconfigure o valor para max*/
      
    if (!strcmp(r, "Não")) { 
        printf("\n\n%sInforme novamente a capacidade máxima do reservatório: ", margem); 
        scanf("%d", &max); 
    } 
    
    //o cpódigo seguinte se efetuará ou se a r for igual a "Sim" ou se a correção foi feita 
    printf("\n\n%sÓtimo.\n%sAgora informe a quantidade (mm) de água gasta e reabastecida", margem, margem); 
    printf("\n%spela chuva para cada mês do ano.", margem); 
     
    /*cria array 2D, a primeira casa da 2ª dimensão guarda 
      os mm gastos e a segunda quantidade de mm abastecido pela chuva*/
    int dados[12][2] = {{0,0}}; 
    
    //dará nome aos meses simplesmente por questão de estética 
    char mes[12][100]={ 
        "Janeiro", "Fevereiro", 
        "Março", "Abril", "Maio", 
        "Junho", "Julho", "Agosto", 
        "Setembro", "Novembro",  
        "Outubro", "Dezembro"
    }; 
     
    /*se iniciará um loop para o usuário informar para todos os meses,
      c funcionará como identificador de posição 1D na array/matriz, portanto,
      ele deve começar com zero e nunca ser igual a 12. 
      O loop supre essas condições*/
      
    for (c=0; c<12; c++) { 
        printf("\n\n%s%s", margem, mes[c]); 
         
        printf("\n%sGasto (mm): ", margem); 
        scanf("%d", &dados[c][0]); 
         
        printf("\n%sChuva (mm): ", margem); 
        scanf("%d", &dados[c][1]); 
    } 
     
    printf("\n\n%sRelatório Completo", margem); 
     
    //loop gera relatório 
    for (c=0; c<12; c++) { 
        
        //calcula o que sobra de max quando o povo consome x e chuva enche y 
        float status = max - dados[c][0] + dados[c][1]; 
         
        /*aqui temos uma série de condições simplesmente por estética 
          tomei a liberdade de acrescentar mais um status: "TRANSBORDOU", 
          para caso a quantidade total passe do limite apresentado para o  
          reservatório*/
          
        if (status == max) { 
            
            printf("\n%s%s - Status: CHEIO", margem, mes[c]); 
            //se o valor está igual à capacidade máxima está cheio
            
        } else if (status <= 0) { 
            
            printf("\n%s%s - Status: VAZIO", margem, mes[c]); 
            //se o valor está igual ou abaixo de zero está vazio 
            
        } else if (status > max) { 
            
            printf("\n%s%s - Status: TRANSBORDOU (%.0f%% extra)", margem, mes[c], status*100/max-100); 
            //se o valor se sobrepõe à capacidade máxima então transbordou 
            //também informa o quanto transbordou em termos de percentual 
            
        } else { 
            
            printf("\n%s%s - Status: SOBROU (%.0f%% disponível)", margem, mes[c], status*100/max); 
            //se nenhuma das condições anteriores for verdadeira, o código calcula o percentual restante
            
        } 
    } 
     
    return 0;
} 
