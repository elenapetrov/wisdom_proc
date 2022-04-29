#pragma once
#include <iostream>
#include <fstream>

using namespace std;

struct aphorism_wisdom {
	string text = "";
	string author = "";
	int rate = 0;
};

struct saying_wisdom {
	string text = "";
	string country = "";
	int rate = 0;
};

struct riddle_wisdom {
	string text = "";
	string answer = "";
};
struct wisdom {
	enum type { aphorism, saying, riddle };
	type key;
	union
	{
		aphorism_wisdom a;
		saying_wisdom s;
		riddle_wisdom r;
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
void In(ifstream& ifst, riddle_wisdom& r);

void Out(ofstream& ofst, aphorism_wisdom& a);
void Out(ofstream& ofst, saying_wisdom& s);
void Out(ofstream& ofst, riddle_wisdom& r);

wisdom* InWisdom(ifstream& ifst);
void OutWisdom(ofstream& ofst, Node* container);
void Clear(container* c);
void InCont(ifstream& ifst, container* c);
void OutCont(ofstream& ofst, container* c);
