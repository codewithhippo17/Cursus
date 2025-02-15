#include <stdio.h>

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}


int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}


int main()
{
    int t = 0;
    int trgb = create_trgb(256, 255, 255, 255);
    printf("%d\n", trgb);
    printf("t:%d \n", get_t(trgb));    
    printf("r:%d \n", get_r(trgb));
    printf("g:%d \n", get_g(trgb));
    printf("b:%d \n", get_b(trgb));
}