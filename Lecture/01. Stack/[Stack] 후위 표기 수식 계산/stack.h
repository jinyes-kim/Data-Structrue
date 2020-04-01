#include <stdio.h>
#include <string.h>
#include <stdio.h>

typedef double element; 
typedef struct {
    element* stack;
    int top;
    int capacity;
} stackType;

void init_stack(stackType* s);
int is_full(stackType* s);
int is_empty(stackType* s);
void push(stackType*, element item);
element pop(stackType* s);
element peek(stackType* s);
void delete_stack(stackType* s);
void print_stack(stackType* s, const char* p);