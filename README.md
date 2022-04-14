# Common-Code-For-C-Projects
This is a lite set of defined types and prototypes that can be used with C standard functions. This can be used to decouple your code from the standard library, allowing anyone's code to easily be developed for platforms that do not use the C standard library. The example.c gives implementations of the function prototypes using standard library functions. 

# Why try to decouple C code? 
Decoupling C code allows easy migration to a similar library without having to make changes to your source code.

# What is the point? Doesn't everything use C Standard library?
The main general purpose Operating Systems use the C Standard library, but other platforms that have limited resources can't use the C Standard library because of it's size.

# What if you change to a different library and it creates unexpected bugs?
Ensure that your project uses good testing practices to detect bugs. It will still be up to the developer to mitigate any bugs.
