// Absolute Beginner's Guide to C, 3rd Edition Kindle
// Sample Poker Program from Appendix B
// File drawPokerGame.c

/* This program plays draw poker. Users can play as often as they want, betting between 1 and 5.
 * They are dealt 5 cards and then get to choose which cards to keep, and wihch cards to change.
 * The new hand is then reviewed and the user's payout is set based on the value of the hand.
 * The use's new bankroll is displayed as they are given the option to continue. */

// Header files
#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>

// Two constants defined for determining whether hands are flushes or straights
#define FALSE 0
#define TRUE 1

// Function prototyping
void printGreeting();
int getBet();
char getRank(int rank);
char getSuit(int suit);
void getFirstHand(int cardRank[], int cardSuit[]);
void getFinalHand(int cardRank[], int cardSuit[], int finalRank[], int finalSuit[], int ranksInHand[], int suitsInHand[]);
int analyzeHand(int ranksInHand[], int suitsInHand[]);

int main()
{
  int bet;
  int bank = 100;
  int i;
  int cardRank[5]; // Will be one of 13 values (Ace-King)
  int cardSuit[5]; // Will be one of 4 values (Clubs, Diamonds, Hearts, Spades)
  int finalRank[5];
  int finalSuit[5];
  int ranksInHand[13]; // Used for evaluating the final hand
  int suitsInHand[4]; // Used for evaluating the final hand
  int winnings;
  time_t t;
  char suit, rank, stillPlay;

  // This function is called outside the do...while loop because the greeting only needs to be displayed onece,
  // while everything else in main will urn multiple time, depending on hwo many times the user wants to play.
  printGreeting();

  // Loop runs each time the user plays a hand of draw poker
  do
  {
      bet = getBet();
      srand(time(&t));
      getFirstHand(cardRank, cardSuit);
      printf("Your five cards: \n");
      for (i = 0; i < 5; i++)
      {
        suit = getSuit(cardSuit[i]);
        rank = getRank(cardRank[i]);
        printf("Card #%d: %c%c\n", i + 1, rank, suit);
      }

      // These two arrays are used to figure out the value of the player's hand. 
      // However, they must be zeroed out(initialized 0) in case the user plays multiple hands.
      for (i = 0; i < 4; i++)
      {
        suitsInHand[i] = 0;
      }

      for (i = 0; i < 13; i++)
      {
        ranksInHand[i] = 0;
      }

      getFinalHand(cardRank, cardSuit, finalRank, finalSuit, ranksInHand, suitsInHand);

      printf("Your five final cards: \n");
      for (i = 0; i < 5; i++)
      {
        suit = getSuit(finalSuit[i]);
        rank = getRank(finalRank[i]);
        printf("Card #%d: %c%c\n", i + 1, rank, suit);
      }

      winnings = analyzeHand(ranksInHand, suitsInHand);
      printf("You won %d!\n", bet * winnings);
      bank = bank - bet + (bet * winnings);

      printf("\nYour bank is now %d.\n", bank);
      printf("\nDo you want to play again? ");
      scanf(" %c", &stillPlay);

  } while (toupper(stillPlay) == 'Y');

  return 0;
}
/**********************************************************************************************************************************************************/

/* From here, other 7 functions are followed */


// 1. Print a quick greeting as well as tell the users the value of different winning hands

void printGreeting()
{
  printf("***************************************************************************************************************************************\n");
  printf("\n\n\nWelcome to the Draw Poker Game!\n\n");
  printf("***************************************************************************************************************************************\n");
  printf("Here are the rule:\n");
  printf("You start with 100 credit, and you make a bet from 1 to 5 credits.\n");
  printf("You are dealt 5 cards, and you then choose which cards to keep or discard.\n");
  printf("You want to make the best possible hand.\n");
  printf("\nHere is the table for winnings (assuming a bet of 1 credit):");
  printf("\nPair\t\t\t\t1 credit");
  printf("\nTwo pairs\t\t\t2 credits");
  printf("\nThree of a kind\t\t\t3 credits");
  printf("\nStraight\t\t\t4 credits");
  printf("\nFlush\t\t\t\t5 credits");
  printf("\nFull House\t\t\t8 credits");
  printf("\nFour of a kind\t\t\t10 credits");
  printf("\nStraight Flush\t\t\t20 credits");
  printf("\n\nHave fun!!!\n\n");
}


// 2. Function to deal the first five cards

void getFirstHand(int cardRank[], int cardSuit[])
{
  int i, j;
  int cardDup;

  for (i = 0; i < 5; i++)
  {
    cardDup = 0;
    do
    {
      // Card rank is one of 13 (2-10, J, Q, K, A)
      cardRank[i] = (rand() % 13);
      // Card suit is one of 4 (club, diamond, heart, spade)
      cardSuit[i] = (rand() % 4);

      // Loop that ensures each card is unique
      for (j = 0; j < i; j++)
      {
        if ((cardRank[i] == cardRank[j]) && (cardSuit[i] == cardSuit[j]))
        {
          cardDup = 1;
        }
      }
    } while (cardDup == 1);
  }
}


// 3. Function that changes the rank integer value to a character representing the rank

char getRank(int rank)
{
  switch (rank)
  {
    case 0:
      return ('A');
    case 1:
      return ('2');
    case 2:
      return ('3');
    case 3:
      return ('4');
    case 4:
      return ('5');
    case 5:
      return ('6');
    case 6:
      return ('7');
    case 7:
      return ('8');
    case 8:
      return ('9');
    case 9:
      return ('T');
    case 10:
      return ('J');
    case 11:
      return ('Q');
    case 12:
      return ('K');
  }
}


