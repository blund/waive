# Waive
A reversible logic based assembly like language and virtual machine

## What does any of that mean?
This is a lanugage for programming a _very_ low level virtual machine, basically at the level of individual bits and logic gates.
What makes it special is that those gates are _logically reversible_. This means that any sequence of operations performed can be _undone_ by doing the same operations in reverse - no data is lost. Mathematically, these gates are their own inverses.

## Ok.. but why?
Theoretically, if executed on actual hardware, this could yield very energy efficient computing. There are quite a few resources online, and I need to do more research myself on the matter. This language is just for toying with that concept and seeing what restrictions come up and how to deal with them.

## What comes next?
- Change the structure of the project to be a interpreted language. This way we don't have to recompile all the time :)
- Write a nice parser for the proposed syntax in the full_adder.wve file in the examples folder.
This project is still very.. early in development. Check out the issues for things I'm working on/planning to do.
