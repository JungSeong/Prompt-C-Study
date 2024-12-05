#ifndef __LB_QUEUE_H__
#define __LB_QUEUE_H__

#define TRUE 1
#define FALSE 0
#define SIZE 100

typedef char * Data;

typedef struct _node {
	Data data;
	struct _node *next;
} Node;

typedef struct _lQueue {
	Node *front;
	Node *rear;
	Node *cur;
} LQueue;

typedef LQueue Queue;

void QueueInit(Queue *pq);
int QIsEmpty(Queue *pq);
int QFirst(Queue *pq, Data *qdata);
int QNext(Queue *pq, Data *qdata);

void Enqueue(Queue *pq, Data data);
Data Dequeue(Queue *pq);
Data QPeek(Queue *pq);

#endif
