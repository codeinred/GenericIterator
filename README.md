# GenericIterator

This is a small library for supporting polymorphic and generic iteration over containers of data. Right now the main feature of the library is a class called `GenericIterator`, which is templated on the type of object in the container, and which can bind to any iterator that references that data. 

For example, let's say we have a vector of `int`s:

```
std::vector<int> vect = {10, 20, 30};
```

We can assign `vect.begin()` and `vect.end()` to `GenericIterator`s, and use them to iterate over `vect`:
```
GenericIterator<int&> begin = vect.begin(); 
GenericIterator<int&> end   = vect.end();

for(; begin != end; ++begin) {
    std::cout << *begin << '\n'; 
}
```

Those same iterators could also be re-bound to `std::list<int>` too!

```
std::list<int> list = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}; 

begin = list.begin();
end = list.end(); 

for(; begin != end; ++begin) {
    std::cout << *begin << '\n'; 
}
```

In fact, a `GenericIterator<Value>` can be re-bound to any iterator that produces `Value` wehn defererenced. This includes raw pointers too:
```
begin = vect.data();
end   = vect.data() + vect.size(); 
```
