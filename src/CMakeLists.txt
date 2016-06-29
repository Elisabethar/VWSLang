SET(CMAKE_C_COMPILER "c++")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

find_package(BISON)
find_package(FLEX)

BISON_TARGET(MyParser VWSL.y ${CMAKE_CURRENT_BINARY_DIR}/y.tab.c)
FLEX_TARGET(MyScanner VWSL.l ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.c)
ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_CURRENT_BINARY_DIR}
    )

add_executable(VWSL
    vwsl_main.cpp
    ${BISON_MyParser_OUTPUTS}
    ${FLEX_MyScanner_OUTPUTS}
    )
