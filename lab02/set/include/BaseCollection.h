#ifndef BASE_COLLECTION_H_

#define BASE_COLLECTION_H_

#include <cstddef>


class BaseCollection {
public:
    virtual bool isEmpty() const;
    virtual void clear();
    virtual ~BaseCollection() = 0;
protected:
    size_t size = 0;
};

#endif