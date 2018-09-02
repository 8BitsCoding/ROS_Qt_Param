cmake_minimum_required(VERSION 2.8.3)
project(ros_tutorials_param)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  std_msgs
)

## Generate services in the 'srv' folder
add_service_files(
  FILES
  SrvTutorial.srv
)

generate_messages(
    DEPENDENCIES
    std_msgs
)


include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)


catkin_package(
    LIBRARIES ros_tutorials_param
    CATKIN_DEPENDS roscpp std_msgs
)

add_executable(service_server_param src/service_server.cpp)
add_dependencies(service_server_param ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPOTED_TARGETS})
target_link_libraries(service_server_param
    ${catkin_LIBRARIES}
)

add_executable(service_client_param src/service_client.cpp)
add_dependencies(service_client_param ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPOTED_TARGETS})
target_link_libraries(service_client_param
    ${catkin_LIBRARIES}
)
