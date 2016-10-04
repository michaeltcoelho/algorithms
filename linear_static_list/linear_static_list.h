
#define MAX 100

struct person {
    int num;
    char name[50];
    float n1, n2, n3;
};

typedef struct list List;

List* create_list();

void set_list_free(List* li);

int list_size(List* li);

int is_full(List* li);

int is_empty(List* li);

int append(List* li, struct person p);

int prepend(List* li, struct person p);

int insert_ordered(List* li, struct person p);

int remove_last(List* li);

int remove_first(List* li);

int search_pos(List* li, int pos, struct person *p);

int search(List* li, int num, struct person *p);
