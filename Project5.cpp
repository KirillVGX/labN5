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
        cout << "\nМеню:\n";
        cout << "1. Створити рахунок\n";
        cout << "2. Поповнити рахунок\n";
        cout << "3. Зняти гроші\n";
        cout << "4. Показати рахунки\n";
        cout << "5. Вийти\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        if (choice == 1) {
            Account acc;
            cout << "Введіть ім'я власника: ";
            cin >> acc.owner;
            cout << "Введіть номер рахунку: ";
            cin >> acc.accountNumber;
            acc.balance = 0;
            accounts.push_back(acc);
        } 
        else if (choice == 2) {
            int num;
            double sum;
            cout << "Введіть номер рахунку: ";
            cin >> num;
            cout << "Введіть суму: ";
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
            cout << "Введіть номер рахунку: ";
            cin >> num;
            cout << "Введіть суму: ";
            cin >> sum;
            for (auto& acc : accounts) {
                if (acc.accountNumber == num) {
                    if (acc.balance >= sum) acc.balance -= sum;
                    else cout << "Недостатньо коштів.\n";
                    break;
                }
            }
        } 
        else if (choice == 4) {
            for (const auto& acc : accounts) {
                cout << "Ім'я: " << acc.owner 
                     << ", Номер: " << acc.accountNumber 
                     << ", Баланс: " << acc.balance << "\n";
            }
        } 
        else if (choice == 5) {
            break;
        } 
        else {
            cout << "Некоректний вибір.\n";
        }
    }

    return 0;
}
