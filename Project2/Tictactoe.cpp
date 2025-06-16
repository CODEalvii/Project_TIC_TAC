#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

char currentPlayer = 'X';
char board[3][3];

void initBoard() {
    int count = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = count++;
        }
    }
}

void drawBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c\t", board[i][j]);
            if (j < 2) printf("|\t");
        }
        if (i < 2) printf("\n-------------------------------------");
        printf("\n");
    }
}

int boardFull() {
int boardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return 0;
            }
        }
    }
    return 1;
}

int winningPlayer() {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer))
            return 1;
    }
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer))
        return 1;
    return 0;
}

int main() {
    char playAgain;
    do {
        currentPlayer = 'X';
        initBoard();
        int gameOver = 0;
        while (!gameOver) {
            system("cls");
            drawBoard();
            int Choice, Row, Column;
            printf("Player %c Turn\n", currentPlayer);
            printf("Please Enter Your Choice between 1 and 9: ");
            scanf_s("%d", &Choice);

            if (Choice < 1 || Choice > 9) {
                printf("Invalid choice! Try again.\n");
                getch();
                continue;
            }

            Row = (Choice - 1) / 3;
            Column = (Choice - 1) % 3;

            if (board[Row][Column] == 'X' || board[Row][Column] == 'O') {
                printf("Spot already taken! Try again.\n");
                getch();
                continue;
            }

            board[Row][Column] = currentPlayer;

            if (winningPlayer()) {
                system("cls");
                drawBoard();
                printf("The Current Player %c wins!\n", currentPlayer);
                gameOver = 1;
            }
            else if (boardFull()) {
                system("cls");
                drawBoard();
                printf("Game is Drawn\n");
                gameOver = 1;
            }
            else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }
        printf("Do you want to play again? (y/n): ");
        scanf_s(" %c", &playAgain, 1);
    } while (playAgain == 'y' || playAgain == 'Y');
    return 0;
}


