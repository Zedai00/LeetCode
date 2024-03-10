#include <cmath>
#include <iostream>

struct Node {
  long data;
  Node *next;
  Node(long value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
  Node *head;

public:
  LinkedList() : head(nullptr) {}
  ~LinkedList() {
    Node *current = head;
    while (current != nullptr) {
      Node *temp = current;
      current = current->next;
      delete temp;
    }
  }

  void insert(long value) {
    Node *newNode = new Node(value);
    if (head == nullptr) {
      head = newNode;
    } else {
      Node *t = head;
      while (t->next != nullptr) {
        t = t->next;
      }
      t->next = newNode;
    }
  }

  void insert(std::initializer_list<long> values) {
    for (long i : values) {
      insert(i);
    }
  }

  void printL() {
    Node *t = head;
    while (t != nullptr) {
      std::cout << t->data << " ";
      t = t->next;
    }
    std::cout << std::endl;
  }

  long getNumber() {
    long num = 0;
    long t = 0;
    Node *current = head;
    while (current != nullptr) {
      num = current->data * std::pow(10, t) + num;
      t++;
      current = current->next;
    }
    return num;
  }
};

int main() {
  LinkedList l1;
  l1.insert({2, 4, 9});

  LinkedList l2;
  l2.insert({5, 6, 4, 9});

  long a = l1.getNumber();
  long b = l2.getNumber();
  std::cout << "Numbers: " << a << " " << b << std::endl;

  long sum = a + b;
  LinkedList l3;

  if (sum == 0) {
    l3.insert(0);
  } else {
    while (sum > 0) {
      l3.insert(sum % 10);
      sum /= 10;
    }
  }

  std::cout << "Sum: ";
  l3.printL();

  return 0;
}
