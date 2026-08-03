# Stone, Paper, Scissors Game (C++)



A console-based **Stone, Paper, Scissors** game built with C++. The project demonstrates fundamental programming concepts, memory efficiency, and console customization using the Windows API.



---



## 🚀 Key Features & Architectural Highlights



* **O(1) Evaluation Matrix:** Instead of using long, nested `if-else` blocks or conditional switches to determine the round winner, the game utilizes a performance-optimized **3x3 Look-Up Table (2D Array)**. This makes score evaluation instant and highly readable.

* **Dynamic Console Feedback:** Leverages Windows API (`windows.h`) to dynamically change console text colors and background attributes based on game states (Win/Loss/Draw).

* **Input Validation:** Robust error handling preventing crashes or invalid inputs using overloaded functions and range-bound checks.

* **Modular Architecture:** Clean separation of concerns through specialized structures (`stRoundInfo`, `stGameResults`) and enums.



---



## 🛠️ Code Insights: The Look-Up Table Matrix



Here is how the game instantly decides the winner without conditional branching:



```cpp

// 1 = Player, 2 = Computer, 3 = Draw

short arrResults[3][3] = {

&#x20;   {3, 2, 1}, // Player chose Stone

&#x20;   {1, 3, 2}, // Player chose Paper

&#x20;   {2, 1, 3}  // Player chose Scissor

};

return (enWinner)arrResults[PlayerChoice - 1][ComputerChoice - 1];
```
## 👾Here is how game experience looks:
```
How Many Rounds 1 to 10 ? : 3

Your Choice : [1]:Stone , [2]:Paper , [3]:Scissor >> 3

.----------------Round[1]----------------.
Player Choice   : Scissor
Computer Choice : Stone
Round Winner    : [Computer].
.----------------------------------------.

Your Choice : [1]:Stone , [2]:Paper , [3]:Scissor >> 2

.----------------Round[2]----------------.
Player Choice   : Paper
Computer Choice : Paper
Round Winner    : [Draw].
.----------------------------------------.

Your Choice : [1]:Stone , [2]:Paper , [3]:Scissor >>
1

.----------------Round[3]----------------.
Player Choice   : Stone
Computer Choice : Scissor
Round Winner    : [Player].
.----------------------------------------.
                        --------------------------------------------------------------
                                                G a m e  O v e r
                        --------------------------------------------------------------
                        .-----------------------[Game Results]-----------------------.
                         Game Rounds        : 3
                         Player won times   : 1
                         Computer won times : 1
                         Draw times         : 1
                         Final Winner       : [Draw].
                        .-------------------------------------------------------------.

Do You want to play again ? [Y/N] :
```


---
## 💻 Related Projects

If you'd like to explore more of my C++ journey and see how I build data structures, algorithms, and complete applications from scratch, check out these repositories.

---

### 📚 C++ Data Data Structures & Algorithms From Scratch

A collection of advanced Data Structures and Algorithms implemented completely from scratch in C++.

This repository contains:

- Custom implementations of Linked List, Stack, Queue, Dynamic Array, String, and more.
- Every data structure includes a dedicated **test file (.cpp)** with practical examples.
- Multiple implementations of the same project to compare different approaches (Custom Data Structures vs STL).
- Solutions and projects from **Programming Advices – Algorithms & Problem Solving Level 5** course.

Most of these classes are extensions of the libraries available in **MyCppToolboxLibraries**.

https://github.com/yahiaalsebaie/CppDataStructuresFromScratch

---

### 🔧 MyCppToolboxLibraries

My personal C++ library built completely from scratch.

It contains reusable utility classes that I developed throughout my programming journey, including:

- Date & Time
- String
- Input Validation
- Utility Functions
- Period
- And many more...

Many of the projects below are built on top of these libraries.

https://github.com/yahiaalsebaie/MyCppToolboxLibraries

---

### 🏦 Bank System (OOP)

Object-Oriented implementation of a complete banking system.

Includes the Currency Exchange project.

https://github.com/yahiaalsebaie/Bank-System-OOP

---

### 🏦 Bank Management System (Procedural Programming)

The same banking system implemented using Procedural Programming.

https://github.com/yahiaalsebaie/Bank-Management-System-Cpp

---

### 🏧 ATM System

Complete ATM simulation.

https://github.com/yahiaalsebaie/ATM-System-Course08

---

### 📅 Dual Calendar System

Gregorian & Hijri Calendar Library.

Features:

- Date calculations
- Date arithmetic
- Historical dates
- Astronomical calculations
- Date differences

https://github.com/yahiaalsebaie/Dual-Calendar-System-MiladiAndHijiri

---

### 🎮 Math Game

Console Math Game.

https://github.com/yahiaalsebaie/cpp-Math-Game

---

### ✂️ Stone Paper Scissors Game

Console implementation of the classic game.

https://github.com/yahiaalsebaie/stone-paper-scissors-cpp-game

---

# ⭐ If you find this repository useful...

Please consider giving it a ⭐.

It helps others discover the project and motivates me to continue improving it.

