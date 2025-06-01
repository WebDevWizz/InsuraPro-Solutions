# InsuraPro Solutions – Console-Based CRM System in C++

InsuraPro Solutions is a lightweight, object-oriented Customer Relationship Management (CRM) application developed in C++ for insurance companies seeking to improve client service efficiency and internal data management.

## 📋 Project Overview

Insurance companies often struggle with fragmented and non-intuitive client data systems. InsuraPro addresses this gap by providing a centralized, console-based CRM that allows sales teams and customer service representatives to manage customer records and interaction histories efficiently and interactively.

## 🎯 Key Features

- **Client Management**
  - Add, edit, delete, and view clients
  - Search clients by name or surname
- **Interaction Management**
  - Record customer interactions (e.g., appointments, contracts)
  - View and search interactions associated with each client
- **Persistent Storage**
  - Automatically loads data from CSV files at startup
  - Saves changes back to disk after each operation
- **User Interface**
  - Text-based menu with clear and intuitive navigation

## 💻 Technologies Used

- **C++**
  - Fully object-oriented design using encapsulation and data abstraction
  - Modular structure using custom header and implementation files
- **CSV for Data Storage**
  - Persistent client and interaction data stored in plain text files


## 🚀 Getting Started

### Prerequisites

- C++ compiler (e.g., `g++`, `clang++`)
- Standard C++17 support or later

### How to Run

1. Compile the code:
   ```bash
   g++ -std=c++17 main.cpp Client.cpp Interazioni.cpp -o insurapro

2. Run the program:
   ```bash
   ./insurapro


## 📈 Future Improvements

- File encryption for sensitive data
- Export reports or summaries
- GUI interface with Qt or another framework
- Networked multi-user access
