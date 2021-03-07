# Spell

Spell is a Command-Line program written in C which spell-checks text files using a self-implemented separate-chaining Hash Table.

## Description

Spell works by reading an optional user-specified dictionary or a default dictionary which contains 143,091 words into memory, 
placing each word of the dictionary into a Hash Table. Thereafter, the program opens a user-specified text-to-spell-check and proceeds
to validate each word of the text as being correctly typed by checking if the word is present in the Hash Table. Ultimately, Spell
displays various measures relating to spell-checking execution along with overall algorithm run-time.

## Getting Started

### Installation

1. Install the ```spell-master``` archive by downloading [```spell-master.zip```](https://github.com/tchitete1/spell/archive/master.zip)
2. Open a new terminal window in the directory where the archive was downloaded
3. Unzip the archive using the following command to obtain the ```spell-master``` directory:
```
unzip spell-master.zip
```
4. Change into the ```spell-master``` directory by executing the following command:
```
cd spell-master
```

### Compilation

* To compile ```spell```, enter the following:
```
make
```

### Execution

* To execute ```spell```, execute the following:
```
./spell [dictionary] <text>
```
where ```dictionary``` is either ```small``` or ```large```, located in the ```dictionaries``` directory. 
If this argument is omitted, ```large``` will be loaded as the dictionary. ```text``` is any one of the text files
located in the ```texts``` directory.

* Upon execution, the terminal should output something similar to the following:

```
$ ./spell texts/birdman.txt
MISSPELLED WORDS

BIRDMAN
Written
Alejandro
[...]
Fox

WORDS MISSPELLED:     6131
WORDS IN DICTIONARY:  143091
WORDS IN TEXT:        21798
TIME IN load:         0.05
TIME IN check:        0.02
TIME IN size:         0.00
TIME IN unload:       0.06
TIME IN TOTAL:        0.14
```

### Restoration

* To restore the ```spell-master``` directory back to its original state, execute the following command:
```
make clean
```

## Author

Tanaka Chitete
* [Linkedin](https://www.linkedin.com/in/tanaka-chitete/)

## Acknowledgments

* Thank you to [DomPizzie](https://github.com/DomPizzie) for the [template](https://gist.github.com/DomPizzie/7a5ff55ffa9081f2de27c315f5018afc)
