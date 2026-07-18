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
#include <type_traits>
#include <optional>

template<typename T>
class failure {
    private:
        std::optional<T> provided_value;
    public:
        failure() : provided_value(std::nullopt) {}
        failure(T input) : provided_value(input) {}
        failure(std::optional<T> input) : provided_value(input) {}

        T unwrap() {
            if (provided_value.has_value()) {
                return provided_value.value();
            }
            return T{};
        }
};
