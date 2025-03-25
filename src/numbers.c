/*
 * numbers.c
 *
 *  Created on: Jan 23, 2020
 *      Author: osedro
 */


#include "numbers.h"
#include "ST7920.h"

void numero_1(int x)
{
	DrawFilledRectangle(x, 8, 3,42);
}
void numero_2(int x){
	DrawFilledRectangle(x, 8, 20,2);
	DrawFilledRectangle(x + 20, 8, 3,22);
	DrawFilledRectangle(x, 28, 20,2);
	DrawFilledRectangle(x, 28 ,3,20);
	DrawFilledRectangle(x, 48, 23,2);
}
void numero_3(int x){
	DrawFilledRectangle(x, 8, 20,2);
	DrawFilledRectangle(x + 20, 8, 3,42);
	DrawFilledRectangle(x, 48, 20,2);
	DrawFilledRectangle(x, 28, 20,2);

}
void numero_4(int x){
	  DrawFilledRectangle(x, 8 ,3,20);
	  DrawFilledRectangle(x + 20, 8, 3,42);
	  DrawFilledRectangle(x, 28, 20,2);
}
void numero_5(int x){
	DrawFilledRectangle(x, 8, 23,2);
	DrawFilledRectangle(x + 20, 28, 3,22);
	DrawFilledRectangle(x, 28, 20,2);
	DrawFilledRectangle(x, 10,3,20);
	DrawFilledRectangle(x, 48, 20,2);
}
void numero_6(int x){
	DrawFilledRectangle(x, 8, 23,2);
	DrawFilledRectangle(x, 10 ,3,40);
	DrawFilledRectangle(x, 28, 20,2);
	DrawFilledRectangle(x, 48, 20,2);
	DrawFilledRectangle(x + 20, 28, 3,22);
}
void numero_7(int x){
	DrawFilledRectangle(x, 8, 20,2);
	DrawFilledRectangle(x + 20, 8, 3,42);
}
void numero_8(int x)
{
	  DrawFilledRectangle(x, 10 ,3,40);
	  DrawFilledRectangle(x, 8, 20,2);
	  DrawFilledRectangle(x + 20, 8, 3,42);
	  DrawFilledRectangle(x, 28, 20,2);
	  DrawFilledRectangle(x, 48, 20,2);
}
void numero_9(int x){
	 DrawFilledRectangle(x, 10 ,3,20);
	 DrawFilledRectangle(x, 8, 20,2);
	 DrawFilledRectangle(x + 20, 8, 3,42);
	 DrawFilledRectangle(x, 28, 20,2);
	 DrawFilledRectangle(x, 48, 20,2);
}
void numero_0(int x){
	DrawFilledRectangle(x, 10, 3,40);
    DrawFilledRectangle(x, 8, 20,2);
    DrawFilledRectangle(x + 20, 8, 3,42);
    DrawFilledRectangle(x, 48, 20,2);

}
