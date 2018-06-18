#include <stdio.h>
#include <stdlib.h>				//check dhp/DHP
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdbool.h> // It seems that you may not need on other computer this library


struct Hunter
{
	bool alive;
	int x;
	int y;
	double hp;
	double dmg;
	char name[7];
};

struct Hunter Robbin = { true, 26, 26, 500.0, 60.0, "Robbin"}; // the hunter himself

struct Duck {       // main structure for ducks with set parametrs


	bool here;
	bool alive;
	bool flyable;
	int x;
	int y;
	double hp;
	double dmg;
	char type[13];
	char smallt[7];
};

struct Duck RedHatDuck  = { true, true, true,  26, 26, 120.0,  0.0, "RedHatDuck  ", "rdDuck" };
struct Duck MallardDuck = { true, true, true,  26, 26, 130.0,  0.0, "MallardDuck ", "mrDuck" };
struct Duck RubberDuck  = { true, true, false, 26, 26, 200.0, 20.0, "RubberDuck  ", "rbDuck" };

struct Duck ducks[20]; //global array ducks of structures type Duck (max 20, in my point of view 20 ducks for one small lake is enough)

double DuckArray(int typd, int rhtcount, int rbrcount, int mlrcount, int numd) //function type double
{
	int i;
	double dhp = 0;
	for (i = 0; i < numd; i++) //filling aray
	{
		typd = rand() % 3; // randomly chooses type of duck
		if (typd == 0)
		{
			ducks[i] = RedHatDuck;
			rhtcount++;
			dhp += ducks[i].hp;
		}
		if (typd == 1)
		{
			ducks[i] = MallardDuck;
			mlrcount++;
			dhp += ducks[i].hp;
		}
		if (typd == 2)
		{
			ducks[i] = RubberDuck;
			rbrcount++;
			dhp += ducks[i].hp;
		}

		if (i == (numd - 1))
		{
			printf("\n \t\t\t Ducks and Robbin\n  Ducks in total : %d\n  ", numd);
			printf("RedhatDucks : %d\n  ", rhtcount);
			printf("MallarDucks : %d\n  ", mlrcount);
			printf("RubberDucks : %d\n  ", rbrcount);
		}
	}
	return dhp;
}


void PositionOnLake(int numd, int lake)
{
	int i=0, j=0;
	int xrand = 0, yrand = 0;
	bool okxy = false;
	Robbin.x = rand() % lake;
	Robbin.y = rand() % lake;


	while (i < numd)
	{
		okxy = false;
		xrand = rand() % lake;
		yrand = rand() % lake;


		if (((Robbin.x == (xrand - 1)) && (Robbin.y == (yrand + 1))) ||
			((Robbin.x == (xrand)) && (Robbin.y == (yrand + 1))) ||
			((Robbin.x == (xrand + 1)) && (Robbin.y == (yrand + 1))) ||
			((Robbin.x == (xrand - 1)) && (Robbin.y == (yrand))) ||
			((Robbin.x == (xrand)) && (Robbin.y == (yrand))) ||
			((Robbin.x == (xrand + 1)) && (Robbin.y == (yrand))) ||
			((Robbin.x == (xrand - 1)) && (Robbin.y == (yrand - 1))) ||
			((Robbin.x == (xrand)) && (Robbin.y == (yrand - 1))) ||
			((Robbin.x == (xrand + 1)) && (Robbin.y == (yrand - 1))))
		{
			xrand = rand() % lake;
			yrand = rand() % lake;
		}

		for (j = 0; j < i; j++)
		{
			if (((ducks[j].x == (xrand - 1)) && (ducks[j].y == (yrand + 1))) ||
				((ducks[j].x == (xrand)) && (ducks[j].y == (yrand + 1))) ||
				((ducks[j].x == (xrand + 1)) && (ducks[j].y == (yrand + 1))) ||
				((ducks[j].x == (xrand - 1)) && (ducks[j].y == (yrand))) ||
				((ducks[j].x == (xrand)) && (ducks[j].y == (yrand))) ||
				((ducks[j].x == (xrand + 1)) && (ducks[j].y == (yrand))) ||
				((ducks[j].x == (xrand - 1)) && (ducks[j].y == (yrand - 1))) || 
				((ducks[j].x == (xrand)) && (ducks[j].y == (yrand - 1))) ||
				((ducks[j].x == (xrand + 1)) && (ducks[j].y == (yrand - 1))))
			{
				okxy = true;
				break;
			}
		}
		if (okxy == false)
		{
			ducks[i].x = xrand;
			ducks[i].y = yrand;
			//printf("[%d]  %s ( x = %d ; y = %d )\n", i + 1, ducks[i].type, ducks[i].x, ducks[i].y);
			i++;
		}

	}

	printf("Hunter position in the lake :\n");
	printf("%s ( x = %d ; y = %d )\n\n", Robbin.name, Robbin.x, Robbin.y);

	printf("Ducks positions in the lake :\n");
	i = 0;
	while (i < numd)
	{
		if (i==numd-1)
			printf("[%d]  %s ( x = %d ; y = %d )\n", i + 1, ducks[i].type, ducks[i].x, ducks[i].y);
		else
			printf("[%d]  %s ( x = %d ; y = %d )\t \t[%d] %s ( x = %d ; y = %d )\n", i+1, ducks[i].type, ducks[i].x, ducks[i].y, i + 2, ducks[i+1].type, ducks[i+1].x, ducks[i+1].y);
		i += 2;
	}
}	


