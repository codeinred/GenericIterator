#include "IteratorBase.hpp"

template <class Iter, class Value>
class IteratorDerived : public IteratorBase<Value>
{
    Iter it;

   public:
    IteratorDerived() = default;
    IteratorDerived(Iter it) : it(it) {}
    IteratorDerived(IteratorDerived const&) = default;
    IteratorDerived(IteratorDerived&&)      = default;

    Value                operator*() const override { return *it; }
    IteratorBase<Value>& operator++() override
    {
        ++it;
        return *this;
    }

    bool operator!=(IteratorBase<Value> const& other) const override
    {
        auto* derived = dynamic_cast<IteratorDerived const*>(&other);
        return derived == nullptr || it != derived->it;
    }
    bool operator==(IteratorBase<Value> const& other) const override
    {
        auto* derived = dynamic_cast<IteratorDerived const*>(&other);
        return derived != nullptr && it == derived->it;
    }
    IteratorBase<Value>* clone() const override
    {
        return new IteratorDerived(*this);
    }
};
