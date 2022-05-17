#ifndef BASE_MANAGER_HPP_

#define BASE_MANAGER_HPP_

#include <string>

#include <iostream> // TODO - shouldn't be here

class BaseManager {
public:
    virtual std::string getType() = 0;

    virtual void run() = 0;

private:
    BaseManager() = default;
};

#endif