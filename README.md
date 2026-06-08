# Quiz-Game-with-Question-Bank

A C programming project that implements a quiz game with a file-based question bank, multiple difficulty levels, randomized questions, scoring system, and high score tracking.

## Features
- Load questions from external file (`questions.txt`)
- Three difficulty levels: Easy, Medium, Hard
- Randomized question order
- Score calculation with difficulty multiplier
- High score saving and loading
- Input validation and error handling

## How to Compile and Run

```bash
gcc -o quiz_game quiz_game.c
./quiz_game
```

## File Structure

- `quiz_game.c` - Main source code
- `questions.txt` - Question bank file
- `highscore.txt` - Auto-generated high score file
- `LICENSE` - MIT License
- `README.md` - Project documentation

## Question File Format

```
question|optionA|optionB|optionC|optionD|answer|difficulty
```

- **Answer**: A, B, C, or D
- **Difficulty**: 1 (Easy), 2 (Medium), 3 (Hard)

## Concepts Used

- Arrays, Structures, Strings
- File Handling (read/write)
- Random number generation
- Loops and control structures
- Functions and pointers
