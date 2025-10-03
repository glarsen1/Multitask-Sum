# Multitask Sum (C, Pthreads)

This project demonstrates **multithreading in C** using the POSIX threads (`pthreads`) library.  
The program initializes an array of integers (1–10) and creates multiple worker threads. Each thread cooperatively sums elements of the array, reducing it step by step until only the final total remains.

---

## Features
- Implementation of **multithreading** with `pthread_create` and `pthread_join`.
- **Mutex synchronization** to ensure thread-safe operations on shared data.
- Demonstrates cooperative reduction of an array to compute the **final sum**.
- Example of applying concurrency in a simple aggregation task.

---

## 📂 Project Structure
- Multitask_Sum.c # Source code
- Multitask_Sum.txt # Text file
- multitask_sum.exe # Application
- outDebug.exe # Application
- README.md # Project description and instructions


---

## 🛠️ Requirements
- GCC or any C compiler with pthreads support  
- POSIX threads library (`pthreads`)

On Windows, you can use [MinGW-w64](https://winlibs.com/) or MSYS2.  
On Linux/macOS, `pthreads` is usually pre-installed.

---

## ⚡ Compilation
Use the following command to compile:

```bash
gcc Multitask_Sum.c -o multitask_sum -lpthread

