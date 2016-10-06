#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <cstdlib>
#include <stdio.h>  
#include <math.h>  
#include <time.h>  
 
class Random {
private:
	double u;
	double U_Random() 
		{  
        	double f;  
       		f = (double)(rand() % 1000);  
        	/* printf("%fn",f); */  
        	return f/1000;  
    };
public:
	Random() {
		srand( (unsigned)time( NULL ) );  
	}
    int poisson(double x);
	  
};
   
int Random::poisson(double x) {
    int k = 0;
    double Lambda = x;
    long double p = 1.0;
    long double l = exp(-Lambda);
    // printf("%.15Lfn",l);  
    do {
        k = k + 1;
        u = U_Random();
        p = p * u;
    } while (p >= l);
    return k - 1;
}
#endif