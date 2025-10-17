#include "string_header.hpp"

std::size_t length( char const *a ){
    // length returns the length of string a
    unsigned int len {0};
    
    while (a[len] != '\0' ){
        ++len;
    }

    return len;
}

int compare( char const *str1, char const *str2 ){
    // compare returns if str1 comes later (return 1), earlier (return -1), or is the same (return 0) as str2 in the dictionary
    std::size_t k {0};
    while (true){
        if ((str1[k] == '\0') && (str2[k] == '\0')){
            // same length and same previous -> same strings
            return 0;
        } else if (str1[k] == '\0'){
            // first word is 'prefix' of second word
            return -1;
        } else if (str2[k] == '\0'){
            // second word is 'prefix' of first word
            return 1;
        } else if(str1[k] > str2[k]){
            // letter in first word is later alphabetically than letter in second word (same position)
            return 1;
        } else if (str1[k] < str2[k]){
            // letter in first word is earlier alphabetically than letter in second word (same position)
            return -1;
        } else {
            // letters are still the same therefore increments to next letter 
            ++k;
        }
    }
} 

void assign( char *str1, char const *str2 ){
    // assign performs the overwriting of the characters at str1 with the characters of str2, so that following this
    // operation, both strings up to and including the null character are the same

    for (std::size_t k{0}; k < 21; ++k){
        str1[k] = str2[k];
        if (str2[k] == '\0'){
            return;
        }
    }
}

unsigned int distance( char const *str1, char const *str2 ){
    //calculates the edit distance between the two strings. That is, the minimum number of insertions of a character, changing a
    //character, or deleting a character that are required to convert one string into the other. 

    if (*str1 == '\0'){
        return length(str2);
    } 
    if (*str2 == '\0'){
        return length(str1);
    } 
    if (str1[0] == str2[0]){
        return distance(str1+1, str2+1);
    }
    else{
        return 1 + std::min({distance(str1+1, str2+1), distance(str1+1, str2), distance(str1, str2+1)});
        // add comments here
    }
}

std::size_t is_sorted( char *array[], std::size_t capacity ){
    // The first array function std::size_t is_sorted( char *array[], std::size_t capacity ) will return
    // capacity if the strings in the array follow a dictionary ordering. The return value
    // is the index of the first entry that is less than the previous entry, or equal to capacity
    // if the array is sorted.
    
    for (std::size_t ind{0}; ind < (capacity-1); ++ind){
        if (compare(array[ind], array[ind+1]) > 0){
            return ind+1;
        }
    }
    return capacity;
        
}

void insert( char *array[], std::size_t capacity ){
    // insert assumes the first
    // capacity - 1 entries of the array are sorted and then inserts the entry at capacity - 1 into the correct
    // location in the array, moving any string that appears after it in the dictionary to the right by one location.

    char value[21];
    assign(value, array[capacity-1]);

    for (std::size_t ind{0}; ind < capacity; ++ind){
        if (compare(array[ind], value) >= 0){
            for (std::size_t shift{capacity-1}; shift > ind; --shift){
                assign(array[shift], array[shift-1]);
            }
            assign(array[ind], value);
            return;
        }
    }

}

void insertion_sort( char *array[], std::size_t capacity ){
    
    //recursive implementation
    if (capacity <= 1){
        // base case: has reached the first term 
        return;
    } else {
        insertion_sort(array, capacity-1);
        insert(array, capacity);
    }

}

std::size_t remove_duplicates( char *array[], std::size_t capacity ){
    // remove_duplicates assumes that the array is sorted and removes duplicate entries by shifting all unique strings 
    // to the left filling in any gaps left by the duplicate entries. The value returned is the number of unique entries.

    std::size_t dup{0};

    for (std::size_t ind{0}; ind < (capacity-1); ++ind){ 
        if (compare(array[ind], array[ind+1]) == 0){
            ++dup;
            for(std::size_t shift{ind+1}; shift < (capacity-1); ++shift){
                assign(array[shift], array[shift+1]);
            }
            assign(array[capacity-1], "\0");
        }
    }
    return capacity-dup;
}

std::size_t find( char *array[], std::size_t capacity, char const *str){
    // find walks through the array. If it finds the string str, it returns the index where the string was found. If the
    // string is not in the array, it returns the index of the first entry of the array that has the smallest distance (as
    // defined by the above distance(...) function). If there are multiple entries, only the first index is returned

    std::size_t min_dis {distance(array[0], str)};
    std::size_t min_dis_ind{0};

    for (std::size_t ind{0}; ind < capacity; ++ind){ 
        if (compare(array[ind], str) == 0){
            // if the string is found, return index 
            return ind;
        } else {
            // check if it is smallest distance from string
            if (distance(array[ind], str) < min_dis){
                min_dis = distance(array[ind], str);
                min_dis_ind = ind; 
            }
        }
    }
    return min_dis_ind;
}

void free_word_array( char** word_array ){
    //free_word_array deallocates the memory allocated for the array of character arrays by the 
    //read_words_from_file(...) function by calling delete[] word_array[0] and then delete[] word_array

    delete [] word_array[0]; // array with contiguous list of all words
    delete [] word_array; // array with pointers to each word

    word_array = nullptr;

}