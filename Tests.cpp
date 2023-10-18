#include "Tests.hpp"
using namespace std;

template <typename T>
void TestDirectBypass(BinaryTree<T>& tree){
    cout << "Testing of DirectBypass is (";
    for (int i = 1; i < 10; i++) {
        tree.Insert(&tree, i, i);
    }
    tree.DirectBypass(&tree);
    assert(tree.DetectKey(&tree, 1) == 1);
    cout << " ) successful." << endl;
}

template <typename T>
void TestReverseBypass(BinaryTree<T>& tree){
    cout << "Testing of ReverseBypass is (";
    int *array = new int[10];
    for (int i = 1; i < 10; i++) {
        tree.Insert(&tree, i, i);
    }
    for (int i = 9; i >=0; i--) {
        array[i] = i;
    }
    tree.ReverseBypass(&tree);
    assert(tree.DetectKey(&tree, 1) == array[1]);
    delete [] array;
    cout << " ) successful." << endl;
}


template <typename T>
void TestSymmetricalBypass(BinaryTree<T>& tree){
    cout << "Testing of SymmetricalBypass is (";
    tree.SymmetricalBypass(&tree);
    assert(tree.DetectKey(&tree, 1) == 1);
    cout << ") successful." << endl;
}


template <typename T>
void TestSubTree(BinaryTree<T>& tree, int key, BinaryTree<T>& subtree){
    cout << "Testing of SubTree is ";
    subtree = *tree.SubTree(&tree, key);
    assert(subtree.TreeLength(&subtree) == 3);
    cout << "successful." << endl;
}


template <typename T>
void TestDeleteNodeByKey(BinaryTree<T>& tree, int key, BinaryTree<T> &tree1){
    cout << "Testing of DeleteNodeByKey is ";
    tree1 = *tree.DeleteNodeByKey(&tree, key);
    assert(tree1.TreeLength(&tree1) == 4);
    cout << "successful." << endl;
}


void TEST(){
    auto* tree = new BinaryTree<int>(0, 0);
    TestDirectBypass(*tree);
    delete tree;

    tree = new BinaryTree<int>(0, 0);
    TestReverseBypass(*tree);
    delete tree;

    tree = new BinaryTree<int>(0, 0);
    tree->Insert(tree, 1, 4);
    tree->Insert(tree, 2, 15);
    tree->Insert(tree, 3, 19);
    tree->Insert(tree, 4, 56);
    TestSymmetricalBypass(*tree);
    delete tree;


    tree = new BinaryTree<int>(0, 0);
    auto* subtree = new BinaryTree<int>();
    tree->Insert(tree, 1, 4);
    tree->Insert(tree, 2, 15);
    tree->Insert(tree, 3, 19);
    tree->Insert(tree, 4, 56);
    TestSubTree(*tree, 2, *subtree);
    delete tree;
    delete subtree;

    tree = new BinaryTree<int>(0, 0);
    auto* root = new BinaryTree<int>();
    tree->Insert(tree, 1, 4);
    tree->Insert(tree, 2, 15);
    tree->Insert(tree, 3, 19);
    tree->Insert(tree, 4, 56);
    TestDeleteNodeByKey(*tree, 2, *root);
    delete tree;

     auto *tree1 = new BinaryTree<double>(0, 0);
    TestDirectBypass(*tree1);
    delete tree1;

    tree1 = new BinaryTree<double>(0, 0);
    TestReverseBypass(*tree1);
    delete tree1;

    tree1 = new BinaryTree<double>(0, 0.453);
    tree1->Insert(tree1, 1, 4.0947);
    tree1->Insert(tree1, 2, 15.7465);
    tree1->Insert(tree1, 3, 19.364);
    tree1->Insert(tree1, 4, 56.59867);
    TestSymmetricalBypass(*tree1);
    delete tree1;


    tree1 = new BinaryTree<double>(0, 0);
    auto* subtree1 = new BinaryTree<double>();
    tree1->Insert(tree1, 1, 4.8746);
    tree1->Insert(tree1, 2, 15.7368);
    tree1->Insert(tree1, 3, 19.122);
    tree1->Insert(tree1, 4, 56.49857);
    TestSubTree(*tree1, 2, *subtree1);
    delete tree1;
    delete subtree1;

    tree1 = new BinaryTree<double>(0, 0.7668);
    auto* tree2 = new BinaryTree<double>();
    tree1->Insert(tree1, 1, 4.96);
    tree1->Insert(tree1, 2, 15.686957);
    tree1->Insert(tree1, 3, 19.34327);
    tree1->Insert(tree1, 4, 56.58764);
    TestDeleteNodeByKey(*tree1, 2,  *tree2);
    delete tree1;
    delete tree2;
}
