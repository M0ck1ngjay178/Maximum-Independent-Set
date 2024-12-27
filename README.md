# 🌟 Maximum Independent Set

This repository contains implementations of **Brute Force** and **Greedy Algorithms** to find the **Maximum Independent Set (MIS)** of a graph. The Maximum Independent Set problem is a classic optimization problem in graph theory, widely used in various fields such as network design, scheduling, and resource allocation.

## 📑 Table of Contents
- [📖 Introduction](#introduction)
- [🔍 Algorithms](#algorithms)
  - [💻 Brute Force Algorithm](#brute-force-algorithm)
  - [⚡ Greedy Algorithm](#greedy-algorithm)
- [✨ Features](#features)
- [🛠️ Setup and Usage](#setup-and-usage)
- [📊 Performance Comparison](#performance-comparison)
- [🤝 Collaborators](#collaborators)
- [🙌 Acknowledgments](#acknowledgments)

---

## 📖 Introduction
An **independent set** in a graph is a set of vertices such that no two vertices in the set are connected by an edge. The **Maximum Independent Set (MIS)** is the largest possible independent set for a given graph.

This repository provides:
- 🧮 A brute-force algorithm to exhaustively find the MIS.
- ⚡ A greedy algorithm for a faster approximation of the MIS.

---

## 🔍 Algorithms

### 💻 Brute Force Algorithm
The brute force approach systematically explores all possible subsets of vertices to find the largest independent set. While accurate, it has exponential time complexity (\(O(2^n)\)) and is impractical for large graphs.

#### 🔑 Characteristics:
- ✅ Guarantees the exact solution.
- ⏳ Inefficient for graphs with a large number of vertices.

### ⚡ Greedy Algorithm
The greedy algorithm builds the independent set iteratively by selecting vertices based on certain heuristics. While faster, it does not guarantee the largest independent set.

#### 🔑 Characteristics:
- 🚀 Efficient and fast for large graphs.
- 🌟 Provides an approximate solution.

---

## ✨ Features
- 🕸️ Handles both sparse and dense graphs.
- 📏 Outputs the size and composition of the independent set.
- ⏱️ Includes runtime measurement for performance evaluation.

---

## 🛠️ Setup and Usage

### 📋 Prerequisites
Ensure you have a working C++ environment. The code has been tested with:
- 🛠️ GCC Compiler
- 🖥️ Visual Studio Code (VSCode) or any preferred IDE

### ⚙️ Compilation
1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/Maximum-Independent-Set.git
   cd Maximum-Independent-Set
---
### Performance Comparison

**🧮 Brute Force:**  
- **Time Complexity**: \(O(2^n)\)  
  🚦 Suitable for small graphs.

**⚡ Greedy:**  
- **Time Complexity**: \(O(V + E)\)  
  🚀 Suitable for larger graphs but may not always find the optimal solution.

---

### Collaborators

**👨‍💻 Primary Contributors**  
This project was developed collaboratively by:  
- **🟢 BONAL**  
- **🟡 GEREGA**  
- **🔵 RUFFING**

---

### Acknowledgments

We would like to thank everyone who contributed directly or indirectly to the development of this project. Special mentions:  
- 🙏 **Mentors** for guidance and support.  
- 💬 **Peers** for valuable feedback during development.  

💖 Your collaboration and insights are greatly appreciated!
