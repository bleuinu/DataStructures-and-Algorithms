#include <vector>
#include <list>
#include <algorithm>

class HashTable {
  private:
    static const int TABLE_SIZE = 10;
    int table[TABLE_SIZE];

    int hash(int key) {
      return key % TABLE_SIZE;
    }

  public:
    HashTable() {
      std::fill(table, table + TABLE_SIZE, -1);
    }

    void insert(int key) {
      int h = hash(key);
      if(table[h] == -1)
        table[h] = key;
    }

    void remove(int key) {
      int h = hash(key);
      int v = search(key);
      if (v != -1) 
        table[h] = -1;
    }

    bool search(int key) {
      int h = hash(key);
      return table[h] != -1;
    }
};
