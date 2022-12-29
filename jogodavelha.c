#include <stdio.h>
#include <stdlib.h>

void fun_imprimir_jogo(char jogo[3][3], int l, int c){
    printf("\n\n\t   0   1    2\n\n");
                for (l = 0; l < 3; l++){
                    for (c = 0; c < 3; c++){
                        if(c==0){
                            printf("\t %d", l);
                        }
                        printf(" %c ", jogo[l][c]);
                        if(c < 2){
                            printf("|");
                        }
                    }
                    if(l < 2){
                    printf("\n\t  ------------");
                    }
                    printf("\n");
                }
}
void fun_guardar_ranking(nome1,v_nome1,nome2,v_nome2){
    FILE *arq;
    arq=fopen("ranking.txt","w");
    fprintf(arq,"%s --%d--\n",nome1,v_nome1);
    fflush(arq);
    fprintf(arq,"%s --%d--\n",nome2,v_nome2);
    fflush(arq);
    fclose(arq);
}
void fun__provocar(v_1,nome1,v_2,nome2){
    if(v_1>v_2){
        printf("%sta ganhando ein, se liga %s",nome1,nome2);
    }
    if(v_2>v_1){
        printf("%s ta ganhando ein, se liga %s",nome2,nome1);
    }
}
typedef struct nomes{
    char nome_jogador1[100];
    int v_jogador1;
    char nome_jogador2[100];
    int v_jogador2;
}t_nomes;

