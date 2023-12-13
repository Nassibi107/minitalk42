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
Certainly! Here's a customized version of your text for a GitHub README:

---

# Understanding Signals in Unix and POSIX

In the realm of Unix and POSIX-compliant operating systems, a **signal** serves as a standardized notification message. These messages are dispatched asynchronously to running programs, informing them of specific events.

## Sending a Signal

Signals are transmitted by the operating system's kernel under two primary circumstances:

1. **System-wide Events:** The kernel detects system-wide occurrences such as a divide-by-zero error or the completion of a child process.

2. **Process Request:** A process can explicitly request the dispatch of a signal using the `kill` system call. Remarkably, a process can even signal itself using this mechanism.

It's noteworthy that only a single pending signal of any particular type, such as `SIGCHLD`, can exist at a given time. Until this signal is received, the system refrains from sending additional `SIGCHLD` signals.

## Receiving a Signal

While the operating system appears to multitask, it fundamentally engages in rapid context switching, transitioning between processes seamlessly.

### Signal Actions

Upon receiving a signal, a process can respond in various ways:

- **Terminate:** The process concludes abruptly.
- **Core Dump:** The process terminates while generating a core dump—a file encapsulating its memory and registers for subsequent analysis.
- **Ignore:** The signal is disregarded, and the program persists in its regular execution.
- **Stop:** The process's execution is suspended until it receives the `SIGCONT` signal.

For an in-depth exploration of sending and intercepting signals in C, delve into [Sending and Intercepting a Signal in C](https://www.codequoi.com/en/sending-and-intercepting-a-signal-in-c/).

Explore the intricacies of signals and enhance your understanding of Unix and POSIX systems.

---

Feel free to adjust the formatting and structure as needed for your specific use case on GitHub.
