#pragma once
class node {
	static node* head;
public:
	node* next;
	char* artist, * album;
	node(char *, char *);
	~node();
	void insert(char *artistTmp, char *albumTmp);
	node* returnHead();
	int count();
};

inline node* mainRegister;