*This project has been created as part of the 42 curriculum by andtruji, bsiguenc.*

# MiniRT

A simple 3D ray tracing engine written in C using MiniLibX.

---

## Description
**MiniRT** is a basic 3D ray tracing engine developed in C as part of the 42 school curriculum. The goal of this project is to model 3D scenes using fundamental ray-tracing principles, rendering realistic computer-generated images complete with ambient lighting, diffuse illumination, directional light sources, hard shadows, and geometric primitives.

The application reads and parses scene configuration files formatted as `.rt` files, which contain all specifications for ambient lighting, cameras, light sources, spheres, planes, and cylinders. Once the scene file is parsed and validated, the program computes ray-primitive intersections, calculates pixel color values, and renders the output image inside a MiniLibX display window.

---

## Features
- **Geometric Primitives:** Analytical ray intersection logic for Spheres, Planes, and Cylinders.
- **Lighting & Shadows:** Ambient lighting, diffuse illumination, and ray-traced hard shadows.
- **Scene File Parser:** Robust parsing and validation of `.rt` configuration files with comprehensive error handling.
- **Window & Event Management:** Clean event handling for window lifecycle events (`ESC` key press and window close button).

---

## Instructions

### Prerequisites
- GCC or Clang compiler
- GNU Make
- MiniLibX graphics library and system dependencies (X11 on Linux / AppKit & OpenGL on macOS)

### Compilation
Clone the repository and build the executable using `make`:
```bash
git clone [https://github.com/AndrewTowers/miniRT.git](https://github.com/AndrewTowers/miniRT.git)
cd miniRT
make