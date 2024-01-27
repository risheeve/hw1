#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr() {
    head_ = NULL;
    tail_ = NULL;
    size_ = 0;
}

ULListStr::~ULListStr() {
    clear();
}

bool ULListStr::empty() const {
    return size_ == 0;
}

size_t ULListStr::size() const {
    return size_;
}

void ULListStr::push_back(const std::string& val) {
    if (empty()) {
        
        head_ = tail_ = new Item();
    } else if (tail_->last == ARRSIZE) {
        
        Item* newTail = new Item();
        tail_->next = newTail;
        newTail->prev = tail_;
        tail_ = newTail;
    }
    tail_->val[tail_->last] = val;
    tail_->last++;
    size_++;
}

void ULListStr::push_front(const std::string& val) {
    if (empty()) {
        head_ = tail_ = new Item();
        head_->val[head_->last++] = val; 
    } else if (head_->first == 0) {
        Item* newHead = new Item();
        newHead->val[newHead->last++] = val; // Corrected element assignment
        newHead->next = head_;
        head_->prev = newHead;
        head_ = newHead;
    } else {
        head_->val[--head_->first] = val;
    }
    size_++;
}

void ULListStr::pop_back() {
    if (empty()) {
        throw std::invalid_argument("Cannot pop_back from an empty list.");
    }
    tail_->last--;
    size_--;
    if (tail_->first == tail_->last) {
        Item* temp = tail_;
        tail_ = tail_->prev;
        if (tail_) {
            tail_->next = NULL;
        } else {
            head_ = NULL; 
        }
        delete temp;
    }
}

void ULListStr::pop_front() {
    if (empty()) {
        throw std::invalid_argument("Cannot pop_front from an empty list.");
    }
    head_->first++;
    size_--;
    if (head_->first == head_->last) {
        Item* temp = head_;
        head_ = head_->next;
        if (head_) {
            head_->prev = NULL;
        } else {
            tail_ = NULL; 
        }
        delete temp;
    }
}

std::string const& ULListStr::back() const {
    if (empty()) {
        throw std::invalid_argument("List is empty. No back element.");
    }
    return tail_->val[tail_->last - 1];
}

std::string const& ULListStr::front() const {
    if (empty()) {
        throw std::invalid_argument("List is empty. No front element.");
    }
    return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
    if (loc >= size_) {
        return NULL;
    }
    Item* temp = head_;
    while (temp != NULL && loc >= (temp->last - temp->first)) {
        loc -= (temp->last - temp->first);
        temp = temp->next;
    }
    if (temp == NULL) {
        return NULL;
    }
    return &(temp->val[temp->first + loc]);
}

void ULListStr::set(size_t pos, const std::string& val) {
    std::string* ptr = getValAtLoc(pos);
    if (ptr == NULL) {
        throw std::invalid_argument("Bad location");
    }
    *ptr = val;
}

std::string& ULListStr::get(size_t pos) {
    std::string* ptr = getValAtLoc(pos);
    if (ptr == NULL) {
        throw std::invalid_argument("Bad location");
    }
    return *ptr;
}

std::string const& ULListStr::get(size_t pos) const {
    std::string* ptr = getValAtLoc(pos);
    if (ptr == NULL) {
        throw std::invalid_argument("Bad location");
    }
    return *ptr;
}

void ULListStr::clear() {
    while (head_ != NULL) {
        Item* temp = head_->next;
        delete head_;
        head_ = temp;
    }
    tail_ = NULL;
    size_ = 0;
}

