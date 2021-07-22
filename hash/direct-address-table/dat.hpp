#include <iostream>
#include <vector>
#include <string>
using namespace std;

class DAT {
  private:
    static const int MAX_KEY = 10007;
    bool table[MAX_KEY];

  public:
    DAT() {
      fill(table, table + MAX_KEY, false);
    }

    bool search(int key) {
      return table[key];
    }

    void insert(int key) {
      table[key] = true;
    }

    void remove(int key) {
      table[key] = false;
    }
};
