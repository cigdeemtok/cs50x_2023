#include <stdlib.h>
#include <stdio.h>

/* AMEX-- 15 digits, starts with 34 or 37
   MASTERCARD-- 16 digits, starts with 51,52,53,54,55
   VISA-- 13-and16-digits, starts with 4
   INVALID. -> these are outputs that should be printed.

*/
int noOfDigits(long long int n){
    int digits = 0;
    while(n!=0){
        n = n/10;
        digits +=1;
    }
    return digits;
}

int main(void)
{
    //prompt user
    long long int number;
    printf("Please enter your credit card number:");
    scanf("%lld",&number);
    //printf("Your credit card number: %lld\n",number);


    //number of digits
    int digits = noOfDigits(number);
    //printf("digits: %d\n",digits);

    //splitting digits
    int arr1[16];
    int fsum = 0;
    int amex = 0, mastercard = 0, visa = 0;
    for(int i=0 ; i<digits; i++){
        int tmp;
        tmp = number%10;
        number = number/10;
        arr1[i] = tmp;
        if(i%2==0){
            fsum = fsum + arr1[i];
        }
        switch(digits){
            case 15:
                if(arr1[digits-1]==3 && (arr1[digits-2]==4 || arr1[digits-2]==7)){
                    amex = 1;
                }
                break;
            case 16:
                if(arr1[digits-1]==4){
                    visa = 1;
                }else if(arr1[digits-1]==5 && (arr1[digits-2]==1||arr1[digits-2]==2||arr1[digits-2]==3||arr1[digits-2]==4||arr1[digits-2]==5)){
                    mastercard = 1;
                }
            case 13:
                if(arr1[digits-1]==4){
                    visa = 1;
                }
        }

    }
    //printf("fsum %d\n",fsum);
    //printf("last status of number:%lld",number);
    //check sum
    int arr2[8];
    int k = 0;
    for(int j=1; j<=digits; j+=2){
        arr2[k] = arr1[j]*2;
        k++;
    }

    int sum = 0;
    for(int a=0 ; a<digits/2;a++){
        if(arr2[a]>=10){
            int n;
            n = arr2[a]%10;
            arr2[a] = arr2[a]/10;
            sum = sum + n + arr2[a];
        }else{
            sum += arr2[a];
        }
    }
    int totalSum = fsum + sum;
    int isValid = 0;
    if(totalSum%10 == 0){
        isValid = 1;
    }
    //printf("sum= %d\n",sum);
    //printf("total sum :%d\n",fsum+sum);

    if(isValid){
        if(amex){
            printf("AMEX\n");
        }else if(mastercard){
            printf("MASTERCARD\n");
        }else if(visa){
            printf("VISA\n");
        }
    }else{
        printf("INVALID\n");
    }



}
