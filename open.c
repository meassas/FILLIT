

#include "fillit.h"
#include "libft.h"

int		proto_place(char **tetri, char **map, int t, int my, int mx, int m);

#define BUF_SIZE 550// 21 Char * 26 Tetrimax

int		main(int ac, char **av)
{
	int fd;
	int ret;
	char buf[BUF_SIZE + 1];
	char	**tabtetri;
	int		y;
	char	**map;
	int	tmp;
	int		nbtetri;

	tmp = 0;
	if (ac != 2)
	{
		ft_putstr("usage : source_file target_file");
		return (0);
	}
	y = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Open FAILED");
		return (1);
	}
	ret = read(fd, buf, BUF_SIZE); // soit boucle de read, soit taille max 26 elements
	buf[ret] = '\0';
	if (ret > 546 || ret < 19) //nb de char max pour 26 tetriminos
	{
		ft_putstr("error");
		return (0);
	}
	if (close(fd) == -1)
	{
		ft_putstr("read FAILED");
		return (1);
	}
	nbtetri = cntTetri(buf, '\n');
	tabtetri = ft_splitetri(buf, '\n');
	while (tabtetri[tmp] != 0)
	{
		if (ft_tetri_isvalid(tabtetri[tmp]) == 0)
		{
			ft_putendl("error");
			return (1);
		}
		tmp++;
	}
	ft_rangetetri(tabtetri);
	ft_setalpha(tabtetri);
	map = ft_setmap(ft_sqrtSup(nbtetri * 4));
	//ft_putnbr(nbtetri);
	//ft_putchar('\n');
	//if (nbtetri == 1)
	//{
		while (ft_place_OK(tabtetri[0], map, 0, 0) != 4)
		{
			free (map);
			nbtetri++;
			map = ft_setmap(nbtetri);
		}
	//	ft_cpy(tabtetri[0], map, 0, 0);
	//}
	//else
	//{
		while (placetetri(tabtetri, map, 0, 0, 0, 0) != 1)
		{
			free (map);
			map = ft_setmap(nbtetri);
			nbtetri++;
		}
	//}
	y = 0;
	while (map[y] != 0)
	{
		ft_putstr(map[y]);
		ft_putchar('\n');
		y++;
	}
	return (0);
}
