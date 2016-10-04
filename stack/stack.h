// stack.h
#define MAX 100

struct person {
    int num;
    char name[50];
    int age;
};

typedef struct stack Stack;

Stack* create_stack();

void destroy(Stack *s);

int length(Stack *s);

int is_full(Stack *s);

int is_empty(Stack *s);

int push(Stack *s, struct person p);

int pop(Stack *s);

int get(Stack *s, struct person *p);
