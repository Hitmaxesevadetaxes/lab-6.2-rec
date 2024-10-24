#include <iostream>
#include <iomanip> // ��� ������������� ���������
#include <cstdlib> // ��� rand() �� srand()
#include <ctime>   // ��� time()
#include <climits> // ��� INT_MAX

// ������� ��� ��������� ���������� ����� � �����
void generateArray(int arr[], int size, int lowerBound, int upperBound) {
    for (int i = 0; i < size; ++i) {
        arr[i] = lowerBound + rand() % (upperBound - lowerBound + 1);
    }
}

// ������� ��� ��������� ������
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << std::setw(4) << arr[i];
    }
    std::cout << std::endl;
}

// ���������� ������� ��� ����������� ������� ���������� ��������� ��������
int findMinOddIndexRecursive(const int arr[], int size, int index = 0, int minOddValue = INT_MAX, int minOddIndex = -1) {
    // ������� �������
    if (index == size) {
        return minOddIndex; // ��������� ��������� ������
    }

    // ����������, �� �������� ������� �������� � ������ �� �������� �����
    if (arr[index] % 2 != 0 && arr[index] < minOddValue) {
        minOddValue = arr[index];
        minOddIndex = index;
    }

    // ����������� ������ ��� ���������� ��������
    return findMinOddIndexRecursive(arr, size, index + 1, minOddValue, minOddIndex);
}

// ������� ��� ���� ������ (����� ���������� ��������� ����� �� 0)
void modifyArray(int arr[], int size, int index) {
    if (index != -1) {
        arr[index] = 0; // ����� ���������� ��������� �������� �� 0
    }
}

int main() {
    const int size = 10; // ����� ������
    int arr[size];

    // ����������� ���������� ���������� �����
    srand(static_cast<unsigned>(time(0)));

    // �������� �����
    generateArray(arr, size, -10, 35);

    // �������� ������������ �����
    std::cout << "���������� �����:\n";
    printArray(arr, size);

    // ��������� ������ ���������� ��������� �������� ����������
    int minOddIndex = findMinOddIndexRecursive(arr, size);

    // �������� ������ � �������� ���������� ��������� ��������, ���� �� ���������
    if (minOddIndex != -1) {
        std::cout << "������ ���������� ��������� ��������: " << minOddIndex << std::endl;
        std::cout << "�������� ���������� ��������� ��������: " << arr[minOddIndex] << std::endl;
    }
    else {
        std::cout << "��������� �������� ������� �� ��������.\n";
    }

    // ���������� �����, ���� ��������� �������� �������
    modifyArray(arr, size, minOddIndex);

    // �������� ������������� ����� (���� �������)
    std::cout << "������� �����:\n";
    printArray(arr, size);

    return 0;
}
