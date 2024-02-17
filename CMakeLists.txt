project(MyApp C CXX)
cmake_minimum_required(VERSION 3.3.2)

include(cmake/App.cmake)

set(SOURCES "src/MyApp.h"
            "src/MyApp.cpp"
            "src/UI.h"
            "src/UI.cpp"
            "src/main.cpp")

add_app("${SOURCES}")

set(ASSETS_PATH "$<TARGET_FILE_DIR:${APP_NAME}>/assets") 

add_custom_command(TARGET ${APP_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/assets/" "${ASSETS_PATH}")