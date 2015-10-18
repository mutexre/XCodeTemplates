//
//  Option.h
//  LookseryTestTask
//
//  Created by mutexre on 09/10/15.
//  Copyright © 2015 mutexre. All rights reserved.
//

#pragma once

#include <functional>

template <typename T>
class Option
{
public:
    bool defined;
    T value;

    Option() : defined(false) {}
    Option(T val) : defined(true), value(val) {}

    void define(T&& value) {
        defined = true;
        this->value = std::move(value);
    }

    void define(const T& value) {
        defined = true;
        this->value = value;
    }

    void undefine() {
        defined = false;
    }

    T get() const {
        return value;
    }

    T getOrElse(T defaultValue) {
        return defined ? value : defaultValue;
    }

    T getOrExecute(std::function<void()> f) {
        if (!defined) f();
        return value;
    }

    T operator->() const {
        return value;
    }

    bool operator==(const Option<T>& o) const {
        if (defined == o.defined) {
            if (defined)
                return value == o.value;
            else
                return true;
        }

        return false;
    }

    bool operator!=(const Option<T>& o) const {
        return !operator==(o);
    }

    operator bool() const {
        return defined;
    }
};
