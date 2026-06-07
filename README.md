# Student Management System (C)

A simple command-line Student Management System written in C that allows users to manage student records using dynamic memory allocation and basic data structures.

## Features

* Add new student(s)
* View all students
* Search students by roll number
* Update student information (name, age, cgpa or everything)
* Delete student record from the list
* Dynamic memory allocation using `malloc`
* Binary search implementation for fast student lookup

---

## Project Structure

### Student Structure

```c
struct student {
    int rollno;
    char name[50];
    int age;
    float cgpa;
};
```

Each student record contains:

| Field  | Description        |
| ------ | ------------------ |
| rollno | Unique roll number |
| name   | Student name       |
| age    | Student age        |
| cgpa   | Student CGPA       |

---

## Available Operations

### 1. Add Student

Adds a new student to the system.

Information required:

* Name
* Age
* CGPA

Roll numbers are assigned automatically. (based on the indexes of the students)

---

### 2. View All Students

Displays all student records currently stored in the system.

Displayed information:

* Name
* Age
* Roll Number
* CGPA

---

### 3. Search Student

Searches for a student using their roll number.

The program uses Binary Search to find records efficiently.

**Time Complexity:** O(log n)

---

### 4. Update Student

Allows updating:

* Name
* Age
* CGPA
* All details at once

---

### 5. Delete Student

Removes a student record from the system.

After deletion, remaining records are shifted to fill the empty space.

---

### 6. Exit

Terminates the program and frees allocated memory.

---

## How to Compile

Using GCC:

```bash
gcc student_management.c -o student_management
```

---

## How to Run

```bash
./student_management
```

On Windows:

```bash
student_management.exe
```

---

## Sample Menu

```text
#############################
 # STUDENT MANAGEMENT SYSTEM #
#############################

1. Add Student
2. View All Students
3. Search Student
4. Update Student
5. Delete Student
6. Exit
```

---

## Memory Management

The program dynamically allocates memory for up to 20 students:

```c
struct student* mahindra =
    (struct student*)malloc(20 * sizeof(struct student));
```

Allocated memory is released before program termination:

```c
free(mahindra);
```

---

## Limitations

* Maximum capacity is fixed at 20 students.
* Student data is not saved to a file.
* Data is lost when the program exits.
* Binary search assumes records remain sorted by roll number.
* Input validation is limited.
* Names may contain newline characters because `fgets()` is used without removing the trailing newline.

---

## Possible Improvements

* Store data in files for persistence.
* Automatically resize storage using `realloc()`.
* Add sorting functionality.
* Improve input validation.
* Allow custom roll numbers.
* Remove trailing newline characters from names.
* Add confirmation prompts before deletion.
* Create a menu loop that redisplays options after every operation.

---

## Concepts Demonstrated

This project demonstrates:

* Structures in C
* Dynamic memory allocation (`malloc`, `free`)
* Functions
* Arrays of structures
* Binary Search
* CRUD Operations (Create, Read, Update, Delete)
* User input handling
* Menu-driven programming

---

## Author

Student Management System developed in C as a beginner/intermediate project for learning data structures, memory management, and CRUD operations.
