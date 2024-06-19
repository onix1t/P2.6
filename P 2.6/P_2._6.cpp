#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;

// --[ Задание 1 ]--

// Словарь для перевода
pair<string, string> dictionary[] = {
    {"Mother", "668437"},
    {"Father", "328437"},
    {"Son", "766"},
    {"Бабушка", "2226842"},
    {"Морковка", "55645242"},
    {"Улица", "64472"}
};
const int dictSize = sizeof(dictionary) / sizeof(dictionary[0]);

// Функция перевода чисел в слова и слов в числа
void translate(const string& input, bool numberToWord) {
    istringstream iss(input);
    string token;
    while (iss >> token) {
        for (int i = 0; i < dictSize; ++i) {
            if ((numberToWord && dictionary[i].second == token) ||
                (!numberToWord && dictionary[i].first == token)) {
                cout << (numberToWord ? dictionary[i].first : dictionary[i].second) << " ";
                break;
            }
        }
    }
    cout << "\r\n";
}

// --[ Задание 2 ]--

// Функция подсчётв хэша
string calculateHash(const string& word) {
    string hash = word;
    sort(hash.begin(), hash.end());
    return hash;
}

// Функция нахождения анаграмм
vector<string> findAnagrams(const string& target, const vector<string>& words) {
    string targetHash = calculateHash(target);
    vector<string> anagrams;
    for (const auto& word : words) {
        if (calculateHash(word) == targetHash) {
            anagrams.push_back(word);
        }
    }
    return anagrams;
}

// --[ Задание 3 ]--

// Функция нахождения дубликатов чисел в массиве 
void findDuplicates(const vector<int>& array) {
    set<int> seen, duplicates;
    for (int num : array) {
        if (!seen.insert(num).second) {
            duplicates.insert(num);
        }
    }
    if (duplicates.empty()) {
        cout << "Дубликатов нет.\r\n";
    } else {
        cout << "Найденные дубликаты: ";
        for (int num : duplicates) {
            cout << num << " ";
        }
        cout << "\r\n";
    }
}

// --[ Задание 4 ]--

//Функция нахождения дубликотов символов в строке
bool hasDuplicateChars(const string& str) {
    set<char> charSet;
    for (char c : str) {
        if (!charSet.insert(c).second) {
            return true;
        }
    }
    return false;
}

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Практика 6\r\n\r\n";
    
    cout << "Задание 1\r\n";
    int mode;
    cout << "Введите число (1 - перевод чисел в слова, 2 - перевод слов в числа): ";
    cin >> mode;
    cin.ignore();

    string input;
    cout << "Введите текст/число: ";
    getline(cin, input);

    if (mode == 1) {
        cout << "Текст из ваших цифр: ";
        translate(input, true);
    } else if (mode == 2) {
        cout << "Цифры из вашего текста: ";
        translate(input, false);
    } else {
        cout << "Ой! Что-то пошло не так :(\r\n";
    }

    cout << "Задание 2\r\n";
    string targetWord = "listen";
    vector<string> wordList = {"enlists", "google", "inlets", "banana"};

    vector<string> anagrams = findAnagrams(targetWord, wordList);

    cout << "Анаграммы слова " << targetWord << ": ";
    for (const auto& anagram : anagrams) {
        cout << anagram << " ";
    }
    cout << "\r\n";

    cout << "Задание 3\r\n";
    vector<int> array = {1, 2, 3, 4, 5, 2, 6, 7, 8, 5};

    findDuplicates(array);
    
    cout << "\r\n";

    cout << "Задание 4\r\n";
    string inputString;
    cout << "Введите строку: ";
    cin >> inputString;

    if (hasDuplicateChars(inputString)) {
        cout << "Строка имеет дубликаты символов.\r\n";
    } else {
        cout << "Строка не имеет дубликаты символов.\r\n";
    }

    return 0;
}
