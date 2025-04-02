
typedef struct {
    int *stack;
    int maxSize;
    int top;
} CustomStack;

CustomStack *customStackCreate(int maxSize) {
    CustomStack *obj = (CustomStack *)malloc(sizeof(CustomStack));
    if (obj == NULL) {
        return NULL;
    }
    obj->stack = (int *)malloc(sizeof(int) * maxSize);
    if (obj->stack == NULL) {
        free(obj);
        return NULL;
    }
    obj->maxSize = maxSize;
    obj->top = -1;
    return obj;
}

void customStackPush(CustomStack *obj, int x) {
    if (obj->top < obj->maxSize - 1) {
        obj->top++;
        obj->stack[obj->top] = x;
    }
}

int customStackPop(CustomStack *obj) {
    if (obj->top == -1) {
        return -1;
    } else {
        return obj->stack[obj->top--];
    }
}

void customStackIncrement(CustomStack *obj, int k, int val) {
    int incrementCount = k;
    if (obj->top + 1 < k) {
        incrementCount = obj->top + 1;
    }
    for (int i = 0; i < incrementCount; i++) {
        obj->stack[i] += val;
    }
}

void customStackFree(CustomStack *obj) {
    if (obj) {
        free(obj->stack);
        free(obj);
    }
}

/**
 * Your CustomStack struct will be instantiated and called as such:
 * CustomStack* obj = customStackCreate(maxSize);
 * customStackPush(obj, x);
 
 * int param_2 = customStackPop(obj);
 
 * customStackIncrement(obj, k, val);
 
 * customStackFree(obj);
*/