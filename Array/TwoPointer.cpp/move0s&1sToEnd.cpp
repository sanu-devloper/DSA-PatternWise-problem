#include <iostream>
#include <vector>

using namespace std;

void segregate0and1(vector<int> &arr) {
    int i = 0;
    int j = arr.size() - 1;

    while (i < j) {

        if (arr[i] == 0) {
            i++;
        }
        else if (arr[j] == 1) {
            j--;
        }
        else {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
}

int main() {

    vector<int> arr = {1, 0, 1, 0, 1, 0, 0, 1, 1, 0};

    cout << "Before segregation:\n";

    for (int num : arr) {
        cout << num << " ";
    }

    cout << endl;

    segregate0and1(arr);

    cout << "\nAfter segregation:\n";

    for (int num : arr) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}