// This is a comment, it will be removed by the preprocessor. All this
// happens BEFORE the compiler ever gets to see the code.

// Comments which start with two slashes, run until the end of the
// line.

Anything before the // does not get removed by the preprocessor.

You can also write /* inline comments */ like this.

/* Comments which start with a slash-star, continue until the first
   occurrence of star-slash, continuing over many lines if
   necessary. */

/* Because of the matching pair of delimiters in this comment syntax,
   people sometimes make the mistake of thinking that such comments
   can be nested, for example, they might thing that /* these three
   words */ are a comment nested within another comment. This is not
   the case, as you can check for yourself by observing the
   preprocessor does NOT remove the words you are currently
   reading. The first occurrence of star-slash terminates the comment,
   regardless of how many slash-stars preceded it Syntax highlighting
   in your editor should also reflect this */


// The following is a preprocessor directive.
#define ABC The first three letters of the alphabet
// It instructs the preprocessor to replace every occurrence of the
// sequence of three characters 'ABC' with whatever follows them on
// the (logical) line. Let's see it in action.

ABC -> The first three letters of the alphabet.

// Remember that this happens BEFORE the compiler gets to look at the
// code.

// The strings (such as ABC in our example) which are to be
// substituted, are known as macros.


// Observe what happens if the macro is embedded within some other text.

xxxABCxxx
xxxABC
   ABCxxx
xxx ABC xxx

// Macros may also be defined to have arguments:
#define BLAH(a,b,c) You gave me three things: a, b and c. I like the c best.

BLAH(banana, apple, 12 green monkeys)


// Note that macros do not HAVE to be made up of capital letters, any
// valid C++ identifier will do. However, the convention is to make up
// macro names of capitals.

#define a_macro2 some stuff

gimme a_macro2

// Macros can also be undefined:
#undef a_macro2

gimme a_macro2


// There are also conditional directives, which allow you exclude
// chunks of the input file depending on whether some macro or other
// has been defined.

#define DEFINED

#ifdef DEFINED
All this will be kept
#else
And this will be removed by the preprocessor
#endif

#ifndef NOT_DEFINED
This will be kept
#else
All this stuff will be removed by the preprocessor
#endif

// The #else is optional


