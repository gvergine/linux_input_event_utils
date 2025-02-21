# linux input event utils

This repository contains the source code of two programs that read and write `input_event`s.

* `ie2t` - input event to text - reads input events and prints them out in text format
* `t2ie` - text to input event - reads textual representation of the event and write it as an input_event


## usage

Both utilities are unix filters (i.e. read from stdin and write on stdout).

### ie2t

Synopsis: `ie2t < /dev/input/event0` or `cat /dev/input/event0 | ie2t` 

E.g:

```
# ie2t < /dev/input/event0
```
Then interact with the system and check the events printed
```
time=1740126112.603678 type=3 code=57 value=47
time=1740126112.603678 type=3 code=53 value=790
time=1740126112.603678 type=3 code=54 value=1164
time=1740126112.603678 type=0 code=0 value=0
time=1740126112.709216 type=3 code=57 value=-1
time=1740126112.709216 type=0 code=0 value=0
```

### t2ie

Synopsis: `t2ie > /dev/input/event0`

E.g:
```
# t2ie > /dev/input/event0
```
Then write in the stdin the events
```
type=3 code=57 value=47
type=3 code=53 value=790
type=3 code=54 value=1164
type=0 code=0 value=0
type=3 code=57 value=-1
type=0 code=0 value=0
```
and see the outcome on the system.