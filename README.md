# Information Security Lab - Cryptography Algorithms in C

## Overview

This repository contains implementations of classical cryptography algorithms written in C. These programs demonstrate the fundamental concepts of encryption and decryption used in Information Security and Cryptography.

The project was developed as part of Information Security laboratory work to understand how plaintext can be converted into ciphertext and later restored using various encryption techniques.

---

## Algorithms Implemented

### 1. Caesar Cipher

**File:** `Ceaser_cipher.c`

The Caesar Cipher is one of the simplest substitution ciphers. Each letter in the plaintext is shifted by a fixed number of positions in the alphabet.

**Example:**

Plaintext:
HELLO

Shift:
3

Ciphertext:
KHOOR

**Concepts Covered**

* Encryption
* Decryption
* Character manipulation
* ASCII values

---

### 2. Monoalphabetic Cipher

**File:** `monoalphabetic_cipher.c`

The Monoalphabetic Cipher replaces each character of the plaintext with another fixed character according to a substitution table.

**Example:**

Plaintext:
HELLO

Substitution:
A→Q, B→W, C→E ...

Ciphertext:
ITSSG

**Concepts Covered**

* Substitution techniques
* Key mapping
* Encryption and decryption

---

### 3. Playfair Cipher

**File:** `Playfair_Cipher.c`

The Playfair Cipher is a digraph substitution cipher that encrypts pairs of letters instead of single letters.

A 5×5 matrix is generated using a keyword, and encryption rules are applied to each letter pair.

**Concepts Covered**

* Matrix operations
* Digraph encryption
* Classical cryptography

---

### 4. Rail Fence Cipher

**File:** `Rail_Fense_Cipher.c`

The Rail Fence Cipher is a transposition cipher. Characters are arranged in a zigzag pattern across multiple rows and then read row by row to generate the ciphertext.

**Example:**

Plaintext:
HELLO WORLD

Rails:
3

Ciphertext:
HOLELWRDLO

**Concepts Covered**

* Transposition techniques
* Pattern generation
* Data rearrangement

---

## Technologies Used

* C Programming Language
* GCC Compiler
* Command Line Interface

---

## Learning Outcomes

Through this project, the following concepts were learned:

* Fundamentals of Cryptography
* Encryption and Decryption Techniques
* Classical Cipher Algorithms
* String Manipulation in C
* Information Security Basics
* Secure Communication Concepts

---

## How to Run

Compile the program:

```bash
gcc filename.c -o output
```

Run the program:

```bash
./output
```

Example:

```bash
gcc Ceaser_cipher.c -o ceaser
./ceaser
```

---

## Repository Structure

```text
Information-Security-Lab/
│
├── Ceaser_cipher.c
├── monoalphabetic_cipher.c
├── Playfair_Cipher.c
├── Rail_Fense_Cipher.c
└── README.md
```

---

## Author

**Prit Koradiya**

Computer Engineering Student

This repository is created for academic learning and practical understanding of classical cryptographic algorithms.
