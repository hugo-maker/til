#include <stddef.h>
#include <assert.h>

/*
 * Demonstration code for sorting a linked list.
 * 
 * The algorithm used is Mergesort, because that works really well
 * on linked lists, without requiring the O(N) extra space it needs
 * when you do it on arrays.
 * 
 * This code can handle singly and doubly linked lists, and
 * circular and linear lists too. For any serious application,
 * you'll probably want to remove the conditionals on `is_circular'
 * and `is_double' to adapt the code to your own purpose. 
 * 
 */

/*
 * This file is copyright 2001 Simon Tatham.
 * 
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 * 
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT.  IN NO EVENT SHALL SIMON TATHAM BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/*
 * This is the actual sort function. Notice that it returns the new
 * head of the list. (It has to, because the head will not
 * generally be the same element after the sort.) So unlike sorting
 * an array, where you can do
 * 
 *     sort(myarray);
 * 
 * you now have to do
 * 
 *     list = listsort(mylist);
 */

ListNode *listsort(ListNode *node) 
{
  ListNode *p, *q, *e, *tail;
  int insize, nmerges, psize, qsize, i;

  // make sure node is not NULL
  check_mem(node);

  insize = 1;

  while (1) 
  {
    p = node;
    node = NULL;
    tail = NULL;

    nmerges = 0; // count number of merges we do in this pass

    while (p) 
    {
      nmerges++; // there exists a merge to be done

      // step `insize' places along from p
      q = p;
      psize = 0;
      for (i = 0; i < insize; i++) 
      {
        psize++;
        q = q->next;
        if (!q)
        {
          break;
        }
      }

      /* if q hasn't fallen off end, we have two lists to merge */
      qsize = insize;

      /* now we have two lists; merge them */
      while (psize > 0 || (qsize > 0 && q)) 
      {
        /* decide whether next element of merge comes from p or q */
        if (psize == 0) 
        {
          /* p is empty; e must come from q. */
          e = q; 
          q = q->next;
          qsize--;
        } 
        else if (qsize == 0 || !q) 
        {
          /* q is empty; e must come from p. */
          e = p;
          p = p->next;
          psize--;
        } 
        else if (cmp(p,q) <= 0) // List_compare cmp
        {
          /* First element of p is lower (or same);
           * e must come from p. */
          e = p;
          p = p->next;
          psize--;
        }
        else 
        {
          /* First element of q is lower; e must come from q. */
          e = q;
          q = q->next;
          qsize--;
        }

        /* add the next element to the merged list */
        if (tail) 
        {
          tail->next = e;
        } 
        else 
        {
          node = e;
        }

        /* Maintain reverse pointers in a doubly linked list. */
        e->prev = tail;
        tail = e;
      }

      /* now p has stepped `insize' places along, and q has too */
      p = q;
    }
    tail->next = NULL;

    /* If we have done only one merge, we're finished. */
    if (nmerges <= 1) // allow for nmerges==0, the empty list case
    {
      return node;
    }

    /* Otherwise repeat, merging lists twice the size */
    insize *= 2;
  }

error:
  return NULL;
}
