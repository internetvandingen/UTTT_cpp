# UTTT_cpp
C++ console implementation of the game Ultimate Tic Tac Toe (UTTT), speedtested on intel i7 (2nd gen).
Speedup over python of almost 90 times.

C++:
Debug mode:
100000 random games in [23.004, 23.119, 22.788] seconds.<br>
Average:    0.2297 ms/game or 4353 games/s

Release mode: (optimized for speed on CPU)
100000 random games in [6.658, 6.375, 6.368] seconds.<br>
Average:      0.06467 ms/game or 15463 games/s


Python:
10000 games in [55.98, 56.61, 57.91] seconds <br>
Average: 5.6833333 ms/game or 175 games/s
