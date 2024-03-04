#pragma once 
#include <iostream>
#include <fstream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

Node* makeNode(int x);

void readFile(Node *&head);

unsigned int changeListIntoNum(Node *head);

void print(unsigned int x);

void deleteList(Node *&head);