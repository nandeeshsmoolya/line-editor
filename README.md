# Activity 7 – Simple Line Editor in C

## Team Members

* Nandeesh
* Naman Vijaykumar

## Project Description

This project is a simple command-line line editor developed in C. It allows users to create, view, modify, save, and search a small text document through terminal commands.

## Features Implemented

* Insert a line
* Delete a line
* Display the document
* Save document to a text file
* Load document from a text file
* Search for a word or phrase

## Data Structure

The editor uses an **array of strings** to store the document lines.

This data structure was chosen because it is simple to implement and provides easy access to individual lines. Since this editor is designed for a small document, the shifting required during insertion and deletion is acceptable.

## Files

```text
line_editor.c   - Main C program
HELP.md         - Command and usage guide
README.md       - Project documentation
```

## How to Compile

Open the terminal in the project folder and run:

```bash
gcc line_editor.c -o editor
```

## How to Run

### Windows

```bash
editor.exe
```

### Linux / macOS

```bash
./editor
```

## Example

```text
===== SIMPLE LINE EDITOR =====
1. Insert line
2. Delete line
3. Display document
4. Save file
5. Load file
6. Search
7. Exit
```

## Learning Outcome

Through this activity, we learned how to implement a basic text editor using C, work with arrays and strings, handle files, and organize a program using functions.

## Activity

**Portfolio Building – Activity 7**
**Topic:** Build a Simple Line Editor in C
