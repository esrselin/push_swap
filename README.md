# push_swap — Sorting via Two Stacks + Chunk/Area-Based Algorithm

## 📄 Project Overview

`push_swap` takes a list of integers (given as command line arguments), and produces — on standard output — a sequence of instructions (stack operations) that will sort the list in ascending order using **two stacks** (stack **A** and stack **B**) and a restricted set of operations. The goal is to sort using **as few moves as possible**. At the end, stack A must be sorted, and stack B empty. ([GitHub][1])

Your implementation (in this repo) includes a variety of source files that together implement parsing, indexing/normalizing, chunking/area-splitting, stack operations, and sorting logic for both small and large inputs.

---

## 🔧 Allowed Operations

The permitted stack operations (as per the general push_swap rules) are: ([GitHub][2])

* `sa`, `sb`, `ss` — swap the top two elements of stack A, B, or both.
* `pa`, `pb` — push the top element from B→A (`pa`) or A→B (`pb`).
* `ra`, `rb`, `rr` — rotate stack A, B, or both: shift all elements up by one, top becomes bottom.
* `rra`, `rrb`, `rrr` — reverse rotate stack A, B, or both: shift all elements down by one, bottom becomes top.

Your code files implement these operations; e.g., `ps_swap.c` likely handles `sa`/`sb`, `ps_push.c` handles `pa`/`pb`, `ps_rotate.c` and `ps_revrotate.c` handle rotations, etc.

---

## 📂 Repository Structure (as in your repo)

Relevant files: ([GitHub][3])

```
push_swap/
│
├── ps_parse.c            — argument & input parsing
├── ps_parse_utils.c      — helper functions for parsing / validation
├── ps_index_sort.c       — indexing / normalization of values
├── ps_ranking.c          — (likely) ranking / assigning normalized indices
├── ps_split.c            — dividing data into chunks / areas
├── ps_sort.c             — main sorting logic (small or general)
├── ps_sort2.c            — additional sorting logic (variants / helpers)
├── ps_sort_area.c        — sorting within defined area / chunk logic
├── ps_push.c             — push operations
├── ps_swap.c             — swap operations
├── ps_rotate.c           — rotate operations
├── ps_revrotate.c        — reverse rotate operations
├── ps_rotate_stack.c     — maybe helper for rotate logic on stacks
├── ps_b_to_a.c           — logic to move elements back from B to A (re-insertion)
├── ps_utils.c            — general utilities
├── push_swap.c           — main entry point
├── push_swap.h           — header file (structs, prototypes, etc.)
└── Makefile
```

This modular breakdown aligns with typical push_swap implementations: parsing, normalization, stack operations, and sort logic split across files.

---

## 🧠 Sorting Strategy (Algorithm) — How It Works in Your Implementation

Your implementation appears to follow a **chunk/area-based sorting strategy with indexing/normalization**, combining special-case handling for small input sizes and a more general algorithm for larger sizes. This approach reflects common push_swap optimization techniques. ([Scribd][4])

### 1. Normalization / Indexing

* Upon parsing inputs (in `ps_parse.c` / `ps_parse_utils.c`), duplicates, invalid integers, non-numeric arguments, etc. are handled and validated.
* Then, to ease comparison and to avoid issues with large or negative numbers, the integers are “normalized”: each distinct integer is assigned a **rank or index** according to its order in the sorted set. This mapping is performed by `ps_index_sort.c` and `ps_ranking.c`.
* After normalization, the values used during sorting are their ranks (e.g. from 0 to N-1), which simplifies comparisons and makes chunk boundaries based on index rather than actual values.

This is a common and recommended approach in many push_swap implementations — it simplifies logic and avoids dealing with value magnitude or sign. ([Stack Overflow][5])

### 2. Strategy Based on Input Size

Your code distinguishes at least two general cases:

* **Small inputs** (e.g. very few numbers) → use a dedicated small-sort logic in `ps_sort.c` / `ps_sort2.c` (and maybe `ps_sort_area.c`) that handles minimal permutations manually (or with minimal logic) to reduce number of moves.
* **Larger inputs** → use chunk/area-based sorting:

  * The full set of ranked values is divided into **chunks or “areas”** according to size. E.g. for 100 elements, maybe 5–7 chunks; for larger (500+), more chunks — this partitioning logic is presumably implemented in `ps_split.c`.
  * Then, the algorithm iterates through these chunks: for each chunk (i.e. a subset of the rank-range), elements belonging to that chunk are pushed from stack A to stack B (with `pb`), while performing efficient rotations to bring those elements to top with minimal moves.
  * Once a chunk is moved to B, the algorithm proceeds to re-insert elements back into A in sorted order: using `ps_b_to_a.c`, it likely computes for each element in B what is the “cost” (in number of operations) to bring it to top of B, then what is the cost to position correctly in A (via rotations), sums these costs, and picks the “cheapest move” — then executes it. This way, insertion back is done optimally, reducing overall moves. This “cost-based reinsertion + chunking” is a known efficient technique. ([Medium][6])
  * This process repeats until all elements are back in A and A is sorted.

This approach — chunk + cost-based insertion — tends to perform far better (fewer total operations) than naive “push minimum / push one by one” or full insertion-sort-style approaches. ([Medium][7])

### 3. Final Adjustments & Edge Cases

* The code covers argument validation (duplicates, invalid input).
* For very small sizes (e.g. 2–3 elements), it uses a minimal, specialized logic rather than chunk algorithm — this avoids overhead and yields minimal moves.
* Utilities in `ps_utils.c` likely handle general tasks: memory, linked-list or stack representation (your stacks are probably implemented as linked lists or appropriate struct), stack size, checking if already sorted (to avoid unnecessary operations), etc.

---

## 🚀 Usage & Building

Assuming standard Makefile configuration:

```bash
make
```

Then run:

```bash
./push_swap <list of integers>
```

For example:

```bash
./push_swap 42 5 -3 123 9 -6 99 -8 -12 0
```

The program prints to `stdout` a list of operations (one per line), e.g.:

```
pb
ra
pb
sa
pa
pa
ra
...
```

When these operations are applied (on stacks A and B starting with the input), stack A should end up sorted ascending, and B be empty. (You may optionally use a separate “checker” program to verify correctness, if implemented.)

---

## ⚠️ Error Handling & Input Validation

Your implementation should (and likely does) handle:

* Non-numeric arguments
* Duplicates
* Integer overflows / out-of-range values
* No arguments or empty input
* Memory allocation failures
* Improper usage

Upon error, the program should output an error message and exit gracefully (no segmentation fault, no undefined behavior). This is standard requirement for the push_swap project. ([GitHub][2])

---

## 📝 Summary of Advantages of This Approach

* Normalization simplifies comparisons and avoids potential pitfalls with integer values (negative, large, duplicates)
* Chunk/area-based sorting reduces operations significantly compared to naive sorting, especially on large inputs
* Cost-based reinsertion optimizes how elements are moved from B back to A, minimizing wasted rotations or unnecessary moves
* Specialized small-input logic yields minimal operations for small sets, where chunking overhead would be inefficient
* Modular code structure (parsing, operations, sorting logic, utilities) makes the implementation easier to maintain, read, and extend

---
