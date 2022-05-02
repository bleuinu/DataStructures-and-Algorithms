#include <stdio.h>
#include <stdlib.h>

#define DEFAULT 8

typedef struct {
  int front;
  int rear;
  int size;
  int *arr;
} Queue;

void enqueue(Queue *, int);
int dequeue(Queue *);

static inline _Bool empty(Queue *);
static inline _Bool full(Queue *);
static inline int front(Queue *);
static inline int rear(Queue *);
static void print(Queue *);

int main(void) {
  Queue queue = {.front = -1,
    .rear = -1,
    .size = DEFAULT,
    .arr = (int *)malloc(sizeof(int) * DEFAULT)};

  enqueue(&queue, 14);
  enqueue(&queue, 22);
  enqueue(&queue, 13);
  enqueue(&queue, -6);
  print(&queue);

  dequeue(&queue);
  dequeue(&queue);
  print(&queue);

  enqueue(&queue, 9);
  enqueue(&queue, 20);
  enqueue(&queue, 25);
  print(&queue);

  full(&queue);
  empty(&queue);
  front(&queue);
  rear(&queue);

  free(queue.arr);

  return 0;
}

void enqueue(Queue *q, int data) {
  if (full(q)) {
    printf("[[ enqueue - queue is full ]]\n");
    return;
  }

  printf("[[ equeuing - %d ]]\n", data);
  if (q->front == -1) {
    q->front = q->rear = 0;
  } else if (q->rear == q->size - 1 && q->front != 0) {
    q->rear = 0;
  } else {
    ++(q->rear);
  }

  q->arr[q->rear] = data;
}

int dequeue(Queue *q) {
  if (empty(q)) {
    printf("[[ dequeue - queue is empty ]]\n");
    return -1;
  }

  int data = (q->arr)[q->front];
  printf("[[ dequeing - %d ]]\n", data);
  (q->arr)[q->front] = -1;

  if (q->front == q->rear) {
    q->front = q->rear = -1;
  } else if (q->front == q->size - 1) {
    q->front = 0;
  } else {
    ++(q->front);
  }

  return data;
}

static inline _Bool empty(Queue *q) {
  if (q->front == -1) {
    return 1;
  }

  return 0;
}

static inline _Bool full(Queue *q) {
  return ((q->rear == q->size - 1 && q->front == 0) ||
      (q->rear == q->front - 1));
}

static inline int front(Queue *q) {
  if (empty(q)) {
    printf("[[ front - queue is empty ]]\n");
    return -1;
  }

  return q->front;
}
static inline int rear(Queue *q) {
  if (empty(q)) {
    printf("[[ rear - queue is empty ]]\n");
    return -1;
  }

  return q->rear;
}

static void print(Queue *q) {
  if (empty(q)) {
    printf("[[ print -- queue is empty ]]\n");
    return;
  }

  int i = q->front;
  int n = q->rear;

  for (; i <= n; ++i) {
    printf("%d ", (q->arr)[i]);
  }
  printf("\n");
}
