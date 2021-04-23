# CS4328HW3

program intends to show the difference between the useage of threads and how to use them as well as undertanding mutual exclusion 

## Usage
```bash
gcc -std=c99 no_mutual.c -lpthread -lm -o no_mutual
gcc -std=c99 mutual.c -lpthread -lm -o mutual

can run mutiple times to verify 