#include<cmath>
#include<stdio.h>
int main(){
	unsigned long long i=0;
	double q,w,e,r,t;
	for(q=0.0; q<=1.0;q+=0.0001){
		for(w=0.0; w<=1.0;w+=0.0001){
			for(e=0.0; e<=1.0;e+=0.0001){
				for(r=0.0; r<=1.0;r+=0.0001){
					for(t=0.0; t<=1.0;t+=0.0001){
						if((q+w+e+r+t) == 1.0){
							if( ((2*q)+(2*w)+(2*e)+(3*r)+(3*t)) == (round((0-( (q*log2(q)) + (w*log2(w)) + (e*log2(e)) + (r*log2(r)) + (t*log2(t))))*100))/100){
								printf("q1 = %f\nq2 = %f\nq3 = %f\nq4 = %f\nq5 = %f\n----------\n",q,w,e,r,t);
							}
//							if(q == 0.25 && w==0.25 && e==0.25 && r==0.125 && t==0.25) printf("%f - mde\n",(0-( (q*log2(q)) + (w*log2(w)) + (e*log2(e)) + (r*log2(r)) + (t*log2(t)))));
							i++;
						}
//						printf("%llu\n",i);
					}
				}
			}
		}
	}
	printf("%llu\n",i);
	return 0;
}
