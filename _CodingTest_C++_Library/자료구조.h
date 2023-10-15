#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//트리 노드
class Node
{
public:
    Node(int index, int x, int y) : _index(index), _x(x), _y(y) {};

public:
    int _index;
    int _x;
    int _y;
    Node* _leftNode = nullptr;
    Node* _rightNode = nullptr;
};

//이진 트리 생성
//Node를 사용한 vector를 넘겨야함
//우선 순위 생각해서 넣을 것 (입력 순서면 상관없지만 우선순위가 존재하면 정렬 후에 넣어야한다)
void makeBinaryTree(vector<Node>& nodes, Node& rootNode)
{
    const int nodeSize = nodes.size();
    for (int index = 1; index < nodeSize; ++index)
    {
        Node* currentNode = &rootNode;
        Node* insertNode = &nodes[index];
        while (true)
        {
            bool isLeft = false;
            if (insertNode->_x < currentNode->_x)
                isLeft = true;

            if (isLeft)
            {
                if (currentNode->_leftNode == nullptr)
                {
                    currentNode->_leftNode = insertNode;
                    break;
                }
                else
                    currentNode = currentNode->_leftNode;
            }
            else
            {
                if (currentNode->_rightNode == nullptr)
                {
                    currentNode->_rightNode = insertNode;
                    break;
                }
                else
                    currentNode = currentNode->_rightNode;
            }
        }
    }
}

//전위순회
void preOrder(Node* node, vector<int>& root)
{
    if (node == nullptr)
        return;

    root.push_back(node->_index);
    preOrder(node->_leftNode, root);
    preOrder(node->_rightNode, root);
}

//중위순회
void preOrder(Node* node, vector<int>& root)
{
    if (node == nullptr)
        return;

    preOrder(node->_leftNode, root);
    root.push_back(node->_index);
    preOrder(node->_rightNode, root);
}

//후위순회
void postOrder(Node* node, vector<int>& root)
{
    if (node == nullptr)
        return;

    postOrder(node->_leftNode, root);
    postOrder(node->_rightNode, root);
    root.push_back(node->_index);
}