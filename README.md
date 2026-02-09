# C++ Ray Tracer

A simple **CPU-based ray tracer written in C++** as a learning project.

---

## What is Implemented

- Basic ray tracing pipeline
- Sphere ray–intersection
- Scene abstraction using Hittable objects
- Simple materials (Lambertian diffuse, metal, dielectric)
- Recursive ray scattering with depth limit
- Gradient background
- Image output to `.ppm`
- Optional SFML window rendering
- Built using CMake

---

## Warm-up Work

Before the main ray tracer, smaller exercises were completed to practice:

- RAII and memory management
- Smart pointers
- File I/O
- Vector math (dot and cross products)
- Basic multithreading concepts

These live under `examples/` and informed the final design.

---

## Project Structure

src/
- main.cpp
- vec3.h
- ray.h / ray.cpp
- sphere.*
- hittable.*
- hittable_list.*
- material.*
- util.*

---

## Build System

Uses **CMake**.

### Requirements
- C++17 compiler
- CMake (>= 3.16)
- SFML 3 (optional)

---

## Build and Run

1. Create build directory
```
mkdir build
cd build
```

2. Configure
```
cmake ..
```

3. Build
```
cmake --build .
```

4. Run
```
./ray-tracer
```

Save image output:
```
./ray-tracer > output.ppm
```
