#include "FComponent.h"
#include <iostream>


int main()
{
	Component* root = new Folder("rootFolder");
	Component* folder1 = new Folder("Folder1)");
	Component* msg1 = new Message("msg1");
	Component* msg2 = new Message("msg2");
	Component* msg3 = new Message("msg3");
	folder1->Add(msg1);
	folder1->Add(msg2);

	Component* folder2 = new Folder("Folder2");
	folder2->Add(msg3);
	
	root->Add(folder1);
	root->Add(folder2);

	std::cout << root->Operation() << std::endl;
	
	delete root;
	delete folder1;
	delete folder2;
	delete msg1;
	delete msg2;
	delete msg3;
}