#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include "album.h"
node* node::head = NULL;

node* node::returnHead() {
	return head;
}


node::node(char* artistTmp, char* albumTmp)
{
	artist = new char[32];
	album = new char[32];
	strcpy(this->artist, artistTmp);
	strcpy(this->album, albumTmp);
	this->next = NULL;
}


void node::insert(char* artistTmp, char* albumTmp)
{
	if (this->head == NULL)
	{
		head = new node(artistTmp, albumTmp);
		head->next = NULL;
	}
	else {
		node* p = new node(artistTmp, albumTmp);
		p->next = head;
		head = p;
	}
}

node::~node() {
	this->head = NULL;
}

int node::count()
{
	int i = 0;
	node* p = head;
	while (p != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}