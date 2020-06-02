//---------------------------------------------------------------------------

#include <vcl.h>
#include <utility>
#pragma hdrstop

#include "Unit1.h"
#include "Tree.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Node *tree = NULL;
int n = 0;
AnsiString a[1000], b[1000];
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Memo->Clear();
    List->Lines->Clear();
}

void print(Node *tree,int x, TTreeView *view)
{
	if (tree!=nullp) return;
	if (x == -1)
	{
		view->Items->AddFirst(NULL,tree->key);
	}
	else
		view->Items->AddChildFirst(view->Items->Item[x],  tree->key);
	x++;
	print(tree->left,x,view);
	print(tree->right,x,view);
}

void clear(TMemo *Memo,TTreeView *view)
{
	  Memo->Clear();
      view->Items->Clear();
}


//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
	tree->Clear(tree);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonDirectClick(TObject *Sender)
{
	Memo->Clear();
	tree->DirectOrder(tree, Memo);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonAscendingClick(TObject *Sender)
{
	Memo->Clear();
	tree->KeyPrint(tree, Memo);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonReverseClick(TObject *Sender)
{
	Memo->Clear();
	tree->ReverseOrder(tree, Memo);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonFindClick(TObject *Sender)
{
	try
	{
		tree->Find(tree,Edit);
	}
	catch(...)
	{
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonDeleteClick(TObject *Sender)
{
	try
	{
		tree->Delete(&tree,StrToInt(Edit->Text));
		TreeView->Items->Clear();
		print(tree,-1,TreeView);
        Edit->Clear();
	}
	catch(...)
	{
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonBalanceClick(TObject *Sender)
{
	tree->balance(&tree);
    TreeView->Items->Clear();
	print(tree,-1,TreeView);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AddTreeClick(TObject *Sender)
{
	try
	{
		tree->Add(&tree,StrToInt(Key->Text), String->Text);
		clear(Memo,TreeView);
		print(tree, -1, TreeView);
		String->Clear();
		Key->Clear();
	}
	catch(...)
	{
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::AddArrayClick(TObject *Sender)
{
	AnsiString s = Key->Text + " | " + String->Text;
	List->Lines->Add(s);
	a[n] = Key->Text;
	b[n] = String->Text;
	n++;
	Key->Clear();
	String->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonAddClick(TObject *Sender)
{
	for (int i = 0; i < n; i++)
	{
		try
		{
			tree->Add(&tree,StrToInt(a[i]),b[i]);
		}
		catch (...)
		{
			return;
		}
	}
	clear(Memo,TreeView);
	print(tree,-1,TreeView);
	List->Lines->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonFindSumClick(TObject *Sender)
{
	int sum = 0;
	tree->Sum(tree, sum);
    Sum->Text = IntToStr(sum);
}
//---------------------------------------------------------------------------

