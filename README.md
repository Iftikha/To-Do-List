# Simple To-Do List Application

## Overview
This is a simple command-line To-Do List application built using C++. It allows users to manage their tasks efficiently by providing features to add, view, mark as done, and delete tasks. The application is designed for beginners to practice basic programming concepts like loops, conditional statements, and dynamic arrays.

---

## Features
- **Add Task:** Add a new task with a description and automatically assigned ID.
- **View Tasks:** View all tasks with their ID, description, status (done or not), and date added.
- **Mark as Done:** Mark a specific task as completed.
- **Delete Task:** Remove a task from the list by its ID.
- **Persistent Task IDs:** Ensures unique task IDs for all tasks.

---

## Requirements
- C++ Compiler (e.g., GCC, Clang, MSVC)
- Basic understanding of C++ and terminal usage

---

## How to Use
### 1. Clone the Repository
```
git clone https://github.com/Iftikha/To-Do-List
cd To-Do-List

```

### 2. Compile the Code
Use a C++ compiler to build the application:
```
g++ -o main main.cpp

```

### 3. Run the Application
Run the compiled program:
```
./main

```

### 4. Use the Menu
The application presents a menu with the following options:
```
1. Add Task
2. View Tasks
3. Mark Task as Done
4. Delete Task
5. Exit
```
Choose an option by entering the corresponding number.

---

## Code Structure
- **`addTask()`**: Adds a new task with a unique ID and description.
- **`viewTasks()`**: Displays all tasks, showing their details and statuses.
- **`markDone()`**: Marks a task as completed based on its ID.
- **`deleteTask()`**: Deletes a task by its ID and reassigns IDs if needed.
- **`main()`**: Provides the menu interface and handles user input.

---

## Example Usage
### Adding a Task:
```
Enter task description: Complete the project
Task added with ID: 1
```

### Viewing Tasks:
```
Task ID: 1, Description: Complete the project, Status: No, Date Added: 2024-12-25
```

### Marking a Task as Done:
```
Enter the task ID: 1
Task marked as done!
```

### Deleting a Task:
```
Enter the task ID: 1
Task deleted successfully!
```

---

## Future Enhancements
- Add file-based persistence to save tasks across sessions.
- Implement a user-friendly GUI.
- Allow filtering tasks based on their status (not done).

---

## Contributing
Feel free to fork this repository, make changes, and submit a pull request. Contributions are welcome!

---

## License
This project is open-source and available under the [MIT License](LICENSE).

---

## Author
**Iftikhar Ahmed**
- [GitHub Profile](https://github.com/iftikha)
