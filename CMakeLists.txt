cmake_minimum_required(VERSION 3.8)
project(camb_io)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(library_name camb_io)
set(lib_srcs src/camb_io.cpp)
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_cpplint REQUIRED)
find_package(ament_cmake_uncrustify REQUIRED)

find_package(rclcpp REQUIRED)

find_package(std_msgs REQUIRED)
find_package(ackermann_msgs REQUIRED)

add_library(${library_name} ${lib_srcs})

ament_target_dependencies(${library_name} rclcpp std_msgs ackermann_msgs)
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
else()
  ament_uncrustify(${library_name} ${lib_srcs})
endif()

target_include_directories(${library_name} PUBLIC
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
$<INSTALL_INTERFACE:include>)

add_executable(${library_name}_node ${lib_srcs} src/main.cpp)

ament_target_dependencies(${library_name}_node rclcpp std_msgs ackermann_msgs)
target_link_libraries(${library_name}_node ${library_name})


target_compile_features(${library_name} PUBLIC c_std_99 cxx_std_17)

install(TARGETS ${library_name}
  DESTINATION lib/${PROJECT_NAME})

install(TARGETS ${library_name}_node
  DESTINATION lib/${PROJECT_NAME})
# add config folder
install(DIRECTORY config
  DESTINATION share/${PROJECT_NAME}
)

install(
  DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)
# Doxygen
  ament_package()
