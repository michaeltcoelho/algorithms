
struct person {
    int num;
    char name[50];
    float n1, n2, n3;
};

typedef struct element *List;

List* create_list();

void lfree(List* list);

int length(List* list);

int is_empty(List* list);

int is_full(List* list);

int prepend(List* list, struct person p);

int append(List* list, struct person p);

int ordered_insert(List* list, struct person p);

int delete(List* list, int num);

int get(List* list, int pos, struct person *p);

void print(List* list);
