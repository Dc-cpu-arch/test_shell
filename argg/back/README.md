[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]




# Simple Shell (Shelldon)
Let us introduce Shelldon, our simple_shell project that must have the same behavior thah sh shell in output and error. Our goal was to learn develop teamwork and imporve individual skills reagarding code.


---
## RESOURCES :books:
</div>

* [Unix shell](https://www.geeksforgeeks.org/introduction-linux-shell-shell-scripting/)
* [Thompson shell](https://brennan.io/2015/01/16/write-a-shell-in-c/)

* [ken Thompson](https://medium.com/@josefgoodyear/building-a-linux-shell-in-c-8be5e109458b)

* [Making your own Linux Shell in C](https://www.geeksforgeeks.org/making-linux-shell-c/)

---
<div align="center">

## Let's start :warning:

</div>

Clone this repo:

```
$ git clone https://github.com/valeria2426/simple_shell.git
```

Compile with

```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

Execute it:
```
$ ./hsh
```
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
---

## USAGE:  :heavy_exclamation_mark: :heavy_exclamation_mark:

</div>

### INTERACTIVE MODE:

```
$ <command> <flags> <argument>
```
EXAMPLE:

* INPUT:
```
$ echo Hello World!
```
* OUTPUT:
```
 Hello World!
```
<div align="center"><img src="images/hello_world.png" width="200" height="50" /> </div>

### NON-INTERACTIVE MODE:

```
$ echo <commands and arguments> | ./hsh
```
EXAMPLE:

* INPUT:
```
$ echo "ls -l" | ./hsh
```

* OUTPUT
```
total 140
-rw-rw-r-- 1 vagrant vagrant 639 Aug 13 19:14 0_principal_header.h
(...)
```
<div align="center"><img src="images/ls.png" width="480" height="150" /> </div>
---
<div align="center">

---

## BUILT-IN COMMANDS


| Command | Description  |
| ------- | --- |
| exit | Exit simple shell|
| env | Display environment variables |
| setenv | Set environment variable value or create a new one |
| unsetenv | Delete environment variable |


---

---

### AUTHORS
* **Valeria Trujillo Rodriguez** - [valeria2426](https://github.com/valeria2426) :sunglasses:
* **Nicolás Urrea Rangel** - [Nicolas](https://github.com/Nicolas) :sunglasses:
* **Camilo Garzon** - [Camilo Garzon](https://github.com/Dc-cpu-arch) :sunglasses:


[contributors-shield]: https://img.shields.io/github/contributors/valeria2426/simple_shell?style=flat-square
[contributors-url]: https://github.com/valeria2426/simple_shell/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/valeria2426/simple_shell.svg?style=flat-square
[forks-url]: https://github.com/valeria2426/simple_shell/network/members
[stars-shield]: https://img.shields.io/github/stars/valeria2426/simple_shell.svg?style=flat-square
[stars-url]: https://github.com/valeria2426/simple_shell/stargazers
[issues-shield]: https://img.shields.io/github/issues/valeria2426/simple_shell?style=flat-square
[issues-url]: https://github.com/valeria2426/simple_shell/issues
