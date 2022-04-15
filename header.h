#pragma once
#include <iostream>
#include <fstream>

using namespace std;

struct aphorism_wisdom {
	string text = "";
	string author = "";
};

struct saying_wisdom {
	string text = "";
	string country = "";
};
struct wisdom {
	enum type { aphorism, saying };
	type key;
	union
	{
		aphorism_wisdom a;
		saying_wisdom s;
	};
	~wisdom() {}
	wisdom() : a() {}
};

struct Node {
	wisdom* thought = NULL;
	Node* next = NULL;
	Node* prev = NULL;
};




struct container {
	int size = 0;
	Node* current = NULL;
	Node* head = NULL;
};

void In(ifstream& ifst, aphorism_wisdom& a);
void In(ifstream& ifst, saying_wisdom& s);

void Out(ofstream& ofst, aphorism_wisdom& a);
void Out(ofstream& ofst, saying_wisdom& s);

wisdom* InWisdom(ifstream& ifst);
void Clear(container* c);
void InCont(ifstream& ifst, container* c);
void OutCont(ofstream& ofst, container* c);