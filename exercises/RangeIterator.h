// ---------------
// RangeIterator.h
// ---------------

#ifndef RangeIterator_h
#define RangeIterator_h

#include <cstddef>  // ptrdiff_t
#include <iterator> // input_iterator_tag

using namespace std;

template <typename T>
class Range_Iterator {
    public:
        typedef input_iterator_tag iterator_category;
        typedef T                  value_type;
        typedef ptrdiff_t          difference_type;
        typedef T*                 pointer;
        typedef T&                 reference;

    private:
        T _v;

    public:
        Range_Iterator(const T& v) :
                _v (v)
            {}

        bool operator == (const Range_Iterator& rhs) const {
            return (_v == rhs._v);}

        bool operator != (const Range_Iterator& rhs) const {
            return !(*this == rhs);}

        const T& operator * () const {
            return _v;}

        Range_Iterator& operator ++ () {
            ++_v;
            return *this;}

        Range_Iterator operator ++ (int) {
            Range_Iterator x = *this;
            ++*this;
            return x;}};

#endif // RangeIterator_h
