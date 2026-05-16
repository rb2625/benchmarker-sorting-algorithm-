# Sorting Algorithm Benchmarker

A C++ benchmarking program that implements and compares **5 classic sorting algorithms** — each with two versions (V1 baseline and V2 optimized) — across three different input scenarios: random, ascending, and descending arrays of 100,000 integers.

Built as a project for CSCI 215 (Data Structures and Algorithms).

---

## Algorithms Implemented

| Algorithm | V1 (Baseline) | V2 (Optimized) |
|---|---|---|
| Bubble Sort | Standard nested loops | Early exit + shrinking unsorted boundary via last-swap tracking |
| Insertion Sort | Linear search for insert position | Binary search for insert position + skip if already in place |
| Selection Sort | Always swaps, searches from index 0 | Skips redundant swaps, caches max/min, searches from `last` |
| Merge Sort | Standard recursive merge | Skips merge step if two halves are already in order |
| Quick Sort | Pivot = first element | Pivot = middle element (avoids worst case on sorted arrays) |

Each algorithm has both an **ascending** and **descending** variant.

---

## Input Scenarios

The program runs all algorithms across three phases:

- **Phase 1 – Random:** 100,000 shuffled integers loaded from `random.txt`
- **Phase 2 – Ascending:** Pre-sorted ascending data from `ascending.txt`
- **Phase 3 – Descending:** Pre-sorted descending data from `descending.txt`

> Note: QuickSort V1 is commented out in Phases 2 & 3 because it hits stack overflow on already-sorted arrays due to worst-case O(n²) recursion depth with a first-element pivot.

---

## Project Structure

```
sorting-benchmark/
├── main.cpp          # All sort implementations + benchmarking driver
├── random.txt        # 100,000 random integers (required)
├── ascending.txt     # 100,000 ascending integers (required)
├── descending.txt    # 100,000 descending integers (required)
└── README.md
```

---

## How to Run

### 1. Compile

```bash
g++ -O0 -o sorting_benchmark main.cpp
```

> Use `-O0` to disable compiler optimizations so timing results reflect actual algorithm performance.

### 2. Generate Input Files (if you don't have them)

You can generate the three input files with a quick Python script:

```python
import random

nums = random.sample(range(1, 200001), 100000)

with open("random.txt", "w") as f:
    f.write("\n".join(map(str, nums)))

with open("ascending.txt", "w") as f:
    f.write("\n".join(map(str, sorted(nums))))

with open("descending.txt", "w") as f:
    f.write("\n".join(map(str, sorted(nums, reverse=True))))
```

### 3. Run

```bash
./sorting_benchmark
```

---

## Sample Output

```
###########################################
        PHASE 1: RANDOM ARRAY INPUT
###########################################

BubbleSort V1 Ascending:  18.234501 seconds
BubbleSort V2 Ascending:  14.112233 seconds
...
MergeSort V1 Ascending:   0.021456 seconds
QuickSort V2 Ascending:   0.013201 seconds
```

---

## Key Takeaways

- **Merge Sort and Quick Sort V2** are consistently the fastest across all scenarios (~O(n log n))
- **Bubble Sort and Insertion Sort** are slow on random data but Insertion Sort V2 is near-instant on already-sorted ascending input
- **Quick Sort V1** crashes on sorted input due to stack overflow — V2 (middle pivot) fixes this
- **Selection Sort** has no meaningful best case — it always does O(n²) comparisons regardless of input order

---

## Requirements

- C++ compiler (g++ recommended)
- Input files: `random.txt`, `ascending.txt`, `descending.txt` (each with 100,000 integers, one per line)
