Dhyaan Shah/Dhruvin Jhaveri


Compile and Run TicTacToe.c file

To play against the computer, press 1 (Computer always being O)\
To play the two player mode, press 2 (wherein player 1 has the choice to select either X or O and player 2 will get the other accordingly)\
Press 3 to exit

To place an X/O on the grid, enter the coordinates (space seperated)

| 1 | 2 | 3 |\
| 4 | 5 | 6 |\
| 7 | 8 | 9 |

Assuming player will only play in an empty space
Program will throw a warning if player tries to play in a filled space

Single player\
Player has an option to go either first or second against the computer

Computer Move priority:\
Computer will try to win if possible (Two O already alligned)\
If not possible then computer will try to block player from winning if possible (Two X already alligned)\
Otherwise, computer will play randomly in any empty space\
Note: Computer is not completely optimal, but it will try to win or block player from winning whenever possible

If there is no winner till all the spaces are filled on the grid, \
then the game is tied
