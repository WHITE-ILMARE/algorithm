# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/zhangzheyuan/projects/github/algorithm/classical

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zhangzheyuan/projects/github/algorithm/classical/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/bfs-map.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bfs-map.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bfs-map.dir/flags.make

CMakeFiles/bfs-map.dir/bfs-map.cpp.o: CMakeFiles/bfs-map.dir/flags.make
CMakeFiles/bfs-map.dir/bfs-map.cpp.o: ../bfs-map.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhangzheyuan/projects/github/algorithm/classical/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bfs-map.dir/bfs-map.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bfs-map.dir/bfs-map.cpp.o -c /Users/zhangzheyuan/projects/github/algorithm/classical/bfs-map.cpp

CMakeFiles/bfs-map.dir/bfs-map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bfs-map.dir/bfs-map.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhangzheyuan/projects/github/algorithm/classical/bfs-map.cpp > CMakeFiles/bfs-map.dir/bfs-map.cpp.i

CMakeFiles/bfs-map.dir/bfs-map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bfs-map.dir/bfs-map.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhangzheyuan/projects/github/algorithm/classical/bfs-map.cpp -o CMakeFiles/bfs-map.dir/bfs-map.cpp.s

# Object files for target bfs-map
bfs__map_OBJECTS = \
"CMakeFiles/bfs-map.dir/bfs-map.cpp.o"

# External object files for target bfs-map
bfs__map_EXTERNAL_OBJECTS =

bfs-map: CMakeFiles/bfs-map.dir/bfs-map.cpp.o
bfs-map: CMakeFiles/bfs-map.dir/build.make
bfs-map: CMakeFiles/bfs-map.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zhangzheyuan/projects/github/algorithm/classical/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bfs-map"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bfs-map.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bfs-map.dir/build: bfs-map

.PHONY : CMakeFiles/bfs-map.dir/build

CMakeFiles/bfs-map.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bfs-map.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bfs-map.dir/clean

CMakeFiles/bfs-map.dir/depend:
	cd /Users/zhangzheyuan/projects/github/algorithm/classical/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zhangzheyuan/projects/github/algorithm/classical /Users/zhangzheyuan/projects/github/algorithm/classical /Users/zhangzheyuan/projects/github/algorithm/classical/cmake-build-debug /Users/zhangzheyuan/projects/github/algorithm/classical/cmake-build-debug /Users/zhangzheyuan/projects/github/algorithm/classical/cmake-build-debug/CMakeFiles/bfs-map.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bfs-map.dir/depend

