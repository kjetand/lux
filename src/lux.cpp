module;

#include <iostream>

export module lux;

namespace lux
{
export void hello_world()
{
    std::cout << "Hello, world!" << std::endl;
}
} // namespace lux