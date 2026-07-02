# Password Generator and Evaluator

A C program that generates strong passwords and evaluates password strength based on multiple security criteria.

## Project Description

This program provides two main functionalities:
1. **Password Generator**: Creates random strong passwords with customizable length
2. **Password Evaluator**: Analyzes existing passwords and rates their strength

## Features

- ✅ Generate random passwords with uppercase, lowercase, digits, and special characters
- ✅ Shuffle password characters for better randomness
- ✅ Evaluate password strength based on character diversity
- ✅ Length-based scoring system (6-25+ characters)
- ✅ Penalty system for repeated patterns
- ✅ Interactive menu-driven interface
- ✅ User-friendly feedback and recommendations

## Concepts Used

- **Functions**: Modular programming with generator() and evaluation()
- **Arrays**: Character sets and scoring arrays
- **Strings**: Password manipulation and evaluation
- **Pointers**: Passing passwords by reference
- **Modular Programming**: Separated concerns for generation and evaluation
- **Random Number Generation**: Using rand() and time()
- **Character Checking**: Using ctype library (isupper, islower, isdigit)

## How to Run

### Compile:

gcc -o password-tool password_generator.c

### Execute:

./password-tool        # Mac/Linux
password-tool.exe      # Windows

## How to Use

### Option 1: Generate Password
1. Select option `1`
2. Enter desired password length (8-25 characters)
3. Program generates a strong password
4. Password displayed on screen

### Option 2: Evaluate Password
1. Select option `2`
2. Enter password to evaluate
3. Program analyzes and rates strength
4. Receive score and recommendations

## Example Output
Your Password tools

Password Generator.
Password Evaluator.
Enter your choice --> (1) or (2): 1

Enter the length of your desire password (8-25): 12
Generating Password....
Your password is: K9@mLxP#2qRz

## Scoring System

### Character Diversity Score (0-40 points)
- All 4 types (uppercase, lowercase, digits, special): 40 points
- 2-3 types: 30 points
- 1 type: 15 points

### Length Score (0-50 points)
- < 6 characters: 0 points
- 6-7 characters: 10 points
- 8-11 characters: 20 points
- 12-17 characters: 35 points
- 18+ characters: 50 points

### Pattern Penalties
- Repeated characters (3+ consecutive): -10 points
- Alternating pattern (ABAB): -10 points

### Overall Strength Rating
- **Weak**: Score < 40 (needs improvement)
- **Medium**: Score 40-79 (good but could be stronger)
- **Strong**: Score ≥ 80 (highly secure)

## Password Generation Algorithm

1. Ensure at least one uppercase, lowercase, digit, and special character
2. Fill remaining positions with random character types
3. Shuffle all characters using Fisher-Yates algorithm
4. Null-terminate the string

## Security Features

- Uses time-based seeding for randomness
- Character shuffling prevents predictable patterns
- Evaluates both character diversity and length
- Detects and penalizes common weak patterns
- Provides actionable feedback

## Password Strength Recommendations

- **For Weak Passwords**: Add more characters, numbers, and symbols
- **For Medium Passwords**: Increase length or add more variety
- **For Strong Passwords**: Already excellent security!

## Constraints

- Password length: 8-25 characters
- Maximum password length: 26 characters (including null terminator)
- Special characters supported: !@#$%&*-_

## Future Enhancements

- [ ] Save generated passwords to file
- [ ] Password strength meter with visual feedback
- [ ] Custom character sets for generation
- [ ] Password history tracking
- [ ] Keyboard pattern detection
- [ ] Dictionary word detection
- [ ] Common password database checking

## Learning Outcomes

This project demonstrates:
- Modular function design
- String manipulation in C
- Random number generation
- Character classification
- Algorithm implementation
- User input validation
- Interactive program design

## Skills Demonstrated

- C Programming
- Modular Programming
- Algorithm Design
- String Processing
- Data Validation
- User Interface Design

## Author

Husain Chatiwala (Nirma University CSE)

## Date

Created: November 2025

## License

This project is for educational purposes.
