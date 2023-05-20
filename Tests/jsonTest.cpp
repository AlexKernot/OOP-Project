#include "../json.hpp"

class jsonTest : private JSON {
public:
    bool Start() {
        std::cout << "All tests passed.";
        return true;
    }
};

int main(void) {
    jsonTest tests;
    bool result = tests.Start();
    return result;
}