#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <assert.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <limits.h>
#include <time.h>

#define TRUE 1
#define FALSE 0


clock_t start, end;
double cpu_time_used;

typedef int DATTYPE; //ptr stands for pointer

struct pq_element
{
    DATTYPE data; // this can be any data type
    double priority;
};
typedef struct pq_element pq_element;

struct pq
{
    pq_element *pq_array; //array of pq_element-s
    int n;     // number of elements in PQ
    int alloc; // number of elements memory was allocated for
};
typedef struct pq pq;
typedef struct pq * pq_ptr;

pq_ptr pq_new(int size)
{
    pq_ptr new_pq;
    new_pq = (pq_ptr *)malloc(sizeof(pq));
    new_pq->pq_array = (pq_element *)malloc(sizeof(pq_element) * size);
    new_pq->alloc = size;
    new_pq->n = 0;

    return new_pq;
}

void pq_push(pq_ptr q, DATTYPE data, double priority)
{
    pq_element * pq_element_ptr;
    int s, f; // indices to traverse tree (s son, f father)

    // check if we need to reallocate memory
    int myq=q->n;
    int myalloc=q->alloc;
    if (myq >= myalloc)
    {
        q->alloc *= 2;
        q->pq_array = (pq_element *)realloc(q->pq_array, sizeof(pq_element) * q->alloc);
    }
    q->n++; // one more element in PQ
    s = q->n - 1; // new element is placed at bottom of tree/array
    f = (s-1)/2; //pq_array[f] is father of pq_array[s]
    while ((s > 0) && (priority < q->pq_array[f].priority))
    {
        q->pq_array[s] = q->pq_array[f]; // shift father down
        s = f; // son takes place of father
        f = (s-1)/2; // father at this new position of son
    }
    //place element here
    //printf("Inserting data %d and priority %d in heap at index %d\n", data, priority, s);
    q->pq_array[s].data = data;
    q->pq_array[s].priority = priority;

}

/* adjust tree that lost its root */
void pq_adjusttree(pq_ptr q)
{
    int p;  // index to parent
    int s1; // index for son 1
    int s2; // index for son 2
    int i;

    p = 0;
    s1 = 1;
    s2 = 2;

    // readjusting tree since root (pq_array[0]) will be deleted
    do
    {
           // if only one son, or son 1 lower priority
           if ((s2 > q->n-1) )
           {
               q->pq_array[p]=q->pq_array[s1]; // son 1 takes place of parent
               p = s1;
           }
           else if((q->pq_array[s1].priority < q->pq_array[s2].priority)){
             q->pq_array[p]=q->pq_array[s1]; // son 1 takes place of parent
             p = s1;
           }
           else
           {
               q->pq_array[p]=q->pq_array[s2]; // son 2 takes place of parent
               p = s2;
           }
           s1 = p+p + 1;
           s2 = p+p + 2;
    } while (s1 <= q->n-1); // parent doesn't have any children. we are done
    //printf("priority last parent: %d\n", p);

    // rellocate nodes in array after last parent that was moved up
    int size = q->n;
    int current = p+1;
    for(current; current !=size; current++)
    {
        q->n = current - 1;
        pq_push(q, q->pq_array[current].data, q->pq_array[current].priority);
    }

    q->n = size-1; // one fewer element in heap

    if (q->n < q->alloc/2 && q->n >= 4)
    {
        q->pq_array = realloc(q->pq_array, sizeof(pq_element) * (q->alloc/2));
        q->alloc = q->alloc/2;
    }

}

void pq_display(pq_ptr pq)
{
    int i;
    printf("Size of priority queue: %d\n", pq->n);
    printf("Space allocated for queue: %d\n", pq->alloc);
    printf("Data in priority queue:\n");
    for (i = 0; i < pq->n; i++)
        printf("%d ", pq->pq_array[i].data);
    printf("\n");
    printf("Priority of the data:\n");
    for (i = 0; i < pq->n; i++)
        printf("%lf ", pq->pq_array[i].priority);
    printf("\n");
}


DATTYPE pq_pop(pq_ptr q)
{
    // if (q->n == 0)
    // {
    //     printf("Underflow error: trying to pop empty queue\n");
    //     return 0;
    // }

    DATTYPE out;
    out = q->pq_array[0].data;
    if (q->n == 1)
        q->n = 0;
    else
        pq_adjusttree(q);
    return out;
}

int main()
{
    int i;
    int data;
    pq_ptr my_pq;
    my_pq = pq_new(10);
    double priority[] = {54.5, 234, 34, 354, 76, 12, 79, 23, 8, 28};
    start=clock();
    for (i = 0; i < 10; i++)
    {
        pq_push(my_pq, i, priority[i]);
        pq_display(my_pq);
        printf("\n");
    }
    end=clock();
    cpu_time_used=((double) (end-start))/CLOCKS_PER_SEC;
    printf("cpu_time_used: %lf\n", cpu_time_used);
    for (i = 0; i < 10; i++)
    {
        printf("Popping element out of priority queue: ");
        data = pq_pop(my_pq);
        //printf("%d\n");
        pq_display(my_pq);
        printf("\n");
    }


    return 0;
}
