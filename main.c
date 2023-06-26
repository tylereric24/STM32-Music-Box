#include "mbed.h"


#define SPEAKER D3
#define RED_LED D5
#define GREEN_LED D6
#define BLUE_LED D9
#define BUTTON1 D4
#define BUTTON2 D7






//Define note frequency
# define C     0.55
# define D     0.45
# define E     0.4
# define F     0.37
# define G     0.33
# define A     0.31
# define B     0.25
# define CA     0 


//Define beat length
# define b1     0.5
# define b2     0.25
# define b3     0.125
# define b4     0.075


//Create music
float note[] = {C,C,E,E,CA,C, C,E,E,CA,E,D, F,G,F,E,F,D,CA,F,CA,E, E,D,F,D,C,C,D,E, E,D,F,F,D,F,E,CA,B,CA, B,A,F,B,E, CA,CA,G,B};
float beat[] = {b3,b3,b3,b3,b1,b2, b2,b3,b3,b1,b2,b2, b3,b3,b3,b3,b3,b3,b3,b3,b2,b1, b4,b1,b4,b3,b2,b2,b4,b2, b2,b3,b2,b3,b1,b3,b2,b1,b1,b2, b3,b2,b1,b1,b3, b4,b3,b3,b3};




DigitalIn volume(BUTTON1);
DigitalIn speed(BUTTON2);


PwmOut Speaker(SPEAKER);




PwmOut RedLed(RED_LED);
PwmOut GreenLed(GREEN_LED);
PwmOut BlueLed(BLUE_LED);


DigitalIn test (D7);




Ticker timer; 


static int k;






void timer_ISR(){ 




        if (k<(sizeof(note)/sizeof(int))){


                if(note[k] == CA)                                       
                        Speaker = 0;                                          
                else {
                        Speaker.period(0.005*note[k]);                           
            if (volume) Speaker = 0.8;                          
            else Speaker = 0.2;
        }


                k++;
                        
                
                timer.attach(&timer_ISR, ((beat[k]/2)+0.5));
                        
                
            RedLed = note[k];
            GreenLed = beat[k];
            BlueLed = Speaker;
        }else{
                k = 0;                                                         
                Speaker = 0;
        }
} 




int main(){
        timer.attach(&timer_ISR, 0.1);                                            
    k=0;


    while(1){ 
                __WFI();
    }
        
}
