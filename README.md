# Simple Neural Net written in C++

Wanted to pass some time on a flight, prepare for an upcoming AI class, and keep my c++ sharp, so I decided to try my hand at implementing a simple XOR gate using a neural network. 

Based on [@miloharper](https://github.com/miloharper)'s fantastic [tutorial on Medium](https://medium.com/technology-invention-and-more/how-to-build-a-simple-neural-network-in-9-lines-of-python-code-cc8f23647ca1#.hjy9dav7z).

This project presented some fun challenges with "translation" from Python. I found that working in c++ required a greater understanding of the matrices and mathematics powering the neural net, because of the language's static, explicitly declared types.

---

Next steps:

1. Implement the next post in the series, a [tutorial for a layered neural net](https://medium.com/technology-invention-and-more/how-to-build-a-multi-layered-neural-network-in-python-53ec3d1d326a#.m95snc31h).
2. Refactor my code
..* There are a lot of syntactically similar functions in the "train" member function, so it might be worth it to write a replacement function and pass the original functions in as parameters. 
