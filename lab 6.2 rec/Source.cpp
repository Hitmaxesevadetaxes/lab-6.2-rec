#include <iostream>
#include <iomanip> // для форматованого виведення
#include <cstdlib> // для rand() та srand()
#include <ctime>   // для time()
#include <climits> // для INT_MAX

// Функція для генерації випадкових чисел у масиві
void generateArray(int arr[], int size, int lowerBound, int upperBound) {
    for (int i = 0; i < size; ++i) {
        arr[i] = lowerBound + rand() % (upperBound - lowerBound + 1);
    }
}

// Функція для виведення масиву
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << std::setw(4) << arr[i];
    }
    std::cout << std::endl;
}

// Рекурсивна функція для знаходження індексу найменшого непарного елемента
int findMinOddIndexRecursive(const int arr[], int size, int index = 0, int minOddValue = INT_MAX, int minOddIndex = -1) {
    // Базовий випадок
    if (index == size) {
        return minOddIndex; // Повертаємо знайдений індекс
    }

    // Перевіряємо, чи поточний елемент непарний і менший за поточний мінімум
    if (arr[index] % 2 != 0 && arr[index] < minOddValue) {
        minOddValue = arr[index];
        minOddIndex = index;
    }

    // Рекурсивний виклик для наступного елемента
    return findMinOddIndexRecursive(arr, size, index + 1, minOddValue, minOddIndex);
}

// Функція для зміни масиву (заміна найменшого непарного числа на 0)
void modifyArray(int arr[], int size, int index) {
    if (index != -1) {
        arr[index] = 0; // Заміна найменшого непарного елемента на 0
    }
}

int main() {
    const int size = 10; // Розмір масиву
    int arr[size];

    // Ініціалізація генератора випадкових чисел
    srand(static_cast<unsigned>(time(0)));

    // Генеруємо масив
    generateArray(arr, size, -10, 35);

    // Виводимо згенерований масив
    std::cout << "Початковий масив:\n";
    printArray(arr, size);

    // Знаходимо індекс найменшого непарного елемента рекурсивно
    int minOddIndex = findMinOddIndexRecursive(arr, size);

    // Виводимо індекс і значення найменшого непарного елемента, якщо він знайдений
    if (minOddIndex != -1) {
        std::cout << "Індекс найменшого непарного елемента: " << minOddIndex << std::endl;
        std::cout << "Значення найменшого непарного елемента: " << arr[minOddIndex] << std::endl;
    }
    else {
        std::cout << "Найменший непарний елемент не знайдено.\n";
    }

    // Модифікуємо масив, якщо знайдений непарний елемент
    modifyArray(arr, size, minOddIndex);

    // Виводимо модифікований масив (якщо змінений)
    std::cout << "Змінений масив:\n";
    printArray(arr, size);

    return 0;
}
