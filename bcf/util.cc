#include "base/util.h"

#include "absl/strings/str_cat.h"

namespace bcf {
namespace util {

Result<std::string> CanonicalizePath(const std::string& input) {
  char tmp_path[PATH_MAX];
  if (realpath(input.c_str(), tmp_path) == nullptr) {
    return BuildPosixErr(absl::StrCat("Failed to canonicalize ", input));
  }

  return std::string(tmp_path);
}

}  // namespace util
}  // namespace bcf
