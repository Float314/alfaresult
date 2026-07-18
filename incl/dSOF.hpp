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
#include <vector>
#include <algorithm>
#include <variant>
#include "result.hpp"

template<typename T>
class dSOF : public result<T> {
    private:
        std::vector<T> args_success;
        std::vector<T> args_failure;
        T provided_arg;

    public:
        dSOF(T input) : result<T>(input), provided_arg(input) {}

        template<typename... Args>
        void define_args_failure(Args&&... args) {
            args_failure = std::vector<T>{ std::forward<Args>(args)... };
        }

        template<typename... Args>
        void define_args_success(Args&&... args) {
            args_success = std::vector<T>{ std::forward<Args>(args)... };
        }

        void provide_arg(T arg) {
            provided_arg = arg;
        }

        std::variant<Ok<T>, failure<T>> unwrap() {
            bool in_success = (std::find(args_success.begin(), args_success.end(), provided_arg) != args_success.end());
            bool in_failure = (std::find(args_failure.begin(), args_failure.end(), provided_arg) != args_failure.end());

            if (in_success && !in_failure) {
                return Ok<T>(provided_arg);
            } else {
                return failure<T>(provided_arg);
            }
        }
};
