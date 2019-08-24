#ifndef BCF_ERR_TESTING_H_
#define BCF_ERR_TESTING_H_

#define ASSERT_OK_AND_ASSIGN(dest, expr)                                       \
  dest = ({                                                                    \
    auto result = (expr);                                                      \
    ASSERT_TRUE(result.ok()) << result.err();                                  \
    std::move(*result);                                                        \
  });

#endif //  BCF_ERR_TESTING_H_
