#include <iostream>

using namespace std;

struct Node{
  int data;
  Node *pNext;
};

void inputBookStore(Node *pStore);
void deleteStore(Node *pStore);
void displayStore(Node *pStore);
int main(){
	Node *pStore = nullptr;
	pStore = new Node;

    inputBookStore(pStore);
    deleteStore(pStore);

    delete pStore;
	return 0;
}

void inputBookStore(Node *pStore){
    cin >> pStore -> data;
	Node *cur = pStore;
    int n;
    while (cin >> n){
        if (n == 0) break;
        if (pStore == nullptr){
            pStore = new Node;
            cur = pStore;
        } else {
            cur -> pNext = new Node;
            cur = cur -> pNext;
        }
		cur -> data = n;
		cur -> pNext = nullptr;
    }
    cur -> pNext = nullptr;
}

void displayStore(Node *pStore){
    Node *cur = pStore;
    while (cur != nullptr){
        cout << cur -> data << " ";
        cur = cur -> pNext;
    }
}
void deleteStore(Node *pStore){
    // deallocate
    Node *cur = pStore;
    cur = pStore;
    Node *temp = cur;
    while (cur -> pNext != nullptr){
        temp = cur;
        cur = cur -> pNext;
        delete temp;
    }
    delete cur;
}