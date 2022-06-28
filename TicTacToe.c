#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<time.h>

char board1[3][3];
char p1,p2;

void fordelay(int j)
{   int i,l;
    for(i=0;i<j;i++)
         l=i;
}

char gridChar(int i) {
  switch (i) {
  case -1:
    return 'X';
  case 0:
    return ' ';
  case 1:
    return 'O';
  }
}

void draw(int b[9]) {
  printf(" %c | %c | %c\n", gridChar(b[0]), gridChar(b[1]), gridChar(b[2]));
  printf("---+---+---\n");
  printf(" %c | %c | %c\n", gridChar(b[3]), gridChar(b[4]), gridChar(b[5]));
  printf("---+---+---\n");
  printf(" %c | %c | %c\n", gridChar(b[6]), gridChar(b[7]), gridChar(b[8]));
}

int win(const int board[9])
{
  unsigned wins[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6},
                         {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
  int i;

  for (i = 0; i < 8; ++i)
  {
    if (board[wins[i][0]] != 0 && board[wins[i][0]] == board[wins[i][1]] &&
        board[wins[i][0]] == board[wins[i][2]])
      return board[wins[i][2]];
  }
  return 0;
}

int minimax(int board[9], int player) {

  int winner = win(board);
  if (winner != 0)
    return winner * player;

  int move = -1;
  int score = -2;
  int i;
  for (i = 0; i < 9; ++i) {
    if (board[i] == 0) {
      board[i] = player;
      int thisScore = -minimax(board, player * -1);
      if (thisScore > score) {
        score = thisScore;
        move = i;
      }
      board[i] = 0;
    }
  }
  if (move == -1)
    return 0;
  return score;
}

void computerMove(int board[9]) {
  int move = -1;
  int score = -2;
  int i;
  for (i = 0; i < 9; ++i) {
    if (board[i] == 0) {
      board[i] = 1;
      int tempScore = -minimax(board, -1);
      board[i] = 0;
      if (tempScore > score) {
        score = tempScore;
        move = i;
      }
    }
  }

  board[move] = 1;
}
 int check6(char n) {
  int i, flag = 0;
      if (n!= 88 &&  n!= 79) {

        flag = 0;
      } else {
          printf("\nTry A Different Square\n");
        flag = 1;
      }

    return flag;
  }

void playerMove(int board[9]) {
  int move = 0;
 do {

    printf("\nInput (0-8): ");
    scanf("%d", &move);
    printf("\n");
    system("cls");
 }
  while (move >= 9 || move < 0 && board[move] == 0 || check6(gridChar(board[move]))==1);
  board[move] = -1;
}

void tttsingle()
{
    printf("\nSinglePlayer Mode\n");

  int board[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  printf("Board:\n");
  printf(" 0 | 1 | 2 \n---+---+---\n 3 | 4 | 5 \n---+---+---\n 6 | 7 | 8 \n");
  printf("Computer: O, You: X\n Would You Like To Go First Or Second:\n>");
  int player = 0;
  scanf("%d", &player);
  printf("\n");

  printf("\n");

  unsigned turn;
  for (turn = 0; turn < 9 && win(board) == 0; ++turn) {
    if ((turn + player) % 2 == 0)
      computerMove(board);
    else {
      draw(board);
      playerMove(board);
    }
  }
  switch (win(board)) {
  case 0:
    printf("Good Try, It's A Draw\n");
    break;
  case 1:
    draw(board);
    printf("You Can't Beat The Computer, You Lose.\n");
    break;
  case -1:
    printf("You Beat The Computer!\n");
    break;
  }
}


int check2()
{
    int i,j,flag=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(board1[i][j]!=88 && board1[i][j]!=79 )
            {
                flag=0;
                break;
            }
            else
            {
                flag=1;
            }
        }
    }
    return flag;
}

int space(int e,int d)
{
      if(board1[e][d]!=88 && board1[e][d]!=79)
      {
          return 1;
      }
      else
      {
          return 0;
      }
}

int player1()
{
  int e=check2();
  if(e==0)
  {
      char column;
      char row;
      abcgg:
      printf("\nPlayer 1:");
      printf("\nEnter Row(A,B,C) and Column(1,2,3):");
      scanf(" %c %c", &row, &column);
      if(row==65 || row==66 || row==67)
      {
            if(column=='1' || column=='2' || column=='3')
            {
                int rowind = row - 'A';
                int colind = column - '1';
                int d=space(rowind,colind);
                if (d==1)
                {
                    board1[rowind][colind] = p1;
                    system("cls");
                    tttboard();
                    int r=check();
                    if(r!=1)
                    {
                        player2();

                    }
                    else{}
                }
                else
                {
                    printf("\nSquare Occupied, Try Again:");
                    goto abcgg;
                }
            }
            else
            {
                printf("\nInvalid, Try Again:");
                goto abcgg;
            }
      }
      else
      {
            printf("\nInvalid, Try Again:");
            goto abcgg;
      }
  }
  else
  {
        printf("\nIt's A Draw");
  }
}


