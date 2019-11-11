#include <iostream>

using namespace std;


class BinTree{
    private:
            //узел дерева
        class Node{
            public:
                int Key;    //ключ
                int Data;      //инфомационное поле
                Node *Left, *Right;
                Node(int key)
                {
                    Key = key;
                    Left = NULL;
                    Right = NULL;
                }
        };
        Node *root = NULL;

    public:
        int add_node(int key)
        {
            Node *newNude = new Node(key);
            if(root == NULL)
            {
                root = newNude;
                return 0;
            }
            Node *Current = root;
            while(1)
            {
                if(newNude->Key == Current->Key)
                    return 1;
                if(newNude->Key < Current->Key)
                {
                    if(Current->Left == NULL)
                    {
                        Current->Left = newNude;
                        return 0;
                    }
                    Current = Current->Left;
                }
                else
                {
                    if(Current->Right == NULL)
                    {
                        Current->Right = newNude;
                        return 0;
                    }
                    Current = Current->Right;
                }
            }
        }
        BinTree(){}
        BinTree(istream &is)
        {
        	cout << "create bin tree\n";
            int key;
            cout << "list of keys:\n";
            while(is >> key)
            {
            	cout << key << " ";
                this->add_node(key);
            }
            cout << endl;
        }
        int printFatherAndSons(Node * node)
        {
            if(node == NULL)
                return 1;
            cout << node->Key << " ";
            if(node->Right != NULL)
            cout << node->Right->Key << " ";
            if(node->Left != NULL)
            cout << node->Left->Key;
            cout << endl;
            printFatherAndSons(node->Right);
            printFatherAndSons(node->Left);

        }
        int printBinTree()
        {
            cout << "function printBinTree\n";
            cout << "father son son\n";
            this->printFatherAndSons(root);

        }
};

int main()
{
    BinTree tree(cin);
    tree.printBinTree();
    return 0;
}
