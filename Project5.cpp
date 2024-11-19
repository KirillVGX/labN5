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
        cout << "1. Создать счет\n";
        cout << "2. Пополнить счет\n";
        cout << "3. Снять деньги\n";
        cout << "4. Показать счета\n";
        cout << "5. Выйти\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        if (choice == 1) {
            Account acc;
            cout << "Введите имя владельца: ";
            cin >> acc.owner;
            cout << "Введите номер счета: ";
            cin >> acc.accountNumber;
            acc.balance = 0;
            accounts.push_back(acc);
        }
        else if (choice == 2) {
            int num;
            double sum;
            cout << "Введите номер счета: ";
            cin >> num;
            cout << "Введите сумму: ";
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
            cout << "Введите номер счета: ";
            cin >> num;
            cout << "Введите сумму: ";
            cin >> sum;
            for (auto& acc : accounts) {
                if (acc.accountNumber == num) {
                    if (acc.balance >= sum) acc.balance -= sum;
                    else cout << "Недостаточно средств.\n";
                    break;
                }
            }
        }
        else if (choice == 4) {
            for (const auto& acc : accounts) {
                cout << "Имя: " << acc.owner
                    << ", Номер: " << acc.accountNumber
                    << ", Баланс: " << acc.balance << "\n";
            }
        }
        else if (choice == 5) {
            break;
        }
        else {
            cout << "Некорректный выбор.\n";
        }
    }

    return 0;
}