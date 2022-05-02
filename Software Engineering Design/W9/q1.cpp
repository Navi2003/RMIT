
#include <iostream>
#include <iomanip>

using namespace std;

class Node{
public:
    int value;
    Node *prev = NULL;
    Node *next = NULL;

    Node(int value){
        this->value = value;
    }

    void setLinks(Node *prev, Node *next){
        this->prev = prev;
        this->next = next;
    }

    void linkNext(Node *next){
        this->next = next;
        if (next != NULL){
            next->prev = this;
        }
    }

    void linkPrev(Node *prev){
        this->prev = prev;
        if(prev != NULL){
            prev->next = this;
        }
    }
};

void printNodeForward(Node *n){
    while (n != NULL){
        cout << n->value << " --> ";
        n = n->next;
    }
}

void printNodeBackward(Node *n){
    while (n != NULL){
        cout << n->value << " --> ";
        n = n->prev;
    }
}

void insertNode(Node *&head, Node *&last, Node *priorNode, Node *newNode){
    if (priorNode == NULL){
        newNode->linkNext(head);
        head = newNode;
    } else {
        newNode->linkNext(priorNode->next);
        newNode->linkPrev(priorNode);
        if(priorNode == last){
            last = newNode;
        }
    }
}

void deleteNode(Node *&head, Node *&last, Node *delNode){
    if (delNode == head){
        delNode->next->prev = NULL;
        head = delNode->next;
        delNode->next = NULL;
    } else if (delNode == last){
        delNode->prev->next = NULL;
        last = delNode->prev;
        delNode->prev = NULL;
    } else {
        delNode->prev->linkNext(delNode->next);
    }
}

void swapNode(Node *&head, Node *&last, Node *n1, Node *n2){
    Node temp2 = *n2;

    if (n2->prev == n1){
        n2->linkPrev(n1->prev);
        n1->linkPrev(n2);
        n1->linkNext(temp2.next);
    } else if (n2->next == n1){
        n2->linkNext(n1->next);
        n1->linkPrev(temp2.prev);
        n1->linkNext(n2);
    } else {
        n2->linkNext(n1->next);
        n2->linkPrev(n1->prev);
        n1->linkNext(temp2.next);
        n1->linkPrev(temp2.prev);
    }
    head =  (head == n1) ? n2 :
            (head == n2) ? n1 : head;

    last =  (last == n1) ? n2 :
            (last == n2) ? n1 : last;
}

void sortAscend(Node *&head, Node *&last){
    while(1){
        int swap = 0;
        for (Node *left = head; left != NULL && left != last; ){
            if (left->value > left->next->value){
                swapNode(head, last, left, left->next);
                swap = 1;
            } else {
                left = left->next;
            }
        }
        if (swap == 0){
            break;
        }
    }
}

int main(){
    Node n1(8), n2(5), n3(3), n4(6), n5(100), n6(200);
    Node *head = &n1;

    n1.next = &n2;
    n2.prev = &n1;

    n2.next = &n3;
    n3.prev = &n2;

    n3.next = &n4;
    n4.prev = &n3;

    Node *last = &n4;
    
    insertNode(head, last, NULL, &n5);
    insertNode(head, last, &n3, &n6);
    deleteNode(head, last, &n2);
    cout << head->value << "\n";
    printNodeForward(head);
    cout << "\n";
    printNodeBackward(last);
    cout << "\n";
    sortAscend(head, last);
    printNodeForward(head);
    cout << "\n";
    printNodeBackward(last);

    return 0;
}

