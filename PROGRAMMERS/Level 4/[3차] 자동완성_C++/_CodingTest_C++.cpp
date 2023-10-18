#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <queue>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Trie
{
public:
    struct Node
    {
        int childCount = 0;
        bool isFinish = false;
        unique_ptr<Node> childNodes[26];
    };

    Trie() {};

    void insertWord(string word);
    int getFindCount(string word);

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
        if(currentNode->childNodes[alphabet].get() == nullptr)
            currentNode->childNodes[alphabet] = make_unique<Node>();

        currentNode = currentNode->childNodes[alphabet].get();
        //특수
        {
            ++currentNode->childCount;
        }
    }

    currentNode->isFinish = true;
}

int Trie::getFindCount(string word)
{
    int count = 0;
    Node* currentNode = &_rootNode;
    for (count; count < word.size(); ++count)
    {
        if (currentNode->childCount == 1)
            break;

        int alphabet = word[count] - 97;
        currentNode = currentNode->childNodes[alphabet].get();
    }
    
    return count;
}

int solution(vector<string> words) 
{
    int answer = 0;
    Trie trie;
    for (const string& word : words)
        trie.insertWord(word);

    for (const string& word : words)
        answer += trie.getFindCount(word);

    return answer;
}

int main()
{
    //solution({ "go","gone","guild" });
    //solution({ "abc","def","ghi","jklm" });
    solution({ "word","war","warrior","worldz" });
}