#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define STACK_SIZE 10


typedef struct stack {
	uint8_t elements[STACK_SIZE];
	int8_t top;
}ST_stack_t;


void createEmptyStack(ST_stack_t* stack);
int8_t push(ST_stack_t* stack, uint8_t data);
int8_t pop(ST_stack_t* stack, uint8_t* data);
int8_t printStack(ST_stack_t* stack);
int8_t getStackTop(ST_stack_t* stack, uint8_t* topData)
int8_t isEmpty(ST_stack_t* stack);
int8_t isBalancedParanthethes(uint8_t* expression);
