#include "BinarySearchTree.h"
#include "BinaryTreeIterator.h"
#include "ListArray.h"
using CSC2110::ListArray;
#include "ListArrayIterator.h"
using CSC2110::ListArrayIterator;
#include "CD.h"
using CSC2110::CD;

#include <iostream>
using namespace std;

void deleteCDs(ListArray<CD>* list)
{
   ListArrayIterator<CD>* iter = list->iterator();

   while(iter->hasNext())
   {
      CD* cd = iter->next();
      delete cd;
   }

   delete iter;
}

int main()
{
   //the unsorted ListArray of cds
   ListArray<CD>* cds = CD::readCDs("cds.txt");
   int numItems = cds->size();
   //cout << numItems << endl;
   //cout << endl;

   //test the binary search tree
   //insert all of the cds
   ListArrayIterator<CD>* iter = cds->iterator();
   BinarySearchTree<CD>* bst = new BinarySearchTree<CD>(&CD::compare_items, &CD::compare_keys);
 
  while(iter->hasNext())
   {
      CD* cd = iter->next();
      bst->insert(cd);
   }
  
   delete iter;
   

   BinaryTreeIterator<CD>* bst_iter = bst->iterator();
   bst_iter->setInorder();  //takes a snapshot of the data
   
   while(bst_iter->hasNext())
   {
      CD* cd = bst_iter->next();
      cd->displayCD();
   }

   delete bst_iter;
 
   //DO THIS
   //display the height of the binary search tree (not minimum height)
   //display whether the binary search tree is balanced (should not be balanced)

  cout << " My height: " << bst -> getHeight() << endl;
   
   bool balance = bst -> isBalanced();
   
if (balance)
   {
      cout << "It is balanced. " << endl;
   }

  else
   {
      cout << "It is not balanced. " << endl;
   }
  

   //create a minimum height binary search tree
 
   BinarySearchTree<CD>* min_bst = bst->minimize();

    BinaryTreeIterator<CD>*  min_bst_iter = min_bst->iterator();
    
   //make sure that an inorder traversal gives sorted order
   bst_iter->setInorder();  //takes a snapshot of the data
   

  while(bst_iter->hasNext())
   {
      CD* cd = bst_iter->next();
      cd->displayCD();
   }
  
   
   delete min_bst_iter;

   //DO THIS
   //display the height of the binary search tree (should be minimum height)
   //display whether the binary search tree is balanced (should be balanced
   
   cout << "My minimum height: " << min_bst -> getHeight() << endl;

   bool min_balance = min_bst -> isBalanced();

   if(min_balance)
   {
      cout << "It is balanced. " << endl;
   }

   else
   {
      cout << "It is not balanced. " << endl;
   }



   //create a complete binary search tree
 

   //make sure that an inorder traversal gives sorted order
   BinarySearchTree<CD>* complete_bst = bst->minimizeComplete();
   BinaryTreeIterator<CD>*  comp_bst_iter = complete_bst->iterator();
   comp_bst_iter->setInorder();  //takes a snapshot of the data
 
  while(bst_iter->hasNext())
   {
      CD* cd = comp_bst_iter->next();
      cd->displayCD();
   }
   
   delete comp_bst_iter;


 
   delete bst;
   //DO THIS
   //display the height of the complete binary search tree (should be minimum height)
   //display whether the binary search tree is balanced (should be balanced)

   cout << " Total height: " << complete_bst->getHeight() << endl;

   bool com_balance = complete_bst -> isBalanced();

   if(com_balance)
   {
      cout << "It is balanced. " << endl;
   }

   else
   {
      cout << "It is not balanced. " << endl;
   }

   delete complete_bst;

   deleteCDs(cds);
   delete cds;
   return 0;
}
