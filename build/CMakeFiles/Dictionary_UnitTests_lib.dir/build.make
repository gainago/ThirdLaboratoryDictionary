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
CMAKE_SOURCE_DIR = /home/goshagaina/MEPHILabsMyselfThirdSemester/ThirdLaboratoryDictionary

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/goshagaina/MEPHILabsMyselfThirdSemester/ThirdLaboratoryDictionary/build

# Include any dependencies generated for this target.
include CMakeFiles/Dictionary_UnitTests_lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Dictionary_UnitTests_lib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Dictionary_UnitTests_lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Dictionary_UnitTests_lib.dir/flags.make

Dictionary_UnitTests_lib_autogen/timestamp: /usr/lib/qt5/bin/moc
Dictionary_UnitTests_lib_autogen/timestamp: /usr/lib/qt5/bin/uic
Dictionary_UnitTests_lib_autogen/timestamp: CMakeFiles/Dictionary_UnitTests_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/goshagaina/MEPHILabsMyselfThirdSemester/ThirdLaboratoryDictionary/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target Dictionary_UnitTests_lib"
	/usr/bin/cmake -E cmake_autogen /home/goshagaina/MEPHILabsMyselfThirdSemester/ThirdLaboratoryDictionary/build/CMakeFiles/Dictionary_UnitTests_lib_autogen.dir/AutogenInfo.json Debug
	/usr/bin/cmake -E touch /home/goshagaina/MEPHILabsMyselfThirdSemester/ThirdLaboratoryDictionary/build/Dictionary_UnitTests_lib_autogen/timestamp

CMakeFiles/Dictionary_UnitTests_lib.dir/Dictionary_UnitTests_lib_autogen/mocs_compilation.cpp.o: CMakeFiles/Dictionary_UnitTests_lib.dir/flags.make
CMakeFiles/Dictionary_UnitTests_lib.dir/Dictionary_UnitTests_lib_autogen/mocs_compilation.cpp.o: Dictionary_UnitTests_lib_autogen/mocs_compilation.cpp
CMakeFiles/Dictionary_UnitTests_lib.dir/Dictionary_UnitTests_lib_autogen/mocs_compilation.cpp.o: CMakeFiles/Dictionary_UnitTests_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/goshagaina/MEPHILabsMyselfThirdSemester/ThirdLaboratoryDictionary/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Dictionary_UnitTests_lib.dir/Dictionary_UnitTests_lib_autogen/mocs_compilation.cpp.o"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Dictionary_UnitTests_lib.dir/Dictionary_UnitTests_lib_autogen/mocs_compilation.cpp.o -MF CMakeFiles/Dictionary_UnitTests_lib.dir/Dictionary_UnitTests_lib_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/Dictionary_UnitTests_lib.dir/Dictionary_UnitTests_lib_autogen/mocs_compilation.cpp.o -c /home/goshagaina/MEPHILabsMyselfThirdSemester/ThirdLaboratoryDictionary/build/Dictionary_UnitTests_lib_autogen/mocs_compilation.cpp

CMakeFiles/Dictionary_UnitTests_lib.dir/Dictionary_UnitTests_lib_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Dictionary_UnitTests_lib.dir/Dictionary_UnitTests_lib_autogen/mocs_compilation.cpp.i"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/goshagaina/MEPHILabsMyselfThirdSemester/ThirdLaboratoryDictionary/build/Dictionary_UnitTests_lib_autogen/mocs_compilation.cpp > CMakeFiles/Dictionary_UnitTests_lib.dir/Dictionary_UnitTests_lib_autogen/mocs_compilation.cpp.i

CMakeFiles/Dictionary_UnitTests_lib.dir/Dictionary_UnitTests_lib_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Dictionary_UnitTests_lib.dir/Dictionary_UnitTests_lib_autogen/mocs_compilation.cpp.s"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/goshagaina/MEPHILabsMyselfThirdSemester/ThirdLaboratoryDictionary/build/Dictionary_UnitTests_lib_autogen/mocs_compilation.cpp -o CMakeFiles/Dictionary_UnitTests_lib.dir/Dictionary_UnitTests_lib_autogen/mocs_compilation.cpp.s

