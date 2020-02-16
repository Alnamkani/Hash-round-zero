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

int min_tuple(int size, int ar[], int max_tuple, int diff) {
    
    int total = 0;
    
    for (int i = 1; i < max_tuple; ++i) {
        
        total += ar[size - i];
        
        if (total >= diff) {
            return i;
        }
    }
    return max_tuple; //if you are here fuck me
} 

/* 
int what_to_remove(int size, int diff, int ar[], int max_tuple, int min_tuple)
{
    for () 
    {
        for (int i = 0; i < size; i++)
        {
            if (ar[i] == diff) {return i;}
            
        }
    }
} */


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
    int max_tuple_var = max_tuple(num_of_types, slices_per_type, diff);
    int min_tuple_var = min_tuple(num_of_types, slices_per_type, max_tuple_var, diff);
    cout << min_tuple_var << "    " << max_tuple_var << endl;
    //cout << max_tuple(num_of_types, slices_per_type, diff) << endl;

    delete [] slices_per_type;

  return 0;
}