void LakeMap(int numd,	int lake, int size)
{
	int i = 0, j = 0, k = 0, g = 0;
	char map[25][25][10]; 
	char smap[25][25];
	
	if (size == 0)
	{
													//Small map
		for (i = 0; i < lake; i++)
		{
			for (j = 0; j < lake; j++)
			{
				for (k = 0; k < numd; k++)
				{
					if ((i == ducks[k].x) && (j == ducks[k].y))
					{
						smap[i][j] = 'D';
						break;
					}
					else if ((i == Robbin.x) && (j == Robbin.y))
					{
						smap[i][j] = 'R';
					}
					else
						smap[i][j] = '~';


				}
				printf("%c ", smap[i][j]);

			}
			printf("\n");
		}
	}
	else if (size == 1)
	{
													//Big map
		for (i = 0; i < lake; i++)
		{
			for (j = 0; j < lake; j++)
			{
				for (k = 0; k < numd; k++)
				{
					if ((i == ducks[k].x) && (j == ducks[k].y))
					{
						for (g = 0; g < 7; g++)
						{
							map[i][j][g] = ducks[k].smallt[g];
						}
						break;
					}
					else if ((i == Robbin.x) && (j == Robbin.y))
					{
						for (g = 0; g < 7; g++)
						{
							map[i][j][g] = Robbin.name[g];
						}
					}
					else
					{
						for (g = 0; g < 7; g++)
						{
							map[i][j][g] = ' ';
							map[i][j][g + 1] = '~';
							g++;
						}
					}
				}
				for (g = 0; g < 7; g++)
				{
					printf("%c", map[i][j][g]);
				}
			}
			printf("\n\n");
		}

	}


}


int Hunt(int numd, double dhp, int lake, int size)
{
	int i = 0, /*?j?*/j = 0, r = 0, r1 = 0, r0, crit = 11, shotnum = 0, dklive = 0, dkill = 0;
	//crit - critical hit;	stotnum - shot counter;	dklive/kill - counters of ducks
	
	double dmg = 0.0;
	dklive = numd;

	i = MinDistance(numd); //calculating distance to the nearest duck
	
	while (dhp > 0) //main_cykle
	{
		r0 = rand() % 3 + 1;             //hunter has 1-2 extra shots  

		for (j = 0; j < r0; j++) //sub_cykle for extra shots
		{
			printf("%s has %.f HP!\n...aiming\n", ducks[i].type, ducks[i].hp);

			r = rand() % 9;
			if (r > 3)
			{
				r1 = rand() % 4;
				printf("Possible critical hit= %d %%\nshoting...\n", 100 / crit);
				if (r1 == 0)												// possibility of critical hit is 0.2
				{
					dmg = Robbin.dmg + Robbin.dmg*(crit / 100.0);
					ducks[i].hp -= dmg;
					dhp -= dmg;
					printf("Critical damage %.f  ! ! ! \n", dmg);
					printf("Duck [%d] hp = %.f \n", i, ducks[i].hp);
					crit = rand() % 10 + 1;
					shotnum++;
					printf("Hunter shot number = %d \n", shotnum);
					printf("---------------------------------------------------------------\n");

				}
				else
				{
					dmg = Robbin.dmg;
					ducks[i].hp -= dmg;
					dhp -= dmg;
					printf("Damage =  %.f \n", dmg);
					printf("Duck [%d] hp = %.f \n", i, ducks[i].hp);
					crit = rand() % 10 + 1;
					shotnum++;
					printf("Hunter shot number = %d\n", shotnum);
					printf("---------------------------------------------------------------\n");
				}
			}
			else
			{
				switch (r)
				{
				case 0:
					printf("Possible critical hit= %d %%\nshoting...\n", 100 / 2);
					dmg = Robbin.dmg * 2;
					ducks[i].hp -= dmg;
					dhp -= dmg;
					printf("Critical damage x2!\n");
					printf("Duck [%d] hp = %.f\n", i, ducks[i].hp);
					shotnum++;
					crit = 10;
					printf("Hunter shot number = %d\n", shotnum);
					printf("---------------------------------------------------------------\n");
					break;
				case 1:
					printf("Possible critical hit= %d %%\nshoting...\n", 100 / crit);
					crit = rand() % 10 + 1;
					printf("Duck [%d] hp = %.f \n", i, ducks[i].hp);
					shotnum++;
					printf("Hunter missed, but duck still here\n");
					printf("Hunter shot number = %d\n", shotnum);
					printf("---------------------------------------------------------------\n");
					break;
				case 2:
					printf("Possible critical hit= %d %%\nshoting...\n", 100 / crit);
					crit = rand() % 10 + 1;
					printf("Duck [%d] hp = %.f\n", i, ducks[i].hp);
					shotnum++;
					if (ducks[i].flyable == true)
					{
						printf("Hunter missed, duck flew away ..\n");
						ducks[i].here = false;
					}
					else
					{
						dmg = Robbin.dmg / 2;
						ducks[i].hp -= dmg;
						dhp -= dmg;
						printf("Damage =  %.f p \n", dmg);
						printf("Duck [%d] hp = %.f \n", i, ducks[i].hp);

					}

					printf("Hunter shot number = %d \n", shotnum);
					printf("---------------------------------------------------------------\n");
					break;
				case 3:
					printf("Possible critical hit= %d %% \nshoting...\n", 100 / crit);
					crit = rand() % 10 + 1;
					printf("Duck [%d] hp = %.f \n", i, ducks[i].hp);
					shotnum++;
					if (ducks[i].flyable == false)
					{
						printf("Ricochet hited hunter...\n");
						Robbin.hp -= 30 + 20 * (10 / crit);
						printf("Robbin HP = %.f\n", Robbin.hp);
					}
					else
					{
						dmg = Robbin.dmg / 2;
						ducks[i].hp -= dmg;
						dhp -= dmg;
						printf("Damage -  %.f \n", dmg);
						printf("Duck [%d] hp = %.f \n", i, ducks[i].hp);

					}

					printf("Hunter shot number = %d \n", shotnum);
					printf("---------------------------------------------------------------\n");
					break;
				default:
					printf("Something is wrong.\n");
					break;
				}
			}

			if (ducks[i].hp <= 0)					           //cheking if duck is alive
			{
				ducks[i].alive = false;
				dkill++;         													//kill counter
				printf("%s was shoted by Robbin !\n +1 Kill\n", ducks[i].type);
				printf("---------------------------------------------------------------\n");
				dklive--;																  //live counter
				HunterMove(i);															 //hunter moves to the duck place
				i = MinDistance(numd);		//i++;         								//switching to the next duck -  nearest to Robbin position
				LakeMap(numd, lake, size);
			}		
			if ((dkill >= 1) && (dkill >= numd / 2) && (shotnum < 50))  //conditions for end of game simulation
			{
				printf("Hunter won!!! %d / %d \n", dkill, numd);
				return 0;
			}
			else if (dhp <= 0)
			{
				printf("Hunter won! All ducks were shoted down ! %d / %d !\n", dkill, numd);
				return 0;
			}
			else if ((shotnum >= 50) || (Robbin.hp <= 0))
			{
				printf("Ducks won!!! %d alive ducks\n", dklive);
				return 0;
			}

		}
	}


}


