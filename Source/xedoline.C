#include<regx51.h>
#include<stdio.h>
// bien toan cuc
unsigned char check90 ;
unsigned char check90_L ;
unsigned char check90_R;
unsigned char check_half_L ;
unsigned char check_half_R ;
unsigned int i;
unsigned int state;
// Khai bao cac chan 
	 // khai bao button
sbit button_1 = P3^0;
sbit button_2 = P3^1;
	 // chan sensor cho cong P1
	 // hai chan tin hieu dieu khien Speed DC
sbit pwm_out_L = P2^4 ;
sbit pwm_out_R = P2^5 ;
	 // out test sensor
	 // 4 chan tin hieu dieu khien  DC
sbit motor_L_1 = P2^0;
sbit motor_L_2 = P2^1;
sbit motor_R_1 = P2^2;
sbit motor_R_2 = P2^3;
	 // dinh nghia trang thai cua xe ( 1 tren - 0 ngoai vach ) su dung 6 bit giua
#define L4 0x81	   //10000001
#define L3 0xC1	   //11000001
#define L2 0xE1	   //11100001
#define L5 0xA1	   //10100001
#define L1 0xB1	   //10110001
#define TT 0x99	   //10011001
#define TT1 0x91   //10010001
#define TT2 0x89   //10001001
#define R1 0x8D	   //10001101
#define R5 0x85	   //10000101
#define R2 0x87	   //10000111
#define R3 0x83	   //10000011
#define RE 0xFF	   //11111111
#define TL1 0xB9   //10111001
#define TL2 0xF9   //11111001
#define TL3 0xF1   //11110001
#define TL4 0xFD   //11111101
#define TR1 0x9F   //10011111
#define TR2 0x9D   //10011101
#define TR3 0x8F   //10001111
#define TR4 0xBF   //10111111 
  
	 // bien tang led 
unsigned char but ;
	 // bien % gia tri Speed
unsigned char pwm_duty  ;
	 // bien tang 
unsigned char count ;
	 // ham delay_ms 
void  delay_ms(unsigned int t ){
   unsigned int  x, y ;
   for ( x = 0; x< t; x++){
   		for ( y = 0 ; y < 123 ; y++);
   }	

}

	 // ham bam xung PWM cho DC Left
void pwm_cycle_L(pwm_duty)
{
unsigned char i ;
pwm_out_L = 1;
for ( i= 0; i<255; i++)
	{
 if(i == pwm_duty)	pwm_out_L = 0;
 
	}
}
 	// ham bam xung PWM cho DC right
void pwm_cycle_R(pwm_duty)
{
unsigned char i ;
pwm_out_R = 1;
for ( i= 0; i<255; i++)
	{
 if(i == pwm_duty)	pwm_out_R = 0;
 
	}
}
	 // Ham dieu khien dong co DC Left + Speed
void motor_L(unsigned char option,pwm_duty){
	if ( option == 1 ){		 // Di toi , motor quay thuan
  	 	motor_L_1 = 1;
   		motor_L_2 = 0;
   		pwm_cycle_L(pwm_duty);
   		}
	else if ( option == 0 ){		 // Di lui , motor quay nghich
  	 	motor_L_1 = 0;
   		motor_L_2 = 1;
   		pwm_cycle_L(pwm_duty);
   		}
		 
}
	 // Ham dieu khien dong co DC Right + Speed
void motor_R(unsigned char option,pwm_duty){
  if ( option == 1 ){		 // Di toi , motor quay thuan
  	 	motor_R_1 = 1;
   		motor_R_2 = 0;
   		pwm_cycle_R(pwm_duty);
   		}
	else if ( option == 0 ){		 // Di lui , motor quay nghich
  	 	motor_R_1 = 0;
   		motor_R_2 = 1;
   		pwm_cycle_R(pwm_duty);
   		}
}
	 //Ham Stop DC 
void stop_L(){
		pwm_out_L = 1;
	 	motor_L_1 = 0;
 		motor_L_2 = 0;
}
void stop_R(){
		pwm_out_R = 1;
 		motor_R_1 = 0;
		motor_R_2 = 0;
}

