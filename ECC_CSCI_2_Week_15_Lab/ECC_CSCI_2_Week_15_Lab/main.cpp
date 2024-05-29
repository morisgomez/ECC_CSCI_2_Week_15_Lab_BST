/*
 Program Name: main.cpp
 Programmer: Moris Gomez
 Date: Tuesday 05/29/2024
 Version Control: 10.0
 About: Week 15, CSCI 2, Lab.
 Description:
 
 1. Design a PartInfo class that holds the following parts information:

 PartID Number: an integer
 PartName: a string

 2. Create a binary tree whose nodes contain an object of the 
 PartInfo class. The nodes should be sorted on the PartID number.
 
 3. Test the binary tree by inserting nodes with the following information.
 1038 RAM
 1042 Motherboard
 1078 CPU
 1287 Graphic Card

 1920 Hard Disk

 2508 Power Supply
 3780 Modem
 4239 USB Port

 4. Your program should allow the user to enter a PartID number,
 then search the tree for the number. If the number is found, it
 should display the part’s name. If the node is not found, it
 should display “part is not found.”
 */

#include <iostream>
using namespace std;

class PartInfo
{
private:
    struct TreeNode
    {
        int PartID;
        string PartName;
        TreeNode* left;
        TreeNode* right;
    };
    TreeNode* root;
    
public:
    //default constructor for IntBinaryTree class:
    PartInfo()
    {
        root = NULL;
    } //close constructor
    
    TreeNode* getRoot()
    {
        return root;
    }
    
    //function 1: creates a TreeNode.
    void createNode(int num, string name)
    {
        TreeNode* newNode = NULL;
        newNode = new TreeNode;
        newNode->PartID = num;
        newNode->PartName = name;
        newNode->left = NULL;
        newNode->right = NULL;
        insertNode(root, newNode); //passes new TreeNode into function 2.
    } //close createNode function.
    
    //function 2: puts new TreeNode in proper place
    void insertNode(TreeNode*& nodeptr, TreeNode*& newNode) //&???????
    //(root, newNode)
    {
        if(nodeptr == NULL) //base case controlling recursion and located at end of branch, so insertion point found.
        { //also means root is not set in first node creation.
            nodeptr = newNode; //insert data.
        }
        else if(newNode->PartID < nodeptr->PartID) //data is less than parent data, so go left.
            //3 < 7
            //10 < 7
        {
            insertNode(nodeptr->left, newNode); //recursion to go left.
            //nodeptr->left (null) becomes nodeptr in new call.
            //move to next node after each recursion call.
        }
        else //data is greater than parent data, so go right.
        {
            //3 > 7
            //10 > 7
            insertNode(nodeptr->right, newNode); //recursion to go right.
            //nodeptr->right (null) becomes nodeptr in new call.
            //move to next node after each recursion call.
        }
    } //close insertNode function.
    
    //function 3:
    string searchNode(int num)
    {
        TreeNode* nodeptr = root;
        while(nodeptr) //nodeptr is pointing to a Node.
        {
            if(nodeptr->PartID == num)
            {
                return nodeptr->PartName;
            }
            else if(num < nodeptr->PartID)
            {
                nodeptr = nodeptr->left;
            }
            else
            {
                nodeptr = nodeptr->right;
            }
        } //end while.
        return "part is not found."; //?????????????
    } //close searchNode function.
    
    void displayPreOrder(TreeNode* nodeptr) const //root-left-right.
    {
        if(nodeptr)
        {
            cout << nodeptr->PartID << endl; //root.
            displayPreOrder(nodeptr->left); //recursion.
            displayPreOrder(nodeptr->right); //recursion.
        } //end if.
    } //close displayPreOrder function.
};

int main()
{
    /*
     1038 RAM
     1042 Motherboard
     1078 CPU
     1287 Graphic Card
     1920 Hard Disk -> Root so make this node first.
     2508 Power Supply
     3780 Modem
     4239 USB Port
     */
    //1. create PartInfo object:
    PartInfo BSTOne;
    
    //2. create & add root node:
    BSTOne.createNode(1920, "Hard Disk");
    
    //3. create & add rest of nodes:
    BSTOne.createNode(1038, "RAM");
    BSTOne.createNode(1042, "Motherboard");
    BSTOne.createNode(1078, "CPU");
    BSTOne.createNode(1287, "Graphic Card");
    BSTOne.createNode(2508, "Power Supply");
    BSTOne.createNode(3780, "Modem");
    BSTOne.createNode(4239, "USB Port");
    
    //4. search part via PartID & return part name:
    cout << BSTOne.searchNode(3780) << endl; //Modem.
    cout << BSTOne.searchNode(2508) << endl; //Power Supply.
    cout << BSTOne.searchNode(1287) << endl; //Graphic Card.
    cout << BSTOne.searchNode(1078) << endl; //CPU.
    cout << BSTOne.searchNode(1042) << endl; //Motherboard.
    cout << BSTOne.searchNode(1038) << endl; //RAM.
    cout << BSTOne.searchNode(4239) << endl; //USB Port.
    cout << BSTOne.searchNode(1920) << endl; //Hard Disk.
    
    cout << BSTOne.searchNode(1921) << endl; //part is not found.
    
    //5. use preorder algorithm
    BSTOne.displayPreOrder(BSTOne.getRoot());
    
    //6. checking node locations/tree formation
    //left subtree of root.
    cout << BSTOne.getRoot()->left->PartID << endl;
    cout << BSTOne.getRoot()->left->right->PartID << endl;
    cout << BSTOne.getRoot()->left->right->right->PartID << endl;
    
    //right subtree of root.
    cout << BSTOne.getRoot()->right->PartID << endl;
    cout << BSTOne.getRoot()->right->right->PartID << endl;
    cout << BSTOne.getRoot()->right->right->right->PartID << endl;
    
    return 0;
}
