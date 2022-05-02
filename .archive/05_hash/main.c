#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int key;
  int value;
} item;

typedef struct {
  /**
   * 0 - data DNE
   * 1 - data exists
   * 2 - data existed at least once
   */
  int flag;
  item *data;
} hashtable;

const int SIZE = 10;
hashtable *arr;

int hash(int k) {
  return k % SIZE;
}

void add(int key, int value) {
  int index = hash(key);
  int i = index;

  item *new_item = (item *)malloc(sizeof(item));
  new_item->key = key;
  new_item->value = value;

  while(arr[i].flag == 1) {
    if(arr[i].data->key == key) {
      printf("key already exists, hence updating its value\n");
      arr[i].data->value = value;
    }

    i = (i + 1) % SIZE;
    if(i == index) {
      printf("Hash table is full, cannot add any more items\n");
      return;
    }
  }

  arr[i].flag = 1;
  arr[i].data = new_item;
  printf("Key (%d) has been added\n", key);
}

_Bool exists(int key) {
  return arr[hash(key)].data != NULL;
}

int get(int key) {
  int index = hash(key);
  if(arr[index].data == NULL) {
    printf("No item found with a key: %d\n", key);
    return -1;
  }

  return arr[index].data->value;
}

void remove_item(int key) {
  int index = hash(key);
  int i = index;

  while(arr[i].flag != 0) {
    if(arr[i].flag == 1 && arr[i].data->key == key) {
      arr[i].flag = 2;
      arr[i].data = NULL;
      printf("Key (%d) has been removed.\n", key);
      return ;
    }

    i = (i + 1) % SIZE;
    if(i == index) {
      break;
    }
  }

  printf("This key does not exist\n");
}

void display(void) {
  for(int i=0; i<SIZE; ++i) {
    item *curr = (item *)arr[i].data;
    if(curr == NULL) {
      printf("Array [%d] has no elements.\n", i);
    } else {
      printf("Array [%d] has elements: %d (key) and %d (value)\n", i, curr->key, curr->value);
    }
  }
}

int main(void) {
  arr = (hashtable *)malloc(sizeof(hashtable) * SIZE);
  // initialize 'item' structure
  for(int i=0; i<SIZE; ++i) {
    arr[i].flag = 0;
    arr[i].data = NULL;
  }

  printf("Implementation of Hash Table in C with Linear Probing \n\n");

  int repeat;
  do {
    printf("MENU-: \n1.Add item"
        "\n2.Remove item" 
        "\n3.Display Hashtable"
        "\n Enter your choice -:");

    int choice;
    scanf("%d", &choice);

    int key, value;
    switch(choice) 
    {
      case 1:
        printf("Inserting item in Hashtable\n");
        printf("Enter key and value-:\t");
        scanf("%d %d", &key, &value);
        add(key, value);
        break;
      case 2:
        printf("Deleting item in Hashtable \n Enter the key to delete-:");
        scanf("%d", &key);
        remove_item(key);
        break;
      case 3:
        display();
        break;
      default:
        printf("Wrong Input\n");
    }

    printf("\n Do you want to continue-:(press 1 for yes)\t");
    scanf("%d", &repeat);
  } while(repeat == 1);

  return 0;
}
