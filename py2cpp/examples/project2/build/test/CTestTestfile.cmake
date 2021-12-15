# CMake generated Testfile for 
# Source directory: D:/cloud/github/luk036.github.io/py2cpp/examples/project2/test
# Build directory: D:/cloud/github/luk036.github.io/py2cpp/examples/project2/build/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(Root2Tests "D:/cloud/github/luk036.github.io/py2cpp/examples/project2/build/test/Debug/root2Tests.exe")
  set_tests_properties(Root2Tests PROPERTIES  _BACKTRACE_TRIPLES "D:/cloud/github/luk036.github.io/py2cpp/examples/project2/test/CMakeLists.txt;10;add_test;D:/cloud/github/luk036.github.io/py2cpp/examples/project2/test/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(Root2Tests "D:/cloud/github/luk036.github.io/py2cpp/examples/project2/build/test/Release/root2Tests.exe")
  set_tests_properties(Root2Tests PROPERTIES  _BACKTRACE_TRIPLES "D:/cloud/github/luk036.github.io/py2cpp/examples/project2/test/CMakeLists.txt;10;add_test;D:/cloud/github/luk036.github.io/py2cpp/examples/project2/test/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(Root2Tests "D:/cloud/github/luk036.github.io/py2cpp/examples/project2/build/test/MinSizeRel/root2Tests.exe")
  set_tests_properties(Root2Tests PROPERTIES  _BACKTRACE_TRIPLES "D:/cloud/github/luk036.github.io/py2cpp/examples/project2/test/CMakeLists.txt;10;add_test;D:/cloud/github/luk036.github.io/py2cpp/examples/project2/test/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(Root2Tests "D:/cloud/github/luk036.github.io/py2cpp/examples/project2/build/test/RelWithDebInfo/root2Tests.exe")
  set_tests_properties(Root2Tests PROPERTIES  _BACKTRACE_TRIPLES "D:/cloud/github/luk036.github.io/py2cpp/examples/project2/test/CMakeLists.txt;10;add_test;D:/cloud/github/luk036.github.io/py2cpp/examples/project2/test/CMakeLists.txt;0;")
else()
  add_test(Root2Tests NOT_AVAILABLE)
endif()
