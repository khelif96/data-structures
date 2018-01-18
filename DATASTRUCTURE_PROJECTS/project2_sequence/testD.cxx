#include<cassert>
#include"sequence2.h"
#include<algorithm>

namespace main_savitch_4
{
const sequence::size_type sequence::DEFAULT_CAPACITY;


sequence::sequence(size_type initial_capacity)
{
	data = new value_type[initial_capacity];
	capacity = initial_capacity;
	used = 0;
	current_index = 0;
}


sequence::sequence(const sequence& source)
{
    data = new value_type[source.capacity];
    capacity = source.capacity;
    used = source.used;
    current_index = source.current_index;
	 for(size_type i=0; i < used; i++)
		data[i]=source.data[i];
    //copy(source.data, source.data + used, data);
}

sequence::~sequence()
{
	//delete [] data;
}

void sequence::start( )
{
	current_index = 0;
}

void sequence::advance( )
{
	if(is_item())
		current_index++;
}

void sequence::insert(const value_type& entry)
{
    if(used == capacity)
        resize(used+1);

    if(!(is_item()))
        current_index = 0;

    for(size_type i = used; i > current_index; i--)
    {
        data[i] = data[i-1];
    }
    data[current_index] = entry;
    ++used;
}

void sequence::attach(const value_type& entry)
{
    if(used == capacity)
        resize(used+1);

    if(current_index >= used)
    {
        start();
        advance();
        advance();
    }
    if(used!=0)
    {
        for(size_type i = used; i > current_index+1; i--)
        {
            data[i] = data[i-1];
        }
        data[current_index+1] = entry;
        current_index++;
    }

    data[current_index] = entry;
    ++used;
}

void sequence::remove_current( )
{

	for(size_type i = current_index; i < used; i++)
	{
		data[i] = data[i+1];
	}
	used--;

}

void sequence::resize (size_type new_capacity)
{

    value_type* larger_array;
	if(new_capacity == capacity)
	   {return;}
    if(new_capacity < used)
        new_capacity = used;
   else
	{
    larger_array = new value_type[new_capacity];
	 //delete [] data;
	 //copy(data, data + used, larger_array);
    for(size_type i=0; i < used; i++)
      larger_array[i]=data[i];
	 data = larger_array;
    capacity = new_capacity;
	  }
}



void sequence::operator = (const sequence& source)
{
	value_type* new_data;

	if (this == &source)
		return;

	if(capacity != source.capacity)
	{
		new_data = new value_type[source.capacity];

		//delete [] data;
		data = new_data;
		capacity = source.capacity;
	}
	used = source.used;
	current_index = source.current_index;
//	copy(source.data, source.data + used, data);
for(size_type i=0; i < used;i++)
		new_data[i]=source.data[i];
}

sequence::size_type sequence::size() const
{
	return used;
}

bool sequence::is_item( ) const
{
return(current_index < used);
}

sequence::value_type sequence::current() const
{
	return data[current_index];
}




}
