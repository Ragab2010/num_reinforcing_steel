#ifndef LINKE_LIST
#define LINKE_LIST

#include<iostream>
using namespace std;

struct Node{

	int number;
	int length;
	Node * next;
};

class list{
	private:
		enum{ IRON =12};
		int fraction;
		int number_of_Iron;
		Node *head;
		Node *head_fraction;
		Node *end;
		Node *end_fraction;
		int size;
		int size_fraction;
	public:
	list();
	list(int number , int length);
	int insert(int number , int length);
	int travest();
	int search(int length);
	int remove(Node *pn ,Node *back_pn);
	int insert_fraction( int length);

	int show();
	int calc();
	~list();

};

int Read( list & pn);
int exit();

#endif
