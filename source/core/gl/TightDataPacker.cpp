#include <radix/core/gl/TightDataPacker.hpp>

namespace radix {

TightDataPacker::TightDataPacker(unsigned int reserveBytes) {
  data.reserve(reserveBytes);
}

void TightDataPacker::reserve(unsigned int bytes) {
  data.reserve(bytes);
}

unsigned int TightDataPacker::getSize() const {
  return data.size();
}

const uint8_t* TightDataPacker::getDataPtr() const {
  return data.data();
}

} /* namespace radix */
