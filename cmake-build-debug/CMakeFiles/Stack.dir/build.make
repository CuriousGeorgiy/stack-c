# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\79017\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\202.7319.62\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\79017\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\202.7319.62\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\79017\Documents\Work\MIPT\1 semester\Stack"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\79017\Documents\Work\MIPT\1 semester\Stack\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\Stack.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\Stack.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\Stack.dir\flags.make

CMakeFiles\Stack.dir\main.cpp.obj: CMakeFiles\Stack.dir\flags.make
CMakeFiles\Stack.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\79017\Documents\Work\MIPT\1 semester\Stack\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Stack.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\Llvm\bin\clang-cl.exe @<<
 /nologo -TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Stack.dir\main.cpp.obj /FdCMakeFiles\Stack.dir\ -c "C:\Users\79017\Documents\Work\MIPT\1 semester\Stack\main.cpp"
<<

CMakeFiles\Stack.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Stack.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\Llvm\bin\clang-cl.exe > CMakeFiles\Stack.dir\main.cpp.i @<<
 /nologo -TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\79017\Documents\Work\MIPT\1 semester\Stack\main.cpp"
<<

CMakeFiles\Stack.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Stack.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\Llvm\bin\clang-cl.exe @<<
 /nologo -TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Stack.dir\main.cpp.s /c "C:\Users\79017\Documents\Work\MIPT\1 semester\Stack\main.cpp"
<<

# Object files for target Stack
Stack_OBJECTS = \
"CMakeFiles\Stack.dir\main.cpp.obj"

# External object files for target Stack
Stack_EXTERNAL_OBJECTS =

Stack.exe: CMakeFiles\Stack.dir\main.cpp.obj
Stack.exe: CMakeFiles\Stack.dir\build.make
Stack.exe: CMakeFiles\Stack.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\79017\Documents\Work\MIPT\1 semester\Stack\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Stack.exe"
	C:\Users\79017\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\202.7319.62\bin\cmake\win\bin\cmake.exe -E vs_link_exe --intdir=CMakeFiles\Stack.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\Llvm\bin\lld-link.exe /nologo @CMakeFiles\Stack.dir\objects1.rsp @<<
 /out:Stack.exe /implib:Stack.lib /pdb:"C:\Users\79017\Documents\Work\MIPT\1 semester\Stack\cmake-build-debug\Stack.pdb" /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\Stack.dir\build: Stack.exe

.PHONY : CMakeFiles\Stack.dir\build

CMakeFiles\Stack.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Stack.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Stack.dir\clean

CMakeFiles\Stack.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\Users\79017\Documents\Work\MIPT\1 semester\Stack" "C:\Users\79017\Documents\Work\MIPT\1 semester\Stack" "C:\Users\79017\Documents\Work\MIPT\1 semester\Stack\cmake-build-debug" "C:\Users\79017\Documents\Work\MIPT\1 semester\Stack\cmake-build-debug" "C:\Users\79017\Documents\Work\MIPT\1 semester\Stack\cmake-build-debug\CMakeFiles\Stack.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\Stack.dir\depend

