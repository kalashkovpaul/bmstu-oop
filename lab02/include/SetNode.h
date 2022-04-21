#ifndef SET_NODE_H_

#define SET_NODE_H_

#include <memory>

template<typename T>
class SetNode {
    T data;
    std::shared_ptr<SetNode<T>> next;
    std::shared_ptr<SetNode<T>> previous;

public:
    SetNode() = default;
    explicit SetNode(const T& data);
    explicit SetNode(std::shared_ptr<SetNode<T>>& node);

    ~SetNode() = default;

    const T& getData() const;

    void setData(const T& value);
    void setNull();

    void insertBefore(std::shared_ptr<SetNode<T>> node);

    void exclude();

    void setNext(const SetNode<T>& node);
    void setNext(const std::shared_ptr<SetNode<T>>& node);

    void setPrevious(const SetNode<T>& node);
    void setPrevious(const std::shared_ptr<SetNode<T>>& node);

    std::shared_ptr<SetNode<T>> getNext() const;
    std::shared_ptr<SetNode<T>> getPrevious() const;

    bool operator==(const std::shared_ptr<SetNode<T>>& node) const;
    bool operator!=(const std::shared_ptr<SetNode<T>>& node) const;
    bool operator<(const std::shared_ptr<SetNode<T>>& node) const;
};

#include "SetNode.hpp";

#endif