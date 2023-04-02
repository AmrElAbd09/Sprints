
#include "Balanced.h"

/* Description:
 * - This function takes a reference to a stacks type
 * - Initialize this stack with Zeros
 * - Initialize the top with -1
 * Return:
 * - Nothing to return
 */
void createEmptyStack(ST_stack_t* stack){
    stack -> top = -1;
    for (int8_t i = 0; i < STACK_SIZE; i++)
    {
        stack->elements[i] = 0;
    }
}


/* Description:
 * - This function takes a reference to the stack and data to store
 * - Stores the data passed into the stack
 * Return:
 * - returns -1 if the stack is full
 * - returns 0 otherwise
 */
int8_t push(ST_stack_t* stack, uint8_t data){

    if (stack->top == (STACK_SIZE-1))
    {
        return -1;
    }
    stack->top++;
    stack->elements[stack->top] = data;
    return 0;
}

/* Description:
 * - This function takes a reference to the stack
 * - Stores the data popped from the stack in a data variable
 * Return:
 * - returns -2 if the stack is empty
 * - returns 0 otherwise
 */
int8_t pop(ST_stack_t* stack, uint8_t* data){
    if (stack->top == -1)
    {
        return -2;
    }
    *data = stack->elements[stack->top];
    stack->top--;
    return 0;

}

/* Description:
 * - This function takes a reference to the stack
 * - Prints all stack's data starting from the top
 * Return:
 * - returns -1 if the stack is full
 * - returns -2 if the stack is empty
 * - returns 0 otherwise
 */
int8_t printStack(ST_stack_t* stack)
{
    if (stack->top == (STACK_SIZE - 1))
    {
        return -1;
    }
    else if (stack->top == -1)
    {
        return -2;
    }
    else
    {
        for (int8_t i = stack->top; i >= 0; i--)
        {
            printf("%c ", stack->elements[i]);
        }
        printf("\n");
        return 0;
    }
}


/* Description:
 * - This function takes a reference to the stack
 * - Stores its top data into a variable
 * Return:
 * - returns -2 if the stack is empty
 * - 0 otherwise
 */
int8_t getStackTop(ST_stack_t* stack, uint8_t* topData)
{
    if (stack->top == -1)
    {
        return -2;
    }
    *topData = stack->elements[stack->top];
    return 0;
}

/* Description:
 * - This function takes a reference to the stack
 * - Checks if the stack is empty or not
 * Return:
 * - returns -2 if the stack is empty
 * - 0 otherwise
 */
int8_t isEmpty(ST_stack_t* stack)
{
    if (stack->top == -1)
    {
        return -2;
    }
    return 0;
}

/* Description:
 * - This function takes an expression array max 10 characters
 * - Checks if the parentheses are balanced or not
 * - Checks the following parentheses types {, }, (, ) only
 * Return:
 * - returns -2 if the neither of paranthethes is used
 * - returns -1 if the parentheses are not balanced
 * - returns 0 if the parentheses are balanced
 */
int8_t isBalancedParanthethes(uint8_t* expression)
{
    ST_stack_t MyStack;
    createEmptyStack(&MyStack);
    uint8_t temp = 0;

    for (int8_t i = 0; i < strlen(expression); i++)
    {

        getStackTop(&MyStack, &temp);

        if (expression[i] == '{' || expression[i] == '(')
        {
            push(&MyStack, expression[i]);
        }
        else if (expression[i] == ')' || expression[i] == '}')
        {
            if (MyStack.top == -1)
            {
                return -1;
            }
            pop(&MyStack, &temp);
            if ((expression[i] == '}' && temp != '{') || (expression[i] == ')' && temp != '('))
            {
                return -1;
            }

        }
    }
    if (MyStack.top != -1)
    {
        return -1;
    }

    else if (temp == '\0')
    {
        return -2;
    }

    return 0;

}

