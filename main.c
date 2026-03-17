#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    size_t size;
    size_t capacity;
    size_t item_size;
} stack_headers;

void* init_stack(size_t capacity, size_t type_size);
#define INIT_CAPACITY 256
#define stack_header(stack) ((stack_headers*) stack - 1)

void push(void* stack, void* item);
void* pop(void* stack);

typedef struct {
   char* data;
   size_t size;
} string8;

#define STR_LIT(s) (string8){ (char*)(s), sizeof((s)) - 1 }

int main(void) {
    void* string_stack = init_stack(INIT_CAPACITY, sizeof(string8*));
    push(string_stack, &STR_LIT("first_string"));
    push(string_stack, &STR_LIT("second_string"));
    push(string_stack, &STR_LIT("third_string"));

    printf("%s\n", ((string8*)pop(string_stack))->data);
    printf("%s\n", ((string8*)pop(string_stack))->data);
    printf("%s\n", ((string8*)pop(string_stack))->data);
    return 0;
}

void* init_stack(size_t capacity, size_t type_size) {
    void* newStack = malloc(sizeof(stack_headers) + (type_size * capacity));
    newStack = (void*)((char*)newStack + sizeof(stack_headers));
    stack_header(newStack)->size = 0;
    stack_header(newStack)->capacity = capacity;
    stack_header(newStack)->item_size = type_size;

    return newStack;
}


void push(void* stack, void* item) {
    stack_headers* header = stack_header(stack);

    if (header->size >= header->capacity) {
        size_t new_capacity = header->size * 2;
        void* copy = realloc(header, sizeof(stack_headers) + (header->item_size * new_capacity));
        stack = (void*)((char*)stack + sizeof(stack_headers));
        header->capacity = new_capacity;
    }

    char* destination = (char*) stack + header->size * header->item_size;
    memcpy(destination, item, header->item_size);
    header->size++;
}

void* pop(void* stack) {
    stack_headers* header = stack_header(stack);
    if (header->size == 0) return NULL;

    header->size--;
    char* item = (char*) stack + header->size * header->item_size;
    return (void*)item;
}
