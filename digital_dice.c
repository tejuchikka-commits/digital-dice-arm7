#include <LPC21xx.h> 
#include "LCD_header.h" 
volatile int x; 
volatile int rolled = 0;
 void eint0_isr(void) __irq
 { 
EXTINT = 0x01; 
x = (T0PC%6)+1; 
LCD_CMD(0xC0); 
LCD_INTEGER(x);   
++rolled; 
LCD_CMD(0xC6); 
LCD_INTEGER(rolled); 
T0TCR=0x02; 
T0TCR=0x00; 
T0TCR=0x01; 
VICVectAddr = 0; 
} 
int main() 
{ 
int cnt = 0; 
T0PR =5;
 T0TCR = 0x01;
 LCD_INIT(); 
LCD_STRING("DICE"); 
LCD_CMD(0x86);
 LCD_STRING("ROLLED");
 LCD_CMD(0xC0); 
LCD_INTEGER(0);
 LCD_CMD(0xC6); 
LCD_INTEGER(0); 
PINSEL1 |= 0x00000001;
 VICIntSelect = 0x00000000; VICVectCntl0 = 0x20 | 14; 
VICVectAddr0 = (int)eint0_isr;
 EXTMODE = 0x01; 
EXTPOLAR = 0x00; delay_milliseconds(250);
 VICIntEnable = (1 << 14);
 while (1) { 
cnt++;
 } 
}