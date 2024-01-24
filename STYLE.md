# Style Guide
Follow: <link>https://userweb.cs.txstate.edu/~v_m137/cs3358_fall2015/codingstyle.html</link>
## Notes:
* <b>Do not</b> put 'using namespace std;'. With a program that is going to be relatively complex, we want to be able to differientiate when we are using std functions or non-std functions by using the scope resolution. Also, it is safety in case we decide to implement a similar function as the std library. 
* Use inline braces as follows:<br>
<code>int main() {<br>
return 0;<br>
}</code><br> 
or<br>
<code>class FooClass {<br>
    int foo();<br>
};</code><br>
* Use function and variable name convention <code>lower_case_underscore</code><br>
* Use Cpp-style comments for comments <code>//</code> and C-style/Javadoc-style for documentation<br>
example:<br>
<code>/** This is a function.<br>
\* @param function parameters<br>
\* @return function return<br>
*/</code><br>
or<br>
<code>/**<br>
\* @project Project name<br>
\* @file main.cpp<br>
\* @developers anon<br>
*/</code><br>
* File naming conventions:<br>
Always underscore, with hyphens as spaces, .h and .cpp<br>
<code>my-really-long-file-name-header.h<br>
<my-really-long-file-name-implementation.cpp<br></code><br>
Why? Follows most *NIX applications! Also, having consistent style along with proper commenting is an absolute must.
