#include <iostream>

using namespace std;

int main() {
    char name[12];
    char std_id[20];
    char major[12];

    cout << "�̸� : ";
    cin >> name;
    cout << "�й� : ";
    cin >> std_id;
    cout << "���� : ";
    cin >> major;

    cout << name << " " << std_id << " " << major << endl;

    return 0;
}