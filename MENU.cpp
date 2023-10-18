#include "MENU.hpp"
using namespace std;

template <typename T>
void MENU() {
    int Key, SwitchKey;
    T value;
    auto* tree = new BinaryTree<T>();
    BinaryTree<T>* node;
    BinaryTree<T>* subtree;
    tree = tree->DeleteNodeByKey(tree, 0);

    while (true) {

        cout << "....................MENU...................." << endl;
        cout << "1. Insert." << endl;
        cout << "2. Search." << endl;
        cout << "3. Delete node by key." << endl;
        cout << "4. Print keys." << endl;
        cout << "5. Direct." << endl;
        cout << "6. Reverse" << endl;
        cout << "7. Symmetrical" << endl;
        cout << "8. Subtree" << endl;
        cout << "9. Exit" << endl;
        cout << "10. Menu of types." << endl;
        cout << "............................................" << endl;
        cout << "Input key : ";
        cin >> SwitchKey;
        cout << endl;

        switch (SwitchKey) {
            case 1:
                cout << "Input value of node : ";
                cin >> value;
                tree = tree->Insert(tree, value);
                cout << endl;
                break;
            case 2:
                try {
                    cout << "Input key : ";
                    cin >> Key;
                    node = tree->Search(tree, Key);
                    cout << "Node : " << node->GetValue() << endl;
                }
                catch(...)
                { cout << "Try again." << endl; }
                break;
            case 3:
                cout << "Input key : ";
                cin >> Key;
                tree->DeleteNodeByKey(tree, Key);
                cout << endl;
                break;
            case 4:
                cout << "Keys : ";
                tree->PrintKeys(tree);
                cout << endl << endl;
                break;
            case 5:
                cout << "Direct : ";
                tree->DirectBypass(tree);
                cout << endl << endl;
                break;
            case 6:
                cout << "Reverse : ";
                tree->ReverseBypass(tree);
                cout << endl << endl;
                break;
            case 7:
                cout << "Symmetrical: ";
                tree->SymmetricalBypass(tree);
                cout << endl << endl;
                break;
            case 8:
                try {
                    cout << "Input key : ";
                    cin >> Key;
                    subtree = tree->SubTree(tree, Key);
                    cout << "Subtree is created." << endl;
                    cout << "It's  keys : ";
                    subtree->PrintKeys(subtree);
                    cout << endl;
                    cout << "Values : ";
                    subtree->SymmetricalBypass(subtree);
                }
              catch(...)
                {cout << "Try again." << endl;}
                cout << endl ;
                break;
            case 9:
                return;
            case 10:
                 GeneralMenu();
            default:
                cout << "Incorrect key." << endl;
                break;
        }
    }
}

int GeneralMenu(){
    while(true) {
        int key;
        cout << "...........Type..........." << endl;
        cout << "1. Int" << endl;
        cout << "2. Double" << endl;
        cout << "3. Char" << endl;
        cout << "4. String" << endl;
        cout << ".........................." << endl;
        cout << "-";
        cin >> key;
        switch (key) {
            case 1:
                MENU<int>();
                break;
            case 2:
                MENU<double>();
                break;
            case 3:
                MENU<char>();
                break;
            case 4:
                MENU<string>();
                break;
            default:
                cout << "Try again." << endl;
                break;
        }
    }
    return 0;
}
