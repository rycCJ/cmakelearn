add_test([=[Solution1Test.HasCycle]=]  D:/cmakelearn/build/bin/tests.exe [==[--gtest_filter=Solution1Test.HasCycle]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[Solution1Test.HasCycle]=]  PROPERTIES WORKING_DIRECTORY D:/cmakelearn/build/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  tests_TESTS Solution1Test.HasCycle)
