# RPi Zero 2W IMU Motion Visualizer (GY-BMI160)

A small embedded Linux project running on **Raspberry Pi Zero 2W**, built using **Yocto**.  
The goal is to interface with a **GY-BMI160 6-axis IMU (accelerometer + gyroscope)** over I2C and visualize motion in real time in a terminal-based interface.

---

## Overview

This project focuses on learning and experimenting with embedded Linux development in a practical, hardware-driven way.

It uses:
- Raspberry Pi Zero 2W
- Yocto-based custom Linux image
- C++ userspace application
- I2C communication
- GY-BMI160 6-axis IMU (accelerometer + gyroscope)

The end goal is to read motion data from the sensor and visualize it as a real-time 2D position (and optionally a simple physics simulation) in the terminal.

---

## Hardware

- Raspberry Pi Zero 2W
- GY-BMI160 (6-axis IMU: accelerometer + gyroscope)
- I2C interface (enabled via device tree / Yocto configuration)

---

## Goals

The project is structured as a sequence of small, verifiable steps:

1. Establish I2C communication with the IMU
2. Read and verify sensor registers
3. Read raw accelerometer / gyroscope data
4. Convert raw values into meaningful motion data
5. Visualize motion in a terminal-based 1D/2D display
6. (Optional) Add smoothing / “ball-like” motion behavior

---

## Application

The main userspace application is:

```
tilt-grid
```

A C++ application built with a typical embedded workflow (CMake via Make helpers, cross-compilation via Yocto SDK).

---

## Build & Development Workflow

### Generate build system

```bash
make generate
```

### Build application

```bash
make build
```

### Deploy to device

```bash
make deploy
```

### Connect via SSH

```bash
make ssh
```

---

## Typical Development Loop

1. Modify C++ source code locally
2. Generate build system (`make generate`)
3. Build (`make build`)
4. Deploy to Raspberry Pi (`make deploy`)
5. Run and test on device via SSH

---

## Development Stages

### Level 1 — I2C Detection
Confirm that the IMU is visible on the I2C bus.

### Level 2 — Register Read
Read basic device registers (e.g. chip ID).

### Level 3 — Register Write/Read
Verify two-way communication with the sensor.

### Level 4 — Motion Data
Read raw accelerometer and gyroscope data.

### Level 5 — Interpretation
Convert raw sensor data into meaningful motion values.

### Level 6 — 1D Visualization
Map motion to a single-axis terminal visualization.

### Level 7 — 2D Visualization
Extend visualization into a 2D grid.

### Level 8 — Optional Physics Layer
Add smoothing, inertia, or “ball-like” motion behavior.

---

## Philosophy

- Every step must be verifiable
- Focus on small feedback loops
- Prioritize understanding hardware behavior over feature complexity
- Keep development incremental and observable

---

## Notes

- Sensor output may be noisy and require filtering
- Calibration may be required depending on configuration
- Early stages prioritize correctness over precision

---

## License

Educational use only.
