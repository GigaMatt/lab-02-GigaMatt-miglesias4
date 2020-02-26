# CS 4375 - Operating Systems

## Lab 2: Context Swapping

**Author: Matthew Iglesias**</br>
**Author: Matthew Montoya**</br>
**Due: February 28, 2020**

### Objective

The objective for this project is to for this lab is to build a user shell in a group of two for a Unix operating system, and concluding with a report detailing our work. My group partner for this lab is [Matthew Iglesias](https://github.com/miglesias4). Lab demos will be done individually with the TA.

### Directory Structure

The directory structure used herein to manage documents and files is as follows:

At the top level, files describing the project meant for users to read: ```README.md```. The only other files that would be expected here is a ```.gitignore``` file, listing files and/or folders which Git should ignore and a ```.git``` file, containing git metadata. There are two subdirectories of this structure: ```/src``` and ```/test```.

All source code related to this project is located in the ```/src``` subdirectory.

All test code related to this project is located in the ```/test``` subdirectory.

### Approach

The approach for this lab follows the Roachism™ approach, described in lecture on 24 February 2019:

_In terms of abstraction, we want to define a shell interface that provides an abstract function of moving data, allowing any technology to implement the interface, where the interface hides details of implementation._

With this lab, we aim to abstract the core features of the shell, i.e. isolating error exception functions from I/O redirects, and separating all functions from the ```main()``` function, storing all dependencies in a single ```.h``` file. In abstracting the core features, both contributors can simultaneously work on different branches (different functions of the code) in parallel, avoiding merge conflicts and conflicts with other functions of the shell. Lastly, we take components from UTEP's CS 3331 and CS 4311 courses, creating JavaDoc-like comments to promote program understanding for all project contributors.

### How To Compile & Run

1. Using a Linux VM, navigate to the ```/src``` subdirectory via the terminal
2. Enter the following command to compile the program</br>
  ```sudo make```</br>
3. Enter the following command to execute the program</br>
  ```./<program_name>.o```

### Dependencies

1. A Linux-based virtual machine OR
2. A Linux-based machine (Note: This should be reserved for advanced users)

### Warnings

* Although the dependencies call for the use of a virtual machine, you may use a local Linux OS to compile & execute this code. This should be reserved for advanced users
