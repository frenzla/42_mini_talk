![42banner](https://github.com/user-attachments/assets/32a50147-12ad-4c84-b192-c33ece0b28d1)


# 42_mini_talk

The purpose of this project is to code a small data exchange program using UNIX signals.

Objectives:
- Produce `server` & `client` executables
- `client` must communicate a string passed as a parameter to `server` *(referenced by its process ID)* which then displays it
- Use `SIGUSR1` & `SIGUSR2` signals **ONLY**
- Add reception acknowledgement system
- Support Unicode characters

For detailed information, refer to [the subject of this project](https://github.com/frenzla/42_mini_talk/blob/main/mini_talk_subject.pdf).

Part of my coding mastering journey 🥷

## 42

[42 is a world class computer programming school](https://42.fr/en/homepage/) that proposes a new way of learning computer science:
- No teachers
- No classrooms
- Open 24/7, 365 days/year
- Students are trained through peer-to-peer pedagogy, and project-based learning.
- Methodology that develops both tech & life skills.
- The 42 cursus is free for whoever is approved in its selection process.


## How to Install and Run the Project 

`make` to create the 2 executables.

To run, launch the "server" and the "client" in different shell tabs with the following:

```shell
$ ./server
```

This will show your server's PID.

```shell
$ ./client <PID_SERVER> <STRING>
```

This will show string on the server window.
