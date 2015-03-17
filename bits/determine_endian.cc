
string determine_endian()
{
    unsigned n = 1;
    if (*(char *)&n == 1) return string("little-endian");
    else return string("big-endian");
}

unsigned convert(unsigned n)
{
    unsigned byte0, byte1, byte2, byte3;

    byte0 = (n & 0x000000FF >> 0);
    byte1 = (n & 0x0000FF00 >> 8);
    byte2 = (n & 0x00FF0000 >> 16);
    byte3 = (n & 0xFF000000 >> 24);

    return (byte0 << 24) | (byte1 << 16) | (byte2 << 8) | (byte3 << 0);
}


