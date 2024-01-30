#include <unistd.h>

/* write_padding: writes a specified number of padding characters to the output stream */
int write_padding(int count, char c)
{
    int i, written;

    written = 0;
    for (i = 0; i < count; i++)
    {
        if (write(1, &c, 1) == -1)
            return (-1);
        written++;
    }
    return (written);
}
