// malloc() stdlib.h
// free() stdlib.h
// assert() assert.h
// strdup() string.h
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person
{
  char *name;
  int age;
  int height;
  int weight;
};

struct Person *Person_create(char *name, int age, int height, int weight)
{
  struct Person *who = malloc(sizeof(struct Person));
  /* 
   * void assert(scalar expression);
   * If expression is true, assert() do nothing.
   * If  expression  is  false assert() prints an error message to standard error and terminates the program by calling abort(3).
   * In this case, if (who == NULL), assert() works.
   */
  assert(who != NULL);

  /* who->name is syntax sugar of (*who).name
   * char *strdup(const char *s);
   * The  strdup()  function  returns  a  pointer to a new string which is a duplicate of the string s.
   * Memory for the new string is obtained with malloc(), and can be freed with free().
   */

  who->name = strdup(name);
  who->age = age;
  who->height = height;
  who->weight = weight;

  return who;
}

void Person_destory(struct Person *who)
{
  assert(who != NULL);

  free(who->name);
  free(who);
}

void Person_print(struct Person *who)
{
  printf("Name: %s\n", who->name);
  printf("\tAge: %d\n", who->age);
  printf("\tHeight: %d\n", who->height);
  printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char *argv[])
{
  // make two people structures
  struct Person *joe = Person_create("Joe Alex", 32, 64, 140);
  struct Person *frank = Person_create("Frank Blank", 20, 72, 180);

  // print them out and where they are in memory
  printf("Joe is at memory location %p:\n", joe);
  Person_print(joe);

  printf("Frank is at memory location %p:\n", frank);
  Person_print(frank);

  // make everyone age 20 years and print them again
  joe->age += 20;
  joe->height -= 2;
  joe->weight += 40;
  Person_print(joe);

  frank->age += 20;
  frank->weight += 20;
  Person_print(frank);

  // destory them both so we clean up
  Person_destory(joe);
  Person_destory(frank);

  return 0;
}
