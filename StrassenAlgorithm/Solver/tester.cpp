int mainx(int n) {
    if (n <= 2) {
        int a11 = a[0][0];
        int a12 = a[0][1];
        int a21 = a[1][0];
        int a22 = a[1][1];
        int b11 = b[0][0];
        int b12 = b[0][1];
        int b21 = b[1][0];
        int b22 = b[1][1];
        int p1 = a11 * (b12 - b22);
        int p2 = (a11 + a12) * b22;
        int p3 = (a21 + a22) * b11;
        int p4 = a22 * (b21 - b11);
        int p5 = (a11 + a22) * (b11 + b22);
        int p6 = (a12 - a22) * (b21 + b22);
        int p7 = (a11 - a21) * (b11 + b12);
        s[0][0] = p5 + p4 - p2 + p6;
        s[0][1] = p1 + p2;
        s[1][0] = p3 + p4;
        s[1][1] = p1 + p5 - p3 - p7;
    }
}