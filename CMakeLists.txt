cmake_minimum_required(VERSION 3.10)

project(sdl-tic-tac-toe)
set(CMAKE_CXX_STANDARD 17)

# Deps

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Build rules

include_directories(./include)
add_executable(tictactoe
  src/event.cpp
  src/surface.cpp
  src/app/app.cpp
  src/app/app_event.cpp
  src/app/app_game_logic.cpp
  src/app/app_render.cpp
  src/main.cpp
)

find_package(OpenGL REQUIRED)
find_package(SDL REQUIRED)
target_link_libraries(tictactoe OpenGL::GL SDL::SDL)
