#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "forca.h"

//Variáveis Globais
char palavraSecreta[TAM_PALAVRA];
char chutes[26];
int ponteirochute = 0;

void abertura()
{
    printf("\n");
    printf("##################\n");
    printf("#                #\n");
    printf("# Jogo da Forca! #\n");
    printf("#                #\n");
    printf("##################\n");
    printf("\n");
}

void chuta()
{
    char chute;
    printf("Qual eh o seu chute? ");
    scanf(" %c", &chute);
    printf("\n");

    chutes[ponteirochute] = chute;
    ponteirochute++;
}

int jachutou(char letra)
{
    int achou = 0;

    for (int j = 0; j < ponteirochute; j++)
    {
        if (chutes[j] == letra)
        {
            achou = 1;
            break;
        }
    }
    return achou;
}
void desenhaforca()
{
    int erros = chuteserrados();

    printf("  _______      \n");
    printf(" |/      |     \n");

    printf(" |      %c%c%c    \n",
    (erros >=1 ?'(' : ' '),
    (erros >=1 ?'_' : ' '),
    (erros >=1 ?')' : ' '));

    printf(" |      %c%c%c   \n",
    (erros >=3 ?'\\' : ' '),
    (erros >=2 ?'|' : ' '),
    (erros >=4 ?'/' : ' '));

    printf(" |       %c     \n",
    (erros >=2 ?'|' : ' '));

    printf(" |      %c %c   \n",
    (erros >=5 ?'/' : ' '),
    (erros >=6 ?'\\' : ' '));

    printf(" |             \n");
    printf("_|___          \n");
    printf("\n\n");
    
    
    for (int i = 0; i < strlen(palavraSecreta); i++)
    {
        int achou = jachutou(palavraSecreta[i]);

        if (achou)
        {
            printf("%c ", palavraSecreta[i]);
        }
        else
        {
            printf("_ ");
        }
    }
    printf("\n");
    printf("\n");
    printf("XXXXXXXXXXXXXXXXXXXX\n");
    printf("\n");
}

void adicionapalavra()
{
    char quer;
    printf("\n");
    printf("Deseja adicionar uma palavra ao jogo? (S/N)");
    scanf(" %c", &quer);

    if (quer == 'S')
    {
        char novapalavra[TAM_PALAVRA];

        printf("Digite a palavra: \n");
        scanf("%s", novapalavra);

        FILE *f;
        f = fopen("palavras.txt", "r+");

        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;

        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novapalavra);

        fclose(f);
    }
}

void escolhepalavra()
{
    FILE *f;

    f = fopen("palavras.txt", "r");
    if (f == 0)
    {
        printf("Desculpe, o banco nao esta disponivel!");
        exit(1);
    }

    int qtdpalavras;
    fscanf(f, "%d", &qtdpalavras);

    srand(time(0));
    int randomico = rand() % qtdpalavras;
    // Ao usar o %, incluimos o -1

    for (int i = 0; i <= randomico; i++)
    {
        fscanf(f, "%s", palavraSecreta);
    }

    fclose(f);
}

int chuteserrados(){
    int erros = 0;

    for (int i = 0; i < ponteirochute; i++)
    {
        int existe = 0;

        for (int j = 0; j < strlen(palavraSecreta); j++)
        {
            if (chutes[i] == palavraSecreta[j])
            {
                existe = 1;
                break;
            }
        }

        if (!existe)
            erros++;
    }

    return erros;
}

int enforcou()
{
    return chuteserrados() >= 6;
}

int ganhou()
{
    for (int i = 0; i < strlen(palavraSecreta); i++)
    {
        if (!jachutou(palavraSecreta[i]))
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    escolhepalavra();
    abertura();

    do
    {
        desenhaforca();

        chuta();

    } while (!ganhou() && !enforcou());

    if (ganhou())
    {
        printf("\nParabens, voce ganhou!\n\n");

        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");
        adicionapalavra();
    }
    else
    {
        printf("\nPoxa, voce foi enforcado!\n");
        printf("A palavra era **%s**\n\n", palavraSecreta);

        printf("    _______________         \n");
        printf("   /               \\       \n");
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n\n");
    }
}