# RPi Zero 2W Random Number Guess Game

A small embedded Linux project running on **Raspberry Pi Zero 2W**, built using **Yocto**.  
The goal is to create an interactive "Random Number Guess" game displayed on an **I2C display**.

---

## Overview

This project focuses on learning and experimenting with embedded Linux development in a practical, hardware-driven way.

It uses:
- Raspberry Pi Zero 2W
- Yocto-based custom Linux image
- C++ userspace application
- I2C communication
- I2C LCD/OLED display (e.g., 16x2 LCD or SSD1306 OLED)

The game generates a random number and lets the user guess it, with feedback shown on the display.

---

## Hardware

- Raspberry Pi Zero 2W
- I2C display (16x2 LCD or SSD1306 OLED)
- I2C interface (enabled via device tree / Yocto configuration)

---

## Goals

The project is structured as a sequence of small, verifiable steps:

1. Establish I2C communication with the display
2. Initialize the display and show static text
3. Implement random number generation logic
4. Create user input mechanism (buttons or serial)
5. Implement game logic (compare guess vs random number)
6. Display feedback (too high, too low, correct!)

---

## Application

The main userspace application is:

```
game
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
Confirm that the display is visible on the I2C bus.

### Level 2 — Display Initialization
Initialize the display and verify it works.

### Level 3 — Static Text
Display static text on the screen.

### Level 4 — Random Number Generation
Implement random number generation logic.

### Level 5 — Input Mechanism
Implement user input (buttons or serial).

### Level 6 — Game Logic
Implement guess comparison and feedback.

### Level 7 — Game Flow
Complete game flow (new game, guess, win/lose).

---

## Philosophy

- Every step must be verifiable
- Focus on small feedback loops
- Prioritize understanding hardware behavior over feature complexity
- Keep development incremental and observable

---

## Notes

- Display may require specific initialization sequence
- I2C address may vary depending on display module
- Early stages prioritize correctness over features

---

## License

Educational use only.
