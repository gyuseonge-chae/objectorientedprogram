#include <iostream>

using namespace std;

int main() {
    char name[12];
    char std_id[20];
    char major[12];

    cout << "이름 : ";
    cin >> name;
    cout << "학번 : ";
    cin >> std_id;
    cout << "전공 : ";
    cin >> major;

    cout << name << " " << std_id << " " << major << endl;

    return 0;
}