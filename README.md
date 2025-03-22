# 🚀 Energy-Efficient OS Scheduling (Preemptive SJF Algorithm)

This project implements a **Preemptive Shortest Job First (SJF) CPU scheduling algorithm** with **dynamic process input, power consumption tracking, execution table, Gantt Chart visualization, and detailed logging**. The goal is to **reduce energy consumption without compromising performance**.

---

## 📌 Project Overview

- **Algorithm Used**: Preemptive Shortest Job First (SJF) Scheduling
- **Key Features**:  
  ✔ Implements **Preemptive SJF CPU Scheduling**  
  ✔ **Dynamic Process Input** from the user  
  ✔ **Gantt Chart Visualization** of process execution  
  ✔ **Execution Table** with Completion Time, Turnaround Time (TAT), and Waiting Time (WT)  
  ✔ **Power Consumption Tracking** (simulated energy usage)  
  ✔ **Logging System** with timestamps (logs execution details in `log.txt`)

---

## 📂 Project Structure
```
energy-efficent-os-scheduling
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
```
---

## 🛠️ Installation & Compilation

### **🔹 Step 1: Clone the Repository**

```sh
git clone https://github.com/ayanchoudhary76/energy-efficent-os-scheduling.git
cd energy-efficent-os-scheduling
```

### **🔹 Step 2: Compile the Code**

```sh
g++ -Iutils -Imodules main.cpp modules/scheduler.cpp utils/logger.cpp -o scheduler.exe
```

### **🔹 Step 3: Run the Program**

```sh
./scheduler.exe
```

### **🔹 Step 4: Check Logs**

After running the program, check the log file:

```sh
type log.txt
```

---

## 📊 Expected Output (Console)

```
Enter the number of processes: 5
Enter Process ID, Arrival Time, and Burst Time for Process 1: 1 0 5
Enter Process ID, Arrival Time, and Burst Time for Process 2: 2 1 3
Enter Process ID, Arrival Time, and Burst Time for Process 3: 3 2 8
Enter Process ID, Arrival Time, and Burst Time for Process 4: 4 3 6
Enter Process ID, Arrival Time, and Burst Time for Process 5: 5 4 4
```

```
Process Execution Order:
-------------------------------------------------------------------
| Process | Arrival Time | Burst Time | Completion Time | TAT | WT |
-------------------------------------------------------------------
|    P2   |      1       |     3      |       4        |  3  |  0  |
|    P5   |      4       |     4      |       8        |  4  |  0  |
|    P1   |      0       |     5      |       13       | 13  | 8  |
|    P4   |      3       |     6      |       19       | 16  | 10  |
|    P3   |      2       |     8      |       27       | 25  | 17  |
-------------------------------------------------------------------
Total Energy Consumption: 130 units
Average Turnaround Time: 12.2
Average Waiting Time: 7.0
```

---

## 📜 Gantt Chart Visualization (Example)

```
Gantt Chart:
| P1 | P2 | P2 | P2 | P1 | P1 | P1 | P1 | P5 | P5 | P5 | P5 | P4 | P4 | P4 | P4 | P4 | P4 | P3 | P3 | P3 | P3 | P3 | P3 | P3 | P3 |
0    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18   19   20   21   22   23   24   25   26
```

---

## 📑 Logging System (`log.txt`)

After execution, the `log.txt` file contains:

```
[LOG] Starting Preemptive SJF Scheduling...
[LOG] Executing Process P1 at time 0
[LOG] Executing Process P2 at time 1
[LOG] Executing Process P2 at time 2
[LOG] Executing Process P2 at time 3
[LOG] Executing Process P1 at time 4
[LOG] Executing Process P5 at time 8
[LOG] Executing Process P4 at time 12
[LOG] Executing Process P3 at time 18
[LOG] Total Energy Consumption: 130 units
[LOG] Average Turnaround Time: 12.2
[LOG] Average Waiting Time: 7.0
```

---

## 📩 Author

- **Developer**: Ayan Choudhary
- **GitHub**: [My GitHub Profile](https://github.com/your-username)
