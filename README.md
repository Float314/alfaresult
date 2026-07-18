# alfaresult - Library for rewsult type 

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

Suppose if result is 