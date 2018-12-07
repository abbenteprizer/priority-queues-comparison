#include <stdio.h>
#include <stdlib.h>

struct node {
  int data; // only storing int for now
  double priority; 
  struct node *next;
};


struct node *newQueue(int data, double priority) {
  struct node* first = (struct node*)malloc(sizeof(struct node*));
  first->data = data;
  first->priority = priority;
  first->next = NULL;

  return first;
}

void insert(struct node *head, int data, double priority) {
  struct node *new = newQueue(data, priority);
  struct node *first = head;

  // Boundary condition where node is first in the list
  if(priority <= (head->priority)) { // FIFO?
    new->next = head;
    head = new;
    //    printf("we got here 1 and p = %f \n", priority);    
  } else {
    while((head->next != NULL) && priority >((head->next)->priority)){
      //      printf("we got here 2 and p = %f \n", priority);
      head = head->next;
    }

    new->next = head->next;
    head->next = new;
  }
  
}

void show(struct node *pq) {
  struct node *it = pq;
  while(it != NULL) {
    printf("Node with data %d and priority %f\n", it->data, it->priority);
    it = it->next;
    
  }
  
}

struct node* removePriorityMax(struct node *pq) {
  struct node *ret = (struct node*)malloc(sizeof(ret));
  ret->data = pq->data;
  ret->priority = pq->priority;
  ret->next = NULL;
  printf(" did we get here? \n");

  if(pq->next != NULL) {
    printf("i stepped forward \n");
    pq = pq->next; // Step forward
    return ret;
  }

  printf("list is now empty \n");
  return ret;
}


int main(int argc, char* argv[]) {
  // create new node
  printf("now making the queue\n");
  struct node *pq = newQueue(5, 0.3);

  printf("now inserting in the queue\n");  
  insert(pq, 3, 0.34);
  insert(pq, 7, 2.38);
  insert(pq, 7, 2.33);
  insert(pq, 7, 1.38);    
  
  show(pq);

  struct node *test;
  printf("now for tested\n");  
  test = removePriorityMax(pq);

  printf("now for removed\n");
  show(test);

  printf("how does pq look?\n");
  show(pq);

       
  return 0;
}
