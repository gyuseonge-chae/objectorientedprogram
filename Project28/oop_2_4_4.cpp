#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
    char word[50] = { 0, };
    Node* next;
};

class wordList
{
public:
    wordList(void);
    ~wordList(void);
    void addNode(char* arr);
    int searchInList(char* arr);
    void DisplayList(void);
private:
    Node* head;
    Node* tail;
};

//멤버함수

wordList::wordList()
{
    head = NULL;
    tail = NULL;
}

wordList::~wordList()
{
    if (head != NULL)
    {
        Node* curr = head;
        Node* temp_next;

        while (curr != NULL)
        {
            temp_next = curr->next;
            delete curr;
            curr = temp_next;
        } 
        //현재 노드를 curr, temp에 '현재 노드'에 저장된 next를 임시 보관
        //curr을 해제 후 계속 다음으로 옮겨가면서 해제

        head = NULL;
        tail = NULL;
    }
}

void wordList::addNode(char* arr)
{
    if (head != NULL)
    {
        tail->next = new Node;
        tail = tail->next;
    }
    else
    {
        head = new Node;
        tail = head;
    }
    strcpy_s(tail->word, arr);
    tail->next = NULL;
}

int wordList::searchInList(char* arr)
{
    Node* currNode = head;

    while (currNode != NULL)
    {
        if (_stricmp(currNode->word, arr) != 0)
        {
            currNode = currNode->next;
            return 0;
        }
        else
        {
            while(currNode != NULL)
            {
                currNode = currNode->next;
            }
            return 1;
        }
    }
}

void wordList::DisplayList()
{
    Node* currNode = head;

    while (currNode != NULL)
    {
        cout << currNode->word << "->";
        currNode = currNode->next;
    }

    cout << endl;
}

int main()
{
    wordList word_chain_game;
    char now_word[50]; //'지금' 입력받은 단어
    char prev_word[50] = { 0, }; //'바로 전' 입력한 단어
    int chained_time = 0;

    while (1)
    {
        cout << "CMD(Word/exit) >>";
        cin >> now_word;

        if (chained_time == 0 || now_word[0] == prev_word[strlen(prev_word) - 1] || now_word[0] + 32 == prev_word[strlen(prev_word) - 1] || now_word[0] == prev_word[strlen(prev_word) - 1] + 32)
        {// 맨 처음 입력 시 - 완전 같은 때 - 입력 받은게 대문자, 이전은 소문자 - 입력 받은게 소문자, 이전에 대문자 
            if (word_chain_game.searchInList(now_word) == 0)
            {
                word_chain_game.addNode(now_word);
                word_chain_game.DisplayList();
                strcpy_s(prev_word, now_word);

                chained_time++;
            } // 단어가 그 동안 없었다면 다음 노드에 넣어 끝말잇기
            else if (word_chain_game.searchInList(now_word) == 1)
            {
                cout << "Already Exitsts" << endl;
                word_chain_game.DisplayList();
            } // 이미 있는 단어를 입력한 경우
        }
        else if (_stricmp(now_word, "exit") == 0)
        {
            word_chain_game.~word_chain_game();
            break;
        }
        else //잇지 못하는 단어 입력
        {
            cout << "Not Chained" << endl;
            word_chain_game.DisplayList();
        }
    }

    return 0;
}