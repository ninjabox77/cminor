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

Discrete types consists of boolean, integer, character, and enumeration types (as named in *type* declarations). In C-Minor, the programmer may specify a range for each integer variable, and the compiler wills select the correct representation for that use. Table 1 shows the built-in descrete types in C-Minor. 

<div align="center">*Table 1: Descrete types*
  
| Keyword | Description | Range | Coercion |
|:---------|-------------|-------|----------|
| `BOOL` | true or false | false, true | none |

</div>
