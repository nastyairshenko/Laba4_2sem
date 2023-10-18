#ifndef LAB4_2SEM_TESTS_HPP
#define LAB4_2SEM_TESTS_HPP
#include <iostream>
#include "Tests.hpp"
#include "BinaryTree.hpp"
#include <cassert>


template <typename T>
void TestDirectBypass(BinaryTree<T> *tree);

template <typename T>
void TestReverseBypass(BinaryTree<T>& tree);

template <typename T>
void TestSymmetricalBypass(BinaryTree<T>& tree);

template <typename T>
void TestSubTree(BinaryTree<T>& tree, int key, BinaryTree<T>& subtree);

template <typename T>
void TestDeleteNodeByKey(BinaryTree<T>& tree, int key,  BinaryTree<T>& tree1);

void TEST();

#endif //LAB4_2SEM_TESTS_HPP
