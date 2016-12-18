#include <stdio.h>
#include <string.h>
typedef unsigned char *byte_pointer;

// Run with gcc show-bytes.c -o show-bytes && ./show-bytes

/* Show bytes in hex format */
void show_bytes(byte_pointer start, int len) {
    int i;
    for (i = 0; i < len; i++){
        printf(" %.2x", start[i]);
    }
}

/* Show single byte in bit format */
void show_byte_in_bits(byte_pointer start) {
    int i;
    for (i = 0; i < 8 ; i++){
        printf("%d", (*start & ( 1 << (i ^ 7) ))>0);
    }
}

/* Show bytes in hex format (Turn little endian to big endian) */
void show_bytes_be(byte_pointer start, int len) {
    int i;
    for (i = len -1 ; i >= 0; i--){
        printf(" %.2x", start[i]);
    }
}

/* Show bytes in bit format */
void show_bits(byte_pointer start, int len) {
    int i;
    for (i = 0; i < len; i++){
        show_byte_in_bits(start+i);
        printf(" ");
    }
}

/* Show bytes in bit format (Turn little endian to big endian) */
void show_bits_be(byte_pointer start, int len) {
    int i;
    for (i = len -1 ; i >= 0; i--){
        show_byte_in_bits(start+i);
        printf(" ");
    }
}

/* Show bit sequence of arbitrary length */
void bits(byte_pointer start, int len) {
    int i;
    for (i = 0; i < len; i++){
        if (i % 8 == 0)
            printf(" ");
        printf("%d",( *( start + (i >> 3) ) & ( 1 << (  (i & 7) ^ 7 ) ) ) > 0 );
    }
}


void show_int(int x) {
    printf("Integer value [decimal:%d] [hex:0x%x]\n",x,x);
    printf("little endian:\t[");
    show_bytes((byte_pointer) &x, sizeof(int));
    printf(" ]\t[");
    show_bits((byte_pointer) &x, sizeof(int));
    printf("]\n");

    printf("big    endian:\t[");
    show_bytes_be((byte_pointer) &x, sizeof(int));
    printf(" ]\t[");
    show_bits_be((byte_pointer) &x, sizeof(int));
    printf("]");
}


void show_float(float x) {
    printf("Float value [decimal:%f]\n",x);
    printf("little endian:\t[");
    show_bytes((byte_pointer) &x, sizeof(float));
    printf(" ]\t[");
    show_bits((byte_pointer) &x, sizeof(float));
    printf("]\n");

    printf("big    endian:\t[");
    show_bytes_be((byte_pointer) &x, sizeof(float));
    printf(" ]\t[");
    show_bits_be((byte_pointer) &x, sizeof(float));
    printf("]");
}


void show_pointer(void *x){
    printf("Pointer value [decimal:%d] [hex: %x]\n",(int)(x), (int)(x));
    printf("little endian:\t[");
    show_bytes((byte_pointer) &x, sizeof(void *));
    printf(" ]\t[");
    show_bits((byte_pointer) &x, sizeof(void *));
    printf("]\n");

    printf("big    endian:\t[");
    show_bytes_be((byte_pointer) &x, sizeof(void *));
    printf(" ]\t[");
    show_bits_be((byte_pointer) &x, sizeof(void *));
    printf("]");
}

void test_show_bytes(int val){
    int ival = val;
    float fval = (float) ival;
    int *pval = &ival;

    show_int(ival);
    printf("\n");

    show_float(fval);
    printf("\n");

    show_pointer(pval);
    printf("\n");
}



void exercise2_5(){
    int val = 0x87654321;
    byte_pointer valp = (byte_pointer) &val;

    printf("\n==============================================\n");
    printf("Exercise 2.5: Show bytes [0~3] of hex %x. in small endian\n",val);

    show_int(val);
    printf("\n");
}

void exercise2_6(){
    int x = 3510593;
    float f = (float) x;
    printf("\n==============================================\n");
    printf("Exercise 2.6: Show representation of integer %d and float %f\n", x, f);

    show_int(x);
    printf("\n");

    show_float(f);
    printf("\n");
    printf("Hint: float.bits[9:] = int.bits[1:]\n");
}


void exercise2_7(){
    const char *s = "abcdef";
    printf("\n==============================================\n");
    printf("Exercise 2.7: show bytes on string: %s \n\t`show_bytes((byte_pointer)s,strlen(s));`\n",s);
    show_bytes((byte_pointer)s,strlen(s));
    printf("\nNow with strlen(s)+1:\n");
    show_bytes((byte_pointer)s,strlen(s)+1);
    printf("\n");
}

int main(int argc, char *argv[]) {
    //gcc show-bytes.c -o show-bytes && ./show-bytes
    int val;
    if (argc > 1) {
      if (argv[1][0] == '0' && argv[1][1] == 'x'){
        sscanf(argv[1]+2, "%x", &val);
      } else {
        sscanf(argv[1], "%d", &val);
      }

      printf("Reinterpret integer %d to int, float, pointer\n", val);
      test_show_bytes(val);
    } else {
      exercise2_5();
      exercise2_6();
      exercise2_7();
    }
    return 0;
}