void Doline(unsigned char speed) {
	unsigned char temp1, temp2, input ;
	input = P1 ;
	if (speed == 1) {	           //////// Do line trang ////////////////
	switch (input) 
	{
	  case TT : // xe chay thang
	  {
	 	motor_L(1,200);
		motor_R(1,200);
		temp1 = 0;
		temp2 = 0;
		break;
	  }
	  case TT1 : // xe chay thang
	  {
	 	motor_L(1,200);
		motor_R(1,200);
		temp1 = 0;
		temp2 = 0;
		break;
	  }
	  case TT2 : // xe chay thang
	  {
	 	motor_L(1,200);
		motor_R(1,200);
		temp1 = 0;
		temp2 = 0;
		break;
	  }
	 case L1 : // xe chay lech sang trai nhieu muc 1
	 {

	 	motor_L(1,165);
		motor_R(1,220);
		temp1 = 0;
		temp2 = 0;
		break;
	 }
	 case L5 : // xe chay lech sang trai nhieu muc 2
	 {

	 	motor_L(1,125);
		motor_R(1,240);
		temp1 = 0;
		temp2 = 0;
		break;
	 }
	 case TL1 : // xe chay lech sang trai nhieu muc 1
	 {

	 	motor_L(1,165);
		motor_R(1,220);
		temp1 = 0;
		temp2 = 0;
		break;
	 }
	 case TL3 : // xe chay lech sang trai nhieu muc 1	 // cua sensor cu
	 {

	 	motor_L(1,165);
		motor_R(1,220);
		temp1 = 0;
		temp2 = 0;
		break;
	 }
	  case L2 : // xe chay lech sang trai nhieu muc 2
	 {

	 	motor_L(1,125);
		motor_R(1,240);
		temp1 = 0;
		temp2 = 0;
		break;
	 }
	 case L3 : // xe chay lech sang trai nhieu muc 3
	 {

	 	motor_L(1,100);
		motor_R(1,230);
		temp1 = 1;
		temp2 = 0;
		break;
	 }
	 
	 case R1 : // xe chay lech sang phai nhieu muc 1
	 {

	 	motor_L(1,220);
		motor_R(1,165);
		temp1 = 0;
		temp2 = 0;
		break;
	 }
	 case TR1 : // xe chay lech sang phai nhieu muc 1
	 {

	 	motor_L(1,220);
		motor_R(1,165);
		temp1 = 0;
		temp2 = 0;
		break;
	 }
	  case TR3 : // xe chay lech sang phai nhieu muc 1  // cua sensor cu
	 {

	 	motor_L(1,220);
		motor_R(1,165);
		temp1 = 0;
		temp2 = 0;
		break;
	 }
	  case R5 : // xe chay lech sang phai nhieu muc 1
	 {

	 	motor_L(1,240);
		motor_R(1,125);
		temp1 = 0;
		temp2 = 0;
		break;
	 }
	  case R2 : // xe chay lech sang phai nhieu muc 2
	 {

	 	motor_L(1,240);
		motor_R(1,125);
		temp1 = 0;
		temp2 = 0;
		break;
	 }
	 case R3 : // xe chay lech sang phai nhieu muc 3
	 {

	 	motor_L(1,230);
		motor_R(1,100);
		temp1 = 0;
		temp2 = 1;
		break;
	 }

	 default: 
	 	motor_L(1,200);
		motor_R(1,200);
		break;
	}
   }
  if ( speed == 0) 				       //////////////// Do line Den ///////////////////////
  {
  	 switch (input) 
	{
	  case 0xE7 : // xe chay thang
	  {
	 	motor_L(1,180);
		motor_R(1,180);
		temp1 = 0;
		temp2 = 0;
		break;
	  }
	  case 0xF7 : // xe chay thang
	  {
	 	motor_L(1,180);
		motor_R(1,180);
		temp1 = 0;
		temp2 = 0;
		break;
	  }
	  case 0xEF : // xe chay thang
	  {
	 	motor_L(1,180);
		motor_R(1,180);
		temp1 = 0;
		temp2 = 0;
		break;
	  }
	 case 0xCF : // xe chay lech sang trai nhieu muc 1
	 {

	 	motor_L(1,165);
		motor_R(1,200);
		temp1 = 0;
		temp2 = 0;
		break;
	 }
	  case 0xC7 : // xe chay lech sang trai nhieu muc 1
	 {

	 	motor_L(1,165);
		motor_R(1,200);
		temp1 = 0;
		temp2 = 0;
		break;
	 }
	 case 0xDF : // xe chay lech sang trai nhieu muc 1
	 {

	 	motor_L(1,165);
		motor_R(1,200);
		temp1 = 0;
		temp2 = 0;
		break;
	 }
	  case 0x9F : // xe chay lech sang trai nhieu muc 2
	 {

	 	motor_L(1,145);
		motor_R(1,220);
		temp1 = 0;
		temp2 = 0;
		break;
	 }
	 case 0x8F : // xe chay lech sang trai nhieu muc 2
	 {

	 	motor_L(1,145);
		motor_R(1,220);
		temp1 = 0;
		temp2 = 0;
		break;
	 }
	 case 0xBF : // xe chay lech sang trai nhieu muc 3
	 {

	 	motor_L(1,90);
		motor_R(1,240);
		temp1 = 1;
		temp2 = 0;
		break;
	 }
	 
	 case 0xF3 : // xe chay lech sang phai nhieu muc 1
	 {

	 	motor_L(1,200);
		motor_R(1,165);
		temp1 = 0;
		temp2 = 0;
		break;
	 }
	 case 0xE3 : // xe chay lech sang phai nhieu muc 1
	 {

	 	motor_L(1,200);
		motor_R(1,165);
		temp1 = 0;
		temp2 = 0;
		break;
	 }
	 case 0xFB : // xe chay lech sang phai nhieu muc 1
	 {

	 	motor_L(1,200);
		motor_R(1,165);
		temp1 = 0;
		temp2 = 0;
		break;
	 }
	 
	  case 0xF9 : // xe chay lech sang phai nhieu muc 2
	 {

	 	motor_L(1,220);
		motor_R(1,145);
		temp1 = 0;
		temp2 = 0;
		break;
	 }
	 case 0xF1 : // xe chay lech sang phai nhieu muc 2
	 {

	 	motor_L(1,220);
		motor_R(1,145);
		temp1 = 0;
		temp2 = 0;
		break;
	 }
	 case 0xFD : // xe chay lech sang phai nhieu muc 3
	 {

	 	motor_L(1,245);
		motor_R(1,90);
		temp1 = 0;
		temp2 = 1;
		break;
	 }
	 default :
	 {
		motor_L(1,180);
		motor_R(1,180);
		break;
	 }
	}
  }
}


