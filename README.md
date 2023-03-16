# C-Minor

C-Minor is a pedagogical language that has been proposed by Dr. John Minor at the University of Nevada Las Vegas (UNLV) to facilitate the learning of programming languages for first years college students. It follows largely C-style syntax and borrows elements from many other languages such as Fortran 90, Ada, LISP, Java, and Pascal. The main paradigms of the language are imperative and object-oriented. The simplified syntax of C-Minor may serve as a stepping stone to other C style languages for novice programmers while avoiding overly complex constructs they have no need of.

The work will be focused largely on faithfully building a compiler and a virtual machine for the language. An example of a `hello world!` program written in C-Minor is depicted below:

```c++
main {
  out "hello world!"
}
```

**Note**: There is a good possibility that you will encounter compile errors or miscompilations when you attempt to compile a program other than the compiler itself. This is basically a one-man project, and I have spent only a few months of my spare time so far.

### Authors

* John Minor
* Benjamin Cisneros (<benjcisneros@gmail.com>)

## Basic Structure

Using a `type` declaration creates a new user-defined type (an *enumeration type*) containing the specified list of identifiers with the given ordering and which are treated as new global constants by the compiler.

There are four kinds of variables in C-Minor: `const` variables, which are global, read-only and statically allocated; `global` variables, which are global, read-write and statically allocated; `local` variables, which are read-write and dynamically allocated on entrance to their block of declaration and deallocated on exit; and `multi` (multiple-typed) class objects, which are also local variables but may be assigned different class types at runtime using the `retype` statement. All local names must be assigned a starting value or the label `uninit` (uninitiated), which causes the system to check and give a runtime error if the variable is ever used before being set.

The scope rules are obvious: global names (`func`, `class`, `global`, `const`, and `type` names) have global scope and may never be redefined; and the scope of `local`/`multi` variables (and formal parameters) is their block of declaration, except while the name is redeclared in an inner-nested block (which is allowed). Note that class elements have their own scope rules.

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

## Arrays

Arrays allow for the creation of an indexable collection of variables under a single identifier. It should be noted that arrays indexes start at 1 in C-Minor rather than at 0. The first element of the array felt a more natural semantic concept rather than the offset value from the array pointer. Arrays are created using brackets `[]`, and their length, which is known at compile time, is part of their type signature `[length]`.

```c++
INT numbers = {1, 2, 3, 4, 5}
```

The buil-int C-Minor function allows a user to specify a single value inside of `Array(<expression>)` to be assigned to all elements of an array during declaration.

```c++
INT numbers[5] = Array(0)
```

A fixed size array can also be created by including the `Array` keyword.

```c++
INT numbers[5] = Array[5](0)
```

Note that mltidimensional arrays must be full in C-Minor, no jagged arrays are possible. Dimensions are listed in a row-major ordering where spatial adjacency is de- termined by the rightmost index.

```
INT numbers[3][4][2] = {
  {{111,112},{121,122},{131,132},{141,142}},
  {{211,212},{221,222},{231,232},{241,242}},
  {{311,312},{321,322},{331,332},{341,342}}
}
```

## Functions

While not the same as methods, functions allow programmers to encapsulate a small subprogram that may be called by its unique identifier and a set of optional values. For instance, the `main` function, which serves as many programs' entry point, is one of the language's most significant functions (which you have already seen).

```c++
main {
  out "hello world!"
  a_function()
}

func a_function(in STRING s) => void {
  out "from " + s
}
```
The `func` keyword is preceded by optional modifiers, and followed by a parameter list, an arrow, a return type, and a block to execute upon being called. Functions can either return a direct result (have a non-`void` return type) or work entirely through side-effects (a `void` result). Non-`void` functions may have side-effects, but if declared `pure`, the compiler will check and warn the user if any side-effects are being used. Note that a `void` function that is also labeled pure will do nothing.

The default implementation for functions is non-recursive, because that is the more common use and requires the least amount of run-time overhead. If recursion is desired, the function must be declared `recurs`.

### Parameters

We can specify that a function has parameters, which are unique variables that are part of the signature of the function. Notice that *all* functions can employ static parametric polymorphism by specifying and using type parameters. If a type parameter is labeled `discr` (discrete), then it is restricted to bein called only with a *discrete type* argument; `scalar` requires a *scalar type*; and a `class` requires an *identifier* argument only. The unspecified default allows any legal *type* as an argument.

Each parameter is assigned a *direction* through the use of the `in`, `out`, or `inout` keywords. If no direction is specified, `in` is used as the default behavior.

* `in` Parameters marked as in may be used in expressions. A variable that is not in can only be assigned to. A parameter marked only as in may have an expression as its value in a function call
* `out` A parameter marked as `out` is essentially passed to the function by reference. Any changes made to the variable will be assigned to the variable used in the function call. Any `out` parameter can only be called with a variable, using a non-variable expression will result in an error. A `out` only variable may only have values assigned to it, it cannot be used as part of an expression.
* `inout` If both directions are assigned, the parameter can only be called with a variable, can be used in an expression and assigned to. Upon the function's resolution, the value in the parameter will be assigned to its calling variable.

# License

C-Minor is distributed under the terms of the [MIT License](https://github.com/git/git-scm.com/blob/main/MIT-LICENSE.txt).
