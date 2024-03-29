package(default_visibility = ["//visibility:public"])

cc_library(
    name = "err",
    hdrs = [
        "err.h",
    ],
    deps = [
        "@com_google_absl//absl/base",
        "@com_google_absl//absl/strings",
    ],
)

cc_test(
    name = "err_test",
    srcs = [
        "err_test.cc",
    ],
    deps = [
        ":err",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "err-testing",
    hdrs = [
        "err-testing.h",
    ],
    deps = [
        "@com_google_absl//absl/base",
        "@com_google_absl//absl/strings",
    ],
)

cc_library(
    name = "file-reader",
    srcs = [
        "file-reader.cc",
    ],
    hdrs = [
        "file-reader.h",
    ],
    deps = [
        ":err",
        ":reader",
    ],
)

cc_library(
    name = "logging",
    srcs = [
        "logging.cc",
    ],
    hdrs = [
        "logging.h",
    ],
)

cc_library(
    name = "mpsc-queue",
    hdrs = [
        "mpsc-queue.h",
    ],
    deps = [
        "@com_google_absl//absl/base",
        "@com_google_absl//absl/synchronization",
    ],
)

cc_test(
    name = "mpsc-queue_test",
    srcs = [
        "mpsc-queue_test.cc",
    ],
    deps = [
        ":mpsc-queue",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "once-callback",
    srcs = [
        "once-callback-internal.h",
    ],
    hdrs = [
        "once-callback.h",
    ],
    deps = [
        "@com_google_absl//absl/base",
    ],
)

cc_test(
    name = "once-callback_test",
    srcs = [
        "once-callback_test.cc",
    ],
    deps = [
        ":once-callback",
        "@com_google_absl//absl/memory",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "reader",
    hdrs = [
        "reader.h",
    ],
    deps = [
        ":err",
        "@com_google_absl//absl/types:span",
    ],
)

cc_library(
    name = "scoped-destructor",
    hdrs = [
        "scoped-destructor.h",
    ],
    deps = [
        "@com_google_absl//absl/base",
    ],
)

cc_library(
    name = "scoped-fd",
    hdrs = [
        "scoped-fd.h",
    ],
)

cc_test(
    name = "scoped-fd_test",
    srcs = [
        "scoped-fd_test.cc",
    ],
    deps = [
        ":scoped-fd",
        "@com_google_absl//absl/memory",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "stdin-reader",
    hdrs = [
        "stdin-reader.h",
    ],
    deps = [
        ":err",
        ":reader",
    ],
)

cc_library(
    name = "task-runner",
    srcs = [
        "task-runner.cc",
    ],
    hdrs = [
        "task-runner.h",
    ],
    deps = [
        ":mpsc-queue",
        ":once-callback",
    ],
)

cc_test(
    name = "task-runner_test",
    srcs = [
        "task-runner_test.cc",
    ],
    deps = [
        ":task-runner",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "util",
    srcs = [
        "util.cc",
    ],
    hdrs = [
        "util.h",
    ],
    deps = [
        ":err",
        "@com_google_absl//absl/base",
        "@com_google_absl//absl/strings",
    ],
)

cc_library(
    name = "zlib-deflate-reader",
    srcs = [
        "zlib-deflate-reader.cc",
    ],
    hdrs = [
        "zlib-deflate-reader.h",
    ],
    linkopts = ["-lz"],
    deps = [
        ":logging",
        ":reader",
    ],
)

cc_binary(
    name = "zlib-deflate-reader_test",
    srcs = [
        "zlib-deflate-reader_test.cc",
    ],
    linkopts = ["-lz"],
    deps = [
        ":stdin-reader",
        ":zlib-deflate-reader",
    ],
)