void run()
{
  if ( P1 == 0x81 || P1 == 0xC3 )
	{
		
		 Doline(0);
		 check90 = 1;
		 check90_L = 0;
		 check90_R = 0;
	}
	else if (check90 ==1  )
		{  	  
			
			  if ( check90_L == 1 && P1 == 0xFF){
				motor_R(1,220);
				stop_L();
				
			  }
			  else if (	check90_R == 1 && P1 == 0xFF){
				stop_R();
				motor_L(1,220);
				
			  }
			  else {
			  switch (P1)
			  {
					case 0xF1://TR1:
						motor_R(1,220);
						stop_L();
						check90_L = 1;
						break;
					case 0xE1://TR3:
						motor_R(1,220);
						stop_L();
						check90_L = 1;
						break ;
					case 0xC1://TR4:
						motor_R(1,220);
						stop_L();
						check90_L = 1;
						break;
					case 0x8F://TL2:
						stop_R();
						motor_L(1,220);
						check90_R = 1;
						break;
					case 0x87://TL3:
						stop_R();
						motor_L(1,220);
						check90_R = 1;
						break ;
					case 0x83://TL4:
						stop_R();
						motor_L(1,220);
						check90_R = 1;
						break;
					default : 
						Doline(0);
			   }
			   }
     }
	else if (  P1 == TL2 || P1 == TL3 || P1 == TL4 )	  /////// chuyen lan ben trai 
	{
	   check_half_L = 1;
	   check90 = 0;
	  	Doline(0);
	}
	else if ( check_half_L == 1 && P1 ==0x81 )
	{
			motor_R(1,220);
			motor_L(1,115);
	
	}
	else if (  P1 == TR1 || P1 == TR3 || P1 == TR4 )	  //////// chuyen lan ben phai
	{
	   check_half_R = 1;
	   check90= 0;
	  	Doline(0);
	}
	else if ( check_half_R == 1 && P1 ==0x81 )
	{
			motor_L(1,220);
			motor_R(1,115);
	
	}
	else 
	{
		Doline(0);
	}


}

void led_sensor(){
 	P0 = P1 ;
	}
 void led_Decorate(){
   P0 = 0xFF;
   delay_ms(500);
   P0 = 0x00;
   delay_ms(500);
 }
 void led_Decorate_2(){		 ///// led trang tri ///////
   P0 = 0xAA;
   delay_ms(75);
   P0 = 0x55;
   delay_ms(75);
   P0 = 0x18;
   delay_ms(200);
   P0 = 0x24;
   delay_ms(200);
   P0 = 0x42;
   delay_ms(200);
   P0 = 0x81;
   delay_ms(200);
 }
	 // Ham chinh
void main()
{

P1 = 0x81;

while(1){
     
	 if ( button_1 == 0){
		delay_ms(20);
		if ( button_1 ==0 )
		{
	 			i= ~i ;
				while(button_1 == 0){};
	   	}
	  }
	  if ( i ){
		
		led_sensor();
	  	run();
	  }
	  else 
	  {
	   	 led_Decorate();
		 if ( button_2 == 0){
			delay_ms(20);
			if ( button_2 ==0 )
			{
	 			led_Decorate_2() ;
				while(button_2 == 0){};
	   		}
	 	 }
	  }
	 
}

}