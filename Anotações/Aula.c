//############### Imprimir ###############
printf("Algo %d, e outra coisa %D", variavel, outravariavel);



//############### Capturar ###############
scanf("%d", &nomevariavel);



//############### Variáveis ###############
//Inteiras
%d

short
2 Bytes ou 16 Bits = 2^16 valores

int
4 Bytes ou 32 Bits = 2^32 valores

long
8 Bytes ou 64 Bits = 2^64 valores

//Decimais
%f //Com todas as casas decimais
%.1f //Apenas com a primeira casa decimal

float
4 Bytes ou 32 Bits = 2^32 valores

double
8 Bytes ou 64 Bits = 2^64 valores

//------------------------------------
//P/ funcionar bem com contas, é necessário
//que um dos termos também seja double, mesmo
//que seja uma constante.
//------------------------------------
//é possível também utilizar casting, quando não
//há constantes para serem alteradas, para isto basta
//fazer a/(double)b ou (double)a/b, e o resultado da conta
//será dado em ponto flutuante ao invés de inteiro.
//------------------------------------
//Também conseguimos converter dadods double pra inteiro
//fazendo o seguinte casting: int a = (int)b.
//Porém é melhor não fazer em casos de cating de dados
//com mais info para menos info.
//------------------------------------

//Texto
char
" %c" //Grava apenas uma letra, sempre usar com o espaço antes
char X = '~'; //sempre usar aspas simples para enviar uma letra
scanf("%c", &nomearray[i]);

//########### Binário ###############

X= 0 OU 1

XXXX XXXX //8 Bits foram um byte, ou seja 2^8 valores = 256

0101 b0
<<<<
(1*2^0)+(0*2^1)+(1*2^2)+(0*2^3) = 5

VVVV XXXX XXXX// Utilizamos um binário a frente para representar quantas
//casas devemos pular até inserir a vírgula. ex. 01 coloca a
//vírgula após a primeira casa.


//########### Hexa ###############

Y = 0,1,2,3,4,5,6,7,8,9,A,B,C,D,E ou F.

5BF x0
<<<
(15*16^0)+(11*16^1)+(5*16^2)=1471


//########### Arrays ###############
var X[n]; //var= tipo de veriável, X= nome do Array, n=tam Array
X[n] = Y; //Grava Y na posição n do Array X
scanf("%c", &X[i]); //faz a leitura e gravação de um char
sprintf (X,"~"); //Escreve o conteúdo de uma string em um Array
printf ("%s",X); //Escreve todo o conteudo do Array no console

strlen(X); //retorna o tamanho do Array X
// é necessária a biblioteca string.h

//------------------------------------
//Ao utilizarmos um array de char, se não utilizarmos o sprinf,
//precisamos colocar no último espaço um \0, pois representa
//O fim da string.
//------------------------------------
//Se utilizarmos o strlen em um for, cuidado para sempre fazer,
//i=0 até i<strlen(x) i++, pois o Array vai de zero à um valor.
//------------------------------------
//Podemos somar ou subtrair uma variável em conjunto com um array
//com facilidade com auxilio do += e -=, Ex.: total += X[i];
//------------------------------------
//Um Array é um ponteiro por natureza, logo X é um ponteiro,
//por este motivo não é necessário enviá-lo com &X nem utilizar
//(*X) quando o transferimos para outra função.
//------------------------------------

//############### Gerando Valores Aleatórios ###############
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int segundos = time(0);
    srand(segundos);
    int numeroGrande = rand();

    int numeroAleatorio = (numeroGrande)%100; //Divisor com resto 
    //Dá um numero entre 1 e 99
}

//------------------------------------
//Podemos definir a quantidade de números com base
//no divisor da função rand, ex.: %150 nos dá 149 valores
//------------------------------------


//############### O módulo de um valor ###############

abs(x) //dá o valor INTEIRO e positivo de X
fabsf(x) //dá o valor COM VIRGULA, float e positivo de X
fabs(x) //dá o valor COM VIRGULA, double e positivo de X


//############### Operações ###############
//For
for(int i = 1; i>=3; i++){
    //For de 1 até 3
    continue; //Pula para a próxima iteração do for
}

//If
if(primeiro verdadeiro ou falso){
    //Executar se primeiro verdadeiro
}
else if(segundo verdadeiro ou falso){
    //Executar se segundo verdadeiro
    break; //Termina o loop, caso esteja contido em um
}
else{
    //Executar se tudo falhar
}

//Switch
switch (dificuldade)
    {
    case 1:
        //Faz algo no caso 1
        break;
    case 2:
        //Faz algo no caso 2
        break;
    default:
        //Faz algo em qualquer outro valor
        break;
    }
}

//While
while(){
    //Faz algo enquanto verdadeiro, se inserirmos "1"
    //executa até encontrar um break;
}

//Do-While
do{
    //Faz algo enquanto verdadeiro, porém o teste
    //ocorre apenas após a primeira execução do bloco
}while();

//Ternário
int X = ((condição) ?   (retorno caso true)   :   (false));
    
//tambem podemos usar Ternário em prints
printf("numero %c 0\n",(X < 0 ?'<' : '>')


//############### Funções void ###############
void X (int a, double b, char c[20] ){
    double mult = (double)a * b;
    printf("%s",c);
    printf("%.1f", mult);
}

//invocação:
X(mult1,mult2,frase);


//############### Funções com retorno ###############
double X (int a, double b){
    double mult = (double)a * b;
    return mult;
}

//invocação:
double multiplicacao = X(mult1,mult2,frase);
printf("%.1f", multiplicacao);


//############### Funções e ponteiros ###############
void X (int* a){ //aponta para o endereço de memória de a
    (*a)++; //soma o VALOR contido no end. de memoria
}

//invocação:
x(&a); //envia o endereço de memória de a


//############### Lidando com arquivos ###############
FILE* f; //cria uma variável de armazenamento de arquivo

f= fopen("nomedoarquivo.txt","r"); //abre um arquivo para leitura
f= fopen("nomedoarquivo.txt","r+"); //abre um arquivo para escrita
 
if(f==0){
    //realiza algo se o banco não está disponível
}

var X; //inicia a var de armazenamento, pode ser int, char, etc.
fscanf(f,%d, &X);//lê a primeira linha do arquivo e salva em X

var Y[n]; //inicia array de armazenamento, pode ser int, char, etc.
fscanf(f,%d, Y);//lê a primeira linha do arquivo e salva em y
