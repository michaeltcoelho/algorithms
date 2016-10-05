// linked_stack.h

struct person {
    int num;
};

typedef struct element* Stack;

Stack* create_stack();

void destroy(Stack *s);

int length(Stack *s);

int is_empty(Stack *s);

int qpush(Stack *s, struct person p);

int qpop(Stack *s);

int get(Stack *s, struct person *p);