// 4. Function that changes the suit integer value to a character representing the suit

char getSuit(int suit)
{
  switch (suit)
  {
    case 0:
      return ('c');
    case 1:
      return ('d');
    case 2:
      return ('h');
    case 3:
      return ('s');
  }
}


// 5. Function to get user's bet between 1 and 5

int getBet()
{
  int bet;

  // Will keep running until the user enters 0-5
  do
  {
    printf("How much do you want to bet? (Enter a number 1 to 5, or 0 to quit the game): ");
    scanf(" %d", &bet);
    if (bet >= 1 && bet <= 5 )
    {
      return (bet);
    }
    else if (bet == 0)
    {
      exit(1);
    }
    else
    {
      printf("\n\nPlease enter a bet from 1-5 or 0 to quit the game.\n");
    }
  } while ((bet < 0) || (bet > 5));
}


// 6. Function reviews the final hand and determins value of the hand

int analyzeHand(int ranksInHand[], int suitsInHand[])
{
  int num_consec = 0;
  int i, rank, suit;
  int straight = FALSE;
  int flush = FALSE;
  int four = FALSE;
  int three = FALSE;
  int pairs = 0;

  /* suitsInHand is 4 counters that represents how many hearts, clubs, diamonds, spades are in the hand.
   * These 4 counters must add up to 5. For example if you have 5 hearts in the hand of cards, the array would have the values 5,0,0,0
   * ranksInHand is 13 counters, that represent how many two’s, three’s, etc. you have in the hand.
   * This must also total 5. For example, if you have a pair of 3’s, and three Kings’s,
   * this array would have the values A,2,3,4,5,6,7,8,9,T,J,Q,K 
   *                                  0,0,2,0,0,0,0,0,0,0,0,0,3 */
  for (suit = 0; suit < 4; suit++)
  {
    if (suitsInHand[suit] == 5)
    {
      flush = TRUE;
    }
  }

  /* Controling the flags */

  // Searching the lowest rank card. And if it is found, then it starts to control the straight flag.
  rank = 0;
  while (ranksInHand[rank] == 0)
  {
    rank++;
  }

  /* Controling the straight flag.
   *
   *  A,2,3,4,5,6,7,8,9,T,J,Q,K                     
   *  0,0,1,1,1,1,0,0,0,1,0,0,0
   *
   *  In this case, num_consec is 4. */
  for (; (rank < 13) && ranksInHand[rank]; rank++)
  {
    num_consec++;
  }
  if (num_consec == 5)
  {
    straight = TRUE;
  }

  for (rank = 0; rank < 13; rank++)
  {
    if (ranksInHand[rank] == 4)
    {
      four = TRUE;
    }
    if (ranksInHand[rank] == 3)
    {
      three = TRUE;
    }
    if (ranksInHand[rank] == 2)
    {
      pairs++;
    }
  }

  // Judging the value of hand based on the flags.
  if (straight && flush)
  {
    printf("Straight flush\n\n");
    return (20);
  }
  else if (four)
  {
    printf("Four of a kind\n\n");
    return (10);
  }
  else if (three && pairs == 1)
  {
    printf("Full house\n\n");
    return (8);
  }
  else if (flush)
  {
    printf("Flush\n\n");
    return (5);
  }
  else if (straight)
  {
    printf("Straight\n\n");
    return (4);
  }
  else if (three)
  {
    printf("Three of a kind\n\n");
    return (3);
  }
  else if (pairs == 2)
  {
    printf("Two pairs\n\n");
    return (2);
  }
  else if (pairs == 1)
  {
    printf("Pair\n\n");
    return (1);
  }
  else
  {
    printf("High Card\n\n");
    return (0);
  }
}


// 7. This function looks through each of the five cards in the first hand and asks the user if they want to keep the card.
//    If they say no, they get a replacement card.

void getFinalHand(int cardRank[], int cardSuit[], int finalRank[], int finalSuit[], int ranksInHand[], int suitsInHand[])
{
  int i, j, cardDup;
  char suit, rank, ans;

  for (i = 0; i < 5; i++)
  {
    suit = getSuit(cardSuit[i]);
    rank = getRank(cardRank[i]);
    printf("Do you want to keep card #%d: %c%c?", i + 1, rank, suit);
    printf("\nPlease answer (Y/N): ");
    scanf(" %c", &ans);

    if (toupper(ans) == 'Y')
    {
      finalRank[i] = cardRank[i];
      finalSuit[i] = cardSuit[i];
      ranksInHand[finalRank[i]]++;
      suitsInHand[finalSuit[i]]++;
      continue;
    }
    else if (toupper(ans) == 'N')
    {
      cardDup = 0;
      do 
      {
        cardDup = 0;
        finalRank[i] = (rand() % 13);
        finalSuit[i] = (rand() % 4);

        // First check your new card against the 5 original cards to avoid duplication
        for (j = 0; j < 5; j++)
        {
          if ((finalRank[i] == cardRank[j]) && (finalSuit[i] == cardSuit[j]))
          {
            cardDup = 1;
          }
        }

        // Next, check the card against newly drawn cards to avoid duplication
        for (j = 0; j < i; j++)
        {
          if ((finalRank[i] == finalRank[j]) && (finalSuit[i] == finalSuit[j]))
          {
            cardDup = 1;
          }
        }
      } while (cardDup == 1);
      ranksInHand[finalRank[i]]++;
      suitsInHand[finalSuit[i]]++;
    }
  }
}
