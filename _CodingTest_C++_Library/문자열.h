#pragma once
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <queue>
#include <string>
#include <vector>
#include <sstream>
#include <memory>

using namespace std;

void parsing(const string& data, vector<string>& result, const char delimiter = ' ')
{
	string token;
	stringstream splitStream(data);

	while (getline(splitStream, token, delimiter))
		result.push_back(token);
}

//Trie 자료구조 - 문자열이 있는지 확인하는 알고리즘
namespace std
{
    class Trie
    {
    public:
        struct Node
        {
            bool isFinish = false;
            unique_ptr<Node> childNodes[26];
        };

        Trie() {};

        void insertWord(string word);

    private:
        Node _rootNode;
    };

    void Trie::insertWord(string word)
    {
        int count = 0;
        Node* currentNode = &_rootNode;
        for (count; count < word.size(); ++count)
        {
            int alphabet = word[count] - 97;
            if (currentNode->childNodes[alphabet].get() == nullptr)
                currentNode->childNodes[alphabet] = make_unique<Node>();

            currentNode = currentNode->childNodes[alphabet].get();
        }

        currentNode->isFinish = true;
    }

    //int Trie::getFindCount(string word)
    //{
    //    int count = 0;
    //    Node* currentNode = &_rootNode;
    //    for (count; count < word.size(); ++count)
    //    {
    //        if (currentNode->childCount == 1)
    //            break;

    //        int alphabet = word[count] - 97;
    //        currentNode = currentNode->childNodes[alphabet].get();
    //    }

    //    return count;
    //}
}