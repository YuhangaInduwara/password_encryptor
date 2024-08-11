# PasswordGenerator

## Overview

This C program is designed to validate and encrypt passwords according to specific security rules. It ensures the input password meets predefined criteria and then encrypts it using a series of transformations. The encryption process involves:

- Adding 4 to each digit in the password.
- Converting all lowercase letters to uppercase.
- Adding the length of the string at the beginning of the password.
- Appending `*` to the end of the password.
- Reversing the resulting string.

## Features

- **Password Validation:** Ensures the password is between 6 and 9 characters long and contains at least one numeric digit.
- **Encryption Process:** Implements a series of transformations including digit adjustment, letter case conversion, length prefixing, and string reversal.
- **Error Handling:** Provides informative error messages for invalid passwords and prompts the user to re-enter valid input.

## Usage Instructions

1. **Compilation:**
   - To compile the program, use the following command:
     ```bash
     gcc -o password_encryptor password_encryptor.c
     ```

2. **Execution:**
   - Run the compiled executable using the following commands:
     - **Windows:**
       ```bash
       password_encryptor.exe
       ```
     - **Linux/Mac:**
       ```bash
       ./password_encryptor
       ```

## Example

Given the input password `Hello3`, the program generates the following encrypted password:

```plaintext
*7OOLLEH6
