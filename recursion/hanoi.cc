
void tower_of_hanoi(int n, char from, char to, char tmp)
{
    if (n > 0) {
        tower_of_hanoi(n-1, from, tmp, to);
        printf("\nMove disk %d from %c to %c\n", n, from, to);
        tower_of_hanoi(n-1, tmp, to, from);
    }
}
