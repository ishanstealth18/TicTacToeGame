/*
Project: Tic Tac Toe game
Author: Ishan Kansara
Date: 1/7/2019
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void makeGrid();
void startGame();
int playerOneTurn();
int validateInputNum();
void showUpdatedGrid();
int checkPattern();
void endGame();

int grid [3][3];


void makeGrid()
{
    int temp = 0;
    int j = 0;
    for(int i = 0; i<3; i++)
    {
        for(j = 0; j<3; j++)
        {
            grid[i][j] = temp;
            printf("%2d |", grid[i][j]);
            ++temp;
        }
        printf("\n");
        printf("------------\n");
    }
}

void showUpdatedGrid()
{
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            printf("%2d |", grid[i][j]);
        }
        printf("\n");
        printf("------------\n");
    }
}

int checkPattern()
{
    int count = 0;
    int winFlag = 0;
    //Check horizontal row
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {

            if((grid[i][j] == 88))
            {
                count++;
            }
        }
        if(count == 3)
        {
            winFlag = 1;
            break;
        }
        else
        {
            count = 0;
        }
    }
    //check vertical rows
    int k = 0;
    count = 0;
    while(k<3)
    {
        for(int i = 0; i<3; i++)
        {
            if((grid[i][k] == 88))
            {
                count++;
            }
        }
        k++;
        if(count == 3)
        {
            winFlag = 1;
            break;
        }
        else
        {
            count = 0;
        }
    }

    //Check cross right
    count = 0;
    for(int i = 0; i<3; i++)
    {
        for(int j = i; j<3; j++)
        {
            if((grid[i][j] == 88))
            {
                count++;
            }
            break;
        }
        if(count == 3)
        {
            winFlag = 1;
            break;
        }
    }

    //check cross left
    count = 0;
    int x1 = 2;
    for(int i = 0; i<3; i++)
    {
        if((grid[i][x1] == 88))
        {
            count++;
        }
        x1--;
        if(count == 3)
        {
            winFlag = 1;
            break;
        }
    }
    count = 0;
    return winFlag;
}


int checkPattern2()
{
    int count2 = 0;
    int winFlag2 = 0;
    //Check horizontal row
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {

            if((grid[i][j] == 79))
            {
                count2++;
            }
        }
        if(count2 == 3)
        {
            winFlag2 = 1;
            break;
        }
        else
        {
            count2 = 0;
        }
    }
    //check vertical rows
    int k2 = 0;
    count2 = 0;
    while(k2<3)
    {
        for(int i = 0; i<3; i++)
        {
            if((grid[i][k2] == 79))
            {
                count2++;
            }
        }
        k2++;
        if(count2 == 3)
        {
            winFlag2 = 1;
            break;
        }
        else
        {
            count2 = 0;
        }
    }

    //Check cross right
    count2 = 0;
    for(int i = 0; i<3; i++)
    {
        for(int j = i; j<3; j++)
        {
            if((grid[i][j] == 79))
            {
                count2++;
            }
            break;
        }
        if(count2 == 3)
        {
            winFlag2 = 1;
            break;
        }
    }

    //check cross left
    count2 = 0;
    int x = 2;
    for(int i = 0; i<3; i++)
    {
        if((grid[i][x] == 79))
        {
            count2++;
        }
        x--;
        if(count2 == 3)
        {
            winFlag2 = 1;
            break;
        }
    }
    count2 = 0;
    return winFlag2;
}



void endGame(int playerNum)
{
    printf("****Player %d wins.****",playerNum);
}

int validateInputNum(int inputNumber,int playerNum)
{
    int checkResult = 0;
    int validateValue = 88;
    printf("Input for player %d: %d\n",playerNum,inputNumber);
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            if((inputNumber == grid[i][j]) && (grid[i][j] != 88))
            {
                printf("Validated successful.\n");
                grid[i][j] = 'X';
            }
        }
    }
    showUpdatedGrid();
    checkResult = checkPattern();
    return checkResult;
}

int validateInputNum2(int inputNumber2,int playerNum2)
{
    int checkResult2 = 0;
    int validateValue2 = 88;
    printf("Input for player %d: %d\n",playerNum2,inputNumber2);
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            if((inputNumber2 == grid[i][j]) && (grid[i][j] != 79))
            {
                printf("Validated successful.\n");
                grid[i][j] = 'O';
            }
        }
    }
    showUpdatedGrid();
    checkResult2 = checkPattern2();
    return checkResult2;
}



int playerOneTurn()
{
    int finalResult = 0;
    int playerNum = 1;
    int inputNum = 0;
    printf("\nPlayer 1: Enter Number: \n");
    scanf("%d", &inputNum);
    finalResult = validateInputNum(inputNum,playerNum);
    return finalResult;
}

int playerTwoTurn()
{
    int finalResult2 = 0;
    int playerNum2 = 2;
    int inputNum2 = 0;
    printf("\nPlayer 2: Enter Number: \n");
    scanf("%d", &inputNum2);
    finalResult2 = validateInputNum2(inputNum2,playerNum2);
    return finalResult2;
}

void startGame()
{
    int stopFlag1 = 0;
    int stopFlag2 = 0;
    int turn = 1;
    while(turn < 6)
    {
        printf("\nTurn number: %d", turn);
        stopFlag1 = playerOneTurn();
        if(stopFlag1 == 1)
        {
            endGame(1);
            break;
        }
        //Condition to exit in case of draw.
        if(turn == 5)
        {
            break;
        }
        stopFlag2 = playerTwoTurn();
        if(stopFlag2 == 1)
        {
            endGame(2);
            break;
        }
            turn++;
    }
    if((stopFlag1 != 1) && (stopFlag2 != 1))
    {
        printf("/n****Game draw.****/n");
    }
}

int main()
{
    //int totalTurn = 0;
    printf("==========Tic Tac Toe Game==========\n");
    printf("Player 1 : (88) Player 2 : (79)\n\n");
    makeGrid();
    printf("\n");
    startGame();

    return 0;
}
