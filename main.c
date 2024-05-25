#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void forca(
    int estado) { // Função forca: criar a 'imagem' da forca para cada estado.

  switch (estado) {
  case 0:
    printf("\n---------------");
    printf("\n|             |"); // APENAS A FORCA
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n-");
    break;
  case 1:
    printf("\n---------------");
    printf("\n|             |");
    printf("\n|             O");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n-");
    break;
  case 2:
    printf("\n---------------");
    printf("\n|             |");
    printf("\n|             O");
    printf("\n|             |");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n-");
    break;
  case 3:
    printf("\n---------------");
    printf("\n|             |");
    printf("\n|             O");
    printf("\n|             |\\"); // Para ser desenhado um braço é necessário usar duas barras invertidas.
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n-");
    break;
  case 4:
    printf("\n---------------");
    printf("\n|             |");
    printf("\n|             O");
    printf("\n|            /|\\");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n-");
    break;
  case 5:
    printf("\n---------------");
    printf("\n|             |");
    printf("\n|             O");
    printf("\n|            /|\\");
    printf("\n|              \\");
    printf("\n|");
    printf("\n|");
    printf("\n-");
    break;
  case 6:
    printf("\n---------------");
    printf("\n|             |");
    printf("\n|             O");
    printf("\n|            /|\\");
    printf("\n|            / \\");
    printf("\n|");
    printf("\n|        VOCÊ FOI ENFORCADO, O JOGO ACABOU! ");
    printf("\n-");
    break;
  }
}
void limpa_tela() { system("clear || cls"); }


char* obter_tema(int tema) {

  switch (tema) {
  case 0:
    return "Animais";
  case 1:
    return "Objetos";
  case 2:
    return "Comidas";
  case 3:
    return "Países";
  case 4:
    return "Profissões";
  case 5:
    return "Flores\n";
  } 

  return ""; 
}

void imprimir_temas() {
  
  printf("Escolha um dos temas abaixo para iniciar o Jogo da Forca:\n\n");
  for(int i = 0; i < 6; i++) {
      printf("%d - %s\n", i, obter_tema(i));
  }
}

int main(void) {

  int erros = 0; // Ao erro do jogador,é add +1
  char palavra_secreta[100], contraprova[100], letra, erro1, erro2, erro3, erro4, erro5, erro6;

  int tema_escolhido; // Verificar se o número do tema é válido
  char temas[6][10][100] = {
      {"cachorro", "gato", "elefante", "leao", "tigre", "girafa", "macaco", "panda", "zebra", "rinoceronte"},
      {"celular", "computador", "notebook", "microondas", "tablet", "televisao", "guarda-chuva", "ventilador", "frigobar", "ar-condicionado"},
      {"macarrao", "feijao", "arroz", "batata", "carne", "ovo", "lasanha", "pizza", "hamburguer", "sushi"},
      {"brasil", "argentina", "chile", "paraguai", "uruguai", "peru", "colombia", "venezuela", "equador", "bolivia"},
      {"engenheiro", "medico", "professor", "dentista", "matematico", "arquiteto", "programador", "designer", "contador", "fisioterapeuta"},
      {"rosa", "orquidea", "margarida", "tulipa", "cravo", "lirio", "petunia", "azaleia", "bromelia", "hibisco"},
  };

  imprimir_temas();

  printf("Digite o numero do tema escolhido: ");
  scanf("%d", &tema_escolhido);

  if (tema_escolhido < 0 || tema_escolhido > 5) {
    printf("Tema invalido. Escolha um numero entre 0 e 5.\n");
    
    return 1; // Encerrar o programa com código de erro
  }

  srand(time(NULL));
  int palavra_aleatoria = rand() % 10; // Declaração e inicialização da palavra aleatória
  strcpy(contraprova, temas[tema_escolhido][palavra_aleatoria]);
  strcpy(palavra_secreta, temas[tema_escolhido][palavra_aleatoria]);

 

  for (int i = 0; i < strlen(contraprova); i++) { // substitui a letra por underline
    if (contraprova[i] == '-') {
        contraprova[i] = '-'; // usado apenas uma aspas pq é relacionado à um caractere da palavra.
    } else {
          contraprova[i] = '_';
    }
  }

  limpa_tela();

  while (1) {
    limpa_tela(); // imprimir a forca
    forca(erros);
    printf("\nAdivinhe a palavra: "); // imprimir o numero de letras respectivo à palavra secreta

    for (int i = 0; i < strlen(contraprova);
         i++) // adiciona os espaços entre as letras.
      printf("%c ", contraprova[i]);
      printf("\n\nA palavra tem %zu caracteres", strlen(contraprova)); // recebe a letra
      printf("\nO tema escolhido foi: %s", obter_tema(tema_escolhido));
      printf("\nLetras erradas: %c, %c, %c, %c, %c, %c", erro1, erro2, erro3, erro4, erro5, erro6);
      printf("\n\nDigite a letra: "); 
      scanf(" %c", &letra);
    
    
    // verifica se a letra esta correta para todas as letras
    int sera_que_errou = 1; //é considerado que a principio ele errou. E se ainda sim o valor do 'sera que errou' permanecer verdadeiro apos passar pelo primeiro if, add +1 no erro.

    for (int i = 0; i < strlen(contraprova); i++) {
      if (letra == palavra_secreta[i]) { // letra digitada = letra da palavra secreta que esta rodando no for
          contraprova[i] = letra;
        sera_que_errou = 0; // se caso ele acertou pelo menos 1 letra, o valor do 'sera que errou' se torna falso. E por tanto  nao é add +1 no erro.
      }
    }
    if (sera_que_errou == 1) {
      erros++;
      if (erros==1){
        erro1 = letra;
      }
      if (erros==2){
        erro2 = letra;
      }if (erros==3){
        erro3 = letra;
      }if (erros==4){
        erro4 = letra;
      }if (erros==5){
        erro5 = letra;
      }if (erros==6){
        erro6 = letra;
      }
    }

    if (strcmp(contraprova, palavra_secreta) == 0) { // string de comparação igual a 0 indica que é o mesmo
             printf("\nA palavra secreta é: ");

      for (int i = 0; i < strlen(contraprova); i++)
        printf("%c ", contraprova[i]);
      printf("\nVOCÊ VENCEU! PARABÉNS! :D");
      break;
    }

    if (erros == 6) { // verifica de perdeu
      forca(erros);
      break;
    }
  }

  return 0;
}
