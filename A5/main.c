#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STACK 100

typedef int element;
//구조체 배열 사용
typedef struct {
    element data[MAX_STACK];
    int top;
} StackType;

int is_empty(StackType* s) {
    return (s->top == -1);
}

int is_full(StackType* s) {
    return (s->top == (MAX_STACK - 1));
}

void push(StackType* s, element item) {
    if (is_full(s)) {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    s->top++;
    s->data[s->top] = item;
    printf("push %d \n", item);
}

element pop(StackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        return -1;
    }
    else {
        element item = s->data[s->top];
        s->top--;
        printf("pop %d\n", item);
        return item;
    }
}

int main() {
    srand(time(NULL));

    StackType stack;
    stack.top = -1;

    for (int i = 0; i < 30; i++) {
        int rand_num = rand() % 100 + 1;
        if (rand_num % 2 == 0) {
            push(&stack, rand_num);
        }
        else {
            pop(&stack);
        }
    }

    return 0;
}
