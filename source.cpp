#include "Header.h"
using namespace std;

void In(ifstream& ifst, aphorism_wisdom& f) {
	ifst >> f.text;
	ifst >> f.author;
}
void OutAphorism(ofstream& ofst, aphorism_wisdom& f) {
	ofst << "Text: " << f.text << endl;
	ofst << "It is an aphorism. Author: " << f.author << endl;
}
void In(ifstream& ifst, saying_wisdom& f) {
	ifst >> f.text;
	ifst >> f.country;
}
void OutSaying(ofstream& ofst, saying_wisdom& f) {
	ofst << "Text: " << f.text << endl;
	ofst << "It is a saying. Country: " << f.country << endl;
}

wisdom* InWisdom(ifstream& ifst) {
	wisdom* sh;
	int k = 0;
	ifst >> k;
	//aphorism_wisdom* a;
	//saying_wisdom* s;
	switch (k) {
	case 1:
		sh = new wisdom;
		sh->key = wisdom::type::aphorism;
		In(ifst, sh->a);
		break;
	case 2:
		sh = new wisdom;
		sh->key = wisdom::type::saying;
		In(ifst, sh->s);
		break;
	default:
		return 0;
	}
	return sh;
}
void OutWisdom(ofstream& ofst, Node* container)
{
	if (container->thought->key == wisdom::type::aphorism)
	{
		//aphorism_wisdom* aw;
		//aw = (aphorism_wisdom*)(c->current->thought->aphorism);
		//aw = (aphorism_wisdom*)(c->current->thought);
		OutAphorism(ofst, container->thought->a);
	}
	else
	{
		//saying_wisdom* sw;
		//sw = (saying_wisdom*)(c->current->thought->saying);
		//sw = (saying_wisdom*)(c->current->thought);
		OutSaying(ofst, container->thought->s);
	}
}

void Clear(container* c) {
	c->current = NULL;
	c->size = 0;
	c->head = 0;
}

void InCont(ifstream& ifst, container* c) {
	while (!ifst.eof()) {

		Node* newNode = new Node;
		newNode->thought = InWisdom(ifst);
		//aphorism_wisdom* sh = (aphorism_wisdom*)newNode->sh->a;
		if (c->head == NULL)
		{
			c->head = newNode;
			c->head->next = newNode;
			c->head->prev = newNode;
			c->size = 1;
		}
		else
		{
			c->current = c->head;
			while (c->current->next != c->head)
			{
				c->current = c->current->next;
			}
			c->current->next = newNode;
			c->current->next->prev = c->current;
			c->current = c->current->next;
			c->current->next = c->head;
			c->head->prev = c->current;
			c->size++;
		}
	}
}
void OutCont(ofstream& ofst, container* c) {
	ofst << "Container contents " << c->size << " elements." << endl;

	int i = 1;
	if (c->head == NULL)
	{
		return;
	}
	c->current = c->head;
	do
	{
		ofst << i << ": ";
		OutWisdom(ofst, c->current);
		c->current = c->current->next;
		i++;
	} while (c->current != c->head);
}