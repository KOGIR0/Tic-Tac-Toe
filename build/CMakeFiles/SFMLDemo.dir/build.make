# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kogiro/Public/ticTacToe

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kogiro/Public/ticTacToe/build

# Include any dependencies generated for this target.
include CMakeFiles/SFMLDemo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SFMLDemo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SFMLDemo.dir/flags.make

CMakeFiles/SFMLDemo.dir/main.cpp.o: CMakeFiles/SFMLDemo.dir/flags.make
CMakeFiles/SFMLDemo.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kogiro/Public/ticTacToe/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SFMLDemo.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SFMLDemo.dir/main.cpp.o -c /home/kogiro/Public/ticTacToe/main.cpp

CMakeFiles/SFMLDemo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SFMLDemo.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kogiro/Public/ticTacToe/main.cpp > CMakeFiles/SFMLDemo.dir/main.cpp.i

CMakeFiles/SFMLDemo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SFMLDemo.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kogiro/Public/ticTacToe/main.cpp -o CMakeFiles/SFMLDemo.dir/main.cpp.s

CMakeFiles/SFMLDemo.dir/src/Button.cpp.o: CMakeFiles/SFMLDemo.dir/flags.make
CMakeFiles/SFMLDemo.dir/src/Button.cpp.o: ../src/Button.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kogiro/Public/ticTacToe/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SFMLDemo.dir/src/Button.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SFMLDemo.dir/src/Button.cpp.o -c /home/kogiro/Public/ticTacToe/src/Button.cpp

CMakeFiles/SFMLDemo.dir/src/Button.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SFMLDemo.dir/src/Button.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kogiro/Public/ticTacToe/src/Button.cpp > CMakeFiles/SFMLDemo.dir/src/Button.cpp.i

CMakeFiles/SFMLDemo.dir/src/Button.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SFMLDemo.dir/src/Button.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kogiro/Public/ticTacToe/src/Button.cpp -o CMakeFiles/SFMLDemo.dir/src/Button.cpp.s

CMakeFiles/SFMLDemo.dir/src/Field.cpp.o: CMakeFiles/SFMLDemo.dir/flags.make
CMakeFiles/SFMLDemo.dir/src/Field.cpp.o: ../src/Field.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kogiro/Public/ticTacToe/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SFMLDemo.dir/src/Field.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SFMLDemo.dir/src/Field.cpp.o -c /home/kogiro/Public/ticTacToe/src/Field.cpp

CMakeFiles/SFMLDemo.dir/src/Field.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SFMLDemo.dir/src/Field.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kogiro/Public/ticTacToe/src/Field.cpp > CMakeFiles/SFMLDemo.dir/src/Field.cpp.i

CMakeFiles/SFMLDemo.dir/src/Field.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SFMLDemo.dir/src/Field.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kogiro/Public/ticTacToe/src/Field.cpp -o CMakeFiles/SFMLDemo.dir/src/Field.cpp.s

CMakeFiles/SFMLDemo.dir/src/Sprite.cpp.o: CMakeFiles/SFMLDemo.dir/flags.make
CMakeFiles/SFMLDemo.dir/src/Sprite.cpp.o: ../src/Sprite.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kogiro/Public/ticTacToe/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SFMLDemo.dir/src/Sprite.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SFMLDemo.dir/src/Sprite.cpp.o -c /home/kogiro/Public/ticTacToe/src/Sprite.cpp

CMakeFiles/SFMLDemo.dir/src/Sprite.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SFMLDemo.dir/src/Sprite.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kogiro/Public/ticTacToe/src/Sprite.cpp > CMakeFiles/SFMLDemo.dir/src/Sprite.cpp.i

CMakeFiles/SFMLDemo.dir/src/Sprite.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SFMLDemo.dir/src/Sprite.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kogiro/Public/ticTacToe/src/Sprite.cpp -o CMakeFiles/SFMLDemo.dir/src/Sprite.cpp.s

CMakeFiles/SFMLDemo.dir/src/Text.cpp.o: CMakeFiles/SFMLDemo.dir/flags.make
CMakeFiles/SFMLDemo.dir/src/Text.cpp.o: ../src/Text.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kogiro/Public/ticTacToe/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SFMLDemo.dir/src/Text.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SFMLDemo.dir/src/Text.cpp.o -c /home/kogiro/Public/ticTacToe/src/Text.cpp

