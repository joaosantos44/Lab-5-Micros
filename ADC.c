/*
 * ADC.c
 * Created: 22/04/2024 16:24:48
 *  Author: joaos
 */ 

#include "ADC.h"
#include <avr/io.h>
#include <stdint.h>

void ConfiADCPin(uint8_t VoltRef, uint8_t Just, uint8_t Pin){
	
		if(VoltRef == 0){
			ADMUX &= ~((1 << REFS0) | (1 << REFS1));
		}
		else if(VoltRef == 1){
			ADMUX |= (1 << REFS0);
			ADMUX &= ~(1 << REFS1);
		}
		else{
			ADMUX |= (1 << REFS0) | (1 << REFS1);
		}
		
		
		
		
		if(Just == 1){
			ADMUX |= (1 << ADLAR);
		}
		else{
			ADMUX &= ~(1 << ADLAR);
		}
		
		
		
		ADMUX = (ADMUX & 0xF0) | Pin;
}


void ConfiADC(uint8_t Abil, uint8_t AutoTrig, uint8_t Inter, uint8_t Prescaler){
	
	if(Abil == 1){
		ADCSRA |= (1 << ADEN);
	}
	else{
		ADCSRA &= ~(1 << ADEN);
	}
	
	
	
	if(AutoTrig == 1){
		ADCSRA |= (1 << ADATE);
	}
	else{
		ADCSRA &= ~(1 << ADATE);
	}
	
	if(Inter == 1){
		ADCSRA |= (1 << ADIE);
	}
	else {
		ADCSRA &= ~(1 << ADIE);
	}
	
	switch (Prescaler){
		case 2:
		ADCSRA &= ~((1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2));
		break;
		case 4:
		ADCSRA |= (1 << ADPS1);
		ADCSRA &= ~((1 << ADPS0) | (1 << ADPS2));
		break;
		case 8:
		ADCSRA |= (1 << ADPS0 ) | (1 << ADPS1);
		ADCSRA &= ~(1 << ADPS2);
		break;
		case 16:
		ADCSRA |= (1 << ADPS2);
		ADCSRA &= ~((1 << ADPS0) | (1 << ADPS1));
		break;
		case 32:
		ADCSRA |= (1 << ADPS0 ) | (1 << ADPS2);
		ADCSRA &= ~(1 << ADPS1);
		break;
		case 64:
		ADCSRA |= (1 << ADPS1) | (1 << ADPS2);
		ADCSRA &= ~(1 << ADPS0);
		break;
		case 128:
		ADCSRA |= (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2);
		break;
		default:
		ADCSRA &= ~((1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2));
	}
	
}
