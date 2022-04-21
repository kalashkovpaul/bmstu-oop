#ifndef ERRORS_H_

#define ERRORS_H_

#include <exception>
#include <string>
#include <cstring>

class BaseError: public std::exception {
public:
    BaseError(const std::string& time, const std::string& filename, \
    const std::string& classname, const std::string& method) {
        errorInfo = "\nTime: " + time + "\tFile: " + filename +
                    "\n\tClass: " + classname + "\tMethod: " + method;
    }

    const char* what() const noexcept override {
        std::string message = "[ ERROR ]: Set Error. " + errorInfo;
        char *cmessage = new char[1 + message.size()];
        std::strcpy(cmessage, message.c_str());
        return cmessage;
    }
protected:
    std::string errorInfo;
};

class BadAllocError: BaseError {
public:
    BadAllocError(const std::string& time, const std::string& filename, \
    const std::string& classname, const std::string& method):
        BaseError(time, filename, classname, method) {}

    const char* what() const noexcept override {
        std::string message = "[ ERROR ]: Bad Allocation Error. " + errorInfo;
        char *cmessage = new char[1 + message.size()];
        std::strcpy(cmessage, message.c_str());
        return cmessage;
    }  
};

class IteratorError: BaseError {
public:
    IteratorError(const std::string& time, const std::string& filename, \
    const std::string& classname, const std::string& method):
        BaseError(time, filename, classname, method) {}

    const char* what() const noexcept override {
        std::string message = "[ ERROR ]: Invalid iterator. " + errorInfo;
        char *cmessage = new char[1 + message.size()];
        std::strcpy(cmessage, message.c_str());
        return cmessage;
    }  
};

#endif