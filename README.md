# ft_containers_:

In C++ STL (Standard Template Library), 3 things are meaningful and important:

1. Containers: These are used to manage a collection of objects of a certain kind. Containers can be of two types: Sequence Containers (vector, deque, list) and Associative Containers (Set, Multiset, Map, Multimap).
2. Algorithms: These are used to process the elements of a collection. That is algorithms feed from containers and process those elements in a predefined way and may also push the results into the same/different container.
3. Iterator: These are used to step through the elements of collection of objects (aka containers).

The designer of STL chose a wonderful yet simple common approach - "The separation of data and operation".

- The data is held and managed by the `Container` classes.
- The operations over the containers are defined and managed by the configurable algorithms.

So, if `Container` classes and algorithms are completely different entities, there has to be a bridge between them, right? There has to be a dedicated tunnel between them, there has to be some kind of glue between them. Yes, you are right <=====> Iterators are those Bridge/Tunnel/Glue.

Someone might argue that STL concepts of Container/Algorithm/Iterator contradicts with the fundamental ideas of Object-Oriented Programming: The STL separates the Data and the Operations (Algorithm) over it <---> rather than combining them. The beauty and flexibility of this design is you can almost bind up every kind of container with every kind of algorithm (by kind of algorithm, I mean to say - Modifying/Non-modifying/Mutating/Sorting/Numeric etc.).

[Containers in C++ STL (Standard Template Library) - GeeksforGeeks](https://www.geeksforgeeks.org/containers-cpp-stl/)

[What are Containers/Adapters? C++](https://stackoverflow.com/questions/3873802/what-are-containers-adapters-c)

## Vectors in C++ STL:

`vector` one of the sequence containers, meaning the data is reliably ordered.  Vectors are as same dynamic arrays they use contiguous storage locations for their elements, which means you can access any element with an integer index in constant time.

[vector - C++ Reference](https://cplusplus.com/reference/vector/vector/)

[vector (classe)](https://docs.microsoft.com/fr-fr/cpp/standard-library/vector-class?view=msvc-160&viewFallbackFrom=vs-2019)

[Vector in C++ STL - GeeksforGeeks](https://www.geeksforgeeks.org/vector-in-cpp-stl/)

### Allocator:

[std::allocator() in C++ with Examples - GeeksforGeeks](https://www.geeksforgeeks.org/stdallocator-in-cpp-with-examples/)

### **Types of Iterators:**

[Iterators in C++ STL - GeeksforGeeks](https://www.geeksforgeeks.org/iterators-c-stl/?ref=lbp)

[- C++ Reference](https://cplusplus.com/reference/iterator/)

[](https://docs.microsoft.com/en-us/cpp/standard-library/iterator?view=msvc-170)

### Operators :

[C++ Operator Overloading: Common Practice](https://arne-mertz.de/2015/01/operator-overloading-common-practice/)

### Iterator_traits :

[std::iterator is deprecated: Why, What It Was, and What to Use Instead - Fluent C++](https://www.fluentcpp.com/2018/05/08/std-iterator-deprecated/)

[std::iterator_traits](https://en.cppreference.com/w/cpp/iterator/iterator_traits)

[An Introduction to "Iterator Traits"](https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits)

### Reverse_iterator:

[reverse_iterator - C++ Reference](https://www.cplusplus.com/reference/iterator/reverse_iterator/)

[Why isn't a reverse iterator a formal iterator category according to the C++17 standard?](https://stackoverflow.com/questions/55226605/why-isnt-a-reverse-iterator-a-formal-iterator-category-according-to-the-c17-s/55226720#55226720)

### Random_access_iterator

[Random Access Iterators](https://docs.oracle.com/cd/E19422-01/819-3704/Ran_7821.htm)

[random_access_iterator_tag - C++ Reference](https://cplusplus.com/reference/iterator/RandomAccessIterator/)

### Explicit constructors :

Constructors are functions with the same name as the class. They are used to create the instance of a class. They are provided default by the compiler. But still, the user can have his/her own constructor declared. We can have a constructor with a single parameter and use this kind of constructor for doing type conversion or implicit conversion.

```cpp
#include <iostream>

class A
{
	int data;
	public:
		A(int a) : data(a){
		    cout<<"A::Constructor...\n";
		};
	friend void display(A obj);
};

void display(A obj){
    cout<<"Valud of data in obj :="<< obj.data<<endl;
}

int main(void)
{
	A a = 98;
  // A a1(99);
  // display(a1);
	display(1000);
	return (0);
}
```

A declaration like below in this example is called as an **Implicit Conversion** and calls A(int a) constructor to create an A object from the integer value

[Implicit conversions](https://en.cppreference.com/w/cpp/language/implicit_conversion)

To avoid all such confusions that happen with Implicit Conversion and Constructor Conversion, we can use **explicit** keyword in constructor declaration. This forces the compiler not to do an implicit conversion and throws an error for this kind of code. And thus make sure the constructor is explicitly called with the right syntax. This keyword is used only for the constructors.

## enable_if:

[C++ Tutorial => enable_if](https://riptutorial.com/cplusplus/example/3777/enable-if)

[](https://eli.thegreenplace.net/2014/sfinae-and-enable_if/)

### Type traits

A type trait is a templated struct that has member types that give you information about the type that it is templated on.

[A quick primer on type traits in modern C++](https://www.internalpointers.com/post/quick-primer-type-traits-modern-cpp)

[https://www.youtube.com/watch?v=VvbTP_k_Df4](https://www.youtube.com/watch?v=VvbTP_k_Df4)

[Template Specialization in C++ - GeeksforGeeks](https://www.geeksforgeeks.org/template-specialization-c/)

## Stack  in c++ STL :

A stack is a data structure that operates based on LIFO (Last In First Out) technique. The std::stack allows elements to be added and removed from one end only.

The std::stack class is a container adapter. Container objects hold data of a similar data type. You can create a stack from various sequence containers. If no container is provided, the Deque container will be used by default. Container adapters don’t support iterators, so they can’t be used to manipulate data.

[stack - C++ Reference](https://www.cplusplus.com/reference/stack/stack/)

[](https://www.guru99.com/stack-in-cpp-stl.html)

## Map in STL:

### AVL tree :

[AVL Trees: Rotations, Insertion, Deletion with C++ Example](https://www.guru99.com/avl-tree.html)

[value_compare Class ( )](https://docs.microsoft.com/en-us/cpp/standard-library/value-compare-class-map?view=msvc-170)

### AVL tree rotations :

[AVL Tree - javatpoint](https://www.javatpoint.com/avl-tree)

[](https://www.cise.ufl.edu/~nemo/cop3530/AVL-Tree-Rotations.pdf)

### Traversing Trees with Iterators:

[Traversing Trees with Iterators](https://www.cs.odu.edu/~zeil/cs361/latest/Public/treetraversal/index.html)