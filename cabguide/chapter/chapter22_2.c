// Absolute Beginner's Guide to C, 3rd Edition Kindle
// sample program from Chapter22_2
// File chapter22_2.c

/* This program fills three arrays with a player's total points, rebounds, and assists 
 * It loop through the scoreing array and finds the game with the most points. 
 * Once it knows that infomation, it prints the totals from all three categories from that game */

#include <stdio.h>

int main(void)
{
  int gameScores[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
  int gameRebounds[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
  int gameAssists[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
  int bestGame = 0; // The comparison variable for best scoring game
  int gmMark = 0; // This will mark which game is the best scoring game
  int i;

  for (i = 0; i < 10; i++)
  {
    // if loop will compare each game to the current best total
    // if the current score is higher, it becomes the new best and the counter variable becomes the new flag gmMark
    if (gameScores[i] > bestGame)
    {
      bestGame = gameScores[i];
      gmMark = i;
    }
  }

  // Print out the details of the best scoring game
  // Because arrays starts at 0, add 1 to the game number
  printf("\n\nThe Player's best scoring game totals:\n");
  printf("The best game was game #%d\n",gmMark + 1);
  printf("Scored %d points\n",gameScores[gmMark]);
  printf("Grabbed %d rebounds\n",gameRebounds[gmMark]);
  printf("Dished %d assists\n",gameAssists[gmMark]);

  return 0;
}
