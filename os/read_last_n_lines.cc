#include <cstdio>

using namespace std;

int main()
{
    int nlines = 3;

    char buffer[512];

    FILE *pf;
    pf = fopen("test.txt", "rb");
    fseek(pf, 0, SEEK_END);
    int size_of_file = ftell(pf);


    int cnt = 0;
    int block_idx = 1;
    int offset_from_end = 0;
    while (cnt < nlines) {
        fseek(pf, size_of_file - 512 * block_idx, SEEK_SET);
        fread(buffer, 1, 512, pf);

        for (int i = 511; i >= 0; i--) {
            if (buffer[i] == '\n') {
                cnt += 1;

                if (cnt == nlines) {
                    offset_from_end += (511 - i);
                    goto L1;
                }
            }
        }

        block_idx += 1;
        offset_from_end += 512;
    }

L1:
    fseek(pf, size_of_file - offset_from_end, SEEK_SET);
    while (fgets(buffer, 511, pf)) {
        printf("%s", buffer);
    }

    fclose(pf);
}
