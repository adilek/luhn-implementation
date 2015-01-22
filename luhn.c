#include <stdio.h>
#include <math.h>

//#define IMPLEMENTATION2

int getNumLength (long long);
int sumOfDigits(int);
int getCardType(int);

int main() {
    long long card_number_input = "enter number here";
    short l = getNumLength(card_number_input);
    short card_number[l];
    int checksum=0;
    for (int i=0;i<l;i++) {
        card_number[i]=card_number_input % 10;
        card_number_input = card_number_input /10;          
    }
    
#ifndef IMPLEMENTATION2
    for (int i=0;i<l;i++) {
        if (i%2==1) {
            //checksum+=sumOfDigits(card_number[i]*2);
            int doubling = card_number[i]*2;
            checksum+= (doubling > 9)? doubling -9 : doubling;
        }else{
            checksum+=card_number[i];
        }

    }
#else
    int inc = l%2;
 
    for (int i=0;i<l;i++) {
    int digit = card_number[i];
  
    int n = digit * (2 - (i + inc) %2);
    checksum+= (n > 9)? n - 9 : n;
    }
#endif
    
    if (checksum%10==0) printf("VALID\n");
    
                    
    return 0;
}

/*
int sumOfDigits (int number) {
    int sum = 0;
    while (number>0) {
        sum+=number%10;
        number /= 10;
    }   
    return sum;
}
*/

int getNumLength (long long number) {
    int l = 1;    
    l = floor(log10(number))+1;    
    return l;
}
