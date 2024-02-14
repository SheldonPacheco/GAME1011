#include <cstring>
#include <iostream>

using namespace std;

class ArrayExample 
{
    private:
        int* m_nums = 0;
        int m_size = 0;
    public:
        ArrayExample(int size) {

            m_size = size;
            m_nums = new int[m_size];
        }
        //Copy Constructor, as it takes in the same class
        ArrayExample(const ArrayExample& arrayExample) {
            m_size = arrayExample.m_size;
            m_nums = new int[m_size];
            for (int ctr = 0; ctr < m_size; ctr++) {
                m_nums[ctr] = arrayExample.m_nums[ctr];
            }
        }
        ~ArrayExample() {
            delete[] m_nums;
        }
        void SetNum(int index, int value) {
            m_nums[index] = value;
        }
        int GetNum(int index) {
            return m_nums[index];
        }
        void PrintArray() {
            for (int ctr = 0; ctr < m_size; ctr++) {
                cout << m_nums[ctr] << ", ";
            }
            cout << "\n";
        }
};

int main()
{
    ArrayExample ex1(10);
    for (int i = 0; i < 10; i++) {
        ex1.SetNum(i, i);
    }
    ex1.PrintArray();
    ArrayExample ex2 = ex1;
    ex2.PrintArray();
    for (int i = 0; i < 10; i++) {
        ex1.SetNum(i, i*2);
    }
    ex1.PrintArray();
    ex2.PrintArray();
    return 0;
}
