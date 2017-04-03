.. image:: https://img.shields.io/badge/License-MIT-yellow.svg
  :target: https://opensource.org/licenses/MIT
  :alt: License

*Algorithmic Exercises and Adventures in C*

In my recent `research` I have so far used exclusively Python, `Tensorflow`_ and `scikit-learn`_. But that's not enough to be a good software engineer, which you need to be to either set up your own tech company or get a job at a great one.

So, I'm going through Steven S. Skiena's `The Algorithm Design Manual`_. I needed to learn C properly to do this. This repository contains code that implements exercises from Skiena's books (each chapter in a separate directory), as well as various bits and pieces of code I developed for training, in the `misc`_ directory.

Requirements
------------
Pure ANSI C code. Tested on Ubuntu 14.04 with the standard C library.

Tests
-----
There seems to be no standard C testing framework, so I wrote my own tests. Each repository contains a test_*.c file. If you compile and run it, it'll display percentage of tests that passed/failed in each category.

.. _MIT license: https://opensource.org/licenses/MIT
.. _research: https://www.vision.caltech.edu/~kchalupk/
.. _The Algorithm Design Manual: http://www.algorist.com/
.. _scikit-learn: http://scikit-learn.org/stable/
.. _TensorFlow: https://www.tensorflow.org/
.. _misc: misc
