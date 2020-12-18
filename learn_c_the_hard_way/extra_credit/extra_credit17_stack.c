// From https://tunasalmon.com/2017/09/24/%E3%82%B9%E3%82%BF%E3%83%83%E3%82%AF%E3%81%AE%E5%AE%9F%E8%A3%85/
#include <stdio.h>

#define MAX_LENGTH 32

struct stack
{
  int array[MAX_LENGTH];
  int top;
};

int push(struct stack *stk, int input)
{
  if (stk->top <= MAX_LENGTH)
  {
    stk->top++;
    stk->array[stk->top] = input;
    return 0;
  }
  else
  {
    printf("Cannot add Data.\n");
    return -1;
  }
}

int pop(struct stack *stk)
{
  if (stk->top != 0)
  {
    int temp = stk->top;
    stk->top--;
    return stk->array[temp];
  }
  else
  {
    printf("Not found.\n");
    return -1;
  }
}

void init_stack(struct stack *stk)
{
  for (int i = 0; i < MAX_LENGTH; i++)
  {
    stk->array[i] = 0;
  }
  stk->top = 0;
}

void show_stack(struct stack *stk)
{
  for (int i = 0; i < MAX_LENGTH; i++)
  {
    printf("%d ", stk->array[i]);
  }
  printf("\ntop:%d\n\n", stk->top);
}

int main(void)
{
  int i;
  int d;
  struct stack stk;

  init_stack(&stk);
  for (i = 1; i < 10; i++)
  {
    push(&stk, i * 3);
    show_stack(&stk);
  }

  d = pop(&stk);
  printf("\n%d\n", d);
  show_stack(&stk);

  return 0;
}
