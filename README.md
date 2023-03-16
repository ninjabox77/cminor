# C-Minor

C-Minor is a pedagogical language that has been proposed by Dr. John Minor at the University of Nevada Las Vegas (UNLV) to facilitate the learning of programming languages for first years college students. It follows largely C-style syntax and borrows elements from many other languages such as Fortran 90, Ada, LISP, Java, and Pascal. The main paradigms of the language are imperative and object-oriented. The simplified syntax of C-Minor may serve as a stepping stone to other C style languages for novice programmers while avoiding overly complex constructs they have no need of.

The work will be focused largely on faithfully building a compiler and a virtual machine for the language. An example of a `hello world!` program written in C-Minor is depicted below:

```c++
main {
  out "hello world!"
}
```

<b>Note</b>: There is a good possibility that you will encounter compile problems or miscompilations if you attempt to compile a program other than the compiler itself. This is basically a one-man project, and I have spent only a few months of my spare time so far.

### Authors

* John Minor
* Benjamin Cisneros (<benjcisneros@gmail.com>)

## Data Types

Every value in C-Minor has a specific data type, which lets it know what kind of data is being specified and how to deal with it. Keep in mind that C-Minor is a *statically typed* language, which means that it needs to know the types of all variables at compile-time. However, the compiler can usually infer what type we want to use based on the value and how to use it. We will look at two data type subsets: *discrete* and *scalar*.

Discrete types consists of boolean, integer, character, and enumeration types (as named in *type* declarations). In C-Minor, the programmer may specify a range for each integer variable, and the compiler will select the correct representation for that use. This allows, for instance, for the creation of a subtype of `CHAR` that contains just the uppercase letters, `CHAR: 'A'..'Z'`. Scalar types, however, include string and floating point numbers. `STRING` is a built-in, dynamic-length string type that automatically allocates and deallocates memory whenever needed (similiar to the `string` library of C++). Instead of requiring programmers to choose a hardware representation for their `FLOAT` variables, which is low-level, C-Minor allows programmers to select the number of digits of precision that is needed, giving a more accurate representation to guarantee the accuracy desired. Table 1 shows the built-in data types in C-Minor. 

<div align="center">
  
| Type Name | Keyword | Implementation | Group |
|:---------|:---------|----------------|-------|
| Boolean | `BOOL` | boolean | Discrete |
| Integer | `INT` | int64 | Discrete |
| Character | `CHAR` | string | Discrete |
| Enumeration | `type` | enum | Discrete |
| Floating Point | `FLOAT` | double | Scalar |
| String | `STRING` | string | Scalar |
| Class | `identifier` | class | Object |

  <p>Table 1: Data types.</p>
</div>

## Functions

While not the same as methods, functions allow programmers to encapsulate a small subprogram that may be called by its unique identifier and a set of optional values. For instance, the `main` function, which serves as many programs' entry point, is one of the language's most significant functions, which you have already seen.

```c++
main {
  out "hello world!"
  a_function()
}

func a_function() => void {
  out "from a_function"
}
```
The `func` keyword is preceded by optional modifiers, and followed by a parameter list, an arrow, a return type, and a block to execute upon being called. Functions can either return a direct result (have a non-`void` return type) or work entirely through side-effects (a `void` result). Non-`void` functions may have side-effects, but if declared `pure`, the compiler will check and warn the user if any side-effects are being used. Note that a `void` function that is also labeled pure will do nothing.

# License

C-Minor is distributed under the terms of the [MIT License](https://github.com/git/git-scm.com/blob/main/MIT-LICENSE.txt).
