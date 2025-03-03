#[[
   Copyright 2023 The Silkworm Authors

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
]]

find_package(Boost REQUIRED headers filesystem system)
find_package(CLI11 REQUIRED)

add_executable(execute execute.cpp)
target_include_directories(execute PUBLIC ${CMAKE_SOURCE_DIR} "${SILKWORM_MAIN_DIR}/third_party/libmdbx")
target_link_libraries(
  execute
  PRIVATE Boost::headers
          Boost::filesystem
          Boost::system
          CLI11::CLI11
          silkworm_node
          cmd_common
)
