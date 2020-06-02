//---------------------------------------------------------------------------

#ifndef TreeH
#define TreeH
//---------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vcl.h>
#include <math.h>

class node{
	public:
	int key;
	AnsiString name;
	node *left, *right;
	void add(node **tree, int x, AnsiString str);
	void simmetricPrint(node *tree, TMemo *mem);
	void preOrderPrint(node *tree, TMemo *mem);
	void postOrderPrint(node *tree, TMemo *mem);
	void deleteTree(node *tree);
	int getDeep(node *tree);
	void deleteNode(node **tree, int data);
	void balance(node **tree);
    void findNode(node *tree,TEdit *edit);
	private:
    int max(int a,int b);
};
#endif
