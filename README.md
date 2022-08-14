# L3IC

L3IC (**L**ow **L**evel **L**anguage for **I**nput **C**ontrolling) allows you to control mouse and keyboard input on Windows.

## Plans

### Virtual Machine

L3IC-VM will be a bytecode virtual machine, I am planning to keep it simple and efficient.

- Virtual Machine should mess with the bytecode source code only once. Commands will be executed char-by-char.
- Planning to write in C99. L3IC-VM should directly use `Windows.h` without any Wrappers or Libraries.
- L3IC-VM commands should be easy-to-write and not confuse other people. Because i am also thinking this is useful for Desktop/CLI Apps.
- I will use `clang` for C compiler.

### IR Compiler

L3IC-IR is an intermediate representation compiler for L3IC-VM.

- Planning to write in Rust. Since L3IC-IR will convert the given source to bytecode, it doesn't need to use `Windows.h`.
- Planning to use pascal-case (`ThisIsPascalCase`).
- Planning to support macros with parameters.

### Decompiler

L3IC-DE is a decompiler for L3IC-VM. Will decompile given bytecode to an intermediate representation.

- Planning to write in Rust.
- Decompiler will not be in focus until L3IC reaches a certain point.

## Pull Requests

At this point, pull requests are not accepted since the project has not evolved yet. You can contribute to the project on GitHub Issues.

## License

L3IC and subprojects are licensed under the MIT license.
