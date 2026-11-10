# Minitalk

42 School project — client/server communication using only UNIX signals.

## Description

Minitalk is a pair of programs, a **server** and a **client**, that exchange
a text message without sockets, pipes or files: the only channel is
`SIGUSR1` / `SIGUSR2`, sent with `kill()`.

- The server starts, prints its PID, then waits forever for signals.
- The client receives the server's PID and a string, splits each character
  into 8 bits, and sends one signal per bit: `SIGUSR1` for a `1` bit,
  `SIGUSR2` for a `0` bit.
- The server's signal handler accumulates the 8 bits of each incoming
  character and rebuilds it. A null byte (`\0`) marks the end of the
  message: the server prints the full string and sends `SIGUSR2` back to
  the client as an acknowledgment.
- The client then prints a confirmation once it receives that
  acknowledgment.

## Usage

```bash
make

# terminal 1
./server
# PID <pid>

# terminal 2
./client <pid> "Hello, world!"
```

## Project structure

- `server.c` — signal handler reconstructing the message bit by bit.
- `client.c` — encodes the string into bits and sends it via signals.
- `libft/` — custom C standard library (`ft_printf`, `get_next_line`, ...)
  used by both the client and the server.
- `Makefile` — builds `client` and `server` (`all`, `clean`, `fclean`, `re`).

## Notes

- Only the mandatory part is implemented (no bonus).
- Compiled with the 42 norm flags: `-Wall -Wextra -Werror`.
