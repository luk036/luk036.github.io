cmake_minimum_required( VERSION 2.6 )
set ( CMAKE_BUILD_TYPE Debug )
add_definitions ( -Wall )
set ( LIBRARY_OUTPUT_PATH ../lib )
include_directories( ../ )
set ( ellipsoidAA_HDRS
  ellipsoid.h
  gp_base.h
  gp_prob1.h
  posynomial.h
  monomial.h
  )

set ( ellipsoid_SRCS
  gp_prob1.cpp
  )

add_library ( ellipsoid ${ellipsoid_SRCS} ${UIS} ${RSCS} ${TRS} ${MOCS} )

link_directories( ../lib )

add_executable ( cvx_test1 cvx_test1.cpp ${ellipsoid_SRCS} ${UIS} ${RSCS} ${TRS} ${MOCS} )
add_executable ( cvx_test2 cvx_test2.cpp ${ellipsoid_SRCS} ${UIS} ${RSCS} ${TRS} ${MOCS} )
add_executable ( gp_test gp_test.cpp ${ellipsoid_SRCS} ${UIS} ${RSCS} ${TRS} ${MOCS} )
target_link_libraries ( cvx_test1 )
target_link_libraries ( cvx_test2 )
target_link_libraries ( gp_test ellipsoid )
target_link_libraries ( rgp_test ellipsoid )
