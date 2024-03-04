#pragma once
#include <iostream>
#include <fstream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *makeNode(int x);
void readFile(Node*& head1, Node*& head2, int &x);
int countList(Node *head);
void linkList(Node *head1, Node *& head2, int x);
void printList(Node *head, int x);
void deleteList(Node *&head);
