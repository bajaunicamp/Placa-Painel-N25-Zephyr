// Esse programa de expemplo printa "Hello World!" no LOG no momento em que o led pisca

#include <zephyr/kernel.h>
#include "ST7920.h"
#include <bitmap.h>
#include "zephyr/logging/log.h"
#include "numbers.h"
#include <can.h>
#include <globals.h>

LOG_MODULE_REGISTER();

void draw_main();
void draw_main_devagar();
void draw_velocidade(uint8_t velocidade);


int main(){
  //Inicializações
  ST7920_Init();

  // Mostrar logo
  ST7920_GraphicMode(1);
  ST7920_DrawBitmap((const unsigned char*)jupiter_logo);
  ST7920_GraphicMode(0);
  k_msleep(1000);


  draw_main();


  while (true) {
    k_msleep(700);
    velocidade += 1;
    draw_main();
  }
}

int altura_bateria_old = 0;
void draw_main(){
  ST7920_GraphicMode(1);
  ST7920_DrawBitmap((const unsigned char*)interface);

  // Desenhar Bateria
  int altura_bateria = (bateria*57)/100;
  DrawFilledRectangle(2, 3+(57-altura_bateria), 12, altura_bateria);

  // Desenhar Combustível 
  int altura_combustivel = (combustivel*57)/100;
  DrawFilledRectangle(19, 3+(57-altura_combustivel), 12, altura_combustivel);

  // Desenhar rodas
  int altura_de = (pneu_de*6)/100;
  DrawFilledRectangle(101, 7+(6-altura_de), 1, altura_de);
  
  int altura_dd = (pneu_dd*6)/100;
  DrawFilledRectangle(121, 7+(6-altura_dd), 1, altura_dd);

  int altura_te = (pneu_te*6)/100;
  DrawFilledRectangle(101, 31+(6-altura_te), 1, altura_te);

  int altura_td = (pneu_td*6)/100;
  DrawFilledRectangle(121, 31+(6-altura_td), 1, altura_td);


  // Desenhar Sinal
  if (sinal>33) {
    DrawFilledRectangle(102, 50, 2, 8);
  }
  if (sinal>66) {
    DrawFilledRectangle(108, 46, 2, 12);
  }
  if (sinal>90) {
    DrawFilledRectangle(114, 42, 2, 16);
  }

  draw_velocidade(velocidade);
  ST7920_Update();

}

// Desenha a velocideade (Precisa dar Update!!)
void draw_velocidade(uint8_t velocidade){

  int unidade = velocidade%10;
  int dezena = (velocidade%100)/10;

  switch (unidade) {
    case 0:
      numero_0(65);
      break;
    case 1:
      numero_1(65);
      break;
    case 2:
      numero_2(65);
      break;
    case 3:
      numero_3(65);
      break;
    case 4:
      numero_4(65);
      break;
    case 5:
      numero_5(65);
      break;
    case 6:
      numero_6(65);
      break;
    case 7:
      numero_7(65);
      break;
    case 8:
      numero_8(65);
      break;
    case 9:
      numero_9(65);
      break;

    default:
      ST7920_Clear();
      break;
  }

  switch (dezena) {
    case 0:
      numero_0(35);
      break;
    case 1:
      numero_1(35);
      break;
    case 2:
      numero_2(35);
      break;
    case 3:
      numero_3(35);
      break;
    case 4:
      numero_4(35);
      break;
    case 5:
      numero_5(35);
      break;
    case 6:
      numero_6(35);
      break;
    case 7:
      numero_7(35);
      break;
    case 8:
      numero_8(35);
      break;
    case 9:
      numero_9(35);
      break;
    default:
      ST7920_Clear();
      break;
  }

}
