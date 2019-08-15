#ifndef _BASE_UTIL_H_
#define _BASE_UTIL_H_

#include <string>

#include "bcf/err.h"

namespace bcf {
namespace util {

// Canonicalize a unix path (e.g. remove ..).
Result<std::string> CanonicalizePath(const std::string& input);

}  // namespace util
}  // namespace bcf

#endif  // _BASE_UTIL_H_
