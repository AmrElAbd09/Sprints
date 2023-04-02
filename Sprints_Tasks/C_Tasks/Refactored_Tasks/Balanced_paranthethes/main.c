#include "Balanced.h"


int main()
{
int8_t state = 0;
    uint8_t array[10] = "{(2+3)}";
    state=isBalancedParanthethes(array);
    switch (state)
    {
    case 0:
        printf("The expression %s is balanced\n",array);
        break;
    case -1:
        printf("The expression %s is not balanced\n",array);
        break;
    case -2:
        printf("The expression %s doesn't include paranthethes\n",array);
        break;
    }
    memcpy(array,"{((2+3)}",10);
    state=isBalancedParanthethes(array);
    switch (state)
    {
    case 0:
        printf("The expression %s is balanced\n",array);
        break;
    case -1:
        printf("The expression %s is not balanced\n",array);
        break;
    case -2:
        printf("The expression %s doesn't include paranthethes\n",array);
        break;
    }
    memcpy(array,"[(2+3)]",10);
    state=isBalancedParanthethes(array);
    switch (state)
    {
    case 0:
        printf("The expression %s is balanced\n",array);
        break;
    case -1:
        printf("The expression %s is not balanced\n",array);
        break;
    case -2:
        printf("The expression %s doesn't include paranthethes\n",array);
        break;
    }
    memcpy(array,"{(2+3)/((3+3)*(15-10))}",10);
    state=isBalancedParanthethes(array);
    switch (state)
    {
    case 0:
        printf("The expression %s is balanced\n",array);
        break;
    case -1:
        printf("The expression %s is not balanced\n",array);
        break;
    case -2:
        printf("The expression %s doesn't include paranthethes\n",array);
        break;
    }
    memcpy(array,"(2+3)/((3+3)*(15-10))",10);
    state=isBalancedParanthethes(array);
    switch (state)
    {
    case 0:
        printf("The expression %s is balanced\n",array);
        break;
    case -1:
        printf("The expression %s is not balanced\n",array);
        break;
    case -2:
        printf("The expression %s doesn't include paranthethes\n",array);
        break;
    }
    memcpy(array,"{{2+3)/((3+3)*(15-10)))",10);
    state=isBalancedParanthethes(array);
    switch (state)
    {
    case 0:
        printf("The expression %s is balanced\n",array);
        break;
    case -1:
        printf("The expression %s is not balanced\n",array);
        break;
    case -2:
        printf("The expression %s doesn't include paranthethes\n",array);
        break;
    }
    memcpy(array,"{(2+3(/((3+3)*(15-10))}",10);
    state=isBalancedParanthethes(array);
    switch (state)
    {
    case 0:
        printf("The expression %s is balanced\n",array);
        break;
    case -1:
        printf("The expression %s is not balanced\n",array);
        break;
    case -2:
        printf("The expression %s doesn't include paranthethes\n",array);
        break;
    }
    memcpy(array,"{(2+3)/((3+3(*)15-10))}",10);
    state=isBalancedParanthethes(array);
    switch (state)
    {
    case 0:
        printf("The expression %s is balanced\n",array);
        break;
    case -1:
        printf("The expression %s is not balanced\n",array);
        break;
    case -2:
        printf("The expression %s doesn't include paranthethes\n",array);
        break;
    }
    memcpy(array,"{(2+3)/(})2+3)/((3+3)*(15-10))}",10);
    state=isBalancedParanthethes(array);
    switch (state)
    {
    case 0:
        printf("The expression %s is balanced\n",array);
        break;
    case -1:
        printf("The expression %s is not balanced\n",array);
        break;
    case -2:
        printf("The expression %s doesn't include paranthethes\n",array);
        break;
    }
    memcpy(array,"[2+3]*5",10);
    state=isBalancedParanthethes(array);
    switch (state)
    {
    case 0:
        printf("The expression %s is balanced\n",array);
        break;
    case -1:
        printf("The expression %s is not balanced\n",array);
        break;
    case -2:
        printf("The expression %s doesn't include paranthethes\n",array);
        break;
    }
    return 0;
}
