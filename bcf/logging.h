#pragma once

#include <iostream>
#include <sstream>

namespace bcf {

extern int gVerboseLogLevel;

class Logger {
 public:
  enum class Type {
    INFO,
    WARN,
    ERR,
  };

  // If |verbosity| is not zero, will have a label VLOG(vebosity) instead of a
  // label corresponding to the associated |type|.
  Logger(Type type, int verbosity, const char* file, int line);
  ~Logger();

  std::ostream& stream() { return stream_; }

 private:
  static const char* TypeString(Type type);

  const Type type_;
  std::ostringstream stream_;
};

namespace logging_internal {

std::ostream& GetNullStream();

}  // namespace logging_internal
}  // namespace bcf

#define LOG(type) bcf::Logger(bcf::Logger::Type::type, 0, __FILE__, __LINE__).stream()
#define VLOG(level)                                                     \
  ((gVerboseLogLevel >= level)                                          \
       ? bcf::Logger(bcf::Logger::Type::INFO, level, __FILE__, __LINE__).stream() \
       : logging_internal::GetNullStream())
