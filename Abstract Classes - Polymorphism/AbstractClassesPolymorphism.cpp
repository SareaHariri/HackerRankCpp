#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct Node {
  Node *next;
  Node *prev;
  int value;
  int key;
  Node(Node *p, Node *n, int k, int val)
      : prev(p), next(n), key(k), value(val){};
  Node(int k, int val) : prev(NULL), next(NULL), key(k), value(val){};
};

class Cache {

protected:
  map<int, Node *> mp;            // map the key to the node in the linked list
  int cp;                         // capacity
  Node *tail;                     // double linked list tail pointer
  Node *head;                     // double linked list head pointer
  virtual void set(int, int) = 0; // set function
  virtual int get(int) = 0;       // get function
};
class LRUCache : Cache {
public:
  LRUCache(int c) { this->cp = c; }
  void set(int k, int v) {
    if (this->mp.empty()) {
      mp[k] = new Node(k, v);
      head = mp[k];
      tail = mp[k];
    } else {
      if (mp.find(k) != mp.end()) {
        mp[k]->value = v;
      } else {
        mp[k] = new Node(k, v);
        head->next = mp[k];
        head = mp[k];
        if (mp.size() > cp) {
          struct Node *toRemove = tail;
          tail = tail->next;
          mp.erase(toRemove->key);
        }
      }
    }
  }
  int get(int k) {
    int l_ret = -1;
    if (mp.find(k) != mp.end()) {
      l_ret = mp[k]->value;
    }
    return l_ret;
  }
};

int main() {
  int n, capacity, i;
  cin >> n >> capacity;
  LRUCache l(capacity);
  for (i = 0; i < n; i++) {
    string command;
    cin >> command;
    if (command == "get") {
      int key;
      cin >> key;
      cout << l.get(key) << endl;
    } else if (command == "set") {
      int key, value;
      cin >> key >> value;
      l.set(key, value);
    }
  }
  return 0;
}
