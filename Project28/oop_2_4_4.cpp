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

//����Լ�

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
        //���� ��带 curr, temp�� '���� ���'�� ����� next�� �ӽ� ����
        //curr�� ���� �� ��� �������� �Űܰ��鼭 ����

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
    char now_word[50]; //'����' �Է¹��� �ܾ�
    char prev_word[50] = { 0, }; //'�ٷ� ��' �Է��� �ܾ�
    int chained_time = 0;

    while (1)
    {
        cout << "CMD(Word/exit) >>";
        cin >> now_word;

        if (chained_time == 0 || now_word[0] == prev_word[strlen(prev_word) - 1] || now_word[0] + 32 == prev_word[strlen(prev_word) - 1] || now_word[0] == prev_word[strlen(prev_word) - 1] + 32)
        {// �� ó�� �Է� �� - ���� ���� �� - �Է� ������ �빮��, ������ �ҹ��� - �Է� ������ �ҹ���, ������ �빮�� 
            if (word_chain_game.searchInList(now_word) == 0)
            {
                word_chain_game.addNode(now_word);
                word_chain_game.DisplayList();
                strcpy_s(prev_word, now_word);

                chained_time++;
            } // �ܾ �� ���� �����ٸ� ���� ��忡 �־� �����ձ�
            else if (word_chain_game.searchInList(now_word) == 1)
            {
                cout << "Already Exitsts" << endl;
                word_chain_game.DisplayList();
            } // �̹� �ִ� �ܾ �Է��� ���
        }
        else if (_stricmp(now_word, "exit") == 0)
        {
            word_chain_game.~word_chain_game();
            break;
        }
        else //���� ���ϴ� �ܾ� �Է�
        {
            cout << "Not Chained" << endl;
            word_chain_game.DisplayList();
        }
    }

    return 0;
}