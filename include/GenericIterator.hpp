#include "IteratorDerived.hpp"
#include <memory>
#include <utility>

template <class Value>
class GenericIterator
{
    std::unique_ptr<IteratorBase<Value>> iterator;

   public:
    GenericIterator() = default;
    GenericIterator(GenericIterator const& it) : iterator(it.iterator->clone())
    {
    }
    GenericIterator(GenericIterator&&) = default;

    // Creates a GenericIterator from an IteratorBase
    explicit GenericIterator(IteratorBase<Value> const& it)
      : iterator(it.clone())
    {
    }

    // Creates a GenericIterator from an IteratorDerived
    template <class Iter>
    explicit GenericIterator(IteratorDerived<Iter, Value> const& it)
      : iterator(it.clone())
    {
    }

    // Creates a GenericIterator by wrapping another Iter
    template <class Iter>
    GenericIterator(Iter it) : iterator(new IteratorDerived<Iter, Value>(it))
    {
    }

    GenericIterator& operator=(GenericIterator const& it)
    {
        iterator = std::unique_ptr<IteratorBase<Value>>(it.iterator->clone());
        return *this;
    }
    GenericIterator& operator=(GenericIterator&&) = default;

    Value            operator*() const { return *(*iterator); }
    GenericIterator& operator++()
    {
        ++(*iterator);
        return *this;
    }
    bool operator==(GenericIterator const& other) const
    {
        return *iterator == *other.iterator;
    }
    bool operator!=(GenericIterator const& other) const
    {
        return *iterator != *other.iterator;
    }
};

template <class Iter>
GenericIterator(Iter)->GenericIterator<decltype(*std::declval<Iter>())>;[D[D[D[D[D[D[D[D[D[D[D[D[D