int player2()
{
  int e=check2();
  if(e==0)
  {
      char column;
      char row;
      abcgg:
      printf("\nPlayer 2:");
      printf("\nEnter Row(A,B,C) and Column(1,2,3):  ");
      scanf(" %c %c", &row, &column);
      int rowind = row - 'A';
      int colind = column - '1';
      int d=space(rowind,colind);
      if(row==65 || row==66 || row==67)
      {
          if(column=='1' || column=='2' || column=='3')
          {
            if (d==1)
            {
                board1[rowind][colind] = p2;
                system("cls");
                tttboard();
                int r=check();
                if(r!=1)
                {
                    player1();

                }
            }
            else
            {
                printf("\nSquare Occupied, Try Again:");
                goto abcgg;
            }
           }
           else
           {
                printf("\nInvalid, Try Again:");
                goto abcgg;
           }
      }
      else
      {
          printf("\nInvalid, Try Again:");
            goto abcgg;
      }
  }
  else
  {
        printf("\nIt's A Draw");
  }
}

  int check()
  {
     char ch;
     int i=0,j=0;
     int flag=0;
  for(i=0;i<3;i++)
  {

          if(board1[i][0]==board1[i][1] && board1[i][1]==board1[i][2])
      {
           if(board1[i][2]==88 || board1[i][2]==79)
           {
               flag=1;
             ch=board1[i][j];
             if(ch==p1)
             {
                 printf("\nPlayer 1 (%c) Wins!",ch);
                 return 1;
             }
             else
             {
                 printf("\nPlayer 2 (%c) Wins!",ch);
                 return 1;
             }
           }
      }
      }

  for(j=0;j<3;j++)
  {
        flag=1;

        if(board1[0][j]==board1[1][j] && board1[1][j]==board1[2][j] )
        {
            if(board1[2][j]==88 || board1[2][j]==79)
            {
                ch=board1[0][j];
                if(ch==p1)
                {
                    printf("Player 1 (%c) Wins!",ch);
                    return 1;
                }
                else
                {
                    printf("Player 2 (%c) Wins!",ch);
                    return 1;
                }
            }

        }

  }
  if(board1[0][0]==board1[1][1] && board1[1][1]==board1[2][2])
  {
     if(board1[0][0]==88 || board1[0][0]==79)
     {
        ch=board1[0][0];
        if(ch==p1)
        {
            printf("Player 1 (%c) Wins!",ch);
            return 1;
        }
        else
        {
            printf("Player 2 (%c) Wins!",ch);
            return 1;
        }
     }
  }
  else if(board1[0][2]==board1[1][1] && board1[1][1]==board1[2][0])
  {
    ch=board1[0][2];
    if(board1[2][0]==88 || board1[2][0]==79)
    {
        if(ch==p1)
        {
            printf("Player 1 (%c) Wins!",ch);
            return 1;
        }
        else
        {
            printf("Player 2 (%c) Wins!",ch);
            return 1;
        }
    }
  }
}

int tttboard()
{
    int i, j;
    printf(" | 1| 2| 3|\n");
    for (int i = 0; i < 3; i++)
    {

        printf("%c| ", 'A' + i);
        for (int j = 0; j < 3; j++)
        {
            if(board1[i][j]!='\0')
            {
               printf("%c| ", board1[i][j]);
            }
            else
            {
                printf(" | ");
            }

        }
        printf("\n");
    }
}

void tttmulti()
{

    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            board1[i][j]=0;
        }
    }
    printf("\nMultiplayer Tic Tac Toe\n");
    abcgg:
    printf("\nPlayer 1 choose X or O:");
    scanf("%c", &p1);
    system("cls");

    switch (p1)
    {
    case 'X':
        p2 = 'O';
        printf("board1\n");
        tttboard();
        player1();
        break;

    case 'O':
        p2 = 'X';
        printf("board1\n");
        tttboard();
        player1();
        break;
    default:
        goto abcgg;
    }
}


int main()
{
    int f,i;
    system("cls");
printf("ooooooooooooo  o8o                 ooooooooooooo                          ooooooooooooo                      \n");
printf("8'   888   `8  ` '                 8'   888   `8                          8'   888   `8                        \n");
printf("     888      oooo   .ooooo.            888       .oooo.    .ooooo.            888       .ooooo.   .ooooo.       \n");
printf("     888      `888  d88' ` Y8           888      `P  )88b  d88' ` Y8           888      d88' `88b d88' `88b      \n");
printf("     888       888  888                 888       .oP 888  888                 888      888   888 888ooo888      \n");
printf("     888       888  888   .o8           888      d8(  888  888   .o8           888      888   888 888    .o      \n");
printf("    o888o     o888o `Y8bod8P'          o888o     `Y888  8o `Y8bod8P'          o888o     `Y8bod8P' `Y8bod8P'      \n");
printf("                                                                                                                 \n");
printf("                                                                                                                 \n");
printf("                                                                                                                 \n");
printf("               ooooooo  ooooo      88   .oooooo.                                                                 \n");
printf("                `8888    d8'      .8'  d8P'  `Y8b                                                                \n");
printf("                  Y888..8P       .8'  888      888                                                               \n");
printf("                   `8888'       .8'   888      888                                                               \n");
printf("                  .8PY888.     .8'    888      888                                                               \n");
printf("                 d8'  `888b   .8'     `88b    d88'                                                               \n");
printf("               o888o  o88888o 88       `Y8bood8P'               \n");

    qwerty:
    printf("\n1||Singleplayer\n");
    printf("2||Multiplayer\n");
    printf("3||Exit\n>");
    scanf("%d",&f);
    switch(f)
    {
    case 1:
        {
            printf("\n\n\n\tLOADING\n");
        for(i=0;i<=20;i++)
        {
            fordelay(100000000);
            printf("%c",220);
        }
            system("cls");
            tttsingle();
            goto qwerty;
        }
    case 2:
        {
            printf("\n\n\n\tLOADING\n");
        for(i=0;i<=20;i++)
        {
            fordelay(100000000);
            printf("%c",220);
        }
            system("cls");
            tttmulti();
            goto qwerty;
        }
    }
}
