#pragma once
#include <iostream>
#include <string>
#include "iterator.hpp"

namespace ariel
{
    template <typename T>
    class BinaryTree
    {
    private:
        Node<T> *Tree_Root;
        
        void Transfer_Tree_Nodes(Node<T> *D_V, const Node<T> *S_V)
        {
            if(S_V==nullptr||D_V==nullptr){
                return;
            }

            if (S_V->Right_Child != nullptr)
            {
                D_V->Right_Child = new Node<T>(S_V->Right_Child->DATA);
                D_V->Right_Child->Parent_Node = D_V;
                Transfer_Tree_Nodes(D_V->Right_Child, S_V->Right_Child);
            }
            if (S_V->Left_Child != nullptr)
            {
                D_V->Left_Child = new Node<T>(S_V->Left_Child->DATA);
                D_V->Left_Child->Parent_Node = D_V;
                Transfer_Tree_Nodes(D_V->Left_Child, S_V->Left_Child);
            }
        }
        Node<T> *check_exist_node(Node<T> *F_NODE, T S_V)
        {
            if (F_NODE->DATA == S_V)
            {
                return F_NODE;
            }
            Node<T> *SER_V = nullptr;
            if (F_NODE->Left_Child != nullptr)
            {
                SER_V = check_exist_node(F_NODE->Left_Child, S_V);
            }
            if(SER_V!=nullptr){
                return SER_V;
            }
            if (F_NODE->Right_Child != nullptr)
            {
                SER_V = check_exist_node(F_NODE->Right_Child, S_V);
            }
            return SER_V;
        }

        
    public:
        BinaryTree() : Tree_Root(nullptr) {}
        BinaryTree(BinaryTree &R_V)
        {
            Tree_Root = new Node<T>(R_V.Tree_Root->DATA);
        }
        BinaryTree(BinaryTree &&R_V) noexcept
        {
            Tree_Root = R_V.Tree_Root;
            R_V.Tree_Root = nullptr;
        }
        ~BinaryTree() {};
        BinaryTree &operator=(const BinaryTree<T> &R_V)
        {
            if (this != &R_V)
            {
                Tree_Root = new Node<T>(R_V.Tree_Root->DATA);
                Transfer_Tree_Nodes(Tree_Root, R_V.Tree_Root);
            }
            return *this;
        }

        BinaryTree &operator=(BinaryTree<T> &&R_V) noexcept
        {
            Tree_Root = R_V.Tree_Root;
            R_V.Tree_Root = nullptr;
            return *this;
        }

        BinaryTree &add_root( T R_V)
        {
            if (Tree_Root == nullptr)
            {
                Tree_Root = new Node<T>(R_V);
            }
            Tree_Root->DATA = R_V;
            return *this;
        }
       
        BinaryTree &add_left(T P_V, T F_NODE)
        {
            if (Tree_Root != nullptr)
            {
                Node<T> *n = check_exist_node(Tree_Root, P_V);
                if (n != nullptr)
                {
                    if (n->Left_Child != nullptr)
                    {
                        n->Left_Child->DATA = F_NODE;
                    }
                    else
                    {
                        n->Left_Child = new Node<T>(F_NODE);
                        n->Left_Child->Parent_Node = n;
                    }
                    return *this;
                }
            }
            throw "Error";
        }

        BinaryTree &add_right(T P_V, T F_NODE)
        {
            if (Tree_Root != nullptr)
            {
                Node<T> *src = check_exist_node(Tree_Root, P_V);
                if (src != nullptr)
                {
                    if (src->Right_Child != nullptr)
                    {
                        src->Right_Child->DATA = F_NODE;
                    }
                    else
                    {
                        src->Right_Child = new Node<T>(F_NODE);
                        src->Right_Child->Parent_Node = src;
                    }
                    return *this;
                }
            }
            throw "Error";
        }

        auto begin()
        {
            return begin_inorder();
        }

        auto end()
        {
            return end_inorder();
        }

        auto begin_preorder()
        {
            return PreOrder<T>{Tree_Root};
        }

        auto end_preorder()
        {
            return PreOrder<T>{};
        }

        auto begin_inorder()
        {
            return InOrder<T>{Tree_Root};
        }

        auto end_inorder()
        {
            return InOrder<T>{};
        }

        auto begin_postorder()
        {
            return POSTOrder<T>{Tree_Root};
        }

        auto end_postorder()
        {
            return POSTOrder<T>{};
        }

        const Node<T> *get_root() const { return Tree_Root; }

        friend std::ostream &operator<<(std::ostream &os, const BinaryTree &t)
        {

            return os;
        }
    };
    
}
