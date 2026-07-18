#include "result.hpp"

int main() {
    int* wnfon = nullptr;
    result<int*> res(wnfon);
    auto val = res.unwrap();
    return 0;
}
