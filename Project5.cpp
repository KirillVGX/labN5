#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Account {
    string owner;
    int accountNumber;
    double balance;
};

int main() {
    vector<Account> accounts;
    int choice;

    while (true) {
        cout << "\n����:\n";
        cout << "1. ������� ����\n";
        cout << "2. ��������� ����\n";
        cout << "3. ����� ������\n";
        cout << "4. �������� �����\n";
        cout << "5. �����\n";
        cout << "��� �����: ";
        cin >> choice;

        if (choice == 1) {
            Account acc;
            cout << "������� ��� ���������: ";
            cin >> acc.owner;
            cout << "������� ����� �����: ";
            cin >> acc.accountNumber;
            acc.balance = 0;
            accounts.push_back(acc);
        }
        else if (choice == 2) {
            int num;
            double sum;
            cout << "������� ����� �����: ";
            cin >> num;
            cout << "������� �����: ";
            cin >> sum;
            for (auto& acc : accounts) {
                if (acc.accountNumber == num) {
                    acc.balance += sum;
                    break;
                }
            }
        }
        else if (choice == 3) {
            int num;
            double sum;
            cout << "������� ����� �����: ";
            cin >> num;
            cout << "������� �����: ";
            cin >> sum;
            for (auto& acc : accounts) {
                if (acc.accountNumber == num) {
                    if (acc.balance >= sum) acc.balance -= sum;
                    else cout << "������������ �������.\n";
                    break;
                }
            }
        }
        else if (choice == 4) {
            for (const auto& acc : accounts) {
                cout << "���: " << acc.owner
                    << ", �����: " << acc.accountNumber
                    << ", ������: " << acc.balance << "\n";
            }
        }
        else if (choice == 5) {
            break;
        }
        else {
            cout << "������������ �����.\n";
        }
    }

    return 0;
}