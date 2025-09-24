# DAA Lab: Longest Common Subsequence (LCS) and Longest Repeating Subsequence (LRS)
This repository contains two C++ programs that implement dynamic programming solutions for the Longest Common Subsequence and Longest Repeating Subsequence problems. These were developed as part of a Design and Analysis of Algorithms (DAA) lab course.

Files
lcs_lrs.cpp:  This program finds the Longest Repeating Subsequence (LRS) of a given string. An LRS is a subsequence that appears at least twice in the string, without having the same characters at the same indices. It works by finding the LCS of the string with itself, with the added condition that a character match (X[i-1] == Y[j-1]) is only considered if the indices i and j are different.

lcs.cpp: This program finds the Longest Common Subsequence (LCS) between two different strings. The standard dynamic programming approach is used to fill a cost matrix and a direction matrix to determine the length and print the subsequence.
