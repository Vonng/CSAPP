#include<stdio.h>

// gcc int.c -o int && ./int

/***********************************************************************
Exercise 2.23
*************************************************************************/

int func1(unsigned word){
    return (int)((word << 24)>>24);
}


int func2(unsigned word){
    return ((int) word << 24)>>24;
}

void exercise2_23(){
    printf("\n============================\nExercise2.23:\n");
    int w1 = 0x00000076,w2=0x87654321,w3=0x000000c9,w4=0xEDCBA987;
    printf("%x func1(w)=%x func2(w)=%x\n",w1,func1(w1),func2(w1) );
    printf("%x func1(w)=%x func2(w)=%x\n",w2,func1(w2),func2(w2) );
    printf("%x func1(w)=%x func2(w)=%x\n",w3,func1(w3),func2(w3) );
    printf("%x func1(w)=%x func2(w)=%x\n",w4,func1(w4),func2(w4) );
}

int main(){
    exercise2_23();
}