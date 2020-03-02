#include <stdio.h>
#include <X11>

int main() {
    Display * d = XOpenDisplay((char*)0);

    if (d) {
        unsigned n;

        XkbGetIndicatorState(d, XkbUseCoreKbd, &n);

        printf((n & 1)?"caps on\n":"caps off\n");
    }
}
