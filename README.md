# Connect-4
This doesn't include very robust input verification.

I moved stuff around to mimick the way most projects I have seen organized. Its not the only way to do it but after messing around with a few different ways to do it this is my favorite..

So below is the stuff that would get committed and shared with git

CMakeLists.txt - this is a special file which tells "CMake" (you can google and download cmake if you want) how to generate make files for whatever operating system is being used. On linux it makes regular make files, on windows it usually generates a visual studio project, and on mac I think it can generate an xcode project. This is really nice cause only one file is needed to build the project on any operating system.

/src - a folder with all source files (.c or .cpp files)

/include - a folder with all header files

/deps - this contains all libraries that the projects use (probably worry about that later)

/test - this contains all little programs that test the overall project. For example - if you have a fairly large command prompt rpg going on and you want to write a function to generate items for an inventory, rather than making some branch in the game to test the function out, you can make another file "test_inventory.cpp" with its own main which does nothing except test the function. All files in this folder can be set up to make their own seperate exe files outside of the main game.

/doc - This is for later on in the project if you want others to be able to use the code you make. You can use something like doxygen to generate an html webpage type thing that will let the users browse your classes and functions to see what they do.


And now here are some typical folders that won't be committed to git but only exist on the local machine.

/bin - this would have all executable files that you build (possibly under subdirectories here)

/lib - all library files generated by the project - if you ever want to build a library for others to use

Last thing I'll say - projects can usually generate 32 bit (x86) executable or a 64 bit (x64) executable, and these may either be debug or release builds.

Debug build has extra debug information embedded in the exe so that you can step through your program and debug it while release build has the compiler optimize everything as much as possible and not include any debug symbols.

I usually (and a lot of other people) append "d" to everything that has debug symbols and I seperate x86 and x64 in different folders. So if I have some program example.exe (say its windows), my bin folder would look like

/bin/x64/example.exe

/bin/x64/exampled.exe

/bin/x86/example.exe

/bin/x86/exampled.exe

Whew.. Okay.. I have no idea how much of this stuff you already are familiar with I just know its kind of the drudge work of programming and took me forever to figure out a good organization for my projects that would work on all platforms.

I am telling you this stuff cause I don't want you to be freaked out by anything when we start actually working on our stickman project. I hope to start doing some work on it here in about two weeks. The first thing I want to do is get a setup to where we both can easily commit and build the project on our local machines for the duration of the project.


Other than all that..

I'm liking what I am seeing!! You are using structs and passing pointer to structs around to functions which I like a lot! Its a really clean way to pass info around. The game worked well and detected wins in a variety of different situations.

I also like your board drawing and your use of functions. Each one having an obvious purpose - makes things really easy to understand.

Good job dude!! I am excited to work on a project with you.

I should warn you - I usually use underscore_case rather than camelCase for stuff ;)