#ifndef LAB4_2SEM_BINARYTREE_HPP
#define LAB4_2SEM_BINARYTREE_HPP

#include <iostream>
using namespace std;

template <typename T> class BinaryTree{
private:
    int Key;
    T ValNode;
    BinaryTree* left;
    BinaryTree* right;

public:
    BinaryTree() {
        left = nullptr;
        right = nullptr;
    }

    BinaryTree(int k, T thing) {
        Key = k;
        ValNode = thing;
        left = NULL;
        right = NULL;
    }

    int GetKey ()
    { return this -> Key; }

    BinaryTree* GetLeft()
    { return left; }

    BinaryTree* GetRight()
    { return right; }

    int TreeLength(BinaryTree* root) {
        if (root == NULL)
        { return 0; }
        return TreeLength(root->left) + TreeLength(root->right) + 1;
    }

    T GetValue ()
    { return this -> ValNode; }

    void SetKey(BinaryTree* node, int key)
    { node->Key = key; }

    void SetValue(BinaryTree* node, T value)
    { node->ValNode = value; }

    void SetLeft(BinaryTree<T>* node)
    { this->left = node; }

    void SetRight(BinaryTree<T>* node)
    { this->right = node; }

    bool DetectKey(BinaryTree<T>* root, int key) {
        if (root == nullptr)
        { return false; }
        if (root->Key == key)
        { return true; }
        return DetectKey(root->left, key) || DetectKey(root->right, key);
    }

    template <typename D = T> BinaryTree<T>* Insert(BinaryTree<T>* root, D value) {
        if constexpr (std::is_same_v<D, int>) {
            int key = value;
            return Insert(root, key, value);
        }
        else if constexpr (std::is_same_v<D, char>) {
            int key = static_cast<int>(value);
            cout << value << endl;
            return Insert(root, key, value);
        }
        else if constexpr (std::is_same_v<D, double>) {
            int key = static_cast<int>(value);
            return Insert(root, key, value);
        }
        else if constexpr (std::is_same_v<D, string>) {
            int key = 0;
            for (char c : value) {
                key += static_cast<int>(c);
            }
            return Insert(root, key, value);
        }
        else {
            return nullptr;
        }
    }

    BinaryTree<T>* Insert(BinaryTree<T>* root, int key, T value) {
        if (root == nullptr)
        { return new BinaryTree<T>(key, value); }
        if (key < root->Key) {
            if (root->left == nullptr)
            { root->left = new BinaryTree<T>(key, value); }
            else
            { root->left = Insert(root->left, key, value); }
        }
        else if (key > root->Key) {
            if (root->right == nullptr)
            { root->right = new BinaryTree<T>(key, value); }
            else
             { root->right = Insert(root->right, key, value); }
        }
        else
        { root->ValNode = value; }
        return root;
    }

    BinaryTree* Search(BinaryTree* root, int key) {
        if (root == NULL || root->Key == key)
        { return root; }
        if (key < root->Key)
        { return Search(root->left, key); }
        else
        { return Search(root->right, key); }
    }

    BinaryTree<T>* DeleteNodeByKey(BinaryTree<T>* root, int key){
        if (root == nullptr)
        { return nullptr; }
        if (key < root->Key)
        { root->left = DeleteNodeByKey(root->left, key); }
        else if (key > root->Key)
        { root->right = DeleteNodeByKey(root->right, key); }
        else {
            if (root->left == nullptr && root->right == nullptr) {
                if (root->left == nullptr && root->right == nullptr) {
                    delete root;
                    root = nullptr;
                }
            }
            else if (root->left == nullptr) {
                BinaryTree<T>* temp = root->right;
                root->right = nullptr;
                delete root;
                root = temp;
            }
            else if (root->right == nullptr) {
                BinaryTree<T>* temp = root->left;
                root->left = nullptr;
                delete root;
                root = temp;
            }
            else {
                BinaryTree<T>* temp = Min(root->right);
                root->Key = temp->Key;
                root->ValNode = temp->ValNode;
                root->right = DeleteNodeByKey(root->right, temp->Key);
            }
        }
        return root;
    }

    BinaryTree* Min(BinaryTree* node){
        BinaryTree* now = node;
        while (now && now->left != NULL) {
            now = now->left;
        }
        return now;
    }

    void DirectBypass(BinaryTree* root){
        if (root != NULL) {
            cout << root -> ValNode << " ";
            DirectBypass(root->left);
            DirectBypass(root->right);
        }
    }

    void ReverseBypass(BinaryTree* root){
        if (root != NULL) {
            ReverseBypass(root->left);
            ReverseBypass(root->right);
            cout << root -> ValNode << " ";
        }
    }

    void SymmetricalBypass(BinaryTree* root){
        if (root != NULL) {
            SymmetricalBypass(root->left);
            cout << root->ValNode << " ";
            SymmetricalBypass(root->right);
        }
    }

    void PrintKeys(BinaryTree<T>* root){
        if (root == NULL)
        { return; }
        PrintKeys(root->left);
        cout << root->Key << " ";
        PrintKeys(root->right);
    }

    BinaryTree<T>* SubTree(BinaryTree<T>* root, int key){
        BinaryTree<T>* subtreeRoot = Search(root, key);
        if (subtreeRoot == nullptr)
        { return nullptr; }
        BinaryTree<T>* leftSubtree = subtreeRoot->GetLeft();
        BinaryTree<T>* rightSubtree = subtreeRoot->GetRight();
        auto* newSubtreeRoot = new BinaryTree<T>(subtreeRoot->GetKey(), subtreeRoot->GetValue());
        if (leftSubtree != nullptr){
            BinaryTree<T>* newLeftSubtree = CopyTree(leftSubtree);
            newSubtreeRoot->SetLeft(newLeftSubtree);
        }
        if (rightSubtree != nullptr){
            BinaryTree<T>* newRightSubtree = CopyTree(rightSubtree);
            newSubtreeRoot->SetRight(newRightSubtree);
        }
        return newSubtreeRoot;
    }

    BinaryTree<T>* CopyTree(BinaryTree<T>* root) {
        if (root == nullptr)
        { return nullptr; }
        auto* copy = new BinaryTree<T>(root->GetKey(), root->GetValue());
        copy->SetLeft(CopyTree(root->GetLeft()));
        copy->SetRight(CopyTree(root->GetRight()));
        return copy;
    }

    ~BinaryTree() {
        if (left != NULL) {
            delete left;
            left = NULL;
        }
        if (right != NULL) {
            delete right;
            right = NULL;
        }
    }
};

#endif //LAB4_2SEM_BINARYTREE_HPP
