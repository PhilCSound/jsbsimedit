# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/manit007/jsbsimedit

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/manit007/jsbsimedit/out/build/Linux-x64-GCC-Debug

# Utility rule file for ExperimentalSubmit.

# Include any custom commands dependencies for this target.
include thirdparty/pugixml/CMakeFiles/ExperimentalSubmit.dir/compiler_depend.make

# Include the progress variables for this target.
include thirdparty/pugixml/CMakeFiles/ExperimentalSubmit.dir/progress.make

thirdparty/pugixml/CMakeFiles/ExperimentalSubmit:
	cd /home/manit007/jsbsimedit/out/build/Linux-x64-GCC-Debug/thirdparty/pugixml && /usr/bin/ctest -D ExperimentalSubmit

ExperimentalSubmit: thirdparty/pugixml/CMakeFiles/ExperimentalSubmit
ExperimentalSubmit: thirdparty/pugixml/CMakeFiles/ExperimentalSubmit.dir/build.make
.PHONY : ExperimentalSubmit

# Rule to build all files generated by this target.
thirdparty/pugixml/CMakeFiles/ExperimentalSubmit.dir/build: ExperimentalSubmit
.PHONY : thirdparty/pugixml/CMakeFiles/ExperimentalSubmit.dir/build

thirdparty/pugixml/CMakeFiles/ExperimentalSubmit.dir/clean:
	cd /home/manit007/jsbsimedit/out/build/Linux-x64-GCC-Debug/thirdparty/pugixml && $(CMAKE_COMMAND) -P CMakeFiles/ExperimentalSubmit.dir/cmake_clean.cmake
.PHONY : thirdparty/pugixml/CMakeFiles/ExperimentalSubmit.dir/clean

thirdparty/pugixml/CMakeFiles/ExperimentalSubmit.dir/depend:
	cd /home/manit007/jsbsimedit/out/build/Linux-x64-GCC-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/manit007/jsbsimedit /home/manit007/jsbsimedit/thirdparty/pugixml /home/manit007/jsbsimedit/out/build/Linux-x64-GCC-Debug /home/manit007/jsbsimedit/out/build/Linux-x64-GCC-Debug/thirdparty/pugixml /home/manit007/jsbsimedit/out/build/Linux-x64-GCC-Debug/thirdparty/pugixml/CMakeFiles/ExperimentalSubmit.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : thirdparty/pugixml/CMakeFiles/ExperimentalSubmit.dir/depend

