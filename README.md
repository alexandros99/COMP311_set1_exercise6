# COMP311_set1_exercise6
Exercise 6

First af all the code is in C++ as I saw that it should be in C or Java too late and converting it to C or Java (I tried Java because strings and unordered hash maps are difficult in c) was causing time consuming errors that I did not manage to solve at that time.

This code finds a solution for inputs like ab+ab=cd, but does not find a solution for the given inputs. This is not because of the algorithm (which is correct), but because inputs like to+to=for/too+too=for/won+won=too contain the same letter (o) in the addents(to,too,won) and also in the result(for/too) and my code cannot handle this (weakness). But it can calculate correctly an input like to+to=fyr and too+too=fyr! Also won+won=trr etc. So, the logic of the algorithm is correct and it works.

How it works:
The main idea is that the basic function (allDiff) performs the backtracking algorithm. It recursively changes the integer value related to each letter from 0 to base, while satisfying the constraint that there cannot be equalities between these values. If it finds a solution (any solution), it will print it and exit, else it will keep looking until it has searched all of the possible integer combinations for the letters. If it does not find one, it means that either there is none or the result string contains some letter that the two addents also contain (the problem we spoke of above).

Other functions:
checkDigitsNotEqual: checks that all the letters have different integer values between them
solutionExists: returns true if it finds a solution given the current integer values, false otherwise

I hope that the fact that I wrote it in C++ does not affect my grade, as my team's 1st project was in C++ and also I commited much of my time in this beautiful exercise.
Thank you for reading this!
