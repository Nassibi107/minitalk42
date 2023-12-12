# minitalk42

# Project: Unix Signal Data Exchange

## Table of Contents

- [Project Overview](#project-information)
- [Unix Processes](#unix-processes)
- [Unix Signals](#unix-signals)
- [Used Functions & Brief Explanation](#used-functions--their-brief-explanation)
  - [signal()](#signal)
  - [sigaction()](#sigaction)
  - [struct sigaction](#struct-sigaction)
  - [sigemptyset()](#sigemptyset)
  - [sigaddset()](#sigaddset)
  - [getpid()](#getpid)
  - [kill()](#kill)
  - [pause()](#pause)
  - [sleep()](#sleep)
  - [usleep()](#usleep)
- [Minitalk Explained!](#minitalk-explained)
  - [STEP 1: Make Server Receive a Signal from Client](#step-1-make-server-receive-a-signal-from-client)
  - [STEP 2: Convert ASCII Character to Binary Character](#step-2-convert-ascii-character-to-binary-character)
  - [STEP 3: Convert Binary Character to ASCII Character](#step-3-convert-binary-character-to-ascii-character)
  - [STEP 4: Sending a String from Client to Server](#step-4-sending-a-string-from-client-to-server)
- [Links](#links)

## Project Information

The purpose of this project is to code a small data exchange program using UNIX signals. The project involves creating a communication program in C, comprising both a client and a server. The server, launched first, displays its PID, and the client takes the server's PID and a string as parameters. Once the server receives the string, it displays it.

### Keep in Mind

- Handle errors sensitively; the program should not quit unexpectedly.
- Ensure no memory leaks.
- Use only one justified global variable.

### Mandatory

- Produce server & client executables.
- The client must communicate a string passed as a parameter to the server (referenced by its process ID), which then displays it.
- Use only SIGUSR1 & SIGUSR2 signals.

### Bonus

- Add a reception acknowledgment system.
- Support Unicode characters.

### Allowed Functions (Manual)

- write
- ft_printf and any equivalent YOU coded
- signal
- sigemptyset & sigaddset
- sigaction
- kill
- getpid
- malloc
- free
- pause
- sleep
- usleep
- exit

## Unix Processes

...

(Continue with the content as per the original text.)
-------
This text provides an introduction to signals, which are standardized messages in POSIX-compliant operating systems used for triggering specific behaviors like quitting or error handling. Signals are a form of inter-process communication, interrupting the normal flow of executing processes when sent by the operating system. When a signal is received, the process can take action based on predefined behaviors or custom signal handlers. There are two types of signals: Maskable (can be changed or ignored by the user, e.g., Ctrl+C) and Non-Maskable (cannot be changed or ignored, usually for non-recoverable hardware errors). Signal handlers can be installed using system calls like signal(2) or sigaction(2). Signals are defined in the signal.h header file as macro constants, starting with "SIG" followed by a short description. It emphasizes using signal names instead of signal numbers for portability, as signal numbers can vary between systems. The text also mentions the macro NSIG, representing the total number of defined signals.