CMakeFiles/Dictionary_UnitTests_lib.dir/Tests/UnitTests/Definition/UnitTests.cpp.o: CMakeFiles/Dictionary_UnitTests_lib.dir/flags.make
CMakeFiles/Dictionary_UnitTests_lib.dir/Tests/UnitTests/Definition/UnitTests.cpp.o: /home/goshagaina/MEPHILabsMyselfThirdSemester/ThirdLaboratoryDictionary/Tests/UnitTests/Definition/UnitTests.cpp
CMakeFiles/Dictionary_UnitTests_lib.dir/Tests/UnitTests/Definition/UnitTests.cpp.o: CMakeFiles/Dictionary_UnitTests_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/goshagaina/MEPHILabsMyselfThirdSemester/ThirdLaboratoryDictionary/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Dictionary_UnitTests_lib.dir/Tests/UnitTests/Definition/UnitTests.cpp.o"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Dictionary_UnitTests_lib.dir/Tests/UnitTests/Definition/UnitTests.cpp.o -MF CMakeFiles/Dictionary_UnitTests_lib.dir/Tests/UnitTests/Definition/UnitTests.cpp.o.d -o CMakeFiles/Dictionary_UnitTests_lib.dir/Tests/UnitTests/Definition/UnitTests.cpp.o -c /home/goshagaina/MEPHILabsMyselfThirdSemester/ThirdLaboratoryDictionary/Tests/UnitTests/Definition/UnitTests.cpp

CMakeFiles/Dictionary_UnitTests_lib.dir/Tests/UnitTests/Definition/UnitTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Dictionary_UnitTests_lib.dir/Tests/UnitTests/Definition/UnitTests.cpp.i"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/goshagaina/MEPHILabsMyselfThirdSemester/ThirdLaboratoryDictionary/Tests/UnitTests/Definition/UnitTests.cpp > CMakeFiles/Dictionary_UnitTests_lib.dir/Tests/UnitTests/Definition/UnitTests.cpp.i

CMakeFiles/Dictionary_UnitTests_lib.dir/Tests/UnitTests/Definition/UnitTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Dictionary_UnitTests_lib.dir/Tests/UnitTests/Definition/UnitTests.cpp.s"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/goshagaina/MEPHILabsMyselfThirdSemester/ThirdLaboratoryDictionary/Tests/UnitTests/Definition/UnitTests.cpp -o CMakeFiles/Dictionary_UnitTests_lib.dir/Tests/UnitTests/Definition/UnitTests.cpp.s

# Object files for target Dictionary_UnitTests_lib
Dictionary_UnitTests_lib_OBJECTS = \
"CMakeFiles/Dictionary_UnitTests_lib.dir/Dictionary_UnitTests_lib_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/Dictionary_UnitTests_lib.dir/Tests/UnitTests/Definition/UnitTests.cpp.o"

# External object files for target Dictionary_UnitTests_lib
Dictionary_UnitTests_lib_EXTERNAL_OBJECTS =

libDictionary_UnitTests_lib.so: CMakeFiles/Dictionary_UnitTests_lib.dir/Dictionary_UnitTests_lib_autogen/mocs_compilation.cpp.o
libDictionary_UnitTests_lib.so: CMakeFiles/Dictionary_UnitTests_lib.dir/Tests/UnitTests/Definition/UnitTests.cpp.o
libDictionary_UnitTests_lib.so: CMakeFiles/Dictionary_UnitTests_lib.dir/build.make
libDictionary_UnitTests_lib.so: CMakeFiles/Dictionary_UnitTests_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/goshagaina/MEPHILabsMyselfThirdSemester/ThirdLaboratoryDictionary/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX shared library libDictionary_UnitTests_lib.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Dictionary_UnitTests_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Dictionary_UnitTests_lib.dir/build: libDictionary_UnitTests_lib.so
.PHONY : CMakeFiles/Dictionary_UnitTests_lib.dir/build

CMakeFiles/Dictionary_UnitTests_lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Dictionary_UnitTests_lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Dictionary_UnitTests_lib.dir/clean

CMakeFiles/Dictionary_UnitTests_lib.dir/depend: Dictionary_UnitTests_lib_autogen/timestamp
	cd /home/goshagaina/MEPHILabsMyselfThirdSemester/ThirdLaboratoryDictionary/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/goshagaina/MEPHILabsMyselfThirdSemester/ThirdLaboratoryDictionary /home/goshagaina/MEPHILabsMyselfThirdSemester/ThirdLaboratoryDictionary /home/goshagaina/MEPHILabsMyselfThirdSemester/ThirdLaboratoryDictionary/build /home/goshagaina/MEPHILabsMyselfThirdSemester/ThirdLaboratoryDictionary/build /home/goshagaina/MEPHILabsMyselfThirdSemester/ThirdLaboratoryDictionary/build/CMakeFiles/Dictionary_UnitTests_lib.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Dictionary_UnitTests_lib.dir/depend
