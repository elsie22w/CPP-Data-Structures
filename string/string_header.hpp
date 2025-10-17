#ifndef STRING
#define STRING

#include <iostream>
#include <cassert>
#include <algorithm>

int main();
void read_words_from_file(                                                      
    char const *filename,
    char **&work_array,
    std::size_t &numwords,
    std::size_t max_length
);

std::size_t     length( char const *a );                                        
int             compare( char const *str1, char const *str2 );                  
void            assign( char *str1, char const *str2 );                         
unsigned int    distance( char const *str1, char const *str2 );                 
std::size_t     is_sorted( char *array[], std::size_t capacity );               
void            insert( char *array[], std::size_t capacity );                  
void            insertion_sort( char *array[], std::size_t capacity );          
std::size_t     remove_duplicates( char *array[], std::size_t capacity );       
std::size_t     find( char *array[], std::size_t capacity, char const *str);    
void            free_word_array( char** word_array );                           

#endif