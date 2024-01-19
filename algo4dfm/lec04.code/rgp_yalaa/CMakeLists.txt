cmake_minimum_required ( VERSION 2.6 )
set ( CMAKE_BUILD_TYPE Debug )
add_definitions ( -Wall )

include_directories (
  ../ellipsoid
  /home/luk036/yalaa-0.92/src
  /home/luk036/cxsc/include
  )

set ( rgp_yalaa_HDRS
  rgp_prob1.h
  rgp_base.h
  )

set ( rgp_yalaa_SRCS
  rgp_base.cpp
  rgp_prob1.cpp
  rgp_test.cpp
  )

link_directories( ../lib )
# assume libraries of yalaa and cxsc has been copied to /usr/lib
add_executable ( ry_test ${rgp_yalaa_SRCS} ${UIS} ${RSCS} ${TRS} ${MOCS} )
target_link_libraries ( ry_test ellipsoidAA yalaa cxsc)
