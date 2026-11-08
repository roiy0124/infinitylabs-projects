# C++ Systems Programming — Projects & Exercises

Data structures, memory management and systems components written from scratch in C++98, as part of an intensive systems programming course at Infinity Labs R&D.

Every component comes with its own unit tests and compiles cleanly with strict warnings:

```
g++ -std=c++98 -pedantic-errors -Wall -Wextra
```

---

## Featured projects

### Scheduler — `projects/scheduler`
A task scheduler that runs tasks in time order. Supports repeating tasks, adding and removing tasks while the scheduler is running, stopping mid-run, and safe handling of tasks that throw. Each task is identified by a unique ID (see `uid`).

### Variable-Size Allocator — `projects/vsa`
A memory allocator that manages a fixed memory pool and hands out blocks of any size. Handles alignment (including unaligned pools), merges adjacent free blocks to fight fragmentation, and reuses freed memory.

### Shapes — `projects/shapes`
A shapes hierarchy rendered with GLUT, drawing a full scene (house, trees, mountains, sun, clouds) with keyboard interaction.

---

## Data structures — `cpp/`

| Component | Description |
|-----------|-------------|
| `slist` | Generic singly linked list (template) |
| `dlist` | Doubly linked list, built as a shared library with a Makefile |
| `vector` | Dynamic array |
| `stack` | Generic stack |
| `pq` | Priority queue template with custom comparators |
| `cirbuff` | Circular buffer with wrap-around reads and writes |
| `rcstring` | Reference-counted string with copy-on-write |
| `uid` | Unique ID generator, unique across processes |

---

## Language fundamentals — `cpp/`

Exercises covering pointers, functions, types, operator overloading (`complex`), bit manipulation (`bitwise`), recursion, file I/O, strings and arrays, expression evaluation, and word-optimized `memcpy` / `memset` / `memmove` (`word`).

---

## Building

Each folder builds on its own. With a Makefile:

```
cd cpp/dlist
make
./dlist_test.out
```

Or compile a single exercise directly:

```
cd cpp/bitwise
g++ -std=c++98 -pedantic-errors -Wall -Wextra bitwise.cpp bitwise_test.cpp -o test
./test
```

The Shapes project requires OpenGL / GLUT. See `projects/shapes/readme`.

---

**Roie Itzhakov** · [github.com/roiy0124](https://github.com/roiy0124)
