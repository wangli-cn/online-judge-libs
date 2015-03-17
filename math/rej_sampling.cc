
int rand10() {
    int r, c, idx;
    do {
        r = rand7();
        c = rand7();
        idx = c + (r-1)*7;
    } while (idx > 40);
    return 1 + (idx-1) % 10;
}
