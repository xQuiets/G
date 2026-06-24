#include <iostream>
#include <string>
using namespace std;

int main()
{
    system("chcp 1251");
    setlocale(LC_ALL, "");
    srand(time(0));
    int num = rand() % 998 + 1;
    cout << "Программа: угадай число.\n";
    cout << "Компьютер загадал число от 1 до 999. \n";
    cout << "Угадай его за минимальное число попыток. \n";
    cout << "Максимум 10 попыток!\n";
    int usernum = 0;
    int count = 0;
    string input;

    while (count < 10) {
        bool validInput = false;

        do {
            cout << "Введите число (осталось попыток: " << 10 - count << "): ";
            cin >> input;

            bool isNumber = true;
            for (int i = 0; i < input.length(); i++) {
                if (input[i] < '0' || input[i] > '9') {
                    isNumber = false;
                    break;
                }
            }

            if (!isNumber) {
                cout << "Ошибка! Введите число.\n";
                continue;
            }

            usernum = stoi(input);

            if (usernum < 1 || usernum > 999) {
                cout << "Число должно быть от 1 до 999.\n";
                continue;
            }

            validInput = true;

        } while (!validInput);

        count++;

        if (usernum > num) {
            cout << "Перелёт...\n";
        }
        else if (usernum < num) {
            cout << "Недолёт...\n";
        }
        else {
            cout << "Вы угадали число " << num << " за " << count << " попыток.\n";
            break;
        }
    }

    if (usernum != num) {
        cout << "\nПопытки закончились!\n";
        cout << "Было загадано число: " << num << "\n";
        cout << "Вы проиграли :(\n";
    }

    return 0;
}