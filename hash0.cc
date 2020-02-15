#include <iostream>
using namespace std;

int sum(int size, int ar[]) {
    int s = 0;
    for (int i = 0; i < size; ++i) {
        s += ar[i];
    }
    return s;
}

int max_tuple(int size, int ar[], int diff) {
    int total = 0;
    for (int i = 0; i < size; ++i) {
        total += ar[i];
        if (total > diff) {
            return i;
        }
    }
    return -1;
}


int main()
{
    int max_wanted_slices = 0;  
    cin >> max_wanted_slices;

    int num_of_types = 0;  
    cin >> num_of_types;

    int* slices_per_type = new int [num_of_types * sizeof(int)];

    for (int i = 0; i < num_of_types; i++) {
        cin >> slices_per_type[i];
    }

    int diff = sum(num_of_types, slices_per_type) - max_wanted_slices;

    cout << max_tuple(num_of_types, slices_per_type, diff) << endl;


  return 0;
}
