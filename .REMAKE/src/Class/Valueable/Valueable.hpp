#ifndef _VALUEABLE_HPP_
#define _VALUEABLE_HPP_

template <class Y>
class Valueable {
    public:
        virtual Y getValue() const = 0;
};

#endif