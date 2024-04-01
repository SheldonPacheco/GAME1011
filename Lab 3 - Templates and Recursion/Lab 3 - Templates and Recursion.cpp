#include <iostream>
#include <vector>
#include <utility>

using namespace std;

template<typename T>
int LinearSearch(const vector<T>& arr, const T& value) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

template<typename T>
int BinarySearch(const vector<T>& arr, const T& value) {
    int first = 0;
    int last = arr.size() - 1;
    while (first <= last) {
        int middle = first + (last - first) / 2;
        if (arr[middle] == value) {
            return middle;
        }
        if (arr[middle] < value) {
            first = middle + 1;
        }
        else {
            last = middle - 1;
        }
    }
    return -1;
}

template<typename T, typename Comparator>
void Sort(vector<T>& A, Comparator comp) {
    int n = A.size();
    for (int i = 1; i < n; ++i) {
        int j = i;
        while (j > 0 && comp(A[j], A[j - 1])) {
            swap(A[j], A[j - 1]);
            --j;
        }
    }
}
void Search(const vector<int>& numbers) {
    int choice = 0;
    while (true) {
        cout << "Enter number you want to search for (-1 to exit): ";
        cin >> choice;
        if (LinearSearch(numbers, choice) != -1 && BinarySearch(numbers, choice) != -1) {
            cout << "Found at index: " << LinearSearch(numbers, choice) << "\n";
            cout << "Found at index: " << BinarySearch(numbers, choice) << "\n";
        }
        else {
            cout << "number not found" << "\n";
        }
        if (choice == -1) {
            break;
        }
    }
}
int main() {

    vector<int> numbers = { 4, 2, 7, 1, 9, 3, 6, 10, 0, 8, 1, 29, 53 };
    cout << "Unsorted array: ";
    for (int number : numbers) {
        cout << number << " ";
    }
    cout << "\n";
    Sort(numbers, less<int>());
    cout << "Sorted array: ";
    for (int number : numbers) {
        cout << number << " ";
    }
    cout << "\n";

    Search(numbers);


    return 0;
}
