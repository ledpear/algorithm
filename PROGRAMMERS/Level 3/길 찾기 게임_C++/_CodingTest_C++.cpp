#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Node
{
public:
    Node(int index, int x, int y)
        : _index(index)
        , _x(x)
        , _y(y)
    {};

public:
    int _index;
    int _x;
    int _y;
    Node* _leftNode = nullptr;
    Node* _rightNode = nullptr;
};

void preOrder(Node* node, vector<int>& root)
{
    if (node == nullptr)
        return;

    root.push_back(node->_index);
    preOrder(node->_leftNode, root);
    preOrder(node->_rightNode, root);
}

void postOrder(Node* node, vector<int>& root)
{
    if (node == nullptr)
        return;

    postOrder(node->_leftNode, root);
    postOrder(node->_rightNode, root);
    root.push_back(node->_index);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) 
{
    vector<vector<int>> answer;

    //1. 노드를 Y가 큰 순서로 정렬 (같으면 x가 작은 순서)
    //노드 자료구조 생성 후 정렬
    vector<Node> tree;
    const int nodeSize = nodeinfo.size();
    tree.reserve(nodeSize);
    for (int index = 0; index < nodeSize; ++index)
        tree.emplace_back(index + 1, nodeinfo[index][0], nodeinfo[index][1]);

    sort(tree.begin(), tree.end(), [](const Node& rhs, const Node& lhs) -> bool {
        if (rhs._y == lhs._y)
            return rhs._x < lhs._x;

        return rhs._y > lhs._y;
    });

    //2. 트리노드 만들기
    Node& rootNode = tree.front();
    for (int index = 1; index < nodeSize; ++index)
    {
        Node* currentNode = &rootNode;
        Node* insertNode = &tree[index];
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

    //3. 전위순회
    vector<int> orderResult;
    orderResult.reserve(nodeSize);
    preOrder(&rootNode, orderResult);
    answer.push_back(orderResult);

    //4. 후위순회
    orderResult.clear();
    postOrder(&rootNode, orderResult);
    answer.push_back(orderResult);

    return answer;
}

int main()
{
    vector<vector<int>> nodeinfo;
    nodeinfo.push_back({ 5, 3 });
    nodeinfo.push_back({ 11,5 });
    nodeinfo.push_back({ 13,3 });
    nodeinfo.push_back({ 3,5 });
    nodeinfo.push_back({ 6,1 });
    nodeinfo.push_back({ 1,3 });
    nodeinfo.push_back({ 8,6 });
    nodeinfo.push_back({ 7,2 });
    nodeinfo.push_back({ 2,2 });

    solution(nodeinfo);
}