#include <cstdlib>

#include "bcf/logging.h"
#include "bcf/stdin-reader.h"
#include "bcf/zlib-deflate-reader.h"


namespace bcf {
namespace {

Result<void> Run() {
  StdinReader stdin_reader;

  auto zlib_reader = TRY(ZlibDeflateReader::Create(&stdin_reader));
  while (true) {
    char buf[BUFSIZ];
    ssize_t num_read = TRY(zlib_reader->Read(buf));
    if (num_read == -1) {
      break;
    }
    fwrite(buf, 1, num_read, stdout);
  }

  return {};
}

}  // namespace
}  // namespace bcf

// Simple compression program which reads from stdin and writes to stdout.
int main() {
  auto result = bcf::Run();
  if (!result.ok()) {
    LOG(ERR) << result.err();
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