CMakeFiles/SFMLDemo.dir/src/Text.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SFMLDemo.dir/src/Text.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kogiro/Public/ticTacToe/src/Text.cpp > CMakeFiles/SFMLDemo.dir/src/Text.cpp.i

CMakeFiles/SFMLDemo.dir/src/Text.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SFMLDemo.dir/src/Text.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kogiro/Public/ticTacToe/src/Text.cpp -o CMakeFiles/SFMLDemo.dir/src/Text.cpp.s

CMakeFiles/SFMLDemo.dir/src/TicTakToe.cpp.o: CMakeFiles/SFMLDemo.dir/flags.make
CMakeFiles/SFMLDemo.dir/src/TicTakToe.cpp.o: ../src/TicTakToe.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kogiro/Public/ticTacToe/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/SFMLDemo.dir/src/TicTakToe.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SFMLDemo.dir/src/TicTakToe.cpp.o -c /home/kogiro/Public/ticTacToe/src/TicTakToe.cpp

CMakeFiles/SFMLDemo.dir/src/TicTakToe.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SFMLDemo.dir/src/TicTakToe.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kogiro/Public/ticTacToe/src/TicTakToe.cpp > CMakeFiles/SFMLDemo.dir/src/TicTakToe.cpp.i

CMakeFiles/SFMLDemo.dir/src/TicTakToe.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SFMLDemo.dir/src/TicTakToe.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kogiro/Public/ticTacToe/src/TicTakToe.cpp -o CMakeFiles/SFMLDemo.dir/src/TicTakToe.cpp.s

# Object files for target SFMLDemo
SFMLDemo_OBJECTS = \
"CMakeFiles/SFMLDemo.dir/main.cpp.o" \
"CMakeFiles/SFMLDemo.dir/src/Button.cpp.o" \
"CMakeFiles/SFMLDemo.dir/src/Field.cpp.o" \
"CMakeFiles/SFMLDemo.dir/src/Sprite.cpp.o" \
"CMakeFiles/SFMLDemo.dir/src/Text.cpp.o" \
"CMakeFiles/SFMLDemo.dir/src/TicTakToe.cpp.o"

# External object files for target SFMLDemo
SFMLDemo_EXTERNAL_OBJECTS =

SFMLDemo: CMakeFiles/SFMLDemo.dir/main.cpp.o
SFMLDemo: CMakeFiles/SFMLDemo.dir/src/Button.cpp.o
SFMLDemo: CMakeFiles/SFMLDemo.dir/src/Field.cpp.o
SFMLDemo: CMakeFiles/SFMLDemo.dir/src/Sprite.cpp.o
SFMLDemo: CMakeFiles/SFMLDemo.dir/src/Text.cpp.o
SFMLDemo: CMakeFiles/SFMLDemo.dir/src/TicTakToe.cpp.o
SFMLDemo: CMakeFiles/SFMLDemo.dir/build.make
SFMLDemo: /usr/lib/x86_64-linux-gnu/libsfml-system.so
SFMLDemo: /usr/lib/x86_64-linux-gnu/libsfml-window.so
SFMLDemo: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so
SFMLDemo: /usr/lib/x86_64-linux-gnu/libsfml-network.so
SFMLDemo: /usr/lib/x86_64-linux-gnu/libsfml-audio.so
SFMLDemo: CMakeFiles/SFMLDemo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kogiro/Public/ticTacToe/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable SFMLDemo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SFMLDemo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SFMLDemo.dir/build: SFMLDemo

.PHONY : CMakeFiles/SFMLDemo.dir/build

CMakeFiles/SFMLDemo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SFMLDemo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SFMLDemo.dir/clean

CMakeFiles/SFMLDemo.dir/depend:
	cd /home/kogiro/Public/ticTacToe/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kogiro/Public/ticTacToe /home/kogiro/Public/ticTacToe /home/kogiro/Public/ticTacToe/build /home/kogiro/Public/ticTacToe/build /home/kogiro/Public/ticTacToe/build/CMakeFiles/SFMLDemo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SFMLDemo.dir/depend

