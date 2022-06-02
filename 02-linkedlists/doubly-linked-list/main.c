#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0 
#define ERROR -1

#include "debug.h"
#include "dll.h"

int main(void) {
    unsigned seed = time(0);
    srand(seed);

    DLL *list = init();

    #ifdef TEST_SIZE
        printf("size: %d\n", list->size);
        printf("\n");
    #endif

    #ifdef TEST_EMPTY
        if(empty(list)) {
            printf("List is empty\n");
        } else {
            printf("List is not empty\n");
        }
        printf("\n");
    #endif

    #ifdef TEST_PUSH_FRONT
        for(int i=0; i<10; ++i) {
            push_front(list, i);
            print(list);
        }
        printf("\n");
    #endif

    #ifdef TEST_PUSH_BACK
        for(int i=0; i<10; ++i) {
            push_back(list, i);
            print(list);
        }
        printf("\n");
    #endif

    #ifdef TEST_POP_FRONT
        for(int i=0; i<5; ++i) {
            pop_front(list);
        }
        printf("\n");
    #endif 

    #ifdef TEST_ERASE
        for(int i=0; i<5; ++i) {
            erase(list, rand()%10);
            print(list);
        }
        printf("\n");
    #endif

    #ifdef TEST_INSERT
        for(int i=0; i<10; ++i) {
            insert(list, rand()%10, rand() % 100);
            print(list);
        }
        printf("\n");
    #endif

    #ifdef TEST_POP_BACK
        for(int i=0; i<5; ++i) {
            pop_back(list);
        }
        printf("\n");
    #endif

    #ifdef TEST_FRONT
        printf("front: %d\n", front(list));
        printf("\n");
    #endif

    #ifdef TEST_BACK
        printf("back: %d\n", back(list));
        printf("\n");
    #endif

    #ifdef TEST_VALUE_AT
        printf("size: %d\n", list->size);
		for(int i=0; i<list->size; ++i) {
			printf("value_at(%d): %d\n", i, value_at(list, i));
		}
        printf("\n");
    #endif

    #ifdef TEST_PRINT_FROM_N
        for(int i=0; i<list->size+1; ++i) {
            print_from_n(list, i);
        }
        printf("\n");
    #endif

    #ifdef TEST_REMOVE_VALUE
        remove_value(list, 10);
        print(list);
        remove_value(list, 2);
        print(list);
        remove_value(list, 2);
        print(list);
        remove_value(list, 1);
        print(list);
        remove_value(list, 8);
        print(list);
        printf("\n");
    #endif

    #ifdef TEST_REVERSE
        for(int i=0; i<10; ++i) {
            push_back(list, rand() % 100);
        }
        printf("\n Regular: ");
        print(list);
        reverse(list);
        printf("\n Reversed: ");
        print(list);
    #endif 

    _free(&list);

    return 0;
}

DLL* init() {
    DLL *list = (DLL *)malloc(sizeof(DLL));

    list->dummy_head = new_node(-1);
    list->dummy_tail = new_node(-1);

	list->dummy_head->next = list->dummy_tail;
	list->dummy_tail->prev = list->dummy_head;
    list->size = 0;

    return list;
}

void _free(DLL **list) {
#ifdef DEBUG
    printf("[[ inside '_free()' ]]\n");
#endif
    while(!empty(*list)) {
        pop_front(*list);
    }

    free((*list)->dummy_head);
    free(*list);
    *list = NULL;
}

void print(DLL *list) {
#ifdef DEBUG
    printf("[[ inside 'print()' ]]\n");
#endif
    if(list->size == 0) {
        printf("ERROR: list is empty.\n");
        return;
    }

    ListNode *temp = list->dummy_head;
    while(temp->next != list->dummy_tail) {
        temp = temp->next;
        printf("%d ", temp->data);
    }
    printf("\n");
}

void print_from_n(DLL *list, int index) {
#ifdef DEBUG
    printf("[[ inside 'print_from_n(%d)' ]]\n", index);
#endif
    if(list->size == 0) {
        printf("ERROR: list is empty.\n");
        return;
    }
    
    if(index < 0 || index >= list->size) {
        printf("ERROR: index out of range\n");
        return;
    }

    ListNode *temp = list->dummy_head->next;

    for(int i=0; i<index; ++i) {
        temp = temp->next;
    }

    while(temp->next != list->dummy_tail) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    
    printf("\n");
}

void reverse(DLL *list) {
#ifdef DEBUG
    printf("[[ inside reverse ]]\n");
#endif
    if(list->size == 0) {
        printf("ERROR: empty list\n");
        return;
    }

    ListNode *prev = list->dummy_tail;;
    ListNode *curr = list->dummy_head->next;
    
    while(curr != list->dummy_tail){
        ListNode *next = curr->next;
        curr->next=prev;
        prev = curr;
        curr=next;
    }
    list->dummy_head->next = prev;
}

int size(DLL *list) {
    return list->size;
}

_Bool empty(DLL *list) {
    return list->size == 0;
}

