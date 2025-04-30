#include <stdio.h>
#include <stdbool.h>

int main(){
    //Inicializa as variáveis dos navios
    int navio1[3] = {3, 3, 3};
    int navio2[4] = {3, 3, 3, 3};
    int navio3[3] = {3, 3, 3};
    int navio4[3] = {3, 3, 3};
    //Inicializa as variáveis das habilidades
    int cone[3][5] = {
        {0, 0, 5, 0, 0},
        {0, 5, 5, 5, 0},
        {5, 5, 5, 5, 5},
    };
    int cruz[3][5] = {
        {0, 0, 5, 0, 0},
        {5, 5, 5, 5, 5},
        {0, 0, 5, 0, 0},
    };
    int octaedro[3][5] = {
        {0, 0, 5, 0, 0},
        {0, 5, 5, 5, 0},
        {0, 0, 5, 0, 0},
    };
    //Inicializa a variável do tabuleiro
    int tabuleiro[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };
    

    //Adiciona o navio1
    bool navio1Disponivel = true;
    for(int i = 0; i < 3; i++){
        if(tabuleiro[4+i][3] == 0){
            continue;
        } else{
            navio1Disponivel = false;
        }
    }

    if(navio1Disponivel){
        for(int i = 0; i < 3; i++){
            tabuleiro[4+i][3] = navio1[i];
        }
    } else{printf("Navio 1 Indisponível nessa localização\n"); }

    //Aduciona navio2
    bool navio2Disponivel = true;
    for(int i = 0; i < 4; i++){
        if(tabuleiro[7][1+i] == 0){
            continue;
        } else{
            navio2Disponivel = false;
        }
    }

    if(navio2Disponivel){
        for(int i = 0; i < 3; i++){
            tabuleiro[7][1+i] = navio2[i];
        }
    } else{printf("Navio 2 Indisponível nessa localização\n"); }
    
    //Aduciona navio3
    bool navio3Disponivel = true;
    for(int i = 0; i < 4; i++){
        if(tabuleiro[0+i][1+i] == 0){
            continue;
        } else{
            navio3Disponivel = false;
        }
    }

    if(navio3Disponivel){
        for(int i = 0; i < 3; i++){
            tabuleiro[0+i][1+i] = navio3[i];
        }
    } else{printf("Navio 3 Indisponível nessa localização\n"); }
    //Aduciona navio4
    bool navio4Disponivel = true;
    for(int i = 0; i < 4; i++){
        if(tabuleiro[0+i][4+i] == 0){
            continue;
        } else{
            navio4Disponivel = false;
        }
    }

    if(navio4Disponivel){
        for(int i = 0; i < 3; i++){
            tabuleiro[0+i][4+i] = navio4[i];
        }
    } else{printf("Navio 4 Indisponível nessa localização\n"); }

    //Habilidade cone
    int pontoOrigemConeX = 5;
    int pontoOrigemConeY = 7;
    bool habilidadeConeDisponivel = true;
    //Condicional de disponibilidade da Cone
    for(int i = 0; i <3; i++){
        for(int j = 0; j<5; j++){
            
            if(i+(pontoOrigemConeY) <= 10 && j+(pontoOrigemConeX-2) <= 10){
                continue;
            } else{
                habilidadeConeDisponivel = false;
                break;
            }
            
        }
    }
    if(habilidadeConeDisponivel){ //Checa a disponibilidade da habilidade, se for verdadeiro, prossegue com o código da habilidade
        for(int i = 0; i <3; i++){
            for(int j = 0; j<5; j++){
                if(cone[i][j]!=0){
                    tabuleiro[i+pontoOrigemConeY][j+(pontoOrigemConeX-2)] = cone[i][j];
                }
            }
        }
    } else{ printf("Habilidade Cone Indisponível nessa localização\n");}
    
    //Habilidade cruz
    int pontoOrigemCruzX = 3;
    int pontoOrigemCruzY = 3;
    bool habilidadeCruzDisponivel = true;
    //Condicional de disponibilidade da Cruz
    for(int i = 0; i <3; i++){
        for(int j = 0; j<5; j++){
            
            if(i+(pontoOrigemCruzY-1) <= 10 && j+(pontoOrigemCruzX-2) <= 10){
                continue;
            } else{
                habilidadeCruzDisponivel = false;
                break;
            }
            
        }
    }
    if(habilidadeCruzDisponivel){ //Checa a disponibilidade da habilidade, se for verdadeiro, prossegue com o código da habilidade
        for(int i = 0; i <3; i++){
            for(int j = 0; j<5; j++){
                if(cruz[i][j]!=0){
                    tabuleiro[i+(pontoOrigemCruzY-1)][j+(pontoOrigemCruzX-2)] = cruz[i][j];
                }
            }
        }
    } else{ printf("Habilidade Cruz Indisponível nessa localização\n");}
    
    //Habilidade octaedro
    int pontoOrigemOctaedroX = 5;
    int pontoOrigemOctaedroY = 5;
    bool habilidadeOctaedroDisponivel = true;
    //Condicional de disponibilidade do octaedro
    for(int i = 0; i <3; i++){
        for(int j = 0; j<5; j++){
            
            if(i+(pontoOrigemOctaedroY-1) <= 10 && j+(pontoOrigemOctaedroX-2) <= 10){
                continue;
            } else{
                habilidadeOctaedroDisponivel = false;
                break;
            }
            
        }
    }
    if(habilidadeOctaedroDisponivel){ //Checa a disponibilidade da habilidade, se for verdadeiro, prossegue com o código da habilidade
        for(int i = 0; i <3; i++){
            for(int j = 0; j<5; j++){
                if(octaedro[i][j]!=0){
                    tabuleiro[i+(pontoOrigemOctaedroY-1)][j+(pontoOrigemOctaedroX-2)] = octaedro[i][j];
                }
            }
        }
    } else{ printf("Habilidade Octaedro Indisponível nessa localização\n");}
    
    

    //Exibe o tabuleiro
    for(int i = 0; i <10; i++){
        for(int j = 0; j<10; j++){
            printf("%i ", tabuleiro[i][j]);
        }
        printf("\n");
    }

}