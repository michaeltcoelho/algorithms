// queue.h
#define MAX 100

struct person {
    int num;
    char name[50];
    int age;
};

typedef struct queue Queue;

Queue* create_queue();

void destroy(Queue *q);

int length(Queue *q);

int is_full(Queue *q);

int is_empty(Queue *q);

int qput(Queue *q, struct person p);

int qremove(Queue *q);

int get(Queue *q, struct person *p);
