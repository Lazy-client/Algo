# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\jetbrain\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\jetbrain\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Project\CLionProjects\Algo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Project\CLionProjects\Algo\cmake-build-debug-mingw

# Include any dependencies generated for this target.
include CMakeFiles/strand.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/strand.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/strand.dir/flags.make

CMakeFiles/strand.dir/strand/strand.cpp.obj: CMakeFiles/strand.dir/flags.make
CMakeFiles/strand.dir/strand/strand.cpp.obj: ../strand/strand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Project\CLionProjects\Algo\cmake-build-debug-mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/strand.dir/strand/strand.cpp.obj"
	D:\mingw\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\strand.dir\strand\strand.cpp.obj -c D:\Project\CLionProjects\Algo\strand\strand.cpp

CMakeFiles/strand.dir/strand/strand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/strand.dir/strand/strand.cpp.i"
	D:\mingw\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Project\CLionProjects\Algo\strand\strand.cpp > CMakeFiles\strand.dir\strand\strand.cpp.i

CMakeFiles/strand.dir/strand/strand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/strand.dir/strand/strand.cpp.s"
	D:\mingw\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Project\CLionProjects\Algo\strand\strand.cpp -o CMakeFiles\strand.dir\strand\strand.cpp.s

# Object files for target strand
strand_OBJECTS = \
"CMakeFiles/strand.dir/strand/strand.cpp.obj"

# External object files for target strand
strand_EXTERNAL_OBJECTS =

strand.exe: CMakeFiles/strand.dir/strand/strand.cpp.obj
strand.exe: CMakeFiles/strand.dir/build.make
strand.exe: CMakeFiles/strand.dir/linklibs.rsp
strand.exe: CMakeFiles/strand.dir/objects1.rsp
strand.exe: CMakeFiles/strand.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Project\CLionProjects\Algo\cmake-build-debug-mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable strand.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\strand.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/strand.dir/build: strand.exe

.PHONY : CMakeFiles/strand.dir/build

CMakeFiles/strand.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\strand.dir\cmake_clean.cmake
.PHONY : CMakeFiles/strand.dir/clean

CMakeFiles/strand.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Project\CLionProjects\Algo D:\Project\CLionProjects\Algo D:\Project\CLionProjects\Algo\cmake-build-debug-mingw D:\Project\CLionProjects\Algo\cmake-build-debug-mingw D:\Project\CLionProjects\Algo\cmake-build-debug-mingw\CMakeFiles\strand.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/strand.dir/depend
