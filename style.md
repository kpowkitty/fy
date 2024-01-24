# Style Guide
Follow: <link>https://userweb.cs.txstate.edu/~v_m137/cs3358_fall2015/codingstyle.html</link>
## Notes:
* Use inline braces as follows:<br>
<code>int main() {<br>
return 0;<br>
}</code>
or
<code>class FooClass {<br>
    int foo();<br>
};</code><br>
* Use function and variable name convention <code>lower_case_underscore</code><br>
* Use Cpp-style comments for comments <code>//</code> and C-style/Javadoc-style for documentation<br>
example:
<code>
/** This is a function.
\* @param function parameters
\* @return function return
*/</code>
or
<code>
/**
\* @project Project name
\* @file main.cpp
\* @developers anon
*/</code>
* File naming conventions:<br>
Always underscore, with hyphens as spaces, .h and .cpp
<code>my-really-long-file-name-header.h<br>
<my-really-long-file-name-implementation.cpp<br></code>
Why? Because I said so. Follows most *NIX applications!
