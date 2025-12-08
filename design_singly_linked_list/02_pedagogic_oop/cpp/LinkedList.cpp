#include "LinkedList.h"

namespace teaching {

LinkedList::LinkedList() : head(nullptr), tail(nullptr), size_count(0) {}

LinkedList::~LinkedList() {
  Node *curr = head;
  while (curr) {
    Node *next = curr->next;
    delete curr;
    curr = next;
  }
}

// Copy Constructor
LinkedList::LinkedList(const LinkedList &other)
    : head(nullptr), tail(nullptr), size_count(0) {
  Node *curr = other.head;
  while (curr) {
    insertTail(curr->val); // Re-use insertTail for deep copy
    curr = curr->next;
  }
}

// Copy Assignment
LinkedList &LinkedList::operator=(const LinkedList &other) {
  if (this == &other)
    return *this;

  // 1. Clean up old
  Node *curr = head;
  while (curr) {
    Node *next = curr->next;
    delete curr;
    curr = next;
  }
  head = nullptr;
  tail = nullptr;
  size_count = 0;

  // 2. Copy new
  curr = other.head;
  while (curr) {
    insertTail(curr->val);
    curr = curr->next;
  }
  return *this;
}

int LinkedList::get(int index) const {
  if (index < 0 || index >= size_count)
    return -1;
  Node *curr = head;
  for (int i = 0; i < index; ++i) {
    curr = curr->next;
  }
  return curr->val;
}

void LinkedList::insertHead(int val) {
  Node *newNode = new Node(val);
  newNode->next = head;
  head = newNode;
  if (size_count == 0) {
    tail = newNode;
  }
  size_count++;
}

void LinkedList::insertTail(int val) {
  Node *newNode = new Node(val);
  if (size_count == 0) {
    head = newNode;
    tail = newNode;
  } else {
    tail->next = newNode;
    tail = newNode; // Update tail
  }
  size_count++;
}

bool LinkedList::remove(int index) {
  if (index < 0 || index >= size_count)
    return false;

  if (index == 0) {
    Node *temp = head;
    head = head->next;
    if (size_count == 1) {
      tail = nullptr;
    }
    delete temp;
  } else {
    Node *prev = head;
    for (int i = 0; i < index - 1; ++i) {
      prev = prev->next;
    }
    Node *toDelete = prev->next;
    prev->next = toDelete->next;
    if (index == size_count - 1) {
      tail = prev;
    }
    delete toDelete;
  }
  size_count--;
  return true;
}

std::vector<int> LinkedList::getValues() const {
  std::vector<int> res;
  // Pre-allocate often bad for linked list as we don't know size fast unless we
  // track it. We track it! So we could reserve.
  res.reserve(size_count);
  Node *curr = head;
  while (curr) {
    res.push_back(curr->val);
    curr = curr->next;
  }
  return res;
}

int LinkedList::size() const { return size_count; }

} // namespace teaching
