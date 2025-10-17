#include <initializer_list>
#include <iostream>
#include <cassert>

/**********************************************************************************
 * README 
 * ********************************************************************************
 * Starter code, skeleton of the Set and Node classes, from UWaterloo ECE 150 (Douglas Wilhelm Harder) Course
*/

class Set;
class Node;
std::ostream &operator<<( std::ostream &out, Set const &rhs );
 
  /////////////////////////////
 /// Set class declaration ///
/////////////////////////////
class Set {
  public:
    Set( std::initializer_list<int> initial_values );
   ~Set();
 
    // The instructions will describe exactly what to do
    Set( Set const &orig );
    Set( Set      &&orig );
 
    // The instructions will describe exactly what to do
    Set &operator=( Set const &orig );
    Set &operator=( Set      &&orig );
 
    // Size operations
    bool        empty() const;
    std::size_t size()  const;
 
    // Clear all items out of the set
    void clear();
 
    // Find the value item in the set
    //  - Return the address of the node if found,
    //    and nullptr otherwise.
    Node *find( int const &item ) const;
 
    // Insert the item into the set if it
    // is not already in the set.
    //  - Return 1 if the item is new,
    //    and 0 otherwise.
    std::size_t insert( int const &item );
 
    // Insert all the items in the array
    // from array[begin] to array[end - 1]
    // that are not already in the set.
    //  - Return the number of items inserted
    //    into the set.
    std::size_t insert( int         const array[],
                        std::size_t const begin,
                        std::size_t const end );
 
    // Remove the item from the set and
    // return the number of items removed.
    std::size_t erase( int const &item );
 
    // Move any items from 'other', whose values
    // do not appear in 'this', to 'this'
    // Leave any items that already appear
    // in 'this' and 'other' in 'other'. 
    std::size_t merge( Set &other );

 
    // Set operations
    Set &operator|=( Set const &other );
    Set &operator&=( Set const &other );
    Set &operator^=( Set const &other );
    Set &operator-=( Set const &other );
 
    Set operator|( Set const &other ) const;
    Set operator&( Set const &other ) const;
    Set operator^( Set const &other ) const;
    Set operator-( Set const &other ) const;
 
    // Returns 'true' if the 'other' set
    // is a subset of 'this' set; that is,
    // all entries in the 'other' set are
    // also in this set.
    bool operator<=( Set const &other ) const;
    bool operator>=( Set const &other ) const;
    bool operator<( Set const &other ) const;
    bool operator>( Set const &other ) const;
 
    bool operator==( Set const &other ) const;
    bool operator!=( Set const &other ) const;
   
  private:
    Node *p_head_;
    std::size_t set_size_;
 
  friend std::ostream &operator<<( std::ostream &out, Set const &rhs );
};


  ///////////////////////////////
 /// Node class declaration  ///
///////////////////////////////
class Node {
  public:
    Node( int new_value, Node *new_next );
    int   value() const;
    Node *next()  const;
 
  private:
    int   value_;
    Node *next_;

  // Allow any member function in the class
  // 'Set' to access or modify the member
  // variables of any instance of this class.
  friend class Set;
};

 
  ///////////////////////////////
 /// Node class Definition   ///
///////////////////////////////

// Node constructor
Node::Node( int new_value, Node *new_next ) {
  value_ = new_value;
  next_ = new_next;
}
 
int Node::value() const {
  return value_;
}

Node *Node::next() const {
  return next_;
}


  ///////////////////////////////
 /// Set class definition    ///
///////////////////////////////

// Initializing constructor
Set::Set( std::initializer_list<int> initial_values) {
  p_head_ = nullptr;
  set_size_ = 0;
  for (int const &value : initial_values){
    insert(value);
  }
}

// Destructor
Set::~Set() {
}
 
// Copy constructor
Set::Set( Set const &orig ) {
}

// Move constructor
Set::Set( Set &&orig ) {
}
 
// Copy assignment
Set &Set::operator=( Set const &orig ) {
  return *this;
}

// Move assignment
Set &Set::operator=( Set &&orig ) {
  return *this;
}
 
// Empty
bool Set::empty() const {
  return p_head_ == nullptr;
}

// Size
size_t Set::size() const {
  return set_size_;
}
 
 
// Clear
void Set::clear() {

}
 
// Find
Node *Set::find( int const &item ) const {
  Node *search {p_head_};
  while (search != nullptr){
    if (search -> value_ == item){
      return search;
    }
    search = search -> next_;
  }
  return nullptr;
}
 
// Insert the item into the set
std::size_t Set::insert( int const &item ) {
  if (!find(item)){
    Node *temp {new Node(item, p_head_)};
    p_head_ = temp;
    ++set_size_ ;
    return 1;
  }
  return 0;
}
 
// Insert all the items in the array
std::size_t Set::insert( int         const array[],
                         std::size_t const begin,
                         std::size_t const end ) {
  return 0;
}

 
// Remove the item from the set and
// return the number of items removed.
std::size_t Set::erase( int const &item ) {
  return 0;
}
 
// Move any items from 'other', whose values
// do not appear in 'this', to 'this'.
// Leave any items that already appear
// in both sets, in both sets. 
std::size_t Set::merge( Set &other ) {
  std::size_t count{ 0 };
  return 0;
}

  //////////////////////
 /// Set operations ///
//////////////////////
Set &Set::operator|=( Set const &other ) {
  return *this;
}
 
Set &Set::operator&=( Set const &other ) {
  return *this;
}
 
Set &Set::operator^=( Set const &other ) {
  return *this;
}
 
Set &Set::operator-=( Set const &other ) {
  return *this;
}
 
Set Set::operator|( Set const &other ) const {
  Set result{};
  return result;
}
 
Set Set::operator&( Set const &other ) const {
  Set result{};
  return result;
}
 
Set Set::operator^( Set const &other ) const {
  Set result{};
  return result;
}
 
Set Set::operator-( Set const &other ) const {
  Set result{};
  return result;
}
 
// Returns 'true' if the 'other' set
// is a subset of 'this' set; that is,
// all entries in the 'other' set are
// also in this set.
bool Set::operator>=( Set const &other ) const {
  return false;
}
 
bool Set::operator<=( Set const &other ) const {
  return false;
}
 
bool Set::operator>( Set const &other ) const {
  return false;
}
 
bool Set::operator<( Set const &other ) const {
  return false;
}
 
bool Set::operator==( Set const &other ) const {
  return false;
}
 
bool Set::operator!=( Set const &other ) const {
  return false;
}


  ////////////////////////////////////////////
 /// Supplied Code for print Set objects  ///
////////////////////////////////////////////
/// @brief Overloads the << operator allowing the print of Set objects
/// @param out The ostream to print to (e.g. std::cout <<)
/// @param rhs The Set to print (e.g. << set_A)
/// @note You do not need to edit or alter this code
std::ostream &operator<<( std::ostream &out, Set const &rhs ) {
  out << "{";
  if ( !rhs.empty() ) {
    out << rhs.p_head_->value();   
    for ( Node *ptr{ rhs.p_head_->next() }; ptr != nullptr; ptr = ptr->next() ) {
      out << ", " << ptr->value();
    }
  }
  out << "}";
 
  return out;
}