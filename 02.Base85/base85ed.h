#ifndef __BASE85ED__
#define __BASE85ED__

#include <vector>
#include <cstdint>

namespace base85
{

std::vector<uint8_t> encode(const std::vector<uint8_t> &bytes);
std::vector<uint8_t> decode(const std::vector<uint8_t> &b85str);

}

#endif