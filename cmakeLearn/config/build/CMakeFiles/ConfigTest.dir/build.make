# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /mnt/e/AaronLearnWorkspaces/Practise/cmakeLearn/config

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/e/AaronLearnWorkspaces/Practise/cmakeLearn/config/build

# Include any dependencies generated for this target.
include CMakeFiles/ConfigTest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ConfigTest.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ConfigTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ConfigTest.dir/flags.make

CMakeFiles/ConfigTest.dir/main.c.o: CMakeFiles/ConfigTest.dir/flags.make
CMakeFiles/ConfigTest.dir/main.c.o: ../main.c
CMakeFiles/ConfigTest.dir/main.c.o: CMakeFiles/ConfigTest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/AaronLearnWorkspaces/Practise/cmakeLearn/config/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ConfigTest.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ConfigTest.dir/main.c.o -MF CMakeFiles/ConfigTest.dir/main.c.o.d -o CMakeFiles/ConfigTest.dir/main.c.o -c /mnt/e/AaronLearnWorkspaces/Practise/cmakeLearn/config/main.c

CMakeFiles/ConfigTest.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ConfigTest.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/e/AaronLearnWorkspaces/Practise/cmakeLearn/config/main.c > CMakeFiles/ConfigTest.dir/main.c.i

CMakeFiles/ConfigTest.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ConfigTest.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/e/AaronLearnWorkspaces/Practise/cmakeLearn/config/main.c -o CMakeFiles/ConfigTest.dir/main.c.s

# Object files for target ConfigTest
ConfigTest_OBJECTS = \
"CMakeFiles/ConfigTest.dir/main.c.o"

# External object files for target ConfigTest
ConfigTest_EXTERNAL_OBJECTS =

ConfigTest: CMakeFiles/ConfigTest.dir/main.c.o
ConfigTest: CMakeFiles/ConfigTest.dir/build.make
ConfigTest: CMakeFiles/ConfigTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/e/AaronLearnWorkspaces/Practise/cmakeLearn/config/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ConfigTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ConfigTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ConfigTest.dir/build: ConfigTest
.PHONY : CMakeFiles/ConfigTest.dir/build

CMakeFiles/ConfigTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ConfigTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ConfigTest.dir/clean

CMakeFiles/ConfigTest.dir/depend:
	cd /mnt/e/AaronLearnWorkspaces/Practise/cmakeLearn/config/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/e/AaronLearnWorkspaces/Practise/cmakeLearn/config /mnt/e/AaronLearnWorkspaces/Practise/cmakeLearn/config /mnt/e/AaronLearnWorkspaces/Practise/cmakeLearn/config/build /mnt/e/AaronLearnWorkspaces/Practise/cmakeLearn/config/build /mnt/e/AaronLearnWorkspaces/Practise/cmakeLearn/config/build/CMakeFiles/ConfigTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ConfigTest.dir/depend