int main(){
    // estrutura de dados
    t_nomes m_nomes;
    FILE *arq;
    int escolha,l,c,linha,coluna,jogador,ganhou,jogadas,opcao,retorno,retorno2,voltar_menu=0,size;
    char jogo[3][3],letra,letra2,nome[100];
    int bufferLength = 255;
    char buffer[bufferLength];
    do{
        m_nomes.v_jogador1=0;
        m_nomes.v_jogador2=0;
        system("cls");
        printf("Ola, seja bem vindo ao Jogo da Velha\n");
        printf("\n\tMENU\n\n");
        printf("[1]Jogar(multiplayer)\n");
        printf("[2]Ranking\n");
        printf("[3]Creditos\n");
        printf("[4]Sair\n");
        scanf("%d",&escolha);
        switch (escolha)
        {
        case 1:
            system("cls");
            printf("Jogador 1, qual seu nome?\n");
            // while((getchar())!='\n');
            fflush(stdin);
            fgets(m_nomes.nome_jogador1,100,stdin);
            fflush(stdin);
            system("cls");
            printf("Jogador 2, qual seu nome?\n");
            fflush(stdin);
            fgets(m_nomes.nome_jogador2,100,stdin);
            fflush(stdin);
                do{
                    jogador = 1;
                    ganhou = 0;
                    jogadas = 0;
                    // inicializar estrutura de dados
                    for(l=0;l<3;l++){
                        for(c=0;c<3;c++){
                            jogo[l][c] = ' ';
                        }
                    }
                    do{
                        //imprimir jogo
                        system("cls");
                        fun_imprimir_jogo(jogo,l,c);
                        //ler coordenadas
                        fun__provocar(m_nomes.v_jogador1,m_nomes.nome_jogador1,m_nomes.v_jogador2,m_nomes.nome_jogador2);
                        do{
                            printf("\n%s Digite a linha e a coluna que deseja jogar\n", jogador==1?m_nomes.nome_jogador1:m_nomes.nome_jogador2);
                            retorno= scanf("%d%d", &linha, &coluna);
                            do{
                                letra = getchar();
                            }while(letra != '\n');
                        }while(retorno == 0 || linha<0 || linha > 2 || coluna < 0 || coluna > 2  || jogo[linha][coluna] != ' ');

                        //salvar coordenadas
                        if(jogador == 1){
                            jogo[linha][coluna] = 'O';
                            jogador++;
                        }
                        else{
                            jogo[linha][coluna] = 'X';
                            jogador = 1;
                        }
                        jogadas++;
                        
                        //alguem ganhou por linha
                        system("cls");
                        if(jogo[0][0] == 'O' && jogo[0][1] == 'O' && jogo[0][2] == 'O' ||
                           jogo[1][0] == 'O' && jogo[1][1] == 'O' && jogo[1][2] == 'O' ||
                           jogo[2][0] == 'O' && jogo[2][1] == 'O' && jogo[2][2] == 'O'){
                            printf("\t-----GANHOU-----");
                            fun_imprimir_jogo(jogo,l,c);
                            printf("\nParabens! O jogador %s venceu por linha!\n",m_nomes.nome_jogador1);
                            m_nomes.v_jogador1++;
                            ganhou = 1;
                        }
                        if(jogo[0][0] == 'X' && jogo[0][1] == 'X' && jogo[0][2] == 'X' ||
                           jogo[1][0] == 'X' && jogo[1][1] == 'X' && jogo[1][2] == 'X' ||
                           jogo[2][0] == 'X' && jogo[2][1] == 'X' && jogo[2][2] == 'X'){
                            printf("\t-----GANHOU-----");
                            fun_imprimir_jogo(jogo,l,c);
                            printf("\nParabens! O jogador %s venceu por linha!\n",m_nomes.nome_jogador2);
                            m_nomes.v_jogador2++;
                            ganhou = 1;
                        }
                        //alguem ganhou por coluna
                        if(jogo[0][0] == 'O' && jogo[1][0] == 'O' && jogo[2][0] == 'O' ||
                           jogo[0][1] == 'O' && jogo[1][1] == 'O' && jogo[2][1] == 'O' ||
                           jogo[0][2] == 'O' && jogo[1][2] == 'O' && jogo[2][2] == 'O'){
                            printf("\t-----GANHOU-----");
                            fun_imprimir_jogo(jogo,l,c);
                            printf("\nParabens! O jogador %s venceu por coluna!\n",m_nomes.nome_jogador1);
                            m_nomes.v_jogador1++;
                            ganhou = 1;
                        }
                        if(jogo[0][0] == 'X' && jogo[1][0] == 'X' && jogo[2][0] == 'X' ||
                           jogo[0][1] == 'X' && jogo[1][1] == 'X' && jogo[2][1] == 'X' ||
                           jogo[0][2] == 'X' && jogo[1][2] == 'X' && jogo[2][2] == 'X'){
                            printf("\t-----GANHOU-----");
                            fun_imprimir_jogo(jogo,l,c);
                            printf("\nParabens! O jogador %s venceu por coluna!\n",m_nomes.nome_jogador2);
                            m_nomes.v_jogador2++;
                            ganhou = 1;
                        }
                        //alguem ganhou por diagonal principal
                        if(jogo[0][0] == 'O' && jogo[1][1] == 'O' && jogo[2][2] == 'O'){
                            printf("\t-----GANHOU-----");
                            fun_imprimir_jogo(jogo,l,c);
                            printf("\nParabens! O jogador %s venceu por diagonal principal\n",m_nomes.nome_jogador1);
                            m_nomes.v_jogador1++;
                            ganhou = 1;
                        }
                        if(jogo[0][0] == 'X' && jogo[1][1] == 'X' && jogo[2][2] == 'X'){
                            printf("\t-----GANHOU-----");
                            fun_imprimir_jogo(jogo,l,c);
                            printf("\nParabens! O jogador %s venceu por diagonal principal\n",m_nomes.nome_jogador2);
                            m_nomes.v_jogador2++;
                            ganhou = 1;
                        }
                        //alguem ganhou por diagonal secundaria
                        if(jogo[0][2] == 'O' && jogo[1][1] == 'O' && jogo[2][0] == 'O'){
                            printf("\t-----GANHOU-----");
                            fun_imprimir_jogo(jogo,l,c);
                            printf("\nParabens! O jogador %s venceu por diagonal principal\n",m_nomes.nome_jogador1);
                            m_nomes.v_jogador1++;
                            ganhou = 1;
                        }
                        if(jogo[0][2] == 'X' && jogo[1][1] == 'X' && jogo[2][0] == 'X'){
                            printf("\t-----GANHOU-----");
                            fun_imprimir_jogo(jogo,l,c);
                            printf("\nParabens! O jogador %s venceu por diagonal principal\n",m_nomes.nome_jogador2);
                            m_nomes.v_jogador2++;
                            ganhou = 1;
                        }
                    }while(ganhou == 0 && jogadas < 9);
                    if(ganhou == 0){
                        system("cls");
                        fun_imprimir_jogo(jogo,l,c);
                        printf("\nVelha!!Empatou\n");
                    }
                    do{
                        printf("\nDigite 1 para jogar novamente ou 2 para finalizar a rodada e contabilizar o ranking de vitorias: \n");
                        retorno2= scanf("%d", &opcao);
                            do{
                                letra2=getchar();
                            } while(letra2!='\n');
                    }while(retorno2==0);
                }while(opcao == 1);
                if(opcao==2){
                    system("cls");
                    fun_guardar_ranking(m_nomes.nome_jogador1,m_nomes.v_jogador1,m_nomes.nome_jogador2,m_nomes.v_jogador2);
                    printf("%s ----> %d\n",m_nomes.nome_jogador1,m_nomes.v_jogador1);
                    printf("%s ----> %d\n",m_nomes.nome_jogador2,m_nomes.v_jogador2);
                    printf("\n\n");
                    printf("\nDeseja voltar ao menu?Digite 1\n");
                    printf("---Nota: qualquer outra tecla pressionada fechara a aplicacao.\n");
                    scanf("%d",&voltar_menu);
                }
            break;
            case 2:
                system("cls");
                arq=fopen("ranking.txt","r");
                if (NULL != arq) {
                    fseek (arq, 0, SEEK_END);
                    size = ftell(arq);
                    fclose(arq);
                    if (0 == size) {
                        printf("Ainda nao existe partida gravada no arquivo\n");
                        printf("Jogue uma rodada com um amigo e contabilize as vitorias para salva-las no arquivo\n\n");
                    }
                else{
                    arq=fopen("ranking.txt","rb");
                    printf("\tRANKING\n");
                    printf("Na ultima partida o ranking foi este:\n");
                    while(!feof(arq)){
                        while(fgets(buffer,bufferLength,arq)!=NULL){               
                        printf("%s",buffer);
                        }   
                    }
                    fclose(arq);
                }
            
                }
                    printf("\nDeseja voltar ao menu?Digite 1\n");
                    printf("---Nota: qualquer outra tecla pressionada fechara a aplicacao.\n");
                    scanf("%d",&voltar_menu);
                    break;
            case 3:
                    system("cls");
                    printf("<-----Creditos----->\n");
                    printf("Fabio Felipe Santos Viana\n");
                    printf("Gustavo Rodrigues Goncalves\n");
                    printf("Jose Placido de Andrade Neto\n");
                    printf("Vitor Emmanuel Goncalves dos Santos\n\n");
                    printf("Deseja voltar ao menu?Digite 1\n");
                    printf("---Nota: qualquer outra tecla pressionada fechara a aplicacao.\n");
                    scanf("%d",&voltar_menu);
                    break;
            case 4:
                    exit(0);
        default:
            break;
        }
    }while(voltar_menu==1);
        
    return 0;
}