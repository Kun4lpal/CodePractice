//Given a positive integer num, write a function which returns True if num is a perfect square else False.
bool isPerfectSquare(int x) {
    long r = x;
    while (r*r > x)
        r = (r + x/r) / 2;
    return r*r == x;
}