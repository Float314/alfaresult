/* 
   Copyright (C) 2026, Float314

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#pragma once
#include <cstdint>
#include <functional>
#include <iostream>
#include <variant>
#include <type_traits>
#include "success.hpp"
#include "failure.hpp"

template<typename T>
class result {
    private:
        T provided_val;
        std::variant<Ok<T>, failure<T>> process(T input) {
            if constexpr (std::is_pointer_v<T>) {
                if (input == nullptr) {
                    return failure<T>();
                }
                return Ok<T>(input);
            }
            else if constexpr (std::is_same_v<T, int> || std::is_same_v<T, bool>) {
                if (input != 0) return failure<T>(input);
                return Ok<T>(input);
            }
            else {
                return Ok<T>(input);
            }
        }
    public:
        result(T input) : provided_val(input) {}

        template<typename M>
        bool isOk(const std::variant<Ok<M>, failure<M>>& inp) {
            return std::holds_alternative<Ok<M>>(inp);
        }

        auto unwrap() {
            return process(provided_val);
        }

        auto unwrapOr(T defaultValue) {
            auto res = process(provided_val);
            if (std::holds_alternative<Ok<T>>(res)) {
                return std::get<Ok<T>>(res).unwrap();
            }
            return defaultValue;
        }
};
