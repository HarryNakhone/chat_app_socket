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
CMAKE_SOURCE_DIR = /home/hrry/c_socket

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hrry/c_socket/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/c_socket.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/c_socket.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/c_socket.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/c_socket.dir/flags.make

CMakeFiles/c_socket.dir/main.c.o: CMakeFiles/c_socket.dir/flags.make
CMakeFiles/c_socket.dir/main.c.o: /home/hrry/c_socket/main.c
CMakeFiles/c_socket.dir/main.c.o: CMakeFiles/c_socket.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/hrry/c_socket/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/c_socket.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/c_socket.dir/main.c.o -MF CMakeFiles/c_socket.dir/main.c.o.d -o CMakeFiles/c_socket.dir/main.c.o -c /home/hrry/c_socket/main.c

CMakeFiles/c_socket.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/c_socket.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/hrry/c_socket/main.c > CMakeFiles/c_socket.dir/main.c.i

CMakeFiles/c_socket.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/c_socket.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/hrry/c_socket/main.c -o CMakeFiles/c_socket.dir/main.c.s

# Object files for target c_socket
c_socket_OBJECTS = \
"CMakeFiles/c_socket.dir/main.c.o"

# External object files for target c_socket
c_socket_EXTERNAL_OBJECTS =

c_socket: CMakeFiles/c_socket.dir/main.c.o
c_socket: CMakeFiles/c_socket.dir/build.make
c_socket: /home/hrry/socket_util/cmake-build-debug/libsocket_util.a
c_socket: CMakeFiles/c_socket.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/hrry/c_socket/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable c_socket"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/c_socket.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/c_socket.dir/build: c_socket
.PHONY : CMakeFiles/c_socket.dir/build

CMakeFiles/c_socket.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/c_socket.dir/cmake_clean.cmake
.PHONY : CMakeFiles/c_socket.dir/clean

CMakeFiles/c_socket.dir/depend:
	cd /home/hrry/c_socket/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hrry/c_socket /home/hrry/c_socket /home/hrry/c_socket/cmake-build-debug /home/hrry/c_socket/cmake-build-debug /home/hrry/c_socket/cmake-build-debug/CMakeFiles/c_socket.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/c_socket.dir/depend

