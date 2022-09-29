# include <iostream>

using namespace std;

class Node 
{ 
public: 
    double data; 
    Node* next;
};
                  
 class List 
 {
 public:
     List(void) { head = NULL; }
     ~List(void);
     bool IsEmpty() { return head == NULL; }
     Node* InsertNode(int idx, double x);
     void FindNode(double x);
     int DeleteNode(double x);
     void DisplayList(void);
 private:
     Node* head;
};
 
 Node * List::InsertNode(int index, double x)
 {
     if (index < 0) 
     {
         return NULL; 
     }
     
     int currIndex = 1;
     Node* currNode = head;
    
     while (currNode && index > currIndex)
     {
         currNode = currNode->next;
         currIndex++;
     }
                   
     if (index > 0 && currNode == NULL)
     {
         return NULL;
     }//node�� ��ġ
     
     Node* newNode = new Node;
     newNode->data = x;    //���Խ�ų ���ο� ��带 ������

     if (index == 0)
     {
         newNode->next = head;
         head = newNode;
     }
     else
     {
         newNode->next = currNode->next;
         currNode->next = newNode;
     }    //�ƹ��͵� ���� �� ó������ ����, �ִٸ� �� ���� ��ġ�� ����
                         
     return newNode;
}

 void List::FindNode(double x)
 {
     Node* currNode = head;
     int currIndex = 1;

     while (currNode != NULL)
     {
         if (currNode->data == x)
         {
             cout << "Found Index: " << currIndex << endl;
         }
         currNode = currNode->next;
         currIndex++;
     }
 }

 int List::DeleteNode(double x) 
 {
     Node* prevNode = NULL;
     Node* currNode = head;
     int currIndex = 1;
    
     while (currNode && currNode->data != x) 
     {
         prevNode = currNode;
         currNode = currNode->next;
         currIndex++;
     }

     if (currNode) 
     {
         if (prevNode) 
         {
              prevNode->next = currNode->next;
              delete currNode;
         }
         else 
         {
             head = currNode->next;
             delete currNode;
         }
         return currIndex;
     }
     return 0;
 }

 void List::DisplayList()
 {
     int num = 0;
     Node* currNode = head;

     while (currNode != NULL)      //������ ��� �������� while�� ����
     {
         cout << currNode->data << endl;
         currNode = currNode->next;
         num++;
     }

     cout << "Number of nodes in the list :" << num << endl;
 }

List::~List()
{
    Node* currNode = head, * nextNode = NULL;

    while (currNode != NULL) 
    {
        nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    }     // head ���� ������ ����ؼ� �� ���� �Űܰ��鼭 currNode�� �������� ��
}

int main()
{
    char cmd[20];
    int a = 0, index = 0;
    Node* head, tail;
    List sdList; 

    while(1)
    {
        cout << "Please Enter Command(1: insert, 2: find, 3: delete, 4: print, 5: quit) :";
        cin >> cmd;

        if (cmd[0] == 'i')
        {
            cin >> a;
            sdList.InsertNode(index, a);
            index++;
        }
        else if (cmd[0] == 'f')
        {
            cin >> a;
            sdList.FindNode(a);
        }
        else if (cmd[0] == 'd')
        {
            cin >> a;
            sdList.DeleteNode(a);
        }
        else if (cmd[0] == 'p')
        {
            sdList.DisplayList();
        }
        else if (cmd[0] == 'q')
        {
            break;
        }
        else
        {
            cout << "Invalid Command";
        }
        cout << endl;
    }

    return 0;
}