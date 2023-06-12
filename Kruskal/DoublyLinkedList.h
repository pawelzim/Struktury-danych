#include <iostream>

using namespace std;

template <typename T>
struct Node {
    T value;
    Node<T>* next;
    Node<T>* previous;
    Node() {
        next = nullptr;
        previous = nullptr;
    }
};

template <class T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int counter;

public:
    DoublyLinkedList();
    void newHead(T val);
    void popHead();
    void newTail(T val);
    void popTail();
    void display(int start, int end);
    int size();
    Node<T>* getFromTail(int x);
    Node<T>* getFromHead(int x);
};

template <typename T>
void Swap(Node<T>* n1, Node<T>* n2);



// ### implementacje metod klasy ###

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
    counter = 0;
}

template <typename T>
void DoublyLinkedList<T>::newHead(T val) {
    Node<T>* tmp = new Node<T>();
    tmp->value = val;
    if (head == nullptr && tail == nullptr) {
        tmp->next = nullptr;
        tmp->previous = nullptr;
        head = tmp;
        tail = tmp;
        counter++;
        return;
    }
    tmp->next = nullptr;
    tmp->previous = head;
    head->next = tmp;
    head = tmp;
    counter++;
}

template <typename T>
void DoublyLinkedList<T>::popHead() {
    if (head == nullptr) {
        cout << "List is empty, cannot popHead" << endl;
        return;
    }
    Node<T>* tmp = head;
    if (head == tail) {
        head = nullptr;
        tail = nullptr;
        delete tmp;
        counter--;
        return;
    }
    head = head->previous;
    delete tmp;
    head->next = nullptr;
    counter--;
}

template <typename T>
void DoublyLinkedList<T>::newTail(T val) {
    Node<T>* tmp = new Node<T>();
    tmp->value = val;
    if (head == nullptr && tail == nullptr) {
        tmp->next = nullptr;
        tmp->previous = nullptr;
        head = tmp;
        tail = tmp;
        counter++;
        return;
    }
    tmp->previous = nullptr;
    tmp->next = tail;
    tail->previous = tmp;
    tail = tmp;
    counter++;
}

template <typename T>
void DoublyLinkedList<T>::popTail() {
    if (tail == nullptr) {
        cout << "List is empty, cannot popTail" << endl;
        return;
    }
    Node<T>* tmp = tail;
    if (tail == head) {
        tail = nullptr;
        head = nullptr;
        delete tmp;
        counter--;
        return;
    }
    tail = tail->next;
    delete tmp;
    tail->previous = nullptr;
    counter--;
}

template <typename T>
void DoublyLinkedList<T>::display(int start, int end) {
    if (start > end) {
        cout << "Display error" << endl;
        return;
    }
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Node<T>* tmp2 = head;
    int pom = 0;
    while (tmp2 != nullptr && pom != start) {
        tmp2 = tmp2->next;
        pom++;
    }
    for (int i = start; i <= end; i++) {
        if (tmp2 != nullptr) {
            cout << tmp2->value << " ";
            tmp2 = tmp2->next;
        }
        else {
            //cout << "End of list" << endl;
            return;
        }
        cout << endl;
    }
}

template <typename T>
int DoublyLinkedList<T>::size() {
    return counter;
}

template <typename T>
Node<T>* DoublyLinkedList<T>::getFromTail(int x) {
    if (x < 0) {
        cout << "getFromTail error x<0" << endl;
        return nullptr;
    }
    else if (x >= counter) {
        cout << "getFromTail error x>= counter" << endl;
        return nullptr;
    }

    int i = 0;
    Node<T>* tmp = tail;

    while (i != x && tmp != nullptr) {
        tmp = tmp->next;
        i++;
    }

    return tmp;
}

template <typename T>
Node<T>* DoublyLinkedList<T>::getFromHead(int x) {
    if (x < 0 || x >= counter) {
        cout << "getFromHead error" << endl;
        return nullptr;
    }

    int i = 0;
    Node<T>* tmp = head;

    while (i != (counter - x - 1) && tmp != nullptr) {
        tmp = tmp->previous;
        i++;
    }

    return tmp;
}

template <typename T>
void Swap(Node<T>* n1, Node<T>* n2) {
    T val = n1->value;
    n1->value = n2->value;
    n2->value = val;
}