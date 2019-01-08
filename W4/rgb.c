#include <stdio.h>
#include <stdint.h>

typedef struct rgb_st
{
    uint16_t red:5;
    uint16_t green:6;
    uint16_t blue:5;
} rgb_t;

typedef struct test_register_st
{
    uint8_t bit0:1;
    uint8_t bit1:1;
    uint8_t bit2:1;
    uint8_t bit3:1;
    uint8_t bit4:1;
    uint8_t bit5:1;
    uint8_t bit6:1;
    uint8_t bit7:1;
} test_register_t;

typedef union Data {
   int i;
   char str[20];
} data_t;

typedef union temp {
    test_register_t bit_field;
    uint8_t value;
} temp_t;

// uint8_t test_register = 0b11011100;

void main(void)
{
    data_t data;
    data.str[0]='d' ;
    data.str[1]='r' ;
    data.str[2]='a' ;
    data.str[3]='f' ;
    data.str[4]='t' ;
    data.str[5]='\0';
    // int i;
    // test_register_t test_register={1,1,0,1,1,1,0,0};
    // printf("Size of struct: %d\n", sizeof(rgb_t));
    
    // for(i=0;i<8;i++)
    // {
        // printf("%d", test_register.bit7);
    // }
    // printf("Register number: %d\n", test_register);
    // test_register.bit7= 0;
    // printf("Register number: %d\n", test_register);
    printf("original union: %x %s\n", data.i, data.str);
    data.i = 5;
    printf("original union: %x %s\n", data.i, data.str);
    
    temp_t var;
    var.value = 0XAB;
    printf("Bit number 5 of value if: %d\n", var.bit_field.bit0);
    printf("Bit number 5 of value if: %d\n", var.bit_field.bit1);
    printf("Bit number 5 of value if: %d\n", var.bit_field.bit2);
    printf("Bit number 5 of value if: %d\n", var.bit_field.bit3);
    printf("Bit number 5 of value if: %d\n", var.bit_field.bit4);
    printf("Bit number 5 of value if: %d\n", var.bit_field.bit5);
    printf("Bit number 5 of value if: %d\n", var.bit_field.bit6);
    printf("Bit number 5 of value if: %d\n", var.bit_field.bit7);
    return;
}