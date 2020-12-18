// From https://it-ojisan.tokyo/stack-push-pop-dynamic/
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3
#define MAX_UPSIZE 2

typedef struct
{
  int *pData;
  int tail;
  int thisNum;
} Stack_t;

void printStack(Stack_t *pStack)
{
  for (int i = 0; i < SIZE * pStack->thisNum; i++)
  {
    printf("%d ", pStack->pData[i]);
  }
  putchar('\n');
}

int initStack(Stack_t *pStack)
{
  pStack->pData = (int *)malloc(sizeof(int) * SIZE);
  if (!pStack->pData)
  {
    printf("Failed to malloc\n");
    return -1;
  }

  for (int i = 0; i < SIZE; i++)
  {
    pStack->pData[i] = 0;
  }
  pStack->tail = -1;
  pStack->thisNum = 1;

  printStack(pStack);

  return 0;
}

int push(Stack_t *pStack, int value)
{
  int *pTmp;
  if (pStack->tail >= SIZE * MAX_UPSIZE - 1)
  {
    printf("Full. Cannot add Data\n");
    printStack(pStack);
    return 0;
  }

  if (pStack->tail >= SIZE * pStack->thisNum - 1)
  {
    printf("Upsize stack\n");
    pStack->thisNum++;
    pTmp = (int *)realloc(pStack->pData, sizeof(int) * SIZE * pStack->thisNum);
    if (pTmp)
    {
      pStack->pData = pTmp;
      for (int i = pStack->tail + 1; i < SIZE * pStack->thisNum; i++)
      {
        pStack->pData[i] = 0;
      }
    }
    else
    {
      printf("Failed to realloc\n");
      return -1;
    }
  }

  pStack->tail++;
  pStack->pData[pStack->tail] = value;

  printStack(pStack);

  return 0;
}

int pop(Stack_t *pStack)
{
  int *pTmp;

  if (pStack->tail <= -1)
  {
    printf("Empty\n");
    return 0;
  }

  if ((pStack->thisNum > 1) && (pStack->tail <= SIZE * (pStack->thisNum - 1)) )
  {
    printf("Downsize stack\n");
    pStack->thisNum--;
    pTmp = (int *)realloc(pStack->pData, sizeof(int) * SIZE * pStack->thisNum);
    if (pTmp)
    {
      pStack->pData = pTmp;
    }
    else
    {
      printf("Failed to realloc\n");
      return -1;
    }
  }

  pStack->pData[pStack->tail] = 0;
  pStack->tail--;

  printStack(pStack);

  return 0;
}

void deleteStack(Stack_t *pStack)
{
  free(pStack->pData);
}

int main(void)
{
  Stack_t Stack;
  Stack_t *pStack = &Stack;

  initStack(pStack);

  pop(pStack);

  push(pStack, 1);
  push(pStack, 2);
  push(pStack, 3);
  push(pStack, 4);
  push(pStack, 5);
  push(pStack, 6);
  push(pStack, 7);
  push(pStack, 8);
  
  pop(pStack);
  pop(pStack);
  pop(pStack);
  pop(pStack);

  push(pStack, 3);
  push(pStack, 4);
  push(pStack, 5);
  push(pStack, 6);
  push(pStack, 7);

  pop(pStack);
  pop(pStack);
  pop(pStack);
  pop(pStack);
  pop(pStack);
  pop(pStack);
  pop(pStack);
  pop(pStack);

  push(pStack, 1);
  push(pStack, 2);
  push(pStack, 3);
  push(pStack, 4);
  push(pStack, 5);
  push(pStack, 6);
  push(pStack, 7);
  push(pStack, 8);

  deleteStack(pStack);

  return 0;
}
