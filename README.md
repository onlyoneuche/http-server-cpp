# HTTP Server in C++

This is a step-by-step implementation of an HTTP server in C++,
originally started as part of the [Codecrafters HTTP Server challenge](https://codecrafters.io).
I later migrated it into my own repo to learn deeper and track progress independently.

---

## 📚 Roadmap (Next Steps)

This project follows the Codecrafters HTTP challenge outline.  
Completed steps are marked with ✅, pending ones with ⬜.

- ✅ Introduction
- ✅ Repository Setup
- ✅ Bind to a port
- ✅ Respond with 200
- ✅ Extract URL path
- ⬜ Respond with body
- ⬜ Read header
- ⬜ Concurrent connections
- ⬜ Return a file
- ⬜ Read request body
- ⬜ HTTP Compression
  - ⬜ Compression headers
  - ⬜ Multiple compression schemes
  - ⬜ Gzip compression
- ⬜ Persistent Connections
  - ⬜ Persistent connections
  - ⬜ Concurrent persistent connections
  - ⬜ Connection closure


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
