# ft_containers_:

In C++ STL (Standard Template Library), 3 things are meaningful and important:

1. Containers: These are used to manage collection of objects of a certain kind. Containers can be of two types: Sequence Containers (vector, deque, list) and Associative Containers (Set, Multiset, Map, Multimap).
2. Algorithms: These are used to process the elements of a collection. That is algorithms feed from containers and process those elements in a predefined way and may also push the results into the same/different container.
3. Iterator: These are used to step through the elements of collection of objects (aka containers).

The designer of STL chose a wonderful yet simple common approach - "The separation of data and operation".

- The data is held and managed by the `Container` classes.
- The operations over the containers are defined and managed by the configurable algorithms.

So, if `Container`classes and algorithms are completely different entities, there has to be a bridge between them, right? There has to be a dedicated tunnel between them, there has to be some kind of glue between them. Yes, you are right <=====> Iterators are those Bridge/Tunnel/Glue.

Someone might argue that STL concepts of Container/Algorithm/Iterator contradicts with the fundamental ideas of Object Oriented Programming: The STL separates the Data and the Operations (Algorithm) over it <---> rather than combining them. The beauty and flexibility of this design is you can almost bind up every kind of container with every kind of algorithm (by kind of algorithm, I mean to say - Modifying/Non-modifying/Mutating/Sorting/Numeric etc.).

[Containers in C++ STL (Standard Template Library) - GeeksforGeeks](https://www.geeksforgeeks.org/containers-cpp-stl/)

[What are Containers/Adapters? C++](https://stackoverflow.com/questions/3873802/what-are-containers-adapters-c)

## Vectors in C++ STL:

`vector` one of the sequence containers, meaning the data is reliably ordered.  Vectors are as same dynamic arrays they use contiguous storage locations for their elements, which means you can access any element with an integer index in constant time.

[vector - C++ Reference](https://cplusplus.com/reference/vector/vector/)

[vector (classe)](https://docs.microsoft.com/fr-fr/cpp/standard-library/vector-class?view=msvc-160&viewFallbackFrom=vs-2019)

[Vector in C++ STL - GeeksforGeeks](https://www.geeksforgeeks.org/vector-in-cpp-stl/)

### Std::allocator:

[std::allocator() in C++ with Examples - GeeksforGeeks](https://www.geeksforgeeks.org/stdallocator-in-cpp-with-examples/)

**Types of Iterators:**

[Iterators in C++ STL - GeeksforGeeks](https://www.geeksforgeeks.org/iterators-c-stl/?ref=lbp)

[- C++ Reference](https://cplusplus.com/reference/iterator/)

Iterators traits :

[iterator_traits - C++ Reference](https://www.cplusplus.com/reference/iterator/iterator_traits/)

[An Introduction to "Iterator Traits"](https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits)In C++ STL (Standard Template Library), 3 things are meaningful and important:

1. Containers: These are used to manage collection of objects of a certain kind. Containers can be of two types: Sequence Containers (vector, deque, list) and Associative Containers (Set, Multiset, Map, Multimap).
2. Algorithms: These are used to process the elements of a collection. That is algorithms feed from containers and process those elements in a predefined way and may also push the results into the same/different container.
3. Iterator: These are used to step through the elements of collection of objects (aka containers).

The designer of STL chose a wonderful yet simple common approach - "The separation of data and operation".

- The data is held and managed by the `Container` classes.
- The operations over the containers are defined and managed by the configurable algorithms.

So, if `Container`classes and algorithms are completely different entities, there has to be a bridge between them, right? There has to be a dedicated tunnel between them, there has to be some kind of glue between them. Yes, you are right <=====> Iterators are those Bridge/Tunnel/Glue.

Someone might argue that STL concepts of Container/Algorithm/Iterator contradicts with the fundamental ideas of Object Oriented Programming: The STL separates the Data and the Operations (Algorithm) over it <---> rather than combining them. The beauty and flexibility of this design is you can almost bind up every kind of container with every kind of algorithm (by kind of algorithm, I mean to say - Modifying/Non-modifying/Mutating/Sorting/Numeric etc.).

[Containers in C++ STL (Standard Template Library) - GeeksforGeeks](https://www.geeksforgeeks.org/containers-cpp-stl/)

[What are Containers/Adapters? C++](https://stackoverflow.com/questions/3873802/what-are-containers-adapters-c)

## Vectors in C++ STL:

`vector` one of the sequence containers, meaning the data is reliably ordered.  Vectors are as same dynamic arrays they use contiguous storage locations for their elements, which means you can access any element with an integer index in constant time.

[vector - C++ Reference](https://cplusplus.com/reference/vector/vector/)

[vector (classe)](https://docs.microsoft.com/fr-fr/cpp/standard-library/vector-class?view=msvc-160&viewFallbackFrom=vs-2019)

[Vector in C++ STL - GeeksforGeeks](https://www.geeksforgeeks.org/vector-in-cpp-stl/)

### Std::allocator:

[std::allocator() in C++ with Examples - GeeksforGeeks](https://www.geeksforgeeks.org/stdallocator-in-cpp-with-examples/)

**Types of Iterators:**

[Iterators in C++ STL - GeeksforGeeks](https://www.geeksforgeeks.org/iterators-c-stl/?ref=lbp)

[- C++ Reference](https://cplusplus.com/reference/iterator/)

Iterators traits :

[iterator_traits - C++ Reference](https://www.cplusplus.com/reference/iterator/iterator_traits/)

[An Introduction to "Iterator Traits"](https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits)