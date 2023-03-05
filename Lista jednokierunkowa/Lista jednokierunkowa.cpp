#include <iostream>
#include "header.h"

class Node {
public:
    int value;
    Node* next;

    Node(int val) {
        value = val;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void addNode(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void deleteHead() {
        if (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void display() {
        Node* current = head;
        while (current != NULL) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList myList;

    myList.addNode(1);
    myList.addNode(2);
    myList.addNode(3);
    myList.addNode(10);
    myList.addNode(10);
    myList.addNode(10);
    myList.display();

    myList.deleteHead();
    myList.display();

    return 0;
}
