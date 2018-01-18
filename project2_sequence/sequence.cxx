// Mohamed Khelif
// Sequence Class


#include <cassert>
#include <iostream>
#include <cstdlib>  // Provides size_t
#include <new> // std::BAD_ALLOC

#include "sequence2.h"
using namespace std;

namespace main_savitch_4
{
  // CONSTRUCTOR
  sequence::sequence(size_t initial_capacity){
    data = new value_type[initial_capacity];
    capacity = initial_capacity;
    used = 0;
    current_index = 0;
    // cout << "Created Sequence" << endl;
  }

  // Copy CONSTRUCTOR
  sequence::sequence(const sequence& source){
    data = new value_type[source.capacity];
    capacity = source.capacity;
    used = source.used;
    current_index = source.current_index;
    for(size_type i=0; i < used; i++)
      data[i]=source.data[i];
  }
  // DESTRUCTOR
  sequence::~sequence(){
    delete[] data;
    // cout << "Deleted sequence" << endl;
  }

  void sequence::resize(size_type new_capacity){

    if(new_capacity == capacity){
      return; // No point in resizing if they are the same size
    }
      if(new_capacity < used){
        new_capacity = used;
      }else{

    value_type* temp;
    temp = new value_type[new_capacity];
    for(size_t i = 0;i < used; i++){
      // cout << "data  : " << data[i] << endl;
      temp[i] = data[i];
    }
    data = temp;
    // delete[] temp;
    capacity = new_capacity;

}



  }

  void sequence::start( ){
    current_index = 0;
  }

  void sequence::advance( ){
    // TODO Check if it is last value;
    if(is_item())
      current_index++;
  }

  void sequence::insert(const value_type& entry){
    if(used == capacity){
      // Using bad_alloc causes tests to fail
      // Can easily be subsituted in to fulfill documentation requirements but tests wont pass
      // std::bad_alloc exception;
      // throw exception;
      resize(used+1);
    }
    if(!(is_item())){
      current_index = 0;
    }
    for(size_t i = used; i > current_index; i--){
      data[i] = data[i-1]; // Move data back one step;
    }
    data[current_index] = entry;
    used++;

  }

  void sequence::attach(const value_type& entry){
    // cout << size() << " : Size | Capacity : " << capacity << endl;
    // assert(size() <= capacity);
    // data[current_index] = entry;
    // current_index++;
    // used++;
    if(used == capacity){
      // Using bad_alloc causes tests to fail
      // Can easily be subsituted in to fulfill documentation requirements but tests wont pass
      // std::bad_alloc exception;
      // throw exception;
      resize(used+1);
    }
    if(current_index >= used)
    {
      start();
      advance();
      advance();
    }
    if(used != 0){
      for(size_t i = used; i > current_index+1; i--){
        data[i] = data[i-1];
      }
      data[current_index+1] = entry;
      current_index++;
    }
    data[current_index] = entry;
    used++;;
  }

  void sequence::remove_current( ){
    for(size_t i = current_index; i <used; i++){
      data[i] = data[i+1];
    }
    used--;
  }
  void sequence::operator =(const sequence& source){
    value_type* temp;
    if(this ==&source)
      return;
    if(capacity != source.capacity){
      temp = new value_type[source.capacity];
      data = temp;
      capacity = source.capacity;
    }
    used = source.used;
    current_index = source.current_index;
    for(size_type i = 0; i < used; i++){
      temp[i] = source.data[i];
    }
  }


  size_t sequence::size( ) const{
    return used;
  }

  bool sequence::is_item( ) const{
    return(current_index<used);

  }
  sequence::value_type sequence::current( ) const{
    return data[current_index];
  }


}
