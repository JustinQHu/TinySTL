#pragma once

#include<memory>
#include<cmath>
#include<stdexcept>


	
namespace tiny
{

	typedef unsigned long long    size_type;



//iterator class



	//pre-declaration, needed in friend declaraion
	template<typename T> class vector;
	template<typename T> class Iterator;
	template<typename T> Iterator<T>& operator+(Iterator<T> & iv, size_type  pos);
	template<typename T> bool operator==(Iterator<T> & iv1, Iterator<T> & iv2);
	template<typename T> bool operator!= (Iterator<T> & iv1, Iterator<T> & iv2);
    



	template<class T>
	class Iterator
	{
		 friend  Iterator& operator+<T>(Iterator& iv, size_type  pos);
		 friend  bool operator==<T>(Iterator& iv1, Iterator& iv2);
		 friend  bool operator!=<T>(Iterator& iv1, Iterator& iv2);
		 friend class vector<T>;

	public:
		//default constructor
		Iterator(T* pTemp = 0) :pIterator(pTemp) {}

		//copy constructor
		Iterator(const Iterator & iv) :pIterator(iv.pIterator) {}

		//assign operation 
		Iterator& operator= (const Iterator & iv)
		{
			pIterator = iv.pIterator;
			return *this;
		}


		//operator ++
		Iterator & operator++()
		{
			++pIterator;
			return *this;
		}


		//operator+
		Iterator& operator+(size_type pos)
		{
			pIterator += pos;
			return *this;
		}

		//operator-
		Iterator& operator-(size_type pos)
		{
			pIterator -= pos;
			return *this;

	}


		// dereference operator
		T& operator*()
		{
			return *pIterator;
		}


		// get the raw pointer
		T* getPointer()
		{
			return pIterator;
		}



	private:
		T *  pIterator;

	};



	template<class T> Iterator<T>& operator+(Iterator<T> & iv, size_type pos)
	{

		iv.pIterator += pos ;

		return iv;
	}



	template<class T> bool operator==(Iterator<T> & iv1, Iterator<T> & iv2)
	{
		return iv1.pIterator == iv2.pIterator;
	}



	template<class T> bool operator!= (Iterator<T> & iv1, Iterator<T> & iv2)
	{
		return  !(iv1 == iv2);
	}










//container class



	template<class T>
	class vector
	{
			

	public:
		typedef   Iterator<T>    iterator;
		//default constructor,construct a empty vector
		vector() :p_first_element(0), p_first_free(0), p_end(0) {}
		
		//constructor
		vector(size_type count,const T& t):p_first_element(0), p_first_free(0), p_end(0)
		{
			for (size_type i = 0; i != count; ++i)
			{
				push_back(t);
			}
		
		}


		//copy constructor
		 vector(const vector&);


		//destructor
		~vector();



//Element access  interfaces
		// get the first element 
		const T& front() const 
		{
			return  *p_first_element;
		}

		T& front() 
		{
			return  *p_first_element;
		}


		//get the last element
		const T& back() const
		{
			return *(p_first_free - 1);
		}


	    T& back() 
		{
			return *(p_first_free - 1);
		}

		// get the pos element 
		const T& at(size_type pos) const
		{
			if (!(pos < size()) )
				throw std::out_of_range("out of range");


			return   *(p_first_element + pos);
		}


	    T& at(size_type pos)
		{
			if (!(pos < size()))
				throw std::out_of_range("out of range");


			return   *(p_first_element + pos);
		}

		//overloaded operator[]
		const T& operator[] (size_type pos) const
		{
			if (!(pos < size()))
				throw std::out_of_range("out of range");


			return   *(p_first_element + pos);
		}


		T& operator[] (size_type pos) 
		{
			if (!(pos < size()))
				throw std::out_of_range("out of range");


			return   *(p_first_element + pos);
		}




//iterator interface

		iterator& begin()
		{
			
			iv.pIterator = p_first_element;
			return iv;
		}


		iterator& end()
		{
			
			iv.pIterator = p_first_free;
			return iv;
		}






//Modifiers interfaces

		//add a element to vector
		void push_back(const T& element_t);


		//remove the last element of vector
		void pop_back();

		//remove of element from container,leave the capacity() unchanged;
		void clear();

		//resize container to hold count element;
		void resize(size_type count);

		//erase the element at pos,return iterator following the removed element
		iterator& erase(iterator& pos);

		//insert element before pos 
		iterator& insert(iterator& pos, const T& value);




//capacity interface

		//get size of vector<T>
		size_type  size() const
		{
			return p_first_free - p_first_element;
		}

		//get capacity of vector<T>
		size_type capacity() const
		{

			return p_end - p_first_element;
		}


		//get max_size() of vector<T>
		size_type  max_size()  const
		{
			
			if (4 == sizeof(p_first_element))
			{
				return std::exp2(32)/ sizeof(T) -1;

			}
			else
			{
				return std::exp2(64) / sizeof(T) - 1;
			}

		}



