#include <stdio.h>
#include <string.h>

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

void chuta(char chutes[26], int *EndTentativas)
{
    char chute;
    printf("Qual eh o seu chute? ");
    scanf(" %c", &chute);
    chutes[(*EndTentativas)] = chute;
    (*EndTentativas)++;
}

int jachutou(char chutes[26], char letra, int tentativas)
{
    int achou = 0;

    for (int j = 0; j < tentativas; j++)
    {
        if (chutes[j] == letra)
        {
            achou = 1;
            break;
        }
    }
    return achou;
}
void desenhaforca(char palavraSecreta[20], int tentativas, char chutes[26], int achou)
{
    for (int i = 0; i < strlen(palavraSecreta); i++)
    {
        int achou = jachutou(chutes, palavraSecreta[i], tentativas);

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
}

void escolhepalavra(char palavraSecreta[20]){

}

int main()
{
    char palavraSecreta[20];
    char chutes[26];
    int tentativas = 0;
    
    sprintf(palavraSecreta, "MELANCIA");

    int acertou = 0;
    int enforcou = 0;
    

    escolhepalavra(palavraSecreta);
    abertura();

    do
    {
        desenhaforca(palavraSecreta, tentativas, chutes, achou);

        chuta(chutes, &tentativas);

        printf("\n");
        printf("XXXXXXXXXXXXXXXXXXXX\n");
        printf("\n");

    } while (!acertou && !enforcou);
}