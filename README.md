## Learning Objectives

This project is being progressively expanded as a learning exercise to explore:

- C programming
- Data serialization (CSV)
- PostgreSQL
- R for statistical analysis and visualization
- Reproducible scientific workflows




# Game of Life: Boundary Conditions Comparison

## Overview

This project implements Conway's Game of Life in C and compares the evolution of the system under three different boundary conditions:

* Closed boundaries
* Periodic boundaries (torus topology)
* Möbius strip boundaries

The simulation evolves the same initial configuration using the three topologies simultaneously, allowing direct comparison of their behavior.

In addition to the simulation itself, the project exports all generations to a CSV file that can later be analyzed using SQL and R.

---

## Features

* Dynamic memory allocation for arbitrary grid sizes.
* Input loaded from text files.
* Three independent Game of Life implementations:

  * Closed boundaries
  * Periodic boundaries
  * Möbius boundaries
* Side-by-side visualization of the three worlds.
* Export of simulation results to CSV format.
* Designed as a learning project combining:

  * C programming
  * SQL databases
  * Data analysis in R

---

## Input Format

The input file must contain:

1. Number of rows and columns.
2. The initial state of each cell.

Example:

```text
10 10
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 1 1 1 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 1 1 1 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
```

Where:

* `1` = alive cell
* `0` = dead cell

---

## Compilation

Compile using GCC:

```bash
gcc game.c -o game
```

Run:

```bash
./game
```

The program will ask for the name of the input file.

---

## Output

The simulation generates a CSV file:

```text
life.csv
```

Structure:

```csv
generation,row,col,state,topology
0,0,0,1,closed
0,0,1,0,closed
0,0,2,1,closed
...
```

Columns:

| Column     | Description                 |
| ---------- | --------------------------- |
| generation | Simulation step             |
| row        | Cell row                    |
| col        | Cell column                 |
| state      | 0 = dead, 1 = alive         |
| topology   | closed, periodic, or mobius |

---

## Project Structure

```text
.
├── game.c
├── life_input.txt
├── life.csv
├── sql
│   ├── create_tables.sql
│   └── queries.sql
└── R
    └── analysis.R
```

---

## SQL Analysis

The generated CSV can be imported into PostgreSQL.

Example table:

```sql
CREATE TABLE life (
    generation INTEGER,
    row_num INTEGER,
    col_num INTEGER,
    state INTEGER,
    topology VARCHAR(20)
);
```

Example query:

```sql
SELECT generation,
       COUNT(*) AS alive_cells
FROM life
WHERE state = 1
GROUP BY generation
ORDER BY generation;
```

---

## R Analysis

The exported data can be analyzed in R using:

* dplyr
* ggplot2
* gganimate

Example:

```r
library(dplyr)
library(ggplot2)

alive <- life %>%
  filter(state == 1) %>%
  group_by(generation, topology) %>%
  summarise(alive = n())

ggplot(alive,
       aes(generation, alive, color = topology)) +
  geom_line()
```

---

## Future Improvements

* Detection of oscillators and still lifes.
* Automatic cycle detection.
* Performance optimization.
* Additional boundary conditions.
* Direct database export.
* Interactive visualization.

---

## Purpose

This project started as a C implementation of Conway's Game of Life and evolved into a complete data-analysis workflow:

**C → CSV → SQL → R**

The goal is to practice simulation, data storage, querying, and statistical analysis within a single project.
