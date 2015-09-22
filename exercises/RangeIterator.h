// ---------------
// RangeIterator.h
// ---------------

#ifndef RangeIterator_h
#define RangeIterator_h

template <typename T>
class Range_Iterator {
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

        T operator * () const {
            return _v;}

        Range_Iterator& operator ++ () {
            ++_v;
            return *this;}

        const Range_Iterator operator ++ (int) {
            Range_Iterator x = *this;
            ++*this;
            return x;}};

#endif // RangeIterator_h
