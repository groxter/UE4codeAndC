// MemoryPool.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <memory>
#include <vector>
#include <limits>

template<class T>
class TrackingAllocator //Custom class to track all the allocations in the memory
{
public: // has to be public otherwise memory library will send us an error telling us that cannot be access
	    // to this class private.
	using valueType = T;

	using pointer = T *;
	using constPointer = const T *;
	
	using voidPointer = void *;
	using constVoidPointer = const void*;
	using sizeType = sizeT;
	using differenceType = std::ptrdiffT;

	template<class U>
	struct rebind // Convert the custom trackingAllocator to handle other types.
	{
		using other = TrackingAllocator<U>;
	};

	TrackingAllocator() = default;

	template<class U>
	TrackingAllocator(const TrackingAllocator<U> &other) {};

	~TrackingAllocator() = default;

	pointer allocate(sizeType numObjects) // Allocate to memory
	{
		memoryAllocations += numObjects;
		return static_cast<pointer>(operator new(sizeof(T) * numObjects));
	}

	pointer allocate(sizeType numObjects, constVoidPointer nearest) // An override function of allocate that has a pointer to the nearest element allocated previously
	{
		return allocate(numObjects);
	}
     
	void deallocate(pointer p, sizeType numObjects) // Part of the memory library to be implemented
	{
		operator delete(p);
	}

	sizeType maxSize() const // Useful to check what objects can be allocate to memory or otherwise. It is good to have it around to make things easy.
	{  
		return std::numeric_limits<sizeType>::max();
	}

	template<class U, class... Args> // templates parameter packs
	void construct(U *p, Args && ...args)
	{
		new(p) U(std::forward<Args>(args)...); // pass those finite arguments to the pointer
	}

	template<class U>
	void destroy(U* p) // Call the destructor of the pointer.
	{
		p->~U();
	}

	sizeType getAllocations() const
	{
		return memoryAllocations;
	}

private:
	static sizeType memoryAllocations;
};
template<class T>
typename TrackingAllocator<T>::sizeType TrackingAllocator<T>::memoryAllocations = 0;

int main()
{
	using TAint = TrackingAllocator<int>;
	using TAdouble = TAint::rebind<double>::other; // using the internal convertor of rebind structure.

	std::vector<int, TrackingAllocator<int>> v(5); // Simple allocator that creates int values. it will make an allocation of 5 objects.
												   // Careful some types does not work with the allocator and need to be rebind.
	std::cout << v.get_allocator().getAllocations() << std::endl;
    return 0;                                      
}

