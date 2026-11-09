#ifndef INT_HASH_SET_HPP
#define INT_HASH_SET_HPP

#include <functional>
#include <iostream>
#include <list>
#include <vector>

class IntHashSet {
public:
    IntHashSet() : buckets_(8), size_(0) {}

    bool contains(int value) const {
        const auto& bucket = buckets_[index(value)];
        for (int item : bucket) {
            if (item == value) {
                return true;
            }
        }
        return false;
    }

    bool insert(int value) {
        if (contains(value)) {
            return false;
        }
        if ((size_ + 1) * 4 > buckets_.size() * 3) {
            rehash(buckets_.size() * 2);
        }
        buckets_[index(value)].push_back(value);
        ++size_;
        return true;
    }

    bool erase(int value) {
        auto& bucket = buckets_[index(value)];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (*it == value) {
                bucket.erase(it);
                --size_;
                return true;
            }
        }
        return false;
    }

    void print() const {
        for (const auto& bucket : buckets_) {
            for (int value : bucket) {
                std::cout << value << ' ';
            }
        }
        std::cout << '\n';
    }

    void clear() {
        std::vector<std::list<int>> empty(8);
        buckets_.swap(empty);
        size_ = 0;
    }

private:
    std::vector<std::list<int>> buckets_;
    std::size_t size_;

    std::size_t index(int value) const {
        return std::hash<int>{}(value) % buckets_.size();
    }

    void rehash(std::size_t count) {
        std::vector<std::list<int>> next(count);
        for (const auto& bucket : buckets_) {
            for (int value : bucket) {
                next[std::hash<int>{}(value) % count].push_back(value);
            }
        }
        buckets_.swap(next);
    }
};

#endif
