[![Official project](https://img.shields.io/badge/c%20minor-UNLV-red)]()
[![c++17](https://img.shields.io/badge/c%2B%2B-17-orange)]()
[![GitHub license](https://img.shields.io/badge/license-MIT-blue)]((https://github.com/git/git-scm.com/blob/main/MIT-LICENSE.txt))

# C Minor: A Pedagogical Language Based on High-Level Design Principles

C Minor is a pedagogical language that has been proposed by Dr. John Minor at the University of Nevada Las Vegas (UNLV) to facilitate the learning of programming languages for first years college students. It mostly uses a C-style syntax and incorporates parts of a variety of other languages, including Fortran 90, Ada, LISP, Java, and Pascal. Nontheless, the simplified syntax of C Minor may serve as a stepping stone to other C-style languages for novice programmers while avoiding overly complex constructs they have no need of. The main paradigms of the language are imperative and object-oriented. An example of a `hello world!` program written in C Minor is depicted below:

```c++
main {
  out "hello world!"
}
```

Note that there is a good possibility that you will encounter compile errors or miscompilations when you attempt to compile a program other than the compiler itself. Since this is basically a one-man project, I will spent only a few months of my spare time so far.

### Stages

The work will be focused largely on faithfully building a compiler and a virtual machine for the language. 

1. Lexer (without preprocessor)
2. Parser (supports basic syntax)
3. Semantic Analysis
4. Code Generation for Virtual Machine

### More information about this project:

#### What is the purpose of this project?

* Provide a visual aid to help first years colleque students who are learning to code for the first time or who have some programming experience but need to solidify their comprehension.
* Provide a visual aid to help second years colleque students who are learning assembly for the first time.
* Make it C++ compliant.

#### Why use C++ insteand of C?

C++ makes it easier to organize large amount of code, which is important giving that this is a one-man project.

#### What platform will it be targetting?

Mainly Linux and Unix-platforms.

### Authors

* Benjamin Cisneros (b4ben[AT]gmx.com)

### Official Notes

Among other small changes in syntax, **Version 2.0** of C Minor has added global read-write variables, eliminated all semicolons, and has replaced the `==` operator with `=`. **Version 3.0** has added the local command, the `uninit` label, and separate delimeters for constant lists (`@..@`) and arrays (`[...]`) instead of using braces.

## Basic Structure

Using a `type` declaration creates a new user-defined type (an *enumeration type*) containing the specified list of identifiers with the given ordering and which are treated as new global constants by the compiler.

There are four kinds of variables in C Minor: `const` variables, which are global, read-only and statically allocated; `global` variables, which are global, read-write and statically allocated; `local` variables, which are read-write and dynamically allocated on entrance to their block of declaration and deallocated on exit; and `multi` (multiple-typed) class objects, which are also local variables but may be assigned different class types at runtime using the `retype` statement. All local names must be assigned a starting value or the label `uninit` (uninitiated), which causes the system to check and give a runtime error if the variable is ever used before being set.

The scope rules are obvious: global names (`func`, `class`, `global`, `const`, and `type` names) have global scope and may never be redefined; and the scope of `local`/`multi` variables (and formal parameters) is their block of declaration, except while the name is redeclared in an inner-nested block (which is allowed). Note that class elements have their own scope rules.

## Data Types

Every value in C Minor has a specific data type, which lets it know what kind of data is being specified and how to deal with it. Keep in mind that C Minor is a *statically typed* language, which means that it needs to know the types of all variables at compile-time. However, the compiler can usually infer what type we want to use based on the value and how to use it. We will look at two data type subsets: *discrete* and *scalar*.

Discrete types consists of boolean, integer, character, and enumeration types (as named in *type* declarations). In C Minor, the programmer may specify a range for each integer variable, and the compiler will select the correct representation for that use. This allows, for instance, for the creation of a subtype of `CHAR` that contains just the uppercase letters, `CHAR: "A"..."Z"`. Scalar types, however, include string and floating point numbers. `STRING` is a built-in, dynamic-length string type that automatically allocates and deallocates memory whenever needed (similiar to the `string` library of C++). Instead of requiring programmers to choose a hardware representation for their `FLOAT` variables, which is low-level, C Minor allows programmers to select the number of digits of precision that is needed, giving a more accurate representation to guarantee the accuracy desired. The table below shows the built-in data types in C Minor. 

<div align="center">
  
| Type Name | Keyword | Implementation | Group |
|:---------:|:---------:|----------------|-------|
| Boolean | `BOOL` | boolean | Discrete |
| Integer | `INT` | int64 | Discrete |
| Character | `CHAR` | string | Discrete |
| Enumeration | `type` | enum | Discrete |
| Floating Point | `FLOAT` | double | Scalar |
| String | `STRING` | string | Scalar |
| Class | `identifier` | class | Object |

</div>

## Arrays

Arrays allow for the creation of an indexable collection of variables under a single identifier. It should be noted that arrays indexes start at 1 in C Minor rather than at 0. The first element of the array felt a more natural semantic concept rather than the offset value from the array pointer. Arrays are created using brackets `[]`, and their length, which is known at compile time, is part of their type signature `[<length>]`.

```c++
INT numbers[5] = [1, 2, 3, 4, 5]
```

The buil-int C Minor function allows a user to specify a single value inside of `Array(<expression>)` to be assigned to all elements of an array during declaration.

```c++
INT numbers[5] = Array(0)
```

A fixed size array can also be created by including the `Array` keyword.

```c++
INT numbers[5] = Array[5](0)
```

Note that mutidimensional arrays must be full in C Minor, no jagged arrays are possible. Dimensions are listed in a row-major ordering where spatial adjacency is determined by the rightmost index.

```c++
INT numbers[3][4][2] = [
  [[111,112],[121,122],[131,132],[141,142]],
  [[211,212],[221,222],[231,232],[241,242]],
  [[311,312],[321,322],[331,332],[341,342]]
]
```

### Slices

C Minor allows for segments of arrays to be assigned or used at a time. This concept, called a *slice*, allows for a subset array to be extracted. Only the rightmost dimension is sliceable in this way. This generates a single dimension array containing the values associated with the slice that can either be assigned to or used as part of an assignment. To utilize the slice concept, the last dimension is indexed by `@<integer>...<integer>@` rather than just a single value. Both integers must be within the bounds of the array and the left must be less than or equal to the right.

## Lists

In addition to arrays, C Minor also includes a built in indexable list to store a collection of values. While arrays are statically sized, the list is dynamically allocated using one of three list command statements. Elements can be added to and removed from the list during runtime.

```c++
List l1 = @1,2,3,4,5@
List l2 = uninit
append l2 = 6
append l1 = l2
insert l1@3@ = 100
out "size: ", Length(l1), ", values: ", l1, endl
```

The `append` command adds a new element or sublist to the end of the list specified before the `=` operator, while `insert` puts a new element or sublist into the list at the location specified by the integer expression (Again, the first element is 1, the second element is 2, and so on). `insert` will automatically reorder the rest of the elements so that they remain in the same order following the inserted element(s). The `remove` command does the opposite of insert, it deletes the indicated element(s) and merges the following values. All of these commands automatically allocate or recover space as needed, and if heap space is ever exhausted, a garbage collection routine will be automatically run. Lastly, to facilitate tracking the size of the list, a built-in function is included named `Length`.

## Functions

While not the same as methods, functions allow programmers to encapsulate a small subprogram that may be called by its unique identifier and a set of optional values. For instance, the `main` function, which serves as many programs' entry point, is one of the language's most significant functions (which you have already seen).

```c++
main {
  out "hello world!"
  a_function("a function")
}

func a_function(in STRING s) => void {
  out "from ", s
}
```
The `func` keyword is preceded by optional modifiers, and followed by a parameter list, an arrow, a return type, and a block to execute upon being called. Functions can either return a direct result (have a non-`void` return type) or work entirely through side-effects (a `void` result). Non-`void` functions may have side-effects, but if declared `pure`, the compiler will check and warn the user if any side-effects are being used. Note that a `void` function that is also labeled pure will do nothing.

The default implementation for functions is non-recursive, because that is the more common use and requires the least amount of run-time overhead. If recursion is desired, the function must be declared `recurs`.

### Return Type

Functions must declare a single type to return as a value upon the completion of its execution. If a function is declared to have a void return type, it uses the `return` keyword with no expression and can the function can never be used as part of an expression. If the return type is an array, it can utilize array size parameters to provide dynamic dimensions for the return value

### Parameters

We can specify that a function has parameters, which are unique variables that are part of the signature of the function. Notice that *all* functions can employ static parametric polymorphism by specifying and using type parameters. If a type parameter is labeled `discr` (discrete), then it is restricted to bein called only with a *discrete type* argument; `scalar` requires a *scalar type*; and a `class` requires an *identifier* argument only. The unspecified default allows any legal *type* as an argument.

Each parameter is assigned a *direction* through the use of the `in`, `out`, or `inout` keywords. If no direction is specified, `in` is used as the default behavior.

* `in` Parameters marked as in may be used in expressions. A variable that is not in can only be assigned to. A parameter marked only as in may have an expression as its value in a function call
* `out` A parameter marked as `out` is essentially passed to the function by reference. Any changes made to the variable will be assigned to the variable used in the function call. Any `out` parameter can only be called with a variable, using a non-variable expression will result in an error. A `out` only variable may only have values assigned to it, it cannot be used as part of an expression.
* `inout` If both directions are assigned, the parameter can only be called with a variable, can be used in an expression and assigned to. Upon the function's resolution, the value in the parameter will be assigned to its calling variable.

All intrinsic types and data structures can be used as function parameters, including objects, arrays, and lists. Parameter names are used to hold the sizes of array dimensions and these will automatically be treated as in integer parameters. These *conformant array parameters* allow array-processing functions to handle arbitrary-sized data, but not to alter the size or shape of array arguments.

## Classes

A class allows for the merging of vari- ables and functions into a single self contained object. If a class is labeled `abstr` (abstract), the compiler will give an error if the declaration of an object (except `multi`-type objects) uses that class as its type. A `final` class requires the compiler to give an error if any class uses it as a parent. The default case allows a class to have both arbitrary objects and derived classes. Like the function case, any class can be made generic (polymorphic) by specifying and using type parameters.

```c++
class Person
protect {
  STRING name
  INT age
}
public {
  method setName(STRING n) => void { name = n }
  method setAge(INT a) => void { age = a }
}
```

Class bodies consist of two declaration sections: `protect` and `public`. The scope of an element (field or method) declared in the protect area is restricted to only its declaration class and, through inheritance, its derived classes by simply using the element’s name. Elements declared as `public` can be accessed like `protect` elements plus they are also accessible globally by any object of the class, using standard *dot notation*.

Note the required ordering of class elements (`protect` before `public` and fields before methods). The declarations of fields and methods are analogous to variables and functions, except that fields are not initialized. Conversely the use and the scope rules of methods are very different from functions, so two different terms (`func` and `method`) are used in C Minor to avoid confusion.

#### Notes on **inheritance**

A derived type can only add new elements to those that it inherits and can never eliminate any, although it may override an inherited method’s definition with a new one, unless that method is labeled **last**. If a non-**last** method is redefined, then the new definition must use the same signature, type, and scope option as the overridden element; otherwise the compiler will give an error. These requirements ensure that a parent class is always a subtype of all its derived classes.

## Statements

In C Minor, statements are lines of code intended to change the state of the program. Each statement begins with a specific keyword unique to that statement, and generally statement keywords are verbs that hint at what the statement does. The keywords `choice`, `in`, and `out` do not follow this scheme.

<div align="center">

| **Type** | **Keyword** |
|----------|-------------|
| variable | `set` |
| control | `if` |
| control | `choice` |
| looping | `loop` |
| iterator | `for` |
| iterator | `for@` |
| iterator | `for[]` |
| list command | `append` |
| list command | `insert` |
| list command | `remove` |
| console I/O | `out` |
| console I/O | `in` |
| program termination | `stop` |
| void function call | `call` |
| function/method return | `return` |

</div>

### I/O Statements

The `in` and `out` commands handle I/O using the standard input and output streams. Variables in the in statement may be labeled with an optional *prompt* string which will be printed before the corresponding value is read. In the out statement, an optional minimum-width specifier can be given for each expression, as well as the precision (number of digits to be printed after the decimal point) for arithmetic expressions. `endl` generates a carriage return/line feed.

#### Input

The `in` statement accepts a comma separated list of scalar or discrete variables. Each variable may include a helpful suggestion text for the user by utilizing a *string* followed by a `:` before the variable name. Each incoming input must be coerceable into the specified variable's type. Here is an simple example of how to read user input:

```c++
in "Enter a number between 0 and 10" : number
```

where `number` is declared as

```c++
INT number = ...
```

#### Output

The user can generate console output by utilizing the out statement. `out` accepts a list of comma separated primitive elements. Note that arrays and lists cannot be output directly, only individual elements can be passed to the `out`. Values can have a minimum width defined by appending a `:` followed by an integer expression. This will ensure that the string generated by the passed value will be at least the specified length. The text is left justified when utilizing this buffering operator.

Floating point values can also specify a number of decimal places to round to (including 0). Note that in order to utilize this feature, the value must first specify a minimum width using the preceding operator followed by a dot operator `.` followed by another integer value. `type` values (or enumerations) when passed to the out statement are output as the name of the enumeration rather than their ranking or numeric equivalent. An enumeration named `Tuesday` of type `weekdays` would be output as the string `Tuesday`.

Finally, in place of a value, the user can also include the keyword `endl` in the list of values to output. This will insert line feed and/or carriage returns as appropriate.

```c++
out "the number is ", number, endl
```

### Conditionals

C Minor features two control statements that allows for code to be executed or not based on some condition.

#### If

The `if` statement is similar to that found in C++, Java, etc. except that braces are always required around each conditional code segment for readability, and the `else` condition is always required even when empty (which is signified by `else{}`). These improvements eliminate common programming errors like the ambiguous else-association problem. Notice also that all conditions *must* be Boolean expressions, which allows the `=` operator to be used here only for the equality check and *never* as the assignment operator; here is an example:

```c++
if (<expr>) {
  ...
} else {}
```

#### Choice

The multiple-choice (`choice`) statement replaces the error-prone switch statement of C++, Java, etc. Like in the `if` statement, the other case is always required and braces are required around each case segment. A list of labels is allowed on each case segment, including ranges of values from `<lower value> ... <upper value>`. And most importantly, only the one correctly labeled choice is executed and then the statement is exited. The compiler will give an error if the same label appears attached to more than one code segment or if the constants are not of the same type as the discrete expression.

```
choice (day)
on Monday...Wednesday { ... }
on Thursday { ... }
on Friday { ... }
other { ... }
```

#### Looping

The block associated with the `loop` statement repeats until the `until` statement's `BOOL` expression has a `true` value. That is, the conditional associated with the `loop` is an ending condition rather than a continuation condition and can be placed anywhere in the loop's sequence. No `break` style command exists to terminate the loop outside of the until statement. This natural, general loop form subsumes *all* other logical loops, eg. `while`, `do-while`, etc., as well as the unstructured `break` and `continue` commands. For example,

```
loop {
<statement>
until ...
<statement>
}
```

where either one of the `<statement>`s is optional. 

This vastly improved counter-based loop requires that the counter identifier be declared in the heading so that its scope is only the loop body. This ensures that no outside variable name is accidentally used and changed by the loop (a common error). Also the counter is treated as a read-only variable in the loop body, so that the compiler will give an error if the programmer tries to change it. This requirement guarantees that the loop is *safe*; that is, it will always finish and it cannot be changed (accidentally or on purpose) into an infinite loop. Students should be taught to always use the `loop` construct for all indefinite (unsafe) loops and reserve the for for definite (safe) loops.

#### Iterators

The discrete-type `for` always requires a lower and upper bound be specified for the counter, and these bounds are static. That is, they will not change during the loop execution, even if a variable used in their expression is changed in the body of the loop. Again, this makes the for-loop safe. When using the in option, the counter is automatically initialized to the lower bound and incremented by 1 (or `Next` function) on each iteration until reaching the upper bound. When the inrev (in reverse) option is specified, the counter is initialized to the upper bound and decremented by 1 (or `Prev`) on each iteration until the lower bound is reached. Stepping by other values has been eliminated because of its rare use and easy simulation. Note that if the lower bound expression evaluates to a value larger than the upper bound expression on entrance to the `for`, it is not an error but instead causes the execution of the loop body to be skipped entirely.

```c++
for (INT i in 1...10) {
  out i, " "
}
// output: 1 2 3 4 5 6 7 8 9 10
```

There are two other forms of the for-loop: an iterator for array expressions (`for[]`) and an iterator for list expressions (`for@`). In both these forms, the loop `<id>` will automatically be set to a different element within the array/list on each iteration, proceeding from the first element to the last (if `in` is chosen) or from the last element to the first (if `inrev` is chosen). Again, row major ordering is used on multi-dimensional arrays. These statements allow the programmer to process all elements in an array or list without the need for an explicit counter (or counters). Note that the for@ loop body may not change the size of the `<list expr>`; ie., no appends, removes, nor inserts may be used.

```c++
INT arr[10] = {1,2,3,4,5,6,7,8,9,10}
for[] (INT value in arr) {
  out value, " "
}
// output: 1 2 3 4 5 6 7 8 9 10
```

or

```c++
for@ (INT i inrev @1...10@) {
  out i, " "
}
// output: 10 9 8 7 6 5 4 3 2 1
```

### Expressions

TODO:

# License

C Minor is distributed under the terms of the [MIT License](https://github.com/git/git-scm.com/blob/main/MIT-LICENSE.txt).
