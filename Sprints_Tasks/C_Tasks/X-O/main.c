#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


typedef unsigned char uint8_t;
uint8_t position;
uint8_t configArray[2];
uint8_t board[10] = { '0', '1','2','3','4','5','6','7','8','9' };
int gameState = 2;
int playerno = 1;


void drawBoard(uint8_t* board)
{
    printf("\n -------------\n");
    printf(" | %c | %c | %c | ", board[1], board[2], board[3]);
    printf("\n -------------\n");
    printf(" | %c | %c | %c | ", board[4], board[5], board[6]);
    printf("\n -------------\n");
    printf(" | %c | %c | %c | ", board[7], board[8], board[9]);
    printf("\n -------------\n");
}

void updateBoard(uint8_t* board, uint8_t position, uint8_t value)
{
    board[position] = value;
    drawBoard(board);
}

uint8_t getPlayerSymbol(uint8_t playerNumber, uint8_t* symbol)
{

    uint8_t input;
    printf("Player %d Please choose your symbol (X) or (O)\n", playerNumber + 1);
    scanf(" %c", &input);
    fflush(stdin);

    if (input != 'X' && input != 'O' && input != 'x' && input != 'o')
    {
        printf("Wrong input! choose again\n");
        return 1;
    }
    for (uint8_t i = 0; i < 2; i++)
    {
        if (i != playerNumber && input == configArray[i])
        {
            printf("Duplicated symbol! choose another.\n");
            return 1;
        }
    }
    *symbol = input;
    return 0;
}

void setPlayerConfig(uint8_t* configArray)
{
    for (uint8_t i = 0; i < 2; i++)
    {
        uint8_t symbol;

        while (getPlayerSymbol(i, &symbol))
        {
        }
        configArray[i] = symbol;
    }
}

void loadAndUpdate(uint8_t playerNumber)
{
    uint8_t value = configArray[playerNumber - 1];
    printf("\n");
    printf("Player %d please choose the desired position\n", playerNumber);
    scanf(" %c", &position);
    fflush(stdin);
    while (1)
    {
        int num = position - '0';
        if (board[num] == 'X' || board[num] == 'O' || board[num] == 'x' || board[num] == 'o')
        {
            printf("Reserved position! choose another.\n");
            scanf(" %c", &position);
        }
        else
        {
            updateBoard(board, num, value);
            break;
        }

    }
}

void getGameState(uint8_t* board, uint8_t* gameState)
{
    if (board[1] == board[2] && board[2] == board[3])
    {
        printf("Winner is player %d\n", playerno);
        *gameState = 0;
    }
    else if (board[4] == board[5] && board[5] == board[6])
    {
        printf("Winner is player %d\n", playerno);
        *gameState = 0;
    }
    else if (board[7] == board[8] && board[8] == board[9])
    {
        printf("Winner is player %d\n", playerno);
        *gameState = 0;
    }
    else if (board[1] == board[4] && board[4] == board[7])
    {
        printf("Winner is player %d\n", playerno);
        *gameState = 0;
    }
    else if (board[2] == board[5] && board[5] == board[8])
    {
        printf("Winner is player %d\n", playerno);
        *gameState = 0;
    }
    else if (board[3] == board[6] && board[6] == board[9])
    {
        printf("Winner is player %d\n", playerno);
        *gameState = 0;
    }
    else if (board[1] == board[5] && board[5] == board[9])
    {
        printf("Winner is player %d\n", playerno);
        *gameState = 0;
    }
    else if (board[3] == board[5] && board[5] == board[7])
    {
        printf("Winner is player %d\n", playerno);
        *gameState = 0;
    }
    else if (board[1] != '1' && board[2] != '2' && board[3] != '3'
          && board[4] != '4' && board[5] != '5' && board[6] != '6'
          && board[7] != '7' && board[8] != '8' && board[9] != '9')
    {
        printf("Game ends in DRAW!\n");
        *gameState = 1;

    }


    else
    {
        *gameState = 2;
    }
}


int main()
{

    setPlayerConfig(configArray);
    drawBoard(board);
    while (1)
    {
        if (gameState == 2)
        {
            loadAndUpdate(playerno);
            getGameState(board, &gameState);
            if (playerno == 1)
            {
                playerno = 2;
            }
            else
            {
                playerno = 1;
            }
        }
        else if (gameState == 0)
        {
            break;
        }
        else if (gameState == 1)
        {
            break;
        }

    }


    return 0;
}
