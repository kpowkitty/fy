# Hi there! Thank you for working on this project with me. I have added some useful information below about how the project works, like CMake, Github branches, and etc. Please read through this entirely to save us a lot of headaches in the future! If you have any issues, don't hesitate to reach out to me. I will do my best to get back to you in a timely manner!

## BRANCHES <br>

Okay, so we will be running this project on github.<br>
- It is a private repository, so you will not be able to fork; rather, you will be working <b>in your own branches.</b><br>
- When you clone into the repository, make sure, in terminal, you do<br>
<code>git fetch<br>
git checkout your-username-here</code><br>
(^ This puts you on your branch.)<br>

<b> Always be up to date with main, and always be on your branch. </b> You need to check this <b>every time</b> you start a new coding session.<br>
That means, every new session should start with:<br>
<code>git checkout your-username-here<br>
git pull origin main</code><br>

## CMAKE <br>

I have set up the project with CMake so it can be run in any application or operating system, so you guys are free to use whatever IDE you want. 
- One thing: if you use something like VS, it adds VS only files to it. We don’t want those VS files added to the main branch on github. So, you will need to add those files to your .gitignore file. That will keep those files from being pushed to the main branch. This means editing .gitignore and adding the exact names of those files. This might not be limited to VS, so be on the lookout for this.<br>

### BUILDING THE PROGRAM <br>

Use <code>mkdir debug</code> to create your build folder.

<code>cd debug</code> to enter your build folder.

<p align="center"><b>** YOU MUST BE IN YOUR DEBUG DIRECTORY TO DO THESE NEXT TWO COMMANDS **</b></p><br>

1. Sourcing the cache<br>

<code>cmake ../</code><br>

- This tells CMake which files to build (which should be the entire file tree, as we are calling the root directory).<br>
When you do this command, it sources the directory you specificy. In our case, it is ../, as the previous directory holds all our files.<br> 

2. Compiling the program<br>

<code>cmake  --build .</code> or <code>make fy</code> (if you prefer)<br>

- This calls CMake to now compile those files, and it produces an executable.<br>

- The main executable is fy. 

<code>./fy</code> runs the executable.

### (TODO: IMPLEMENT TESTING EXECUTABLE: Ignore this for now). 
But, I have also added an executable for <b>testing.</b> I want to keep our tests in a separate .cpp file from main so we can all test and it not be constantly conflicted. Now, your compile command should be this:<br>

<code>cmake –build . –target testing</code> or <code>make testing</code> (again, if you prefer)<br>

And it will compile it with your testing file specifically. You must run ./testing instead of ./fy.<br>

Once you have tested your work and it is working as expected, you can add it to the main.cpp file. Then, test that by doing the original build “cmake –build .” and test it with “./fy”<br> 
### END IGNORE

### Important Note ###

CMake works on a cache, so if you make any critical changes to your build, i.e. add a file, remove a file, etc, something that would affect how the program compiles, then you need to re-source your cache. (See above for how to source your cache).

If it’s just completely broken, you might need to completely remove all files in your build directory and then re-source your cache. To do this, do

<code>rm -r *</code>

<p align="center"><b>BUT YOU MUST BE IN YOUR BUILD FOLDER.</b></p><br>
<p align="center">If you use remove in the wrong directory, you are in for a world of hurt. You have been warned.</p>
