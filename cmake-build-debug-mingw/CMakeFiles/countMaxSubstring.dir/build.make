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
include CMakeFiles/countMaxSubstring.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/countMaxSubstring.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/countMaxSubstring.dir/flags.make

CMakeFiles/countMaxSubstring.dir/strand/countMaxSubstring.cpp.obj: CMakeFiles/countMaxSubstring.dir/flags.make
CMakeFiles/countMaxSubstring.dir/strand/countMaxSubstring.cpp.obj: ../strand/countMaxSubstring.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Project\CLionProjects\Algo\cmake-build-debug-mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/countMaxSubstring.dir/strand/countMaxSubstring.cpp.obj"
	D:\mingw\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\countMaxSubstring.dir\strand\countMaxSubstring.cpp.obj -c D:\Project\CLionProjects\Algo\strand\countMaxSubstring.cpp

CMakeFiles/countMaxSubstring.dir/strand/countMaxSubstring.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/countMaxSubstring.dir/strand/countMaxSubstring.cpp.i"
	D:\mingw\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Project\CLionProjects\Algo\strand\countMaxSubstring.cpp > CMakeFiles\countMaxSubstring.dir\strand\countMaxSubstring.cpp.i

CMakeFiles/countMaxSubstring.dir/strand/countMaxSubstring.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/countMaxSubstring.dir/strand/countMaxSubstring.cpp.s"
	D:\mingw\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Project\CLionProjects\Algo\strand\countMaxSubstring.cpp -o CMakeFiles\countMaxSubstring.dir\strand\countMaxSubstring.cpp.s

# Object files for target countMaxSubstring
countMaxSubstring_OBJECTS = \
"CMakeFiles/countMaxSubstring.dir/strand/countMaxSubstring.cpp.obj"

# External object files for target countMaxSubstring
countMaxSubstring_EXTERNAL_OBJECTS =

countMaxSubstring.exe: CMakeFiles/countMaxSubstring.dir/strand/countMaxSubstring.cpp.obj
countMaxSubstring.exe: CMakeFiles/countMaxSubstring.dir/build.make
countMaxSubstring.exe: CMakeFiles/countMaxSubstring.dir/linklibs.rsp
countMaxSubstring.exe: CMakeFiles/countMaxSubstring.dir/objects1.rsp
countMaxSubstring.exe: CMakeFiles/countMaxSubstring.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Project\CLionProjects\Algo\cmake-build-debug-mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable countMaxSubstring.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\countMaxSubstring.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/countMaxSubstring.dir/build: countMaxSubstring.exe

.PHONY : CMakeFiles/countMaxSubstring.dir/build

CMakeFiles/countMaxSubstring.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\countMaxSubstring.dir\cmake_clean.cmake
.PHONY : CMakeFiles/countMaxSubstring.dir/clean

CMakeFiles/countMaxSubstring.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Project\CLionProjects\Algo D:\Project\CLionProjects\Algo D:\Project\CLionProjects\Algo\cmake-build-debug-mingw D:\Project\CLionProjects\Algo\cmake-build-debug-mingw D:\Project\CLionProjects\Algo\cmake-build-debug-mingw\CMakeFiles\countMaxSubstring.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/countMaxSubstring.dir/depend

