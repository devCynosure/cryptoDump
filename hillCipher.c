

float encrypt[3][1], decrypt[3][1], a[3][3], b[3][3], c[3][3];

void encryption(); //encrypts the message
void decryption(); //decrypts the message
void getKeyMessage();
void inverse();

double mfmod(double x,double y)
{
    double a;
    return x-((int)(x/y))*y;
}
void main()
{
    getKeyMessage();
}

void encryption(float mes[3][1])
{
    int i, j, k;
    memset(encrypt, 0, sizeof encrypt); // this function clears the array
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 1; j++)
        {
            for (k = 0; k < 2; k++)
            {
                encrypt[i][j] = encrypt[i][j] + a[i][k] * mes[k][j];
            }
        }
    }

    printf("\nEncrypted string is: ");
    for (i = 0; i < 2; i++)
    {
        printf("%c", (char)(mfmod(encrypt[i][0], 26) + 97));
    }
    decryption();
}

void decryption()
{
    int i, j, k;
    inverse();

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 1; j++)
        {
            for (k = 0; k < 2; k++)
            {
                decrypt[i][j] = decrypt[i][j] + b[i][k] * encrypt[k][j];
            }
        }
    }

    printf("\nDecrypted string is: ");
    for (i = 0; i < 2; i++)
    {
        printf("%c", (char)(mfmod(decrypt[i][0], 26) + 97));
    }
    memset(decrypt, 0, sizeof decrypt);
    memset(b, 0, sizeof b);
    memset(c, 0, sizeof c);
    printf("\n");
}

void getKeyMessage()
{
    int i, j;
    char msg[100];
    float mes[3][1];

    printf("Enter 2x2 matrix for key:\n");

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            scanf("%f", &a[i][j]);
            //c[i][j] = a[i][j];
        }
    }

    printf("\nEnter the string: ");
    scanf("%s", msg);
    int len = strlen(msg);
    int count = 0;
    printf("After dividing string into 2 pairs each:\n");
    while (count < len)
    {
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
            {
                c[i][j] = a[i][j];
            }
        }
        for (i = 0; i < 2; i++)
        {
            mes[i][0] = msg[count] - 97;
            count++;
        }
        printf("\n");
        encryption(mes);
    }
}

void inverse()
{
    int i, j, k;
    float p, q;

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            if (i == j)
            {
                b[i][j] = 1;
            }
            else
            {
                b[i][j] = 0;
            }
        }
    }
    for (k = 0; k < 2; k++)
    {
        for (i = 0; i < 2; i++)
        {
            p = c[i][k];
            q = c[k][k];

            for (j = 0; j < 2; j++)
            {
                if (i != k)
                {
                    c[i][j] = c[i][j]*q - p * c[k][j];
                    b[i][j] = b[i][j]*q - p * b[k][j];
                }
            }
        }
    }
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            b[i][j] = b[i][j] / c[i][i];
        }
    }
}
