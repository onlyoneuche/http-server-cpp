# HTTP Server in C++

This is a step-by-step implementation of an HTTP server in C++,
originally started as part of the [Codecrafters HTTP Server challenge](https://codecrafters.io).
I later migrated it into my own repo to learn deeper and track progress independently.

---

## 🚀 Features Implemented
- [x] Create and bind a TCP socket
- [x] Accept client connections
- [x] Parse the HTTP request line
- [x] Return `200 OK` for `/`, `404 Not Found` otherwise

---

## 🛠️ Build & Run Locally

### Prerequisites
- C++ compiler (e.g., `g++` or `clang++`)
- `cmake`
- (Optional) `curl` for testing

### Build
```bash
cmake -B build -S .
cmake --build build