void push_front(DLL *list, int data) {
#ifdef DEBUG
    printf("[[ inside 'push_front(%d)' ]]\n", data);
#endif
    ListNode *newNode = new_node(data);
	list->dummy_head->next->prev = newNode;
	newNode->prev = list->dummy_head;
	newNode->next = list->dummy_head->next;
	list->dummy_head->next = newNode;
    ++(list->size);
}

int pop_front(DLL *list) {
#ifdef DEBUG
    printf("[[ inside 'pop_front' ]]\n");
#endif
    if(list->size == 0) {
        printf("ERROR: list is empty.\n");
		return ERROR;
    }

    ListNode *temp = list->dummy_head->next;
    int data = temp->data;
    list->dummy_head->next = temp->next;
    free(temp);

    --(list->size);

#ifdef DEBUG
    printf("[[ popping %d ]]\n", data);
#endif
    return data;
}

void push_back(DLL *list, int data) {
#ifdef DEBUG
    printf("[[ inside 'push_back(%d)' ]]\n", data);
#endif
    ListNode *newNode = new_node(data);
	list->dummy_tail->prev->next = newNode;
	newNode->prev = list->dummy_tail->prev;
	newNode->next = list->dummy_tail;
	list->dummy_tail->prev = newNode;
    ++(list->size);
}

int pop_back(DLL *list) {
#ifdef DEBUG
    printf("[[ inside 'pop_back' ]]\n");
#endif

    if(list->size == 0) {
        printf("ERROR: list is empty.\n");
		return ERROR;
    }

	ListNode *t = list->dummy_tail->prev;
	t->prev->next = t->next;
	t->next->prev = t->prev;
	--(list->size);
	int data = t->data;
    free(t);

#ifdef DEBUG
    printf("[[ popping: %d ]]\n", data);
#endif

    --(list->size);
    return data;
}

void insert(DLL *list, int index, int data) {
#ifdef DEBUG
    printf("[[ inside 'insert(index:%d, data:%d)' ]]\n", index, data);
#endif

    if(index < 0 || index > list->size) {
        printf("ERROR: index out of range.\n");
        return;
    }

    if(index == 0) {
        push_front(list, data);
    } else if(index == list->size) {
        push_back(list, data);
    } else {
        ListNode *curr = list->dummy_head;
        for(int i=0; i<index; ++i) {
            curr = curr->next;
        }

        ListNode *newNode = new_node(data);
		curr->next->prev = newNode;
		newNode->next = curr->next;
		newNode->prev = curr->prev;
        curr->next = newNode;

        ++(list->size);
    }
}

void erase(DLL *list ,int index) {
#ifdef DEBUG
    printf("[[ inside 'erase(index:%d)' ]]\n", index);
#endif

    if(list->size == 0) {
        printf("ERROR: list is empty.\n");
        return;
    }
    if(index < 0 || index > list->size) {
        printf("ERROR: index out of range.\n");
        return;
    }

    if(index == 0) {
        pop_front(list);
    } else if(index == list->size-1) {
        pop_back(list);
    } else {
        ListNode *curr = list->dummy_head;

        for(int i=0; i<index; ++i) {
            curr = curr->next;
        }

        ListNode *t = curr->next;
		t->next->prev = curr;
        curr->next = t->next;
        free(t);

        --(list->size);
    }
}

_Bool remove_value(DLL *list, int data) {
#ifdef DEBUG
    printf("[[ inside 'remove_value(data: %d)' ]]\n", data);
#endif

    if(list->size == 0) {
        printf("ERROR: list is empty.\n");
        return FALSE;
    }

    ListNode *curr = list->dummy_head;

    while(curr->next != list->dummy_tail) {
        if(curr->next->data == data) {
        #ifdef DEBUG
            printf("[[ value found... deleting the node.. ]]\n");
        #endif
            ListNode *t = curr->next;
			t->next->prev = curr;
            curr->next = t->next;
            free(t);
            --(list->size);
            return TRUE;
        }

        curr = curr->next;
    }
    #ifdef DEBUG
        printf("[[ value NOT found... ]]\n");
    #endif
    return FALSE;
}

/* returns the value of the nth item (starting at 0 for first) */
/* 0-based indexing */
int value_at(DLL *list, int index) {
#ifdef DEBUG
    printf("[[ inside 'value_at(list, %d)' ]]\n", index);
#endif
    if(list->size == 0) {
        printf("ERROR: list is empty.\n");
		return ERROR;
    }
    if(index < 0 || index >= list->size) {
        printf("ERROR: index out of range.\n");
		return ERROR;
    }

    ListNode *curr = list->dummy_head->next;

    for(int i=0; i<index; ++i) {
        curr = curr->next;
    }

    return curr->data;
}

int front(DLL *list) {
#ifdef DEBUG
    printf("[[ inside 'front' ]]\n");
#endif
    if(list->size == 0) {
        printf("ERROR: list is empty.\n");
		return ERROR;
    }

    return list->dummy_head->next->data;
}

int back(DLL *list) {
#ifdef DEBUG
    printf("[[ inside 'back' ]]\n");
#endif
    if(list->size == 0) {
        printf("ERROR: list is empty.\n");
		return ERROR;
    }

    return list->dummy_tail->prev->data;
}
