# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/itsbradnguyen/Desktop/repositories/C-Plus-Plus/Library

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/itsbradnguyen/Desktop/repositories/C-Plus-Plus/Library/out/build

# Include any dependencies generated for this target.
include CMakeFiles/Library.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Library.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Library.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Library.dir/flags.make

CMakeFiles/Library.dir/codegen:
.PHONY : CMakeFiles/Library.dir/codegen

CMakeFiles/Library.dir/src/main.cpp.o: CMakeFiles/Library.dir/flags.make
CMakeFiles/Library.dir/src/main.cpp.o: /home/itsbradnguyen/Desktop/repositories/C-Plus-Plus/Library/src/main.cpp
CMakeFiles/Library.dir/src/main.cpp.o: CMakeFiles/Library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/itsbradnguyen/Desktop/repositories/C-Plus-Plus/Library/out/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Library.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Library.dir/src/main.cpp.o -MF CMakeFiles/Library.dir/src/main.cpp.o.d -o CMakeFiles/Library.dir/src/main.cpp.o -c /home/itsbradnguyen/Desktop/repositories/C-Plus-Plus/Library/src/main.cpp

CMakeFiles/Library.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Library.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/itsbradnguyen/Desktop/repositories/C-Plus-Plus/Library/src/main.cpp > CMakeFiles/Library.dir/src/main.cpp.i

CMakeFiles/Library.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Library.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/itsbradnguyen/Desktop/repositories/C-Plus-Plus/Library/src/main.cpp -o CMakeFiles/Library.dir/src/main.cpp.s

# Object files for target Library
Library_OBJECTS = \
"CMakeFiles/Library.dir/src/main.cpp.o"

# External object files for target Library
Library_EXTERNAL_OBJECTS =

Library: CMakeFiles/Library.dir/src/main.cpp.o
Library: CMakeFiles/Library.dir/build.make
Library: CMakeFiles/Library.dir/compiler_depend.ts
Library: lib/Book/libbook.a
Library: CMakeFiles/Library.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/itsbradnguyen/Desktop/repositories/C-Plus-Plus/Library/out/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Library"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Library.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Library.dir/build: Library
.PHONY : CMakeFiles/Library.dir/build

CMakeFiles/Library.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Library.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Library.dir/clean

CMakeFiles/Library.dir/depend:
	cd /home/itsbradnguyen/Desktop/repositories/C-Plus-Plus/Library/out/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/itsbradnguyen/Desktop/repositories/C-Plus-Plus/Library /home/itsbradnguyen/Desktop/repositories/C-Plus-Plus/Library /home/itsbradnguyen/Desktop/repositories/C-Plus-Plus/Library/out/build /home/itsbradnguyen/Desktop/repositories/C-Plus-Plus/Library/out/build /home/itsbradnguyen/Desktop/repositories/C-Plus-Plus/Library/out/build/CMakeFiles/Library.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Library.dir/depend

