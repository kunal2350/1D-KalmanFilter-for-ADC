#include <stdio.h>
 
int main () {

   /* local variable definition */
   int Xo;	//1st input measurements
   int r = 10000;	//measurement error square
   int Po = 400 ;	//estimate uncertainity square
   scanf("%d", &Xo);
   int Xn;	//Previous estimated value
   int Xn2; // New estimated value
   int z;	//new measured value
   float K;	// Kalman gain
   int Pn;	// new estimation error
   int Pn1; // previous estimation error
   int flag1, flag2, flag3 =0;
   int Xmean;	//mean of all the estimated values
   
   /* while loop execution */
   while(1) {
   		
   		if(flag1 == 0){
   			Pn = Po;
   			flag1 = 1;
		   }
		else{
			Pn = (1-K)*Pn1;
		}
		
   		K = (float)Pn/((float)(Pn+r));
   		
   		if(flag2 == 0){
   			Xn = Xo;
   			flag2 = 1;
		}
		else{
			Xn = Xn2;
		}
		scanf("%d", &z);
   		Xn2 = Xn + K*(z-Xn);
   		Pn1 = Pn;
   		if(flag3 == 0){
   			Xmean = Xn2;
   			flag3 = 1;
		}
		else{
			Xmean = ((float)(Xmean + Xn2))/2;
		}
      	//printf("New estimate: %d", Xn2);
      	printf("measured input: %d", z);
      	printf(" gain: %f", K);
      	//printf(" previous estimate: %d", Xn);
      	//printf(" new estimate error: %d", Pn);
      	//printf(" previous estimate error: %d", Pn1); 
      	printf(" Mean Value: %d \n", Xmean);
   }
 
   return 0;
}
