# C++ Ray Tracer (In Progress)
A ray tracer written in C++ with planned features including:
- Bounding Volume Hierarchies (BVH) for acceleration
- Recursive reflections
- Multithreading for performance

---

## Warm-up and Ray Tracing Exercises
COMPLETED a set of smaller exercises to get more comfortable with:
- Memory management (RAII, smart pointers)
- Multithreading
- File I/O
- Vector math (dot/cross products)

These are collected under `examples/` and serve as the foundation for the main project.

---

## Implementation
Started Working on the main ray tracer:
- Implemented core classes: Vec3, Ray, Sphere, Hittable.
- Implemented basic sphere intersection, simple gradient background.
- Image outputs to `.ppm`
- Working on suface normals and coloring, Lambertian diffuse shading, multiple objects.

Progress can be checked under `src/`

---

## Build with CMake
This project uses **CMake** as its build system.

### Requirements
```
sudo apt install cmake g++
```
---

## To Build and Run

### 1. Create a build directory
```
mkdir build
cd build
```

### 2. Generate build files using CMake
```
cmake ..
```

### 3. Compile the project
```
make
```

### 4. Run the ray tracer
```
./ray-tracer
```

To save output:
```
./ray-tracer > output.ppm
```

---
