unsigned short int debounce = 500;
short time_1,previous =4;
int main (void)
{
    DDRB = 0xF0;     
    while (1) 
    {
      time_1 = millis();
      ((PINB & (1<<PB2)) && previous == 0x04 && time_1-millis() > debounce)? (PORTB |= (1<<PB4)): (PORTB &= ~(1<<PB4));
      previous = PORTB;
    }
    return 0;
}
