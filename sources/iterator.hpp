#pragma once
#include"BinaryTree.hpp"
#include <iostream>
#include <string>
namespace ariel
{
 template <typename T>
    struct Node
    {
        T DATA;
        Node *Parent_Node;
        Node *Left_Child;
        Node *Right_Child;
        Node(const T &value) : DATA(value), Left_Child(nullptr), Right_Child(nullptr), Parent_Node(nullptr) {}
        Node() : Left_Child(nullptr), Right_Child(nullptr), Parent_Node(nullptr) {}
    };

    template <typename T>
    class PreOrder
    {
        Node<T> *preorderROOT;

    public:
        PreOrder(Node<T> *R = nullptr) : preorderROOT(R){};

        T &operator*() const
        {
            return preorderROOT->DATA;
        }

        T *operator->() const
        {
            return preorderROOT->DATA;
        }

        PreOrder &operator++()
        {
            if (preorderROOT->Left_Child != nullptr)
            {
                preorderROOT = preorderROOT->Left_Child;
            }
            else if (preorderROOT->Right_Child != nullptr)
            {
                preorderROOT = preorderROOT->Right_Child;
            }
            else
            {
                helpfun_PreoOrder();
            }

            return *this;
        }

        void helpfun_PreoOrder(){
                while (!(preorderROOT->Parent_Node == nullptr) && preorderROOT->Parent_Node->Right_Child == preorderROOT)
                {
                    preorderROOT = preorderROOT->Parent_Node;
                    while (preorderROOT->Parent_Node != nullptr && preorderROOT->Parent_Node->Right_Child == nullptr)
                    {
                        preorderROOT = preorderROOT->Parent_Node;
                    }
                }
                while (preorderROOT->Parent_Node != nullptr && preorderROOT->Parent_Node->Right_Child == nullptr)
                {
                    preorderROOT = preorderROOT->Parent_Node;
                    while (preorderROOT->Parent_Node != nullptr && (preorderROOT == preorderROOT->Parent_Node->Right_Child || preorderROOT->Parent_Node->Right_Child == nullptr))
                    {
                        preorderROOT = preorderROOT->Parent_Node;
                    }
                }
                if (preorderROOT->Parent_Node == nullptr)
                {
                    preorderROOT = nullptr;
                }
                else
                {
                    preorderROOT = preorderROOT->Parent_Node->Right_Child;
                }
        }

        PreOrder operator++(int)
        {
            PreOrder SUB_ROOT = *this;
            ++(*this);
            return SUB_ROOT;
        }

        bool operator==(const PreOrder &S_N) const
        {
            return preorderROOT == S_N.preorderROOT;
        }

        bool operator!=(const PreOrder &S_N) const
        {
            return !(preorderROOT == S_N.preorderROOT);
        }
    };
    template <typename T>
    class InOrder
    {
        Node<T> *Inorder_Root;

    public:
        InOrder(Node<T> *R = nullptr) : Inorder_Root(R)
        {
            if (R != nullptr)
            {
                while (Inorder_Root->Left_Child != nullptr)
                {
                    Inorder_Root = Inorder_Root->Left_Child;
                }
            }
        }

        T &operator*() const
        {
            return Inorder_Root->DATA;
        }

        T *operator->() const
        {
            return &(Inorder_Root->DATA);
        }

        InOrder &operator++()
        {
            if (Inorder_Root->Right_Child == nullptr)
            {
                while (Inorder_Root->Parent_Node != nullptr && Inorder_Root == Inorder_Root->Parent_Node->Right_Child)
                {
                    Inorder_Root = Inorder_Root->Parent_Node;
                }
                Inorder_Root = Inorder_Root->Parent_Node;
                return *this;
            }
            Inorder_Root = Inorder_Root->Right_Child;
            while (Inorder_Root->Left_Child != nullptr)
            {
                Inorder_Root = Inorder_Root->Left_Child;
            }
            return *this;
        }
        
        InOrder operator++(int)
        {
            const InOrder SUB_ROOT = *this;
            ++(*this);
            return SUB_ROOT;
        }

        bool operator==(const InOrder &S_N) const
        {
            return Inorder_Root == S_N.Inorder_Root;
        }

        bool operator!=(const InOrder &S_N) const
        {
            return !(Inorder_Root == S_N.Inorder_Root);
        }
    };

    template <typename T>
    class POSTOrder
    {
        Node<T> *POSTorder_ROOT;

    public:
        POSTOrder(Node<T> *R = nullptr) : POSTorder_ROOT(R)
        {
            if (!(R == nullptr))
            {
                while (POSTorder_ROOT->Left_Child != nullptr || POSTorder_ROOT->Right_Child != nullptr)
                {
                    if (POSTorder_ROOT->Left_Child != nullptr)
                    {
                        POSTorder_ROOT = POSTorder_ROOT->Left_Child;
                    }
                    else
                    {
                        POSTorder_ROOT = POSTorder_ROOT->Right_Child;
                    }
                }
            }
        }
        T &operator*() const
        {
            return POSTorder_ROOT->DATA;
        }

        T *operator->() const
        {
            return POSTorder_ROOT->DATA;
        }

        POSTOrder &operator++()
        {
            const Node<T> *Sub = POSTorder_ROOT;
            if (POSTorder_ROOT->Parent_Node == nullptr)
            {
                POSTorder_ROOT = POSTorder_ROOT->Parent_Node;
                return *this;
            }
            POSTorder_ROOT = POSTorder_ROOT->Parent_Node;        
            if (POSTorder_ROOT->Right_Child != nullptr && POSTorder_ROOT->Right_Child != Sub)
            {
                POSTorder_ROOT = POSTorder_ROOT->Right_Child;
                while (!( POSTorder_ROOT->Right_Child == nullptr && POSTorder_ROOT->Left_Child == nullptr))
                {
                    if (POSTorder_ROOT->Left_Child == nullptr)
                    {
                        POSTorder_ROOT = POSTorder_ROOT->Right_Child;
                    }
                    else
                    {
                            POSTorder_ROOT = POSTorder_ROOT->Left_Child;
                    }
                }
            }
                
            return *this;
        }
        POSTOrder operator++(int)
        {
            POSTOrder SUB_ROOT = *this;
            ++(*this);
            return SUB_ROOT;
        }

        
        bool operator==(const POSTOrder &other) const
        {
            return POSTorder_ROOT == other.POSTorder_ROOT;
        }
        bool operator!=(const POSTOrder &other) const
        {
            return !(POSTorder_ROOT == other.POSTorder_ROOT);
        }
    };

    
}