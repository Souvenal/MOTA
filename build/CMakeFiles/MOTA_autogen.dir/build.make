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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mac/Developer/Qt_Projects/MOTA

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mac/Developer/Qt_Projects/MOTA/build

# Utility rule file for MOTA_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/MOTA_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MOTA_autogen.dir/progress.make

CMakeFiles/MOTA_autogen: MOTA_autogen/timestamp

MOTA_autogen/timestamp: /opt/anaconda3/bin/moc
MOTA_autogen/timestamp: /opt/anaconda3/bin/uic
MOTA_autogen/timestamp: CMakeFiles/MOTA_autogen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/mac/Developer/Qt_Projects/MOTA/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target MOTA"
	/usr/local/bin/cmake -E cmake_autogen /Users/mac/Developer/Qt_Projects/MOTA/build/CMakeFiles/MOTA_autogen.dir/AutogenInfo.json ""
	/usr/local/bin/cmake -E touch /Users/mac/Developer/Qt_Projects/MOTA/build/MOTA_autogen/timestamp

CMakeFiles/MOTA_autogen.dir/codegen:
.PHONY : CMakeFiles/MOTA_autogen.dir/codegen

MOTA_autogen: CMakeFiles/MOTA_autogen
MOTA_autogen: MOTA_autogen/timestamp
MOTA_autogen: CMakeFiles/MOTA_autogen.dir/build.make
.PHONY : MOTA_autogen

# Rule to build all files generated by this target.
CMakeFiles/MOTA_autogen.dir/build: MOTA_autogen
.PHONY : CMakeFiles/MOTA_autogen.dir/build

CMakeFiles/MOTA_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MOTA_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MOTA_autogen.dir/clean

CMakeFiles/MOTA_autogen.dir/depend:
	cd /Users/mac/Developer/Qt_Projects/MOTA/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mac/Developer/Qt_Projects/MOTA /Users/mac/Developer/Qt_Projects/MOTA /Users/mac/Developer/Qt_Projects/MOTA/build /Users/mac/Developer/Qt_Projects/MOTA/build /Users/mac/Developer/Qt_Projects/MOTA/build/CMakeFiles/MOTA_autogen.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/MOTA_autogen.dir/depend

