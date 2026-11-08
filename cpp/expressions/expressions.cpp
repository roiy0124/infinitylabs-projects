void HexaToSring(char *hex)
{
    int hex_val;
    int i;
    int h_part;
    hex_val = 0;
    for (i=0;hex[i] != '\0';i++)
    {
        if(hex[i] == ' ')
        {
        std::cout << (char)hex_val;
        hex_val = 0;
        }
        else if((int)hex[i] >= 48 && (int)hex[i] <= 57)
            hex_val = 16 * hex_val + ((int)hex[i] - 48);
        else if((int)hex[i] >= 65 && (int)hex[i] <= 70)
            hex_val = 16 * hex_val + ((int)hex[i] - 55);
    }
    std::cout << (char)hex_val;
}

float Power(int n)
{
    float res, multi;
    int i;
    multi = 10;
    if (n < 0)
    {
        n *= -1;
        multi = 1 / multi;
    }
    res = 1;
    for (i = 0; i < n; i++)
        res *= multi;
    return res;
    
}

int FlipNum(int num)
{
    int flipped_num;
    flipped_num = 0;
    
    while(num > 0)
    {
        flipped_num = (flipped_num * 10) + (num % 10);
        num /= 10;
    }
    
    return flipped_num;
}

void Swap(int* x, int* y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}


