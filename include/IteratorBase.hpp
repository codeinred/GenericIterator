template <class Value>
class IteratorBase
{
   public:
    virtual Value         operator*() const                     = 0;
    virtual IteratorBase& operator++()                          = 0;
    virtual bool          operator!=(IteratorBase const&) const = 0;
    virtual bool          operator==(IteratorBase const&) const = 0;

    // We need this function for making copies of the iterator
    virtual IteratorBase* clone() const = 0;
    virtual ~IteratorBase()             = default;
};
