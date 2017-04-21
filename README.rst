.. image:: https://img.shields.io/badge/License-MIT-yellow.svg
  :target: https://opensource.org/licenses/MIT
  :alt: License

*Algorithmic Exercises and Adventures in C*

I'm going through Steven S. Skiena's `The Algorithm Design Manual`_. I needed to learn C from scratch to do this (I only know Python well, and JavaScript to a smaller degree). This repository contains code that implements exercises from Skiena's books (each chapter in a separate directory). It also contains various algorithms and datastructures I wrote for training. 

I learned C from `The C Programming Language` (2nd edition), which is about the now-obsolete C89 standard. The advantage of the book is that I could read through it and have a working knowledge of the language in 3 days. The disadvantage is that I have no idea what happened in C99 and C11. It turns out that Ubuntu's default C compiler works in C89 by default in any case.

Requirements
------------
The whole repository is written in C89, so should run anywhere. Tested on Ubuntu 14.04 with the default C library.

Tests
-----
There seems to be no standard C testing framework, so I wrote my own tests. Each datastructure and algorithm corresponds to a test_*.c file. If you compile and run it, it'll display percentage of tests that passed/failed in each category.

.. _MIT license: https://opensource.org/licenses/MIT
.. _research: https://www.vision.caltech.edu/~kchalupk/
.. _The Algorithm Design Manual: http://www.algorist.com/
.. _scikit-learn: http://scikit-learn.org/stable/
.. _TensorFlow: https://www.tensorflow.org/
.. _misc: misc
.. _The C Programming Langage: http://www.cprogramming.com/books/ritchie.html
