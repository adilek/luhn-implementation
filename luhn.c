#include <stdio.h>
#include <math.h>

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
    
    for (int i=0;i<l;i++) {
        if (i%2==1) {
            int doubling = card_number[i]*2;
            checksum+= (doubling > 9) ? doubling - 9 : doubling;
        }else{
            checksum+=card_number[i];
        }

    }
    
    if (checksum%10==0) printf("VALID\n");
    
                    
    return 0;
}

int getNumLength (long long number) {
    int l = 1;    
    l = floor(log10(number))+1;    
    return l;
}
