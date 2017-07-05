.. image:: https://img.shields.io/badge/License-MIT-yellow.svg
  :target: https://opensource.org/licenses/MIT
  :alt: License

*Algorithmic Exercises and Adventures in C/C++*

I'm going through Steven S. Skiena's `The Algorithm Design Manual`_. I want to remaster both basics of computer science as well as C and C++, which were never particularly useful during my Ph.D. but are great skills to have. This repository contains code that implements exercises from Skiena's books (each chapter in a separate directory). It also contains various algorithms and datastructures I wrote for training. 

I learned C from `The C Programming Language` (2nd edition), which is about the now-obsolete C89 standard. The advantage of the book is that I could read through it and have a working knowledge of the language in 3 days. The disadvantage is that I have no idea what happened in C99 and C11. It turns out that Ubuntu's default C compiler works in C89 by default in any case.

To remaster C++, I'm using Accelerated C++, an awesome fast-paced course.

Requirements
------------
The whole repository is written in C89 and C++, so should run on any Linux distro with C and C++ devel libraries. Tested on Ubuntu 14.04 and Arch Linux.

Tests
-----
There seems to be no standard C testing framework, so I wrote my own tests. Each datastructure and algorithm corresponds to a test_*.c file. If you compile and run it, it'll display percentage of tests that passed/failed in each category.

For C++ testing I use `Catch`_, an awesome header-only testing framework.

.. _MIT license: https://opensource.org/licenses/MIT
.. _research: https://www.vision.caltech.edu/~kchalupk/
.. _The Algorithm Design Manual: http://www.algorist.com/
.. _scikit-learn: http://scikit-learn.org/stable/
.. _TensorFlow: https://www.tensorflow.org/
.. _misc: misc
.. _Catch: https://github.com/philsquared/Catch
.. _The C Programming Langage: http://www.cprogramming.com/books/ritchie.html
