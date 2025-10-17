#include <iostream>
#include <cassert> 

double *geometric(double a, double ratio, std::size_t cap){
    // returns the address of a dynamically allocated array of double that stores the values a, ar, ar^2, ar^3, up to ar^(n−1) 
    // where r is the ratio and n is the capacity of the array
    double *a_geometric{new double [cap]};

    for (std::size_t count{0}; count < cap; ++count){
        a_geometric[count] = a;
        a *= ratio;
    }
    return a_geometric;
}

double *cross_correlation(double array0[], std::size_t cap0, double array1[], std::size_t cap1){
    // will return a dynamically allocated array of capacity cap0 + cap1 - 1. With each entry of this new array
    // initialized to zero, you will then calculate each pair of products array0[i]*array1[j] and add this to the
    // result at index i + j. You may assert that cap0 + cap1 >= 1
    assert(cap0 + cap1 >= 1);
    double *a_cross{new double [cap0 + cap1 - 1]{0.0}};

    if (cap0 == 0 || cap1 == 0){
        return a_cross;
    }

    for (std::size_t i{0}; i < cap0; ++i){
        for (std::size_t j{0}; j < cap1; ++j){
            a_cross[i+j] += array0[i]*array1[j];
        }
    }

    return a_cross;
}

std::size_t shift_duplicates( int array[], std::size_t capacity ){
    // will move duplicate entries to the end of the array. The unique entries will be moved to the front of the array in the
    // same order that they first appear, while the duplicate entries will be moved to the end of the array, but the
    // order does not matter. The value returned will be the number of unique entries.
    std::size_t i {1};
    // starts at index 1, since index 0 will never be a "duplicate"
    unsigned int duplicates{0};

    while ((i+duplicates) < capacity){
        // i + duplicates is how many values have been checked
        for (std::size_t before{i-1}; before >= 0; --before){
            if (array[before] == array[i]){
                // found a duplicate to the left, at index i 
                int temp = array[i];
                for (std::size_t m{i+1}; m < capacity; ++m){
                    // shifts everything to the right of the duplicate to the left
                    array[m-1] = array[m];
                }
                array[capacity-1] = temp;
                // puts the duplicate number at the end of the array 
                ++duplicates;
                break;
            } else{
                if (before == 0){
                // reached the first element and didn't find it as a duplicate...
                ++i;
                break;
                }   
            }
        }
    }
    
    return capacity-duplicates;
    // equal to i...?
}

void deallocate( double *&ptr, bool is_array, std::size_t capacity = 0){  
    // double *&ptr - interpret by reading in reverse:
    // ptr is a reference (&) to a pointer (*) that points to a double 
    // & allows us to modify the pointer 

    // std::size_t capacity = 0 sets the default to the 0 if the capacity is not given >:(

    // 1. If is_array is true, then you will loop through the array setting each entry to zero. The third argument
    // will contain the capacity of the array. You will then deallocate that memory.
    // 2. Otherwise, it is not an array, so it is just a pointer to one instance of type double. You will set that
    // entry to zero and the third argument will be ignored. In both cases, the last action you will take is to set ptr to nullpt

    if (is_array){
        for (std::size_t i{0}; i < capacity; ++i){
            ptr[i] = 0;
        }
        delete[] ptr;
        // deallocates memory for an array 
        // (without it, only the first element would be deallocated -> leaks)
    } else {
        *ptr = 0;
        // * dereferences ptr so we can access the value it points to
        delete ptr;
    }
    ptr = nullptr;
    // removes dangling pointer 
}