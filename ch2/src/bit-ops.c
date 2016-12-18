#include<stdio.h>

// gcc  bit-ops.c -o bit-ops && ./bit-ops


/***********************************************************************
Exercise 2.10
*************************************************************************/
void inplace_swap(int *x, int* y){
  *y = *x ^ *y;		// a, a^b
  *x = *x ^ *y;		// a^(a^b)=0^b=b, a^b
  *y = *x ^ *y;		// b,b^(a^b)=(b^b)^a=0^a=a
}



/***********************************************************************
Exercise 2.11
*************************************************************************/
void reverse_array(int a[], int cnt){
    int  first,last;
    for (first = 0, last = cnt-1; first <= last;first++,last--){
    inplace_swap(&a[first],&a[last]);
    }
}

void exercise2_11(){
    int i = 0;
    printf("========================\nExercise 2.11\nCase1:\n");

    // Case1
    const int len1 = 4;
    int case1[len1] = {1,2,3,4};
    reverse_array(case1,len1);
    for(;i<len1;i++) printf("%d ",case1[i]);

    printf(" \n----------\nCase2:\n");
    //Case2
    const int len2 = 5;
    int case2[len2] = {1,2,3,4,5};
    reverse_array(case2,len2);
    for(i=0;i<len2;i++) printf("%d ",case2[i]);
    printf(" \n");

}

void exercise2_12(){
    int x = 0x87654321;
    printf("============\nExercise 2.12 \n%.2x %.2x %.2x %.2x\n",x,x & 0xff, x^0xffffff00,x|0xff);
}

/***********************************************************************
Exercise 2.13
*************************************************************************/
int bis(int x, int m) {
    return x | m;
}


int bic(int x, int m){
    return x & ~m;
}


int bool_or(int x, int y){
    return bis(x,y);
}

int bool_xor(int x,int y){
    return bis(bic(x,y),bic(y,x));
}

void exercise2_13(){
    int x = 0x123456;
    int y = 0xff;

    printf("============================\nExercise2.13:\n");
    printf("%x %x %x", x, bis(x,y), bic(x,y));
    printf("%x %x %x", x, bool_or(x,y),bool_xor(x,y));
}

/***********************************************************************
Exercise 2.14
*************************************************************************/
void exercise2_14(){
    int x = 0x66,y = 0x39;
    printf("\n============================\nExercise2.14:\n");
    printf("%2x,%2x,%2x,%2x\n",x&y,x|y,~x|~y,x&!y);
    printf("%2x,%2x,%2x,%2x\n",x&&y,x||y,!x||!y,x&&~y);
}


/***********************************************************************
Exercise 2.15
*************************************************************************/
void exercise2_15(){
    int x = 0x66,y = 0x39;
    printf("\n============================\nExercise2.15:\n");
    printf("%d %d", !(x-y) ,!(x-x));
}

/***********************************************************************
Exercise 2.16
*************************************************************************/
void shift_test(unsigned char s){
    printf("x:%2x\tx<<3: %2x;\tx>>2: %2x;\tx>>2:%x;\n",
    s,(unsigned char)(s<<3),(unsigned char)(s>>2),(unsigned char )(((signed char)s)>>2));
}

void exercise2_16(){
    printf("\n============================\nExercise2.16:\n");
    shift_test(0xC3);
    shift_test(0x75);
    shift_test(0x87);
    shift_test(0x66);
}




int main(){
    exercise2_11();
    exercise2_12();
    exercise2_13();
    exercise2_14();
    exercise2_15();
    exercise2_16();
}