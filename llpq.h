#include <stdio.h>
#include <stdlib.h>

struct node {
  int data; // only storing int for now
  double priority; 
  struct node *next;
};

struct node *newQueue(int data, double priority);

void insert(struct node **head, int data, double priority);

void show(struct node **pq);

int isEmpty(struct node **pq);

void removePriorityMax(struct node **pq);

int peek(struct node **head);
