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
include CMakeFiles/correct.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/correct.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/correct.dir/flags.make

CMakeFiles/correct.dir/correct.cpp.o: CMakeFiles/correct.dir/flags.make
CMakeFiles/correct.dir/correct.cpp.o: ../correct.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhangzheyuan/projects/github/algorithm/classical/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/correct.dir/correct.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/correct.dir/correct.cpp.o -c /Users/zhangzheyuan/projects/github/algorithm/classical/correct.cpp

CMakeFiles/correct.dir/correct.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/correct.dir/correct.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhangzheyuan/projects/github/algorithm/classical/correct.cpp > CMakeFiles/correct.dir/correct.cpp.i

CMakeFiles/correct.dir/correct.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/correct.dir/correct.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhangzheyuan/projects/github/algorithm/classical/correct.cpp -o CMakeFiles/correct.dir/correct.cpp.s

# Object files for target correct
correct_OBJECTS = \
"CMakeFiles/correct.dir/correct.cpp.o"

# External object files for target correct
correct_EXTERNAL_OBJECTS =

correct: CMakeFiles/correct.dir/correct.cpp.o
correct: CMakeFiles/correct.dir/build.make
correct: CMakeFiles/correct.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zhangzheyuan/projects/github/algorithm/classical/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable correct"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/correct.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/correct.dir/build: correct

.PHONY : CMakeFiles/correct.dir/build

CMakeFiles/correct.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/correct.dir/cmake_clean.cmake
.PHONY : CMakeFiles/correct.dir/clean

CMakeFiles/correct.dir/depend:
	cd /Users/zhangzheyuan/projects/github/algorithm/classical/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zhangzheyuan/projects/github/algorithm/classical /Users/zhangzheyuan/projects/github/algorithm/classical /Users/zhangzheyuan/projects/github/algorithm/classical/cmake-build-debug /Users/zhangzheyuan/projects/github/algorithm/classical/cmake-build-debug /Users/zhangzheyuan/projects/github/algorithm/classical/cmake-build-debug/CMakeFiles/correct.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/correct.dir/depend

