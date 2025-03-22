# 🚀 Energy-Efficient OS Scheduling (SJF Algorithm)

This project implements a **Shortest Job First (SJF) CPU scheduling algorithm** with **power consumption tracking, Gantt Chart visualization, and logging**. The goal is to **reduce energy consumption without compromising performance**.

---

## 📌 Project Overview

- **Algorithm Used**: Shortest Job First (SJF) (Non-Preemptive)
- **Key Features**:  
  ✔ Implements **SJF CPU Scheduling**  
  ✔ **Gantt Chart Visualization** of scheduled processes  
  ✔ **Power Consumption Tracking** (simulated energy usage)  
  ✔ **Logging System** (logs execution details in `log.txt`)

---

## 📂 Project Structure

energy-efficient-os-scheduling  
│── main.cpp  
│── README.md  
│── Makefile (optional)  
│── log.txt (Generated after running the program)  
│── modules  
│ ├── scheduler.h  
│ ├── scheduler.cpp  
│── utils  
│ ├── logger.h  
│ ├── logger.cpp

## 🛠️ Installation & Compilation

### 🔹 Step 1: Clone the Repository

```sh
git clone https://github.com/your-username/energy-efficient-os-scheduling.git
cd energy-efficient-os-scheduling
```

### 🔹 Step 2: Compile the Code

```sh
g++ -Iutils -Imodules main.cpp modules/scheduler.cpp utils/logger.cpp -o scheduler.exe
```

### 🔹 Step 3: Run the Program

```sh
./scheduler.exe
```

### 🔹 Step 4: Check Logs

After running the program, check the log file:

```sh
type log.txt
```

---

## 📊 Expected Output (Console)

### Scheduled Processes (SJF Order):

```
-----------------------------------------
| Process | Arrival Time | Burst Time | Completion Time | Energy Used |
-----------------------------------------
|    P4   |      3       |     3      |       3         |     15      |
|    P1   |      0       |     6      |       9         |     30      |
|    P3   |      2       |     7      |       16        |     35      |
|    P2   |      1       |     8      |       24        |     40      |
-----------------------------------------
Total Energy Consumption: 120 units
```

### Gantt Chart Visualization:

```
Gantt Chart:
| P4 | P1 | P3 | P2 |
0     3     9    16    24
```

---

## 📑 Logging System (log.txt)

After execution, the `log.txt` file contains:

```
[LOG] Initializing SJF Scheduler...
[LOG] Process 4 executed, Completion Time: 3, Energy Used: 15
[LOG] Process 1 executed, Completion Time: 9, Energy Used: 30
[LOG] Process 3 executed, Completion Time: 16, Energy Used: 35
[LOG] Process 2 executed, Completion Time: 24, Energy Used: 40
[LOG] Total Energy Consumption: 120 units
```

---

## 📩 Author

**Developer**: Ayan Choudhary  
GitHub: [Your GitHub Profile](https://github.com/ayanchoudhary76)
