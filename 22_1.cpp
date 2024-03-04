#include <iostream>

using namespace std;

struct Node{
  int data;
  Node *pNext;
};

Node * findX(Node *pStore, int x);
Node *merge2Lists(Node *&pStrore1, Node *&pStore2);

void inputBookStore(Node *&pStore);
void deleteStore(Node *&pStore);
void displayStore(Node *pStore);

int countNode(Node *head);
void deleteAllX(Node *&pStore, int x);
void reverseStore(Node *&pStore);
int main(){
	Node *pStore = nullptr;
	pStore = new Node;

    inputBookStore(pStore);
    int n = 3;
    Node *x = findX(pStore, n);
    if (x == NULL) cout << "0";
        else cout << "1";
    deleteStore(pStore);

    delete pStore;
	return 0;
}

void inputBookStore(Node *&pStore){
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
void deleteStore(Node *&pStore){
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

void deleteAllX(Node *&pStore, int x){
    Node *cur = pStore;
}

int countNode(Node *head){
    int count = 0;
    while (head != NULL){
        count ++;
        head = head->pNext;
    }
    return count;
}

void reverseStore(Node *&pStore){
    if (!pStore) return;
    Node *cur = pStore, *prev = NULL;
    Node *tmp;
    while (cur != NULL){
        if (cur -> pNext == NULL){
            cur -> pNext = prev;
            pStore = cur;
            return;
        }
        tmp = cur;
        cur = cur->pNext;
        tmp->pNext = prev;
        prev = tmp;
    }    
}

Node* findX(Node *pStore, int x){
    Node *cur = pStore;
    while (cur->data < x || cur != NULL){
        cur = cur->pNext;
    }

    if(cur && cur->data == x) return cur;
    return nullptr;
}

Node *merge2Lists(Node *&pStore1, Node *&pStore2){
    Node *cur1 = pStore1;
    while (cur1 -> pNext != NULL) 
        cur1 = cur1->pNext;

    cur1->pNext = pStore2;
    pStore2 = NULL;
    for (Node *i = pStore1; i != NULL; i++){
        Node *min = i;
        for(Node *j = i->pNext; j!= NULL; j++)
            if(min->data > j->data)
                min = j;
        if(min->data != i->data){
            int tmp = min->data;
            min->data = i->data;
            i->data = tmp;
        }
    }     
}