		//check whether the vector is empty
		bool empty()
		{
			return 0 == size();
		}

		//set the capacity of vector
		void reserve(unsigned long arg_capacity);

		//remove unused capacity
		void shrink_to_fit();


	private:
		void reallocate(unsigned long arg_capacity);  // reallocate memeory,  allocate a new block memory size arg_capacity, copy elements of vector to the new memory block and free the old memory ;



	    static std::allocator<T> av;   //default allocator of vector
		static iterator iv;


		T* p_first_element;   // pointer to first element (pointer to start of allocated memory)
		T* p_first_free;        // pointer  after the last element (pointer to the start of allocated but not constructed element)
		T* p_end;              //pointer to p_end of allocated memory


	};




	//inition of static member: av & iv
	template<class T> std::allocator<T> vector<T>::av = std::allocator<T>();
	template<class T>  typename vector<T>::iterator  vector<T>::iv = Iterator<T>(0);


//class definition
	
	//copy constructor
	template<class T> vector<T>::vector(const vector &vt):p_first_element(0),p_first_free(0),p_end(0)
	{
		size_type _size = vt.size();
		size_type _capacity = vt.capacity();

		T* ptemp = av.allocate(_size);
		p_first_element = ptemp;
	

		for (unsigned int i = 0; i < _size ; ++i)
		{

			av.construct(p_first_element + i, *(vt.p_first_element + i));
		}


		p_first_free = p_first_element + _size;
		p_end = p_first_element + _size;

	}

	


	//destructor
	template<class T>  vector<T>::~vector()
	{
		T* ptemp = p_first_element;
		//delete element in vector
		for (size_type i = 0; i < size(); ++i)
		{

			av.destroy(ptemp + i);
		}


		//free memory 
		av.deallocate(p_first_element, capacity());

	}

	

	template<class T> void  vector<T>::push_back(const T& element_t)
	{
		//if no memory has allocated ,allocate 1*sizeof(T) memory
		if (0 == capacity())
		{
			p_first_element = av.allocate(1);
			p_first_free = p_first_element;
			p_end = p_first_element + 1;
		}

		// if no unused memory left,  doubles the allocated memory
		if (size() == capacity())
		{
			reallocate( 2*capacity() );
		}

		// add a element to vector
		av.construct(p_first_free, element_t);
		p_first_free = p_first_free + 1;


	}



	//remove the last element of vector<T>
	template<class T> void vector<T>::pop_back()
	{
		av.destroy(p_first_free - 1);
		p_first_free = p_first_free - 1;


	}



	template<class T> void vector<T>::clear()
	{
		size_type _size = size();
		for (size_type i = 0; i < _size; ++i)
        {
			pop_back();
		}
	}




	//resize container to hold count element;
	template<class T> void vector<T>::resize(size_type count)
	{
	
		while (count != size())
		{
			if (count > size())
				push_back( T() );
			else pop_back();
		}
	
	}


	template<class T> typename vector<T>::iterator&  vector<T>::erase(iterator&   pos)
	{

		T* ptemp = pos.getPointer()+1;

		while (ptemp != p_first_free)
		{
			*(ptemp-1) = *ptemp ;

			ptemp += 1;

		}

		pop_back();

     	return pos;
	}






	template<class T> typename vector<T>::iterator& vector<T>::insert(iterator& pos, const T& value)
	{

		T* ptemp = pos.getPointer();
		//记录偏移量，因为容器元素个数发生变化时（重新分配内存），原来迭代器（指针）失效
		size_type dif = ptemp - p_first_element;

		//call push_back to add element , and double size vector if necessary
		//push_back(value);
		push_back(value);

		//根据偏移量计算新的对应的指针
		T* ptemp_new = p_first_element + dif;
		T* index = p_first_free - 1;
	

		while (index != ptemp_new)
		{
			*index = *(index -1);
			index -= 1;
		}

		av.construct(ptemp_new, value);

		return pos;
	}






	//allocate new memory block
	template<class T> void vector<T>::reallocate(unsigned long arg_capacity)
	{
		size_type _size = size();
		size_type _capacity = capacity();



		//allocate new memory block
		T* temp = av.allocate(arg_capacity);
		

		//copy element to new memory block and delete element in old memory block
		for (size_type i = 0; i < _size; ++i)
		{
			av.construct(temp + i, *(p_first_element + i));
			av.destroy(p_first_element + i);

		}

		//free old memory block 
		av.deallocate(p_first_element, _capacity);


		// adjust cursor pinters;
		p_first_element = temp;
		p_first_free = p_first_element + _size;
		p_end = p_first_element + arg_capacity;

		
	}




	template<class T> void vector<T>::reserve(unsigned long arg_capacity)
	{
		//if parameter is no bigger than real capacity , do nothing
		if (arg_capacity <= capacity())
			return;

		//re-allocate memory
		reallocate(arg_capacity);
	}


	template<class T> void vector<T>::shrink_to_fit()
	{
		if (size() == capacity())
			return;
		reallocate(size());

	}



}

