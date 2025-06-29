#ifndef SINGLETON_HPP
#define SINGLETON_HPP

namespace RedisCommand {

    template<class T>
    class Singleton {
        protected:
            Singleton() = default;
        public:
            Singleton(const Singleton&) = delete;
            Singleton& operator=(const Singleton&) = delete;

            static T& get_instance() {
                static T instance;
                return instance;
            }
        };
}


#endif //SINGLETON_HPP
