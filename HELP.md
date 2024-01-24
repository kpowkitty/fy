Feeling lost? Need some help? Maybe it's your first time working on this project.
This document is here to explain everything you need to know. <b> Please read
this in its entirety if you need help. If it doesn't help you, please message
me! <b>

<u>BRANCHES</u><br>

Okay, so we will be running this project on github. It is a private repository,
so you will not be able to fork; rather, you will be working in your own branches.
When you clone into the repository, make sure, in terminal, you do
<code>git fetch
git checkout your-username-here</code>
(^ This puts you on your branch.)

Always be up to date with main, and always be on your branch. You need to check this every time you start a new coding session.

CMAKE

I have set up the project with CMake so it can be run in any application or operating system, so you guys are free to use whatever IDE you want. The one thing we need to do, though, is if you use something like VS, it adds VS only files to it. We don’t want those VS files added to the main branch on github. So, you will need to add those files to your .gitignore file. That will keep those files from being pushed to the main branch. This means editing .gitignore and adding the exact names of those files. This might not be limited to VS, so be on the lookout for this.

Another thing: since we are using CMake, you will need to create a build folder. This is already in the .gitignore as long as you call it “build”. This file needs to be in the project's base file tree, and you will use two commands in it to build your project.

** YOU MUST BE IN YOUR BUILD DIRECTORY TO DO THESE TWO COMMANDS **

First command: Sourcing the cache

cmake ../

This tells CMake which files to build (which should be the entire file tree, as we are calling the root directory).
When you do this command, it sources the previous files. If you ever add

Second:

cmake  --build .

This calls CMake to now compile those files, and it produces an executable.

That is how you build with CMake.

The main executable is fy. But, I have also added an executable for testing. I want to keep our tests in a separate .cpp file from main so we can all test and it not be constantly conflicted. You need to copy my testing_template.cpp and name it “testing.cpp”. This will be your testing file. When you do cmake –build ., do

cmake –build . –target testing

And it will compile it with your testing file specifically. You must run ./testing instead of ./fy.

Once you have tested your work and it is working as expected, you can add it to the main.cpp file. Then, test that by doing the original build “cmake –build .” and test it with “./fy”

CMake works on a cache, so if you make any critical changes to your build, i.e. add a file, remove a file, etc, something that would affect how the program compiles, then you need to re-source your cache. (See above for how to source your cache).

If it’s just completely broken, you might need to completely remove all files in your build directory and then re-source your cache. To do this, do

<code>rm -r *</code>

BUT YOU MUST BE IN YOUR BUILD FOLDER.
If you use remove in the wrong directory, you are in for a world of hurt. You have been warned.

