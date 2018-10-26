/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
� Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 9/6/2017
Author  : Sare Soltani & Farnaz Maleki
Company : 
Comments: 

Chip type               : ATmega8A
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*******************************************************/
#include <mega8.h>
#include <stdio.h>
#include <delay.h>

// Alphanumeric LCD functions
//#include <alcd.h>

// Declare your global variables here
unsigned int sensor1; 
unsigned int sensor2;
unsigned int sensor3;
unsigned int sensor4;
unsigned int sensor5;
unsigned int sensor6;

//char display_buffer[40]; //
unsigned int ocr1,ocr2; // 
// Voltage Reference: AREF pin
#define ADC_VREF_TYPE ((0<<REFS1) | (0<<REFS0) | (1<<ADLAR))
// Read the 8 most significant bits
// of the AD conversion result
unsigned char read_adc(unsigned char adc_input){
	ADMUX=adc_input | ADC_VREF_TYPE;
	// Delay needed for the stabilization of the ADC input voltage
	delay_us(10);
	// Start the AD conversion
	ADCSRA|=(1<<ADSC);
	// Wait for the AD conversion to complete
	while ((ADCSRA & (1<<ADIF))==0);
	ADCSRA|=(1<<ADIF);
	return ADCH;
}

void main(void){
	// Port B initialization
	// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
	DDRB=(0<<DDB7) | (0<<DDB6) | (0<<DDB5) | (0<<DDB4) | (0<<DDB3) | (1<<DDB2) | (1<<DDB1) | (0<<DDB0);
	// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
	PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);
	// Port C initialization
	// Function: Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
	DDRC=(0<<DDC6) | (0<<DDC5) | (0<<DDC4) | (0<<DDC3) | (0<<DDC2) | (0<<DDC1) | (0<<DDC0);
	// State: Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
	PORTC=(0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0);
	// Port D initialization
	// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
	DDRD=(0<<DDD7) | (0<<DDD6) | (0<<DDD5) | (0<<DDD4) | (0<<DDD3) | (0<<DDD2) | (0<<DDD1) | (0<<DDD0);
	// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
	PORTD=(0<<PORTD7) | (0<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | (0<<PORTD1) | (0<<PORTD0);
	// Timer/Counter 0 initialization
	// Clock source: System Clock
	// Clock value: Timer 0 Stopped
	TCCR0=(0<<CS02) | (0<<CS01) | (0<<CS00);
	TCNT0=0x00;
	// Timer/Counter 1 initialization
	// Clock source: System Clock
	// Clock value: 1000.000 kHz
	// Mode: Fast PWM top=ICR1
	// OC1A output: Inverted PWM
	// OC1B output: Inverted PWM
	// Noise Canceler: Off
	// Input Capture on Falling Edge
	// Timer Period: 20 ms
	// Output Pulse(s):
	// OC1A Period: 20 ms Width: 1 ms
	// OC1B Period: 20 ms Width: 1 ms
	// Timer1 Overflow Interrupt: Off
	// Input Capture Interrupt: Off
	// Compare A Match Interrupt: Off
	// Compare B Match Interrupt: Off
	TCCR1A=(1<<COM1A1) | (1<<COM1A0) | (1<<COM1B1) | (1<<COM1B0) | (1<<WGM11) | (0<<WGM10);
	TCCR1B=(0<<ICNC1) | (0<<ICES1) | (1<<WGM13) | (1<<WGM12) | (0<<CS12) | (1<<CS11) | (0<<CS10);
	TCNT1H=0x00;
	TCNT1L=0x00;
	ICR1H=0x4E;
	ICR1L=0x1F;
	//OCR1AH=0x4A;
	//OCR1AL=0x37;
	OCR1AH=0x48;
	OCR1AL=0x8A;
	OCR1BH=0x48;
	OCR1BL=0x8A;
	// Timer/Counter 2 initialization
	// Clock source: System Clock
	// Clock value: Timer2 Stopped
	// Mode: Normal top=0xFF
	// OC2 output: Disconnected
	ASSR=0<<AS2;
	TCCR2=(0<<PWM2) | (0<<COM21) | (0<<COM20) | (0<<CTC2) | (0<<CS22) | (0<<CS21) | (0<<CS20);
	TCNT2=0x00;
	OCR2=0x00;
	// Timer(s)/Counter(s) Interrupt(s) initialization
	TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (0<<TOIE0);
	// External Interrupt(s) initialization
	// INT0: Off
	// INT1: Off
	MCUCR=(0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
	// USART initialization
	// USART disabled
	UCSRB=(0<<RXCIE) | (0<<TXCIE) | (0<<UDRIE) | (0<<RXEN) | (0<<TXEN) | (0<<UCSZ2) | (0<<RXB8) | (0<<TXB8);
	// Analog Comparator initialization
	// Analog Comparator: Off
	// The Analog Comparator's positive input is
	// connected to the AIN0 pin
	// The Analog Comparator's negative input is
	// connected to the AIN1 pin
	ACSR=(1<<ACD) | (0<<ACBG) | (0<<ACO) | (0<<ACI) | (0<<ACIE) | (0<<ACIC) | (0<<ACIS1) | (0<<ACIS0);
	// ADC initialization
	// ADC Clock frequency: 125.000 kHz
	// ADC Voltage Reference: AREF pin
	// Only the 8 most significant bits of
	// the AD conversion result are used
	ADMUX=ADC_VREF_TYPE;
	ADCSRA=(1<<ADEN) | (0<<ADSC) | (0<<ADFR) | (0<<ADIF) | (0<<ADIE) | (1<<ADPS2) | (1<<ADPS1) | (0<<ADPS0);
	SFIOR=(0<<ACME);
	// SPI initialization
	// SPI disabled
	SPCR=(0<<SPIE) | (0<<SPE) | (0<<DORD) | (0<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);
	// TWI initialization
	// TWI disabled
	TWCR=(0<<TWEA) | (0<<TWSTA) | (0<<TWSTO) | (0<<TWEN) | (0<<TWIE);
	// Alphanumeric LCD initialization
	// Connections are specified in the
	// Project|Configure|C Compiler|Libraries|Alphanumeric LCD menu:
	// RS - PORTB Bit 0
	// RD - PORTD Bit 0
	// EN - PORTD Bit 1
	// D4 - PORTD Bit 2
	// D5 - PORTD Bit 3
	// D6 - PORTD Bit 4
	// D7 - PORTD Bit 5
	// Characters/line: 8
	//lcd_init(16); //
	ocr1 = OCR1AL + (OCR1AH<<8);
	ocr2 = OCR1BL + (OCR1BH<<8);

	while (1) {
	        sensor1 = read_adc(0);
	        sensor2 = read_adc(1);
	        sensor3 = read_adc(2);
	        sensor4 = read_adc(3);
	        sensor5 = read_adc(4);
	        sensor6 = read_adc(5);
	//        sprintf(display_buffer,"s1:%u,s2:%u\ns3:%u,ocr:%u  ",sensor1,sensor2,sensor3,ocr);
	//        lcd_clear();
	//        lcd_puts(display_buffer);
	         delay_ms(80);
	        if(sensor2 < sensor1) {
	            if( (ocr1 + 100)< 19465 )       
	                ocr1 += 100;
	            	OCR1AH = ocr1>>8;
	            	OCR1AL = ocr1&0xff;  
	        }
	        
	         else if(sensor2 < sensor3)  {	
	            if( (ocr1 - 100)> 17589)
	                ocr1 -= 100;
	            OCR1AH = ocr1>>8;
	            OCR1AL = ocr1&0xff;  
	        }
	     
	        if(sensor5 < sensor4)
	        {
	            if( (ocr2 + 100)< 19465 )       
	                ocr2 += 100;
	            OCR1BH = ocr2>>8;
	            OCR1BL = ocr2&0xff;  
	        }     
	         else if(sensor5 < sensor6)
	        {
	            if( (ocr2 - 100)> 17589)
	                ocr2 -= 100;
	            OCR1BH = ocr2>>8;
	            OCR1BL = ocr2&0xff;  
	        }
	        
	      }
	}
