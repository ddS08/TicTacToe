#include<stdio.h>
#include<stdlib.h>

#include <stdbool.h>
#include <unistd.h>

#define clear "\e[1;1H\e[2J"
void grid_print(char(*)[4]);
void human(char(*)[4]);
void computer(char (*)[4]);
int checkbool(char (*)[4]);
int minimax(char (*)[4],int);

char board1[3][3];
char p1,p2;

void fordelay(int j)
{   int i,l;
    for(i=0;i<j;i++)
         l=i;
}






void computer(char (*grid)[4])
{
    int i,j,pt,bpt=-20,index_x,index_y;
    for (i=0;i<3;i++)
    {
        for (j=0;j<3;j++)
        {
            if (grid[i][j] == ' ')
            {
                grid[i][j]='O';
                pt=minimax(grid,0);
                grid[i][j]=' ';
                if(pt>bpt)
                {
                    bpt=pt;
                    index_x=i;
                    index_y=j;
                }
            }
        }
    }
    grid[index_x][index_y]='O';
}

int minimax(char (*grid)[4],int ismax)
{
    int score,i,j,pt;
    score = check(grid);
    if (score != 0)
    {
        return score;
    }
    if (ismax)      //maximizer
    {
        int bpt = -1;
        for (i=0;i<3;i++)
        {
            for (j=0;j<3;j++)
            {
                if (grid[i][j] == ' ')
                {
                    grid[i][j] = 'O';
                    pt = minimax(grid,0);
                    grid[i][j] = ' ';
                    if (pt>bpt)
                    {
                        bpt = pt;
                    }
                }
            }
        }
        return bpt;
    }
    else        //minimizer
    {
        int bpt = 1;
        for (i=0;i<3;i++)
        {
            for (j=0;j<3;j++)
            {
                if (grid[i][j] == ' ')
                {
                    grid[i][j] = 'X';
                    pt = minimax(grid,1);
                    grid[i][j] = ' ';
                    if (pt<bpt)
                    {
                        bpt = pt;
                    }
                }
            }
        }
        return bpt;
    }
}

void grid_print(char (*grid)[4])
{
    printf(clear);
    sleep(1);
    printf("  %c  |  %c  |  %c  \n",grid[0][0],grid[0][1],grid[0][2]);
    printf("-----------------\n");
    printf("  %c  |  %c  |  %c  \n",grid[1][0],grid[1][1],grid[1][2]);
    printf("-----------------\n");
    printf("  %c  |  %c  |  %c  \n",grid[2][0],grid[2][1],grid[2][2]);
}

void human(char (*grid)[4])
{
    int n,ch[10]={0,00,01,02,10,11,12,20,21,22},index,index_x,index_y;
    
    A:
    printf("\nCHOOSE YOUR BOX NUMBER ");
    scanf("%d",&n);
    
    index=ch[n];
    index_x=index/10;
    index_y=index%10;
    if (index_x>2 || index_y>2 || grid[index_x][index_y]!=' ')
    {
        printf("INVALID INPUT!\n");
        goto A;
    }
    grid[index_x][index_y]='X';
}

int checkbool(char (*grid)[4])
{
    int c=0;        //counter for checking if game is over or not
    for (int i=0;i<3;i++)
    {
        //HORIZONTAL
        if ( (grid[i][0] == grid[i][1]) && (grid[i][1] == grid[i][2]) && (grid[i][0] != ' ') )
        {
            if (grid[i][0] == 'X')
                return -1;
            else
                return 1;
        }
        //VERTICAL
        if ( (grid[0][i] == grid[1][i]) && (grid[1][i] == grid[2][i]) && (grid[0][i] != ' ') )
        {
            if (grid[0][i] == 'X')
                return -1;
            else
                return 1;
        }
    }

    //DIAGONAL
    if ( ((grid[0][0] == grid[1][1]) && (grid[1][1] == grid[2][2]) && (grid[0][0] != ' ')) || ((grid[0][2] == grid[1][1]) && (grid[1][1] ==grid[2][0]) && (grid[1][1] != ' ')) )
    {
        if (grid[1][1] == 'X')
            return -1;
        else
            return 1;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(grid[i][j] != ' ')
                c++;
        } 
    }
    if(c == 9)
        return 78;      //random number telling game is tied
    else
        return 0;       //number telling the game is still to be finished
}


void tttsingle()
{
    printf("\nSinglePlayer Mode\n");

  int board[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  printf("Board:\n");
  printf(" 1 | 2 | 3 \n---+---+---\n 4 | 5 | 6 \n---+---+---\n 7 | 8 | 9 \n");
  printf("Computer: O, You: X\n Would You Like To Go First Or Second:\n>");
  int player = 0;
  scanf("%d", &player);
    int i;
    char grid[4][4]={"   ","   ","   "},names[2][10]={"COMPUTER","HUMAN"};
    grid_print(grid);
  printf("\n");

  printf("\n");

  unsigned turn;
  for (turn = 0; turn < 9 && checkbool(grid)==0; ++turn) {
    if ((turn + player) % 2 == 0)
      computer(grid);
    else {
      grid_print(grid);
      human(grid);
    }
  }
  switch (checkbool(grid)) {
  case 0:
    printf("Good Try, It's A Draw\n");
    break;
  case 1:
    grid_print(grid);
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
