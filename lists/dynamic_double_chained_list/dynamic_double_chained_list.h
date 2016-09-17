struct person {
    int num;
    char name[50];
    float n1, n2, n3;
};

typedef struct element *List;

List* create_list();

void lfree(List* list);
