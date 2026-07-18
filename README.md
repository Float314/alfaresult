# alfaresult

This library adds a result class to C++, simmilar in function of the [geode-sdk result library](https://github.com/geode-sdk/result). Will be used for my future projects... 

# usage

preety generic, actually - 

```cpp 
#include <alfaresult/result.hpp> 

result<int*> res = someFunction();

res.unwrap(); 
res.unwrapOr(1);
res.unwrapOrErr<std::string>("Function returned Nullptr!");

```

Suppose if result is based on a list of arguments 

```cpp
#include <alfaresult/dSOF.hpp>

dSOF<int> dsofClass;

dsofclass.define_args_failure(2, 7, 22, 19); 
dsofclass.define_args_success(65,39,22,0); 

// actually this needs some work... ill fix it soon... 

```

# licensing 

Licensed under the Apache 2.0 license 

Copyright (c) 2026, Float314

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.