int MinDistance(int numd)
{

	int i = 0, x1 = 0, x2 = 0, y1 = 0, y2 = 0;
	double *d, min = 36.0;

	d = (double*)malloc(numd * sizeof(int));

	for (i = 0; i < numd; i++)
	{
		if (ducks[i].alive==true)
		d[i] = pow(((ducks[i].x - Robbin.x)*+(ducks[i].y - Robbin.y)),0.5);
	}

	for (i = 0; i < numd; ++i)
	{
		if (d[i] < min)
		{
			min = d[i];
		}
	}
	printf("Minimal distance is - %.f , nearest duck - %s ", min, ducks[i].type);

	return i;
}


int HunterMove(int i)
{
	Robbin.x = ducks[i].x;
	Robbin.y = ducks[i].y;
}



int main()
{

	srand(time(NULL));


	int lake = 25, typd = 0, rhtcount = 0, rbrcount = 0, mlrcount = 0, size = 0;
	//lake- lake size; typd - duck type; xxxcount - each type counters, size - map size;
	char s[1];
	int numd = rand() % 6 + 15;  //randomly choose number of ducks (for random in scale [M1; M2] : Number = rand() % (M2 - M1 + 1) + M1)
	double dhp = DuckArray(typd, rhtcount, rbrcount, mlrcount, numd); //HP of all ducks & duckarray creation


	
	printf("\n---------------------------------------------------------------\n\n");

	PositionOnLake(numd, lake);


	printf("\n---------------------------------------------------------------\n\n");
	printf("\nMap size : Small - 0, Big - 1 ->");
	scanf("%d", &size);

	LakeMap(numd,lake,size);

	printf("\n---------------------------------------------------------------\n\n");
	printf("In total Ducks have %.f HP\n", dhp);
	printf("Hunter has %.f HP and %.f DMG \n\n", Robbin.hp, Robbin.dmg);

	printf("---------------------------------------------------------------\n");
	printf("Press  <-'ENTER    to start the hunt ... \n");
	printf("---------------------------------------------------------------\n");
	scanf("%c", &s);
	scanf("%c", &s);
	
	Hunt(numd, dhp, lake, size);
	system("pause");
	return 0;
}













