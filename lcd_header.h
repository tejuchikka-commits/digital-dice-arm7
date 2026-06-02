#include<LPC21xx.h>
#define LCD_D 0xFF
#define RS 1<<8
#define E 1<<9

void LCD_INIT(void);
void LCD_CMD(unsigned char);
void LCD_DATA(unsigned char);
void LCD_STRING(unsigned char *);
void LCD_INTEGER(int);
void delay_milliseconds(unsigned int );

void delay_milliseconds(unsigned int millisecond)
{
	T0PR=15000-1;
	T0TCR=0x01;
	while(T0TC<millisecond);
	T0TCR=0x03;
	T0TCR=0x00;	
	
}

void LCD_INIT(void)
{
	IODIR0=LCD_D|RS|E;//P0.0 to P0.9 as Output pins
	LCD_CMD(0x01);//To clear the display
	LCD_CMD(0x02);//Return cursor to home position
	LCD_CMD(0x38);//8bit interface mode with both lines
	LCD_CMD(0x0C);//Display ON,Cursor OFF
	LCD_CMD(0x80);//Select starting address of DDRAM
	
}

void LCD_CMD(unsigned char cmd)
{
	IOCLR0=LCD_D;//To clear the data pins
	IOSET0=cmd;//Assigning command to the data pins
	IOCLR0=RS;//Command register is selected
	IOSET0=E;//Latch the data to the LCD
	delay_milliseconds(2);//wait for 2 milliseconds because
	//LCD is in internal operation mode
	IOCLR0=E;//To re-latch the next byte
	
}

void LCD_DATA(unsigned char d)
{
	IOCLR0=LCD_D;//To clear the data pins
	IOSET0=d;//Assigning data to the data pins
	IOSET0=RS;//Data register is selected
	IOSET0=E;//Latch the data to the LCD
	delay_milliseconds(2);//wait for 2 milliseconds because
	//LCD is in internal operation mode
	IOCLR0=E;//To re-latch the next byte
	
}

void LCD_STRING(unsigned char *s)
{
	char pos=0;
	
	while(*s)
	{
	LCD_DATA(*s++);
		pos++;
		if(pos==16)
			LCD_CMD(0xC0);
	
}
}

void LCD_INTEGER(int n)
{
	unsigned char arr[5];
	signed char i=0;
	if(n==0)
	{
		LCD_DATA('0');
		
	}
	else
	{
		if(n<0)
		{
			LCD_DATA('-');
			n=-n;
		
		}
		while(n>0)
		{
			arr[i++]=n%10;
			n=n/10;
			
		}
		for(i=i-1;i>=0;i--)
	  LCD_DATA(arr[i]+48);
				
	}//else
		
}//integer