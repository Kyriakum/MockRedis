#ifndef PROVIDER_HPP
#define PROVIDER_HPP

#include <memory>

namespace Redis {

template<class T>
    class Provider {
    public:
        virtual ~Provider() = default;

    private:
        virtual std::unique_ptr<T> provide() = 0;
    };
}

#endif //PROVIDER_HPP
