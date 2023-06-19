#include "texteditor.h"
#include <iostream>
using namespace std;

/** 
  * Assignment 2 for COSE213 Data Structures
  *
  * 2022. 4. 4  Won-Ki Jeong (wkjeong@korea.ac.kr)
  *
  */


// Default constructor 
TextEditor::TextEditor()
{
	currLine = 0;
	pos = buffer.Begin();
}

TextEditor::~TextEditor()
{
	if (pos != nullptr)
	{
		pos = nullptr;
	}
}

// Insert a new line after the current position
void TextEditor::Insert(const char* s)
{	
	buffer.InsertNext(pos, s);
	++currLine;
	pos.operator++();
}

// Delete the current line
void TextEditor::Delete()
{		
	if (pos == buffer.End())
	{
		pos.operator--();
		buffer.DeleteLast();
	}
	else
	{
		BufferType::Iterator it = pos;
		pos.operator++();
		buffer.DeleteNode(it);
	}
}

// Move one line up
void TextEditor::MoveUp()
{
	if (currLine != 0)
	{
		--currLine;
		pos.operator--();
	}
}

// Move one line down
void TextEditor::MoveDown()
{
	if (currLine != 0)
	{
		++currLine;
		pos.operator++();
	}
}

//
// Interactive mode
//
void TextEditor::Run()
{
	string inp;
	string insert;
		
	while(1)
	{
		cout << "> ";
		getline(cin, inp);
						
		// ToDo	- implement other functions

		if(inp == "u") MoveUp();
		else if(inp == "d") MoveDown();
		else if(inp == "p") Print();
		else if(inp == "pa") PrintAll();
		else if(inp == "r") Delete();
		else if(inp == "i")
		{
			getline(cin, insert);
			Insert(insert.c_str());
		}
		else if(inp == "x") exit(0);
		{
			cout << "No such command. Available commands are u(up), d(down), p(print), pa(print all), r (delete), i(insert), and x(exit)" << endl;
		}		
	}
}


// ----------------------

// Print the current line with the line number
void TextEditor::Print()
{
	if(buffer.Size() < 1) {
		std::cout << "Buffer is empty" << std::endl;
	}
	else {
		std::cout << "Current(L" << currLine << ") : " << *pos << std::endl;
	}
}

// Print all with the line number
void TextEditor::PrintAll()
{
	int i=1;
	for(BufferType::Iterator it=buffer.Begin(); it != buffer.End(); it++)
	{
		cout << "L" << i++ << " :";
		if(i == (currLine+1)) cout << "*";
		else cout << " ";
		cout << *it << endl;		
	}
}
